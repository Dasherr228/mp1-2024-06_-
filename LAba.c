#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <windows.h>

int n, is_sort=0;
int ex = 0;
int GlobArray[10000] = { 0 };
int GlobSort[10000] = { 0 };
double Time[5] = { 0.0 };
int SwapArray[5] = {0};

int MaxArray(int A[])
{
	int max, i,min;
	max = A[0];
	min = A[0];
	for (i = 0; i < n; i++)
	{
		if (max < A[i])
		{
			max = A[i];
		}
		if (min > A[i])
		{
			min = A[i];
		}
	}
	if (max < (-1) * min)
	{
		max = (-1) * min;
	}
	return(max);
}

void ArrayOutput(int A[])
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d\t", A[i]);
	}
	printf("\n__________________________________________________________________\n");
}

void SortTimeOutput(double A[5])
{
	int i;
	for (i = 0; i < 5; i++)
	{	
		switch (i) 
		{
		case 0:
			printf("���������� '���������'\t");
			break;
		case 1:
			printf("���������� ���������\t");
			break;
		case 2:
			printf("���������� �������\t");
			break;
		case 3:
			printf("���������� ���������\t");
			break;
		case 4:printf("������� ����������\t");
			break;
		}
		
		printf("%.7f���\t", A[i]);
		printf("%d ������\n", SwapArray[i]);
	}
	printf("____________________________________________________________________\n");
}

void ArrayInput(int A[])
{
	int i;
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &A[i]);
	}
}

void RandArrayInput(int A[])
{
	srand(time(NULL));
	int i, randtemp, low, up;
	printf("������� ������ ������� ��������� �������:\n");
	scanf_s("%d", &low);
	printf("������� ������� ������� ��������� �������:\n");
	scanf_s("%d", &up);
	for (i = 0; i < n; i++)
	{
		randtemp = low + rand() % (up - low);
		A[i] = randtemp;
	}
}

void ArraySortTest(int A[])
{
	int i;
	for (i = 0; i < n-1; i++)
	{
		if (A[i] > A[i+1])
		{
			is_sort = 0;
			break;
		}
		is_sort = 1;
	}
}

void ArraySettings()
{
	int rightsize=0, arrent, q, stuptest=0, rightarr = 1, rightop=0, stuptest2=0, w, GlobSort[10000] = { 0 };
	for (q = 0; q < 5; q++)
	{
		Time[q] = 0.0;
	}
	for (q = 0; q < 5; q++)
	{
		SwapArray[q] = 0;
	}
	while (!rightop)
	{
		is_sort = 0;
		printf("�������� �������� � ��������:\n");
		printf("1 - ������/�������� ������ ������� � ����������� ��� ��������.\n");
		printf("2 - ������ ����� ������ �������� �������.\n");
		scanf_s("%d", &q);
		switch (q)
		{
		case 1:
			while (!rightsize)
			{
				rightsize = 1;
				printf("������� ������ �������: \t");
				scanf_s("%d", &n);
				if (n <= 0)
				{
					printf("������ ������� �� ����� ���� �������������!!\n");
					rightsize = 0;
				}
				else
				{
					int* GlobArray = malloc(n * sizeof(int));
				}
			}
		case 2:
			rightop = 1;
			while (!(rightarr - 1))
			{
				while (!stuptest)
				{
					stuptest = 1;
					printf("�������� ������ ������� �������: \n");
					printf("1 - ������ ����\n");
					printf("2 - ��������� ������\n");
					scanf_s("%d", &arrent);
					switch (arrent)
					{
					case 1:
						ArrayInput(GlobArray);
						break;
					case 2:
						RandArrayInput(GlobArray);
						break;
					default:
						stuptest = 0;
						printf("������� ������� �� ����������!\n");
						break;
					}
				}
				printf("��� �������� ������: \n");
				ArrayOutput(GlobArray);
				ArraySortTest(GlobArray);
				if (is_sort)
				{
					for (w = 0; w < n; w++)
					{
						GlobSort[w] = GlobArray[w];
					}
				}
				while(!stuptest2)
				{
					stuptest2 = 1;
					printf("������ �����?\n");
					printf("1 - ��\n");
					printf("2 - ���\n");
					scanf_s("%d", &rightarr);
					switch (rightarr)
					{
					case 1:
						rightarr = 2;
						break;
					case 2:
						rightarr = 1;
						stuptest = 0;
						break;
					default:
						printf("������� ������� �� ����������!\n");
						stuptest2 = 0;
						break;
					}
				}
				stuptest2 = 0;
			}
			break;
		default:
			printf("������� ������� �� ����������!\n");
			break;
		}
	}
	main();
}

