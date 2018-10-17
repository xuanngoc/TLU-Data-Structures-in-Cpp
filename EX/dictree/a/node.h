struct Node
{
	char ch;
	Node *next;
	Node *child;

	Node()
	{
		next = child =0;
	}
	Node(char _ch)
	{
		ch = _ch;
		next = child =0;
	}
};