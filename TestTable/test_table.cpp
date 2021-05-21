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
TEST(Record, can_get_a_key)
{
	TRecord r(5, 6);
	ASSERT_NO_THROW(r.GetKey());
	EXPECT_EQ(r.GetKey(), 5);
}
TEST(Record, can_get_a_val)
{
	TRecord r(5, 6);
	ASSERT_NO_THROW(r.GetVal());
	EXPECT_EQ(r.GetVal(), 6);
}
TEST(Record, can_insert_a_record)
{
	TRecord r;
	ASSERT_NO_THROW(r.InsRec(5,6));
	EXPECT_EQ(r.GetKey(), 5);
	EXPECT_EQ(r.GetVal(), 6);
}
TEST(Record, can_compare_a_record)
{
	TRecord r1,r2;
	ASSERT_NO_THROW(r1==r2);
}
TEST(Record, comparing_identical_records_is_true)
{
	TRecord r1, r2;
	EXPECT_EQ(r1 == r2, true);
}
TEST(Record, comparing_no_identical_records_is_true)
{
	TRecord r1, r2(5, 6);
	EXPECT_EQ(r1 == r2, false);
}
TEST(Record, can_assign_records)
{
	TRecord r1, r2, r3;
	ASSERT_NO_THROW(r1 = r2 = r3);
}
TEST(Record, the_records_after_the_assignment_are_the_same)
{
	TRecord r1, r2(5, 6);
	r1 = r2;
	EXPECT_EQ(r1 == r2, true);
}
