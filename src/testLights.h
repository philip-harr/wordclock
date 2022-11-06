#pragma once
#include "setLights.h"
#include "mappings.h"

void testFirst()
{
  setField(static_cast<int>(Words::quarter_pre), false);
  setField(static_cast<int>(Words::it_is), true);
  delay(1000);
  setField(static_cast<int>(Words::it_is), false);
  setField(static_cast<int>(Words::five_pre), true);
  delay(1000);
  setField(static_cast<int>(Words::five_pre), false);
  setField(static_cast<int>(Words::ten_pre), true);
  delay(1000);
  setField(static_cast<int>(Words::ten_pre), false);
  setField(static_cast<int>(Words::twenty_pre), true);
  delay(1000);
  setField(static_cast<int>(Words::twenty_pre), false);
  setField(static_cast<int>(Words::threequarter_pre), true);
  delay(1000);
  setField(static_cast<int>(Words::threequarter_pre), false);
  setField(static_cast<int>(Words::quarter_pre), true);
  delay(1000);
}

void testSecond()
{
  setField(static_cast<int>(Words::four), false);
  setField(static_cast<int>(Words::pre), true);
  delay(1000);
  setField(static_cast<int>(Words::pre), false);
  setField(static_cast<int>(Words::post), true);
  delay(1000);
  setField(static_cast<int>(Words::post), false);
  setField(static_cast<int>(Words::half), true);
  delay(1000);
  setField(static_cast<int>(Words::half), false);
  setField(static_cast<int>(Words::eleven), true);
  delay(1000);
  setField(static_cast<int>(Words::eleven), false);
  setField(static_cast<int>(Words::five), true);
  delay(1000);
  setField(static_cast<int>(Words::five), false);
  setField(static_cast<int>(Words::one), true);
  delay(1000);
  setField(static_cast<int>(Words::one), false);
  setField(static_cast<int>(Words::one_s), true);
  delay(1000);
  setField(static_cast<int>(Words::one_s), false);
  setField(static_cast<int>(Words::two), true);
  delay(1000);
  setField(static_cast<int>(Words::two), false);
  setField(static_cast<int>(Words::three), true);
  delay(1000);
  setField(static_cast<int>(Words::three), false);
  setField(static_cast<int>(Words::four), true);
  delay(1000);
}

void testThird()
{
  setField(static_cast<int>(Words::oclock), false);
  setField(static_cast<int>(Words::six), true);
  delay(1000);
  setField(static_cast<int>(Words::six), false);
  setField(static_cast<int>(Words::eight), true);
  delay(1000);
  setField(static_cast<int>(Words::eight), false);
  setField(static_cast<int>(Words::seven), true);
  delay(1000);
  setField(static_cast<int>(Words::seven), false);
  setField(static_cast<int>(Words::twelve), true);
  delay(1000);
  setField(static_cast<int>(Words::twelve), false);
  setField(static_cast<int>(Words::ten), true);
  delay(1000);
  setField(static_cast<int>(Words::ten), false);
  setField(static_cast<int>(Words::nine), true);
  delay(1000);
  setField(static_cast<int>(Words::nine), false);
  setField(static_cast<int>(Words::oclock), true);
  delay(1000);
}