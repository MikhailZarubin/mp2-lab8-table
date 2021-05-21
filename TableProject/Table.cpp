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
TTable::TTable() :Eff(), DataCount() {

}
bool TTable::IsEmpty()const
{
	return DataCount == 0;
}
int TTable::GetEff()const
{
	return Eff;
}
void TTable::ClearEff()
{
	Eff = 0;
}
void TTable::Print()
{
	TRecord tmp = this->GetCurr();
	for (Reset(); !IsEnd(); GoNext())
		std::cout << '[' << tmp.GetKey() << ']' << tmp.GetVal() << ' ';
}
TArrayTable::TArrayTable(int s):TTable()
{
	size = s;
	curr = 0;
	pRec = std::make_unique<TRecord[]>(size);
}
TArrayTable::TArrayTable(const TArrayTable& t)
{
	size = t.size;
	curr = t.curr;
	pRec = std::make_unique<TRecord[]>(size);
	for (Reset(); !IsEnd(); GoNext())
		pRec[curr] = t.pRec[curr];
}
void TArrayTable::Reset()
{
	curr = 0;
}
void TArrayTable::GoNext()
{
	curr++;
}
bool TArrayTable::IsEnd()
{
	return curr == size;
}
TArrayTable& TArrayTable::operator=(const TArrayTable& t)
{
	size = t.size;
	curr = t.curr;
	pRec = std::make_unique<TRecord[]>(size);
	for (Reset(); !IsEnd(); GoNext())
		pRec[curr] = t.pRec[curr];
	return *this;
}
TRecord TArrayTable::GetCurr()
{
	return pRec[curr];
}