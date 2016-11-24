#include <stdio.h>

#define MAX_NUM	100

int FindNum (int *arr1, int *arr2, int size)
{
	int i;
	int num1 = arr1[size], num2 = arr2[size];

	for(i = 0 ; i < size; i++) if(num1 == arr1[i]) if(num2 == arr2[i]) return i;

	return MAX_NUM;
}

int main(int argc, char **argv)
{
	int index = 0;
	int i;

	while(index++ < MAX_NUM)
	{
		int arrMod[MAX_NUM] = {0}, arrQuot[MAX_NUM] = {0};
		int modCnt = 0;
		
		arrQuot[0] = 10 / index;
		arrMod[0] = 10 % index;
		modCnt++;

//		printf("index = %d, quot = %d, mod = %d Start!\n", index, arrQuot[0], arrMod[0]);

		while(modCnt < MAX_NUM)
		{
			int numIndex = MAX_NUM;

			arrQuot[modCnt] = arrMod[modCnt-1]*10 / index;
			arrMod[modCnt] = arrMod[modCnt-1]*10 % index;
			if(arrMod[modCnt] == 0) break;
			
			numIndex = FindNum(arrQuot, arrMod, modCnt);
			if(numIndex == MAX_NUM) modCnt++;
			else
			{
				printf("%d ", index);
				if(arrQuot[numIndex] == 0)
				{
					numIndex++;
					modCnt++;
				}
				for(i = numIndex; i < modCnt; i++) printf("%d", arrQuot[i]);
				printf("\n");
				break;
			}
		}
	}

	return 0;
}
