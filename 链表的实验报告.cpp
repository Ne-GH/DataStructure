#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct node {
	int data;
	struct node* pnext;
}NODE, * PNODE;

void init(PNODE&);//创建,初始化
void print(PNODE&);//打印
void deleteList(PNODE&);//销毁
void deleteL(PNODE&);//删除某一结点
void seek(PNODE&);//查找
void insert(PNODE&);//插入
void len(PNODE&);
//如果不使用引用,而是以指针为形参,在分配内存时,\
  形参的值会指向新分配的内存的地址而不是和实参保持一致

int main() {
	PNODE Head, End;
	Head = (PNODE)malloc(sizeof(NODE));
	if (!Head) {
		cout << "为头结点分配内存失败" << endl;
		exit(-1);
	}
	Head->pnext = NULL;
	End = Head;
	init(End);
	while (1) {
		cout << "1.输出某个元素的值" << endl;
		cout << "2.在某元素之前插入一个元素" << endl;
		cout << "3.删除链表中的某一元素" << endl;
		cout << "4.查询链表长度及各个元素" << endl;
		cout << "5.退出" << endl;

		cout << "请输入你想进行的操作: ";
		int X;
		cin >> X;
		switch (X) {
		case 1:
			seek(Head);
			break;
		case 2:
			insert(Head);
			break;
		case 3:
			deleteL(Head);
			break;
		case 4:
			len(Head);
			break;
		case 5:
			deleteList(Head);
			goto A;
			break;
		default:
			cout << "输入有误,请重新输入" << endl;
			cout << "----------------------------------" << endl;
			break;
		}
	}
A:
	return 0;
}

void init(PNODE& T) {
	cout << "请输入元素个数和各个元素的值";
	int n;
	cin >> n;
	T->data = n;
	for (int i = 1; i <= n; i++) {
		PNODE temp = (PNODE)malloc(sizeof(NODE));
		if (!temp) {
			cout << "分配内存失败" << endl;
			exit(-1);

		}
		T->pnext = temp;//已有的链表指向新分配的内存
		T = T->pnext;//T始终指向最后的结点
		cin >> T->data;
	}
	T->pnext = NULL;//最后一个结点的指针设为空指针

	cout << "长度为" << n << "的链表创建完成" << endl;
	cout << "----------------------------------" << endl;
	return;
}

void print(PNODE& T) {
	PNODE temp = T->pnext;
	cout << "----------------------------------" << endl;

	while (temp) {//打印头节点之后,空结点之前的数据
		cout << temp->data << "\t";
		temp = temp->pnext;
	}

	putchar(10);
	cout << "----------------------------------" << endl;
}

void deleteList(PNODE& T) {
	PNODE temp = T->pnext;
	while (temp) {
		PNODE t = temp->pnext;//临时变量记下下个内存的位置
		free(temp);          //释放当前内存
		temp = t;            //指向下一块内存
	}                       //t是栈中的数据,函数结束后会自动释放
	T->pnext = NULL;
	cout << "链表的结点均删除完毕" << endl;
	cout << "----------------------------------" << endl;
}

void insert(PNODE& T) {
	PNODE Ttemp = T;
	cout << "请输入你想插入的位置: ";
	int n;
	cin >> n;
	if (n > T->data + 1 || n < 1) {
		cout << "不能在该位置上插入元素" << endl;
		return;
	}
	while (--n)//到达第n个位置的直接前驱结点,如果使用n--会到达第n个结点处
		Ttemp = Ttemp->pnext;
	PNODE temp = (PNODE)malloc(sizeof(NODE));
	cout << "请输入你想插入的数据: ";
	cin >> temp->data;
	if (n == T->data + 1) {
		T->pnext = temp;//在最后一个位置插入
		temp->pnext = NULL;//指针域直接设置为空指针
	}
	else {
		temp->pnext = Ttemp->pnext;//temp指向插入位置之后的结点
		Ttemp->pnext = temp;       //Ttemp的指针指向temp
	}
	T->data++;//链表长度+1
	return;
}

void seek(PNODE& T) {
	cout << "请输入你想查找的数据的位置: ";
	int n;
	cin >> n;
	if (n > T->data || n < 1) {
		cout << "该位置不存在" << endl;
		cout << "----------------------------------" << endl;
		return;
	}
	PNODE temp = T;
	cout << "----------------------------------" << endl;
	cout << "第" << n << "位置的元素是: ";
	while (n--)//到第n个位置
		temp = temp->pnext;

	cout << temp->data << endl;//直接输出该位置上的数据
	cout << "----------------------------------" << endl;
	return;
}

void len(PNODE& T) {
	cout << "----------------------------------" << endl;
	cout << "该链表的长度为" << T->data << endl;
	//创建时使用头结点储存了链表的长度,此处直接访问
	print(T);
	return;
}

void deleteL(PNODE& T) {
	cout << "请输入你想删除的结点位置" << endl;
	int n;
	cin >> n;
	PNODE temp = T;
	if (n > T->data) {
		cout << "该位置没有数据" << endl;
		return;
	}
	while (--n)//到达n位置的直接前驱处
		temp = temp->pnext;

B:
	cout << "该位置的数值为 " << temp->pnext->data << " 是否确定删除(Y/N): ";
	char ch;
	cin >> ch;
	if (ch == 'Y' || ch == 'y') {
		PNODE Ttemp = temp->pnext;//使用临时变量指向待删除元素
		temp->pnext = temp->pnext->pnext;//完成待删除元素的直接前驱指向其直接后继
		free(Ttemp);//释放待删除元素
		T->data--;//链表长度-1;
		cout << "删除成功" << endl;
		cout << "----------------------------------" << endl;
	}
	else if (ch == 'N' || ch == 'n')
		return;
	else
		goto B;

	return;
}