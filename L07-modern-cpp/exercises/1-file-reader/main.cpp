#include <string>
#include <iostream>

enum class fileTypes
{
    Json,
    Xml,
    Html,
};

fileTypes get_file_type(std::string path)
{
    if(path.size() < 5)
        throw std::runtime_error("Wrong file name");
    if(path.back() == 'l')
    {
        if(path.rfind('.') == (path.size() - 4))
            return fileTypes::Xml;
        return fileTypes::Html;
    }
    return fileTypes::Json;
}

std::string load_json(std::string path)
{
    return "json data from " + path;
}

std::string load_xml(std::string path)
{
    return "xml data from " + path;
}

std::string load_html(std::string path)
{
    return "html data from " + path;
}

void load_data()
{
    std::string path;
    std::cout << "Enter file name: ";
    std::cin >> path;

    try {
        if(get_file_type(path) == fileTypes::Json)
            std::cout << load_json(path) << std::endl;
    } catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }

    try {
        if(get_file_type(path) == fileTypes::Xml)
            std::cout << load_xml(path) << std::endl;
    } catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }

    try {
        if(get_file_type(path) == fileTypes::Html)
            std::cout << load_html(path) << std::endl;
    } catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
}

int main()
{
    load_data();
}