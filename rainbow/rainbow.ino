  #include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
#define PIN        6
#define NUMPIXELS 11

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 500

void setup() {
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif

  pixels.begin();
}

void loop() {
  pixels.clear();
  int red[]  = {255, 255, 255,   0,  0,255,};
  int green[]= {  0, 150, 255, 255,  0,   0};
  int blue[] = {  0,   0,   0,   0,255, 255};

  for(int c = 0; c < 8; c++) {
    for(int i=0; i<NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(red[c], green[c], blue[c]));
      pixels.show();
      delay(DELAYVAL*0.025);
    }
  }
}
