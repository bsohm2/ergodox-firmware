# ErgoDox Infinity Complete Keymap Legend

## Physical Keyboard Layout

The ErgoDox Infinity has 7 columns per side plus thumb clusters (2x3).

```
Left Hand (7 wide)              Right Hand (7 wide)

ROW 1:  [ESC] [1] [2] [3] [4] [5] [BSPC]  |  [EQL] [6] [7] [8] [9] [0] [BSPC]
ROW 2:  [TAB] [Q] [W] [E] [R] [T] [LBRK]  |  [RBRK] [Y] [U] [I] [O] [P] [BSLH]
ROW 3:  [CTRL][A] [S] [D] [F] [G]         |  [H] [J] [K] [L] [;] [QUOT]
ROW 4:  [SHIFT][Z][X] [C] [V] [B] [RBRK]  |  [LBRK] [N] [M] [,] [.] [/] [SHIFT]
ROW 5:  [FN][GUI][ALT][PGUP][PGDN]        |  [LEFT][UP][DOWN][RIGHT][MUTE]

THUMB:  [PSCR]  [HOME]          |  [RCTL]  [MENU]
        [END ]  [END ]          |  [RALT]  [RALT]
        [SPACE] [ENTER]         |  [RGUI]  [SPACE]
```

---

## Layer 0: QWERTY (Base Layer with Tap-Hold Modifiers)

**Left Hand:**
```
Row 1: [ESC]  [1]   [2]   [3]    [4]    [5]   [BSPC]
Row 2: [TAB]  [Q]   [W]   [E]    [R]    [T]   [LBRK-toggle SYMBOLS]
Row 3: [CTRL] [A^]  [S^]  [D^]   [F^]   [G]
Row 4: [SHFT] [Z]   [X]   [C]    [V]    [B]   [RBRK-toggle NAV]
Row 5: [FN]   [GUI] [ALT] [PGUP] [PGDN]

^ = Tap-hold modifier (200ms)
A = Tap for A, Hold for Ctrl
S = Tap for S, Hold for Shift
D = Tap for D, Hold for Alt
F = Tap for F, Hold for GUI
```

**Right Hand:**
```
Row 1: [EQL]  [6]   [7]   [8]    [9]   [0]   [BSPC]
Row 2: [LBRK] [Y]   [U]   [I]    [O]   [P]   [BSLH]
Row 3: [H]    [J^]  [K^]  [L^]   [;^]  [QUOT]
Row 4: [RBRK] [N]   [M]   [,]    [.]   [/]   [SHFT]
Row 5: [LEFT] [UP]  [DOWN][RIGHT][MUTE]

^ = Tap-hold modifier
J = Tap for J, Hold for GUI
K = Tap for K, Hold for Alt
L = Tap for L, Hold for Shift
; = Tap for ;, Hold for Ctrl
```

---

## Layer 1: SYMBOLS (Hold LBRK or RBRK)

**Left Hand:**
```
Row 1: [NO]   [F1]  [F2]  [F3]   [F4]   [F5]  [TRANS]
Row 2: [TRANS][!]   [@]   [{]    [}]    [|]   [TRANS]
Row 3: [TRANS][#]   [$]   [(]    [)]    [`]
Row 4: [TRANS][%]   [^]   [[]    []]    [~]   [TRANS]
Row 5: [TRANS][TRANS][TRANS][TRANS][TRANS]
```

**Right Hand:**
```
Row 1: [TRANS][F6]  [F7]  [F8]   [F9]   [F10] [F11]
Row 2: [TRANS][UP]  [7]   [8]    [9]    [*]   [F12]
Row 3: [DOWN] [4]   [5]   [6]    [+]    [TRANS]
Row 4: [TRANS][&]   [1]   [2]    [3]    [\]   [TRANS]
Row 5: [TRANS][DOT] [0]   [EQL]  [TRANS]
```

TRANS = Transparent (shows layer below)
NO = Disabled key

---

## Layer 2: NAVIGATION (Hold RBRK)

**Right Hand Navigation:**
```
Row 1: [TRANS][NO]  [NO]  [NO]   [NO]   [NO]  [NO]
Row 2: [TRANS][PGUP][HOME][UP]   [END]  [NO]  [NO]
Row 3: [PGDN] [LEFT][DOWN][RIGHT][NO]   [TRANS]
Row 4: [TRANS][NO]  [BSPC][DEL]  [NO]   [NO]  [TRANS]
Row 5: [TRANS][TRANS][TRANS][TRANS][TRANS]

