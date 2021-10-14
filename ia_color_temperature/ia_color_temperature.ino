#include <NeuralNetwork.h>

unsigned int layers[] = {3, 3, 1}; 
float *output;
#define NB_OF_ITERATIONS = 4000

const float inputs[6][3] = {
  {1, 0, 0}, //rouge | 1
  {0, 1, 0}, //vert | 0
  {0, 0, 1}, //bleu | 0
  {1, 1, 0}, //jaune | 1
  {0, 1, 1}, //cyan | 0
  {1, 0, 1}, //magenta | 1
};

const float expectedOutput[6][1] = {{1}, {0}, {0}, {1}, {0}, {1}};

NeuralNetwork NN(layers, 3);

void setup() {

  Serial.begin(38400);
  
  for (int i = 0; i < NB_OF_ITERATIONS; i++) {
    if (i % (NB_OF_ITERATIONS / 100) == 0) {
      Serial.print("Entrainement");
      Serial.print(i / (NB_OF_ITERATIONS / 100));
      Serial.println("%");
      }
    
    for (int j = 0; j < 6; j++) {
      NN.FeedForward(inputs[j]);
      NN.BackProp(expectedOutput[j]);
    }
  }

  for (int i = 0; i < 6; i++) {
    output = NN.FeedForward(inputs[i]);
    Serial.print(i);
    Serial.print(": ");
    Serial.println(output[0], 7);  
  }

  NN.print();
}

void loop() {
    
}
