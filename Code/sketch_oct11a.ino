
//Reference
//https://learn.adafruit.com/mini-thermal-receipt-printer/bitmap-printing
//https://www.arduino.cc/en/Tutorial/Button

#include "Adafruit_Thermal.h"
//#include "noun_1352964_cc.h"
#include "SoftwareSerial.h"
#define TX_PIN 6 // Arduino transmit  YELLOW WIRE  labeled RX on printer
#define RX_PIN 5 // Arduino receive   GREEN WIRE   labeled TX on printer

SoftwareSerial mySerial(RX_PIN, TX_PIN); // Declare SoftwareSerial obj first
Adafruit_Thermal printer(&mySerial);     // Pass addr to printer constructor

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

// -----------------------------------------------------------------------

void setup() {
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT_PULLUP);

  // This line is for compatibility with the Adafruit IotP project pack,
  // which uses pin 7 as a spare grounding point.  You only need this if
  // wired up the same way (w/3-pin header into pins 5/6/7):
  pinMode(7, OUTPUT); digitalWrite(7, LOW);

  // NOTE: SOME PRINTERS NEED 9600 BAUD instead of 19200, check test page.
  mySerial.begin(19200);  // Initialize SoftwareSerial
  printer.begin();        // Init printer (same regardless of serial type)

  printer.println(F("Dear new customer:"));
  printer.println(F("Welcome to the algorithm service department. Thank you for allowing us to access your algorithmic record. The following information is provided only with identification presented. \n"));
  printer.feed(1);
  printer.println(F("The YouTube algorithm you are using has three primary viewer factors: watch history, search history, and demographic information. In order for a video to be promoted by YouTube's Browse, Suggested and Recommended features, the video must get through the Candidate Generation Filter and the Ranking filter. The goal of the algorithm is for YouTube to lead to longer viewing sessions."));
  printer.feed(1);
  printer.println(F("For more information, please access our website. Thank you.\n"));
  printer.feed(2);

  printer.sleep();      // Tell printer to sleep
  delay(3000L);         // Sleep for 3 seconds
  printer.wake();       // MUST wake() before printing again, even if reset
  printer.setDefault(); // Restore printer to defaults

}

void loop() {
  delay(1000);
}
