// Goal - match C++ decimal (base 10) integer strings.

// Digit = r(0|..|9)
// PositiveDigit=r(1|..|9)
// Decimal = r(0|(PositiveDigit((|')Digit)*))

#include "gtest/gtest.h"
#include <regex>
#include <string>

using namespace std;

bool IsDecimal(const std::string &candidate) {
    regex matcher("(-?(0|([1-9]('?[0-9])*))|\\((0|([1-9]('?[0-9])*))\\))");
    return regex_match(candidate,matcher);
}

bool IsDouble(const std::string &candidate) {
    regex matcher("-?(0|([1-9]('?[0-9])*))(\\.[0-9]+)?$");
    return regex_match(candidate,matcher);
}

bool IsIdentifier(const std::string &candidate) {
    regex matcher("[_a-zA-Z][_a-zA-Z0-9]+");
    return regex_match(candidate,matcher);
}

TEST(RegEx,DecimalInteger) {
   ASSERT_TRUE(IsDecimal("0"));
   ASSERT_TRUE(IsDecimal("1"));
   ASSERT_TRUE(IsDecimal("1'2'3"));
   ASSERT_TRUE(IsDecimal("1'000'000"));

   ASSERT_TRUE(IsDecimal("-0"));
   ASSERT_TRUE(IsDecimal("-1"));
   ASSERT_TRUE(IsDecimal("-1'2'3"));
   ASSERT_TRUE(IsDecimal("-1'000'000"));

   ASSERT_FALSE(IsDecimal("-"));
   ASSERT_FALSE(IsDecimal("00"));
   ASSERT_FALSE(IsDecimal("00"));
   ASSERT_FALSE(IsDecimal("0001"));
   ASSERT_FALSE(IsDecimal("1''000''000"));
   ASSERT_FALSE(IsDecimal(".20"));
   ASSERT_FALSE(IsDecimal("20."));
}

TEST(RegEx,Double) {
   ASSERT_TRUE(IsDouble("1"));
   ASSERT_TRUE(IsDouble("123456"));
   ASSERT_TRUE(IsDouble("1.234567"));
   ASSERT_TRUE(IsDouble("-1"));
   ASSERT_TRUE(IsDouble("-1.65768"));
   
   ASSERT_FALSE(IsDouble("HelloMynameISNate")); 
   ASSERT_FALSE(IsDouble("-"));
   ASSERT_FALSE(IsDouble(".384"));
   ASSERT_FALSE(IsDouble("16a"));
   ASSERT_FALSE(IsDouble("''afdgsee''"));

}

TEST(RegEx,Identifier) {
    ASSERT_TRUE(IsIdentifier("Alabama_Tree"));
    ASSERT_TRUE(IsIdentifier("_AskiValue_"));
   
    ASSERT_FALSE(IsIdentifier("123456")); 
    ASSERT_FALSE(IsIdentifier("12_AASF"));
}
