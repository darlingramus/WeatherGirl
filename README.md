# WeatherGirl
**Complete weather station** on clean **ATmega328P**.

**Project includes:**
- code in **C** for **PlatformIO**
- projects' pcb in **KiCad**
- Sensors: BME280, OLED SSD1306, DS3231-RTC and TTP223

## Used components
`| Microcontroler | ATmega328P`

`| Sensor temp/pres/hum | BME280`

`| OLED display | OLED SSD1106`

`| DS3231 clock | RTC`

`| Pull-up resistor | 10kΩ`

`| Capacitors | 100nF x 3 | 100uF`

`| ISP programmer | 6-pin (2x3) `

`| Power supply | Screw terminal | 5V` 

`| Stabilizer | AMS1117 5V to 3V3`

## Software requirements

- **PlatformIO** (extention to VSCode or CLion)
- **ISP Programmer**
- **KiCad 10.0** – if you want to check/add something

# Software

## Install and boot

### Step 1: clone repo
```bash
git clone https://github.com/darlingramus/WeatherGirl.git
cd WeatherGirl
```
### Step 2: 
- Open VSCode/Clion
- Install PlatformIO extention
- Open folder WeatherGirl (PlatformIO will find the project automaticaly)

### Step 3: Configure `platformio.ini`
```bash
[env:ATmega328P]
platform = atmelavr
board = ATmega328P
framework = baremetal
upload_protocol = AVRISP
debug_tool = AVRISP
```
### Step 4: Connect ISP programmer
### Step 5: Compile and upload code
PlatformIO: Click upload button

# Hardware - KiCad
PCB designed in KiCad 10.0

## Schematic

<img width="1130" height="778" alt="image" src="https://github.com/user-attachments/assets/2e9ee109-33c4-452c-8d4c-fc4849fa8cd3" />

## Front PCB

<img width="930" height="556" alt="image" src="https://github.com/user-attachments/assets/6172c474-1db5-47aa-8fe3-ae391f19d055" />

## Back PCB

<img width="915" height="544" alt="image" src="https://github.com/user-attachments/assets/f3166503-4372-4b39-8bc8-c83a0b612fbe" />

## How to open in KiCad
Install KiCad
Open hardware/kicad/WeatherGirl.kicad_pro

## License
[MIT](https://choosealicense.com/licenses/mit/)

