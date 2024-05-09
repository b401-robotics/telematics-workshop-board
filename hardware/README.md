# **Hardware**

## 🚀 Getting Started

### Prerequisites

- [Eagle](https://www.autodesk.com/products/eagle/overview) (Untuk membuka file .sch dan .brd)
- [Fusion 360](https://www.autodesk.com/products/fusion-360/overview) (Opsi lain untuk membuka file)

## 🕸 Schematic

This is the schematic diagram for the Board will be used in the workshop. Please save this image for your reference after the workshop ends.

![Schematic](../images/schematic.png)

## 💸 Bill of Material

| Designator | Quantity | Package | Value |      Description      |
|:----------:|:--------:|:-------:|:-----:|:---------------------:|
|  R1 - R4   |    4     |  0805   |  10K  |       Resistor        |
|  R5 - R7   |    3     |  0805   |  330  |       Resistor        |
|  R8 - R10  |    3     |  0805   |  100  |       Resistor        |
|    R11     |    1     |  0805   |  1K   |       Resistor        |
|     C1     |    1     |  2412   | 100u  |   Kapasitor (Polar)   |
|  C2 - C3   |    2     |  0805   |  10u  | Kapasitor (Nonpolar)  |
|     D1     |    1     |  5050   |  RGB  |          LED          |
|     D2     |    1     |  0805   |  Red  |          LED          |
|    SW3     |    1     |    -    |   -   |    Push Button (1)    |
| SW1 - SW2  |    2     |    -    |   -   |    Push Button (2)    |
|    IC1     |    1     | SOT-223 |  3V3  | Voltage Regulator 3V3 |
|     F1     |    1     |  1206   | 750mA |         Fuse          |
|     J1     |    1     |    -    |  6P   |      USB Type-C       |

## SMD Polarity

SMD Led memiliki 2 kaki, yaitu kaki anoda dan kaki katoda. Perhatikan gambar di bawah ini untuk mengetahui kaki mana yang merupakan kaki anoda dan kaki katoda.

![SMD Led Polarity](../images/led_katoda.jpg)

Capacitor Tantalum merupakan salah satu jenis capacitor polar. Perhatikan gambar di bawah ini untuk mengetahui kaki mana yang merupakan kaki anoda(+).

![Capacitor Tantalum Polarity](../images/capacitor_katoda.png)

Untuk melihat component apa saja yang polaritasnya perlu diperhatikan, silakan lihat gambar di bawah ini.

![Polar Component](../images/polar_component.png)
