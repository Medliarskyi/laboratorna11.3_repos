#include "pch.h"
#include "CppUnitTest.h"
#include "../lab11.3/lab11.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest113
{
	TEST_CLASS(UnitTest113)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            string testFile = "test_students.txt";

            ofstream testFileStream(testFile);
            testFileStream << "Smith 85 90 78\n";
            testFileStream << "Johnson 72 88 95\n";
            testFileStream << "Brown 89 84 91\n";
            testFileStream.close();

            stringstream outputBuffer;
            streambuf* originalCoutBuffer = cout.rdbuf(outputBuffer.rdbuf());

            viewFile(testFile);

            cout.rdbuf(originalCoutBuffer);

            string expectedOutput =
                "Surname             Grade 1   Grade 2   Grade 3   \n"
                "--------------------------------------------------\n"
                "Smith               85        90        78        \n"
                "Johnson             72        88        95        \n"
                "Brown               89        84        91        \n"
                "--------------------------------------------------\n";

            Assert::AreEqual(expectedOutput, outputBuffer.str());
		}
	};
}
