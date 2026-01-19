#include <gtest/gtest.h>
#include "StringUtils.h"

TEST(StringUtilsTest, SliceTest){
    //basic but end != 0
    EXPECT_EQ(StringUtils::Slice("abcdef", 0, 1), std::string("a"));
    EXPECT_EQ(StringUtils::Slice("abcdef", 1, 4), std::string("bcd"));
    EXPECT_EQ(StringUtils::Slice("abcdef", 0, 6), std::string("abcdef"));
    EXPECT_EQ(StringUtils::Slice("abcdef", 2, 5), std::string("cde"));
    //end = 0 means to the end!!!
    EXPECT_EQ(StringUtils::Slice("abcdef", 0, 0), std::string("abcdef"));
    EXPECT_EQ(StringUtils::Slice("abcdef", 1, 0), std::string("bcdef"));
    EXPECT_EQ(StringUtils::Slice("abcdef", 2, 0), std::string("cdef"));
    EXPECT_EQ(StringUtils::Slice("abcdef", 3, 0), std::string("def"));
    EXPECT_EQ(StringUtils::Slice("abcdef", 4, 0), std::string("ef"));
    EXPECT_EQ(StringUtils::Slice("abcdef", 5, 0), std::string("f"));
    EXPECT_EQ(StringUtils::Slice("abcdef", 6, 0), std::string(""));
    EXPECT_EQ(StringUtils::Slice("abcdef", 7, 0), std::string(""));
    //negative start value
    EXPECT_EQ(StringUtils::Slice("abcdef", -1, 0), std::string("f"));
    EXPECT_EQ(StringUtils::Slice("abcdef", -2, 0), std::string("ef"));
    EXPECT_EQ(StringUtils::Slice("abcdef", -3, 0), std::string("def"));
    EXPECT_EQ(StringUtils::Slice("abcdef", -4, 0), std::string("cdef"));
    EXPECT_EQ(StringUtils::Slice("abcdef", -5, 0), std::string("bcdef"));
    EXPECT_EQ(StringUtils::Slice("abcdef", -6, 0), std::string("abcdef"));
    EXPECT_EQ(StringUtils::Slice("abcdef", -7, 0), std::string("abcdef"));
    //negative end
    EXPECT_EQ(StringUtils::Slice("abcdef", 0, -1), std::string("abcde"));
    EXPECT_EQ(StringUtils::Slice("abcdef", 0, -2), std::string("abcd"));
    EXPECT_EQ(StringUtils::Slice("abcdef", 0, -5), std::string("a"));
    EXPECT_EQ(StringUtils::Slice("abcdef", 0, -6), std::string(""));
    EXPECT_EQ(StringUtils::Slice("abcdef", 0, -9), std::string(""));
    EXPECT_EQ(StringUtils::Slice("abcdef", 1, -1), std::string("bcde"));
    EXPECT_EQ(StringUtils::Slice("abcdef", -4, -1), std::string("cde"));
    EXPECT_EQ(StringUtils::Slice("abcdef", -6, -5), std::string("a"));
    EXPECT_EQ(StringUtils::Slice("abcdef", -7, -5), std::string("a"));
    //large range
    EXPECT_EQ(StringUtils::Slice("abcdef", -100, 2), std::string("ab"));
    EXPECT_EQ(StringUtils::Slice("abcdef", 2, 100), std::string("cdef"));
    EXPECT_EQ(StringUtils::Slice("abcdef", -100, 100), std::string("abcdef"));
    EXPECT_EQ(StringUtils::Slice("abcdef", 100, 0), std::string(""));
    EXPECT_EQ(StringUtils::Slice("abcdef", 100, 200), std::string(""));
    EXPECT_EQ(StringUtils::Slice("abcdef", 0, -100), std::string(""));
    //start>=end
    EXPECT_EQ(StringUtils::Slice("abcdef",3, 3), std::string(""));
    EXPECT_EQ(StringUtils::Slice("abcdef", 4, 3), std::string(""));
    //empty string
    EXPECT_EQ(StringUtils::Slice("", 0, 0), std::string(""));
    EXPECT_EQ(StringUtils::Slice("", 0, 3), std::string(""));
    EXPECT_EQ(StringUtils::Slice("", -1, 0), std::string(""));
    EXPECT_EQ(StringUtils::Slice("", -100, 100), std::string(""));
    //one char
    EXPECT_EQ(StringUtils::Slice("a", 0, 1), std::string("a"));
    EXPECT_EQ(StringUtils::Slice("a", 0, 0), std::string("a"));
    EXPECT_EQ(StringUtils::Slice("a", 1, 0), std::string(""));
    EXPECT_EQ(StringUtils::Slice("a", -1, 0), std::string("a"));
    EXPECT_EQ(StringUtils::Slice("a", 0, -1), std::string(""));
}



