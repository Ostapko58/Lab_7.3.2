#include <iostream>
#include <iomanip>

using namespace std;
void Input(int** a, const int rowCount, const int colCount);
void Print(int** a, const int rowCount, const int colCount);
void Find(int** a, const int rowCount, const int colCount,int & min);
void Switch(int** a, int** y, const int rowCount);
int main()
{
	int rowCount, colCount;
	cout << "rowCount = "; cin >> rowCount;
	cout << "colCount = "; cin >> colCount;
	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
	Input(a, rowCount, colCount);
	Print(a, rowCount, colCount);
	int min = a[0][0];
	Find(a, rowCount, colCount,min);
	cout << min << endl;
	
	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}

void Input(int** a, const int rowCount, const int colCount)
{

		for (int i = 0; i < rowCount; i++)
		{
			for (int j = 0; j < colCount; j++)
			{
				cout << "a[" << i << "][" << j << "] = ";
				cin >> a[i][j];
			}
			cout << endl;
		}
}
void Print(int** a, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}

void Find(int** a,  int rowCount, const int colCount,int & min)
{
	int s1,s2,k=rowCount;
	int** y = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		y[i] = new int[colCount];
	Switch(a, y, rowCount);
	for (int n = rowCount; n > 1; n--)
	{
		s1 = 0;
		s2 = 0;
		for (int i = 0; i < k - 1; i++)
		{
			s1 += abs(a[i][k - i - 2]);
			s2 += abs(y[i][k - i - 2]);
		}
		if (s1<min)
			min = s1;
		if (s2 < min)
			min = s2;
		k--;
	}
	
	for (int i = 0; i < rowCount; i++)
		delete[] y[i];
	delete[] y;
}

void Switch(int** a,int **y, const int rowCount)
{
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < rowCount - i; j++)
		{
			y[i][j] = a[rowCount - j - 1][rowCount - i - 1];
		}
	}
}
