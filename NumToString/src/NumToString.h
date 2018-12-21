#pragma once

#include <string>
                                                        //0: Fix, 1: Scientific, else Automatic | Only format 0/1
std::string NumToString(double d, unsigned int width = 0, unsigned int format = 2, unsigned int amountOfDecimalPlaces = 4);
//Whole numbers
std::string NumToString(long i, unsigned int width = 0);
std::string NumToString(int i, unsigned int width = 0);
std::string NumToString(unsigned long i, unsigned int width = 0);
std::string NumToString(unsigned int i, unsigned int width = 0);