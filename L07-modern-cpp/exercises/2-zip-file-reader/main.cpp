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



class IPackage
{
public:
    IPackage() = default;
    IPackage(IPackage&& ) = default;

    virtual bool isCompressed(const std::string& path) = 0;

    virtual std::string  decomression(const std::string& path) = 0;

    virtual ~IPackage() = default;
};

class ZIPPackage : public IPackage
{
public:
    ZIPPackage() = default;
    ZIPPackage(ZIPPackage&& ) = default;

    bool isCompressed(const std::string& path) override {
        return path.find("InZip", path.size()-6) != std::string::npos;
    }

    std::string decomression(const std::string& path) override {
        std::cout << "file " + path + " unziped " << std::endl;
        return  path.substr(0, path.size() - 5);
    }
};

void ZIPTest()
{
    ZIPPackage zIPPackage;

    assert(zIPPackage.isCompressed("a.jsonInZip"));
    assert(!zIPPackage.decomression("a.jsonInZip").compare("a.json"));

    assert(zIPPackage.isCompressed("a.xmlInZip"));
    assert(!zIPPackage.decomression("a.xmlInZip").compare("a.xml"));

    assert(zIPPackage.isCompressed("a.htmlInZip"));
    assert(!zIPPackage.decomression("a.htmlInZip").compare("a.html"));
}


std::string unpack_file(const std::string& path)
{
    std::vector<std::unique_ptr<IPackage>> Packaging;
    Packaging.push_back(std::move(std::make_unique<ZIPPackage>()));

    for(const auto& e : Packaging)
    {
        if(e->isCompressed(path)) {
            return e->decomression(path);
        }
    }
    return path;
}


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
    throw std::runtime_error("File format " + path + " not implemented");
}


std::string userInput()
{
    std::string path;
    std::cout << "Enter file name: ";
    std::cin >> path;

    return path; 
}

int main()
{
    ZIPTest();
    JSONTest();
    XMLTest();
    HTMLTest();

    //userInput();

    std::vector<std::string> files = 
    {
        "a.json",
        "a.xml",
        "a.html",
        "a.jsonInZip",
        "a.xmlInZip",
        "a.htmlInZip",
        "a.htmlInRar",
    };

    for(auto f : files)
    {
        std::string unpacked = unpack_file(f);
        load_data(unpacked);
    }

}