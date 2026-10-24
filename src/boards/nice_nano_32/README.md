# nice_nano_32

Clock-only variant of `nice_nano` for nRF52840 with an external 32 MHz crystal.
Pins, USB IDs, UF2 board ID and SoftDevice s140 6.1.1 remain compatible with
`nice_nano`. USB product name, BLE DFU name, UF2 product name and volume label
are `WK_840_D` (the FAT volume label is padded to 11 characters).

`BOARD_LFCLK_SYNTH=1` selects `NRF_CLOCK_LF_SRC_SYNTH` when the bootloader
enables the BLE SoftDevice. This derives the 32.768 kHz LFCLK from HFCLK;
it does not select an external 32.768 kHz crystal. Both RC calibration
parameters are zero. The advertised accuracy remains a conservative 250 ppm.
Keeping HFCLK running increases power consumption during BLE DFU.

USB-only startup retains the shared RC configuration. Application firmware
configures its own clocks; updating this bootloader does not change them.

Build: `make BOARD=nice_nano_32 all`

Outputs in `_build/build-nice_nano_32/`:

- `update-*_nosd.uf2`: bootloader self-update for a compatible existing
  Adafruit UF2 bootloader; does not update the installed SoftDevice.
- `*_s140_6.1.1.hex`: combined bootloader and SoftDevice image for SWD.
- `*_s140_6.1.1.zip`: bootloader and SoftDevice package for Adafruit serial DFU.

Build validation passed for this board, `feather_nrf52840_express`, and
`feather_nrf52832`. No hardware was flashed. USB enumeration, double reset,
BLE advertising, OTA transfer and application startup need device testing.

Reference: https://docs.nordicsemi.com/r/bundle/ps_nrf52840/page/clock.html
