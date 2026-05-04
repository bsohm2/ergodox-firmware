# Gaming Keymap Guide

## Overview

The gaming keymap is optimized for competitive gaming with a focus on:
- **Fast input response** (no tap-hold delays)
- **WASD movement** focused on left hand
- **Ability access** on right hand
- **Quick modifiers** without timing requirements

This is a **separate keymap** from the default QWERTY keymap. You can switch between them by flashing different builds.

## Key Differences from Default Keymap

| Aspect | Default | Gaming |
|--------|---------|--------|
| Tap-Hold | 200ms tapping term | Disabled (0ms) |
| Home Row Mods | Yes (Ctrl/Shift/Alt/GUI) | No (separate keys) |
| WPM Counter | Yes | Disabled |
| Layers | 5 layers (QWERTY, Symbols, Nav, Numpad, Function) | 4 layers (Gaming optimized) |
| Focus | General productivity | Combat responsiveness |

## Layer Breakdown

### Layer 0: GAMING (Base)
```
Left Hand (Movement + Combat)    Right Hand (Abilities + Utilities)
┌─────┬─────┬─────┬─────┬─────┐  ┌─────┬─────┬─────┬─────┬─────┐
│ ESC │  1  │  2  │  3  │  4  │  │  6  │  7  │  8  │  9  │  0  │
├─────┼─────┼─────┼─────┼─────┤  ├─────┼─────┼─────┼─────┼─────┤
│ TAB │  Q  │  W  │  E  │  R  │  │  Y  │  U  │  I  │  O  │  P  │
├─────┼─────┼─────┼─────┼─────┤  ├─────┼─────┼─────┼─────┼─────┤
│CTRL │  A  │  S  │  D  │  F  │  │  H  │  J  │  K  │  L  │  ;  │
├─────┼─────┼─────┼─────┼─────┤  ├─────┼─────┼─────┼─────┼─────┤
│SHFT │  Z  │  X  │  C  │  V  │  │  N  │  M  │  ,  │  .  │  /  │
├─────┼─────┼─────┼─────┼─────┤  ├─────┼─────┼─────┼─────┼─────┤
│ ALT │ --- │CTRL │ GUI │MODS │  │LEFT │ UP  │DOWN │RIGHT│ FN  │
└─────┴─────┴─────┴─────┴─────┘  └─────┴─────┴─────┴─────┴─────┘
                    Space/Enter                  Space/Enter

Left Pinky: Quick access to Alt + Shift + Ctrl
MODS Layer: Hold for ability modifiers
FN Layer: Hold for function keys + utilities
```

**Optimized for:**
- **W/A/S/D** in normal positions (no modifier interference)
- **Q/E/R/F/T** above/beside WASD for abilities
- **1-5** for item quick-select
- **Tab** for inventory
- **ESC** for menus
- **Spacebar** for jump
- **Arrow keys** on right for camera (if needed)

### Layer 1: GAMING_MODS (Hold right pinky in base layer)
Instant access to ability keys WITHOUT tap-hold delays:
```
Left Side: Ability Modifiers       Right Side: Ability Keys
F/G/H/J/K for rapid ability casts  6-0 for numbered abilities
```

### Layer 2: GAMING_NUMPAD (Hold right hand modifier)
Quick item selection via numpad:
```
P1-P9 mapped to ability #1-9
P0 for ultimate
```

### Layer 3: GAMING_FUNCTION (Hold right side modifier)
Media controls and game-specific utilities:
- F1-F12 for settings/console
- Volume controls
- Back to default keymap indicator

## Recommended Setup by Game

### MOBAs (League, Dota 2)
- **QWER** abilities on Q/W/E/R (already positioned)
- **1-5** for items (already at top)
- **D/F** for summoner spells
- **Hold MODS** for quick cast (no hold-to-confirm)

