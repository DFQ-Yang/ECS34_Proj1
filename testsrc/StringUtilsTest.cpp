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
    std::string str = "monkey love banana?";
    std::string res;

    //test empty
    res = StringUtils::Replace("", "ana", "bnb");
    EXPECT_EQ(res, "");

    //test no exist
    res = StringUtils::Replace("who m I", "454", "777");
    EXPECT_EQ(res, "who m I");

    //test normal
    res = StringUtils::Replace(str, "an", "bnb");
    EXPECT_EQ(res, "monkey love bbnbbnba?");

    //test empty old
    res = StringUtils::Replace("ab cd", "", "k");
    EXPECT_EQ(res, "kakbk kckdk");

    //test old,str empty
    res = StringUtils::Replace("", "", "ccc");
    EXPECT_EQ(res, "ccc");
}

TEST(StringUtilsTest, Split){
    std::string str = "no time left !!!!";
    std::vector<std::string> res;
    std::vector<std::string> tmp;

    //test empty str
    res = StringUtils::Split("", "aaa");
    EXPECT_EQ(res, tmp);

    //test normal
    res = StringUtils::Split(str, "e");
    tmp.clear();
    tmp.push_back("no tim");
    tmp.push_back(" l");
    tmp.push_back("ft !!!!");
    EXPECT_EQ(res, tmp);

    //test piles
    res = StringUtils::Split(str, "!");
    tmp.clear();
    tmp.push_back("no time left ");
    EXPECT_EQ(res, tmp);

    //test empty
    res = StringUtils::Split(str, "");
    tmp.clear();
    tmp.push_back("no");
    tmp.push_back("time");
    tmp.push_back("left");
    tmp.push_back("!!!!");
    EXPECT_EQ(res, tmp);

    //test string
    res = StringUtils::Split(str, "o time left !!!");
    tmp.clear();
    tmp.push_back("n");
    tmp.push_back("!");
    EXPECT_EQ(res, tmp);
}

TEST(StringUtilsTest, Join){
    std::vector<std::string> vector = {"About", "two", "hours", "left", "before", "ddl"};
    std::string res;
    
    //test empty vector
    res = StringUtils::Join(" ", {});
    EXPECT_EQ(res, "");

    //test space
    res = StringUtils::Join(" ", vector);
    EXPECT_EQ(res, "About two hours left before ddl");

    //test empty str
    res = StringUtils::Join("", vector);
    EXPECT_EQ(res, "Abouttwohoursleftbeforeddl");

    //test str
    res = StringUtils::Join(" but! ", vector);
    EXPECT_EQ(res, "About but! two but! hours but! left but! before but! ddl");
}

TEST(StringUtilsTest, ExpandTabs){
    std::string res;
    std::string test = "\tI\tstill\thave\t2\thours,\tI\tam\tso\tfast!!  ";

    //test empty str
    res = StringUtils::ExpandTabs("", 7);
    EXPECT_EQ(res, "");

    //test 0 tabspace
    res = StringUtils::ExpandTabs(test, 0);
    EXPECT_EQ(res, "Istillhave2hours,Iamsofast!!  ");

    //test 1 tabspace
    res = StringUtils::ExpandTabs(test, 1);
    EXPECT_EQ(res, " I still have 2 hours, I am so fast!!  ");

    //test default
    res = StringUtils::ExpandTabs(test);
    EXPECT_EQ(res, "    I    still    have    2    hours,    I    am    so    fast!!  ");
}

TEST(StringUtilsTest, EditDistance){
    int res;

    //Test empty left
    res = StringUtils::EditDistance("", "abcdefg", true);
    EXPECT_EQ(res, 7);

    //test empty right
    res = StringUtils::EditDistance("abcdefg", "");
    EXPECT_EQ(res, 7);

    //test both empty
    res = StringUtils::EditDistance("", "", true);
    EXPECT_EQ(res, 0);

    //test same
    res = StringUtils::EditDistance("abcdefg", "abcdefg", true);
    EXPECT_EQ(res, 0);

}
