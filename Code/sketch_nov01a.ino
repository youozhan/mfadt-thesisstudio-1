
//Reference
//https://learn.adafruit.com/mini-thermal-receipt-printer/bitmap-printing
//https://www.arduino.cc/en/Tutorial/Button

#include "Adafruit_Thermal.h"
//#include "noun_1352964_cc.h"
#include "SoftwareSerial.h"
#include "barcode.h"

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

  printer.println(F("********************************"));
  printer.feed(1);
  printer.justify('C');
  printer.boldOn();
  printer.println(F("YouTube"));
  printer.boldOff();

  printer.println(F("https://www.youtube.com"));
  printer.feed(1);
  printer.justify('L');
  printer.println(F("********************************"));

  //  printer.print(F("CODABAR:"));
  //  printer.printBarcode("1234567890", CODABAR);
  //  printer.printBarcode("https://myaccount.google.com/preferences#deleteservices", CODE128);
  printer.printBitmap(barcode_width, barcode_height, barcode_data);
  printer.println(F("Google Account"));
  printer.feed(1);
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

  printer.println(F("COPY OF YOUR DATA"));
  printer.println(F("==============================="));
  printer.println(F("SEARCH HISTORY"));
  printer.println(F("'/results?search_query=godard+coffee+scene'"));
  printer.println(F("'/results?search_query=%E5%BF%AB%E4%B9%90%E7%9A%84%E8%82%A5%E5%AE%85'"));
  printer.println(F("'/results?search_query=%E6%88%91%E5%B0%B1%E6%98%AF%E8%BF%99%E4%B9%88%E8%AF%9A%E5%AE%9E'"));
  printer.println(F("'/results?search_query=%E6%98%A5%E8%8A%82%E5%9B%9E%E5%AE%B6%E6%8C%87%E5%8D%97'"));
  printer.println(F("'/results?search_query=%E6%84%9F%E8%A7%89%E8%BA%AB%E4%BD%93%E8%A2%AB%E6%8E%8F%E7%A9%BA'"));
  printer.println(F("'/results?search_query=%E6%84%9F%E8%A7%89%E8%BA%AB%E4%BD%93%E8%A2%AB%E6%8E%8F%E7%A9%BA+%E5%BD%A9%E8%99%B9%E5%90%88%E5%94%B1%E5%9B%A2'"));
  printer.println(F("'/results?search_query=%E5%BD%A9%E8%99%B9'"));
  printer.println(F("'/results?search_query=braid+gameplay'"));
  printer.println(F("'/results?search_query=braid'"));
  printer.println(F("'/results?search_query=procreate'"));
  printer.println(F("'/results?search_query=%E5%A6%82%E6%87%BF%E4%BC%A072'"));
  printer.println(F("'/results?search_query=%E5%A6%82%E6%87%BF%E4%BC%A075'"));
  printer.println(F("'/results?search_query=%E5%A6%82%E6%87%BF%E4%BC%A0'"));
  printer.println(F("'/results?search_query=Table+saw'"));
  printer.println(F("'/results?search_query=yarn+lampshade+diy+balloon'"));
  printer.println(F("'/results?search_query=yarn+lampshade+diy+balloon'"));
  printer.println(F("'/results?search_query=%E6%B3%95%E8%AF%AD%E7%AE%80%E5%8D%95%E5%AF%B9%E8%AF%9D'"));
  printer.println(F("'/results?search_query=%E5%8C%97%E5%A4%96%E6%B3%95%E8%AF%AD%E6%95%99%E7%A8%8B'"));
  printer.println(F("'/results?search_query=%E5%8C%97%E5%A4%96%E6%B3%95%E8%AF%AD'"));
  printer.println(F("'/results?search_query=francais+beginners'"));
  printer.println(F("'/results?search_query=Make+a+big+avocado+doll'"));
  printer.println(F("'/results?search_query=Make+a+big+avocado+stuff'"));
  printer.println(F("'/results?search_query=hand+embroidery+lamp'"));
  printer.println(F("'/results?search_query=hand+embroidery'"));
  printer.println(F("'/results?search_query=Flora+project'"));
  printer.println(F("'/results?search_query=Flora+object'"));
  printer.println(F("'/results?search_query=hand+embroidery'"));
  printer.println(F("'/results?search_query=french+knit+pressure+sensor'"));
  printer.println(F("'/results?search_query=french+knit'"));
  printer.println(F("'/results?search_query=flora+project'"));
  printer.println(F("'/results?search_query=flora+soft+circuit'"));
  printer.println(F("'/results?search_query=%E7%90%85%E7%90%8A%E6%A6%9C2'"));
  printer.println(F("'/results?search_query=%E7%90%85%E7%90%8A%E6%A6%9C'"));
  printer.println(F("'/results?search_query=adafruit+flora'"));
  printer.println(F("'/results?search_query=adafruit'"));
  printer.println(F("'/results?search_query=%E7%8E%89%E6%B6%B2%E7%90%BC%E6%B5%86+%E5%A1%9E%E5%B0%94%E8%BE%BE'"));
  printer.println(F("'/results?search_query=%E7%8E%89%E6%B6%B2%E7%90%BC%E6%B5%86'"));
  printer.println(F("'/results?search_query=%E5%86%B0%E5%B1%8B+%E5%A1%9E%E5%B0%94%E8%BE%BE'"));
  printer.println(F("'/results?search_query=%E9%9B%B7%E7%A5%9E%E5%85%BD'"));
  printer.println(F("'/results?search_query=%E9%9B%B7%E9%B8%A3%E5%A4%B4%E7%9B%94'"));
  printer.println(F("'/results?search_query=yoshi+switch+gameplay'"));
  printer.println(F("'/results?search_query=embroidery'"));
  printer.println(F("'/results?search_query=salmon+morphing'"));
  printer.println(F("'/results?search_query=salmon+run'"));
  printer.println(F("'/results?search_query=elle+mills'"));
  printer.println(F("'/results?search_query=lasercut+projects'"));
  printer.println(F("'/results?search_query=wood+projects+for+beginner'"));
  printer.println(F("'/results?search_query=wood+projects'"));
  printer.println(F("'/results?search_query=how+to+build+a+dancing+mat'"));
  printer.println(F("'/results?search_query=how+to+build+a+tile+mat'"));
  printer.println(F("'/results?search_query=labo'"));
  printer.println(F("'/results?search_query=wood+stair+arduino+piano'"));
  printer.println(F("'/results?search_query=make+a+piano+arduino'"));
  printer.println(F("'/results?search_query=make+a+piano'"));
  printer.println(F("'/results?search_query=sewing+machine'"));
  printer.println(F("'/results?search_query=%E5%A6%82%E6%87%BF%E4%BC%A060'"));
  printer.println(F("'/results?search_query=%E5%A6%82%E6%87%BF%E4%BC%A0'"));
  printer.println(F("'/results?search_query=nintendo+labo+how+to+catch+a+shark'"));
  printer.println(F("'/results?search_query=human+fall+flat+walkthrough'"));
  printer.println(F("'/results?search_query=human+fall+flat'"));
  //  printer.println(F("LIST OF PRIVACY USAGE"));
  //  printer.println(F("==============================="));
  //  printer.println(F("Personalization"));
  //  printer.println(F("   Web & App Activity"));
  //  printer.println(F("   Location History"));
  //  printer.println(F("   Device Information"));
  //  printer.println(F("   Voice & Audio Activity"));
  //  printer.println(F("   YouTube Search History"));
  //  printer.println(F("   YouTube Watch History"));
  //  printer.println(F("Cookies"));
  //  printer.println(F("   Preference Cookie"));
  //  printer.println(F("   Security Cookie"));
  //  printer.println(F("   Process Cookie"));
  //  printer.println(F("   Advertising Cookie"));
  //  printer.feed(1);
  //  printer.println(F("LIST OF TECHNOLOGIES"));
  //  printer.println(F("==============================="));
  //  printer.println(F("Pattern recognition"));
  //  printer.println(F("Cookies"));
  //  printer.println(F("Anonymization"));

  //  printer.feed(2);
  //  printer.justify('C');
  //  printer.println(F("---Auth Information---"));
  //  printer.justify('L');
  //  printer.println(F("192.168.1.8"));
  //  printer.println(F("Name: Youchun Zhang"));
  //  printer.println(F("Account: youchunyz@gmail.com"));
  //
  //  printer.feed(1);
  //  printer.justify('C');
  //  printer.println(F("Please retain for your record"));
  //  printer.feed(1);
  //
  //  printer.feed(2);

  //  printer.println(F("Thank you for being a new user  of YouTube. Our mission is to give everyone a voice and show them the world.\n"));

  printer.feed(2);

  printer.sleep();      // Tell printer to sleep
  delay(3000L);         // Sleep for 3 seconds
  printer.wake();       // MUST wake() before printing again, even if reset
  printer.setDefault(); // Restore printer to defaults

}

void loop() {
  delay(1000);
}
