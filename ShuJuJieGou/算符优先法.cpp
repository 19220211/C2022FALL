#include <iostream>
using namespace std;
char OPSET[7] = { '+','-','*','/','(',')','@'};
unsigned char prior[7][7] = {
{'>','>','<','<','<','>','>'},
{'>','>','<','<','<','>','>'},
{'>','>','>','>','<','>','>'},
{'>','>','>','>','<','>','>'},
{'<','<','<','<','<','=',' '},
{'>','>','>','>',' ','>','>'},
{'<','<','<','<','<',' ','='} };
template<class T,int MaxSize>
class SeqStack
{
	T data[MaxSize];
	int top;
public:
	SeqStack()
	{
		top = -1;
	}
	void Push(T x)
	{
		if(top==MaxSize-1)
		{
			cerr << "上溢"; exit(1);
		}
		top++;
		data[top] = x;
	}
	T Pop()
	{
		T x;
		if(top==-1)
		{
			cerr << "下溢"; exit(1);
		}
		x = data[top];
		top--;
		return x;
	}
	T Top()
	{
		if (top == -1)
		{
			cerr << "下溢"; exit(1);
		}
		return data[top];
	}
	friend double Operate(double a, char pre_op, double b);
	friend unsigned char Precede(char a, char b);
};

double Operate(double a, char pre_op, double b)
{
	switch (pre_op)
	{
	case'+':return a + b ;
	case'-':return a - b ;
	case'*':return a * b ;
	case'/':return a / b ;
	}
}

unsigned char Precede(char p, char c)
{
	int i = 0, j = 0;
	while (OPSET[i] != p)
		i++;
	while (OPSET[j] != c)
		j++;
	return prior[i][j];
}

/*double Expression_Eval()
{
	SeqStack<char, 100> OPTR;
	SeqStack<double, 100> OPND;
	OPTR.Push('@');
	char ch, pre_op;
	double a, b,x=0.0,s=0.0;
	int xs=-1,flag=0,pd=0;//flag判断表达式是否读完，pd判断是否有符号相邻
	ch= getchar();
	while (ch != '@' || OPTR.Top() != '@')
	{
		if (ch >= '0'&&ch <= '9')
		{
			s= ch - '0';
			if (xs == -1)
				x = x * 10 + s;
			else
			{
				++xs;
				for (int i = 1; i <=xs ; i++)
				{
					s = s / 10.0;
				}
                x=x+ s;
			}
			pd = 1;
			ch = getchar();
		}
		else if(ch=='.')
		{
			xs = 0;
			ch = getchar();
		}
		else
		{
			xs = -1;
			if(flag!= 1&&pd==1)
			   OPND.Push(x);
			if (ch == '@')
				flag=1;
			pre_op = OPTR.Top();
			switch (Precede(pre_op, ch))
			{
			case'<':
				OPTR.Push(ch);
				ch = getchar();
				break;
			case'=':
				OPTR.Pop();
				ch = getchar();
				break;
			case'>':
				b = OPND.Pop();
				a = OPND.Pop();
				pre_op = OPTR.Pop();
				OPND.Push(Operate(a, pre_op, b));
				break;
			}
		    x = 0.0;
			pd = 0;
		}
	}
	return OPND.Top();	
}*/

/*double Expression_Eval(string s1)
{
	SeqStack<char, 100> OPTR;
	SeqStack<double, 100> OPND;
	OPTR.Push('@');
	char ch, pre_op;
	double a, b, x = 0.0, s = 0.0;
	int xs = -1, flag = 0, pd = 0;//flag判断表达式是否读完，pd判断是否有符号相邻
	int n = 0;
	ch = s1[n++];
	while (ch != '@' || OPTR.Top() != '@')
	{
		if (ch >= '0' && ch <= '9')
		{
			s = ch - '0';
			if (xs == -1)
				x = x * 10 + s;
			else
			{
				++xs;
				for (int i = 1; i <= xs; i++)
				{
					s = s / 10.0;
				}
				x = x + s;
			}
			pd = 1;
			ch = s1[n++];
		}
		else if (ch == '.')
		{
			xs = 0;
			ch = s1[n++];
		}
		else
		{
			xs = -1;
			if (flag != 1 && pd == 1)
				OPND.Push(x);
			if (ch == '@')
				flag = 1;
			pre_op = OPTR.Top();
			switch (Precede(pre_op, ch))
			{
			case'<':
				OPTR.Push(ch);
				ch = s1[n++];
				break;
			case'=':
				OPTR.Pop();
				ch = s1[n++];
				break;
			case'>':
				b = OPND.Pop();
				a = OPND.Pop();
				pre_op = OPTR.Pop();
				OPND.Push(Operate(a, pre_op, b));
				break;
			}
			x = 0.0;
			pd = 0;
		}
	}
	return OPND.Top();
}*/

double Expression_Eval(string s1)
{
	SeqStack<char, 100> OPTR;
	SeqStack<double, 100> OPND;
	OPTR.Push('@');
	OPND.Push(0.0);
	OPTR.Push('+');
	char ch, pre_op;
	double a, b, x = 0.0, s = 0.0;
	int k=1,fh = 1, xs = -1, flag = 0, pd[100] = { 0 },xl=1;//flag判断表达式是否读完，xl判断是否有符号相邻,pd[100]累加相邻符号数
	pd[0] = 0;
	pd[1] = 1;
	for(int j=2;j<=s1.length()+2;j++)
	{
		if (s1[j-2] >= '0' && s1[j-2] <= '9')
		{
			k = 0;
			pd[j] = k;
		}
		else
			pd[j] = ++k;
	}
	
	int n = 0,t;
	ch = s1[n++];
	while (ch != '@' || OPTR.Top() != '@')
	{
		if (ch >= '0' && ch <= '9')
		{
			s = ch - '0';
			if (xs == -1)
				x = x * 10 + s;
			else
			{
				++xs;
				for (int i = 1; i <= xs; i++)
				{
					s = s / 10.0;
				}
				x = x + s;
			}
			xl = 0;
			ch = s1[n++];
		}
		else if (ch == '.')
		{
			xs = 0;
			ch = s1[n++];
		}
		else
		{
			t = n + 1;
			if (pd[t] >= 2 && ch == '-')
			{
				fh = -1*fh;
				ch = s1[n++];
			}
			else
			{
				xs = -1;
				if (flag != 1 && pd[t] == 1&&xl==0)
				{
					OPND.Push(fh * x);
					//cout << fh * x;
					fh = 1;
				}
				if (ch == '@')
					flag = 1;
				pre_op = OPTR.Top();
				switch (Precede(pre_op, ch))
				{
				case'<':
					OPTR.Push(ch);
					ch = s1[n++];
					break;
				case'=':
					OPTR.Pop();
					ch = s1[n++];
					break;
				case'>':
					b = OPND.Pop();
					a = OPND.Pop();
					pre_op = OPTR.Pop();
					OPND.Push(Operate(a, pre_op, b));
					break;
				}
				x = 0.0;
				xl = 1;
			}
		}
	}
	return OPND.Top();
}

/*int main()
{	
		cout << "输入计算式，并以@结尾:" << "\n";	
		cout << Expression_Eval() << "\n";	
	return 0;
}*/

int main()
{
	string s;
	while (1)
	{
		cout << "输入计算式，并以@结尾:(#退出)" << "\n";
		cin >> s;
		if (s == "#")
			break;
		cout << Expression_Eval(s) << "\n";
	}
    return 0;
}

