#include <Wire.h>
#include <TM1637Display.h>

// Define display
const int CLK = 2; // TM1637 CLK pin connected to Arduino D2
const int DIO = 3; // TM1637 DIO pin connected to Arduino D3
TM1637Display display(CLK, DIO);

// Variables for time
int hours = 21;
int minutes = 2;

void setup() {
    // Initialize the display
    display.setBrightness(0x0f); // Set brightness (0x0f is maximum)
}

void loop() {
    // Display the current time in HH:MM format
    display.showNumberDecEx(hours * 100 + minutes, 0b01000000, true);

    // Increment the time every minute
    delay(60000); // Wait for one minute
    minutes++;

    // Handle overflow
    if (minutes >= 60) {
        minutes = 0;
        hours++;
    }
    if (hours >= 24) {
        hours = 0;
    }
}
