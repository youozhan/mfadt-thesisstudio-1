
//Reference
//https://learn.adafruit.com/mini-thermal-receipt-printer/bitmap-printing
//https://www.arduino.cc/en/Tutorial/Button

#include "Adafruit_Thermal.h"
//#include "noun_1352964_cc.h"
#include "SoftwareSerial.h"
//#include "barcode.h"

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

  printer.println(F("AD SETTINGS"));
  printer.println(F("==============================="));
  printer.println(F("25-34 years old"));
  printer.println(F("Female"));
  printer.println(F("Sephora"));
  printer.println(F("Macy's"));
  printer.println(F("Nordstrom"));
  printer.println(F("InVision"));
  printer.println(F("Action & Platform Games"));
  printer.println(F("Adventure Games"));
  printer.println(F("Audio Equipment"));
  printer.println(F("Bars, Clubs & Nightlife"));
  printer.println(F("Beauty & Fitness"));
  printer.println(F("Books & Literature"));
  printer.println(F("Business News"));
  printer.println(F("Business Services"));
  printer.println(F("Camera ^ Photo Equipment"));
  printer.println(F("Casual Games"));
  printer.println(F("Cats"));
  printer.println(F("Celebrities & Entertainment News"));
  printer.println(F("Classical Music"));
  printer.println(F("Comics & Animation"));
  printer.println(F("Computer & Video Games"));
  printer.println(F("Computer Hardware"));
  printer.println(F("Computer & Electronics"));
  printer.println(F("Construction & Power Tools"));
  printer.println(F("Cooking & Recipes"));
  printer.println(F("Country Music"));
  printer.println(F("Coupons & Discount Offers"));
  printer.println(F("Credit Cards"));
  printer.println(F("Distributed & Cloud Computing"));
  printer.println(F("Education"));
  printer.println(F("Electornics & Electrical"));
  printer.println(F("Extreme Sparts"));
  printer.println(F("Family"));
  printer.println(F("Fashion & Style"));
  printer.println(F("Fast Food"));
  printer.println(F("Fiber & Textile Arts"));
  printer.println(F("Fitness"));
  printer.println(F("Foreign Language Study"));
  printer.println(F("Gourmet & Specialty Foods"));
  printer.println(F("Graphics & Animation Software"));
  printer.println(F("Green Living & Environmental Issues"));
  printer.println(F("Home & Garden"));
  printer.println(F("Home & Interior Decor"));
  printer.println(F("Home Improvement"));
  printer.println(F("Investing"));
  printer.println(F("Lamps & Lighting"));
  printer.println(F("Luxury Goods"));
  printer.println(F("Mathematics"));
  printer.println(F("Mobile Phones"));
  printer.println(F("Moutain & Ski Resourts"));
  printer.println(F("Movies"));
  printer.println(F("New York City"));
  printer.println(F("Online Video"));
  printer.println(F("Outdoors"));
  printer.println(F("Parenting"));
  printer.println(F("Performing Arts"));
  printer.println(F("Photo Software"));
  printer.println(F("Photographic & Digital Arts"));
  printer.println(F("Politics"));
  printer.println(F("Pop Music"));
  printer.println(F("Price Comparisons"));
  printer.println(F("Rap & Hip-Hop"));
  printer.println(F("Restaurants"));
  printer.println(F("Roleplaying Games"));
  printer.println(F("Science Fiction & Fantasy Films"));
  printer.println(F("Visual Arts & Design Education"));

  printer.feed(2);

  printer.sleep();      // Tell printer to sleep
  delay(3000L);         // Sleep for 3 seconds
  printer.wake();       // MUST wake() before printing again, even if reset
  printer.setDefault(); // Restore printer to defaults

}

void loop() {
  delay(1000);
}
