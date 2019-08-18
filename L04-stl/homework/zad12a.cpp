#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <map>
#include <numeric>
#include <random>
#include <string>
#include <cassert>
#include <functional>

class MyAwesomeCipher
{
public:
    MyAwesomeCipher()
    {
        makeEncodingMap();
        makeDecodingMapBasedOnEncodingMap(); 
    }

    std::string encode(const std::string& input)
    {
        std::string output;
        convertUsingDictionary(input, encMap, output);
        return output;
    }
    
    std::string decode(const std::string& input)
    {
        std::string output;
        convertUsingDictionary(input, decMap, output);
        return output;
    }

    void printMap()
    {
        std::for_each(encMap.cbegin(), 
                      encMap.cend(), 
                      [](std::pair<char, char> p)
                      { std::cout << "key: " << p.first << ",  value: " << p.second << "\n"; });
    }

private:
    typedef std::map<char, char> CipherMap;
    
    CipherMap encMap;
    CipherMap decMap;

    void convertUsingDictionary(const std::string& input, const std::map<char, char>& map, std::string& output)
    {
        std::transform( input.begin(),
                        input.end(),
                        std::back_inserter(output),
                        [&map](char a){ return map.find(a)->second; });
    }

    void printVector(const std::vector<char>& v)
    {
        std::cout << ".";
        std::copy(v.cbegin(), v.cend(), std::ostream_iterator<char>(std::cout, "."));
        std::cout << "\n";
    }

    void insertAsciiTableToVector(std::vector<char> &v)
    {
        constexpr int firstAsciiCode = 32;
        std::generate_n(std::back_inserter(v), 95, [n=firstAsciiCode]() mutable { return static_cast<char>(n++); });
    }

    void shuffleVector(std::vector<char> &v)
    {
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(v.begin(), v.end(), g);
    }

    CipherMap createMapFromVectors(const std::vector<char>& keys, const std::vector<char>& values)
    {
        CipherMap m;
        std::transform(keys.cbegin(), 
                    keys.cend(), 
                    values.cbegin(), 
                    std::inserter(m, m.begin()),
                    [](char a, char b){return std::make_pair(a, b);});
        return m;
    }

    void makeEncodingMap()
    {
        std::vector<char> ascii{};
        insertAsciiTableToVector(ascii);
        std::vector<char> cipheredAscii = ascii;
        shuffleVector(cipheredAscii);
        encMap = createMapFromVectors(ascii, cipheredAscii);    
    }

    void makeDecodingMapBasedOnEncodingMap()
    {
        std::transform( encMap.cbegin(),
                        encMap.cend(),
                        std::inserter(decMap, decMap.begin()),
                        [](std::pair<char, char> p){ return std::make_pair(p.second, p.first); });                
    }
};


class CipherUserInterface
{
public:
    CipherUserInterface(MyAwesomeCipher& someCipher)
        :cipher(someCipher)
    {        
        createMMFunctions();
    }

    void mainMenu()
    {
        unsigned choice;
        try
        {
            for(;;)
            {
                printMenuAndMakeChoice();        
                std::cin >> choice;
                std::cin.ignore();
                mainMenuFunctions[choice]();            
            }
        }
        catch(const MainMenuQuiter)
        {
        }
    }

private:
    class MainMenuQuiter{};
    typedef std::map<unsigned, std::function<void ()>> MMFunctions;
    MMFunctions mainMenuFunctions;
    MyAwesomeCipher& cipher;  

    void printMenuAndMakeChoice()
    {
        std::cout << "- - - - - - - - - - - - - - - - - - \n";
        std::cout << "1. Encrypt a string\n";
        std::cout << "2. Decrypt a string\n";
        std::cout << "3. Print encryption map\n";
        std::cout << "4. Exit\n";
        std::cout << "- - - - - - - - - - - - - - - - - - \n";
        std::cout << "Make your choice and hit return: "; 
    }    
    
    void createMMFunctions()
    {
        mainMenuFunctions[1] = std::bind(&CipherUserInterface::encryptString, this);
        mainMenuFunctions[2] = std::bind(&CipherUserInterface::decryptString, this);
        mainMenuFunctions[3] = std::bind(&CipherUserInterface::printEncodingMap, this);
        mainMenuFunctions[4] = std::bind(&CipherUserInterface::quitFromMainMenu, this);
    }

    void printEncodingMap()
    {
        std::cout << "Using encoding map:\n";
        cipher.printMap();
    }

    void encryptString()
    {
        std::cout << "Enter string that will be encrypted: \n";
        std::string enteredString;
        std::getline(std::cin, enteredString);
        std::cout << "Entered string after encryption: " << cipher.encode(enteredString) << "\n";    
    }

    void decryptString()
    {
        std::cout << "Enter string that will be decrypted: \n";
        std::string enteredString;
        std::getline(std::cin, enteredString);
        std::cout << "Entered string after decryption: " << cipher.decode(enteredString) << "\n";    
    }

    void quitFromMainMenu()
    {
        throw MainMenuQuiter();
    }
};

void tests4AwesomeCipher()
    {
        std::string sampleString, encodedSampleString, decodedSampleString;
        sampleString = "@! Ala ma kota, Milicjant ma pale0123";
        MyAwesomeCipher myAwesomeCipher;
        encodedSampleString = myAwesomeCipher.encode(sampleString);
        decodedSampleString = myAwesomeCipher.decode(encodedSampleString);
        
        assert(sampleString.size()==encodedSampleString.size());
        assert(sampleString!=encodedSampleString);
        assert(sampleString==decodedSampleString);
    }

int main()
{
    tests4AwesomeCipher();
    MyAwesomeCipher myAwesomeCipher;
    CipherUserInterface ui(myAwesomeCipher);
    ui.mainMenu();
    return 0;
}
