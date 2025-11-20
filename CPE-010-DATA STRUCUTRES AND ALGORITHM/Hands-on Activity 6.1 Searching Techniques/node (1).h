template <typename T>
class Node{
	public:
		T data;
		Node *next;
	template <typename T>
	Node<T> *newNode = new Node<T>;
	newNode->data = newData;
	newNode->next = NULL;
	return newNode;
};
