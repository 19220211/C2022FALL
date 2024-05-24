#include<iostream>
#include <string>
#include <vector>
using namespace std;
struct HuffmanNode
{
	char data;
	double weight;
	int parent, lchild, rchild;
};
class HuffmanTree
{
private:
	vector<HuffmanNode>hufftree;
	int n;
public:
	void SelectSmall(int &least, int &less, int &i)
	{
		int m = 0,k;
		double w;
		while (hufftree[m].parent != -1)
			m++;
		w = hufftree[m].weight;
		k = m;
		for (int a = m; a < i; a++)//parent是否-1为flag，先least后less
		{
			if (w > hufftree[a].weight&& hufftree[a].parent==-1)
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
	HuffmanTree(vector<HuffmanNode>&leafs)
	{
		n = leafs.size();
		hufftree.resize(2 * n - 1);
		for (int i = 0; i < n; i++)
		{
			hufftree[i].data = leafs[i].data;
			hufftree[i].weight = leafs[i].weight;
			hufftree[i].parent = hufftree[i].lchild=hufftree[i].rchild=-1;
		}
		for (int i = n; i < 2 * n - 1; i++)
		{
			int least=0, less=0;
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
	char GetData(int i)
	{
		return hufftree[i].data;
	}
	string Decode(vector<int>&source)
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
	char d[100];
	double wei[100];
	int num=0,s;
	cout << "请输入数据[字符 权值 字符 权值……]"<<endl;
	while (1)
	{
		cin >> d[num];
		cin >> wei[num];
		num++;
		if (cin.get() == '\n')
			break;
	}
    leafs.resize(num);   
	for (int j = 0; j < num; j++)
	{
		leafs[j].data = d[j];
		leafs[j].weight = wei[j];
	}
	HuffmanTree t(leafs);
	cout << "字符的Huffman编码："<<endl;
	for (int j = 0; j < num; j++)
	{
		t.GetCode(j);
		cout << t.GetData(j) << ":";
		for (int i = 0; i < t.GetCode(j).size(); i++)
			cout << t.GetCode(j)[i];
		cout << "  ";
	}
	cout << endl << "请输入一个二进制串"<<endl;
	while (1)
	{
		s = cin.get();  
		if (s == '\n')
			break;
		source.push_back(s-48);
	}
	cout << "译码：" << endl;
	cout << t.Decode(source);
    return 0;
}

