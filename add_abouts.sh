#!/bin/bash

# KEYMAP_LEGEND.md
sed -i '3a\n## About This Document\n\nThis is the **complete visual reference** for the default QWERTY keymap. It shows all 5 layers in full detail so you can quickly find any key without hunting through documentation.\n\n**Use this when:** You need to quickly locate a key or understand the complete layout at a glance.\n\n**Legend:**\n- `[KEY]` = Tap for this key\n- `(KEY)` = Hold for modifier / layer toggle\n- `KEY / MODS` = Tap for KEY, hold for MODS\n\n**5 Layers included:**\n1. Layer 0 — QWERTY Base\n2. Layer 1 — Symbols\n3. Layer 2 — Navigation\n4. Layer 3 — Numbers\n5. Layer 4 — Function\n\n**Related:** See [KEYMAP_GUIDE.md](KEYMAP_GUIDE.md) for feature explanations, or [GAMING_GUIDE.md](GAMING_GUIDE.md) / [DIABLO4_GUIDE.md](DIABLO4_GUIDE.md) for alternative keymaps.' KEYMAP_LEGEND.md

echo "✓ KEYMAP_LEGEND.md updated"

