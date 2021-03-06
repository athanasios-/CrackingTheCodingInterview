/*
 * BitManipulator_test.cpp
 *
 *  Created on: Dec 18, 2014
 *      Author: ubuntu
 */
#include <gtest/gtest.h>
#include "BitManipulator.h"
#include <limits>

using namespace std;

namespace chapterFive {

TEST(BitManipulatorTest, MakeSubstringHappyFlowOne){
	unsigned int maxInt = numeric_limits<int>::max();
	unsigned int five = 5;
	ASSERT_EQ(maxInt - 2, BitManipulator::makeSubstring(maxInt, five, 0, 2));
}

TEST(BitManipulatorTest, MakeSubstringHappyFlowTwo){
	unsigned int maxInt = numeric_limits<int>::max();
	unsigned int five = 5;
	ASSERT_EQ(maxInt - 4, BitManipulator::makeSubstring(maxInt, five, 1, 3));
}

TEST(BitManipulatorTest, MakeSubstringHappyFlowThree){
	unsigned int maxInt = numeric_limits<int>::max();
	unsigned int five = 5;
	ASSERT_EQ(maxInt - 8, BitManipulator::makeSubstring(maxInt, five, 2, 4));
}

TEST(BitManipulatorTest, PrintDecimalHappyFlow){
	string number = "2.5";
	ASSERT_EQ("10.1", BitManipulator::printDecimal(number));
}

TEST(BitManipulatorTest, PrintDecimalNoRepresentation){
	string number = "2.3";
	ASSERT_EQ("ERROR", BitManipulator::printDecimal(number));
}


TEST(BitManipulatorTest, NextBiggerOne){
	unsigned int num = 1;
	ASSERT_EQ(2, BitManipulator::getNextBiggerWithSameNumberOfOnes(num));
}

TEST(BitManipulatorTest, NextBiggerFive){
	unsigned int num = 5;
	ASSERT_EQ(6, BitManipulator::getNextBiggerWithSameNumberOfOnes(num));
}

TEST(BitManipulatorTest, NextBiggerThirtyTwo){
	unsigned int num = 32;
	ASSERT_EQ(64, BitManipulator::getNextBiggerWithSameNumberOfOnes(num));
}

TEST(BitManipulatorTest, NextBiggerEleven){
	unsigned int num = 11;
	ASSERT_EQ(13, BitManipulator::getNextBiggerWithSameNumberOfOnes(num));
}

TEST(BitManipulatorTest, NextBiggerTwentyEight){
	unsigned int num = 28;
	ASSERT_EQ(35, BitManipulator::getNextBiggerWithSameNumberOfOnes(num));
}

TEST(BitManipulatorTest, NextBiggerMax){
	unsigned int num = numeric_limits<unsigned int>::max()-1;
	ASSERT_EQ(0, BitManipulator::getNextBiggerWithSameNumberOfOnes(num));
}

TEST(BitManipulatorTest, NextSmallerTwo){
	unsigned int num = 2;
	ASSERT_EQ(1, BitManipulator::getNextSmallerWithSameNumberOfOnes(num));
}

TEST(BitManipulatorTest, NextSmallerEleven){
	unsigned int num = 11;
	ASSERT_EQ(7, BitManipulator::getNextSmallerWithSameNumberOfOnes(num));
}

TEST(BitManipulatorTest, NextSmallerSixtyFour){
	unsigned int num = 64;
	ASSERT_EQ(32, BitManipulator::getNextSmallerWithSameNumberOfOnes(num));
}

TEST(BitManipulatorTest, NextSmallerThertyFive){
	unsigned int num = 35;
	ASSERT_EQ(28, BitManipulator::getNextSmallerWithSameNumberOfOnes(num));
}

TEST(BitManipulatorTest, NextSmallerMaxWithSmaller){
	unsigned int num = numeric_limits<unsigned int>::max()-1;
	ASSERT_EQ(numeric_limits<unsigned int>::max()-2, BitManipulator::getNextSmallerWithSameNumberOfOnes(num));
}

TEST(BitManipulatorTest, NextSmallerMaxWithoutSmaller){
	unsigned int num = numeric_limits<unsigned int>::max()- pow(2,32);
	ASSERT_EQ(0, BitManipulator::getNextSmallerWithSameNumberOfOnes(num));
}

TEST(BitManipulatorTest, FindNumberOfBitChangesZero){
	unsigned int source = 2;
	unsigned int target = 2;
	ASSERT_EQ(0, BitManipulator::findNumberOrBitChanges(source, target));
}

TEST(BitManipulatorTest, FindNumberOfBitChangesOne){
	unsigned int source = 3;
	unsigned int target = 2;
	ASSERT_EQ(1, BitManipulator::findNumberOrBitChanges(source, target));
}

TEST(BitManipulatorTest, FindNumberOfBitChangesTwo){
	unsigned int source = 31;
	unsigned int target = 14;
	ASSERT_EQ(2, BitManipulator::findNumberOrBitChanges(source, target));
}

TEST(BitManipulatorTest, FindNumberOfBitChangesThertyTwo){
	unsigned int source = numeric_limits<unsigned int>::max();
	unsigned int target = 0;
	ASSERT_EQ(32, BitManipulator::findNumberOrBitChanges(source, target));
}

TEST(BitManipulatorTest, SwapEvenOdd){
	unsigned int source = 5;
	ASSERT_EQ(10, BitManipulator::swapEvenOdd(source));
}

TEST(BitManipulatorTest, SwapEvenOddSecond){
	unsigned int source = 10;
	ASSERT_EQ(5, BitManipulator::swapEvenOdd(source));
}

TEST(BitManipulatorTest, FindMissingInt){
	StrangeArray data(5,4);
	ASSERT_EQ(4, BitManipulator::findMissingInt(data));
}

TEST(BitManipulatorTest, FindMissingIntSecond){
	StrangeArray data(132,7);
	ASSERT_EQ(7, BitManipulator::findMissingInt(data));
}

} /* namespace chapterFive */
