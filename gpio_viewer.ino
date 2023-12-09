#include <WiFi.h>
#include "src/gpio_viewer.h"
#include "secrets.h"

// Define the GPIO pins to monitor
const int gpioPins[] = {34,35,32,33,25,26,27,14,12,13,9,10,11}; // Example GPIO pins
const int numPins = sizeof(gpioPins) / sizeof(gpioPins[0]);

GPIOViewer gpio_viewer(50,8080);

void setup()
{
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi...");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected to WiFi");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  pinMode(27, OUTPUT);

  gpio_viewer.begin();
}

void loop()
{
  digitalWrite(27, HIGH);
  delay(500);
  digitalWrite(27, LOW);
  delay(500);
}