void LineSearch(int A[])
{
	int searcher, finder = 0, i, compares=0;
	printf("������� ����� ��� ������\n");
	scanf_s("%d", &searcher);
	for (i = 0; i < n; i++)
	{
		if (A[i] == searcher)
		{
			printf("������ ����� �����: %d\n", i);
			finder = 1;
			break;
		}
		compares++;
	}
	if (!finder)
	{
		printf("����� ��� � �������.\n");
	}
	printf("���� ������� %d ���������.\n", compares);
}

void BinSearch(int A[])
{
	int left = 0, right = n, searcher, finder=0, mid, compares=0;
	printf("������� ����� ��� ������\n");
	scanf_s("%d", &searcher);
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (A[mid] == searcher)
		{
			printf("������ ����� �����: %d\n", mid);
			finder = 1;
			compares++;
			break;
		}
		else if (A[mid] < searcher)
		{
			compares+=2;
			left = mid + 1;
		}

		else
		{
			compares+=2;
			right = mid - 1;
		}
	}
	if (!finder)
	{
		printf("����� ��� � �������.\n");
	}
	printf("���� ������� %d ���������.\n", compares);
	main();
}

void LineSearchMenu()
{
	int i, sorted, stuptest = 0, finder = 0;
	int A[10000] = { 0 };
	while (!stuptest)
	{
		stuptest = 1;
		printf("� ����� ������� �����?\n");
		printf("1 - ���������������\n");
		printf("2 - �����������\n");
		scanf_s("%d", &sorted);
		switch (sorted)
		{
		case 1:
			if (is_sort)
			{
				for (i = 0; i < n; i++)
				{
					A[i] = GlobSort[i];
				}
			}
			else
			{
				stuptest = 0;
				printf("��� ���������������� �������\n");
			}
			break;
		case 2:
			for (i = 0; i < n; i++)
			{
				A[i] = GlobArray[i];
			}
			break;
		default:
			stuptest = 0;
			printf("�������� ������� �� ����������\n");
			break;
		}
	}
	LineSearch(A);
	main();
}

void SearchMenu()
{
	int searchtemp, stuptest=0;
	while (!stuptest)
	{
		stuptest = 1;
		printf("�������� �����:\n");
		printf("1 - �������� �����.\n");
		printf("2 - �������� �����.    ��������! �������� ����� ������ ��� ��������������� ��������\n");
		scanf_s("%d", &searchtemp);
		switch (searchtemp)
		{
		case 1:
			LineSearchMenu();
			break;
		case 2:
			if (is_sort)
			{
				BinSearch(GlobSort);
			}
			else
			{
				printf("��� ���������������� �������!\n");
			}
			break;
		default:
			stuptest = 0;
			printf("������� ������� �� ����������!\n");
			break;
		}
	}
	main();
}

