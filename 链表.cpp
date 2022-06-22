#include<iostream>
using namespace std;
typedef struct node {
	int data;
	struct node* pnext;
}*PNODE, NODE;

void Create(PNODE& T);//创建
void Destroy(PNODE& T);//销毁
void Seek(PNODE T);//查找,返回查找数值的位置
void Print(PNODE T);//打印
void Replace(PNODE T);//替换
void Insertion(PNODE T);//插入
void Delete(PNODE T);//删除
int main() {
	PNODE Head, End, List;
	Head = new NODE;
	Head->pnext = new NODE;
	List = Head->pnext;
	End = List;
	Create(End);
	Print(List);
	Seek(List);
	Replace(Head);
	Print(List);
	Insertion(Head);
	Print(List);
	Delete(Head);
	Print(List);
	/*
	让上面的函数和Destroy()远离上面的函数
	不然极可能把新添加的函数放在Destory后
	然后调试不到错误(都是泪= =)
	*/

	Destroy(List);//销毁
	return 0;
}
void Create(PNODE& T) {//创建
	int len;
	cout << "请输入你想创建的链表长度:";
	cin >> len;
	int i = 0;
	while (i < len) {
		i++;
		cout << "请输入链表第" << i << "个数据的值: ";
		cin >> T->data;
		PNODE now = new NODE;
		T->pnext = now;
		T = T->pnext;
	}
	T->pnext = NULL;//不在结尾添加空指针会使销毁释放时无法结束
	//返回到主函数中的效果应为:End->pnext==NULL
	cout << "所有链表均创建完毕" << endl;
}
void Print(PNODE T) {//打印链表所有储存的数据(无指针)
	while (T->pnext) {
		cout << T->data << ' ';
		T = T->pnext;
	}
	cout << endl;
}
void Destroy(PNODE& T) {//销毁
	PNODE temp = T->pnext;
	while (temp) {
		//	cout << T << endl;查看被释放的内存地址
		delete T;
		T = temp;
		temp = T->pnext;
	}
	//cout << T << endl;//查看最后被释放的临时变量T的地址
	//执行到此处说明temp是空指针,detele可以释放空指针
	delete temp;
	cout << "全部销毁完成" << endl;
}
void Seek(PNODE T) {//查找
	int x;
	cout << "请输入你想查找的数值:";
	cin >> x;
	for (int i = 0; T; i++) {//用i记录位置
		if (T->data == x) {
			cout << "该数的位置在链表的" << i + 1 << "个位置" << endl;
			return;
		}
		T = T->pnext;
	}
	cout << "没有找到该数" << endl;
}
void Replace(PNODE T) {//替换
	cout << "请输入你想替换的数据在链表中的位置:";
	int site;//位置,利用while和site定位数据
	cin >> site;
	while (site--)
		T = T->pnext;
	//因为形参的取值为Head,所以此处正好为第site个数值
	//如果形参为List,此处的位置会向后偏移1
	cout << "这个值为:" << T->data << endl;
	cout << "请输入替换后的数值:";
	cin >> T->data;
	cout << "替换成功" << endl;
}
void Insertion(PNODE T) {//插入
	cout << "请输入你想插入的数据位置及数据";
	int site, temp_data;
	cin >> site >> temp_data;
	site--;
	while (site--)
		T = T->pnext;
	PNODE temp = new NODE;
	temp->data = temp_data;
	temp->pnext = T->pnext;
	T->pnext = temp;
}
void Delete(PNODE T) {
	cout << "请输入你想删除的数据在链表中的位置";
	int site;
	cin >> site;
	site--;
	while (site--)
		T = T->pnext;
	PNODE temp;
	temp = T->pnext;
	T->pnext = T->pnext->pnext;
	delete temp;
}