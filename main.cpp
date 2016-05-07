#include <iostream>
#include "elewator.h"
#include "kopiec.h"

int main()
{
	int elewatorow;
	int operacji;

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

			max->moveUp(tmp->maxKey);
			min->heapifyDown(tmp);
			min->moveUp(tmp->minKey);
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

			max->heapifyDown(tmp);
			min->moveUp(tmp->minKey);
			min->heapifyDown(tmp);
		}
	}

	return 0;
}