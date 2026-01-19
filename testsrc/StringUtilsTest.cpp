#include <gtest/gtest.h>
#include "StringUtils.h"

TEST(StringUtilsTest, SliceTest){
    
}

TEST(StringUtilsTest, Capitalize){
    
}

TEST(StringUtilsTest, Upper){
    std::string uppered;
    //Test empty and blank
    uppered = StringUtils::Upper("");
    EXPECT_EQ(uppered, "");
    uppered = StringUtils::Upper("           ");
    EXPECT_EQ(uppered, "           ");

    //Test with numbers
    uppered = StringUtils::Upper("Only 90 more MB remaining, what can I do....");
    EXPECT_EQ(uppered, "ONLY 90 MORE MB REMAINING, WHAT CAN I DO....");

    //Test normal
    uppered = StringUtils::Upper("If it is not the problem of WSL");
    EXPECT_EQ(uppered, "IF IT IS NOT THE PROBLEM OF WSL");

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
