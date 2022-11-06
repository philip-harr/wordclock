// // #include <Arduino.h>
// // #include <Adafruit_NeoPixel.h>
// // #include "mappings.h"
// // #define PIN1 D1
// // #define PIN2 D2


// // std::vector<Adafruit_NeoPixel> lines = 
// // {
// //   Adafruit_NeoPixel(2, PIN1, NEO_GRB + NEO_KHZ800),
// //   Adafruit_NeoPixel(4, PIN2, NEO_GRB + NEO_KHZ800)
// // };

// // auto a = Adafruit_NeoPixel(4, PIN2, NEO_GRB + NEO_KHZ800);

// void setField(Words field, bool on, int ba)
// {
//   // auto color = on ? Adafruit_NeoPixel::Color(255, 255, 255) : Adafruit_NeoPixel::Color(0, 0, 0);
//   auto color = Adafruit_NeoPixel::Color(111, ba, 0);

//   // auto b = mappings.at(field);

//   // for(auto element : b.entries)
//   // {
//   //   auto led_line = lines.at(element.row);
//   //   for(auto light : element.lights)
//   //   {
//   //     led_line.setPixelColor(light, color);
//   //   }
//   //   led_line.show();
//   // }
//   a.setPixelColor(0, color);
//   a.show();
// }
 
// // void setup() 
// // {
// //   for(auto element : lines)
// //   {
// //     element.begin(); // This initializes the NeoPixel library.
// //   }
// //   a.begin();
// // }
 
// // void loop() 
// // {
// //   setField(Words::it_is, true, 0);
// //   delay(1000);
// //   setField(Words::it_is, true,255);
// //   delay(1000);
// //   // setField(Words::it_is, false);
// //   // delay(1000);
// //   // setField(Words::five_pre, true);
// //   // delay(1000);
// //   // setField(Words::five_pre, false);
// //   // delay(1000);
// // }
 
