#include <string>
#include <iostream>

enum class fileTypes
{
    Json,
    Xml,
    Html,
    JsonInZip,
    XmlInZip,
    HtmlInZip,
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
    } else if(path.back() == 'p') {
        path = path.substr(0, path.size() - 4);
        if(path.back() == 'l')
        {
            if(path.rfind('.') == (path.size() - 4))
                return fileTypes::XmlInZip;
            return fileTypes::HtmlInZip;
        }
        return fileTypes::JsonInZip;
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

std::string load_json_in_zip(std::string path)
{
    std::string result = "unziped";
    path = path.substr(0, path.size() - 4);
    return result + " " + "json data from " + path;
}

std::string load_xml_in_zip(std::string path)
{
    std::string result = "unziped";
    path = path.substr(0, path.size() - 4);
    return result + " " + "xml data from " + path;
}

std::string load_html_in_zip(std::string path)
{
    std::string result = "unziped";
    path = path.substr(0, path.size() - 4);
    return result + " " + "html data from " + path;
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

    try {
        if(get_file_type(path) == fileTypes::JsonInZip)
            std::cout << load_json_in_zip(path) << std::endl;
    } catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }

    try {
        if(get_file_type(path) == fileTypes::XmlInZip)
            std::cout << load_xml_in_zip(path) << std::endl;
    } catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }

    try {
        if(get_file_type(path) == fileTypes::HtmlInZip)
            std::cout << load_html_in_zip(path) << std::endl;
    } catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
}

int main()
{
    load_data();
}