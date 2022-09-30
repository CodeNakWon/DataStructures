#pragma once

template<class T>
struct Node
{
	T data;
	Node* left;
	Node* right;
};

template<class T>
class BinarySearchTree {
private:
	Node<T>* root;

public:
	BinarySearchTree() {
		root = NULL;
	}
	~BinarySearchTree() {
		MakeEmpty();
	}

	bool IsEmpty() const;
	bool IsFull() const;
	void MakeEmpty();
	int GetLength() const;
	void Add(T item);
	void Delete(T item);
	void Retrieve(T &item, bool &found) const;
	void PrintTree(ostream& out) const;
};

template<class T>
bool BinarySearchTree<T>::IsEmpty() const {
	if (root == NULL) {
		return true;
	}
	return false;
}

template<class T>
bool BinarySearchTree<T>::IsFull() const {
	Node* room;
	try
	{
		room = new Node;
		delete room;
		return false;
	}
	catch (std::bad_alloc exception) 
	{
		return true;
	}
}



// GetLength
template<class T>
int BinarySearchTree<T>::GetLength() const {
	return CountNodes(root);
}

template<class T>
int CountNodes(Node<T>* node) {
	if (node == NULL) {
		return 0;
	}
	else {
		return CountNodes(node->left) + CountNodes(node->right) + 1;
	}
}

//Add
template<class T>
void BinarySearchTree<T>::Add(T item) {
	Insert(root, item);
}

template<class T>
void Insert(Node<T>*& node, T item) {
	if (node == NULL) {
		node = new Node<T>;
		node->data = item;
		node->right = NULL;
		node->left = NULL;
	}
	else if (node->data > item) {
		Insert(node->left, item);
	}
	else if (node->data < item) {
		Insert(node->right, item);
	}
}


//Delete
template<class T>
void BinarySearchTree<T>::Delete(T item) {
	Remove(root, item);
}

template<class T>
void Remove(Node<T>*& node, T item) {
	if (node == NULL) {
		return;
	}
	else if (node->data > item) {
		Remove(node->left, item);

	}
	else if (node->data < item) {
		Remove(node->right, item);

	}
	else if (node->data == item) {
		DeleteNode(node);
	}
}

template<class T>
void DeleteNode(Node<T> *&node) {
	T item;
	Node<T>* tmp;
	tmp = node;
	if (node->left == NULL) {
		node = node->right;
		delete tmp;
	}
	else if (node->right == NULL) {
		node = node->left;
		delete tmp;
	}
	else {
		GetPredecessor(node->left, item);
		node->data = item;
		Remove(node->left, item);
	}
}

template<class T>
void GetPredecessor(Node<T>* node, T& item) {
	while (node->right != NULL)
		node = node->right;
	item = node->data;
}


template<class T>
void BinarySearchTree<T>::Retrieve(T& item, bool& found)const{
	SearchNode(root, item, found);
}

template<class T>
void SearchNode(Node<T>* node, T& item, bool& found) {
	if (node->data < item) {
		if (node->right != NULL) {
			SearchNode(node->right, item, found);
		}
		else {
			found = false;
		}
	}
	else if (node->data > item) { // my pic // my pic --> 0xa11312313// 0xa1231231
		if (node->left != NULL) {
			SearchNode(node->left, item, found);
		}
		else {
			found = false;
		}
	}
	else {
		item = node->data;
		found = true;
	}
}


template<class T>
void BinarySearchTree<T>::MakeEmpty() {
	Destroy(root);
	root = NULL;
}

template<class T>
void Destroy(Node<T>* node) {
	if (node != NULL) {
		Destroy(node->left);
		Destroy(node->right);
		delete node;
	}
}

template<class T>
void BinarySearchTree<T>::PrintTree(ostream& out) const
{
	PrintInOrderTraversal(root);			// InOrder 방법으로 출력
}


template<class T>
void PrintInOrderTraversal(Node<T>* root)
{
	
	if (root != NULL)								// root가 존재하는 경우
	{
		PrintInOrderTraversal(root->left);		// root의 왼쪽으로 가서 다시 InOrder 함수 호출
		cout << root->data;				// root 출력
		PrintInOrderTraversal(root->right);	// root의 오른쪽으로 가서 다시 InOrder 함수 호출
	}
}