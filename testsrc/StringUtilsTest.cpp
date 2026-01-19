#include <gtest/gtest.h>
#include "StringUtils.h"

TEST(StringUtilsTest, SliceTest){
    std::string str = "my disk has no space left";
    std::string sliced;

    //Test default as end is 0
    sliced = StringUtils::Slice(str, 0);
    EXPECT_EQ(str, sliced);

    //Test illegal values
    sliced = StringUtils::Slice(str, 25);
    EXPECT_EQ(sliced, "");
    sliced = StringUtils::Slice(str, 1, str.length() + 1);
    EXPECT_EQ(sliced, "");

    //Test illegal length
    sliced = StringUtils::Slice(str, 7, 3);
    EXPECT_EQ(sliced, "");

    //Test positive length
    sliced = StringUtils::Slice(str, 5, 7);
    EXPECT_EQ(sliced, "sk");

    //Test zero length
    sliced = StringUtils::Slice(str, 5, 5);
    EXPECT_EQ(sliced, "");

    //Test negative input
    sliced = StringUtils::Slice(str, -3);
    EXPECT_EQ(sliced, "eft");
    sliced = StringUtils::Slice(str, -7, 23);
    EXPECT_EQ(sliced, "ce le");
}

TEST(StringUtilsTest, Capitalize){
    
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
