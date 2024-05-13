# **Hardware**

This folder contains the hardware design for the Telematics Workshop Board.

## 🚀 Getting Started

### Prerequisites

- [Eagle](https://www.autodesk.com/products/eagle/overview) (Untuk membuka file .sch dan .brd)
- [Fusion 360](https://www.autodesk.com/products/fusion-360/overview) (Opsi lain untuk membuka file)

## 🕸 Schematic

This is the schematic diagram for the Board will be used in the workshop.

![Schematic](../doc/schematic.png)

## 💲 Bill of Material

|   Designator   | Quantity | Package  | Value  |      Description      |
|:--------------:|:--------:|:--------:|:------:|:---------------------:|
|    ESP-12F     |    1     |    -     |   -    |    ESP8266 Module     |
|       U1       |    1     | SOIC-127 | CH340C |    IC USB to UART     |
|       U2       |    1     | SOT-223  |  3V3   | Voltage Regulator 3V3 |
|       D1       |    1     |   0805   |  Red   |          LED          |
|      NEO       |    1     |   5050   |  RGB   |        WS2812B        |
|       F1       |    1     |   1206   | 750mA  |    Resettable Fuse    |
|       J1       |    1     |    -     |   6P   |      USB Type-C       |
|   BOOT, RST    |    2     |    -     |   -    |      Push Button      |
| R1, R2, R3, R4 |    4     |   0805   |  10K   |       Resistor        |
|     R5, R6     |    2     |   0805   |  5.1K  |       Resistor        |
|       R7       |    1     |   0805   |   1K   |       Resistor        |
|       C1       |    1     |   2412   |  100u  |   Kapasitor (Polar)   |
|     C2, C3     |    2     |   0805   |  10u   | Kapasitor (Nonpolar)  |
|       C4       |    1     |   0805   |   1u   | Kapasitor (Nonpolar)  |
|       C5       |    1     |   0805   |  10n   | Kapasitor (Nonpolar)  |
|     Q1, Q2     |    2     |  SOT-23  | BSS138 |   N-Channel MOSFET    |


## 👨‍🔧 PCB Assembly

Refer to the image below for detailed placement and routing.

![PCB Layout](../doc/pcb_layout.png)

> Click the image to view the full resolution.

### SMD Polarity

...

## 📚 Resources

### Telematics Workshop Board

Access the design files for the Telematics Workshop Board directly from this repository:

- [Schematic](schematic/)
- [Board Design](pcb/)
- [3D Model](enclosure/)

### Enclosure

Access the 3D printable enclosure files from this repository, with contributions from the following individuals:

- [B401 Robotics]()

### Libraries

Access the components used in this Schematic and PCB design through the [WorTel Library](https://library.io/libraries/44299601-WorTel-Libray-2024), compatible with both Eagle and Fusion 360.


<!-- ## SMD Polarity

SMD Led memiliki 2 kaki, yaitu kaki anoda dan kaki katoda. Perhatikan gambar di bawah ini untuk mengetahui kaki mana yang merupakan kaki anoda dan kaki katoda.

![SMD Led Polarity](../images/led_katoda.jpg)

Capacitor Tantalum merupakan salah satu jenis capacitor polar. Perhatikan gambar di bawah ini untuk mengetahui kaki mana yang merupakan kaki anoda(+).

![Capacitor Tantalum Polarity](../images/capacitor_katoda.png)

Untuk melihat component apa saja yang polaritasnya perlu diperhatikan, silakan lihat gambar di bawah ini.

![Polar Component](../images/polar_component.png) -->
