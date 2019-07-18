//
// Created by adi on 14.07.19.
//

#include <cassert>
#include "testPalindrome.h"

void testPalindrome(bool (*pal)(std::string_view)) {

    assert(pal("") == true);
    assert(pal(" ") == true);
    assert(pal("1") == true);
    assert(pal("kajak") == true);
    assert(pal("KAYAK") == true);
    assert(pal("AAAAAAAAAAAAAAAAA") == true);
    assert(pal("ADAM") == false);
    assert(pal("Adam") == false);
    assert(pal("AAAABBBB") == false);
    assert(pal("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXY") == false);
}