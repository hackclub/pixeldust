---
name: "Rudraksh Payaal"
slack_id: "U079HV9PTC7"
github_handle: "@Outdatedcandy92"
wokwi: https://wokwi.com/projects/428521730346688513
---

# RP2040PIXEL

Replace the wokwi link below with yours

Wokwi link: [https://wokwi.com/projects/428521730346688513](https://wokwi.com/projects/428521730346688513)

<!-- Uncomment the line below if you need a soldering iron -->
⚠️ I would like to reflow solder some components to reduce the pcba cost, so I would need a reflow pad

Describe your board in 2-3 sentences. What are you making? What will it do? Please add a lot of pictures here!!
A pcb that directly plugs into a USB A port, uses a bare rp2040 chip as its core with multiple neopixel leds on the back.

![Image](https://hc-cdn.hel1.your-objectstorage.com/s/v3/a3135e65a449ccddf64c305f7353ef5ab28b6ae0_screenshot_2025-04-17_201349.png)
![Image](https://hc-cdn.hel1.your-objectstorage.com/s/v3/e8a5ced249877eb8678fee3feda61494b370777e_screenshot_2025-04-17_201355.png)
![Image](https://hc-cdn.hel1.your-objectstorage.com/s/v3/8f765deceba06d427ba5fc439bf04ea736af2be9_screenshot_2025-04-17_201426.png)




A simplified BOM table
(pls include rough pricing of any extra components you're using)

<!-- Example: -->
| No. | Quantity | Comment               | Designator               | Footprint                     | Value  | Manufacturer Part       | Manufacturer       | Supplier Part | Supplier | JLCPCB Price | LCSC Price |
|-----|----------|-----------------------|--------------------------|-------------------------------|--------|--------------------------|--------------------|---------------|----------|--------------|------------|
| 1   | 3        | 1TS026A-1000-0550-CT | BOOT, BTN, RESET         | SW-SMD_4P-L2.6-W1.6-P0.75-LS3.0 |        | 1TS026A-1000-0550-CT     | HYP(鸿源精密)     | C913778       | LCSC     | 0.0926       |            |
| 2   | 3        | 10uF                 | C1, C4, C10              | C0402                         | 10uF   | CL05A106MQ5NUNC          | SAMSUNG(三星)     | C15525        | LCSC     | 0.0047       |            |
| 3   | 2        | 15pF                 | C2, C3                   | C0402                         | 15pF   | 0402CG150J500NT          | FH(风华)          | C1548         | LCSC     | 0.001        |            |
| 4   | 10       | 100nF                | C5, C6, C7, C9, C11–C16  | C0402                         | 100nF  | CL05B104KO5NNNC          | SAMSUNG(三星)     | C1525         | LCSC     | 0.0012       |            |
| 5   | 1        | 1uF                  | C8                       | C0402                         | 1uF    | CL05A105KA5NQNC          | SAMSUNG(三星)     | C52923        | LCSC     | 0.003        |            |
| 6   | 8        | XL-1615RGBC-WS2812B  | LED1–LED8                | LED-SMD_4P-L1.6-W1.5_XL-1615RGBC-WS2812B-1 |        | XL-1615RGBC-WS2812B      | XINGLIGHT(成兴光) | C5349954      | LCSC     | 0.0467       |            |
| 7   | 2        | 1kΩ                  | R1, R5                   | R0402                         | 1kΩ    | 0402WGF1001TCE           | UNI-ROYAL(厚声)    | C11702        | LCSC     | 0.0006       |            |
| 8   | 2        | 27.4Ω                | R3, R4                   | R0402                         | 27.4Ω  | 0402WGF274JTCE           | UNI-ROYAL(厚声)    | C31439        | LCSC     | 0.0003       |            |
| 9   | 1        | 330Ω                 | R6                       | R0402                         | 330Ω   | 0402WGF3300TCE           | UNI-ROYAL(厚声)    | C25104        | LCSC     | 0.0006       |            |
| 10  | 1        | RP2040               | U1                       | LQFN-56_L7.0-W7.0-P0.4-EP     |        | RP2040                   | Raspberry Pi(树莓派) | C2040       | LCSC     | 1.1055       |            |
| 11  | 1        | NCP1117ST33T3G       | U2                       | SOT-223-3_L6.5-W3.4-P2.30-LS7.0-BR |        | NCP1117ST33T3G           | onsemi(安森美)     | C26537        | LCSC     | 0.2792       |            |
| 12  | 1        | W25Q128JVSIQ         | U3                       | SOIC-8_L5.3-W5.3-P1.27-LS8.0-BL |        | W25Q128JVSIQ             | WINBOND(华邦)      | C97521        | LCSC     | 0.573        |            |
| 13  | 1        | ABM8-272-T3          | U4                       | CRYSTAL-SMD_4P-L3.2-W2.5-BL   |        | ABM8-272-T3              | ABRACON            | C20625731     | LCSC     | 0.3705       |            |
| 14  | 1        | SN74AHCT1G125DCKR    | U5                       | SC-70-5_L2.0-W1.3-P0.65-LS2.1-BL |        | SN74AHCT1G125DCKR        | TI(德州仪器)       | C350557       | LCSC     | 0.0818       |            |
| 15  | 1        | USBA_PCB             | X1                       | USBA_PCB                      |        |                          |                    |               |          |              |     |
Tell us a little bit about your design process. What were some challenges? What helped?

This was my first time making a board with a MCU and it was pretty challenging and fun. Since I was going for a usb sized pcb, fitting and routing the components was a major challenge but eventually everything came together prefectly!

Some images of your design (make sure to include both the PCB and Schematic!):
![Image](https://hc-cdn.hel1.your-objectstorage.com/s/v3/03a5399c833b8de99282046e7260baf1da8b5946_image.png)
![Image](https://hc-cdn.hel1.your-objectstorage.com/s/v3/9739c503f1b5b851248e76a0179c0d99e4e4bf7c_image.png)


