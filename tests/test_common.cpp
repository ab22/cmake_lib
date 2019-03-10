#include "libmath/lib.h"
#include "gtest/gtest.h"

TEST(TestMagicalNumber, ValidateMagicNumber)
{
	int magic_number = libmath::get_magic_number();

	EXPECT_EQ(magic_number, 22);
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	auto result = RUN_ALL_TESTS();
	return result;
}
