#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <cassert>

class IFile
{
public:
    IFile() = default;
    IFile(IFile &&  ) = default;

    virtual bool isValidType(std::string path) = 0;

    virtual std::string load(std::string path) = 0;

    virtual ~IFile() = default;
};

class JSONFile : public IFile
{
public:
    JSONFile() = default;
    JSONFile(JSONFile &&  ) = default;

    bool isValidType(std::string path) override {
        return path.find(".json") == path.size() - 5;
    }

    std::string load(std::string path) override {
        return "json data from " + path;
    }
};

class XMLFile : public IFile
{
public:
    XMLFile() = default;
    XMLFile(XMLFile &&  ) = default;
 
    bool isValidType(std::string path) override {
        return path.find(".xml") == path.size() - 4;
    }

    std::string load(std::string path) override {
         return "xml data from " + path;
    }
};

class HTMLFile : public IFile
{
public:
    HTMLFile() = default;
    HTMLFile(HTMLFile &&  ) = default;

    bool isValidType(std::string path) override {
        return path.find(".html") == path.size() - 5;
    }

    std::string load(std::string path) override {
         return "html data from " + path;
    }
    
};

void load_data(std::string path)
{
    std::vector<std::unique_ptr<IFile>> filesReader;
    filesReader.push_back(std::move(std::make_unique<JSONFile>()));
    filesReader.push_back(std::move(std::make_unique<XMLFile>()));
    filesReader.push_back(std::move(std::make_unique<HTMLFile>()));

    for(const auto& reader : filesReader)
    {
            if(reader->isValidType(path)) {
                std::cout << reader->load(path) << std::endl;
                return;
            }
    }
    throw std::runtime_error("File format " + path + "not implemented");
}

std::string userInput()
{
    std::string path;
    std::cout << "Enter file name: ";
    std::cin >> path;

    return path; 
}


void JSONTest()
{
    JSONFile jSONFile;
    assert(jSONFile.isValidType("a.json"));
    assert(!jSONFile.load("a.json").compare("json data from a.json"));
}

void XMLTest()
{
    XMLFile xMLFile;
    assert(xMLFile.isValidType("a.xml"));
    assert(!xMLFile.load("a.xml").compare("xml data from a.xml"));
}

void HTMLTest()
{
    HTMLFile hTMLFIle;
    assert(hTMLFIle.isValidType("a.html"));
    assert(!hTMLFIle.load("a.html").compare("html data from a.html"));
}


int main()
{
    JSONTest();
    XMLTest();
    HTMLTest();

    //userInput();

    std::vector<std::string> files = 
    {
        "a.json",
        "a.xml",
        "a.html",
        "a.zip",
    };

    for(auto f : files)
    {
        try {
            load_data(f);
        } catch(const std::exception& e) {
            std::cerr << e.what() << '\n';
        }
    }

}