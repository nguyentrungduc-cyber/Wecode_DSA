/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
using namespace std;

struct DONTHUC
{
	float HeSo;
	int SoMu;
};
struct NODE
{
	DONTHUC info;
	NODE *pNext;
};
struct DATHUC
{
	NODE *pHead;
	NODE *pTail;
};

// ###INSERT CODE HERE -
NODE *createNode(int heso, int somu)
{
	NODE *p = new NODE();
	p->info.HeSo = heso;
	p->info.SoMu = somu;
	p->pNext = nullptr;
	return p;
}

void CreateEmptyDATHUC(DATHUC &d)
{
	d.pHead = d.pTail = nullptr;
}

void addTail(DATHUC &l, NODE *p)
{
	if (l.pHead == nullptr)
	{
		l.pHead = l.pTail = p;
		return;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}

void SelectionSort(DATHUC &q)
{
	if (q.pHead == nullptr)
		return;
	for (NODE *p = q.pHead; p != q.pTail; p = p->pNext)
	{
		NODE *minNode = p;
		for (NODE *k = p->pNext; k != NULL; k = k->pNext)
		{
			if (k->info.SoMu < minNode->info.SoMu)
				minNode = k;
		}
		int hesoP = p->info.HeSo, somuP = p->info.SoMu;
		p->info.HeSo = minNode->info.HeSo;
		p->info.SoMu = minNode->info.SoMu;
		minNode->info.HeSo = hesoP;
		minNode->info.SoMu = somuP;
	}
}

void filterDaThuc(DATHUC &d) // tìm cặp liền kề cùng mũ
{
	if (d.pHead == nullptr)
		return;
	// duyệt danh sách
	for (NODE *p = d.pHead; p != nullptr && p->pNext != nullptr;) // điều kiện STEP cần nếu đáp ứng "=="
	{
		// cần 1 NODE tiếp theo để so sánh, cũng như sẽ thay đổi nếu "==" còn p không cần
		NODE *q = p->pNext;
		if (p->info.SoMu == q->info.SoMu)
		{
			// cộng hệ số của q vào p
			p->info.HeSo += q->info.HeSo;
			// xóa sổ q
			p->pNext = q->pNext;

			// kiểm tra xem q có phải pTail không
			delete q;
			// kiểm tra xem q có phải pTail không
			if (p->pNext == nullptr)
			{
				d.pTail = p;
			}
		}
		else
		{
			p = p->pNext;
		}
	}
}

void checkZero(DATHUC &d)
{
	// Danh sách rỗng
	if (d.pHead == nullptr)
		return;

	// Xóa các node đầu có hệ số 0
	while (d.pHead != nullptr && d.pHead->info.HeSo == 0)
	{
		NODE *temp = d.pHead;
		d.pHead = d.pHead->pNext;
		delete temp;
	}

	// Nếu sau khi xóa đầu mà rỗng luôn
	if (d.pHead == nullptr)
	{
		d.pTail = nullptr;
		return;
	}

	// Duyệt phần còn lại
	NODE *p = d.pHead;
	while (p != nullptr && p->pNext != nullptr)
	{
		if (p->pNext->info.HeSo == 0)
		{
			NODE *q = p->pNext;
			p->pNext = q->pNext;

			// Nếu xóa node cuối → cập nhật pTail
			if (q == d.pTail)
				d.pTail = p;

			delete q;
		}
		else
		{
			p = p->pNext;
		}
	}
}

void CreatePolynomial(DATHUC &d)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		float heso;
		int somu;
		cin >> heso >> somu;
		addTail(d, createNode(heso, somu));
	}

	SelectionSort(d);
	filterDaThuc(d);
	checkZero(d);
}

void Output(DONTHUC a)
{
	if (a.HeSo == -1)
		cout << "-";
	else if (a.HeSo == 1)
		cout << "";
	else
		cout << a.HeSo;

	if (a.SoMu == 0)
		cout << "";
	else if (a.SoMu == 1)
		cout << "x";
	else if (a.SoMu < 1)
		cout << "-x";
	else // s.SoMu>1
		cout << "x^" << a.SoMu;
}

void Output(DATHUC L)
{
	NODE *p;

	if (L.pHead == NULL)
		cout << "Empty DATHUC.";
	else
	{
		p = L.pHead;
		Output(p->info);
		p = p->pNext;
		while (p)
		{
			cout << " + ";
			Output(p->info);
			p = p->pNext;
		}
	}
}

int main()
{
	DATHUC poly;
	CreateEmptyDATHUC(poly);
	CreatePolynomial(poly);
	Output(poly);
	return 0;
}
