#include<iostream>
#include<vector>
using namespace std;
enum GraphType { undigraph, digraph, undinetwork, dinetwork };
template<class T,int MaxSize>
class SeqQueue
{
	T data[MaxSize];
	int front, rear;
public:
	SeqQueue()
	{
		front = rear = 0;
	}
	void EnQueue(T x)
	{
		if ((rear + 1) % MaxSize == front)
		{
			cerr << "上溢"; exit(1);
		}
		rear = (rear + 1) % MaxSize;
		data[rear] = x;
	}
	T DeQueue()
	{
		if (rear == front)
		{
			cerr << "下溢"; exit(1);
		}
		front = (front + 1) % MaxSize;
		return data[front];
	}
	bool Empty()
	{
		return rear == front;
	}
};
template<class T>
struct Edge
{
	T adjvex;
	float lowcost;
};
template<class T>
struct EdgeType
{
	T head, tail;
	int cost;
	EdgeType(T h, T t, int c)
	{
		head = h; tail = t; cost = c;
	}
};
template<class T>
class MGraph
{
private:
	int vexnum, edgenum;
	GraphType kind;
	vector<vector<float>>edges;
	vector<T>vexs;
	void DFS(int v, bool*visited);
	int MiniNum(Edge<T>* mini)
	{
		//Edge<T>* mini = new Edge<T>[vexnum];
		int m = 0, k;
		float w;
		while (mini[m].lowcost == 0)
			m++;
		w = mini[m].lowcost;
		k = m;
		for (int a = m; a < vexnum; a++)
		{
			if (w > mini[a].lowcost && mini[a].lowcost != 0)
			{
				w = mini[a].lowcost;
				k = a;
			}
		}
		return k;
	}
public:
	MGraph(GraphType t, T v[], int n, int e,int va[],int vb[],int w[]);
	~MGraph() {};
	void DFSTraverse();
	void BFSTraverse();
	void Prim(int v);
	void Dijkstra(int v, int path[], float dist[]);
	void Print()
	{
		cout << "邻接矩阵表示\n";
		for (int i = 0; i < vexnum; i++)
		{
			for (int j = 0; j < vexnum; j++)
			{
				cout << edges[i][j] << " ";
			}
			cout << endl;
		}
	}
	T GetVexValue(int i)
	{
		return vexs[i];
	}
	float GetEdgeValue(int i, int j)
	{
		return edges[i][j];
	}
	void PrintPath(int n, int path[], float dist[], int v)
	{
		
		cout << "从源点" << vexs[v] << "到各终点的最短路径及长度" << endl;
		for (int i = 0; i < n; i++)
		{
			int x=path[i],m=0,y[100];
			cout << vexs[v] ;
			while (x != v)
			{
				y[m++] = x;
				x = path[x];
			}
			while(m>0)
				cout << "->"<< vexs[y[--m]];
			cout <<"->"<<vexs[i]<<"  "<< dist[i] << endl;
		}
	}
};
template<class T>
MGraph<T>::MGraph(GraphType t, T v[], int n, int e, int va[], int vb[],int w[])
{
	vexnum = n;
	edgenum = e;
	kind = t;
	vexs.resize(vexnum);
	edges.resize(vexnum);
	for (int i = 0; i < n; i++)
		vexs[i] = v[i];
	for (int i = 0; i < n; i++)
		edges[i].resize(vexnum);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				edges[i][j] = 0;
			else edges[i][j] = INFINITY;
		}
	}
	for (int i = 0; i < e; i++)
	{
		//int va, vb, w;
		//cin >> va >> vb;
		//cin >> w;
		//edges[va][vb] = edges[vb][va] = w;
		edges[va[i]][vb[i]] = edges[vb[i]][va[i]] = w[i];
	}
}
template<class T>
void MGraph<T>::DFS(int v, bool*visited)
{
	cout << vexs[v];
	visited[v] = true;
	for (int i = 0; i < vexnum; i++)
	{
		if (edges[v][i] == 1 && !visited[i])
			DFS(i, visited);
	}
}
template<class T>
void MGraph<T>::DFSTraverse()
{
	cout << "深度优先（邻接矩阵）\n";
	bool*visited = new bool[vexnum];
	for (int v=0; v < vexnum; v++)
		visited[v] = false;
	for (int v=0; v < vexnum; v++)
		if (!visited[v])
			DFS(v, visited);
	delete[]visited;
}
template<class T>
void MGraph<T>::BFSTraverse()
{
	cout << "\n广度优先（邻接矩阵）\n";
	SeqQueue<int, 10>q;
	bool*visited= new bool[vexnum];
	for (int i=0; i < vexnum; i++)
		visited[i] = false;
	for (int i=0; i < vexnum; i++)
	{
		if (!visited[i])
		{
			cout << vexs[i];
			visited[i] = true;
			q.EnQueue(i);
			while (!q.Empty())
			{
				int u = q.DeQueue();
				for (int j = 0; j < vexnum; j++)
				{
					if (edges[u][j] == 1 && !visited[j])
					{
						cout << vexs[j];
						visited[j] = true;
						q.EnQueue(j);
					}
				}
			}
		}
	}
	delete[]visited;
}

