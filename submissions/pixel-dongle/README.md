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

![image](https://github.com/user-attachments/assets/1027d547-3b78-462f-a5ca-55d53d44db1f)
![image](https://github.com/user-attachments/assets/9b7c4f1a-2e1d-44f0-9c41-1e5c43a7baa4)
![image](https://github.com/user-attachments/assets/d1f260de-b728-4eb6-9fa7-50725a71393b)
![image](https://github.com/user-attachments/assets/55e3e0bd-e829-451d-84e9-c2a5e986e034)


## BOM

| Comment | Footprint | Quantity | LCSC | Cost |
|---------|-----------|----------|------|------|
| 100uF | C_0805_2012Metric_Pad1.18x1.45mm_HandSolder | 1 | C23692977 | $0.4451 |
| 4.7nF | C_0603_1608Metric_Pad1.08x0.95mm_HandSolder | 6 | C7503499 | $0.0138 for 6 but min order is 100 for $0.23 |
| XIAO-ESP32-C3 | XIAO-ESP32C3-DIP | 1 |  | $4.99 |
| SK6812MINI | ScottoKeebs_Components:LED_SK6812MINI | 18 | C5149201 | $1.3336 |
| 6mm Push Button | SW_PUSH_6mm | 3 | C393938 | $0.0156 |
| CR2032 Holder | Battery:BatteryHolder_Keystone_3002_1x2032 | 1 | C238099 | $0.84 |
