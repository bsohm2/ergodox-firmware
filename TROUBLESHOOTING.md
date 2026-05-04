# ErgoDox Infinity Troubleshooting Guide

## Connection Issues
n## About This Document

This is your **first stop** when something goes wrong with your ErgoDox Infinity firmware or hardware.

**Use this when:**
- Right half wont connect
- Firmware wont compile
- Keys dont respond as expected
- Getting USB errors
- Keyboard randomly disconnects during use

### Right Half Disconnects After a Few Keypresses

**Symptom:** Right side works for a moment, then stops responding.

**Root Cause:** IRQ priority conflict between I2C (LED driver) and UART (split communication). This is why we pin to QMK 0.14.0.

**Solution:**
1. Ensure you're on **QMK 0.14.0** (check GitHub Actions artifact)
2. Check USB cable connection to **left half only**
3. Rebuild with this config (already in place):
   ```c
   #define SPLIT_MAX_CONNECTION_ERRORS 65535
   ```
4. If still fails, try:
   - Different USB cable
   - Different USB port
   - Reseat the I2C connector between halves

### Right Half Never Connects

**Symptom:** Right side doesn't respond on first boot.

**Solutions:**
1. **Reseat I2C cable:** The small connector between left and right PCBs can get loose
2. **Flash right half independently:**
   - Unplug left half
   - Flash right half: `dfu-util -D ergodox_infinity_default.bin`
   - Plug back in
3. **Check split transport mode:** Config should have:
   ```c
   #define SPLIT_USB_DETECT
   ```

### Left Half Keeps Disconnecting from PC

**Symptom:** Keyboard repeatedly connects/disconnects from USB.

**Solutions:**
1. **Try different USB cable** (known USB 3.0 compatibility issues)
2. **Reduce polling rate** in config:
   ```c
   #define USB_POLLING_INTERVAL_MS 10
   ```
3. **Check for loose USB connector** on PCB
4. **Disable NO_USB_STARTUP_CHECK temporarily:**
   - Comment out in keyboard_config.h
   - Rebuild and test

## Bootloader Issues

### Cannot Enter DFU Mode

**Symptom:** `dfu-util -l` shows no devices when holding reset.

**Solutions:**
1. **Hold reset button longer** (3-5 seconds minimum)
2. **Verify you are using the correct reset button:**
   - Look for RESET label on PCB
   - Not the same as QK_BOOT key
3. **Try different USB port** (avoid USB 3.0)
4. **Reset multiple times** in quick succession
5. **Check USB cable connection** while holding reset

### dfu-util Says Permission Denied

**Linux/macOS:**
```bash
sudo dfu-util -D ergodox_infinity_default.bin
```

**Better solution (Linux - add udev rules):**
```bash
sudo cat > /etc/udev/rules.d/50-dfu.rules << 'EOF'
SUBSYSTEMS=="usb", ATTRS{idVendor}=="0483", ATTRS{idProduct}=="df11", MODE="0666"
EOF
sudo udevadm control --reload
```

### Firmware Uploaded But Keyboard Does Not Work

**Symptom:** DFU upload succeeds, but keys don't register.

**Solutions:**
1. **Flash both halves** (left first, then right)
2. **Verify correct keyboard in build:**
   ```bash
   qmk compile -kb ergodox_infinity -km default
   ```
3. **Check for RESET key in Function layer:** Pressing it by mistake puts left half back in bootloader
4. **Reboot keyboard** after flashing (unplug, wait 5s, replug)

## Keymap Issues

### Tap-Hold Keys Not Working

**Symptom:** Holding A does not activate Ctrl, tapping does not produce A.

**Solutions:**
1. **Adjust TAPPING_TERM** in keyboard_config.h:
   ```c
   #define TAPPING_TERM 200
   ```
   - Lower = easier to tap, harder to hold
   - Higher = easier to hold, harder to tap
2. **Enable PERMISSIVE_HOLD** (already enabled):
   ```c
   #define PERMISSIVE_HOLD
   ```
3. **Test individually:** Hold just one modifier key for 1+ second

### Macros Not Typing Text

**Symptom:** Macro key pressed but nothing appears.

**Solutions:**
1. **Verify ENABLE_SEND_STRING is enabled:**
   ```c
   #define ENABLE_SEND_STRING
   ```
2. **Check macro is in Function layer:**
   - Hold Function key on right side
   - Press macro key
