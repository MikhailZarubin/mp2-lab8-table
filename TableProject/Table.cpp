#include "Table.h"

TRecord::TRecord(TKey k, TVal v)
{
	Key = k;
	Val = v;
}
void TRecord::InsRec(TKey k, TVal v)
{
	Key = k;
	Val = v;
}
TKey TRecord::GetKey()const
{
	return Key;
}
TVal TRecord::GetVal()const
{
	return Val;
}
bool TRecord:: operator == (const TRecord& rec) const
{
	return (Key == rec.GetKey() && Val == rec.GetVal());
}
TRecord& TRecord::operator =(const TRecord& rec)
{
	Key = rec.GetKey();
	Val = rec.GetVal();
	return *this;
}