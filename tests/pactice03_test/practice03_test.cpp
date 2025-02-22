#include "pch.h"
#include "CppUnitTest.h"
//#include "../../practice/practice03/mathStuff.cpp"
#include "../../practice/practice03/practice03.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace pactice03test
{
	TEST_CLASS(pactice03test)
	{
	public:
		
		TEST_METHOD(TestSumRange_StdRange)
		{
			Assert::AreEqual(15, MathUtils::sumRange(1, 5)); 
		}

		TEST_METHOD(TestSumRange_BadDomain)
		{
			Assert::AreEqual(2, MathUtils::sumRange(2, 2));
		}

		TEST_METHOD(TestSumRange_NegValues)
		{
			Assert::AreEqual(-15, MathUtils::sumRange(-5, 0));
		}


		TEST_METHOD(TestContNeg_DetectNeg)
		{
			std::vector<int> vec = { 1, -2, 3 };
			Assert::IsTrue(MathUtils::containsNegative(vec));
		}

		TEST_METHOD(TestContNeg_PosNumOnly)
		{
			std::vector<int> vec2 = { 1, 2, 3 };
			Assert::IsFalse(MathUtils::containsNegative(vec2));
		}

		TEST_METHOD(TestContNeg_EmptyList)
		{
			std::vector<int> vec3 = {};
			Assert::IsFalse(MathUtils::containsNegative(vec3));
		}

		
		TEST_METHOD(TestFindMax_StdInput)
		{
			std::vector<int> vec1 = {1, 2, 3, 5, 7};
			Assert::AreEqual(7, MathUtils::findMax(vec1));
		}
		TEST_METHOD(TestFindMax_EmptyList)
		{
			std::vector<int> vec3 = { };
			Assert::AreEqual(0, MathUtils::findMax(vec3));
		}
		TEST_METHOD(TestFindMax_EqualValues)
		{
			std::vector<int> vec2 = {1, 1, 1};
			Assert::AreEqual(1, MathUtils::findMax(vec2));
		}

		

		//TEST_METHOD(TestAdd1)
		//{
		//	Assert::AreEqual(5, add(2, 3));
		//}

		//TEST_METHOD(TestDouble1)
		//{
		//	Assert::AreEqual(10, doubleValue(5));
		//}

		//TEST_METHOD(TestFancy1)
		//{
		//	Rectangle r{ 3, 4 };
		//	r.width++;

		//	Assert::AreEqual(16, r.area());
		//	Assert::AreEqual(4, r.width);
		//}


	};
}
