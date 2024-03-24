# esp32-sandbox

Proof of concept embedded Lua scripting in esp32

Tested with esp32-WROOM-32 and esp32-c3 using esp32-idf toolchain

## Prerequisites
- GNU/Linux x86 (if using WSL, check [usbipd](https://github.com/dorssel/usbipd-win) with esp32 vscode ext)
- lua-5.4
- esp32
- esp-idf
- `. ~/esp/esp-idf/export.sh` (i.e., correct environment set)

## Build
- `idf.py menuconfig # set target to esp32`
- `bash prepare.sh`
- `mkdir build && cd build`
- `cmake ..`
- `cmake --build .`

## TODO
- [ ] Create Lua wrapper around esp-idf
- [ ] Link and load Lua script as component
- [ ] Callbacks / Event handlers?

## Resources
- https://github.com/lua/lua
- https://github.com/dorssel/usbipd-win
- https://github.com/espressif/esp-idf
- https://github.com/espressif/esp-idf/tree/master/examples/get-started/hello_world
- https://github.com/espressif/esp-idf/blob/master/examples/peripherals/gpio/generic_gpio/main/gpio_example_main.c
