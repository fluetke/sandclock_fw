/* SandWatch_PrusaContest_Initial F/W *
 * Author: Florian Luetkebohmert <me@fluetke.eu>
 * 2021 - licensed under GPL v3
 */

#include <ESP8266WebServer.h> // webserver
#include <ESP8266HTTPUpdateServer.h>
#include <Stepper.h>

const int stepsPerRevolution = 2048;  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library 
Stepper myStepper(stepsPerRevolution, 5, 0, 4, 2);
ESP8266WebServer httpServer(80);
ESP8266HTTPUpdateServer httpUpdater;
WiFiClient networkClient;

void setup() {
  // set the speed at 60 rpm:
  myStepper.setSpeed(1);
  // initialize the serial port:
  Serial.begin(9600);
  httpUpdater.setup(&httpServer, "/fwupdate", "admin", "admin");
  WiFi.softAP("watch" + WiFi.macAddress());
  httpServer.begin();
}

void loop() {
  // step one revolution  in one direction:
    myStepper.step(-1);  
    ESP.wdtFeed();
    httpServer.handleClient();
}
