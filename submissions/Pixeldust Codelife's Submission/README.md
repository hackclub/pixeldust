
name: "Delroy Prithvi Crasto"


slack_id: "U07V5RDRSL8"


github_handle: "@Programer6"


tutorial: [https://pixeldust.hackclub.com/guidelines](https://pixeldust.hackclub.com/guidelines)


wokwi: [https://wokwi.com/projects/XXXXXX](https://wokwi.com/projects/XXXXXX)  


# YOUR PROJECT NAME


Wokwi link: [https://wokwi.com/projects/430030406209979393](https://wokwi.com/projects/430030406209979393)


I would like to solder the PCB myself (as 100 leds in total) and I don't have soldering iron, so I would like to have one.

Describe your board in 2-3 sentences. What are you making? What will it do? 
This board is an audio-reactive LED matrix: a 10x10 array of WS2812B LEDs controlled by an XIAO ESP32-S3. It listens to audio using an ICS-43434 microphone, processes the audio signal with the ESP32-S3, and applies the results to generate light animations on the LED matrix that are dynamically reactive to the audio to produce an eye-grabbing experience. A push button provides a method of user input.

Schematic and PCB images:
<img width="1054" alt="Screenshot 2025-05-04 at 9 10 23 PM" src="https://github.com/user-attachments/assets/4fa76609-36ad-420a-94a5-920af77a8248" />
<img width="929" alt="Screenshot 2025-05-04 at 9 10 54 PM" src="https://github.com/user-attachments/assets/5915c858-9dfa-4c39-aaf8-6d8ba1723b06" />



A simplified BOM table

| Component                      | Designator(s) | Footprint                                        | Quantity | LCSC Part # | Cost (USD)                           | Notes                                 |
| ------------------------------ | ------------- | ------------------------------------------------ | -------- | ----------- | ------------------------------------ | ------------------------------------- |
| WS2812B LED                    | D1–D100       | SMD5050 (5.0 × 5.0 mm)                           | 100      | C114586     | \$0.0651 each ([LCSC][1], [LCSC][2]) | 50+ price tier; 100 pcs order         |
| XIAO ESP32‑S3                  | U2            | test\:XIAO-ESP32S3-DIP                           | 1        | C20467913   | \$8.2231 ([LCSC][3])                 | 1 pc price                            |
| ICS‑43434 Microphone           | MK1           | Sensor\_Audio\:InvenSense\_ICS-43434‑6\_3.5x2.65 | 1        | —           | \$3.12 each ([DigiKey][4])           | DigiKey pricing for 1 pc              |
| 0.1 µF Capacitor (0603)        | C2            | C\_0603\_1608Metric                              | 1        | C6136995    | \$0.034 ([LCSC][5])                  | Venkel X7R MLCC, 25 V                 |
| 10 kΩ Resistor (0603)          | R1–R3         | R\_0603\_1608Metric                              | 3        | C2889392    | — (not in stock) ([LCSC][6])         | VO 100 mW thick‑film; no price listed |
| Push Button (Cherry MX)        | SW1           | SW\_Cherry\_MX\_1.00u\_PCB                       | 1        | C5687012    | \$1.632 ([LCSC][7])                  | 1+ price tier; out of stock           |
| AMS1117‑3.3 V Regulator        | U1            | SOT‑223‑3                                        | 1        | C6186       | \$0.183 ([LCSC][8])                  | 5+ price tier                         |
| 1000 µF Electrolytic Capacitor | C1            | SMD, D = 10 mm × L = 10.2 mm                     | 1        | C3359       | \$0.1061 ([LCSC][9])                 | Honor Elec, 16 V,  ±20%               |
| 1×3 Pin Header, Vertical       | J1, J2        | PinHeader\_1x03\_P2.54mm\_Vertical               | 2        | C5116482    | \$0.0239 each ([LCSC][10])           | ZHOURI 2.54‑1\*3, 3 pins              |
| Barrel Jack (Würth)            | J3            | Barrel\_Jack\_Switch\_Pin3Ring                   | 1        | —           | — (not on LCSC)                      | Part 694106301002; see Mouser/LCSC†   |
| SMD Indicator LED              | LED           | LED\_SMD\:Generic                                | 1        | —           | — (user‑defined)                     | Status indicator                      |

[1]: https://www.lcsc.com/product-detail/Light-Emitting-Diodes-LED_Worldsemi-WS2812B-B-W_C114586.html "WS2812B-B/W | Worldsemi | Price | In Stock | LCSC Electronics"
[2]: https://www.lcsc.com/product-detail/Light-Emitting-Diodes-LED_5050-RGBIntegrated-Light-4Pin_C114586.html "WS2812B-B/W | Worldsemi | Price | In Stock | LCSC Electronics"
[3]: https://www.lcsc.com/product-detail/Bluetooth-Modules_Seeed-113991114_C20467913.html "113991114 Seeed IoT/Communication Modules | Bluetooth ... - LCSC"
[4]: https://www.digikey.com/en/products/detail/tdk-invensense/ICS-43434/6140298 "ICS-43434 TDK InvenSense | Audio Products - DigiKey"
[5]: https://www.lcsc.com/datasheet/lcsc_datasheet_2411272212_Venkel-C0603X7R250-104JNE-CT_C6136995.pdf "Venkel C0603X7R250-104JNE-CT Datasheet - LCSC"
[6]: https://www.lcsc.com/product-detail/Chip-Resistor-Surface-Mount_VO_C2889392.html "0603 ±5% 10K | VO | Price | In Stock | LCSC Electronics"
[7]: https://www.lcsc.com/product-detail/Mechanical-Keyboard-Shaft_CHERRY-MX1A-11NN_C5687012.html "cherry mx1a-11nn - Mechanical Keyboard Shaft - LCSC"
[8]: https://www.lcsc.com/product-detail/Linear-Voltage-Regulators-LDO_Advanced-Monolithic-Systems-AMS1117-3-3_C6186.html "AMS1117-3.3 | Advanced Monolithic Systems | Price | In Stock - LCSC"
[9]: https://www.lcsc.com/product-detail/Aluminum-Electrolytic-Capacitors-SMD_1000uF-16V_C3359.html "RVT1C102M1010 Honor Elec Capacitors | 1000uF 16V ±20% SMD ..."
[10]: https://www.lcsc.com/product-detail/Pin-Headers_ZHOURI-2-54-1-3_C5116482.html "2.54-1*3 | ZHOURI | Price | In Stock | LCSC Electronics"



Tell us a little bit about your design process. What were some challenges? What helped?

The project started as a portable audio visualizer powered by the ESP32-S3. I had the most difficult time with the first build because manually routing the traces on the PCB for all the components was difficult. I even struggled to fit in 100 LEDs in the design!  In the middle of the frustation, I almost forgot about the auto-tracer that helped move the process along significantly. Another difficultly I had was getting the connections correct for the ICS-43434 microphone, this was due to amount of components and specific pin requirements in the I2S protocol. I had to trace the wiring out from the datasheet to the pins on the ESP32-S3.

