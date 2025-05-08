# IoT RC Car Controller 🚗📡

This is an IoT-based WiFi RC car controller project using NodeMCU ESP8266 and an L298N motor driver. Built by **Coding Moves**.

## Features
- WiFi Access Point created by NodeMCU
- Real-time direction control via web interface
- Adjustable speed using commands (0 to 9)
- Works fully offline without router

## Pin Configuration
| Component     | NodeMCU Pin | Description           |
|---------------|-------------|-----------------------|
| ENA           | D5 (GPIO14) | Right motor speed     |
| ENB           | D6 (GPIO12) | Left motor speed      |
| IN1 (Right)   | D8 (GPIO15) | Motor direction       |
| IN2 (Right)   | D7 (GPIO13) | Motor direction       |
| IN3 (Left)    | D4 (GPIO2)  | Motor direction       |
| IN4 (Left)    | D3 (GPIO0)  | Motor direction       |

## How to Use
1. Flash `rc_car_controller.ino` to your NodeMCU.
2. Connect to WiFi named `NodeMCU Car`.
3. Open the control webpage and send commands like `F`, `B`, `L`, `R`, `S`, etc.

## Credits
Made with ❤️ by [Coding Moves](https://www.youtube.com/@Coding_Moves)
