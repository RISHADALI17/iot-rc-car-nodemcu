//By Coding Moves //
// WiFi control Car using NodeMCU //

\#define ENA   14          // Enable/speed motors Right        GPIO14(D5)
\#define ENB   12          // Enable/speed motors Left         GPIO12(D6)
\#define IN\_1  15          // L298N in1 motors Right           GPIO15(D8)
\#define IN\_2  13          // L298N in2 motors Right           GPIO13(D7)
\#define IN\_3  2           // L298N in3 motors Left            GPIO2(D4)
\#define IN\_4  0           // L298N in4 motors Left            GPIO0(D3)

\#include \<ESP8266WiFi.h>
\#include \<WiFiClient.h>
\#include \<ESP8266WebServer.h>

String command;             // String to store app command state.
int speedCar = 800;         // Speed value (range 400 - 1023).
int speed\_Coeff = 3;

const char\* ssid = "NodeMCU Car";

ESP8266WebServer server(80);

void setup() {
pinMode(ENA, OUTPUT);
pinMode(ENB, OUTPUT);
pinMode(IN\_1, OUTPUT);
pinMode(IN\_2, OUTPUT);
pinMode(IN\_3, OUTPUT);
pinMode(IN\_4, OUTPUT);

Serial.begin(115200);

// Start Wi-Fi Access Point
WiFi.mode(WIFI\_AP);
WiFi.softAP(ssid);

IPAddress myIP = WiFi.softAPIP();
Serial.print("AP IP address: ");
Serial.println(myIP);

// Start web server
server.on("/", HTTP\_handleRoot);
server.onNotFound(HTTP\_handleRoot);
server.begin();
}

// Direction Control Functions
void goAhead() {
digitalWrite(IN\_1, LOW);
digitalWrite(IN\_2, HIGH);
analogWrite(ENA, speedCar);

digitalWrite(IN\_3, LOW);
digitalWrite(IN\_4, HIGH);
analogWrite(ENB, speedCar);
}

void goBack() {
digitalWrite(IN\_1, HIGH);
digitalWrite(IN\_2, LOW);
analogWrite(ENA, speedCar);

digitalWrite(IN\_3, HIGH);
digitalWrite(IN\_4, LOW);
analogWrite(ENB, speedCar);
}

// ✅ Swapped Left and Right logic
void goRight() {
digitalWrite(IN\_1, LOW);
digitalWrite(IN\_2, HIGH);
analogWrite(ENA, speedCar);

digitalWrite(IN\_3, HIGH);
digitalWrite(IN\_4, LOW);
analogWrite(ENB, speedCar);
}

void goLeft() {
digitalWrite(IN\_1, HIGH);
digitalWrite(IN\_2, LOW);
analogWrite(ENA, speedCar);

digitalWrite(IN\_3, LOW);
digitalWrite(IN\_4, HIGH);
analogWrite(ENB, speedCar);
}

void goAheadRight() {
digitalWrite(IN\_1, LOW);
digitalWrite(IN\_2, HIGH);
analogWrite(ENA, speedCar / speed\_Coeff);

digitalWrite(IN\_3, LOW);
digitalWrite(IN\_4, HIGH);
analogWrite(ENB, speedCar);
}

void goAheadLeft() {
digitalWrite(IN\_1, LOW);
digitalWrite(IN\_2, HIGH);
analogWrite(ENA, speedCar);

digitalWrite(IN\_3, LOW);
digitalWrite(IN\_4, HIGH);
analogWrite(ENB, speedCar / speed\_Coeff);
}

void goBackRight() {
digitalWrite(IN\_1, HIGH);
digitalWrite(IN\_2, LOW);
analogWrite(ENA, speedCar / speed\_Coeff);

digitalWrite(IN\_3, HIGH);
digitalWrite(IN\_4, LOW);
analogWrite(ENB, speedCar);
}

void goBackLeft() {
digitalWrite(IN\_1, HIGH);
digitalWrite(IN\_2, LOW);
analogWrite(ENA, speedCar);

digitalWrite(IN\_3, HIGH);
digitalWrite(IN\_4, LOW);
analogWrite(ENB, speedCar / speed\_Coeff);
}

void stopRobot() {
digitalWrite(IN\_1, LOW);
digitalWrite(IN\_2, LOW);
analogWrite(ENA, speedCar);

digitalWrite(IN\_3, LOW);
digitalWrite(IN\_4, LOW);
analogWrite(ENB, speedCar);
}

void loop() {
server.handleClient();
command = server.arg("State");

if (command == "F") goAhead();
else if (command == "B") goBack();
else if (command == "L") goLeft();
else if (command == "R") goRight();
else if (command == "I") goAheadRight();
else if (command == "G") goAheadLeft();
else if (command == "J") goBackRight();
else if (command == "H") goBackLeft();
else if (command == "0") speedCar = 400;
else if (command == "1") speedCar = 470;
else if (command == "2") speedCar = 540;
else if (command == "3") speedCar = 610;
else if (command == "4") speedCar = 680;
else if (command == "5") speedCar = 750;
else if (command == "6") speedCar = 820;
else if (command == "7") speedCar = 890;
else if (command == "8") speedCar = 960;
else if (command == "9") speedCar = 1023;
else if (command == "S") stopRobot();
}

void HTTP\_handleRoot(void) {
if (server.hasArg("State")) {
Serial.println(server.arg("State"));
}
server.send(200, "text/html", "");
delay(1);
}
