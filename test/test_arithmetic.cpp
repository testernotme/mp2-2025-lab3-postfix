// тесты для вычисления арифметических выражений

#include <gtest.h>
#include <gtest.h>
#include <arithmetic.h>
#include <math.h>
TEST(TPostfix, can_create_arithmetic)
{
	ASSERT_NO_THROW(TPostfix t("x"));
}

TEST(arithmetic, can_create_arithmetic_1)
{
	ASSERT_NO_THROW(TPostfix("2"));
}

TEST(TPostfix, can_create_arithmetic_2)
{
	ASSERT_NO_THROW(TPostfix("-2"));
}

TEST(TPostfix, can_create_arithmetic_3)
{
	ASSERT_NO_THROW(TPostfix("2.15"));
}


TEST(TPostfix, can_create_arithmetic_4)
{
	ASSERT_NO_THROW(TPostfix("-0.123"));
}


TEST(TPostfix, can_create_arithmetic_5)
{
	ASSERT_NO_THROW(TPostfix("2/3"));
}

TEST(TPostfix, can_create_arithmetic_6)
{
	ASSERT_NO_THROW(TPostfix("sin(2)"));
}

TEST(TPostfix, can_create_arithmetic_7)
{
	ASSERT_NO_THROW(TPostfix("sin(sqrt(2)+1)"));
}


TEST(TPostfix, can_calc_1)
{
	 TPostfix t("2");
	EXPECT_EQ(t.solve(), 2);
}

TEST(TPostfix, can_calc_2)
{
	TPostfix t("-2");
	EXPECT_EQ(t.solve(), -2);
}

TEST(TPostfix, can_calc_3)
{
	TPostfix t("0.123");
	EXPECT_EQ(t.solve(), 0.123);
}

TEST(TPostfix, can_calc_4)
{
	TPostfix t("2+3");
	EXPECT_EQ(t.solve(), 5);
}

TEST(TPostfix, can_calc_5)
{
	TPostfix t("2-3");
	EXPECT_EQ(t.solve(), -1);
}

TEST(TPostfix, can_calc_6)
{
	TPostfix t("2*3");
	EXPECT_EQ(t.solve(), 6);
}

TEST(TPostfix, can_calc_7)
{
	TPostfix t("2/3");
	EXPECT_EQ(t.solve(), ((double)2) / 3);
}

TEST(TPostfix, can_calc_8)
{
	TPostfix t("2+3/4");
	EXPECT_EQ(t.solve(), 2 + ((double)3) / 4);
}

TEST(TPostfix, can_calc_9)
{
	TPostfix t("2/(3+4)");
	EXPECT_EQ(t.solve(), ((double)2) / (3 + 4));
}

TEST(TPostfix, can_calc_10)
{
	TPostfix t("sin(0)");
	EXPECT_EQ(t.solve(), 0);
}

TEST(TPostfix, can_calc_11)
{
	TPostfix t("cos(0)");
	EXPECT_EQ(t.solve(), 1);
}

TEST(TPostfix, can_calc_12)
{
	TPostfix t("sqrt(2)");
	EXPECT_EQ(t.solve(), sqrt(2));
}

TEST(TPostfix, can_calc_13)
{
	TPostfix t("tg(1+2)");
	EXPECT_EQ(t.solve(), tan(3));
}


TEST(TPostfix, can_calc_14)
{
	TPostfix t("x-z");
	t.setVar("x", 132);
	t.setVar("z", 132);
	EXPECT_EQ(t.solve(), 0);
}

TEST(TPostfix, can_calc_16)
{
	TPostfix t("cos(sin(z/(x-z)))");
	
	double x = 112;
	double z = 1;
	t.setVar("x", x);
	t.setVar("z", z);
	EXPECT_EQ(t.solve(), cos(sin(z / (x - z))));
}