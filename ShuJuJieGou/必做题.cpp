#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<iomanip>
#include <stdlib.h>
#include <malloc.h>
#define num 10000
using namespace std;
int fn, en;
struct Record
{
	int key;
};
Record r[10002]; Record i_arry[10002], rs[10002], r3[10002]; Record r2[10002]; Record r1[10002];
void cc(Record r[],string s)
{
	ofstream fout("result.txt", ios_base::out | ios::app);
	if (!fout)
	{
		cout << "Can't Open file:result.txt" << endl;
		exit(0);
	}
	if (s == "ShellSort" || s=="QuickSort")
	{
		cout << endl << s << endl;
		for (int i = 0; i < num; i++)
			cout << r[i].key << " ";
		fout << endl << s << endl;
		for (int i = 0; i < num; i++)
			fout << r[i].key << " ";
	}
	else
	{
		cout << endl << s << endl;
		for (int i = 1; i <= num; i++)
			cout << r[i].key << " ";
		fout << endl << s << endl;
		for (int i = 1; i <= num; i++)
			fout << r[i].key << " ";
	}
}
void ShellSort(Record r[], int n)
{
	for (int d = n / 2; d >= 1; d = d / 2)
	{
		for(int i=d;i<n;i++)
		{ 
			Record temp = r[i];
			int j;
			for (j = i - d; j >= 0 && temp.key < r[j].key; j = j - d)
				r[j + d] = r[j];
			r[j + d] = temp;
		}
	}
	cc(r,"ShellSort");
}

int Partition(Record r[], int i, int j)
{
	Record temp = r[i];
	while (i < j)
	{
		while (i < j && r[j].key >= temp.key)
			j--;
		if (i < j)
			r[i++] = r[j];
		while (i < j && r[i].key <= temp.key)
			i++;
		if (i < j)
			r[j--] = r[i];
	}
	r[i] = temp;
	return i;
}
void QuickSort(Record r[], int i, int j)
{
	if (i < j)
	{
		int pivot = Partition(r, i, j);
		QuickSort(r,i,pivot - 1);
		QuickSort(r, pivot + 1, j);
	}
}

void Sift(Record r[], int k, int m)
{
	int i = k;
	int j = 2 * i;
	while (j <= m)
	{
		if (j < m && r[j].key < r[j + 1].key)
			j++;
		if (r[i].key > r[j].key)
			break;
		else 
		{
			Record temp = r[i];
			r[i]=r[j];
			r[j] = temp;
			i = j;
			j = 2 * i;
		}
	}
}
void HeapSort(Record r[], int n)
{
	for (int i = n / 2; i >= 1; i--)
		Sift(r, i, n);
	for (int i = 1; i < n; i++)
	{
		Record temp = r[1];
		r[1] = r[n-i+1];
		r[n-i+1] = temp;
		Sift(r, 1, n - i);
	}
	cc(r, "HeapSort");
}

void Merge(Record r[], Record r1[], int s, int m, int t)
{
	int i = s;
	int j = m + 1;
	int k = s;
	while (i <= m && j <= t)
		if (r[i].key <= r[j].key)
			r1[k++] = r[i++];
		else
			r1[k++] = r[j++];
	if (i <= m)
		while (i <= m)
			r1[k++] = r[i++];
	else
		while (j <= t)
			r1[k++] = r[j++];
}
void MergePass(Record r[], Record r1[], int n, int h)
{
	int i = 1;
	while (i <= n - 2*h + 1)
	{
		Merge(r, r1, i, i + h - 1, i + 2 * h - 1);
		i += 2 * h;
	}
	if (i < n - h + 1)
		Merge(r, r1, i, i + h - 1, n);
	else
		for (int k = i; k <= n; k++)
			r1[k] = r[k];
}
void MergeSort1(Record r[], int n)
{
	int h = 1;
	while (h < n)
	{
		MergePass(r, r1, n, h);
		h = 2 * h;
		MergePass(r1, r, n, h);
		h = 2 * h;
	}
	cc(r, "MergeSort1");
}
void MergeSort2(Record r[], Record r1[], int s, int t)
{
	if (s == t)
		r1[s] = r[s];
	else
	{
		int m = (s + t) / 2;
		MergeSort2(r, r2, s, m);
		MergeSort2(r, r2, m+1, t);
		Merge(r2, r1, s, m, t);
	}
}

#include <ctime>
#include<fstream>
#define random(a, b) (rand() % (b - a) + a) //使随机数函数更加便于使用
int main()
{
	cout << "请输入范围：";
	cin >> fn >> en;
	ofstream out;
	out.open("data.txt", ios_base::out);
	srand((int)time(0)); // 产生随机种子  把0换成NULL也行
	for (int i = 0; i < num; i++)
	{
		out << random(fn, en) << " ";
	}
	out << "\n";
	out.close();
	int count = 0;
	ifstream in("data.txt", ios_base::in);
	if (!in)
	{
		cout << "Can't open the file:data.txt" << endl;
		exit(0);
	}
	while (in >> i_arry[count].key)
	{
		count++;
		if (count > num)
			break;
	}
	cout << "生成随机数：";
	for (int i = 0; i < num; i++)
	{
		cout << i_arry[i].key << " ";
	}
	QuickSort(i_arry,0,count-1);
	    cc(i_arry, "QuickSort");
	for (int m = 0; m < num; m++)
		rs[m + 1] = i_arry[m];
	HeapSort(rs, count);
	MergeSort1(rs, count);
	MergeSort2(rs, r3, 1, count);
	    cc(r3, "MergeSort2");
	ShellSort(i_arry, count);
	return 0;
}
