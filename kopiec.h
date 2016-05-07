#pragma once

class Heap
{
	Elewator** tab;
	int length;
	bool firstMax;

	void swap(int a, int b) const;
	bool cmp(int a, int b) const;
public:

	Heap(Elewator** t, int l, bool f = true) : length(l), firstMax(f)
	{
		tab = new Elewator*[l];
		for (int i = 0; i < l; i++)
			tab[i] = t[i];
	}

	void buildHeap() const;
	bool heapify(int i) const;
	void heapifyDown(Elewator* e) const;
	void moveUp(int i) const;
	Elewator* first() const;

	static int parentOf(int i) { return (i - 1) >> 1; }

	static int leftOf(int i) { return (i << 1) + 1; }

	static int rightOf(int i) { return (i << 1) + 2; }
	
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

inline bool Heap::cmp(int a, int b) const
{
	return (firstMax && tab[b]->masa > tab[a]->masa || tab[b]->masa == tab[a]->masa && tab[b]->id < tab[a]->id) || (!firstMax && (tab[b]->masaZero() < tab[a]->masaZero() || (tab[b]->masaZero() == tab[a]->masaZero() && tab[b]->id < tab[a]->id)));
	//return (firstMax && tab[b]->masa > tab[a]->masa || tab[b]->masa == tab[a]->masa && tab[b]->id < tab[a]->id) || (!firstMax && (tab[b]->masa < tab[a]->masa || (tab[b]->masa == tab[a]->masa && tab[b]->id < tab[a]->id) || tab[a]->masa == 0) && tab[b]->masa > 0);
}

inline void Heap::buildHeap() const
{
	for (int i = length / 2; i >= 0; i--)
		heapify(i);
}

inline bool Heap::heapify(int i) const
{
	int largest;
	int l = leftOf(i);
	int r = rightOf(i);

	if (l < length && cmp(i, l))
		largest = l;
	else
		largest = i;

	if (r < length && cmp(largest, r))
		largest = r;

	if(largest != i)
	{
		swap(i, largest);
		heapify(largest);
		return true;
	}
	return false;
}

inline void Heap::heapifyDown(Elewator* e) const
{
	int key;
	do
	{
		key = (firstMax) ? e->maxKey : e->minKey;
	} while (heapify(key));
}

inline void Heap::moveUp(int i) const
{
	if (i < 0 || i > length) return;

	if (!firstMax && tab[i]->masa == 0) {
		return;
	}

	if (i == 0) return;

	int p = parentOf(i);

	if(cmp(p, i))
	{
		swap(i, p);
		moveUp(p);
	}
}

inline Elewator* Heap::first() const
{
	return tab[0];
}
