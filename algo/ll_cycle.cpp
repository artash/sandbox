#include <iostream>


struct Node
{
	Node* next;
	int value;
	Node(int v)
	{
		value = v;
		next = 0;
	}
};

bool hasCycle(const Node* head)
{
	const Node* slow;
	const Node* fast;
	slow = fast = head;

	while(fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
		{
			return true;
		}
	}

	return false;
}

int main()
{

	Node n1(1);
	Node n2(2);
	Node n3(3);
	Node n4(4);
	Node n5(5);
	Node n6(6);
	Node n7(7);
	Node n8(8);
	Node n9(9);

	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	n5.next = &n6;
	n6.next = &n7;
	n7.next = &n8;
	n8.next = &n9;
	n9.next = &n4;

	bool cyclic = hasCycle(&n1);

	std::cout << "list has " << (cyclic ? "" : "no ") << "cycles" << std::endl;;

	return 0;

}