void Swap(int i, int j, int A[])
{
	int temp;
	temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

void BubbleSort(int A[])
{
	int left = 0, right = n - 1, i;
	while (left <= right)
	{
		for (i = right; i > left; i--)
		{
			if (A[i - 1] > A[i])
			{
				Swap(i, i-1, A);
				SwapArray[0]++;
			}
		}
		++left;
		for (i = left; i < right; i++)
		{
			if (A[i] > A[i + 1])
			{
				Swap(i, i + 1, A);
				SwapArray[0]++;
			}
		}
		--right;
	}
}

void InsertSort(int A[])
{
	int pos, val, k;
	for (pos = 0; pos < n - 1; pos++)
	{
		val = A[pos + 1];
		k = pos;
		while ((k >= 0) && (A[k] > val))
		{
			A[k + 1] = A[k];
			SwapArray[1]++;
			k--;
		}
		A[k + 1] = val;
		SwapArray[1]++;
	}
}

void ChoiseSort(int A[])
{
	int i, pos, j;
	for (i = 0; i < n; i++)
	{
		pos = i;
		for (j = i + 1; j < n; j++)
		{
			if (A[pos] > A[j])
			{
				pos = j;
			}
		}
		Swap(pos, i, A);
		SwapArray[2]++;
	}
}
void CountSort(int A[])
{
	int max, i, q, j, pos=0;
	max = MaxArray(GlobArray);
	if (max < 0)
	{
		max = (-1) * max;
	}
	int max2 = max * 2;
	int* B = malloc(max2 * sizeof(int));
	for (q = 0; q < max2; q++)
	{
		B[q] = 0;
	}
	for (i = 0; i < n; i++)
	{
		B[A[i]+max]+=1;
	}
	for (i = 0; i < max2; i++)
	{
		if (B[i] > 0)
		{
			for (j = 0; j < B[i]; j++)
			{
				A[pos] = i-max;
				SwapArray[3]++;
				pos++;
			}
		}
	}
}

void QSort(int* A, int end)
{
	int i = 0, j = end-1, mid;
	mid = A[end/2];
	do
	{
		while (A[i] < mid)
		{
			i++;
		}
		while (A[j] > mid)
		{
			j--;
		}
		if (i <= j)
		{
			Swap(i, j, A);
			SwapArray[4]++;
			i++;
			j--;
		}
	} while (i <= j);
	if (j > 0)
	{
		QSort(A, j + 1);
	}
	if (i < end)
	{
		QSort(&A[i], end - i);
	}
}

void SortMenu()
{
	LARGE_INTEGER freq, start, finish;
	double time;
	int i, stuptest = 0, sorttemp, w;
	int* A = malloc(n * sizeof(int));
	QueryPerformanceFrequency(&freq);
	for (i = 0; i < n; i++)
	{
		A[i] = GlobArray[i];
	}
	while (!stuptest)
	{
		stuptest = 1;
		printf("�������� ����������:\n");
		printf("1 - ���������� '���������'\n");
		printf("2 - ���������� ���������\n");
		printf("3 - ���������� �������\n");
		printf("4 - ���������� ���������\n");
		printf("5 - ������� ����������\n");
		scanf_s("%d", &sorttemp);
		switch(sorttemp)
		{
		case 1:
			QueryPerformanceCounter(&start);
			BubbleSort(A);
			QueryPerformanceCounter(&finish);
			time = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
			Time[0] = time;
			ArraySortTest(A);
			if (is_sort)
			{
				for (w = 0; w < n; w++)
				{
					GlobSort[w] = A[w];
				}
			}
			ArrayOutput(GlobSort);
			break;
		case 2:
			QueryPerformanceCounter(&start);
			InsertSort(A);
			QueryPerformanceCounter(&finish);
			time = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
			Time[1] = time;
			ArraySortTest(A);
			if (is_sort)
			{
				for (w = 0; w < n; w++)
				{
					GlobSort[w] = A[w];
				}
			}
			ArrayOutput(GlobSort);
			break;
		case 3:
			QueryPerformanceCounter(&start);
			ChoiseSort(A);
			QueryPerformanceCounter(&finish);
			time = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
			Time[2] = time;
			ArraySortTest(A);
			if (is_sort)
			{
				for (w = 0; w < n; w++)
				{
					GlobSort[w] = A[w];
				}
			}
			ArrayOutput(GlobSort);
			break;
		case 4:
			QueryPerformanceCounter(&start);
			CountSort(A);
			QueryPerformanceCounter(&finish);
			time = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
			Time[3] = time;
			ArraySortTest(A);
			if (is_sort)
			{
				for (w = 0; w < n; w++)
				{
					GlobSort[w] = A[w];
				}
			}
			ArrayOutput(GlobSort);
			break;
		case 5:
			QueryPerformanceCounter(&start);
			QSort(A, n);
			QueryPerformanceCounter(&finish);
			time = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
			Time[4] = time;
			ArraySortTest(A);
			if (is_sort)
			{
				for (w = 0; w < n; w++)
				{
					GlobSort[w] = A[w];
				}
			}
			ArrayOutput(GlobSort);
			break;
		default:
			printf("������� ������� �� ����������!\n");
			stuptest = 0;
			break;
		}
	}
	main();
}

int main()
{
	int mainmenu, stuptest=0;
	setlocale(LC_ALL, "Rus");
	while ((!stuptest)&&(!ex))
	{
		stuptest = 1;
		printf("������� ����:\n");
		printf("0 - �����\n");
		printf("1 - ��������� �������.\n");
		printf("2 - ���� ������.\n");
		printf("3 - ���� ����������.\n");

		scanf_s("%d", &mainmenu);
		switch (mainmenu)
		{
		case 0:
			ex = 1;
			SortTimeOutput(Time);
			printf("�������� ���!!!\n");
			break;
		case 1:
			ArraySettings();
			break;
		case 2:
			SearchMenu();
			break;
		case 3:
			SortMenu();
			break;
		default:
			printf("������� ������� �� ����������!\n");
			stuptest = 0;
			break;
		}
	}
	return 0;
}