#pragma once

class Elewator
{
public:
	int id;
	int masa;
	int maxKey;
	int minKey;

	Elewator(int i, int m) : id(i), masa(m), maxKey(i), minKey(i)
	{
	}

	int masaZero() const
	{
		if (masa == 0) return 2000000001;
		return masa;
	}
};