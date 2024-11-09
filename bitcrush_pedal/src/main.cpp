/*#include <Arduino.h>
#include "../include/esp_adc/adc_continuous.h"

// variables
const adc_continuous_handle_cfg_t adc_handle_config = {
    .max_store_buf_size = 1024,
    .conv_frame_size = 100,
};

adc_continuous_handle_t adc_handle;
adc_continuous_config_t adc_config;

// put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  adc_continuous_new_handle(&adc_handle_config, &adc_handle);
  adc_config.sample_freq_hz = 40000;
  adc_config.pattern_num = 1;
  

  ESP_ERROR_CHECK(adc_continuous_new_handle(&adc_handle_config, &adc_handle));
}

void loop() {
  // put your main code here, to run repeatedly:
  int dout = 
  printf("%i", dout)
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}*/

#include <Arduino.h>
// Potentiometer is connected to GPIO 34 (Analog ADC1_CH6) 
const int potPin = 12;

// variable for storing the potentiometer value
int potValue = 0;

void setup() {
  Serial.begin(115200);
  delay(1000);
}

void loop() {
  // Reading potentiometer value
  potValue = analogRead(potPin);
  Serial.print("Analog value: ");
  Serial.printf("%u\n",potValue);
  delay(500);
}