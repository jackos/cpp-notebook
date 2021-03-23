#include <iostream>
#include <stdio.h>
#include <string>

int CMultiplier(int num, int multi)
{
    int result = num * multi;
    return result;
}

char *c_address_return(const char *phrase, char *result, size_t resultMaxLength, int num, int multi)
{
    int sum = num * multi;
    snprintf(result, resultMaxLength, "The result of %d x %d is %d annd the phrase passed in is %s", num, multi, sum, phrase);

    return result;
}

extern "C"
{
    int Multiplier(int a, int b)
    {
        return CMultiplier(a, b);
    }
    char *address_return(const char *phrase, char *result, size_t resultMaxLength, int num, int multi)
    {
        return c_address_return(phrase, result, resultMaxLength, num, multi);
    }
    // char *address_return(int a, int b)
    // {
    // return c_address_return(a, b);
    // }
}