#include <iostream>
#include <stdexcept>
using namespace std;
#define eleType int
struct ListNode
{
	eleType  data;
	ListNode* next;
	ListNode(eleType x) : data(x),next(NULL){}//节点构造函数
};

class LinkedList
{
private:
	ListNode* head;//头节点
	int size;
public:
	LinkedList():head(NULL),size(0){}//构造函数
	~LinkedList();
	void insert(int i, eleType value);
	void remove(int i);
	ListNode* find(eleType value);
	ListNode* get(int i);
	void update(int i, eleType value);
	void print();
	

};

LinkedList::~LinkedList()//析构函数，防止构造函数的空实现
{
	ListNode* curr = head;
	while (curr != NULL)
	{
		ListNode* temp = curr;
		curr = curr->next;
		delete  temp;
	}
}

void LinkedList::insert(int i,  eleType value)
{
	if (i<0 || i>size)
	{
		throw std::out_of_range("Invalid position");//非法抛出异常
	}
	ListNode* newNode = new ListNode(value);
	if (i == 0)
	{
		newNode->next = head;
		head = newNode;//头节点
	}
	else
	{
		ListNode* curr = head;
		for (int j = 0; j < i - 1; j++)
		{
			curr = curr->next;
		}
		newNode->next = curr->next;
		curr->next = newNode;
	}
	++size;
}

void LinkedList::remove(int i)
{
	if (i < 0 || i >= size)
	{
		throw std::out_of_range("Invalid position");
	}
	if (i == 0)
	{
		ListNode* temp = head;
		head = head->next;
		delete temp;
	}
	else
	{
		ListNode* curr = head;
		for (int j = 0; j < i - 1; j++)
		{
			curr = curr->next;
		}
		ListNode* temp = curr->next;
		curr->next = temp->next;
		delete temp;
	}
	--size;
}

ListNode* LinkedList::find(eleType value)
{
	ListNode* curr = head;
	while (curr && curr->data != value)
	{
		curr = curr->next;
	}
	return curr;
}
ListNode* LinkedList::get(int i)
{
	if (i < 0 || i >= size)
	{
		throw std::out_of_range("Invalid position");
	}
	ListNode* curr = head;
	for (int j = 0; j < i; ++j)
	{
		curr = curr->next;
	}
	return curr;
}

void LinkedList::update(int i, eleType value)
{
	get(i)->data = value;
}

void LinkedList::print()
{
	ListNode* curr = head;
	while (curr)
	{
		cout << curr->data << " ";
		curr = curr->next;
	}
	cout << endl;
}
int main()
{
	LinkedList list;
	list.insert(0, 10);
	list.insert(1, 20);
	list.insert(2, 30);
	list.insert(3, 40);
	list.insert(4, 50);
	list.print();//
	list.remove(1);
	list.print();//
	list.update(2, 60);
	list.print();//？
	ListNode* Tmp = list.find(30);
	cout << Tmp->data << endl;//？？
	cout << list.get(3)->data << endl;//？？？
	return 0;
}