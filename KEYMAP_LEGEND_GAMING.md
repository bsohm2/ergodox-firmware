# Gaming Keymap Legend - Complete Layout

## Physical Layout (All 14 columns per row + thumb clusters)

```
Left Hand (7 wide)              Right Hand (7 wide)

ROW 1:  [ESC] [1] [2] [3] [4] [5] [BSPC]  |  [=]   [6]   [7]   [8]   [9]   [0]   [BSPC]
ROW 2:  [TAB] [Q] [W] [E] [R] [T] [LBRK]  |  [RBRK] [Y]   [U]   [I]   [O]   [P]   [NO]
ROW 3:  [CTRL][A] [S] [D] [F] [G]         |  [H]   [J]   [K]   [L]   [;]   [']
ROW 4:  [SHFT][Z] [X] [C] [V] [B] [RBRK]  |  [LBRK] [N]   [M]   [,]   [.]   [/]   [SHFT]
ROW 5:  [ALT][NO] [CTRL][GUI][HOTBAR]     |  [LEFT][UP]  [DOWN][RIGHT][FN]

THUMB:  [PSCR]  [HOME]          |  [RCTL]  [MENU]
        [END]   [END]           |  [RALT]  [RALT]
        [SPACE] [ENTER]         |  [RGUI]  [SPACE]
```

---

## Layer 0: GAMING (Base Skills Layer)

**Optimized for WASD-style action games (no tap-hold delays - TAPPING_TERM 0)**

**Left Hand:**
```
Row 1: [ESC]   [1]   [2]    [3]    [4]    [5]   [BSPC]
Row 2: [TAB]   [S1]  [S2]   [S3]   [S4]   [S5]  [LBRK-toggle]
Row 3: [CTRL]  [A]   [S]    [POT]  [F]    [S6]
Row 4: [SHFT]  [Z]   [X]    [C]    [V]    [TP]  [RBRK-toggle]
Row 5: [ALT]   [NO]  [CTRL] [GUI]  [HOTBAR layer]

S1-S6 = Skill slots 1-6 (sends 1-6 keys to game)
POT = Potion (sends Q key - quick heal)
TP = Town Portal (sends T key - escape)
```

**Right Hand:**
```
Row 1: [=]   [6]   [7]    [8]    [9]    [0]   [BSPC]
Row 2: [RBRK] [Y]   [U]    [I]    [O]    [P]   [NO]
Row 3: [H]   [J]   [K]    [L]    [;]    [']
Row 4: [LBRK] [N]   [M]    [,]    [.]    [/]   [SHFT]
Row 5: [LEFT] [UP]  [DOWN] [RIGHT][FN layer]

Standard game keys for inventory, menus, camera
```

---

## Layer 1: GAMING_HOTBAR (Hold HOTBAR modifier)

**Alternative skill bindings for ability combos**

**Left Hand:**
```
Row 1: [NO]   [F1]  [F2]   [F3]   [F4]   [F5]  [TRANS]
Row 2: [TRANS][Q]   [W]    [E]    [R]    [T]   [TRANS]
Row 3: [TRANS][A]   [S]    [D]    [F]    [G]
Row 4: [TRANS][Z]   [X]    [C]    [V]    [B]   [TRANS]
Row 5: [TRANS][TRANS][TRANS][TRANS][TRANS]

Provides alternate key bindings for ability sequences
```

**Right Hand:**
```
Row 1: [TRANS][F6]  [F7]   [F8]   [F9]   [F10] [F11]
Row 2: [TRANS][EXLM][@]    [{]    [}]    [|]   [F12]
Row 3: [HASH] [$]   [(]    [)]    [GRV]  [TRANS]
Row 4: [TRANS][PERC][CIRC] [LBRK] [RBRK] [TILD][TRANS]
Row 5: [TRANS][TRANS][TRANS][TRANS][TRANS]

More ability keys, special characters if needed
```

---

## Layer 2: GAMING_NUMPAD (Hold right hand modifier)

**Quick item/ability selection via numpad (1-0 keys)**

```
Row 1: [TRANS][NO]  [NLCK] [/]    [*]    [-]   [NO]
Row 2: [TRANS][NO]  [P7]   [P8]   [P9]   [+]   [NO]
Row 3: [NO]   [P4]  [P5]   [P6]   [+]    [TRANS]
Row 4: [TRANS][NO]  [P1]   [P2]   [P3]   [PENT][TRANS]
Row 5: [TRANS][P0]  [PDOT] [PENT] [TRANS]

P0-P9 = Numpad digits (mapped to ability selection 0-9)
```

---

## Layer 3: GAMING_FUNCTION (Hold FN key on right)

**Game utilities and settings**

```
Row 1: [RESET][F1]  [F2]   [F3]   [F4]   [F5]  [F6]
Row 2: [TRANS][F7]  [F8]   [F9]   [F10]  [F11] [F12]
Row 3: [NO]   [VOLD][VOLU] [MUTE] [MPLY] [TRANS]
Row 4: [TRANS][NO]  [NO]   [NO]   [NO]   [NO]  [TRANS]
Row 5: [TRANS][TRANS][TRANS][TRANS][TRANS]

RESET = Bootloader
VOLD/VOLU = Volume control
MUTE/MPLY = Media controls
F1-F12 = Game menus, settings, graphics
```

---

## Key Differences from Default Keymap

| Feature | Default | Gaming |
|---------|---------|--------|
| Tapping Term | 200ms | 0ms (disabled) |
| Home Row Mods | Yes | No (separate keys) |
| Latency | Slight (modifier detection) | Zero (instant) |
| WPM Counter | Yes | Disabled |
| Layers | 5 (QWERTY/Symbols/Nav/Numpad/Function) | 4 (Gaming focused) |
| OLED Display | Shows layer name | Shows "GAMING" mode |
| Use Case | Typing, coding, productivity | Competitive gaming |

---

## Why No Tap-Hold in Gaming?

- 200ms latency feels sluggish in action games
- Modern games expect instant key response
- Modifiers mapped to separate keys instead
- TAPPING_TERM 0 ensures zero delay

---

## Build & Flash Gaming Keymap

```bash
# Build
qmk compile -kb ergodox_infinity -km gaming

# Flash (left half)
dfu-util -D ergodox_infinity_gaming.bin

# Flash (right half)
dfu-util -D ergodox_infinity_gaming.bin
```

---

## Customization for Your Games

### MOBA Games (League, Dota 2):
- S1-S4 = QWER abilities
- S5 = Summoner spell 1
- S6 = Summoner spell 2
- POT = Healing/Mana potion
- HOTBAR layer = Item actives

### FPS Games (Valorant, CS:GO):
- S1-S4 = Ability slots
- S5 = Ult/Special
- S6 = Weapon select
- POT = Defuse/Plant
- HOTBAR = Buy menu

### MMO Games (WoW, FFXIV):
- S1-S6 = Hotbar buttons
- POT = Health potion
- HOTBAR = Secondary hotbar
- Numpad = Ability rotation

---

## Gaming Performance Tips

1. Disable WPM counter for less CPU overhead (already done)
2. Reduce OLED updates (100ms interval already set)
3. No tap-hold = instant response (TAPPING_TERM 0)
4. Minimal layers = faster processing
5. Test in practice mode before competitive play

