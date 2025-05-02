---
name: "Marcus Kauffman"
slack_id: "U07D59XCG4U"
github_handle: "@mineinjava"
tutorial: n/a
wokwi: https://wokwi.com/projects/428315472209826817
---

# LEDial

Replace the wokwi link below with yours

Wokwi link: [https://wokwi.com/projects/428315472209826817](https://wokwi.com/projects/428315472209826817)

I have always been fascinated by thermostats, especially ones by NEST. I was wondering if I could make something similar, but for different information, with larger LEDs instead of a display.


I learned PCB design from hackpad/hackboard. I am super proud of the wiring on the back layer as well as the alignment of the rotary encoder. 

## Pictures:
<img width="1485" alt="image" src="https://github.com/user-attachments/assets/78edaf98-1e55-4c4d-9dd0-4c97380137ce" />
<img width="1394" alt="image" src="https://github.com/user-attachments/assets/47fd52c5-b59a-4059-acb6-b3623407cf61" />

<img width="896" alt="image" src="https://github.com/user-attachments/assets/7a438b2a-a8c5-480f-9bcf-1c724b1ce429" />
<img width="827" alt="image" src="https://github.com/user-attachments/assets/f455d983-d432-42d9-b9ab-f431c8fb2c22" />
<img width="897" alt="image" src="https://github.com/user-attachments/assets/f3bad527-09ba-4203-9f0f-18fc6a679896" />

<img width="864" alt="image" src="https://github.com/user-attachments/assets/bc715500-ce63-4cdc-9619-89013e5659a3" />
<img width="913" alt="image" src="https://github.com/user-attachments/assets/bed30fc6-9f47-47c8-87dd-2e8985229b78" />



| Designator                                                                                                                               | Footprint                                 | Quantity | Value                     | LCSC Part #             |     COST |
|------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------|----------|---------------------------|--------------------------|----------|
| C1, C2, C3, C4, C5                                                                                                                       | 0603                                      | 5        | 1u                        |      C15849                    | 0.0510 |
| C6                                                                                                                                       | 0603                                      | 1        | 10u                       |      C19702                    | 0.0120 |
| D*  | LED_WS2812B_PLCC4_5.0x5.0mm_P3.2mm         | 85       | WS2812B                   |           N/A               | N/A |
| J1                                                                                                                                       | USB_C_Receptacle_XKB_U262-16XN-4BVC11     | 1        | USB_C_Receptacle_USB2.0_14P |        DNP                  |
| J2                                                                                                                                       | PinHeader_1x03_P2.54mm_Vertical           | 1        | Conn_01x03_Socket         |          DNP                |
| J3                                                                                                                                       | PinHeader_1x03_P2.54mm_Vertical           | 1        | Conn_01x03_Pin            |             DNP             |
| J4                                                                                                                                       | PinHeader_1x02_P2.54mm_Vertical           | 1        | Conn_01x02_Pin            |              DNP            |
| J5                                                                                                                                       | PinHeader_1x02_P2.54mm_Vertical           | 1        | Conn_01x02_Socket         |                 DNP         |
| J6, J7, J8, J9                                                                                                                           | PinHeader_1x04_P2.00mm_Vertical           | 4        | Conn_01x04                |                    DNP      |
| R1, R2, R5, R6, R7                                                                                                                       | 0603                                      | 5        | 5.1K                      |    C23186                 | 0.0100     |
| R3                                                                                                                                       | 0603                                      | 1        | 100n                      |     C22775               | 0.0020      |
| R4                                                                                                                                       | 0603                                      | 1        | 10k                       |      C25804               | 0.0020     |
| SW1                                                                                                                                      | RotaryEncoder_Alps_EC11E-Switch_Vertical_H20mm | 1        | RotaryEncoder_Switch      |   N/A. EC11 rotary encoder with button         |              |
| U1                                                                                                                                       | ESP32-S3-WROOM-1                          | 1        | ESP32-S3-WROOM-1          |      C9900133532                    | $0.0365 |
| U2                                                                                                                                       | SOT-223-3_TabPin2                         | 1        | NCP1117-3.3_SOT223        |          C5400         | 0.0976       |

*

Diode designators:
```D1, D10, D11, D12, D13, D14, D15, D16, D17, D18, D19, D2, D20, D21, D22, D23, D24, D25, D26, D27, D28, D29, D3, D30, D31, D32, D33, D34, D35, D36, D37, D38, D39, D4, D40, D41, D42, D43, D44, D45, D46, D47, D48, D49, D5, D50, D51, D52, D53, D54, D55, D56, D57, D58, D59, D6, D60, D61, D62, D63, D64, D65, D7, D70, D71, D72, D73, D74, D75, D76, D77, D78, D79, D8, D80, D81, D82, D83, D84, D85, D86, D87, D88, D89, D9
```


