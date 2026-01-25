/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
using namespace std;

struct TNODE
{
	int key;
	TNODE *pLeft;
	TNODE *pRight;
};
typedef TNODE *TREE;

// ###INSERT CODE HERE -
TNODE *CreateNode(int x)
{
	TNODE *p = new TNODE;
	p->key = x;
	p->pLeft = NULL;
	p->pRight = NULL;
	return p;
}

// Chèn node vào BST
int Insert(TREE &T, int x)
{
	if (T)
	{
		if (T->key == x)
			return 0;
		if (x < T->key)
			return Insert(T->pLeft, x);
		return Insert(T->pRight, x);
	}
	T = CreateNode(x);
	return 1;
}

// Tạo cây
void CreateTree(TREE &T)
{
	int x;
	cin >> x;
	if (x == -1)
	{
		T = NULL;
		return;
	}
	T = CreateNode(x);
	while (cin >> x && x != -1)
	{
		Insert(T, x);
	}
}

void ThayThe(TREE &p, TREE &T)
{
	/*
	 */
	// T là node cần xóa, p là copy của T
	// Đầu vào là pRight của node cần xóa nên đệ quy bên trái tìm min-Right
	if (T->pLeft != NULL)
		ThayThe(p, T->pLeft);
	else
	{
		// Sau quá trình trên, ta có T là min-right Node
		// p là TRỎ ĐẾN node cần xóa
		p->key = T->key; // gán giá trị của min-right Node vào giá trị của Node cần xóa
		p = T;			 // sau khi xử lý xong Node cần xóa thì xử lý min-right Node là p trỏ đến nó đê xóa p
		T = T->pRight;	 // nếu p có con bên phải thì cho nó thay thế T không thì NULL
	}
	// mục đích của hàm thay thế lầ trong trường hợp node cần xóa có 2 con thì
	/// tìm node bên phải nhỏ nhất nên ta cần đệ quy bên trái cho đến khi
	//// pLeft null là được thì khi đó t là min-right node
	///// khi có min-right node thì gán giá trị đó vào node cần xóa và p sẽ trỏ đến min-right Node
	///// còn T là T-pRight
}

void DeleteNode(TREE &T, int x)
{
	/*

	*/
	if (T != NULL)
	{
		// B1: Tìm node cần xóa
		if (T->key < x)
			DeleteNode(T->pRight, x);
		else if (T->key > x)
			DeleteNode(T->pLeft, x);
		//////////////////////////////
		else
		{
			// Lúc này: T chính là Node cần xóa, tức là TREE có Root là node cần xóa để tìm min-right Node
			TNODE *p;
			p = T;						// p là Node cần xóa, tức là TREE có Root là node cần xóa để tìm min-right Node
			if (T->pLeft == NULL)		// node không có con trái (có thể có con phải hoặc không)
				T = T->pRight;			// xóa node cần xóa thức làm cho node cha của node cần xóa nối tới con của node cần xóa
			else if (T->pRight == NULL) // / node không có con phải (có thể có con phải hoặc không)
				T = T->pLeft;			// tương tự trên
			else
				ThayThe(p, T->pRight); // trường hợp 2 con
			delete p;
		}
	}
	// mục đích: xóa node chứa giá trị x
	// B1: tìm được Node chứa giá trị X bằng cách đệ quy 3 tình huống if else_if else, else sẽ là Node cần xóa
	// có 3 trường hợp, sẽ xử lý trong tình huống else
	// có 1 node con hoặc không node con nào (node lá): có thể bên trái hoặc bên phải,
	/// sau khi tìm được node cần xóa sẽ kiểm tra pRight của nó, nếu null thì vị trí của nó sẽ là pLeft của nó
	//// tương tự khi kiểm tra pLeft
	// nếu trường hợp trên không đáp ứng thì trường hợp 2 con
	/// thì hàm ThayThe thoi
}

void preorder(TREE Root)
{
	if (Root != NULL)
	{
		cout << Root->key << " ";
		preorder(Root->pLeft);
		preorder(Root->pRight);
	}
}

void PrintTree(TREE t)
{
	if (t == nullptr)
	{
		cout << "Empty Tree.";
		return;
	}
	preorder(t);
}

int main()
{
	TREE T;	  // hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);

	int x;
	cin >> x;

	DeleteNode(T, x);

	PrintTree(T);
	return 0;
}
