#include <NeuralNetwork.h>
#include "Adafruit_TCS34725.h"

// ---- Initialize Adafruit ---- //
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);


// ---- Initialize variables ---- //
int rmax, gmax, bmax, cmax;
int rmin, gmin, bmin, cmin;

unsigned int layers[] = {3, 3, 1}; 
float *output;
#define NB_OF_ITERATIONS 4000
#define NB_COLOR_LEARNING 8

const float inputs[NB_COLOR_LEARNING][3] = {
  {1, 0, 0}, //rouge | 1
  {0, 1, 0}, //vert | 0
  {0, 0, 1}, //bleu | 0
  {1, 1, 0}, //jaune | 1
  {0, 1, 1}, //cyan | 0
  {1, 0, 1}, //magenta | 1
  {0.66, 1, 1}, //rouge feutre | 1
  {0.46, 0.84, 1} //vert feutre | 0
};

float mesuredOutput[3];
const float expectedOutput[NB_COLOR_LEARNING][1] = {{1}, {0}, {0}, {1}, {0}, {1}, {1}, {0}};

NeuralNetwork NN(layers, 3);

// ---- Start the setup ---- //
void setup() {

  Serial.begin(38400);

  // ------------------------------------------------ //

  // ---- Start learning ---- //
  for (int i = 0; i < NB_OF_ITERATIONS; i++) {
    if (i % (NB_OF_ITERATIONS / 100) == 0) {
      Serial.print("Entrainement");
      Serial.print(i / (NB_OF_ITERATIONS / 100));
      Serial.println("%");
      }
    
    for (int j = 0; j < NB_COLOR_LEARNING; j++) {
      NN.FeedForward(inputs[j]);
      NN.BackProp(expectedOutput[j]);
    }
  }

  for (int i = 0; i < NB_COLOR_LEARNING; i++) {
    output = NN.FeedForward(inputs[i]);
    Serial.print(i);
    Serial.print(": ");
    Serial.println(output[0], 7);  
  }

  NN.print();
  // ---- Learning is finished ---- //

  // ------------------------------------------------ //

  // ---- Start the calibration of the sensor ---- //
  Serial.println("Start the calibration process"); 

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
  Serial.println("End the calibration process");
  // ---- End of the calibration ---- //

  // ------------------------------------------------ //
}


// ---- Start the main loop ---- //
void loop() {
  uint16_t r, g, b, c;

  // ---- Mesure the color data ---- //
  tcs.getRawData(&r, &g, &b, &c);

  int R = constrain(map(r, rmin, rmax, 0, 255), 0, 255);
  int G = constrain(map(r, gmin, gmax, 0, 255), 0, 255);
  int B = constrain(map(r, bmin, bmax, 0, 255), 0, 255);

  mesuredOutput[0] = R / 255.0;
  mesuredOutput[1] = G / 255.0;
  mesuredOutput[2] = B / 255.0;
  
  // ---- Use the Neural Network ---- //
  output = NN.FeedForward(mesuredOutput);

  Serial.print("R: "); Serial.print(R); Serial.print(" ");
  Serial.print("G: "); Serial.print(G); Serial.print(" ");
  Serial.print("B: "); Serial.print(B); Serial.println(" ");
  Serial.print("Output : "); Serial.print(output[0], 7); Serial.print(" Answer : ");
  Serial.println(output[0] > 0.5 ? "Warm" : "Cold"); 

  delay(1000);

  
    
}
