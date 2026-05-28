#include <iostream>
#include <json/json.h>

int main()
{
    Json::Value root;
    root["name"] = "Bits";
    root["age"] = 18;

    Json::StreamWriterBuilder writer;
    std::string jsonStr = Json::writeString(writer, root);

    std::cout << jsonStr << std::endl;
    return 0;
}