#include <Adafruit_NeoPixel.h>
#include "mappings.h"
#include <NTPClient.h>
// change next line to use with another board/shield
#include <ESP8266WiFi.h>
//#include <WiFi.h> // for WiFi shield
//#include <WiFi101.h> // for WiFi 101 shield or MKR1000
#include <WiFiUdp.h>
#include <Timezone.h>
#include <TimeLib.h>
#include <cstdlib>
#include "determineClock.h"

#include "setLights.h"
#include "testLights.h"

const char *ssid     = "FRITZ!Box 7582 VH";
const char *password = "34113839197295615221";

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

TimeChangeRule time_cest = {"CEST", Last, Sun, Mar, 2, +120}; 
TimeChangeRule time_cet = {"CET", Last, Sun, Oct, 2, +60}; 
Timezone european_time(time_cest, time_cet);

std::string makeTimeString(time_t t)
{
  char time[8];
  sprintf(time, "%d:%d:%d", hour(t), minute(t), second(t));

  std::string ret(time);
  return ret;
}

std::string makeTimeSentence()
{
  std::string ret;
  for(int i = 0; i < static_cast<int>(Words::MAX_ELEMENTS); ++i)
  {
    if(lights[i])
    {
      ret += mappings_words[i] + " ";
    }
  }
  return ret;
}



void makeLights()
{
  // static int cnt = 0;
  // if(cnt < 10)
  // {
  //   testFirst();
  //   testSecond();
  //   testThird();
  //   cnt++;
  // }
  // else
  // {
    for(int i = 0; i < static_cast<int>(Words::MAX_ELEMENTS); ++i)
    {
      if(lights[i])
      {
        setField(i, true);
      }
      else
      {
        setField(i, false);
      }
    }

  // }
}

void setup() 
{
  Serial.begin(115200);

  WiFi.begin(ssid, password);

  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    Serial.print ( "." );
  }

  timeClient.begin();
  timeClient.setUpdateInterval(10*60*1000 /*set in ms*/);
  std::srand(timeClient.getEpochTime());
  for(auto element : lines)
  {
    element->begin(); // This initializes the NeoPixel library.
  }
}

void loop() 
{

  timeClient.update();
  time_t current_time = european_time.toLocal(timeClient.getEpochTime());
  Serial.println(makeTimeString(current_time).c_str());
  determineClock(current_time, Serial);
  Serial.println(makeTimeSentence().c_str());
  
  if(isStandby(current_time))
  {
    memset(lights, 0, static_cast<int>(Words::MAX_ELEMENTS) * sizeof(bool));
  }
  
  makeLights();


  uint32_t sleep_time_in_ms = 60*1000;
  wifi_set_opmode(NULL_MODE);
  wifi_fpm_set_sleep_type(LIGHT_SLEEP_T);
  wifi_fpm_open();
  // wifi_fpm_set_wakeup_cb(callback);
  wifi_fpm_do_sleep(sleep_time_in_ms *1000 );
  delay(sleep_time_in_ms + 1);
  
 
  WiFi.begin(ssid, password);
  Serial1.println("");
  
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

}
 