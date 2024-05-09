/**
 * @file main.cpp
 * @brief Main program body
 * @version 0.1
 * @date 2023-11-05
 * @author b401
 *
 * This is an OTA firmware for ESP8266
 * The ESP8266 will act as an access point without password
 * To update the firmware, connect to the access point and open the IP address in the browser
 * The IP address is 11.4.0.1
 * Just upload the firmware located on ./.pio/build/[board]/firmware.bin and wait for the ESP8266 to reboot
 *
 */

#include <Arduino.h>
#include "LittleFS.h"
#include <DNSServer.h>
#include <ElegantOTA.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

/* Private macro -------------------------------------------------------------*/
#define NETMASK_24 IPAddress(255, 255, 255, 0)
#define LED_PIN 2
#define LED_RED 13
#define LED_GREEN 14
#define LED_BLUE 12
#define BUTTON_ 15

/* USER CODE BEGIN PM */
#define AP_SSID "Kelompok_99"
#define AP_PASSWORD "12345678"
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
const byte DNS_PORT = 53;
IPAddress esp_32_ip(11, 4, 0, 1);
DNSServer dnsServer;
ESP8266WebServer webServer(80);

/* USER CODE BEGIN PV */
uint8_t led_color_rgb[3] = {0, 0, 0};
uint8_t btn_val = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void init_pin();
void set_led_color();
void reset_led_color();

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

void setup()
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(esp_32_ip, esp_32_ip, NETMASK_24);
  WiFi.softAP(AP_SSID, AP_PASSWORD);

  // if DNSServer is started with "*" for domain name, it will reply with provided IP to all DNS request
  dnsServer.start(DNS_PORT, "*", esp_32_ip);

  // route handle here
  webServer.onNotFound([]()
                       {      
                        webServer.sendHeader("Content-Encoding", "gzip");
                        webServer.send_P(200, "text/html", (const char*)ELEGANT_HTML, sizeof(ELEGANT_HTML)); });

  ElegantOTA.begin(&webServer);

  webServer.begin();

  /* USER CODE BEGIN 2 */
  pinMode(LED_PIN, OUTPUT);

  init_pin();
  /* USER CODE END 2 */
}

void loop()
{
  ElegantOTA.loop();
  dnsServer.processNextRequest();
  webServer.handleClient();

  /* USER CODE BEGIN 3 */
  static uint32_t last_time = 0;
  if (millis() - last_time > 1000)
  {
    last_time = millis();
    digitalWrite(LED_PIN, !digitalRead(LED_PIN));
  }
  /* USER CODE END 3 */

  btn_val = digitalRead(BUTTON_);

  /* USER CODE BEGIN 4 */ // Masukkan yang kalian program di wokwi di sini

  /* USER CODE END 4 */
}

void set_led_color()
{
  analogWrite(LED_RED, led_color_rgb[0]);
  analogWrite(LED_GREEN, led_color_rgb[1]);
  analogWrite(LED_BLUE, led_color_rgb[2]);
}

void reset_led_color()
{
  analogWrite(LED_RED, 0);
  analogWrite(LED_GREEN, 0);
  analogWrite(LED_BLUE, 0);
}

void init_pin()
{
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  pinMode(BUTTON_, INPUT);
  delay(1);
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_BLUE, LOW);
}

/* USER CODE BEGIN 5 */

/* USER CODE END 5 */