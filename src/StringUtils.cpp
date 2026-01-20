#include "../include/StringUtils.h"
#include "stdexcept"
#include "math.h"

namespace StringUtils{

//I actually really want to throw some exceptions when input illegal value, because dont know
//what expected to return if failed. However, there is a noexcept.
std::string Slice(const std::string &str, ssize_t start, ssize_t end) noexcept{
    ssize_t sliceLength;
    const ssize_t strLength = str.length();

    //Check if the start and end is valid
    if(std::abs(start) > strLength | strLength < std::abs(end)){
        return "";
    }

    //Trans negative value to positive
    if(end <= 0) end = strLength + end;
    if(start < 0) start = strLength + start;
    sliceLength = end - start;

    //Check if sliceLegth to slice is legal
    if(sliceLength < 0) return "";

    //Do slice
    std::string sliced = str.substr(start, sliceLength);

    return sliced;
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
    std::string res;

    //Do upperCase
    for(int i = 0; i < str.length(); i++){
        if(str.at(i) >= 97 && str.at(i) <= 122){
            char ch = str.at(i) - 32;
            res += ch;
        }
        else{
            res += str.at(i);
        }
    }

    return res;
}

std::string Lower(const std::string &str) noexcept{
    std::string res;

    //Do upperCase
    for(int i = 0; i < str.length(); i++){
        if(str.at(i) >= 65 && str.at(i) <= 90){
            char ch = str.at(i) + 32;
            res += ch;
        }
        else{
            res += str.at(i);
        }
    }
    
    return res;
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
    if(index == -1) return "";
    return StringUtils::Slice(str, 0, index + 1);
}

std::string Strip(const std::string &str) noexcept{
    //Combine LStrip and RStrip is BothStrip
    return StringUtils::LStrip(StringUtils::RStrip(str));
}

std::string Center(const std::string &str, int width, char fill) noexcept{
    std::string res = "";
    if(str.length() >= width) return str;
    width -= str.length();

    for(int i = 0; i < width / 2; i++){
        res += fill;
    }
    res += str;
    for(int i = 0; i < width / 2; i++){
        res += fill;
    }

    //if width is odd
    if(width % 2 == 1){
        res += fill;
    }
    return res;
}

std::string LJust(const std::string &str, int width, char fill) noexcept{
    if(str.length() >= width) return str;
    width -= str.length();
    std::string res = "";

    for(int i = 0; i < width; i++){
        res += fill;
    }
    res += str;

    return res;
}

std::string RJust(const std::string &str, int width, char fill) noexcept{
    if(str.length() >= width) return str;
    width -= str.length();
    std::string res = "";

    res += str;
    for(int i = 0; i < width; i++){
        res += fill;
    }

    return res;
}

std::string Replace(const std::string &str, const std::string &old, const std::string &rep) noexcept{
    std::string res = "";
    //str empty
    if(str == ""){
        if(old == "") return rep;
        return "";
    }

    //replace old empty
    if(old == ""){
        res += rep;
        for(int i = 0; i < str.length(); i++){
            res += str.at(i);
            res += rep;
        }
        return res;
    }

    //replace normal
    for(int i = 0; i < str.length(); i++){
        if(str.at(i) == old.at(0)){
            //if rest str length less than old, it cannot the one we look for
            if(str.length() - i < old.length()){
                res += str.at(i);
                continue;
            }
            std::string sliced = str.substr(i, old.length());
            //check if it is what we look for
            if(sliced.compare(old) == 0){
                res += rep;
                i += old.length() - 1;
                continue;
            }
        }
        //if i is not the one looking for add this to res
        res += str.at(i);
    }

    return res;
    
}

std::vector< std::string > Split(const std::string &str, const std::string &splt) noexcept{
    std::vector<std::string> res;
    std::string split = splt;
    //check empty
    if(str == "")return res;

    //check empty splt
    if(splt == "") split = " ";

    int start = 0;
    int end = 0;

    for(int i = 0; i < str.length(); i++){
        if(str.at(i) == split.at(0)){
            //if rest str length less than split, it cannot the one we look for
            if(str.length() - i < split.length()){
                end ++;
                continue;
            }
            std::string sliced = str.substr(i, split.length());
            //check if it is what we look for
            if(sliced.compare(split) == 0){
                std::string tmp = StringUtils::Slice(str, start, end);
                //Check countinous matching
                if(tmp != ""){
                    res.push_back(tmp);
                }
                i += split.length() - 1;
                end += split.length();
                start = end;
                continue;
            }
        }
        //if i is not the one looking for, end++
        end ++;
    }
    //deal with rest
    if(end - start > 0){
        res.push_back(StringUtils::Slice(str, start, end));
    }

    return res;
}

std::string Join(const std::string &str, const std::vector< std::string > &vect) noexcept{
    std::string res = "";
    //tempty check
    if(vect.empty()) return "";

    for(int i = 0; i < vect.size() - 1; i++){
        res += vect.at(i);
        res += str;
    }
    
    //deal with rest
    res += vect.at(vect.size() - 1);
    return res;
}

std::string ExpandTabs(const std::string &str, int tabsize) noexcept{
    //empty check
    if(str == "") return "";
    std::string res = "";

    for(int i = 0; i < str.length(); i++){
        //if current char is tab
        if(str.at(i) == 9){
            //add tabsize of space to res
            for(int k = 0; k < tabsize; k++){
                res += ' ';
            }
        }
        //if it is not tab, directly add it to res
        else{
            res += str.at(i);
        }
    }
    return res;
}

int EditDistance(const std::string &left, const std::string &right, bool ignorecase) noexcept{
    // Replace code here
    return 0;
}

};