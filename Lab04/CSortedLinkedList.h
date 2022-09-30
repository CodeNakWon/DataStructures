#pragma once
template <typename T>
struct NodeType
{
	T info; // 노드에서 관리할 레코드
	NodeType* next; // 다음 노드를 가리키는 포인터
};


template <typename T>
class SortedLinkedList
{
public:
	SortedLinkedList(); // Constructor
	~SortedLinkedList(); // Destructor
	void MakeEmpty(); // List를 비움..
	int GetLength() const; // 리스트가 보유하고 있는 item 개수 반환
	int Add(T item); // 새로운 레코드를 리스트에 삽입.
	int Delete(T item);
	int Retrieve(T& item); // Primary key를 기준으로 데이터를 검색하고 해당 데이터를 가져옴
	int Replace(T item);
	void ResetList(); // 레코드 포인터 초기화
	void GetNextItem(T& item); // Current Pointer 가 다음 node 를 가리키도록 이동 후 해당 레코드를 가져옴.
private:
	NodeType<T>* m_pList; // 리스트 포인터
	NodeType<T>* m_pCurPointer; // current pointer
	int m_nLength; // 리스트에 저장된 레코드 수
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