Provides arrow keys, page nav, home/end, backspace/delete
```

---

## Layer 3: NUMPAD (Hold right hand modifier key)

**Right Hand Numpad:**
```
Row 1: [TRANS][NO]  [NLCK] [/]   [*]   [-]   [NO]
Row 2: [TRANS][NO]  [P7]   [P8]  [P9]  [+]   [NO]
Row 3: [NO]   [P4]  [P5]   [P6]  [+]   [TRANS]
Row 4: [TRANS][NO]  [P1]   [P2]  [P3]  [PENT][TRANS]
Row 5: [TRANS][P0]  [PDOT] [PENT][TRANS]

NLCK = Num Lock
P0-P9 = Numpad digits
PENT = Numpad Enter
PDOT = Numpad decimal point
```

---

## Layer 4: FUNCTION (Hold FN key on left)

**Right Hand Functions:**
```
Row 1: [RESET][F1]  [F2]  [F3]   [F4]   [F5]  [F6]
Row 2: [TRANS][F7]  [F8]  [F9]   [F10]  [F11] [F12]
Row 3: [NO]   [EMAIL][URL][CODE] [NO]   [TRANS]
Row 4: [TRANS][NO]  [NO]  [NO]   [NO]   [NO]  [TRANS]
Row 5: [TRANS][TRANS][TRANS][TRANS][TRANS]

RESET = Bootloader (flash mode)
EMAIL = developer@example.com
URL = https://github.com
CODE = C program template
```

---

## QMK Key Code Reference

**Letters:** KC_A - KC_Z
**Numbers:** KC_0 - KC_9

**Modifiers:**
- Ctrl: KC_LCTL (left), KC_RCTL (right)
- Shift: KC_LSFT (left), KC_RSFT (right)
- Alt: KC_LALT (left), KC_RALT (right)
- GUI/Super: KC_LGUI (left), KC_RGUI (right)

**Navigation:**
- Arrows: KC_LEFT, KC_RIGHT, KC_UP, KC_DOWN
- Page: KC_PGUP, KC_PGDN
- Home/End: KC_HOME, KC_END
- Insert/Delete: KC_INS, KC_DEL
- Backspace: KC_BSPC

**Function Keys:** KC_F1 - KC_F12

**Symbols:**
- ! @ # $ % ^ & * ( ) - = [ ] { } ; ' , . / \ | ` ~

**Special:**
- Space: KC_SPC
- Tab: KC_TAB
- Enter: KC_ENT
- Escape: KC_ESC
- Caps Lock: KC_CAPS

**Numpad:**
- Digits: KC_P0 - KC_P9
- Operations: KC_PPLS (+), KC_PMNS (-), KC_PAST (*), KC_PSLS (/)
- Num Lock: KC_NLCK
- Decimal: KC_PDOT
- Enter: KC_PENT

**Media:**
- Mute: KC_MUTE
- Volume Up: KC_VOLU
- Volume Down: KC_VOLD
- Play/Pause: KC_MPLY
- Next Track: KC_MNXT
- Previous: KC_MPRV
- Browser Back: KC_WBAK

**Layer Functions:**
- MO(layer) = Momentary layer (hold activates)
- LT(layer, key) = Layer Tap (hold for layer, tap for key)
- TG(layer) = Toggle layer (press to switch)

---

## Tap-Hold Modifier Summary (200ms)

Press the key quickly = normal character
Hold the key 200ms+ = modifier

Left hand home row:
- A = Character A, or Ctrl (when held)
- S = Character S, or Shift (when held)
- D = Character D, or Alt (when held)
- F = Character F, or GUI (when held)

Right hand home row:
- J = Character J, or GUI (when held)
- K = Character K, or Alt (when held)
- L = Character L, or Shift (when held)
- ; = Character ;, or Ctrl (when held)

---

## Abbreviations

- TRANS = KC_TRNS (Transparent - pass through to layer below)
- NO = KC_NO (Disabled key)
- CTRL = Control
- SHFT = Shift
- ALT = Alt
- GUI = GUI/Super key (Windows key on PC, Command on Mac)
- LBRK = Left bracket [
- RBRK = Right bracket ]
- BSLH = Backslash \
- PGUP = Page Up
- PGDN = Page Down
- BSPC = Backspace
- DEL = Delete
- PSCR = Print Screen
- NLCK = Num Lock
- Pxx = Numpad key (P0-P9, PPLS, PMNS, PAST, PSLS, PDOT, PENT)
- ESC = Escape
- EQL = Equals =

