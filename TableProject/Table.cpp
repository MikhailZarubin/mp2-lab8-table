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
	TRecord tmp;
	for (Reset(); !IsEnd(); GoNext())
	{
		tmp = this->GetCurr();
		std::cout << '[' << tmp.GetKey() << ']' << tmp.GetVal() << ' ';
	}
}
TArrayTable::TArrayTable(std::size_t s):TTable()
{
	if (s == 0)
		throw 0;
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
	return curr == DataCount;
}
TArrayTable& TArrayTable::operator=(const TArrayTable& t)
{
	DataCount = t.DataCount;
	size = t.size;
	curr = t.curr;
	pRec = std::make_unique<TRecord[]>(size);
	for (Reset();!IsEnd();GoNext())
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
TScamTable::TScamTable(size_t s) :TArrayTable(s)
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
	if (max == 0)
		throw 0;
	if (st == 0 || max % st == 0)
		throw st;
	MaxSize = max;
	Step = st;
	array = std::make_unique<std::pair<TRecord, int>[]>(MaxSize);
	for (std::size_t i = 0; i < MaxSize; i++)
		array[i].second = FREE;
}
THashTableStep::THashTableStep(const THashTableStep& t)
{
	DataCount = t.DataCount;
	MaxSize = t.MaxSize;
	Step = t.Step;
	array = std::make_unique<std::pair<TRecord, int>[]>(MaxSize);
	for (std::size_t i = 0; i < MaxSize; i++)
	{
		if (t.array[i].second != FREE)
			array[i].first = t.array[i].first;
		array[i].second = t.array[i].second;
	}
}
THashTableStep& THashTableStep:: operator =(const THashTableStep& t) {
	MaxSize = t.MaxSize;
	Step = t.Step;
	array = std::make_unique<std::pair<TRecord, int>[]>(MaxSize);
	for (std::size_t i = 0; i < MaxSize; i++)
	{
		if (t.array[i].second != FREE)
			array[i].first = t.array[i].first;
		array[i].second = t.array[i].second;
	}
	return *this;
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
	curr = HashFunc(key);
	int DelPos = -1;
	for (std::size_t i = 0; i < MaxSize; i++)
	{
		Eff++;
		if (array[curr].first.GetKey() == key)
			return true;
		else if (array[curr].second == FREE)
			break;
		else if (array[curr].second == DELETE && DelPos == -1)
			DelPos = curr;
		curr = (curr + Step) % MaxSize;
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
		array[curr].second = 0;
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
std::size_t THashTableStep::HashFunc(const TKey& key)
{
	return (std::size_t)(key % MaxSize);
}
TRecord THashTableStep::GetCurr()
{
	return array[curr].first;
}