#pragma once
#include "DataUtil.h"
typedef struct Node
{
	Student* info;
	struct Node* next;
}StackNode, *PStackNode;

