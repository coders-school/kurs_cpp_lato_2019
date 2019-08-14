#include <random>
#include <limits>
#include <string>
#include <iostream>


std::string encrypt ( std::string word, int key ) 
{
    const int z_letterInASCII = 122;
    const int charBefore_a = 96;
    std::string encrypt_word;
    for (auto el : word)
    {
       if( (static_cast<int>(el) + key) > z_letterInASCII ) 
       {
           int move;
           move = ((static_cast<int>(el) + key) - z_letterInASCII);
           int value;
           value = static_cast<char>(charBefore_a + move);
           encrypt_word.push_back(value);
       }
       else
       {
           int value;
           value = static_cast<int>(el) + key;
           encrypt_word.push_back(static_cast<char>(value));
       }
    }
    return encrypt_word;
}

std::string decrypt ( std::string encrypt_word, int key )
{
    const int a_letterInASCII = 97;
    const int charAfter_z = 123;
    std::string decrypt_word;
    for (auto el : encrypt_word)
    {
        if( (static_cast<int>(el) - key) < a_letterInASCII) 
        {
            int move;
            move = a_letterInASCII - (static_cast<int>(el) - key);
            int value;
            value = static_cast<char>(charAfter_z - move);
            decrypt_word.push_back(value);
        }
        else
        {
            int move;
            move = static_cast<int>(el) - key;
            int value;
            value = static_cast<char>(move);
            decrypt_word.push_back(value);
        }
    }
    return decrypt_word;
}

int main()
{
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<int> d(1,26);
    
    int random;
    random = d(gen);
    std::cout << "Key: " << random << std::endl;
    
    std::string word;
    std::cout << "Word to encrypt: ";
    std::cin >> word;
    
    std::cout << "Encrypted word: " << encrypt(word, random) << std::endl;
    
    std::cout << "Want to see the real message?" << std::endl;
    std::cout << "1. yes" << std::endl;
    std::cout << "2. no(quit)" << std::endl;
    
    int choice;
    
    do
    {
        std::cin >> choice;
    
        switch(choice)
         {
             case 1: 
                {
                    std::cout << "Give me the key: ";
                    int key;
                    std::cin >> key;

                    std::cout << "Encrypted message: ";
                    std::string message;
                    std::cin >> message;

                    std::cout << "The real message is: " << decrypt(message,key) << std::endl;
                    return 0;
                }
            case 2: { return 0; }
            default:
                    std::cout << "Wrong number, try again";
                    break;
        }
    } while(choice != 1 && choice != 2);

    return 0;
}
