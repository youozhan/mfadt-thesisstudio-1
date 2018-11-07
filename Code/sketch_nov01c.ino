
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

  printer.println(F("********************************"));
  printer.feed(1);
  printer.justify('C');
  printer.boldOn();
  printer.println(F("IMDB"));
  printer.boldOff();

  printer.feed(1);
  printer.justify('L');
  printer.println(F("********************************"));

  printer.println(F("SIMPLE RECOMMENDERS SYSTEM"));
  printer.println(F("==============================="));
  printer.println(F("Decide on the metric or score to rate movies on"));
  printer.println(F("Calculate the score for everyone"));
  printer.println(F("Sort the movies based on the score"));
  printer.println(F("Output the top results"));
  printer.println(F("A movie with a rating 9 from 10 voters is better than a movie with a rating of 8.9 from 10,000 voters"));
  printer.println(F("Average rating of a movie on IMDB is around 5.6, on a scale of 10"));
  printer.feed(1);
  printer.println(F("CONTENT-BASED RECOMMENDER SYSTEM"));
  printer.println(F("==============================="));
  printer.println(F("Decide on the metric or score to rate movies on"));
  printer.println(F("Calculate the score for everyone"));
  printer.println(F("Sort the movies based on the score"));
  printer.println(F("Compute pairwise similarity scores for all movies"));
  printer.println(F("Recommend movies based on that similarity score"));
  printer.println(F("Get the movie given its title"));
  printer.println(F("Get the list of consine similarity scores for that particular movie with all movies"));
  printer.println(F("Sort based on the similarity scores"));
  printer.println(F("Get the top 10 elements of ths list"));
  printer.feed(1);
  printer.println(F("CREDITS, GENRES AND KEYWORDS BASED RECOMMENDER"));
  printer.println(F("==============================="));
  printer.println(F("Build a recommender based on the 3 top actors, the director, related denres and the movie plot keywords"));
  printer.println(F("Extract the three most important actors, the director and the keywords"));
  printer.println(F("Get the movie given its title"));
  printer.println(F("Get the list of consine similarity scores for that particular movie with all movies"));
  printer.println(F("Sort based on the similarity scores"));
  printer.println(F("Get the top 10 elements of ths list"));

  printer.feed(2);

  printer.sleep();      // Tell printer to sleep
  delay(3000L);         // Sleep for 3 seconds
  printer.wake();       // MUST wake() before printing again, even if reset
  printer.setDefault(); // Restore printer to defaults

}

void loop() {
  delay(1000);
}
