#include <string>
#include <iostream>
#include <vector>
#include <memory>

class File
{
public:
    File() = default;
    virtual bool check_file_type(std::string path) = 0;
    virtual std::string load(std::string path) = 0;
    virtual ~File() = default;
};

class Json : public File
{
public:
    Json() = default;    
    bool check_file_type(std::string path) override
    {
        return path.find(".json") == path.size() - 5;
    }
    std::string load(std::string path) override
    {
        return "Json data from " + path;
    }
};

class Xml : public File
{
public:
    Xml() = default;
    bool check_file_type(std::string path) override
    {
        return path.find(".xml") == path.size() - 4;
    }
    std::string load(std::string path) override
    {
        return "Xml data from " + path;
    }
};

class Html : public File
{
public:
    Html() = default;
    bool check_file_type(std::string path) override
    {
        return path.find(".html") == path.size() - 5;
    }
    std::string load(std::string path) override
    {
        return "html data from " + path;
    }
};

void load_data()
{
    std::string path;
    std::cout << "Enter file name: ";
    try{
        std::cin >> path;
    }
    catch(const std::exception& ex)
    {
        std::cout<< "Wrong input. " << ex.what() << std::endl;
    }

    std::vector<std::shared_ptr<File>> extensionContainer;
    extensionContainer.push_back(std::make_shared<Json>());
    extensionContainer.push_back(std::make_shared<Xml>());
    extensionContainer.push_back(std::make_shared<Html>());

    for (const auto& extension : extensionContainer)
    {
        if (extension->check_file_type(path))
            std::cout<< extension->load(path) << std::endl;
    }
}

int main()
{
    load_data();
}

