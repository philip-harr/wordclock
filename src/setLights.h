#pragma once
#include <Adafruit_NeoPixel.h>
#include "mappings.h"
Adafruit_NeoPixel led1 = Adafruit_NeoPixel(64, D1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel led2 = Adafruit_NeoPixel(32, D2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel led3 = Adafruit_NeoPixel(8, D3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel led4 = Adafruit_NeoPixel(8, D4, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel led5 = Adafruit_NeoPixel(8, D5, NEO_GRB + NEO_KHZ800);

std::vector<Adafruit_NeoPixel*> lines = 
{
  &led1, &led2, &led3, &led4, &led5
};


void setField(int field, bool on)
{
  // auto color = on ? Adafruit_NeoPixel::Color(255, 255, 255) : Adafruit_NeoPixel::Color(0, 0, 0);
  auto color = on ? Adafruit_NeoPixel::Color(150, 150, 150) : Adafruit_NeoPixel::Color(0, 0, 0);
  auto b = mappings_lights[field];


  auto row = lines.at(b.pin);
  if(b.length)
  {
    for(uint32_t i = 0; i < b.length; ++i)
    {
        row->setPixelColor(b.first + i, color);
    }
  }
  else
  {
    for(auto light : b.lights)
    {
        row->setPixelColor(light, color);
    }
  }
  row->show();
  
}
