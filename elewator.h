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
};