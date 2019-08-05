#include <string>

bool palindrom(const std::string& napis)
{
    std::size_t dlugosc = napis.size();
    
    /*
    W naszym przypadku wykorzystujemy znak logiczny mniejszy większy i operujemy na liczbach pełnych 
    co też powoduje że nie zauważyłem żadnych problemów. 
    
    float nie powinien być jednak używany w pętlach. 
    Jest to podyktowane tym, że liczby zmiennoprzecinkowe nie mogą być dokładnie przedstawione w wartościach binarnych.  

    */
    for(float i = 0; i < (dlugosc / 2); ++i)
    {
        if(napis[i] != napis[dlugosc - (i + 1)])
            return false;
    }
    return true;
}
