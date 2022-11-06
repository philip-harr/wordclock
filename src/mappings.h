#pragma once
#include <vector>
#include <inttypes.h>
#include <map>

enum class Words
{
   it_is,
   five_pre,
   ten_pre,
   twenty_pre,
   threequarter_pre,
   quarter_pre,
   pre,
   post,
   half,
   one,
   one_s,
   two,
   three,
   four,
   five,
   six,
   seven,
   eight,
   nine,
   ten_n_nine,
   ten,
   eleven,
   eleven_f_five,
   twelve,
   oclock,
   MAX_ELEMENTS
};
    
class FieldDescription
{
public:
   uint32_t pin;
   std::vector<uint32_t> lights;
   uint32_t first;
   uint32_t length;

   FieldDescription(uint32_t a_row, std::vector<uint32_t> a_lights)
   :pin(a_row), lights(a_lights){}

   FieldDescription(uint32_t a_row, uint32_t a_first, uint32_t a_length)
   :pin(a_row), first(a_first), length(a_length){}
};

FieldDescription mappings_lights[static_cast<int>(Words::MAX_ELEMENTS)] = 
{
   FieldDescription(0, 55, 5), // it is 
   FieldDescription(0, 60, 4), // five_pre
   FieldDescription(0, 51, 4), //ten_pre
   FieldDescription(0, 44, 7), //twenty_pre
   FieldDescription(0, 33, 4), //three_w/o_quarter
   FieldDescription(0, 37, 7), //quarter
   FieldDescription(0, {30, 31, 32}),//    pre,
   FieldDescription(0, {26, 27, 28, 29}),//    post,
   FieldDescription(0, {16, 17, 18, 19}),//    half,
   FieldDescription(0, {13, 14, 15}),//    one,
   FieldDescription(0, {12}),//    one_s,
   FieldDescription(0, {8, 9, 10, 11}),//    two,
   FieldDescription(0, {0, 1, 2, 3}),//    three,
   FieldDescription(0, {4, 5, 6, 7}),//    four,
   FieldDescription(0, {23, 24, 25}), // five

   FieldDescription(1, 14, 5), //six
   FieldDescription(1, 19, 7),//seven
   FieldDescription(1, 10, 4),//eight
   FieldDescription(1, 4, 3),// nine 
   FieldDescription(1, 3, 1),// ten_n_nine 
   FieldDescription(1, 0, 3),//ten
   FieldDescription(0, {20, 21}), //eleven
   FieldDescription(0, {22}), //eleven_f_five
   FieldDescription(1, 26, 6), //twelve
   FieldDescription(1, 7, 3) //oclock
};

std::string mappings_words[static_cast<int>(Words::MAX_ELEMENTS)] = 
{
   "Es ist",
   "fünf" ,
   "zehn" ,
   "zwanzig",
   "dreiviertel",
   "viertel",
   "vor",
   "nach",
   "halb",
   "ein",
   "s",
   "zwei",
   "drei",
   "vier",
   "fünf",
   "sechs",
   "sieben",
   "acht",
   "neun",
   "zehn",
   "elf",
   "zwölf",
   "Uhr" 
};