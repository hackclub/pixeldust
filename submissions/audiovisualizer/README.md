---
name: "Hridya Agrawal"
slack_id: "U0842GMRJKC"
github_handle: "@hridaya423"
---

# Audio Visualizer

⚠️ I would like to have 120 leds for the audio visualizer, so I would need a soldering iron.

Wokwi link: https://wokwi.com/projects/428497544685566977

This PCB captures audio from an I2S microphone and displays the frequency spectrum on a 120-LEDs. It uses FFT to adjust the LED brightness based on the audio data.

## BOM

| Comment           | Footprint                                      | Quantity 
|-------------------|------------------------------------------------|----------|
| WS2812B           | LED_SMD:LED_WS2812B_PLCC4_5.0x5.0mm_P3.2mm     | 120      |
| ICS-43434         | Sensor_Audio:InvenSense_ICS-43434-6_3.5x2.65mm | 1        |
| XIAO-RP2040-DIP   |Seeed Studio XIAO Series Library:XIAO-RP2040-DIP| 1        |

<img width="909" alt="image" src="https://github.com/user-attachments/assets/5bf030fb-a802-4f67-bf97-23652597b09b" />
<img width="520" alt="image" src="https://github.com/user-attachments/assets/2e9a5819-08c6-43ef-a1cf-9f3b2b519502" />
