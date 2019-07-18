//
// Created by adi on 14.07.19.
//

#ifndef HOMEWORK2_TESTPALINDROM_H
#define HOMEWORK2_TESTPALINDROM_H
#include <string_view>

typedef bool (*pal)(std::string_view);

void testPalindrome(bool (*pal)(std::string_view));

#endif //HOMEWORK2_TESTPALINDROM_H

