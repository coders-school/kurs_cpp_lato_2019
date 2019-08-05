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


std::vector<std::pair<char, char>>  exercise12_generate_Scheme(const unsigned int& start, const unsigned int end)
{
	// Random number generator setup
	std::random_device l_random_device;
	auto l_seed = l_random_device();

	std::mt19937_64 l_gen(l_seed);
	std::uniform_int_distribution<unsigned int> distribution(start, end);

	// setup end

	std::vector<std::pair<char, char>> Scheme;

	unsigned int length = end - start;

	unsigned int right = 0;
	auto findpolicy = [&](const auto& val) {
		return (unsigned int)val.second == right;
	};

	auto fillpolicy = [&]()
	{
		while (std::find_if(Scheme.begin(), Scheme.end(), findpolicy) != Scheme.end()) {
			right = distribution(l_gen);
		}

		unsigned int left = start + Scheme.size();
		auto result = std::make_pair<char, char>((char)(left), (char)right);
		right = 0;

		return result;
	};

	std::generate_n(std::back_inserter(Scheme), length + 1, fillpolicy);

	return Scheme;
}

std::map<char, char> exercise12_encodePlan(const std::vector<std::pair<char, char>>& Scheme)
{
	std::map<char, char> plan;
	std::copy(Scheme.begin(), Scheme.end(), std::inserter(plan, plan.begin()));

	return plan;
}

std::map<char, char> exercise12_decodePlan(const std::vector<std::pair<char, char>>& Scheme)
{
	std::map<char, char> plan;
	auto decodingpolicy = [](auto val) {
		return std::make_pair(val.second, val.first);
	};
	std::transform(Scheme.begin(), Scheme.end(), std::inserter(plan, plan.begin()), decodingpolicy);

	return plan;
}

void exercise12()
{
	unsigned int l_start = 32;
	unsigned int l_end = 126;

	std::vector<std::pair<char, char>>Scheme = exercise12_generate_Scheme(l_start, l_end);

	std::map<char, char> encoding = exercise12_encodePlan(Scheme);
	std::map<char, char> decoding = exercise12_decodePlan(Scheme);


	std::string textToBeEncoded;
	std::cout << "Provide text:" << std::endl;
	std::getline(std::cin, textToBeEncoded);

	std::string encodedText;
	for (auto e : textToBeEncoded) {
		encodedText += encoding.find(e)->second;
	}

	std::string decoded;
	for (auto e : encodedText) {
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
    
    std::advance(b, 4);
    distance = std::distance(b, e);

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

void homework4runner()
{
    //exercise4();
	exercise6();
	//exercise9();
	//exercise12();
}

#endif //! HOMEWORK4_H
