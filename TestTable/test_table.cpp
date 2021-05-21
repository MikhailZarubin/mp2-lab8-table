#include "gtest.h"
#include "../TableProject/Table.cpp"

TEST(Record, can_create_a_record)
{
	ASSERT_NO_THROW(TRecord r);
}
TEST(Record, the_default_constructor_initializes_the_values)
{
	TRecord r;
	EXPECT_EQ(r.GetKey() + r.GetVal(), 0);
}
TEST(Record, the_initialization_constructor_initializes_the_values)
{
	TRecord r(2, 3);
	EXPECT_EQ(r.GetKey() + r.GetVal(), 5);
}