TEST(StringUtilsTest, Capitalize){
    EXPECT_EQ(StringUtils::Capitalize(""), std::string(""));
    EXPECT_EQ(StringUtils::Capitalize("hello"), std::string("Hello"));
    EXPECT_EQ(StringUtils::Capitalize(" hello world"), std::string(" hello world"));
    EXPECT_EQ(StringUtils::Capitalize("hello world"), std::string("Hello world"));
    EXPECT_EQ(StringUtils::Capitalize("HELLO WORLD"), std::string("Hello world"));
}

TEST(StringUtilsTest, Upper){
    EXPECT_EQ(StringUtils::Upper("hello"), std::string("HELLO"));
    EXPECT_EQ(StringUtils::Upper("Hello"), std::string("HELLO"));
    EXPECT_EQ(StringUtils::Upper("He!ll-o"), std::string("HE!LL-O"));
    EXPECT_EQ(StringUtils::Upper(""), std::string(""));
    EXPECT_EQ(StringUtils::Upper(" "), std::string(" "));
}

TEST(StringUtilsTest, Lower){
    EXPECT_EQ(StringUtils::Lower("HELLO"), std::string("hello"));
    EXPECT_EQ(StringUtils::Lower("Hello"), std::string("hello"));
    EXPECT_EQ(StringUtils::Lower("He!ll-o"), std::string("he!ll-o"));
    EXPECT_EQ(StringUtils::Lower(""), std::string(""));
    EXPECT_EQ(StringUtils::Lower(" "), std::string(" "));
}

TEST(StringUtilsTest, LStrip){
    EXPECT_EQ(StringUtils::LStrip("Hello"), std::string("Hello"));
    EXPECT_EQ(StringUtils::LStrip(" Hello"), std::string("Hello"));
    EXPECT_EQ(StringUtils::LStrip("Hello "), std::string("Hello "));
    EXPECT_EQ(StringUtils::LStrip("   Hello"), std::string("Hello"));
    EXPECT_EQ(StringUtils::LStrip(" \r \t \nHello"), std::string("Hello"));
}

TEST(StringUtilsTest, RStrip){
    EXPECT_EQ(StringUtils::RStrip("      "),std::string(""));
    EXPECT_EQ(StringUtils::RStrip(""),std::string(""));
    EXPECT_EQ(StringUtils::RStrip("Hello"),std::string("Hello"));
    EXPECT_EQ(StringUtils::RStrip("Hello "),std::string("Hello"));
    EXPECT_EQ(StringUtils::RStrip(" Hello"),std::string(" Hello"));
    EXPECT_EQ(StringUtils::RStrip("Hello   "),std::string("Hello"));
    EXPECT_EQ(StringUtils::RStrip("Hello \r \t \n"),std::string("Hello"));
}

TEST(StringUtilsTest, Strip){
    EXPECT_EQ(StringUtils::Strip(" Hello"),std::string("Hello"));
    EXPECT_EQ(StringUtils::Strip("Hello "),std::string("Hello"));
    EXPECT_EQ(StringUtils::Strip("   Hello"),std::string("Hello"));
    EXPECT_EQ(StringUtils::Strip(" \r \t \nHello"),std::string("Hello"));
    EXPECT_EQ(StringUtils::Strip("      "),std::string(""));
    EXPECT_EQ(StringUtils::Strip(""),std::string(""));
    EXPECT_EQ(StringUtils::Strip("Hello   "),std::string("Hello"));
    EXPECT_EQ(StringUtils::Strip("Hello \r \t \n"),std::string("Hello"));
    EXPECT_EQ(StringUtils::Strip(" \r \t \nHello \r \t \n"),std::string("Hello"));
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
