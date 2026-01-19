#include "StringUtils.h"

namespace StringUtils{

std::string Slice(const std::string &str, ssize_t start, ssize_t end) noexcept{
    // Replace code here
    return "";
}

std::string Capitalize(const std::string &str) noexcept{
    std::string res = "";
    char ch;
    //Check empty str
    if(str.empty()) return str;

    //Modify first
    if(str.at(0) >= 97 && str.at(0) <= 122){
        ch = str.at(0) - 32;
        res += ch;
    }
    else{
        res += str.at(0);
    }

    //Modify rest
    for(int i = 1; i < str.length(); i++){
        //If upperCase change it to lowerCase
        if(str.at(i) >= 65 && str.at(i) <= 90){
            ch = str.at(i) + 32;
            res += ch;
        }
        //else add it directly into res
        else{
            res += str.at(i);
        }
    }

    return res;
}

std::string Upper(const std::string &str) noexcept{
    // Replace code here
    return "";
}

std::string Lower(const std::string &str) noexcept{
    // Replace code here
    return "";
}

std::string LStrip(const std::string &str) noexcept{
    // Replace code here
    return "";
}

std::string RStrip(const std::string &str) noexcept{
    // Replace code here
    return "";
}

std::string Strip(const std::string &str) noexcept{
    // Replace code here
    return "";
}

std::string Center(const std::string &str, int width, char fill) noexcept{
    // Replace code here
    return "";
}

std::string LJust(const std::string &str, int width, char fill) noexcept{
    // Replace code here
    return "";
}

std::string RJust(const std::string &str, int width, char fill) noexcept{
    // Replace code here
    return "";
}

std::string Replace(const std::string &str, const std::string &old, const std::string &rep) noexcept{
    // Replace code here
    return "";
}

std::vector< std::string > Split(const std::string &str, const std::string &splt) noexcept{
    // Replace code here
    return {};
}

std::string Join(const std::string &str, const std::vector< std::string > &vect) noexcept{
    // Replace code here
    return "";
}

std::string ExpandTabs(const std::string &str, int tabsize) noexcept{
    // Replace code here
    return "";
}

int EditDistance(const std::string &left, const std::string &right, bool ignorecase) noexcept{
    // Replace code here
    return 0;
}

};