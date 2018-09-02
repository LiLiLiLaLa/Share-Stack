#ifndef __SHARSTACK_H__
#define __SHARSTACK_H__

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

#define N 100
typedef int SSDataType;
typedef struct ShareStack
{
	SSDataType _a[N];
	int _top1;
	int _top2;
}ShareStack;

void SharStackInit(ShareStack* pss);
void SharStackPush(ShareStack* pss, SSDataType x, int which);
void SharStackPop(ShareStack* pss, int which);
SSDataType SharStackTop(ShareStack* pss, int which);

void TestSharStack();

#endif // !__SHARESTACK_H__