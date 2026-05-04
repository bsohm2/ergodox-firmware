# Setting Up ErgoDox Infinity Ecosystem Project

## Create GitHub Project Board

### Step 1: Create the Project

1. Go to https://github.com/bsohm2?tab=projects
2. Click **New project** button
3. Configure:
   - **Project name:** `ErgoDox Infinity Ecosystem`
   - **Description:** Unified tracking for firmware, web tools, and investigation
   - **Type:** Table (or Board)
   - **Visibility:** Public

### Step 2: Link Repositories

1. Click **Settings** → **Linked repositories**
2. Add all 3 repos:
   - bsohm2/ergodox-firmware
   - bsohm2/ergodox-web-configurator
   - bsohm2/ergodox-irq-fix

### Step 3: Custom Fields

Add these fields:

**Repository:** Firmware | Web Configurator | Investigation

**Component:** Keymap | USB Stability | Web UI | Build

**Keymap:** Default | Gaming | Diablo 4 | General

**Status:** Backlog | In Progress | Review | Done

### Step 4: Add GitHub Topics

**All repos:**
- ergodox
- ergodox-infinity
- qmk
- keyboard

**ergodox-firmware:**
- qmk-firmware
- keymap
- split-keyboard

**ergodox-web-configurator:**
- web-ui
- configurator
- react

**ergodox-irq-fix:**
- debugging
- investigation
- chibios

### Step 5: Add Labels (All Repos)

- firmware
- documentation
- web-ui
- usb-stability
- bug
- enhancement
- help wanted
- investigation
- blocked
- keymap:default
- keymap:gaming
- keymap:diablo4

### Step 6: Cross-Link Repositories

Add to README of each repo:

```markdown
## Part of ErgoDox Infinity Ecosystem

This repo is part of a unified project:

- **[ergodox-firmware](https://github.com/bsohm2/ergodox-firmware)** - Main QMK builds
- **[ergodox-web-configurator](https://github.com/bsohm2/ergodox-web-configurator)** - Web editor
- **[ergodox-irq-fix](https://github.com/bsohm2/ergodox-irq-fix)** - Investigation archive

See [Project Board](https://github.com/users/bsohm2/projects/YOUR_PROJECT_ID) for unified tracking.
```

## Initial Project Structure

### Columns/Status

1. **Backlog** - Planned work
2. **In Progress** - Currently being worked on
3. **In Review** - PR/testing phase
4. **Done** - Completed

### Initial Cards

**Firmware (High Priority)**
- [ ] Test keyboard_config_fixed.h on hardware
- [ ] Merge USB fixes to main branch
- [ ] Update GitHub releases
- [ ] Plan QMK upgrade testing

**Web Configurator (Medium Priority)**
- [ ] Phase 1: Keyboard layout visualization
- [ ] Phase 1: Key editor interface
- [ ] Phase 2: Save/load profiles
- [ ] Phase 3: Cloud sync

**Investigation (Archived)**
- [ ] Document findings (fixed upstream)
- [ ] Create USB stability testing framework
- [ ] Archive investigation results

## Benefits of This Structure

✅ See all 3 projects in one dashboard
✅ Track dependencies between repos
✅ Unified labels and filtering
✅ Consistent issue tracking
✅ Easy for contributors to find work
✅ Public visibility for the project

## Project Board URL

Once created: https://github.com/users/bsohm2/projects/[NUMBER]

Share this with team/community for collaboration.
