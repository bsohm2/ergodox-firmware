# Diablo 4 Keymap Guide

## Overview

This keymap is optimized specifically for Diablo 4 gameplay based on Blizzard's control scheme and community best practices. It leverages the ErgoDox's ergonomic design to create a comfortable farming/dungeon running setup.

**Key Features:**
- 6 Skill Slots mapped to primary position (Q, W, E, R, T, D)
- Potion on Easy Access (left hand pinky area for panic healing)
- Town Portal quick bind (T key)
- Inventory Layer for quick stash management
- Alt Hotbar for secondary ability mappings
- Force Move layer ready for scroll wheel binding
- OLED display shows current layer and active skills

## Why This Layout?

Diablo 4 is a click-heavy action RPG requiring:
1. Fast skill rotation (6 active skills max)
2. Quick potion use under pressure
3. Precise cursor positioning (Force Move on scroll wheel)
4. Frequent inventory management during farming
5. Zero latency (TAPPING_TERM 0 for instant response)

This keymap addresses all of these needs on the ErgoDox.

## Skill System in Diablo 4

Diablo 4 limits you to 6 active skills equipped at once, regardless of class. Typical skill distributions:

### Common Build Archetypes

**Damage Dealer (4 damage + 1 mobility + 1 defense):**
- Skills 1-2: Spenders (high damage, use resources)
- Skill 3: Generator (builds resource)
- Skill 4: Utility (crowd control, damage boost)
- Skill 5: Mobility (dash, teleport, ride)
- Skill 6: Defense (barrier, heal, shield)

**Pet/Minion Build (4 summoners + 1 utility + 1 defense):**
- Skills 1-3: Summon skills (minions, companions)
- Skill 4: Corpse/buff ability
- Skill 5: Support (might not use in combat)
- Skill 6: Defense

### Classes in Diablo 4

- Barbarian: Fury-based, shout buffs, dual wielding
- Sorcerer: Elemental damage, limited resource
- Rogue: Crowd control, stealth, high burst
- Necromancer: Minions, corpse skills, blood magic
- Druid: Shape-shifting, summons, elemental
- Spiritborn (newer): Spirit abilities, hybrid offense/defense
- Paladin (newer): Holy skills, auras, shields

## Layer Breakdown

### Layer 0: DIABLO (Skills Layer - Base)

Left Hand - SKILL ACCESS
- Tab: Inventory open
- S1-S5: Primary skill row (easy reach)
- S6: Mobility/defense usually
- POT: Potion (pinky-accessible, panic button)
- TP: Town portal for quick escape

Right Hand - UTILITIES
- Arrow Keys: Camera/targeting
- I: Inventory
- C: Character sheet
- M: Map
- L: Log

### Layer 1: DIABLO_HOTBAR (Hold right pinky)

Alternative skill bindings for class-specific setups:
- Q/W/E/R/T (top row)
- A/S/D/F (home row)
- Z/X/C/V/B (bottom row)

### Layer 2: DIABLO_INVENTORY (Hold right hand modifier)

Quick stash/inventory management:
- 1-0 for quick stash tabs or item sorting
- Tab selection, itemization shortcuts

### Layer 3: DIABLO_FUNCTION (Hold right modifier)

Game controls and utilities:
- F1-F12: Game settings, graphics, sound
- ESC: Pause menu
- M: Minimap toggle
- Menu: Character menu

## Default D4 Controls Reference

Skill 1: 1 -> Q (S1)
Skill 2: 2 -> W (S2)
Skill 3: 3 -> E (S3)
Skill 4: 4 -> R (S4)
Skill 5: 5 -> T (S5)
Skill 6: 6 -> D (S6)
Potion: Q -> D (POT)
Town Portal: T -> V (TP)
Force Move: Scroll Wheel (default)
Inventory: I -> I (also mapped)
Character: C -> C (mapped)
Map: Tab -> Tab (mapped)

