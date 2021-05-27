#pragma once
#include<iostream>

typedef int TKey;
typedef int TVal;

const int OCCUP = 0;
const int FREE = -1;
const int DELETE = -2;

const std::size_t START_SIZE = 10;
class TRecord {
protected:
	TKey Key;
	TVal Val;
public:
	TRecord(TKey k = 0, TVal v = 0);
	void InsRec(TKey k, TVal v);
	void InsRec(TRecord rec);
	TKey GetKey() const;
	TVal GetVal() const;
	bool operator == (const TRecord& rec) const;
	TRecord& operator = (const TRecord& rec);
};
class THashList
{
protected:
	TRecord rec;
public:
	THashList();
	THashList(TRecord r, THashList* p);
	THashList* pNext;
	TRecord GetRec() const;
};

class TTable
{
protected:
	std::size_t DataCount, Eff;
public:
	TTable();
	bool IsEmpty() const;
	virtual bool IsFull() const = 0;
	virtual bool Find(const TKey& k) = 0;
	virtual bool Delete(const TKey& key) = 0;
	virtual bool Insert(const TRecord& rec) = 0;
	virtual void Reset() = 0;
	virtual void GoNext() = 0;
	virtual bool IsEnd() = 0;
    void Print();
	virtual TRecord GetCurr() = 0;
	std::size_t GetEff() const;
	std::size_t GetData() const;
	void ClearEff();
};
class TArrayTable :public TTable {
protected:
	TRecord* pRec;
	std::size_t size, curr;
public:
	TArrayTable(std::size_t s = START_SIZE);
	TArrayTable(const TArrayTable& t);
	~TArrayTable();
	TArrayTable& operator=(const TArrayTable& t);
	void Reset() override;
	void GoNext() override;
	TRecord GetCurr() override;
	bool IsEnd() override;
	bool IsFull()const override;
	std::size_t GetSize() const;
};
class TScamTable :public TArrayTable {
public:
	TScamTable(std::size_t s = START_SIZE);
	TScamTable(const TScamTable& t);
	bool Find(const TKey& key) override;
	bool Insert(const TRecord& rec) override;
	bool Delete(const TKey& key) override;
};

class TSortTable :public TArrayTable {
	void Sort(std::size_t left, std::size_t right);
public:
	TSortTable(std::size_t s = START_SIZE);
	TSortTable(const TArrayTable& t);
	TSortTable& operator=(TArrayTable& t);
	bool Find(const TKey& key) override;
	bool Insert(const TRecord& rec) override;
	bool Delete(const TKey& key) override;
};

class THashTableStep : public TTable
{
protected:
	std::size_t curr, MaxSize;
	int Step;
	std::unique_ptr<std::pair<TRecord, int>[]> array;
	std::size_t HashFunc(const TKey& key);
public:
	THashTableStep(std::size_t max = START_SIZE, int st = 3);
	THashTableStep(const THashTableStep& table);
	~THashTableStep() = default;
	void Reset() override;
	void GoNext() override;
	bool IsEnd() override;
	TRecord GetCurr() override;
	bool IsFull()const override;
	THashTableStep& operator = (const THashTableStep& table);
	bool Find(const TKey& key) override;
	bool Insert(const TRecord& rec) override;
	bool Delete(const TKey& key) override;
};
class THashTableList :public TTable
{
protected:
	std::size_t MaxSize, current_position;
	int found_now;
	THashList* curr, *prev;
	THashList** array;
	std::size_t HashFunc(const TKey& k);
public:
	THashTableList(std::size_t max = START_SIZE);
	THashTableList(const THashTableList& t);
	~THashTableList();
	THashTableList& operator = (const THashTableList& table);
	void Reset() override;
	void GoNext() override;
	bool IsEnd() override;
	TRecord GetCurr() override;
	bool IsFull()const override;
	bool Find(const TKey& key) override;
	bool Insert(const TRecord& rec) override;
	bool Delete(const TKey& key) override;
};
