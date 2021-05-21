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

};

