//cin.unsetf(ios::skipws);//取消默认的忽视空白字符!
#include<iostream>
#include <string>
#include <vector>
#include<fstream>
#include<iomanip>
using namespace std;
#define NUM 10000
struct HuffmanNode
{
	string data;
	double weight;
	int parent, lchild, rchild;
};
class HuffmanTree
{
private:
	vector<HuffmanNode>hufftree;
	int n;
public:
	void SelectSmall(int& least, int& less, int& i)
	{
		int m = 0, k;
		double w;
		while (hufftree[m].parent != -1)
			m++;
		w = hufftree[m].weight;
		k = m;
		for (int a = m; a < i; a++)//parent是否-1为flag，先least后less
		{
			if (w > hufftree[a].weight && hufftree[a].parent == -1)
			{
				w = hufftree[a].weight;
				k = a;
			}
		}
		least = k;
		hufftree[least].parent = i;
		m = 0;
		while (hufftree[m].parent != -1)
			m++;
		w = hufftree[m].weight;
		k = m;
		for (int a = m; a < i; a++)
		{
			if (w > hufftree[a].weight && hufftree[a].parent == -1)
			{
				w = hufftree[a].weight;
				k = a;
			}
		}
		less = k;
	}
	HuffmanTree(vector<HuffmanNode>& leafs)
	{
		n = leafs.size();
		hufftree.resize(2 * n - 1);
		for (int i = 0; i < n; i++)
		{
			hufftree[i].data = leafs[i].data;
			hufftree[i].weight = leafs[i].weight;
			hufftree[i].parent = hufftree[i].lchild = hufftree[i].rchild = -1;
		}
		for (int i = n; i < 2 * n - 1; i++)
		{
			int least = 0, less = 0;
			SelectSmall(least, less, i);
			hufftree[least].parent = hufftree[less].parent = i;
			hufftree[i].parent = -1;
			hufftree[i].lchild = least;
			hufftree[i].rchild = less;
			hufftree[i].weight = hufftree[least].weight + hufftree[less].weight;
		}
	}
	//~HuffmanTree();
	vector<int>GetCode(int i)
	{
		vector<int>code;
		int p = i;
		int parent = hufftree[i].parent;
		while (parent != -1)
		{
			if (hufftree[parent].lchild == p)
				code.insert(code.begin(), 0);
			else
				code.insert(code.begin(), 1);
			p = parent;
			parent = hufftree[parent].parent;

		}
		return code;
	}
	string GetData(int i)
	{
		return hufftree[i].data;
	}
	string Decode(vector<int>& source)
	{
		string target = "";
		int root = hufftree.size() - 1;
		int p = root;
		for (int i = 0; i < source.size(); i++)
		{
			if (source[i] == 0)
				p = hufftree[p].lchild;
			else
				p = hufftree[p].rchild;
			if (hufftree[p].rchild == -1 && hufftree[p].lchild == -1)
			{
				target = target + hufftree[p].data;
				p = root;
			}
		}
		return target;
	}
};
int main()
{
	vector<HuffmanNode>leafs;
	vector<int>source;
	string r[10000];
	double wei[NUM], sum = 0;
	string d[NUM],c;
	int num = 0, s,count=0,count1=0,count2=0,n=128,hs=0,h=1;
	ifstream fil;
	fil.open("A.txt", ios::in);
	for (int j = 0; j < NUM; j++)
	{
		wei[j] = 0;
	}
	while (getline(fil, c))
		hs++;
	fil.close();
	ifstream file;
	file.open("A.txt", ios::in);
	c = "";
	while (getline(file, r[count1]))
	{
		if(h<hs)
		   r[count1] = r[count1] + '\n';
		h++;
		count2 = 0;
		while (count2 < r[count1].length())
		{
		  if (r[count1][count2] > 127 || r[count1][count2] < 0)
		  {
			  int j = 128;
			c = c + r[count1][count2] + r[count1][count2 + 1];
			while(j<n)
			{
				if (d[j] == c)
				{
                     wei[j]++;
                     break;
				}	
				j++;
			}
			if (j == n)
			{
				d[n] = c;
				wei[n]++;
				n++;
			}
			count2++;
		  }
		  if (r[count1][count2] <= 127 && r[count1][count2] >= 0)
		  {
            c = r[count1][count2];
			d[r[count1][count2]] = c;
			wei[r[count1][count2]] ++;
		  }
		  c = "";
		  count2++;
		}
		count1++;
	}
	file.close();
	count = 0;
	for (int j = 0; j < n; j++)
	{
		if (wei[j] != 0)
			num++;
		sum += wei[j];
	}
	cout << "各字符及频率：" << endl;
	for (int j = 0; j < n; j++)
	{
		if (wei[j] != 0)
			cout << d[j] << "：" << wei[j] / sum << "   ";
	}
	leafs.resize(num);
	for (int j = 0; j < num; j++)
	{
		if (wei[count] != 0)
		{
			leafs[j].data = d[count];
			leafs[j].weight = wei[count];
			count++;
		}
		else
		{
			count++;
			j--;
		}
	}
	HuffmanTree t(leafs);
	cout << endl << "字符的Huffman编码：" << endl;
	for (int j = 0; j < num; j++)
	{
		t.GetCode(j);
		cout << t.GetData(j) << " ";
		for (int i = 0; i < t.GetCode(j).size(); i++)
			cout << t.GetCode(j)[i];
		cout << "   ";
	}
	ofstream out;
	out.open("B.txt", ios_base::out);
	c = "";
	for (int j = 0; j < count1; j++)
	{
		count2 = 0;
		while (count2 < r[j].length())
		{
			int i = 0;
			if (r[j][count2] > 127 || r[j][count2] < 0)
			{			
				c = c + r[j][count2] + r[j][count2 + 1];	
				count2++;   
			}
			if (r[j][count2] <= 127 && r[j][count2] >= 0)
				c = r[j][count2];
			while (c != t.GetData(i))
				i++;
			c = "";
			count2++;
			for (int k = 0; k < t.GetCode(i).size(); k++)
				out << t.GetCode(i)[k];
		}
	}
	out << "\n";
	out.close();
	cout << endl << "Huffman编码文件B：" << endl;
	c = "";
	for (int j = 0; j < count1; j++)
	{
		count2 = 0;
		while (count2 < r[j].length())
		{
			int i = 0;
			if (r[j][count2] > 127 || r[j][count2] < 0)
			{
				c = c + r[j][count2] + r[j][count2 + 1];
				count2++;
			}
			if (r[j][count2] <= 127 && r[j][count2] >= 0)
				c = r[j][count2];
			while (c != t.GetData(i))
				i++;
			c = "";
			count2++;
			for (int k = 0; k < t.GetCode(i).size(); k++)
				cout << t.GetCode(i)[k];
		}
	}
	ifstream inm("B.txt", ios_base::in);
	if (!inm)
	{
		cout << "Can't open the file:B.txt" << endl;
		exit(0);
	}
	while (1)
	{
		s = inm.get();
		if (s == '\n')
			break;
		source.push_back(s - 48);
	}
	cout << endl << "译码文件C：" << endl;
	cout << t.Decode(source);
	ofstream oum;
	oum.open("C.txt", ios_base::out);
	oum << t.Decode(source);
	oum.close();
	return 0;
}
