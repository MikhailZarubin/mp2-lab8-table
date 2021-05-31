#include "Table.h"
//TRecord metods
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
//TTable metods
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
std::size_t TTable::GetEff()const
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
void TTable::SaveFile(std::ofstream& ofs)
{
	TRecord tmp;
	for (Reset(); !IsEnd(); GoNext())
	{
		tmp = this->GetCurr();
		ofs << '\n'<< tmp.GetKey() << ' ' << tmp.GetVal();
	}
}
void TTable::ReadFile(std::ifstream& ifs)
{
	char buff[BUFF_SIZE];
	//ifs.getline(buff, BUFF_SIZE, ' ');
	while (!ifs.eof())
	{
		ifs.getline(buff, BUFF_SIZE, ' ');
		int key = atoi(buff);
		ifs.getline(buff, BUFF_SIZE, '\n');
		int val = atoi(buff);
		TRecord tmp(key, val);
		this->Insert(tmp);
	}
}
//TArrayTable metods
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
std::size_t TArrayTable::GetSize()const {
	return size;
}
//TScamTable metods
TScamTable::TScamTable(size_t s) :TArrayTable(s)
{}
TScamTable::TScamTable(const TScamTable& t):TArrayTable(t)
{}
bool TScamTable::Find(const TKey& key)
{
	bool fl(false);
	curr = DataCount;
	for (int i = 0; i < DataCount; i++)
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
		pRec[curr] = rec;
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
//TSortTable metods
TSortTable::TSortTable(std::size_t s) :TArrayTable(s) {}
TSortTable::TSortTable(const TArrayTable& t):TArrayTable(t)
{
	Sort(0, DataCount-1);
}
void TSortTable::Sort(std::size_t left, std::size_t right)
{
	TRecord leader = pRec[(std::size_t)((left + right) * 0.5)];
	std::size_t l = left, r = right;
	while (l <= r)
	{
		Eff++;
		while (pRec[l].GetKey() < leader.GetKey())
		{
			Eff++;
			l++;
		}
		while (pRec[l].GetKey() > leader.GetKey());
		{
			Eff++;
			r--;
		}
		if (l <= r)
			std::swap(pRec[l++], pRec[r--]);
	}
	if (left < r)
		Sort(left, r);
	else if (right > l)
		Sort(l, right);
}
TSortTable& TSortTable::operator=(TArrayTable& t)
{
	if (&t != this) {
		DataCount = t.GetData();
		size = t.GetSize();
		curr = 0;
		pRec = new TRecord[size];
		for (t.Reset(); !t.IsEnd(); t.GoNext())
		{
			Eff++;
			pRec[curr] = t.GetCurr();
			curr++;
		}
		Sort(0, DataCount - 1);
	}
	return *this;
}
bool TSortTable::Find(const TKey& key)
{
	int left = 0, right = DataCount - 1;
	int pos;
	while (left <= right)
	{
		Eff++;
		pos = (int)((left + right) * 0.5);
		if (pRec[pos].GetKey() == key)
		{
			curr = pos;
			return true;
		}
		else if (pRec[pos].GetKey() > key)
			right = pos - 1;
		else
			left = pos + 1;
	}
	curr = left;
	return false;
}
bool TSortTable::Insert(const TRecord& rec)
{
	if (IsFull())
		throw 0;
	if (!Find(rec.GetKey()))
	{
		for (std::size_t i = DataCount++; i > curr; i--)
		{
			Eff++;
			pRec[i] = pRec[i - 1];
		}
		pRec[curr] = rec;
		return true;
	}
	return false;
}
bool TSortTable::Delete(const TKey& key)
{
	if (IsEmpty())
		throw 0;
	if (Find(key))
	{
		Eff++;
		DataCount--;
		for (std::size_t i = curr; i < DataCount; i++)
		{
			Eff++;
			pRec[i] = pRec[i + 1];
		}
		return true;
	}
	return false;
}
//THashTableStep metods
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
			if (array[curr].second != FREE && array[curr].second != DEL)
				break;
		}
}
void THashTableStep::GoNext()
{
	for (curr = curr+1; curr < MaxSize; curr++)
	{
		Eff++;
		if (array[curr].second != FREE && array[curr].second != DEL)
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
		else if (array[curr].second == DEL && DelPos == -1)
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
		array[curr].first = rec;
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
		array[curr].second = DEL;
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
int THashTableStep::HashFunc(const TKey& key)
{
	return (key % MaxSize);
}
TRecord THashTableStep::GetCurr()
{
	if (curr >= 0 && curr < MaxSize)
		return array[curr].first;
	else
		throw curr;
}
//THashList metods
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
//THashTableList metods
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
		for (current_position = 0; current_position < MaxSize; current_position++)
		{
			Eff++;
			curr = array[current_position];
			if (curr != NULL)
				break;
		}
	}
}
bool THashTableList::IsEnd()
{
	return (found_now >= DataCount);
}
void THashTableList::GoNext()
{
	if (!curr) {
		while (curr == NULL && current_position < MaxSize)
		{
			Eff++;
			curr = array[++current_position];
		}
	}
	else
	{
		curr = curr->pNext;
		if (!curr) {
			while (curr == NULL && current_position < MaxSize)
			{
				Eff++;				
				curr = array[++current_position];
			}
		}
	}
	found_now++;
	Eff++;
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
	if (Eff == 0) Eff = 1;
	return false;
}
bool THashTableList::Insert(const TRecord& rec)
{
	if (IsFull())
		throw 0;
	if (!Find(rec.GetKey()))
	{
		if (prev == NULL)
		{
			std::size_t ind = HashFunc(rec.GetKey());
			array[ind] = new THashList(rec, NULL);
		}
		else
		{
			curr = new THashList(rec, NULL);
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
//TNode metods
TNode::TNode()
{
	rec.InsRec(0, 0);
	pLeft = pRight = NULL;
	height = level = 0;
}
TNode::TNode(TRecord r, TNode* pl, TNode* pr)
{
	rec = r;
	pLeft = pl;
	pRight = pr;
	height = level = 0;
}
TRecord TNode::GetRec() const
{
	return rec;
}
void TNode::InsRec(const TRecord& r)
{
	rec = r;
}
int TNode::GetHeight()const
{
	return height;
}
int TNode::GetLevel()const
{
	return level;
}
void TNode::InsHeight(int h)
{
	height = h;
}
void TNode::InsLevel(int l)
{
	level = l;
}
//TTreeTable metods
TTreeTable::TTreeTable()
{
	pRoot = pCurr = pPrev = NULL;
	found_now = 0;
}
TTreeTable::~TTreeTable()
{
	if (pRoot)
	{
		while (!st.empty())
			st.pop();
		pCurr = pRoot;
		st.push(pCurr);
		while (!st.empty())
		{
			pCurr = st.top();
			st.pop();
			if (pCurr->pLeft)
				st.push(pCurr->pLeft);
			else if (pCurr->pRight)
				st.push(pCurr->pRight);
			delete pCurr;
		}
	}
}
bool TTreeTable::IsFull() const
{
	try {
		TNode* tmp = new TNode;
	}
	catch (std::bad_alloc)
	{
		return true;
	}
	return false;
}
TRecord TTreeTable::GetCurr()
{
	if (pCurr)
	{
		return pCurr->GetRec();
	}
	else
		throw 0;
}
bool TTreeTable::Find(const TKey& key)
{
	pCurr = pRoot;
	pPrev = NULL;
	while (pCurr)
	{
		Eff++;
		if (pCurr->GetRec().GetKey() == key)
			return true;
		else if (pCurr->GetRec().GetKey() < key)
		{
			pPrev = pCurr; 
			pCurr = pCurr->pRight;
		}
		else
		{
			pPrev = pCurr;
			pCurr = pCurr->pLeft;
		}
	}
	pCurr = pPrev;
	return false;
}
bool TTreeTable::Insert(const TRecord& rec)
{
	if (IsFull())
		throw 0;
	if (!Find(rec.GetKey()))
	{
		Eff++;
		DataCount++;
		if (!pRoot)
			pRoot = new TNode(rec);
		else
		{
			TNode* tmp = new TNode(rec);
			if (pCurr->GetRec().GetKey() < rec.GetKey())
				pCurr->pRight = tmp;
			else
				pCurr->pLeft = tmp;
		}
		return true;
	}
	return false;
}
bool TTreeTable::Delete(const TKey& key)
{
	if (IsEmpty())
		throw 0;
	if (Find(key))
	{
		Eff++;
		DataCount--;
		if (!pCurr->pLeft && !pCurr->pRight)
		{
			TNode* tmp = pCurr;
			if (pPrev)
			{
				if (pPrev->pLeft == pCurr)
					pPrev->pLeft = NULL;
				else
					pPrev->pRight = NULL;
			}
			else
				pRoot = NULL;
			delete tmp;
		}
		else if (!pCurr->pLeft && pCurr->pRight)
		{
			TNode* tmp = pCurr;
			if (pPrev)
			{
				if (pPrev->pLeft == pCurr)
					pPrev->pLeft = pCurr->pRight;
				else
					pPrev->pRight = pCurr->pRight;
			}
			else
				pRoot = NULL;
			delete tmp;
		}
		else if (pCurr->pLeft && !pCurr->pRight)
		{
			TNode* tmp = pCurr;
			if (pPrev)
			{
				if (pPrev->pLeft == pCurr)
					pPrev->pLeft = pCurr->pLeft;
				else
					pPrev->pRight = pCurr->pLeft;
			}
			else
				pRoot = NULL;
			delete tmp;
		}
		else
		{
			TNode* tmp = pCurr->pLeft;
			pPrev = pCurr;
			while (tmp->pRight)
			{
				Eff++;
				pPrev = tmp;
				tmp = tmp->pRight;
			}
			pCurr->InsRec(tmp->GetRec());
			if (pPrev != pCurr)
			{
				pPrev->pRight = tmp->pLeft;
			}
			else
				pCurr->pLeft = tmp->pLeft;
			delete tmp;
		}
		return true;
	}
	return false;
}
void TTreeTable::Reset()
{
	while (!st.empty())
		st.pop();
	TNode* tmp=pCurr = pRoot;
	found_now = 0;
	if (pCurr) {
		while (tmp) 
		{
			st.push(tmp);
			pCurr = tmp;
			tmp = tmp->pLeft;
		}
	}
}
void TTreeTable::GoNext()
{
	if (pCurr) {
		TNode* tmp = pCurr = pCurr->pRight;
		if (!st.empty())
			st.pop();
		while (tmp)
		{
			st.push(tmp);
			pCurr = tmp;
			tmp = tmp->pLeft;
		}
		if (!pCurr && !st.empty())
		{
			pCurr = st.top();
			//st.pop();
		}
		found_now++;
	}
}
bool TTreeTable::IsEnd()
{
	return found_now == DataCount;
}
void TTreeTable::PrintTree(std::ofstream& ofs)
{
	if (pRoot != 0)
	{
		std::vector<TNode*> print;
		while (!st.empty())
			st.pop();
		pRoot->InsLevel(4*DataCount);
		st.push(pRoot);
		while (!st.empty())
		{
			pCurr = st.top();
			st.pop();
			print.push_back(pCurr);
			if (pCurr->pLeft)
			{
				pCurr->pLeft->InsLevel(pCurr->GetLevel() - 3);
				pCurr->pLeft->InsHeight(pCurr->GetHeight() + 1);
				st.push(pCurr->pLeft);
			}
			if (pCurr->pRight)
			{
				pCurr->pRight->InsLevel(pCurr->GetLevel() + 3);
				pCurr->pRight->InsHeight(pCurr->GetHeight() + 1);
				st.push(pCurr->pRight);
			}
		}
		for (int i = 0; i < print.size(); i++)
		{
			for (int j = i; j < print.size(); j++)
			{
				if (print[j]->GetHeight() < print[i]->GetHeight())
				{
					TNode* tmp = print[j];
					print[j] = print[i];
					print[i] = tmp;
				}
				else if (print[j]->GetHeight() == print[i]->GetHeight() && print[j]->GetLevel() < print[i]->GetLevel())
				{
					TNode* tmp = print[j];
					print[j] = print[i];
					print[i] = tmp;
				}
				else if (print[j]->GetHeight() == print[i]->GetHeight() && print[j]->GetLevel() == print[i]->GetLevel())
				{
					print[std::max(i, j)]->InsLevel(print[j]->GetLevel() + 1);
				}
			}
		}
		int i = 0;
		while (i < print.size())
		{
			int CurrHeight = print[i]->GetHeight();
			int CurrLevel = 0;
			int add = 0;
			while (i < print.size() && print[i]->GetHeight() == CurrHeight)
			{
				for (int j = CurrLevel+add; j < print[i]->GetLevel()+add; j++)
					ofs << ' ';
				ofs << print[i]->GetRec().GetKey()<<';';
				add += 2;
				for (int j = 10; print[i]->GetRec().GetKey() > j; j++)
					add++;
				CurrLevel = print[i]->GetLevel() + add;
				i++;
			}
			ofs << '\n';
		}
	}
}