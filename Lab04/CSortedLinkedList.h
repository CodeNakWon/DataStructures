#pragma once
template <typename T>
struct NodeType
{
	T info; // ��忡�� ������ ���ڵ�
	NodeType* next; // ���� ��带 ����Ű�� ������
};


template <typename T>
class SortedLinkedList
{
public:
	SortedLinkedList(); // Constructor
	~SortedLinkedList(); // Destructor
	void MakeEmpty(); // List�� ���..
	int GetLength() const; // ����Ʈ�� �����ϰ� �ִ� item ���� ��ȯ
	int Add(T item); // ���ο� ���ڵ带 ����Ʈ�� ����.
	int Delete(T item);
	int Retrieve(T& item); // Primary key�� �������� �����͸� �˻��ϰ� �ش� �����͸� ������
	int Replace(T item);
	void ResetList(); // ���ڵ� ������ �ʱ�ȭ
	void GetNextItem(T& item); // Current Pointer �� ���� node �� ����Ű���� �̵� �� �ش� ���ڵ带 ������.
private:
	NodeType<T>* m_pList; // ����Ʈ ������
	NodeType<T>* m_pCurPointer; // current pointer
	int m_nLength; // ����Ʈ�� ����� ���ڵ� ��
};


template<typename T>
SortedLinkedList<T>::SortedLinkedList() {
	m_nLength = 0;
	m_pList = NULL;
	m_pCurPointer = NULL;
}



template<typename T>
SortedLinkedList<T>::~SortedLinkedList() {
	MakeEmpty();
}

template<typename T>
void SortedLinkedList<T>::MakeEmpty() {
	NodeType<T>* tmp;
	while (m_pList != NULL)
	{
		tmp = m_pList;
		m_pList = m_pList->next;
		delete tmp;
	}
	m_nLength = 0;
}

template <typename T>
int SortedLinkedList<T>::Add(T item) {
	ResetList();
	NodeType<T>* newItem = new NodeType<T>;
	NodeType<T>* pre;
	newItem->info = item;
	newItem->next = NULL;
	T tmp;

	if (m_nLength == 0) {
		m_pList = newItem;
		m_nLength++;
		return 1;
	}

	while (1) {
		pre = m_pCurPointer;
		GetNextItem(tmp);
		if (tmp > item) {
			if (pre == NULL) {
				newItem->next = m_pCurPointer;
				m_pList = newItem;
				break;
			}
			else {
				newItem->next = m_pCurPointer;
				pre->next = newItem;
				break;
			}
		}
		if (m_pCurPointer->next == NULL)
		{
			m_pCurPointer->next = newItem;
			break;
		}

	}
	m_nLength++;
	return 1;
}

template <typename T>
int SortedLinkedList<T>::Delete(T item) {
	NodeType<T>* pre = NULL;

	m_pCurPointer = m_pList;
	while (m_pCurPointer != NULL) {
		if (m_pCurPointer->info != item) {
			pre = m_pCurPointer;
			m_pCurPointer = m_pCurPointer->next;
		}
		else if (pre == NULL) {
			m_pList = m_pCurPointer->next;
			m_nLength--;
			return 1;
		}
		else {
			pre->next = m_pCurPointer->next;
			delete m_pCurPointer;
			m_nLength--;
			return 1;
		}
	}
	return 0;
}


template <typename T>
int SortedLinkedList<T>::Retrieve(T& item) {
	ResetList();
	m_pCurPointer = m_pList;
	while (m_pCurPointer != NULL) {
		if (m_pCurPointer->info == item) {
			item = m_pCurPointer->info;
			return 1;
		}
		m_pCurPointer = m_pCurPointer->next;
	}
	return 0;
}

template <typename T>
int SortedLinkedList<T>::Replace(T item) {
	ResetList();
	m_pCurPointer = m_pList;
	while (m_pCurPointer != NULL) {
		if (m_pCurPointer->info == item) {
			m_pCurPointer->info = item;
			return 1;
		}
		m_pCurPointer = m_pCurPointer->next;
	}
	return 0;
}


template <typename T>
void SortedLinkedList<T>::ResetList() {
	m_pCurPointer = NULL;
}


template <typename T>
void SortedLinkedList<T>::GetNextItem(T& item) {
	if (m_pCurPointer == NULL) {
		m_pCurPointer = m_pList;
	}
	else {
		m_pCurPointer = m_pCurPointer->next;
	}
	item = m_pCurPointer->info;
}

template<typename T>
int SortedLinkedList<T>::GetLength()const {
	return m_nLength;
}
