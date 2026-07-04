//remote v1
#include <Arduino.h>
#include <RF24.h>
#include <nRF24L01.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <Adafruit_MPU6050.h>
#include <Wire.h>
#include <SPI.h>
#include <IRremote.hpp>

#define LED_BUILTIN 2

#define JoystickMode 0
#define IMUMode 1

#define BUTTON1 17
#define BUTTON2 16
#define BUTTON3 27
#define BUTTON4 26

const int joystick1X = 33;
const int joystick1Y = 32;
const int joystick1SW = 25;
const int irPin = 13;

const int mpuaddr = 104; // because AD0 is pulled low
const int ssd1306addr = 0x3C; // sometimes 0x3D

const int nrfCS = 5;
const int nrfCE = 4;

const int screenWidth = 128;
const int screenHeight = 64;

const byte address[6] = "ADDR1";
RF24 nrf(nrfCE, nrfCS);

Adafruit_SSD1306 display(screenWidth, screenHeight, &Wire, -1);
Adafruit_MPU6050 mpu6050;
sensors_event_t accelerometer, gyro, temp;
// note: Adafruit_MPU6050.h needs to be modified for the correct WHO_AM_I address (my clone uses 0x98 which is annoying)


int operatingMode = JoystickMode;

double yAngle = 0;

void buttonChecker(void *pvParameters) {
  int64_t button1CD = 0, button2CD = 0, button3CD = 0, button4CD = 0;
  for(;;) {
    int64_t currentTime = esp_timer_get_time();

    if(digitalRead(BUTTON1) == LOW && currentTime - button1CD >= 670000) {
      button1CD = currentTime;
    }
    if(digitalRead(BUTTON2) == LOW && currentTime - button2CD >= 670000) {
      button2CD = currentTime;
    }
    if(digitalRead(BUTTON3) == LOW && currentTime - button3CD >= 670000) { // disarm a drone
      const char message[] = "disarm";
      nrf.write(&message, sizeof(message));

      button3CD = currentTime;
    }
    if(digitalRead(BUTTON4) == LOW && currentTime - button4CD >= 1200000) { // cycle through operating modes
      operatingMode = !operatingMode;
      
      display.fillRect(0, 0, 128, 16, SSD1306_BLACK);
      display.setCursor(0, 0);
      display.print(operatingMode == JoystickMode ? "Joystick Mode": "IMU Mode");
      display.display();
      if(operatingMode == IMUMode) {
        yAngle = accelerometer.acceleration.y;
      }
      button4CD = currentTime;
    }
    vTaskDelay(67);
  }
}

void transmitLoop(void *pvParameters) {
  for(;;) {
    if(operatingMode == JoystickMode) {
      int stick1RawX = analogRead(joystick1X);
      const char* stick1DirX = stick1RawX <= 4000 && stick1RawX >= 95 ? "NEUTRALX" : (stick1RawX < 95 ? "LEFT" : "RIGHT");

      int stick1RawY = analogRead(joystick1Y);
      const char* stick1DirY = stick1RawY <= 4000 && stick1RawY >= 95 ? "NEUTRALY" : (stick1RawY < 95 ? "UP" : "DOWN");

      Serial.println(strlen(stick1DirX));

      const char balls[] = "";

      nrf.write(stick1DirX, strlen(stick1DirX));
      nrf.write(stick1DirY, strlen(stick1DirY));

    } else if(operatingMode == IMUMode) {
      mpu6050.getEvent(&accelerometer, &gyro, &temp);

      double angleThreshold = 2.41;
      double accX = accelerometer.acceleration.x;
      double accY = accelerometer.acceleration.y;


      if(accX >= angleThreshold) {
        const char message[] = "LEFT";
        nrf.write(&message, sizeof(message));
      } else if(accX <= -angleThreshold) {
        const char message[] = "RIGHT";
        nrf.write(&message, sizeof(message));
      } else {
        const char message[] = "NEUTRALX";
        nrf.write(&message, sizeof(message));
      }
    }
    vTaskDelay(6);
  }
}

TaskHandle_t xButtonCheckerHandle = NULL;
TaskHandle_t xTransmitLoop = NULL;

void setup() {
  Serial.begin(115200);
  Serial.println("LIGM");

  pinMode(2, OUTPUT);
  pinMode(13, INPUT_PULLUP);
  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(BUTTON2, INPUT_PULLUP);
  pinMode(BUTTON3, INPUT_PULLUP);
  pinMode(BUTTON4, INPUT_PULLUP);

  pinMode(34, INPUT);

  if(!display.begin(SSD1306_SWITCHCAPVCC, ssd1306addr)) {
    Serial.println("oled failed to start");
    for(;;);
  }
  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextColor(SSD1306_WHITE);
  display.println("booting");
  display.display();

  if(!nrf.begin()) {
    Serial.println("nrf24l01 failed to start");
  }
  nrf.openWritingPipe(address);
  nrf.setPALevel(RF24_PA_MIN);
  nrf.stopListening();


  if(!mpu6050.begin(mpuaddr, &Wire)) {
    Serial.println("imu failed to start");
    for(;;);
  }
  mpu6050.setFilterBandwidth(MPU6050_BAND_10_HZ);

  BaseType_t xButtonHandler = xTaskCreate(buttonChecker, "ButtonChecker", 4096, NULL, 1, &xButtonCheckerHandle);
  BaseType_t xTransmitHandler = xTaskCreate(transmitLoop, "TransmitLoop", 4096, NULL, 1, &xTransmitLoop);
  
  Serial.println("setup complete");
}

void loop() {
// fffffffffffffff
}
