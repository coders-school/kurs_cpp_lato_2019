#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <ctime>
#include <fstream>
#include <vector>

class Code
{
    std::vector<char> v_base {};
    std::vector<char> v_mutated {};
    std::map<char, char> baseMap;
    std::map<char, char> mutatedMap;

    public:
    Code()
    {
        std::generate_n(std::back_inserter(v_base), 95, [n = ' '] () mutable {return n++;});
        std::copy(v_base.begin(), v_base.end(), std::back_inserter(v_mutated));
        std::random_shuffle(v_mutated.begin(), v_mutated.end());

        std::transform(v_base.begin(), 
                       v_base.end(), 
                       v_mutated.begin(), 
                       std::inserter(baseMap, baseMap.end()), 
                       [](char a, char b){return std::make_pair(a, b);});
        
        std::transform(v_mutated.begin(), 
                       v_mutated.end(), 
                       v_base.begin(), 
                       std::inserter(mutatedMap, mutatedMap.end()), 
                       [](char a, char b){return std::make_pair(a, b);});
    }

    std::string makeEncryption(const std::string &base)
    {   
        std::string mutated;
        std::transform(base.begin(), 
                       base.end(), 
                       std::back_inserter(mutated),
                       [this](char c){return baseMap.find(c)->second; 
                       });
        return mutated;
    }

    std::string makeDecryption(const std::string &mutated)
    {   
        std::string base;
        std::transform(mutated.begin(), 
                       mutated.end(), 
                       std::back_inserter(base),
                       [this](char c){return mutatedMap.find(c)->second; 
                       });
        return base;
    }
};

int main()
{
    std::srand(std::time(0));    
    Code c{};
    std::string s;
    std::string enc_s;
    std::string dec_s;

    std::cout << "Type the message you want to encrypt: ";
    std::getline(std::cin, s);
    enc_s = c.makeEncryption(s);
    std::cout << "Encrypted message is: " << enc_s << std::endl;
    dec_s = c.makeDecryption(enc_s);
    std::cout << "Decrypted message is: " << dec_s << std::endl;

    std::string line;
    std::ifstream baseFile ("base.txt");
    std::ofstream encryptedFile ("encrypted.txt", std::ofstream::out | std::ofstream::trunc);
    std::ifstream encryptedFile2 ("encrypted.txt");
    std::ofstream decryptedFile ("decrypted.txt", std::ofstream::out | std::ofstream::trunc);

    if (decryptedFile.is_open())
    {
        if (encryptedFile.is_open())
        {
            if (baseFile.is_open())
            {
                while (!baseFile.eof())
                {   
                    std::getline(baseFile,line);
                    encryptedFile << c.makeEncryption(line) << std::endl;
                }
                baseFile.close();
                encryptedFile.close();  
            }
            else
            {
                std::cout << "File can't be open." << std::endl;
            }
        }
        else
        {
            std::cout << "File can't be open." << std::endl;
        }

        if (encryptedFile2.is_open())
        {

            while (!encryptedFile2.eof())
            {
                std::getline(encryptedFile2,line);
                decryptedFile << c.makeDecryption(line) << std::endl;
            }
            encryptedFile2.close();  
        }
        else
        {
            std::cout << "File can't be open." << std::endl;
        }

        decryptedFile.close();    
    }
    else
    {
        std::cout << "File can't be open." << std::endl;
    }

    return 0;
}
