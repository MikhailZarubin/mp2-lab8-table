#pragma once
#include<iostream>

typedef int TKey;
typedef int TVal;
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
	int DataCount, Eff;
public:
	TTable();
	bool IsEmpty() const;
	virtual bool Find(TKey k) = 0;
	virtual bool IsFull() const = 0;
	virtual bool Delete(TKey key) = 0;
	virtual bool Insert(const TRecord& rec) = 0;
	virtual void Reset() = 0;
	virtual void GoNext() = 0;
	virtual bool IsEnd() = 0;
	virtual TRecord GetCurr() = 0;
    void Print();
	int GetEff() const;
	void ClearEff();
};

