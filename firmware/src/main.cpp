/*
☲☲☲☲ GETTING STARTED CODE ☲☲☲☲

- This code is for Wortel Development Board V2.
- This code is for beginners who want to learn how to program Wortel Development Board.
- And guess what? It's compatible with both PlatformIO and Arduino IDE!

P.S. This Code Written by Faris 😊 (https://www.farisrfp.me)
*/

#include <Arduino.h>     // Standard Arduino library
#include <EasyButton.h>  // Library for handling button press
#include <FastLED.h>     // Library for controlling RGB LED

/* Variable Declaration */
#define BUTTON_PIN 0  // Button Pin
#define LED_PIN 2     // RGB LED Pin
#define NUM_LEDS 1    // Number of RGB LED

CRGB leds[NUM_LEDS];            // RGB LED Array
EasyButton button(BUTTON_PIN);  // Button Object

/* Function Prototype */
void buttonPressed();        // Function to handle button press
void buttonDoubleClicked();  // Function to handle double click
void buttonLongPressed();    // Function to handle long press

void setup() {
    /* Initialize Serial Monitor */
    Serial.begin(9600);

    /* Initialize RGB LED */
    FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);

    /* Initialize Button */
    button.begin();
    button.onPressed(buttonPressed);
    button.onPressedFor(500, buttonLongPressed);
    button.onSequence(2, 500, buttonDoubleClicked);

    /* you can add your code here */
}

void loop() {
    button.read();  // Always read the button in the loop

    /* you can add your code here */
}

void buttonPressed() {
    Serial.printf("Button Pressed\n");

    /* Generate Random Color */
    leds[0] = CRGB(random(255), random(255), random(255));
    FastLED.show();
}

void buttonDoubleClicked() {
    Serial.printf("Button Double Clicked\n");

    leds[0] = CRGB::Green;
    FastLED.show();
}

void buttonLongPressed() {
    Serial.printf("Button Long Pressed\n");

    leds[0] = CRGB::Red;
    FastLED.show();
}