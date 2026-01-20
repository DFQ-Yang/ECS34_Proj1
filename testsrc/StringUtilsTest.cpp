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
    std::string lowered;
    //Test empty and blank
    lowered = StringUtils::Lower("");
    EXPECT_EQ(lowered, "");
    lowered = StringUtils::Lower("           ");
    EXPECT_EQ(lowered, "           ");

    //Test with numbers
    lowered = StringUtils::Lower("Only 90 more MB remaining, what can I do....");
    EXPECT_EQ(lowered, "only 90 more mb remaining, what can i do....");

    //Test normal
    lowered = StringUtils::Lower("If it is not the problem of WSL");
    EXPECT_EQ(lowered, "if it is not the problem of wsl");
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
   striped = StringUtils::RStrip("");
   EXPECT_EQ(striped, "");
   striped = StringUtils::RStrip("           ");
   EXPECT_EQ(striped, "");

   //Test normal
   striped = StringUtils::RStrip("       WSL is so bad which occupied my C disk  ");
   EXPECT_EQ(striped, "       WSL is so bad which occupied my C disk");
}

TEST(StringUtilsTest, Strip){
    std::string striped;
   //Test empty and blank
   striped = StringUtils::Strip("");
   EXPECT_EQ(striped, "");
   striped = StringUtils::Strip("           ");
   EXPECT_EQ(striped, "");

   //Test normal
   striped = StringUtils::Strip("       WSL is so bad which occupied my C disk  ");
   EXPECT_EQ(striped, "WSL is so bad which occupied my C disk");
}

TEST(StringUtilsTest, Center){
    std::string str = "Thanks to AI, now I have 600 more MB space";
    std::string centered;

    //Test 0 width
    centered = StringUtils::Center(str, 0);
    EXPECT_EQ(centered, "Thanks to AI, now I have 600 more MB space");

    //Test empty str
    centered = StringUtils::Center("", 7, 'k');
    EXPECT_EQ(centered, "kkkkkkk");

    //Test normal and default val, odd number
    centered = StringUtils::Center(str, 45);
    EXPECT_EQ(centered, " Thanks to AI, now I have 600 more MB space  ");
}

TEST(StringUtilsTest, LJust){
    std::string str = "I hate WSL, even docker";
    std::string lsted;

    //Test 0 width
    lsted = StringUtils::LJust(str, 0);
    EXPECT_EQ(lsted, "I hate WSL, even docker");

    //Test empty str
    lsted = StringUtils::LJust("", 8, 'k');
    EXPECT_EQ(lsted, "kkkkkkkk");

    //Test normal and default val
    lsted = StringUtils::LJust(str, 27);
    EXPECT_EQ(lsted, "    I hate WSL, even docker");
}

TEST(StringUtilsTest, RJust){
    std::string str = "I hate WSL, even docker";
    std::string lsted;

    //Test 0 width
    lsted = StringUtils::RJust(str, 0);
    EXPECT_EQ(lsted, "I hate WSL, even docker");

    //Test empty str
    lsted = StringUtils::RJust("", 8, 'k');
    EXPECT_EQ(lsted, "kkkkkkkk");

    //Test normal and default val
    lsted = StringUtils::RJust(str, 27);
    EXPECT_EQ(lsted, "I hate WSL, even docker    ");
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
