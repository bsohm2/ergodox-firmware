"""
LinkedIn Post Generator — calls Anthropic API with web search to draft
a weekly cybersecurity post in Brandon's voice and emails it via Gmail.

Required env vars (set with setup_env.bat before first run):
  ANTHROPIC_API_KEY, LI_EMAIL_SENDER, LI_EMAIL_PASSWORD, LI_EMAIL_RECIPIENT
"""

import os
import sys
import smtplib
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
from datetime import datetime

import anthropic

PROMPT = """You are writing a LinkedIn post on behalf of Brandon Sohm, a cybersecurity
practitioner with a SOC analyst and Solutions Architect background who is actively
job searching.

Step 1 — Search the web for the most talked-about cybersecurity news or trends from
the past 7 days. Focus on these areas (pick whichever has the freshest, most
substantive story):
  • Threat intelligence / active campaigns
  • Zero trust architecture adoption
  • SOC operations / MSSP industry developments
  • Ransomware / extortion trends
  • AI being used offensively or defensively in security

Step 2 — Draft a LinkedIn post based on what you found. The post must:
  • Be 150–220 words (no shorter, no longer)
  • Open with a specific observation or fact — not a generic hook
  • Explain why this matters to defenders in plain English
  • Include one concrete takeaway a SOC analyst or security architect can act on today
  • Close with a thought-provoking question that invites comments
  • Sound like a practitioner, not a vendor or marketer
  • Use short paragraphs (2–4 sentences each)
  • Include 3–5 relevant hashtags at the end
  • Do NOT use em-dashes (—) — use commas or restructure the sentence instead

Return ONLY the finished post text, ready to copy-paste into LinkedIn. No preamble,
no "Here's a post:", no word count note — just the post itself."""


def get_env(key: str) -> str:
    value = os.environ.get(key)
    if not value:
        print(f"ERROR: environment variable {key} is not set", file=sys.stderr)
        print("Run setup_env.bat as Administrator to configure required variables.",
              file=sys.stderr)
        sys.exit(1)
    return value


def generate_linkedin_post(client: anthropic.Anthropic) -> str:
    print(f"[{datetime.now():%Y-%m-%d %H:%M:%S}] Calling Anthropic API with web search...")

    response = client.messages.create(
        model="claude-sonnet-4-6",
        max_tokens=1024,
        tools=[{
            "type": "web_search_20260209",
            "name": "web_search",
            "max_uses": 5,
        }],
        messages=[{"role": "user", "content": PROMPT}],
    )

    text_blocks = [b.text for b in response.content if b.type == "text"]
    if not text_blocks:
        print("ERROR: No text content returned from API", file=sys.stderr)
        sys.exit(1)

    post = "\n".join(text_blocks).strip()
    print(f"[{datetime.now():%Y-%m-%d %H:%M:%S}] Post generated ({len(post.split())} words).")
    return post


def send_email(sender: str, password: str, recipient: str, post_text: str) -> None:
    today = datetime.now().strftime("%B %d, %Y")
    subject = f"LinkedIn Post Draft — {today}"

    body = f"""Hi Brandon,

Here is your LinkedIn post draft for this week:

---

{post_text}

---

Copy the text above and paste it directly into LinkedIn. Edit as needed before posting.

Generated automatically by linkedin_post_generator.py
"""

    msg = MIMEMultipart()
    msg["From"] = sender
    msg["To"] = recipient
    msg["Subject"] = subject
    msg.attach(MIMEText(body, "plain"))

    print(f"[{datetime.now():%Y-%m-%d %H:%M:%S}] Sending email to {recipient}...")
    with smtplib.SMTP_SSL("smtp.gmail.com", 465) as server:
        server.login(sender, password)
        server.sendmail(sender, recipient, msg.as_string())
    print(f"[{datetime.now():%Y-%m-%d %H:%M:%S}] Email sent successfully.")


def main() -> None:
    api_key = get_env("ANTHROPIC_API_KEY")
    sender = get_env("LI_EMAIL_SENDER")
    password = get_env("LI_EMAIL_PASSWORD")
    recipient = get_env("LI_EMAIL_RECIPIENT")

    client = anthropic.Anthropic(api_key=api_key)

    post = generate_linkedin_post(client)
    send_email(sender, password, recipient, post)

    print(f"[{datetime.now():%Y-%m-%d %H:%M:%S}] Done.")


if __name__ == "__main__":
    main()
