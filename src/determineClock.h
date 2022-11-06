#pragma once
#include <vector>
#include "mappings.h"
#include <TimeLib.h>
#include <cstdlib>

bool lights[static_cast<int>(Words::MAX_ELEMENTS)];

void setArrayToFalse()
{
  for(int i = 0; i < static_cast<int>(Words::MAX_ELEMENTS); ++i)
  {
    lights[i] = false;
  }
}

void setWord(Words aWord)
{
  lights[static_cast<int>(aWord)] = true;
}

int roundToFive(int num)
{
  switch (num % 10)
  {
  case 1:
  case 6:
    num--;
    break;
  case 2:
  case 7:
    num-=2;
    break;
  case 3:
  case 8:
    num+=2;
    break;
  case 4:
  case 9:
    num++;
    break;
  default:
    break;
  }
  return num;
}

void determineHour(time_t t, bool pre)
{
  int h = hour(t);
  
  if(pre){ h++; } //we have to add 1, if we say "vor"->5 vor eins, same is valid for "halb & dreiviertel" 
  h = h % 12;

  switch(h)
  {
    case 0:
      setWord(Words::twelve);
      return;
    case 1:
      setWord(Words::one);
      if(roundToFive(minute(t)) % 60)
      {
        setWord(Words::one_s);
      }
      return;
    case 2:
      setWord(Words::two);
      return;
    case 3:
      setWord(Words::three);  
      return;
    case 4:
      setWord(Words::four);  
      return;
    case 5:
      setWord(Words::five);  
      setWord(Words::eleven_f_five);  
      return;
    case 6:
      setWord(Words::six);  
      return;
    case 7:
      setWord(Words::seven);  
      return;
    case 8:
      setWord(Words::eight);  
      return;
    case 9:
      setWord(Words::nine);  
      setWord(Words::ten_n_nine);  
      return;
    case 10:
      setWord(Words::ten);  
      setWord(Words::ten_n_nine);  
      return;
    case 11:
      setWord(Words::eleven);
      setWord(Words::eleven_f_five);
      return;
    default:
      break;
  }
}

bool determineMinutes(time_t t, HardwareSerial ser)
{
  ser.println("Minutes_pre:");
  ser.println(minute(t));
  int min = roundToFive(minute(t));
  ser.println("Minutes_post:");
  ser.println(min);

  switch (min % 60)
  {
  case 0:
    if(minute(t) > 5)
      return true;
    else
      return false;
  case 5:
    setWord(Words::five_pre);
    setWord(Words::post);
    return false;
  case 10:
    setWord(Words::ten_pre);
    setWord(Words::post);
    return false;
  case 15:
    switch(std::rand() % 5)
    {
      case 0:
        setWord(Words::quarter_pre);
        setWord(Words::post);
        return false;
      default: 
        setWord(Words::quarter_pre);
        return true;
    }
  case 20:
    switch(std::rand() % 10)
    {
      case 0: 
        setWord(Words::twenty_pre);
        setWord(Words::post);
        return false;
      default:
        setWord(Words::ten_pre);
        setWord(Words::pre);
        setWord(Words::half);
        return true;
    }
  case 25:
    setWord(Words::five_pre);
    setWord(Words::pre);
    setWord(Words::half);
    return true;
  case 30:
    setWord(Words::half);
    return true;
  case 35:
    setWord(Words::five_pre);
    setWord(Words::post);
    setWord(Words::half);
    return true;
  case 40:
    switch(std::rand() % 10)
    {
      case 0: 
        setWord(Words::twenty_pre);
        setWord(Words::pre);
        return true;
      default:
        setWord(Words::ten_pre);
        setWord(Words::post);
        setWord(Words::half);
        return true;
    }
  case 45:
    switch(std::rand() % 20)
    {
      case 0: 
        setWord(Words::quarter_pre);
        setWord(Words::pre);
        return true;
      default:
        setWord(Words::threequarter_pre);
        setWord(Words::quarter_pre);
        return true;
    }
  case 50:
    switch(std::rand() % 10)
    {
      case 0: 
        setWord(Words::twenty_pre);
        setWord(Words::post);
        setWord(Words::half);
        return true;
      default:
        setWord(Words::ten_pre);
        setWord(Words::pre);
        return true;
    }
  case 55:
    setWord(Words::five_pre);
    setWord(Words::pre);
    return true;
  default:
    return false;
  }

}

void determineOClock(time_t t)
{
  int min = roundToFive(minute(t)) % 60;
  if(! min)
    setWord(Words::oclock);
}

void determineClock(time_t t, HardwareSerial ser)
{
  setArrayToFalse();
  setWord(Words::it_is);
  bool countUp = determineMinutes(t, ser);
  determineHour(t, countUp);
  determineOClock(t);

  // for(int i = 0; i < static_cast<int>(Words::MAX_ELEMENTS); ++i)
  // {
  //   if(lights[i])
  //   {
  //     Serial.println((mappings_words[i]).c_str());
  //     delay(5);
  //   }
  // }

}

bool isStandby(time_t t)
{
  if(hour(t) < 6)
    return true;
  
  return false;
}