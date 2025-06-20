
Smart Traffic Management System (STMS)

his project is designed to help emergency vehicles—like ambulances, fire engines, and police cars—move through traffic faster and more safely in urban areas. It combines a smart web app that gives real-time navigation and live location sharing with traffic officers, and a transmitter-receiver system that automatically turns traffic lights green as the emergency vehicle approaches.
It's built for emergency responders who need faster access during crises, and for traffic authorities who coordinate clear passage. The system ultimately aims to save lives by reducing delays and creating safer, more responsive cities.



## Run Locally

Clone the project

```bash
  git clone https://github.com/Dnyanesh-29/AmbulanceSystem
```

Go to the project directory

```bash
  cd my-project
```
replace your google maps api key

Install dependencies

```bash
  npm install
```

Start the server

```bash
  node server.js

```

##passwords <br/>
 ambulance side -- <br/>
 username - WB37B0249 <br/>
 password - zmH01fh2N/ <br/>

 police side -- <br/>
 username - admin <br/>
 password - password123 <br/>

## Screenshots

<h3>Home Page</h3>
<img src="https://github.com/Dnyanesh-29/AmbulanceSystem/blob/main/ss/home.png?raw=true" width="600"/>

<h3>Login Page</h3>
<img src="https://github.com/Dnyanesh-29/AmbulanceSystem/blob/main/ss/AmbulanceLogin.png?raw=true" width="600"/>

<h3>Ambulance Side</h3>
<img src="https://github.com/Dnyanesh-29/AmbulanceSystem/blob/main/ss/AmbulanceSide.png?raw=true" width="600"/>

<h3>Police Side</h3>
<img src="https://github.com/Dnyanesh-29/AmbulanceSystem/blob/main/ss/PoliceSide.png?raw=true" width="600"/>



## Hardware Side
Upload code of both transmitter side and reciver side to both respective arduinos according to connections given <br/>

## 📚 Required Arduino Libraries

To run this project smoothly, make sure the following libraries are installed in your Arduino IDE:

| Library Name         | Description                                               | Installation Method                          |
|----------------------|-----------------------------------------------------------|-----------------------------------------------|
| `RadioHead (RH_ASK)` | Enables RF communication for transmitter and receiver     | Arduino IDE → Tools → Manage Libraries → Search “RadioHead” |
| `SPI`                | Dependency for `RH_ASK` communication                     | Built-in with Arduino IDE                     |
| `Wire`               | I2C communication protocol (used by LCD module)           | Built-in with Arduino IDE                     |
| `LiquidCrystal_I2C`  | Controls 16x2 LCD via I2C interface                       | Arduino IDE → Tools → Manage Libraries → Search “LiquidCrystal_I2C” |

> 🛠️ **Note:** Make sure to restart the Arduino IDE after installing libraries to apply changes.

Reciver side connections <br/>

---

## 🔌 Hardware Connections

### 📡 RF Receiver (RH_ASK)

| Pin | Arduino |
|-----|---------|
| VCC | 5V      |
| GND | GND     |
| Data | A0     |

### 📟 I2C LCD Display

| Pin | Arduino UNO |
|-----|-------------|
| VCC | 5V          |
| GND | GND         |
| SDA | A4          |
| SCL | A5          |

### 🚦 Traffic Signals (LEDs + Resistors)

Each signal (Red, Yellow, Green) should have a 220Ω–330Ω resistor in series.

| Signal | Red Pin | Yellow Pin | Green Pin |
|--------|---------|------------|-----------|
| 1      | D8      | D9         | D10       |
| 2      | D11     | D12        | D13       |
| 3      | D2      | D3         | D4        |
| 4      | D5      | D6         | D7        |

> **Tip:** Connect all component grounds together for reliable operation.

---


Tranmitter side connection <br/>
To document the hardware setup for this Arduino-based RF **transmitter circuit**, you can add the following Markdown section to your `README.md` file:

---

## 📡 Transmitter Circuit Connections

This transmitter module sends a signal when the button is pressed, simulating an ambulance's presence and triggering traffic control actions on the receiver side.

### 🔧 Pin Configuration

| Component         | Arduino Pin | Notes                           |
|------------------|-------------|---------------------------------|
| RF Transmitter   | N/A (built into RH_ASK) | Connected internally via `RH_ASK driver` |
| Ambulance Red LED   | D6          | Blinks when transmitter is ON   |
| Ambulance Green LED | D7          | Alternates with red LED         |
| Button (Toggle)  | D8          | Use `INPUT_PULLUP`, active LOW  |

> **Tip:** Connect the other leg of the button to **GND**, and ensure LEDs have 220Ω–330Ω resistors in series.

---

## circuit diagram

<img src="https://github.com/Dnyanesh-29/AmbulanceSystem/blob/main/ss/image_2025-06-20_103404862.png?raw=true" width="600"/>





