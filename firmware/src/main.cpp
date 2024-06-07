/*
☲☲☲☲ GETTING STARTED CODE ☲☲☲☲

- This code is for Wortel Development Board V2.
- This code is for beginners who want to learn how to program Wortel Development Board.
- And guess what? It's compatible with both PlatformIO and Arduino IDE!
*/

#include <Arduino.h>     // Standard Arduino library
#include <EasyButton.h>  // Library for handling button press
#include <FastLED.h>     // Library for controlling RGB LED

/* Variable Declaration */
#define BUTTON_PIN 0  // Button Pin
#define LED_PIN D5    // RGB LED Pin
#define NUM_LEDS 1    // Number of RGB LED

CRGB leds[NUM_LEDS];            // RGB LED Array
EasyButton button(BUTTON_PIN);  // Button Object

/* Function Prototype */
void buttonPressed();        // Function to handle button press
void buttonLongPressed();    // Function to handle long press
void buttonDoubleClicked();  // Function to handle double click
void buttonTripleClicked();  // Function to handle triple click

void setup() {
    /* Initialize Serial Monitor */
    Serial.begin(115200);
    randomSeed(analogRead(A0));

    /* Initialize RGB LED */
    FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);

    /* Initialize Button */
    button.begin();
    button.onPressed(buttonPressed);
    button.onPressedFor(500, buttonLongPressed);
    button.onSequence(2, 500, buttonDoubleClicked);
    button.onSequence(3, 500, buttonTripleClicked);

    /* you can add your code here */
}

void loop() {
    button.read();  // Always read the button in the loop

    /* you can add your code here */
}

void buttonPressed() {
    Serial.printf("Button Pressed\n");

    /* Generate Random Color */
    leds[0] = CRGB(random(126), random(126), random(126));
    FastLED.show();
}

void buttonLongPressed() {
    Serial.printf("Button Long Pressed\n");

    leds[0] = CRGB::Red;
    FastLED.show();
}

void buttonDoubleClicked() {
    Serial.printf("Button Double Clicked\n");

    leds[0] = CRGB::Green;
    FastLED.show();
}

void buttonTripleClicked() {
    Serial.printf("Button Triple Clicked\n");

    leds[0] = CRGB::Black;
    FastLED.show();
}