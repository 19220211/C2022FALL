#include<iostream>
#include<vector>
#include<string>
using namespace std;
template<class T>
struct Node
{
	T data;
	Node<T>* next;
};
template<class T>
class LinkQueue
{
private:
	Node<T>* front, * rear;
public:
	LinkQueue()
	{
		Node<T>* s;
		s = new Node<T>;
		s->next = NULL;
		front = rear = s;
	}
	void EnQueue(T x)
	{
		Node<T>* s;
		s = new Node<T>;
		s->data = x;
		s->next = NULL;
		rear->next = s;
		rear = s;
	}
	T DeQueue()
	{
		Node<T>* p; T x;
		if (rear == front)
		{
			cout << "下溢"; exit(1);
		}
		p = front->next;
		x = p->data;
		front->next = p->next;
		if (p->next == NULL)
			rear = front;
		delete p;
		return x;
	}
	bool Empty()
	{
		return rear == front;
	}
};
template<class T>
struct BiNode
{
	T data;
	BiNode<T>* lchild;
	BiNode<T>* rchild;
};
template<class T>
class BiTree
{
private:
	BiNode<T>* root;
	void PreOrder(BiNode<T>* p)
	{
		if (p == NULL)
			return;
		cout << p->data;
		PreOrder(p->lchild);
		PreOrder(p->rchild);
	}
	void InOrder(BiNode<T>* p)
	{
		if (p == NULL)
			return;
		InOrder(p->lchild);
		cout << p->data;
		InOrder(p->rchild);
	}
	void PostOrder(BiNode<T>* p)
	{
		if (p == NULL)
			return;
		PostOrder(p->lchild);
		PostOrder(p->rchild);
		cout << p->data;
	}
	BiNode<T>* CreateByPre(vector<T>& pre, int& i)
	{
			T e = pre[i]; i++;
			if (e == '*')
				return NULL;
			BiNode<T>* p = new BiNode<T>;
			p->data = e;
			p->lchild = CreateByPre(pre, i);
			p->rchild = CreateByPre(pre, i);
			return p;	
	}
	int Count(BiNode<T>* p)
	{
		if (p == NULL)
			return 0;
		int left = Count(p->lchild);
		int right = Count(p->rchild);
		return 1 + left + right;
	}
	int Height(BiNode<T>* p)
	{
		if (p == NULL)
			return 0;
		int left = Height(p->lchild);
		int right = Height(p->rchild);
		if (left > right)
			return left + 1;
		else
			return right + 1;
	}
	BiNode<T>* Search(BiNode<T>* p, T e)
	{
		if (p== NULL)
			return NULL;
		if (p->data == e)
			return p;
		BiNode<T>* q = Search(p->lchild, e);
		if (q != NULL)
			return q;
		return Search(p->rchild, e);
	}
	BiNode<T>* SearchParent(BiNode<T>* p, BiNode<T>* child)
	{
		if (p == NULL||child==NULL)
			return NULL;
		if (p->lchild == child || p->rchild== child)
			return p;
		BiNode<T>* q = SearchParent(p->lchild, child);
		if (q != NULL)
			return q;
		return SearchParent(p->rchild, child);
	}
public:
	 BiTree(vector<T>& pre)
	{
		int i = 0;
		root = CreateByPre(pre, i);
	}
	void PreOrder()
	{
		PreOrder(root);
	}
	void InOrder()
	{
		InOrder(root);
	}
	void PostOrder()
	{
		PostOrder(root);
	}
	void LevelOrder()
	{
		if (root == NULL)
			return;
		LinkQueue<BiNode<T>*>Q;
		Q.EnQueue(root);
		while (!Q.Empty())
		{
			BiNode<T>* p = Q.DeQueue();
			cout << p->data;
			if (p->lchild != NULL)
				Q.EnQueue(p->lchild);
			if (p->rchild != NULL)
				Q.EnQueue(p->rchild);
		}
	}
	int Count()
	{
		return Count(root);
	}
	int Height()
	{
		return Height(root);
	}
	BiNode<T>* Search(T e)
	{
		return Search(root, e);
	}
	BiNode<T>* SearchParent(BiNode<T>* child)
	{
		return SearchParent(root, child);
	}
};

int main()
{
	string pre;
	char d;
	int f=1,g=1;
	cout << "先序遍历：1\n中序遍历：2\n后序遍历：3\n层次遍历：4\n求树高：5\n结点总数：6\n求父结点：7\n退出：0\n";
	while (g == 1)
	{
		cout << "输入带空指针的先序序列：\n";
		cin >> pre;
		vector<char> v;
		for (int i = 0; i < pre.length(); i++)
			v.push_back(pre[i]);
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << " ";
		BiTree<char> b(v);
		while (f!=0)
		{
			cout << "\n输入操作：";
			cin >> f;
			switch (f)
			{
			case 0:
				break;
			case 1:
				b.PreOrder();
				break;
			case 2:
				b.InOrder();
				break;
			case 3:
				b.PostOrder();
				break;
			case 4:
				b.LevelOrder();
				break;
			case 5:
				cout << b.Height();
				break;
			case 6:
				cout << b.Count();
				break;
			case 7:
				cout << "输入该结点的值：";
				cin >> d;
				if (b.SearchParent(b.Search(d)) == NULL)
					cout << "查找失败";
				else
				    cout << "父结点为："<< b.SearchParent(b.Search(d))->data;
				break;
			}
		}
		f = 1;
		cout << "输入是否继续[是 1/否 2]：\n";
		cin >> g;
	}
	return 0;
}
