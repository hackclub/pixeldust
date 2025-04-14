---
name: "Koji Ino"
slack_id: "U07QNKS5SKA"
github_handle: "@Person20020"
tutorial: "Default guide for which capacitors to use."
wokwi: "https://wokwi.com/projects/427432208043670529"
---

# Pixel-Dongle

Wokwi link: https://wokwi.com/projects/427432208043670529

My submission is a board that uses the ESP32-C3. 
This is for the wifi, so that it can be used on battery as a small temperature/humidity display. 
It has 23 neopixels that wrap around the edge that are for displaying whatever data.
It also has a integrated usb a plug so that it can be directly plugged into a usb port. 
This needs to be connected using a USB C male breakout board wired to the pads by the port.

![image](https://github.com/user-attachments/assets/bf3fde38-006f-465a-aac9-0bf5bf1dce90)
![image](https://github.com/user-attachments/assets/693a544f-dacf-4a65-9f94-bfda954afe30)

## BOM

| Comment | Footprint | Quantity | LCSC | Cost |
|---------|-----------|----------|------|------|
| 100uF | C_0805_2012Metric_Pad1.18x1.45mm_HandSolder | 1 |  | $0.0034 |
| 4.7nF | C_0603_1608Metric_Pad1.08x0.95mm_HandSolder | 6 |  | $0.0026 |
| XIAO-ESP32-C3 | XIAO-ESP32C3-DIP | 1 |  | $4.99 |
| SK6812MINI | SK6812MINI | 23 |  |  |
| 6mm Push Button | SW_PUSH_6mm | 3 | C393938 | $0.0156 |
| CR2032 Holder |  | 1 |  |  |
