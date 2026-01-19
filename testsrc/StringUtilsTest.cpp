#include <gtest/gtest.h>
#include "StringUtils.h"

TEST(StringUtilsTest, SliceTest){
    
}

TEST(StringUtilsTest, Capitalize){
    std::string str = "and my operating system is warning me that no space left right now";
    std::string capitalized;

    //Test empty
    capitalized = StringUtils::Capitalize("");
    EXPECT_EQ(capitalized, "");

    //Test strange start and lowercase for the rest
    capitalized = StringUtils::Capitalize(" acBB");
    EXPECT_EQ(capitalized, " acbb");
    capitalized = StringUtils::Capitalize("?Acb C");
    EXPECT_EQ(capitalized, "?acb c");
    capitalized = StringUtils::Capitalize("666IamnotAhacker!");
    EXPECT_EQ(capitalized, "666iamnotahacker!");

    //test normal
    capitalized = StringUtils::Capitalize(str);
    EXPECT_EQ(capitalized, "And my operating system is warning me that no space left right now");
}

TEST(StringUtilsTest, Upper){
    
}

TEST(StringUtilsTest, Lower){
    
}

TEST(StringUtilsTest, LStrip){
    
}

TEST(StringUtilsTest, RStrip){
    
}

TEST(StringUtilsTest, Strip){
    
}

TEST(StringUtilsTest, Center){
    
}

TEST(StringUtilsTest, LJust){
    
}

TEST(StringUtilsTest, RJust){
    
}

TEST(StringUtilsTest, Replace){
    
}

TEST(StringUtilsTest, Split){
    
}

TEST(StringUtilsTest, Join){
    
}

TEST(StringUtilsTest, ExpandTabs){
    
}

TEST(StringUtilsTest, EditDistance){
    
}