struct EdgeNode
{
	int adjvex;
	EdgeNode*nextedge;

};
template<class T>
struct VexNode
{
	T data;
	EdgeNode*firstedge;
};
template<class T>
class ALGraph
{
private:
	int vexnum, edgenum;
	GraphType kind;
	vector<VexNode<T>>adjlist;
	void DFS(int v, bool*visited)
	{
		cout << adjlist[v].data;
	    visited[v] = true;
		for (int i = 0; i < vexnum; i++)
		{
			int flag = 0;
			EdgeNode* p = new EdgeNode;
				if (adjlist[v].firstedge)
					p = adjlist[v].firstedge;
				while (p)
				{
					if (p->adjvex == i)
						flag = 1;
					p = p->nextedge;
				}
			if (flag == 1 && !visited[i])
				DFS(i, visited);
		}
	}
public:
	ALGraph(GraphType t, T v[], int n, int e, int va[], int vb[]);
	~ALGraph() {};
	void DFSTraverse()
	{
		cout << "深度优先（邻接表）\n";
		bool* visited = new bool[vexnum];
		for (int v = 0; v < vexnum; v++)
			visited[v] = false;
		for (int v = 0; v < vexnum; v++)
			if (!visited[v])
				DFS(v, visited);
		delete[]visited;
	}
	void BFSTraverse()
	{
		cout << "\n广度优先（邻接表）\n";
		SeqQueue<int, 10>q;
		bool* visited = new bool[vexnum];
		for (int i = 0; i < vexnum; i++)
			visited[i] = false;
		for (int i = 0; i < vexnum; i++)
		{
			if (!visited[i])
			{
				cout << adjlist[i].data;
				visited[i] = true;
				q.EnQueue(i);
				while (!q.Empty())
				{
					int u = q.DeQueue();
					for (int j = 0; j < vexnum; j++)
					{
						int flag = 0;
						EdgeNode* p = new EdgeNode;
						if (adjlist[u].firstedge)
							 p = adjlist[u].firstedge;
						while (p)
						{
							if (p->adjvex == j)
								flag = 1;
							p = p->nextedge;
						}
						if (flag == 1 && !visited[j])
						{
							cout << adjlist[j].data;
							visited[j] = true;
							q.EnQueue(j);
						}
					}
				}
			}
		}
		delete[]visited;
	}
	void Print()
	{
		EdgeNode* p = new EdgeNode;
		cout << "\n邻接表表示\n";
		for (int i = 0; i < vexnum; i++)
		{
			if (adjlist[i].firstedge)
				p = adjlist[i].firstedge;
			cout << adjlist[i].data;
			while (p)
			{
				cout << "->"<<p->adjvex;
				p = p->nextedge;
			}
			cout << "\n";
		}
	}
};
template<class T>
ALGraph<T>::ALGraph(GraphType t, T vexs[], int n, int e, int va[], int vb[])
{
	EdgeNode*p;
	vexnum = n;
	edgenum = e;
	kind = t;
	adjlist.resize(vexnum);
	for (int i = 0; i < vexnum; ++i)
	{
		adjlist[i].data = vexs[i];
		adjlist[i].firstedge = 0;
	}
	for (int j = 0; j < edgenum; j++)
	{
		//int va, vb;
		//cin >> va >> vb;
		p = new EdgeNode;
		p->adjvex = vb[j];
		p->nextedge = adjlist[va[j]].firstedge;
		adjlist[va[j]].firstedge = p;
		p = new EdgeNode;
		p->adjvex = va[j];
		p->nextedge = adjlist[vb[j]].firstedge;
		adjlist[vb[j]].firstedge = p;
	}
}

