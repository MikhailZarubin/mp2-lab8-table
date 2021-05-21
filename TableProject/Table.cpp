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
TScamTable::TScamTable(int s) :TArrayTable(s)
{}
TScamTable::TScamTable(const TScamTable& t):TArrayTable(t)
{}
bool TScamTable::Find(const TKey& key)
{
	bool fl(false);
	curr = DataCount;
	for (std::size_t i = 0; i < DataCount; i++)
	{
		Eff++;
		if (pRec[i].GetKey() == key)
		{
			fl = true;
			curr = i;
			break;
		}
	}
	return fl;
}
bool TScamTable::Insert(const TRecord& rec)
{
	if (!this->Find(rec.GetKey()))
	{
		TRecord tmp(rec.GetKey(), rec.GetVal());
		pRec[curr] = tmp;
		DataCount++;
		Eff++;
		return true;
	}
	return false;
}
bool TScamTable::Delete(const TKey& key)
{
	if (this->Find(key))
	{
		pRec[curr] = pRec[--DataCount];
		Eff++;
		return true;
	}
	return false;
}