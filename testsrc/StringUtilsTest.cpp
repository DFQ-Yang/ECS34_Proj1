#include <gtest/gtest.h>
#include "StringUtils.h"

TEST(StringUtilsTest, SliceTest){
    
}

TEST(StringUtilsTest, Capitalize){
    
}

TEST(StringUtilsTest, Upper){
    
}

TEST(StringUtilsTest, Lower){
    
}

TEST(StringUtilsTest, LStrip){
   std::string striped;
   //Test empty and blank
   striped = StringUtils::LStrip("");
   EXPECT_EQ(striped, "");
   striped = StringUtils::LStrip("           ");
   EXPECT_EQ(striped, "");

   //Test normal
   striped = StringUtils::LStrip("       WSL is so bad which occupied my C disk  ");
   EXPECT_EQ(striped, "WSL is so bad which occupied my C disk  ");
}

TEST(StringUtilsTest, RStrip){
    std::string striped;
   //Test empty and blank
   striped = StringUtils::LStrip("");
   EXPECT_EQ(striped, "");
   striped = StringUtils::LStrip("           ");
   EXPECT_EQ(striped, "");

   //Test normal
   striped = StringUtils::LStrip("       WSL is so bad which occupied my C disk  ");
   EXPECT_EQ(striped, "       WSL is so bad which occupied my C disk");
}

TEST(StringUtilsTest, Strip){
    std::string striped;
   //Test empty and blank
   striped = StringUtils::LStrip("");
   EXPECT_EQ(striped, "");
   striped = StringUtils::LStrip("           ");
   EXPECT_EQ(striped, "");

   //Test normal
   striped = StringUtils::LStrip("       WSL is so bad which occupied my C disk  ");
   EXPECT_EQ(striped, "WSL is so bad which occupied my C disk");
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
