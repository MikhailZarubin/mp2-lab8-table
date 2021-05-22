#pragma once
#include<iostream>

typedef int TKey;
typedef int TVal;

const int FREE = -1;
const int DELETE = -1;
class TRecord {
protected:
	TKey Key;
	TVal Val;
public:
	TRecord(TKey k = 0, TVal v = 0);
	void InsRec(TKey k, TVal v);
	TKey GetKey() const;
	TVal GetVal() const;
	bool operator == (const TRecord& rec) const;
	TRecord& operator = (const TRecord& rec);
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
	virtual TRecord GetCurr() = 0;
    void Print();
	int GetEff() const;
	void ClearEff();
};
class TArrayTable :public TTable {
protected:
	std::unique_ptr<TRecord[]> pRec;
	std::size_t size, curr;
public:
	TArrayTable(int s = 100);
	TArrayTable(const TArrayTable& t);
	~TArrayTable() = default;
	TArrayTable& operator=(const TArrayTable& t);
	void Reset() override;
	void GoNext() override;
	bool IsEnd() override;
	bool IsFull()const override;
	TRecord GetCurr() override;
};
class TScamTable :public TArrayTable {
public:
	TScamTable(int s = 100);
	TScamTable(const TScamTable& t);
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
	THashTableStep(std::size_t max = 100, int st = 3);
	~THashTableStep() = default;
	void Reset() override;
	void GoNext() override;
	bool IsEnd() override;
	bool IsFull()const override;
	TRecord GetCurr() override;
	bool Find(const TKey& key) override;
	bool Insert(const TRecord& rec) override;
	bool Delete(const TKey& key) override;
};