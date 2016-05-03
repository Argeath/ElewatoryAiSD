#pragma once

class Heap
{
	Elewator** tab;
	int length;
	bool firstMax;

	static int parentOf(int i) { return (i - 1) >> 1; }

	static int leftOf(int i) { return (i << 1) + 1; }

	static int rightOf(int i) { return (i << 1) + 2; }

	void swap(int a, int b) const;

public:
	Heap(Elewator** t, int l, bool f = true) : tab(t), length(l), firstMax(f) {}

	void buildHeap() const;
	void heapify(int i) const;
	Elewator* first() const;
	
};

inline void Heap::swap(int a, int b) const
{
	Elewator* tmp = tab[a];
	tab[a] = tab[b];
	tab[b] = tmp;

	if (firstMax) {
		int tmpKey = tab[a]->maxKey;
		tab[a]->maxKey = tab[b]->maxKey;
		tab[b]->maxKey = tmpKey;
	} else {
		int tmpKey = tab[a]->minKey;
		tab[a]->minKey = tab[b]->minKey;
		tab[b]->minKey = tmpKey;
	}
}

inline void Heap::buildHeap() const
{
	for (int i = length / 2; i > 0; i--)
		heapify(i);
}

inline void Heap::heapify(int i) const
{
	int largest;
	int l = leftOf(i);
	int r = rightOf(i);

	if (l < length && (firstMax && tab[l]->masa > tab[i]->masa || !firstMax && tab[l]->masa < tab[i]->masa && tab[l]->masa > 0))
		largest = l;
	else
		largest = i;

	if (r < length && (firstMax && tab[r]->masa > tab[largest]->masa || !firstMax && tab[r]->masa < tab[largest]->masa && tab[l]->masa > 0))
		largest = r;
	else
		largest = i;

	if(largest != i)
	{
		swap(i, largest);
		heapify(largest);
	}
}

inline Elewator* Heap::first() const
{
	return tab[0];
}
