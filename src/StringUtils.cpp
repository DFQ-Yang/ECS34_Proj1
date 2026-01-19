#include "StringUtils.h"

namespace StringUtils{

std::string Slice(const std::string &str, ssize_t start, ssize_t end) noexcept{
    // Replace code here
    return "";
}

std::string Capitalize(const std::string &str) noexcept{
    // Replace code here
    return "";
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
    //Check empty
    if(str == "") return str;
    int index = 0;
    
    //checking char by char
    for(; index < str.length(); index++){
        if(str.at(index) != 32 && str.at(index) != 9){
            break;
        }
    }

    return StringUtils::Slice(str, index);
}

std::string RStrip(const std::string &str) noexcept{
    //Check empty
    if(str == "") return str;
    int index = str.length() - 1;

    //checking char by char
    for(; index >= 0; index--){
        if(str.at(index) != 32 && str.at(index) != 9){ //32 is space, 9 is tab
            break;
        }
    }

    return StringUtils::Slice(str, 0, index + 1);
}

std::string Strip(const std::string &str) noexcept{
    //Combine LStrip and RStrip is BothStrip
    return StringUtils::RStrip(StringUtils::LStrip(str));
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