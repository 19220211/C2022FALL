#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct BiNode
{
	int key;
	BiNode* lchild, * rchild;
};
class BiSortTree
{
	BiNode* root;
	void Insert(BiNode*& ptr, int k)
	{
		if (ptr == NULL)
		{
			ptr = new BiNode;
			ptr->key = k;
			ptr->lchild = ptr->rchild = NULL;
		}
		else
		{
			if (k < ptr->key)
				Insert(ptr->lchild, k);
			else if (k > ptr->key)
				Insert(ptr->rchild, k);
		}
	}
	BiNode* Search(BiNode* ptr, int k)
	{
		if (ptr == NULL)
			return NULL;
		else
		{
			if (ptr->key == k)
				return ptr;
			else if (ptr->key > k)
				return Search(ptr->lchild, k);
			else
				return Search(ptr->rchild, k);
		}
	}
	void InOrder(BiNode* p)
	{
		if (p == NULL)
			return;
		InOrder(p->lchild);
		cout << p->key<<" ";
		InOrder(p->rchild);
	}
public:
	BiSortTree(int a[], int n)
	{
		root = NULL;
		for (int i = 0; i < n; i++)
			Insert(root, a[i]);
	}
	void Insert(int k)
	{
		Insert(root, k);
	}
	bool Search(int k)
	{
		return Search(root, k) != NULL;
	}
	void InOrder()
	{
		InOrder(root);
	}
};
int main()
{
	int a[100], flag = 1,k=0 , n = 0, num;
	char m;
		cout << "输入整数：";
		while (1)
		{
			cin >> num;
			a[n++] = num;
			if (cin.get() == '\n')
				break;
		}
		BiSortTree b(a, n);
		cout << "中序遍历二叉排序树：";
		b.InOrder();
		cout << "\n二叉排序树建立成功";
		while(1)
		{
			cout << "\n输入关键字(#退出)：";
		        m=cin.get();
				if (m == '#')
					break;
				else
				{ 
				     k = k * 10 + m - 48;
					 m = cin.get();
					 while (m != '\n')
					 {
						 k = k * 10 + m - 48;
						 m = cin.get();
					 }
				}
			if (b.Search(k)==true)
				cout << "查找成功";
			else
				cout << "查找失败";		
			k = 0;
	    }
	return 0;
}