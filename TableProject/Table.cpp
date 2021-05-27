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
void TRecord::InsRec(TRecord rec)
{
	Key = rec.Key;
	Val = rec.Val;
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
	if (&rec != this)
	{
		Key = rec.GetKey();
		Val = rec.GetVal();
	}
	return *this;
}
TTable::TTable()
{
	DataCount = 0;
	Eff = 0;
}
bool TTable::IsEmpty()const
{
	return DataCount == 0;
}
int TTable::GetData() const
{
	return DataCount;
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
	pRec = new TRecord[size];
}
TArrayTable::TArrayTable(const TArrayTable& t)
{
	size = t.size;
	curr = t.curr;
	DataCount = t.DataCount;
	pRec = new TRecord[size];
	for (Reset(); !IsEnd(); GoNext())
		pRec[curr] = t.pRec[curr];
}
TArrayTable::~TArrayTable()
{
	delete[] pRec;
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
	if (&t != this) {
		DataCount = t.DataCount;
		size = t.size;
		curr = t.curr;
		pRec = new TRecord[size];
		for (Reset(); !IsEnd(); GoNext())
			pRec[curr] = t.pRec[curr];
	}
	return *this;
}
TRecord TArrayTable::GetCurr()
{
	if (curr < DataCount)
		return pRec[curr];
	else
		throw curr;
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
TSortTable::TSortTable(std::size_t s) :TArrayTable(s) {}
TSortTable::TSortTable(const TArrayTable& t):TArrayTable(t)
{
	Sort(pRec, pRec + DataCount);
}
void TSortTable::Sort(TRecord* start, TRecord* finish)
{
	for (start; start < finish; start++)
	{
		for (TRecord* j = start; j < finish; j++)
		{
			if (j->GetKey() < start->GetKey())
			{
				TRecord tmp(j->GetKey(), j->GetVal());
				j->InsRec(start->GetKey(), start->GetVal());
				start->InsRec(tmp);
			}
		}
	}
}
bool TSortTable::Find(const TKey& key)
{
	return true;
}
bool TSortTable::Delete(const TKey& key)
{
	return true;
}
bool TSortTable::Insert(const TRecord& rec)
{
	return true;
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
	if (&t != this)
	{
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
	return *this;
}
void THashTableStep::Reset()
{
		for (curr = 0; curr < MaxSize; curr++)
		{
			Eff++;
			if (array[curr].second != FREE && array[curr].second != DELETE)
				break;
		}
}
void THashTableStep::GoNext()
{
	for (curr = curr+1; curr < MaxSize; curr++)
	{
		Eff++;
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
		if (array[curr].second == FREE)
			break;
		else if (array[curr].second == DELETE && DelPos == -1)
			DelPos = curr;
		else if (array[curr].first.GetKey() == key && array[curr].second == OCCUP)
			return true;
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
		array[curr].second = OCCUP;
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
	if (curr >= 0 && curr < MaxSize)
		return array[curr].first;
	else
		throw curr;
}
THashList::THashList(): rec()
{
	pNext = NULL;
}
THashList::THashList(TRecord r, THashList* p)
{
	rec = r;
	pNext = p;
}
TRecord THashList::GetRec()const
{
	return rec;
}
THashTableList::THashTableList(std::size_t s)
{
	if (s == 0)
		throw 0;
	MaxSize = s;
	current_position = 0;
	found_now = 0;
	curr = NULL;
	prev = NULL;
	array = new THashList* [MaxSize];
	for (std::size_t i = 0; i < MaxSize; i++)
		array[i] = NULL;
}
THashTableList::THashTableList(const THashTableList& t)
{
	MaxSize = t.MaxSize;
	DataCount = t.DataCount;
	current_position = 0;
	curr = NULL;
	prev = NULL;
	found_now = 0;
	array = new THashList * [MaxSize];
	for (std::size_t i = 0; i < MaxSize; i++)
	{
		Eff++;
		if (t.array[i] == NULL)
			array[i] = NULL;
		else
		{
			THashList* tmp, * p;
			tmp = t.array[i];
			p = new THashList(tmp->GetRec(), NULL);
			array[i] = p;
			curr = array[i];
			tmp = tmp->pNext;
			while (tmp != NULL)
			{
				Eff++;
				p = new THashList(tmp->GetRec(), NULL);
				curr->pNext = p;
				curr = p;
				tmp = tmp->pNext;
			}
		}
	}
}
THashTableList::~THashTableList()
{
	THashList* tmp;
	for (std::size_t i = 0; i < MaxSize; i++)
	{
		Eff++;
		curr = array[i];
		while (curr != NULL)
		{
			Eff++;
			tmp = curr;
			curr = curr->pNext;
			delete tmp;
		}
//		array[i] = NULL;
	}
	delete[] array;
}
THashTableList& THashTableList::operator=(const THashTableList& t)
{
	if (&t != this)
	{
		THashList* tmp;
		for (std::size_t i = 0; i < MaxSize; i++)
		{
			Eff++;
			curr = array[i];
			while (curr != NULL)
			{
				Eff++;
				tmp = curr;
				curr = curr->pNext;
				delete tmp;
			}
		}
		delete[] array;
		DataCount = t.DataCount;
		MaxSize = t.MaxSize;
		curr = NULL;
		array = new THashList * [MaxSize];
		for (std::size_t i = 0; i < MaxSize; i++)
		{
			Eff++;
			if (t.array[i] == NULL)
				array[i] = NULL;
			else
			{
				THashList* tmp, * p;
				tmp = t.array[i];
				p = new THashList(tmp->GetRec(), NULL);
				array[i] = p;
				curr = array[i];
				tmp = tmp->pNext;
				while (tmp != NULL)
				{
					Eff++;
					p = new THashList(tmp->GetRec(), NULL);
					curr->pNext = p;
					curr = p;
					tmp = tmp->pNext;
				}
			}
		}
	}
	return *this;
}
void THashTableList::Reset()
{
	if (DataCount != 0)
	{
		for (std::size_t i = 0; i < MaxSize; i++)
		{
			Eff++;
			curr = array[i];
			if (curr != NULL)
				break;
		}
		found_now++;
	}
}
bool THashTableList::IsEnd()
{
	return (found_now == DataCount);
}
void THashTableList::GoNext()
{
	if (curr == NULL)
		curr=array[++current_position];
	else
		curr = curr->pNext;
	Eff++;
	while (curr == NULL && current_position<MaxSize)
	{
		Eff++;
		curr = array[++current_position];
	}
	if (current_position != MaxSize)
		found_now++;
}
bool THashTableList::IsFull() const
{
	try {
		THashList* tmp = new THashList;
	}
	catch (std::bad_alloc)
	{
		return true;
	}
	return false;
}
TRecord THashTableList::GetCurr() {
	if (!curr)
		throw NULL;
	return curr->GetRec();
}
std::size_t THashTableList::HashFunc(const TKey& key)
{
	return key % MaxSize;
}
bool THashTableList::Find(const TKey& key)
{
	std::size_t ind = HashFunc(key);
	prev = NULL;
	curr = array[ind];
	while (curr != NULL)
	{
		Eff++;
		if (curr->GetRec().GetKey() != key)
		{
			prev = curr; 
			curr = curr->pNext;
		}
		else
			return true;
	}
	return false;
}
bool THashTableList::Insert(const TRecord& rec)
{
	if (IsFull())
		throw 0;
	if (!Find(rec.GetKey()))
	{
		TRecord res = rec;
		if (prev == NULL)
		{
			std::size_t ind = HashFunc(rec.GetKey());
			array[ind] = new THashList(res, NULL);
		}
		else
		{
			curr = new THashList(res, NULL);
			prev->pNext = curr;
		}
		Eff++;
		DataCount++;
		return true;
	}
	return false;
}
bool THashTableList::Delete(const TKey& key)
{
	if (IsEmpty())
		throw 0;
	if (Find(key))
	{
		if (prev)
		{
			prev->pNext = curr->pNext;
		}
		else
		{
			std::size_t ind = HashFunc(key);
			array[ind] = curr->pNext;
		}
		delete curr;
		Eff++;
		DataCount--;
		return true;
	}
	return false;
}
