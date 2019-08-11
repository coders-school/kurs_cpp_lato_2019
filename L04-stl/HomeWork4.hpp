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

using generatorPair = std::pair< std::mt19937_64, std::uniform_int_distribution<std::size_t> >;

generatorPair generate(const std::size_t& start, const std::size_t& end)
{
    std::random_device l_Random_device;
	auto l_Seed = l_Random_device();

	std::mt19937_64 l_gen(l_Seed);
	std::uniform_int_distribution<std::size_t> l_Distribution(start, end);

    return std::make_pair(l_gen, l_Distribution);
}

std::map<char, char>  exercise12GenerateCodingScheme(const std::size_t& start, const std::size_t& end)
{
    std::size_t l_Length = end - start;


    auto l_Generator = generate(start, end);
    std::map<char, char> l_CodingScheme;

	
	unsigned int l_second = 0;
	auto l_Findpolicy = [&](const auto& val) {
		return static_cast<unsigned int>(val.second) == l_second;
	};

	auto l_Fillpolicy = [&]()
	{
		while (std::find_if(l_CodingScheme.begin(), l_CodingScheme.end(), l_Findpolicy) != l_CodingScheme.end()) {
			l_second = l_Generator.second(l_Generator.first);
		}

		size_t l_First = start + l_CodingScheme.size();
		auto result = std::make_pair<char, char>(static_cast<char>(l_First), static_cast<char>(l_second));
		l_second = 0;

		return result;
	};

	std::generate_n(std::insert_iterator<std::map<char, char>>(l_CodingScheme, l_CodingScheme.begin()), l_Length + 1, l_Fillpolicy);

	return l_CodingScheme;
}

std::map<char, char> exercise12Decode(const std::map<char, char>& encoding)
{
	std::map<char, char> l_Decoding;
	auto decodingpolicy = [](auto val) {
		return std::make_pair(val.second, val.first);
	};
	std::transform(encoding.begin(), encoding.end(), std::inserter(l_Decoding, l_Decoding.begin()), decodingpolicy);

	return l_Decoding;
}

void exercise12()
{
	std::size_t l_Start = 32;
	std::size_t l_End = 126;

	auto l_CodingScheme = exercise12GenerateCodingScheme(l_Start, l_End);
	std::map<char, char> l_Decoding = exercise12Decode(l_CodingScheme);


	std::string l_TextToBeEncoded;
	std::cout << "Provide text:" << std::endl;
	std::getline(std::cin, l_TextToBeEncoded);

	std::string l_EncodedText;
	for (auto e : l_TextToBeEncoded) {
		l_EncodedText += l_CodingScheme[e];
	}

	std::string l_Decoded;
	for (auto e : l_EncodedText) {
		l_Decoded += l_Decoding[e];
	}

	std::cout << "your orginal text: " << l_TextToBeEncoded << std::endl;

	std::cout << "your encoded text: " << l_EncodedText << std::endl;

	std::cout << "your decoded text: " << l_Decoded << std::endl;
}

void exercise9()
{
    std::string l_Palidromes[] = {"ala", "roor", "home"};

    for(int i = 0 ; i < 3; ++i)
    {
        std::string l_Palidrome = l_Palidromes[i];
        auto result = std::mismatch(l_Palidrome.begin(), l_Palidrome.end(), l_Palidrome.rbegin(), l_Palidrome.rend());

        if(result.first == l_Palidrome.end() && result.second == l_Palidrome.rend()) {
            std::cout << "result is " << true << std::endl;
        } else {
            std::cout << "result is " << false << std::endl;
        }
        
    }
}

void exercise6()
{
    std::forward_list<int> l_FList;
    for(std::size_t i = 0; i < 10; ++i) { l_FList.push_front(i); }

    auto l_Begin = std::begin(l_FList);
    auto l_End = std::end(l_FList);

    unsigned int L_counter = 0;
    int l_Value = 0;
    int l_Distance = 0;
    
    std::advance(l_Begin, 4);
    l_Distance = std::distance(l_Begin, l_End);

    std::cout << "value of 5th element is: " << l_Value << "\n";
    std::cout << "distance is: " << l_Distance << "\n";
    std::cout << "size is: " << L_counter << "\n";
}

void exercise4()
{
    std::vector<int> l_List;
    
    for(std::size_t i = 0; i < 1'000'000; i++)
    {
        int l_Value = i + 1;
        l_List.push_back(l_Value);
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

    std:: cout << l_List[500'000] << std::endl;

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

void homework4runner()
{
    exercise4();
	exercise6();
	exercise9();
	exercise12();
}

#endif //! HOMEWORK4_H