3. **Rebuild and reflash:**
   ```bash
   qmk compile -kb ergodox_infinity -km default
   dfu-util -D ergodox_infinity_default.bin
   ```
4. **Check for typos in macro text:**
   ```c
   SEND_STRING("developer@example.com");
   ```

### OLED Display Not Showing Layer Name

**Symptom:** Screen shows nothing or old data.

**Solutions:**
1. **Enable OLED in config:**
   ```c
   #define OLED_DRIVER_ENABLE
   ```
2. **Adjust brightness** (0-255):
   ```c
   #define OLED_BRIGHTNESS 127
   ```
3. **Check I2C connection:** OLED uses I2C
4. **Rebuild with verbose output:**
   ```bash
   qmk compile -kb ergodox_infinity -km default -v
   ```

### OLED Screen Flickers or Has Artifacts

**Symptom:** Display glitches, text overlaps, partial updates.

**Solutions:**
1. **Reduce OLED update frequency:**
   ```c
   #define OLED_UPDATE_INTERVAL 100
   ```
2. **Check I2C cable** (same cable powers OLED)
3. **Disable WPM temporarily:**
   ```c
   // #define WPM_ENABLE
   ```

## Performance Issues

### Keyboard Feels Slow or Laggy

**Symptom:** Keys register with noticeable delay.

**Solutions:**
1. **Disable WPM counter:**
   ```c
   // #define WPM_ENABLE
   ```
2. **Disable OLED updates:**
   ```c
   // #define OLED_DRIVER_ENABLE
   ```
3. **Reduce split communication interval:**
   ```c
   #define SPLIT_TRANSPORT_MIRROR
   ```

### Battery-Powered Right Half Dies Quickly

**Symptom:** Right half runs out of power after 1-2 hours.

**Solutions:**
1. **Disable OLED on right half**
2. **Disable WPM counter:**
   ```c
   // #define WPM_ENABLE
   ```
3. **Check battery connections** for corrosion
4. **Use lower-power firmware build**

## Build Issues

### Firmware Too Large for Chip

**Symptom:** Compilation succeeds but flashing fails with size error.

**Solutions:**
1. **Disable unnecessary features:**
   ```c
   // #define OLED_DRIVER_ENABLE
   // #define WPM_ENABLE
   ```
2. **Reduce number of layers** (remove unused ones)
3. **Simplify macros** (shorter text)

### Build Fails with Unknown Keyboard

**Symptom:** Error like "ergodox_infinity not found"

**Solutions:**
1. **Ensure QMK is up to date:**
   ```bash
   qmk setup --update
   ```
2. **Check keyboard name:**
   ```bash
   qmk list-keyboards | grep ergodox
   ```

### ARM Toolchain Not Found

**Symptom:** "arm-none-eabi-gcc: command not found"

**Solutions:**
```bash
qmk setup --with-tests
```

Or manually install based on your OS.

## OLED/Display Issues

### Screen Stuck on Old Layer Name

**Symptom:** Display shows QWERTY even when on SYMBOLS layer.

**Solutions:**
1. **Check layer state:** Press a unique key from current layer
2. **Rebuild with layer name refresh**
3. **Power cycle keyboard** (unplug for 10 seconds)

### WPM Counter Always Shows 0

**Symptom:** WPM: 0 displayed always.

**Solutions:**
1. **Enable WPM in config:**
   ```c
   #define WPM_ENABLE
   ```
2. **Type for a few seconds** (takes time to calculate)

## General Troubleshooting Steps

1. **Check QMK version:**
   ```bash
   qmk --version
   ```

2. **Rebuild from scratch:**
   ```bash
   qmk clean
   qmk compile -kb ergodox_infinity -km default
   ```

3. **Test with default keymap**

4. **Check GitHub Issues** for similar problems

5. **Contact QMK Discord** for help

## Advanced Debugging

### Serial Console Output
Enable in config:
```c
#define DEBUG_ENABLE
```

### Erase and Rebuild
If all else fails, do a complete rebuild.

### Check Hardware
- **Multimeter:** Test for continuity on I2C lines
- **Microscope:** Check for solder bridges
- **USB analyzer:** Check if right half is detected

---

**If you cannot resolve the issue:**
1. Check the commit history in this repo
2. Search QMK documentation
3. File an issue with:
   - Exact error message
   - QMK version
   - What you were trying to do
