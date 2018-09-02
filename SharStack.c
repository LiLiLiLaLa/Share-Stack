#include "SharStack.h"

void SharStackInit(ShareStack* pss)
{
	assert(pss);
	pss->_top1 = 0;
	pss->_top2 = 1;
}

void SharStackPush(ShareStack* pss, SSDataType x, int which)
{
	assert(pss && (which == 1 || which == 2));
	if (pss->_top1 < N && pss->_top2 < N)
	{
		if (which == 1)
		{
			pss->_a[pss->_top1] = x;
			pss->_top1 += 2;
		}
		else
		{
			pss->_a[pss->_top2] = x;
			pss->_top2 += 2;
		}
	}
	else
		printf("¿Õ¼ä²»×ã\n");
}

void SharStackPop(ShareStack* pss, int which)
{
	assert(pss && (which == 1 || which == 2));

	if (which == 1 && (pss->_top1 - 2 >= 0))
		pss->_top1 -= 2;
	else if (which == 2 && (pss->_top2 - 2 >= 0))
		pss->_top2 -= 2;
}

int error_flag = 0;
SSDataType SharStackTop(ShareStack* pss, int which)
{
	assert(pss && (which == 1 || which == 2));

	if (which == 1 && pss->_top1 - 2 >= 0)
		return pss->_a[pss->_top1 - 2];
	else if (which == 2 && pss->_top2 - 2 >= 0)
		return pss->_a[pss->_top2 - 2];
	error_flag = -1;
	return error_flag;
}

void TestSharStack()
{
	ShareStack ss;
	SharStackInit(&ss);
	SharStackPush(&ss, 11, 1);
	SharStackPush(&ss, 22, 1);
	SharStackPush(&ss, 33, 2);
	SharStackPush(&ss, 44, 1);
	printf("%d\n", SharStackTop(&ss, 1));
	SharStackPop(&ss, 1);
	printf("%d\n", SharStackTop(&ss, 1));
	SharStackPop(&ss, 1);
	printf("%d\n", SharStackTop(&ss, 2));
	SharStackPop(&ss, 2);
	printf("%d\n", SharStackTop(&ss, 2));
	SharStackPop(&ss, 2);
}