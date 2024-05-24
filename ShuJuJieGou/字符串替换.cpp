#include <iostream>
#include<string>
using namespace std;
/*void getnext(char* t)
{
	int j = 0, k = -1, m = 0, next[100] = { 0 };
	m = strlen(t);
	next[0] = -1;
	while (j < m - 1)
	{
		if (k == -1 || t[j] == t[k])
		{
			j++;
			k++;
			next[j] = k;
		}
		else
			k = next[k];
	}
}*/

int* KMPmatching(string s, string t)
{
	int i = 0, j = 0, n = 0, m = 0,sum=0;
	n = s.length();//strlen(s);
	m = t.length();//strlen(t);
	int l = 0, k = -1, next[100] = { 0 }, nextval[100] = { 0 }; //xb[100] = { 0 };
	int* xb = new int[100];
	for(int k=0;k<100;k++)
	xb[k] = { 0 };
	nextval[0]=next[0] = -1;
	while (l < m - 1)
	{
		if (k == -1 || t[l] == t[k])
		{
			l++;
			k++;
			next[l] = k;
			if (t[l] == t[k])
				next[l] = next[k];
			nextval[l] = next[l];
		}
		else
			k = next[k];
	}

	while (i < n && j < m)
	{
		if (j == -1 || s[i] == t[j])
		{
			i++;
			j++;
		}
		else
			j = nextval[j];
		if (j == m)
		{
			j = 0;
			xb[i - m] = 1;
		}
	}

	for (int a = 0; a < n; a++)	
		sum += xb[n];
	return xb;
}

void tihuan(string s, string t, string p, int Sum[])
{
	int i = 0, j = 0, n = 0, m = 0,l=0, sum = 0;
	n = s.length();//strlen(s);
	m = t.length();//strlen(t);
	l = p.length();//strlen(p);
	for (int a = 0; a < n; a++)
		sum += Sum[a];
	if (sum > 0)
	{
		for (i = 0; i < n; i++)
		{
			if (Sum[i] == 0)
				cout << s[i];
			else
			{
				for (j = 0; j < l; j++)
					cout << p[j];
				i = i + m - 1;
			}
		}
		cout << endl;
	}
	else
		cout << "未找到模式t"<<endl;
}

int main()
{
	//char s[100],t[100], p[100];
	string s, t, p;
	while (1)
	{
		cout << "输入主串s：(#退出)" << "\n";
		getline(cin, s); //cin >> s;
		if (s == "#")
			break;
		cout << "输入模式t：" << "\n";
		getline(cin, t);// cin >> t;
		cout << "输入要替换成的字符串p：" << "\n";
		getline(cin, p); //cin >> p;
		cout << "替换后的字符串：" << "\n";
		int* SUM = KMPmatching(s, t);
		tihuan(s, t,p, SUM);
	}
	return 0;
}