## Customization Guide

### For Your Specific Build

Step 1: Open keyboard_layout.c
Step 2: Find the skill slots
Step 3: Adjust as needed

Keep your main damage spenders in S1-S3 (most accessible)
Put mobility in S5 or S6
Put defense/heal in S6

### Example: Sorcerer Build

Layer 0 (Skills):
S1 = Inferno (main spender)
S2 = Firewall (2nd spender)
S3 = Flame Shield (defense)
S4 = Teleport (mobility)
S5 = Fireball (generator)
S6 = Ice Shards (crowd control)

### Example: Barbarian Build

Layer 0 (Skills):
S1 = Whirlwind (damage)
S2 = Bleed (spender)
S3 = Leap (mobility)
S4 = War Cry (buff)
S5 = Thick Skin (defense)
S6 = Upheaval (utility)

## Build & Flash

### Build Diablo 4 Keymap
qmk compile -kb ergodox_infinity -km diablo4

### Flash to Keyboard
Left half in bootloader:
dfu-util -D ergodox_infinity_diablo4.bin

Then right half:
dfu-util -D ergodox_infinity_diablo4.bin

### Test in D4
1. Load into a low-difficulty dungeon
2. Test all 6 skills respond correctly
3. Test potion heal (D key)
4. Test town portal (V key)
5. Verify inventory access
6. Adjust keybinds as needed

## Farming Optimization Tips

### Efficient Skill Rotation
1. Keep generators on easily repeatable keys
2. Keep spenders on quick-access keys
3. Put mobility on thumb or pinky (easy to reach mid-fight)
4. Put defense/heals in muscle-memory positions

### Inventory Management
- Hold the Inventory layer while farming
- Use right-hand numberpad (1-0) to sort items quickly
- Keep stash tab switching on the Hotbar layer

### Potion Usage
- The potion key (D area) is your panic button
- Press before you need healing (better alive than dead)
- Adjust potion bind if D doesn't feel natural

### Force Move (Scroll Wheel Method - RECOMMENDED)

D4 officially supports mapping Force Move to scroll wheel for precise kiting:

1. In D4 Game Menu -> Options -> Controls
2. Find Force Move
3. Bind to Scroll Up or Scroll Down
4. Use scroll wheel for safe distance positioning

This is better than keyboard keys because:
- Continuous input for hold-to-move
- Frees up keyboard for skills
- More precise cursor control

## Troubleshooting

### Skill casts not registering
1. Verify ENABLE_SEND_STRING enabled in config.h
2. Rebuild: qmk compile -kb ergodox_infinity -km diablo4
3. Check D4 has focus (Alt+Tab to game window)
4. Verify skill keys 1-6 work in D4s default binding

### Potion not healing
1. Check D key works in game
2. Verify our macro sends key correctly
3. Try remapping to a different key if conflicts

### Latency/slowness
1. TAPPING_TERM 0 should handle this
2. Reduce OLED_UPDATE_INTERVAL to 150ms
3. Disable any unnecessary layers

## Sources & Research

- Diablo 4 Controls Guide: https://diablo4.wiki.fextralife.com/Controls
- Blizzard Controls Documentation: https://www.wowhead.com/diablo-4/guide/gameplay/user-interface-keyboard-shortcuts
- Custom Keybinds Setup: https://gamerant.com/diablo-4-how-to-change-controls-bind-custom-keys-configure-bindings-keybinding-customization-guide-d4/
- Best Keybind Practices: https://segmentnext.com/diablo-4-keyboard-shortcut-keybind/
- Mythic Drop Keybind Guide: https://mythicdrop.com/guide/diablo-4-keybinds
- SteelSeries Comfort Guide: https://steelseries.com/blog/most-comfortable-diablo-iv-keyboard-bindings-1199
- Build Guides: https://maxroll.gg/d4/build-guides

Pro Tip: Save your keybind setup in D4 so you can quickly restore it if needed!
