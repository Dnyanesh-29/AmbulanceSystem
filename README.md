

---

# 🚨 Smart Traffic Management System (STMS)

A smart and responsive system that enables **emergency vehicles**—like ambulances, police cars, and fire engines—to navigate urban traffic faster and safer by integrating **real-time location sharing**, **automated traffic signal control**, and a **web-based control panel**.

> **Built for** emergency responders, traffic authorities, and smart cities looking to reduce response time and enhance road safety.

---

## 🚀 Features

- 🔀 **Automatic Signal Switching** using RF modules
- 📍 **Live Navigation & Location Tracking** for emergency vehicles
- 🧭 **Dynamic Dashboard** for traffic police
- ⚙️ **Web-Based App** for dispatch and real-time communication
- 🧠 **Microcontroller Integration** using Arduino with RF-based controls
- 🛠️ Simple to deploy and easy to scale

---

## 📦 Run Locally

```bash
# Clone the project
git clone https://github.com/Dnyanesh-29/AmbulanceSystem

# Navigate to the project folder
cd AmbulanceSystem

# Replace Google Maps API Key in the code

# Install dependencies
npm install

# Start the server
node server.js
```

---

## 🔐 Credentials

| User Type       | Username     | Password     |
|----------------|--------------|--------------|
| Ambulance       | WB37B0249    | zmH01fh2N/   |
| Police Dashboard | admin       | password123  |

---

## 🖼️ Screenshots

### 🚦 Home Page  
<img src="https://github.com/Dnyanesh-29/AmbulanceSystem/blob/main/ss/home.png?raw=true" width="700"/>

### 🔐 Login Page  
<img src="https://github.com/Dnyanesh-29/AmbulanceSystem/blob/main/ss/AmbulanceLogin.png?raw=true" width="700"/>

### 🚑 Ambulance Interface  
<img src="https://github.com/Dnyanesh-29/AmbulanceSystem/blob/main/ss/AmbulanceSide.png?raw=true" width="700"/>

### 👮‍♂️ Police Control Panel  
<img src="https://github.com/Dnyanesh-29/AmbulanceSystem/blob/main/ss/PoliceSide.png?raw=true" width="700"/>

---

## 🔌 Hardware Setup

### 📚 Required Arduino Libraries

| Library Name         | Description                                  |
|----------------------|----------------------------------------------|
| `RadioHead (RH_ASK)` | RF communication driver                      |
| `SPI`                | Required for `RH_ASK`                        |
| `Wire`               | I2C support for LCD                          |
| `LiquidCrystal_I2C`  | LCD controller via I2C                       |

> Install via: Arduino IDE → Tools → Manage Libraries

---

## 📡 Receiver Circuit

### 🔗 RF Receiver

| Pin  | Arduino UNO |
|------|-------------|
| VCC  | 5V          |
| GND  | GND         |
| Data | A0          |

### 🖥️ I2C LCD Display

| Pin | Arduino UNO |
|-----|-------------|
| VCC | 5V          |
| GND | GND         |
| SDA | A4          |
| SCL | A5          |

### 🚦 Traffic LEDs

| Signal | Red | Yellow | Green |
|--------|-----|--------|-------|
| 1      | D8  | D9     | D10   |
| 2      | D11 | D12    | D13   |
| 3      | D2  | D3     | D4    |
| 4      | D5  | D6     | D7    |

---

## 📡 Transmitter Circuit

| Component            | Pin      | Notes                                  |
|---------------------|----------|----------------------------------------|
| Red LED (Ambulance) | D6       | Blinks on transmit                     |
| Green LED           | D7       | Alternates with red                    |
| Button              | D8       | `INPUT_PULLUP`, active LOW             |

> Ensure all LEDs have a 220–330Ω resistor in series.

---

## 🔧 Circuit Diagram

<img src="https://github.com/Dnyanesh-29/AmbulanceSystem/blob/main/ss/image_2025-06-20_103404862.png?raw=true" width="700"/>

---

Let me know if you'd like badges, a license section, or deployment instructions for hosting this on a cloud platform!
