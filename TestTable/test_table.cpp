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
TEST(ScamTable, can_create_ScamTable)
{
	ASSERT_NO_THROW(TScamTable t);
}
TEST(ScamTable, can_copy_ScamTable)
{
	TScamTable copy;
	ASSERT_NO_THROW(TScamTable t(copy));
}
TEST(ScamTable, can_assign_table)
{
	TScamTable t1(1), t2(2), t3(3);
	ASSERT_NO_THROW(t1 = t2 = t3);
}
TEST(ScamTable, can_insert_record_in_no_full_ScamTable)
{
	TScamTable t;
	TRecord r;
	ASSERT_NO_THROW(t.Insert(r));
}
TEST(ScamTable, can_find_record_in_ScamTable)
{
	TScamTable t;
	TRecord r;
	ASSERT_NO_THROW(t.Find(r.GetKey()));
}
TEST(ScamTable, can_delete_record_in_no_empty_ScamTable)
{
	TScamTable t;
	TRecord r;
	t.Insert(r);
	ASSERT_NO_THROW(t.Delete(r.GetKey()));
}
TEST(ScamTable, can_not_insert_in_full_ScamTable)
{
	TScamTable t(1);
	TRecord r;
	t.Insert(r);
	ASSERT_ANY_THROW(t.Insert(r));
}
TEST(ScamTable, can_not_delete_in_empty_ScamTable)
{
	TScamTable t;
	TRecord r;
	ASSERT_ANY_THROW(t.Delete(r.GetKey()));
}

TEST(ScamTable, find_for_an_existing_record_in_ScamTable_will_return_the_true)
{
	TScamTable t;
	TRecord r;
	t.Insert(r);
	EXPECT_EQ(t.Find(r.GetKey()), true);
}
TEST(ScamTable, find_for_a_nonexistent_record_in_ScamTable_will_return_the_false)
{
	TScamTable t;
	TRecord r;;
	EXPECT_EQ(t.Find(r.GetKey()), false);
}
TEST(ScamTable, insert_a_nonexistent_record_in_ScamTable_will_return_the_true)
{
	TScamTable t;
	TRecord r;
	EXPECT_EQ(t.Insert(r), true);
}
TEST(ScamTable, insert_an_existing_record_in_ScamTable_will_return_the_false)
{
	TScamTable t;
	TRecord r;
	t.Insert(r);
	EXPECT_EQ(t.Insert(r), false);
}
TEST(ScamTable, delete_an_existing_record_in_ScamTable_will_return_the_true)
{
	TScamTable t;
	TRecord r;
	t.Insert(r);
	EXPECT_EQ(t.Delete(r.GetKey()), true);
}
TEST(ScamTable, delete_a_nonexistent_record_in_ScamTable_will_return_the_false)
{
	TScamTable t;
	TRecord r, r1(5, 6);
	t.Insert(r);
	EXPECT_EQ(t.Delete(r1.GetKey()), false);
}
TEST(HashTableStep, can_create_table)
{
	ASSERT_NO_THROW(THashTableStep t);
}
TEST(HashTableStep, can_not_create_table_with_zero_size)
{
	ASSERT_ANY_THROW(THashTableStep t(0));
}
TEST(HashTableStep, can_not_create_table_with_a_multiple_of_the_size_of_the_step)
{
	ASSERT_ANY_THROW(THashTableStep t(100,10));
}
TEST(HashTableStep, can_copy_table)
{
	THashTableStep t;
	ASSERT_NO_THROW(THashTableStep copy(t));
}
TEST(HashTableStep, can_assign_table)
{
	THashTableStep t1, t2;
	ASSERT_NO_THROW(t1 = t2);
}
TEST(HashTableStep, can_insert_record_in_no_full_HashTableStep)
{
	THashTableStep t;
	TRecord r;
	ASSERT_NO_THROW(t.Insert(r));
}
TEST(HashTableStep, can_find_record_in_HashTableStep)
{
	THashTableStep t;
	TRecord r;
	ASSERT_NO_THROW(t.Find(r.GetKey()));
}
TEST(HashTableStep, can_delete_record_in_no_empty_HashTableStep)
{
	THashTableStep t;
	TRecord r;
	t.Insert(r);
	ASSERT_NO_THROW(t.Delete(r.GetKey()));
}
TEST(HashTableStep, can_not_insert_in_full_HashTableStep)
{
	THashTableStep t(1);
	TRecord r;
	t.Insert(r);
	ASSERT_ANY_THROW(t.Insert(r));
}
TEST(HashTableStep, can_not_delete_in_empty_HashTableStep)
{
	THashTableStep t;
	TRecord r;
	ASSERT_ANY_THROW(t.Delete(r.GetKey()));
}

TEST(HashTableStep, find_for_an_existing_record_in_HashTableStep_will_return_the_true)
{
	THashTableStep t;
	TRecord r;
	t.Insert(r);
	EXPECT_EQ(t.Find(r.GetKey()), true);
}
TEST(HashTableStep, find_for_a_nonexistent_record_in_HashTableStep_will_return_the_false)
{
	THashTableStep t;
	TRecord r;;
	EXPECT_EQ(t.Find(r.GetKey()), false);
}
TEST(HashTableStep, insert_a_nonexistent_record_in_HashTableStep_will_return_the_true)
{
	THashTableStep t;
	TRecord r;
	EXPECT_EQ(t.Insert(r), true);
}
TEST(HashTableStep, insert_an_existing_record_in_HashTableStep_will_return_the_false)
{
	THashTableStep t;
	TRecord r;
	t.Insert(r);
	EXPECT_EQ(t.Insert(r), false);
}
TEST(HashTableStep, delete_an_existing_record_in_HashTableStep_will_return_the_true)
{
	THashTableStep t;
	TRecord r;
	t.Insert(r);
	EXPECT_EQ(t.Delete(r.GetKey()), true);
}
TEST(HashTableStep, delete_a_nonexistent_record_in_HashTableStep_will_return_the_false)
{
	THashTableStep t;
	TRecord r, r1(5, 6);
	t.Insert(r);
	EXPECT_EQ(t.Delete(r1.GetKey()), false);
}
TEST(HashTableList, can_create_HashTableList)
{
	ASSERT_NO_THROW(THashTableList t);
}
TEST(HashTableList, can_copy_empty_HashTableList)
{
	THashTableList copy;
	ASSERT_NO_THROW(THashTableList t(copy));
}
TEST(HashTableList, can_copy_no_empty_HashTableList)
{
	THashTableList copy;
	TRecord rec(5, 6);
	copy.Insert(rec);
	ASSERT_NO_THROW(THashTableList t(copy));
}
TEST(HashTableList, can_assign_mpty_HashTableList)
{
	THashTableList copy, t1, t2;
	ASSERT_NO_THROW(t1 = t2 = copy);
}
TEST(HashTableList, can_assign_no_empty_HashTableList)
{
		THashTableList copy, t1, t2;
		TRecord rec(5, 6);
		copy.Insert(rec);
		ASSERT_NO_THROW(t1 = t2 = copy);
}