### FPS (Valorant, CS:GO)
- **WASD** movement unchanged
- **Q/E** for abilities
- **X/C/V** for grenades (already positioned)
- **1-4** for weapon quick-select
- Numpad layer for buying/economy

### MMO (WoW, FFXIV)
- **1-5** for hotbar buttons (top row)
- **Numpad** for secondary hotbar
- **F1-F12** for additional actions (Function layer)
- **SHIFT/CTRL/ALT** for modifier combos

## Building & Flashing

### Build Gaming Keymap
```bash
qmk compile -kb ergodox_infinity -km gaming
```

### Flash Gaming Build
```bash
dfu-util -D ergodox_infinity_gaming.bin
```

### Switch Back to Default
```bash
qmk compile -kb ergodox_infinity -km default
dfu-util -D ergodox_infinity_default.bin
```

## Customization

### Change Ability Keys
Edit `keymap/gaming/keymap.c` in the `[GAMING]` and `[GAMING_MODS]` layers.

Example: Map Q to ability 1:
```c
KC_Q,    // Currently just Q
// vs
KC_1,    // Change to 1 for item quick-select
```

### Add Game-Specific Macros
1. Add to `enum custom_keycodes`:
   ```c
   ABILITY_1 = SAFE_RANGE,
   ABILITY_2,
   // etc
   ```

2. Add case in `process_record_user()`:
   ```c
   case ABILITY_1:
     if (record->event.pressed) {
       SEND_STRING("q");  // Valorant ability key
     }
     return false;
   ```

3. Map in layer:
   ```c
   ABILITY_1, ABILITY_2, // etc
   ```

### Adjust OLED Display
Edit `oled_task_user()` to show:
- Current game mode
- Health/mana indicators (if applicable)
- Cooldown timers (advanced)

### Performance Tuning
In `config.h`, try:
```c
#define OLED_UPDATE_INTERVAL 150  // Less frequent = faster response
#define NO_ACTION_ONESHOT         // Reduce firmware size
```

## Why Separate Keymaps?

1. **No interference:** Gaming mode isn't cluttered with productivity layers
2. **Tap-hold disabled:** Eliminates 200ms latency from modifier detection
3. **Optimized OLED:** Shows game mode instead of productivity metrics
4. **Cleaner code:** Gaming-specific features don't bloat default keymap
5. **Easy switching:** Flash different build, instant new layout

## Performance Tips

1. **Disable WPM counter:** Reduces CPU load (already disabled)
2. **Reduce OLED updates:** Only 100ms intervals
3. **No tap-hold:** Instant key detection (already disabled)
4. **Minimal layers:** Only what's needed for gaming
5. **USB polling:** Already at 10ms default

## Common Questions

**Q: Can I use both keymaps at once?**
A: Not without coding. You'd need to add layer switching, which adds latency. Better to flash the one you need for that session.

**Q: How do I switch between keymaps?**
A: Flash the `.bin` file:
```bash
# For gaming
dfu-util -D ergodox_infinity_gaming.bin

# For productivity
dfu-util -D ergodox_infinity_default.bin
```

**Q: Can I add macros?**
A: Yes! Edit `process_record_user()` and use `SEND_STRING()` for ability combos.

**Q: Why no tap-hold in gaming?**
A: 200ms latency feels sluggish in competitive games. Direct key presses = instant response.

**Q: Can I customize this further?**
A: Absolutely. Edit `keymap/gaming/keymap.c` and rebuild with `qmk compile`.

## Advanced: Layer Switching Mid-Game

If you want to switch layers WITHOUT flashing, add to default keymap:

```c
// In main keymap config.h
#define LAYER_LOCK_ENABLE

// In keymap.c
#define GAMING_LAYER 5
```

Then map `LAYER_LOCK` key to switch at runtime. But this adds overhead and isn't recommended for competitive gaming.

---

**Tip:** Test in practice mode first before competitive play. Gaming response is very personal—adjust key positions and layer access to your muscle memory!
