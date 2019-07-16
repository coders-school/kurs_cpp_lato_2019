//
// Created by adi on 14.07.19.
//

#include <string>

#ifndef HOMEWORK2_TESTPALINDROM_H
#define HOMEWORK2_TESTPALINDROM_H

typedef bool (*pal)(std::string_view);

void testPalindrome(bool (*pal)(std::string_view));

#endif //HOMEWORK2_TESTPALINDROM_H

