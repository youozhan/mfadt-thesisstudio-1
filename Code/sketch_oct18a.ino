
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

// -----------------------------------------------------------------------

void setup() {

  // This line is for compatibility with the Adafruit IotP project pack,
  // which uses pin 7 as a spare grounding point.  You only need this if
  // wired up the same way (w/3-pin header into pins 5/6/7):
  pinMode(7, OUTPUT); digitalWrite(7, LOW);

  // NOTE: SOME PRINTERS NEED 9600 BAUD instead of 19200, check test page.
  mySerial.begin(19200);  // Initialize SoftwareSerial
  printer.begin();        // Init printer (same regardless of serial type)

  printer.println(F("******************************"));
  printer.feed(1);
  printer.justify('C');
  printer.boldOn();
  printer.println(F("YouTube"));
  printer.boldOff();

  printer.println(F("https://www.youtube.com"));
  printer.feed(1);
  printer.justify('L');
  printer.println(F("******************************"));

//  printer.print(F("CODABAR:"));
  printer.printBarcode("1234567890", CODABAR);
  printer.println(F("192.168.1.8 10/18/2018 13:57"));
  printer.feed(1);
  printer.println(F("LIST OF SERVICE    PRICE"));
  printer.println(F("==============================="));
  printer.println(F("YouTube               FREE"));
  printer.println(F("YouTube Premium     $11.99/month"));
  printer.println(F("YouTube TV            $40/month"));
  printer.println(F("YouTube Music        $9.99/month"));
  printer.println(F("YouTube Kids          FREE"));
  printer.println(F("YouTube VR            FREE"));
  printer.println(F("YouTube Creator Studio      FREE"));
  
  printer.feed(1);
  printer.println(F("LIST OF PRIVACY USAGE"));
  printer.println(F("==============================="));
  printer.println(F("Personalization"));
  printer.println(F("   Web & App Activity"));
  printer.println(F("   Location History"));
  printer.println(F("   Device Information"));
  printer.println(F("   Voice & Audio Activity"));
  printer.println(F("   YouTube Search History"));
  printer.println(F("   YouTube Watch History"));
  printer.println(F("Cookies"));
  printer.println(F("   Preference Cookie"));
  printer.println(F("   Security Cookie"));
  printer.println(F("   Process Cookie"));
  printer.println(F("   Advertising Cookie"));
  printer.feed(1);
  printer.println(F("LIST OF TECHNOLOGIES"));
  printer.println(F("==============================="));
  printer.println(F("Pattern recognition"));
  printer.println(F("Cookies"));
  printer.println(F("Anonymization"));

  printer.feed(2);
  printer.justify('C');
  printer.println(F("---Auth Information---"));
  printer.justify('L');
  printer.println(F("192.168.1.8"));
  printer.println(F("Name: Youchun Zhang"));
  printer.println(F("Account: youchunyz@gmail.com"));

  printer.feed(1);
  printer.justify('C');
  printer.println(F("Please retain for your record"));
  printer.feed(1);

  printer.feed(2);
  
  printer.println(F("Thank you for being a new user  of YouTube. Our mission is to give everyone a voice and show them the world.\n"));

  printer.feed(2);
  
  printer.sleep();      // Tell printer to sleep
  delay(3000L);         // Sleep for 3 seconds
  printer.wake();       // MUST wake() before printing again, even if reset
  printer.setDefault(); // Restore printer to defaults

}

void loop() {
  delay(1000);
}
