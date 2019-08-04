#ifndef HOMEWORK4_H
#define HOMEWORK4_H

#include <list>
#include <vector>
#include <forward_list>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <map>

#include <random>


void exercise12()
{
    int l_start = 32;
    int l_end = 126;


    // Random number generator setup
    std::random_device l_random_device;
    auto l_seed = l_random_device();

    std::mt19937_64 l_gen(l_seed);
    std::uniform_int_distribution<int> distribution(l_start, l_end);

    // setup end

    // generating Cypher
    std::vector<std::pair<char, char>> encodingShame;

    int length = l_end - l_start;
    auto fillpolicy = [&]()
    {
        int left = l_start + encodingShame.size();
        int value = distribution(l_gen);

        auto findpolicy = [&](const auto& val){
            return (int)val.second == value;
        };

        while( std::find_if(encodingShame.begin(), encodingShame.end(), findpolicy) != encodingShame.end()){
            value = distribution(l_gen);
        }


        return std::make_pair<char, char>((char)left, (char)value );   
    };

    
    std::generate_n(std::back_inserter(encodingShame), length + 1, fillpolicy);

    // generating Cypher emd

    // create encoding and decoding maps.


    std::map<char, char> encoding;
    std::copy(encodingShame.begin(), encodingShame.end(), std::inserter(encoding, encoding.begin()));


    std::map<char, char> decoding;
    auto decodingpolicy = [](auto val) {
        return std::make_pair(val.second, val.first); 
    };   
    std::transform(encodingShame.begin(), encodingShame.end(), std::inserter(decoding, decoding.begin()), decodingpolicy);

    // create encoding and decoding maps.


    std::string textToBeEncoded;
    std::cout << "Provide text:" << std::endl;
    std::getline(std::cin, textToBeEncoded);

    std::string encodedText;
    for(auto e : textToBeEncoded) {
        encodedText += encoding.find(e)->second;
    }

    std::string decoded;
    for(auto e : encodedText) {
        decoded += decoding.find(e)->second;
    }

    std::cout << "your orginal text: " << textToBeEncoded << std::endl;

    std::cout << "your encoded text: " << encodedText << std::endl;

    std::cout << "your decoded text: " << decoded << std::endl;
}

void exercise9()
{
    std::string palidromes[] = {"ala", "roor", "home"};

    for(int i = 0 ; i < 3; ++i)
    {
        std::string palidrome = palidromes[i];
        auto result = std::mismatch(palidrome.begin(), palidrome.end(), palidrome.rbegin(), palidrome.rend());

        if(result.first == palidrome.end() && result.second == palidrome.rend()) {
            std::cout << "result is " << true << std::endl;
        } else {
            std::cout << "result is " << false << std::endl;
        }
        
    }
}

void exercise6()
{
    std::forward_list<int> l_fList;
    for(std::size_t i = 0; i < 10; ++i) { l_fList.push_front(i); }

    auto b = std::begin(l_fList);
    auto e = std::end(l_fList);

    unsigned int counter = 0;
    int value = 0;
    int distance = 0;
    for(auto el = b; el != e; ++el)
    {
        if(counter == 4) {
            value = *el;
            distance = std::distance(b, e);
        } 
        ++counter;
    }

    
    std::cout << "value of 5th element is: " << value << "\n";
    std::cout << "distance is: " << distance << "\n";
    std::cout << "size is: " << counter << "\n";
}

void exercise4()
{
    std::vector<int> l_list;
    
    for(std::size_t i = 0; i < 1'000'000; i++)
    {
        int value = i + 1;
        l_list.push_back(value);
    }
    /*

    Czas wypelnienia listy:
    real	0m0,561s
    user	0m0,524s
    sys     0m0,024s

    Czas wypelnienia vectora:
    real	0m0,074s
    user	0m0,069s
    sys     0m0,004s

    */
    /*
        unsigned int counter = 0;
        for(int value : l_list) {
            if(counter == 500'000) {
                std:: cout << value << std::endl;
            }
            ++counter;
        }
    */

    std:: cout << l_list[500'000] << std::endl;

    /*
    Czas wykonania pelnego programu (lista, for loop)
    real	0m0,667s
    user	0m0,599s
    sys	    0m0,035s

    Czas wykonania pelnego programu (vector, for loop)
    real	0m0,145s
    user	0m0,140s
    sys     0m0,004s

    Czas wykonania pelnego programu (vector, accessor[])
    real	0m0,076s
    user	0m0,071s
    sys     0m0,000s

    */
    
}

#endif //! HOMEWORK4_H
