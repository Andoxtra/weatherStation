## Starting the Code
- Install in VSCode PlatformIO
- Connect Weather Station per USB
- Compile the code with ```pio run```
- Compile & Upload the code with ``pio run --target upload``
- Compile & Upload & Monitor ``pio run -t upload -t monitor``

## Common Error

When the Error ``A fatal error occurred: No serial data received.``
occurs you need to
- Remove the cap
- Hold the button in the middle
- Disconnect the USB Cable from the PC
- Reconnect the USB Cable
- Release the button in the middle
- Retry the upload
- When the upload succeeds press the button furthest away from the USB port


## Pins / Addresses

### Button
- USB Near **Pin: 4**
- Middle **Pin: 0**

### BME280
- Address **0x76**

### LED
- Pin **38**

### Display
- Address **0x3c**

