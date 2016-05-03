#include <iostream>
#include "elewator.h"
#include "kopiec.h"

int elewatorow;
int operacji;
/*
struct Elewator
{
	int id;
	int masa;
};

void swap(Elewator** tab, int n1, int n2)
{
	Elewator* tmp = tab[n1];
	tab[n1] = tab[n2];
	tab[n2] = tmp;
}

void comb_sort(Elewator** tab, int size) {
	int gap = size;
	bool swapped = false;
	while ((gap > 1) || swapped) {
		if (gap > 1) gap = int(gap / 1.247330950103979);
		swapped = false;
		for (int i = 0; gap + i < size; i++)
			if (tab[i + gap]->masa < tab[i]->masa) {
				swap(tab, i + gap, i);
				swapped = true;
			}
	}
}

Elewator* GetNajmniejszy(Elewator** tab)
{
	if (elewatorow == 0) return nullptr;

	Elewator* najmniejszy = tab[0];
	for (int i = 1; i < elewatorow; i++)
	{
		if (najmniejszy->masa > 0 && tab[i]->masa > najmniejszy->masa)
			break;
		if (najmniejszy->masa == 0 || (tab[i]->masa < najmniejszy->masa) || (tab[i]->masa == najmniejszy->masa && tab[i]->id < najmniejszy->id))
			najmniejszy = tab[i];
	}

	return najmniejszy;
}

Elewator* GetNajwiekszy(Elewator** tab)
{
	if (elewatorow == 0) return nullptr;

	Elewator* najwiekszy = tab[elewatorow - 1];
	for (int i = elewatorow - 1; i >= 0; --i)
	{
		if (tab[i]->masa < najwiekszy->masa)
			break;
		if ((tab[i]->masa > najwiekszy->masa) || (tab[i]->masa == najwiekszy->masa && tab[i]->id < najwiekszy->id))
			najwiekszy = tab[i];
	}

	return najwiekszy;
}

void sortOptimized(Elewator** tab, Elewator* elew, bool dodano = false)
{
	int offset = 0;
	int ile = 0;

	if(dodano)
	{
		// 1 2 3 8 5 6 7 8 9
		// 1 2 3 5 6 7 8 8 9
		// offset = 3
		// ile = 4
		for (; offset < elewatorow; offset++)
			if (tab[offset]->id == elew->id)
				break;

		for (int i = offset; i < elewatorow; i++, ++ile)
			if (tab[i]->masa >= elew->masa && tab[i]->id != elew->id)
				break;

		comb_sort(tab + offset, ile);
	} else
	{
		// 1 2 3 4 5 6 7 3 9
		// 1 2 3 3 4 5 6 7 9
		// offset = 1
		// ile = 5
		for (; offset < elewatorow; offset++)
			if (tab[elewatorow - offset - 1]->id == elew->id)
				break;

		for (int i = elewatorow - offset - 1; i > 0; i--, ++ile)
			if (tab[i]->masa <= elew->masa && tab[i]->id != elew->id)
				break;

		comb_sort(tab + (elewatorow - offset - ile), ile);
	}
}*/

int main()
{
	scanf("%d", &elewatorow);
	scanf("%d", &operacji);

	Elewator** elewatory = new Elewator*[elewatorow];

	char cmd[3];
	int tmpId = -1;
	int tmpMasa = 0;
	Elewator* tmp;
	char buf[11];

	for (int i = 0; i < elewatorow; i++) {
		scanf("%d", &tmpMasa);
		elewatory[i] = new Elewator(i, tmpMasa);
	}

	Heap* max = new Heap(elewatory, elewatorow);
	max->buildHeap();

	Heap* min = new Heap(elewatory, elewatorow, false);
	min->buildHeap();

	for (int i = 0; i < operacji; i++)
	{
		scanf("%s", cmd);
		if(cmd[0] == 'n')
		{
			if(cmd[1] == 'm')
			{
				tmp = min->first();
			}
			else if (cmd[1] == 'M') {
				tmp = max->first();
			}
			else
			{
				scanf("%d", &tmpId);
				tmp = elewatory[tmpId];
			}
			scanf("%d", &tmpMasa);

			tmp->masa += tmpMasa;
			max->heapify(tmp->maxKey);
			min->heapify(tmp->minKey);
		}
		else if(cmd[0] == 'w')
		{
			if (cmd[1] == 'm')
			{
				tmp = min->first();
			}
			else if (cmd[1] == 'M') {
				tmp = max->first();
			}
			else
			{
				scanf("%d", &tmpId);
				tmp = elewatory[tmpId];
			}

			itoa(tmp->masa, buf, 10);
			fputs(buf, stdout);
			putc('\n', stdout);
		}
		else if (cmd[0] == 'r')
		{
			if (cmd[1] == 'm')
			{
				tmp = min->first();
			}
			else if (cmd[1] == 'M') {
				tmp = max->first();
			}
			else
			{
				scanf("%d", &tmpId);
				tmp = elewatory[tmpId];
			}
			scanf("%d", &tmpMasa);

			tmp->masa -= tmpMasa;
			if (tmp->masa < 0)
				tmp->masa = 0;

			max->heapify(tmp->maxKey);
			min->heapify(tmp->minKey);
		}
	}

	return 0;
}