template<class T>
void MGraph<T>::Prim(int v)
{
	cout << "最小生成树\n";
	Edge<T>*miniedges = new Edge<T>[vexnum];
	for (int i = 0; i < vexnum; i++)
	{
		miniedges[i].adjvex = GetVexValue(v);
		miniedges[i].lowcost = GetEdgeValue(v,i);
	}
	miniedges[v].lowcost = 0;
	for (int i = 1; i < vexnum; i++)
	{
		int k = MiniNum(miniedges);
		cout << miniedges[k].adjvex << "-->" << GetVexValue(k) << endl;
		miniedges[k].lowcost = 0;
		for (int j = 0; j < vexnum; j++)
		{
			if (GetEdgeValue(k, j) < miniedges[j].lowcost)
			{
				miniedges[j].adjvex = GetVexValue(k);
				miniedges[j].lowcost = GetEdgeValue(k, j);
			}
		}
	}
	delete[]miniedges;
}
template<class T>
void MGraph<T>::Dijkstra(int v, int path[], float dist[])
{
	int k;
	bool* s = new bool[vexnum];
	for (int i = 0; i < vexnum; i++)
	{
		s[i] = false;
		dist[i] = GetEdgeValue(v, i);
		if (dist[i] < INFINITY || i == v)
			path[i] = v;
		else 
			path[i] = -1;
	}
	dist[v] = 0;
	s[v] = true;
	for (int i = 1; i < vexnum; i++)
	{
		float min = INFINITY;
		for(int j=0;j<vexnum;j++)
			if (!s[j] && dist[j] < min)
			{
				k = j;
				min = dist[j];
			}
		s[k] = true;
		for(int w=0;w<vexnum;w++)
			if (!s[w] && dist[w] > dist[k] + GetEdgeValue(k, w))
			{
				dist[w] = dist[k] + GetEdgeValue(k, w);
				path[w] = k;
			}
	}
	delete[]s;
	PrintPath(vexnum, path, dist, v);
}



int main()
{
	int n = 0, e, va[100], vb[100], w[100];
	int path[100], v;
	float dist[100];
	cout << "输入无向图的顶点：\n";
	char V[100],c;
	while (1)
	{
		cin >> c;
		V[n++] = c;
		if (cin.get() == '\n')
			break;
	}
	cout << "输入边数：";
	cin >> e;
	cout << "输入每条边的两个端点序号和权值：\n";
	for (int k = 0; k < e; k++)
	{
		cin >> va[k] >> vb[k]>>w[k];
	}
	MGraph<char> g(undigraph, V, n, e,va, vb,w);
	//g.Print();
	//g.DFSTraverse();
	//g.BFSTraverse();
	g.Prim(0);
	cout << "输入源点序号：";
	cin >> v;
	g.Dijkstra(v, path, dist);
	
	//ALGraph<char> al(undigraph, V, n, e, va, vb);
	//al.Print();
	//al.DFSTraverse();
	//al.BFSTraverse();
	return 0;
}

/*0 1 2
0 2 5
0 3 4
1 2 4
2 3 6
1 4 5
2 4 3
2 5 4
3 5 7
4 5 1*/

/*
0 1 10
0 4 100
0 3 30
1 2 50
2 4 10
2 3 20
3 4 60
*/
