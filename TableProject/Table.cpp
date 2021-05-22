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
bool TArrayTable::IsFull() const
{
	return DataCount == size;
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
	if (IsFull())
		throw size;
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
	if (IsEmpty())
		throw 0;
	if (this->Find(key))
	{
		pRec[curr] = pRec[--DataCount];
		Eff++;
		return true;
	}
	return false;
}
THashTableStep::THashTableStep(std::size_t max, int st):TTable()
{
	MaxSize = max;
	Step = st;
	array = std::make_unique<std::pair<TRecord, int>[]>(MaxSize);
}
void THashTableStep::Reset()
{
	for (curr = 0; curr < MaxSize; curr++)
	{
		if (array[curr].second != FREE && array[curr].second != DELETE)
			break;
	}
}
void THashTableStep::GoNext()
{
	for (curr = curr+1; curr < MaxSize; curr++)
	{
		if (array[curr].second != FREE && array[curr].second != DELETE)
			break;
	}
}
bool THashTableStep::IsEnd()
{
	return curr == MaxSize;
}
bool THashTableStep::Find(const TKey& key)
{
	std::size_t pos = HashFunc(key);
	int DelPos = -1;
	for (int i = 0; i < MaxSize; i++)
	{
		Eff++;
		if (array[i].first.GetKey() == key)
			return true;
		else if (array[i].second == FREE)
			break;
		else if (array[i].second == DELETE && DelPos == -1)
			DelPos = curr;
		curr += Step;
	}
	if (DelPos != -1)
		curr = DelPos;
	return false;
}
bool THashTableStep::Insert(const TRecord& rec)
{
	if (IsFull())
		throw MaxSize;
	if (!Find(rec.GetKey()))
	{
		TRecord tmp;
		array[curr].first = tmp;
		DataCount++;
		Eff++;
		return true;
	}
	return false;
}
bool THashTableStep::Delete(const TKey& key)
{
	if (IsEmpty())
		throw 0;
	if (Find(key))
	{
		array[curr].second = DELETE;
		DataCount--;
		Eff++;
		return true;
	}
	return false;
}
bool THashTableStep::IsFull() const
{
	return DataCount == MaxSize;
}