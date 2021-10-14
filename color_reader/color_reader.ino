#include <Wire.h>
#include "Adafruit_TCS34725.h"

/* Initialise with specific int time and gain values */
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

int rmax, gmax, bmax, cmax;
int rmin, gmin, bmin, cmin;

void setup(void) {
  Serial.begin(9600);
  Serial.println("");

  if (tcs.begin()) {
    Serial.println("Found sensor");
  } else {
    Serial.println("No TCS34725 found ... check your connections");
    while (1);
  }

  Serial.println("Phase de calibration du blanc. Entrez y pour confirmer");
  while (Serial.read() != 'y') {
    tcs.getRawData(&rmax, &gmax, &bmax, &cmax);
    Serial.print("Rmax: "); Serial.print(rmax); Serial.print(" ");
    Serial.print("Gmax: "); Serial.print(gmax); Serial.print(" ");
    Serial.print("Bmax: "); Serial.print(bmax); Serial.println(" ");
    delay(1000);
  }

  Serial.println("Phase de calibration du noir. Entrez y pour confirmer");
  while (Serial.read() != 'y') {
    tcs.getRawData(&rmin, &gmin, &bmin, &cmin);
    Serial.print("Rmin: "); Serial.print(rmin); Serial.print(" ");
    Serial.print("Gmin: "); Serial.print(gmin); Serial.print(" ");
    Serial.print("Bmin: "); Serial.print(bmin); Serial.println(" ");
    delay(1000);
  }
}

void loop(void) {
  uint16_t r, g, b, c;

  tcs.getRawData(&r, &g, &b, &c);

  int rmap = map(r, rmin, rmax, 0, 255);
  int gmap = map(r, gmin, gmax, 0, 255);
  int bmap = map(r, bmin, bmax, 0, 255);

  int R = constrain(rmap, 0, 255);
  int G = constrain(gmap, 0, 255);
  int B = constrain(bmap, 0, 255);
  
  Serial.print("R: "); Serial.print(R); Serial.print(" ");
  Serial.print("G: "); Serial.print(G); Serial.print(" ");
  Serial.print("B: "); Serial.print(B); Serial.println(" ");
}
