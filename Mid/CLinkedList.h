#pragma once


template<typename T>
struct DoublyNodeType {
	T data;
	DoublyNodeType* prev;
	DoublyNodeType* next;
};


template<typename T>
class DoublySortedLinkedList {
	friend class DoublyIterator<T>;
private:
	DoublyNodeType<T>* m_pFirst;
	DoublyNodeType<T>* m_pLast;
	int m_nLength;
public:

	//생성자
	DoublySortedLinkedList() {
		m_pFirst = nullptr;
		m_pLast = nullptr;
		m_nLength = 0;
	}

	//소멸자
	~DoublySortedLinkedList() {
		MakeEmpty();// 할당 해제
	}

	/**
	*	@brief	리스트가 비었는지 확인
	*	@pre	리스트가 초기화 됨
	*	@post	없음.
	*	@return	리스가 비었으면 true, 그렇지 않으면 false를 반환
	*/
	bool IsEmpty();


	/**
	*	@brief	리스트를 비움
	*	@pre	없음
	*	@post	리스트가 비워짐
	*/
	void MakeEmpty();
	

	/**
	*	@brief	리스트의 길이를 가져온다
	*	@pre	없음
	*	@post	없음
	*	@return	리스트의 길이
	*/
	int GetLength() const;


	/**
	*	@brief	리스트에 원소를 추가
	*	@pre	없음
	*	@post	리스트에 새로운 객체가 추가됨
	*	@param	item	추가할 객체
	*	@return	추가에 성공하면 1, 같은 원소가 존재시 0을 반환
	*/
	int Add(T item);


	/**
	*	@brief	리스트에서 원소를 삭제
	*	@pre	리스트가 초기화됨
	*	@post	일치하는 데이터가 리스트에 있을 경우 삭제됨.
	*	@param	item	삭제할 객체
	*	@return 삭제할 일치하는 데이터가 있으면 삭제 후 1, 없으면 0을 반환.
	*/
	int Delete(T item);
	
	/**
	*	@brief	Primary key(학번)를 바탕으로 검색하여 해당하는 정보를 새로 채워넣음.
	*	@pre	리스트가 존재/초기화 완료되어있는 상태여야 함.
	*	@post	일치하는 데이터가 리스트에 있을 경우 새로운 데이터로 교체됨.
	*	@param	item	교체할 객체
	*	@return 교체에 성공하면 1, 없으면 0을 반환
	*/
	int Replace(T item);

	/**
	*	@brief	객체을 검색해서 가져옴
	*	@pre	리스트가 초기화됨
	*	@post	일치하는 항목을 발견하면 복사해서 가져감
	*	@param	item	검색하여 복사해서 가져갈 객체
	*	@return	해당 항목을 발견하면1, 그렇지 않으면 0을 반환
	*/
	int Get(T& item);
};


// 리스트가 비었는지 확인
template <typename T>
bool DoublySortedLinkedList<T>::IsEmpty() {
	if (m_nLength == 0) {
		return true;
	}
	else {
		return false;
	}
}

// 리스트를 비움
template <typename T>
void DoublySortedLinkedList<T>::MakeEmpty() {
	DoublyIterator<T> diter(*this);
	DoublyNodeType<T>* tmp;
	while (diter.NotNull()) { // 모든 노드 할당해제
		tmp = diter.m_pCurPointer;
		diter.Next();
		delete tmp; 
	}
	m_nLength = 0;
	m_pFirst = nullptr;
	m_pLast = nullptr;
}


// 리스트의 길이를 확인
template <typename T>
int DoublySortedLinkedList<T>::GetLength() const {
	return m_nLength;
}


// 리스트에 새로운 데이터를 추가
template <typename T>
int DoublySortedLinkedList<T>::Add(T item) {
	DoublyIterator<T> diter(*this);
	DoublyNodeType<T>* node = new DoublyNodeType<T>;
	node->prev = nullptr;
	node->next = nullptr;
	node->data = item;
	// 리스트가 비었을 때 추가
	if (m_nLength == 0) {
		m_pFirst = node;
		m_pLast = node;
		m_nLength++;
		return 1;
	}
	else {
		while (1) {
			if (diter.m_pCurPointer->data > item) {
				// 1.맨앞에 추가
				if (diter.m_pCurPointer->prev == nullptr) {
					diter.m_pCurPointer->prev = node;
					node->next = diter.m_pCurPointer;
					m_pFirst = node;
					m_nLength++;
					return 1;
				}
				// 2. 중간에 추가
				else {
					diter.m_pCurPointer->prev->next = node;
					node->prev = diter.m_pCurPointer->prev;
					diter.m_pCurPointer->prev = node;
					node->next = diter.m_pCurPointer;
					m_nLength++;
					return 1;
				}
			}
			else if (diter.m_pCurPointer->data == item) {
				// 같은 데이터를 발견시 0을 반환
				delete node;
				return 0;
			}
			else if (!diter.NextNotNull()) {
				// 3. 마지막에 추가
				diter.m_pCurPointer->next = node;
				node->prev = diter.m_pCurPointer;
				m_pLast = node;
				return 0;
			}
			diter.Next();
		}
	}
}

// 리스트에서 삭제
template <typename T>
int DoublySortedLinkedList<T>::Delete(T item) {
	DoublyIterator<T> diter(*this);
	while (diter.NotNull()) {
		if (diter.m_pCurPointer->data == item) {
			if (m_nLength == 1) { //길이가 1일때
				m_pFirst = nullptr;
				m_pLast = nullptr;
			}
			else {
				if (diter.m_pCurPointer == m_pFirst) { //첫번째 노드 삭제
					diter.m_pCurPointer->next->prev = nullptr;
					m_pFirst = diter.m_pCurPointer->next;
				}
				else if (diter.m_pCurPointer == m_pLast) { // 마지막 노드 삭제
					diter.m_pCurPointer->prev->next = nullptr;
					m_pLast = diter.m_pCurPointer->prev;
				}
				else { // 중간 노드 삭제
					diter.m_pCurPointer->next->prev = diter.m_pCurPointer->prev;
					diter.m_pCurPointer->prev->next = diter.m_pCurPointer->next;
				}
			}
			delete diter.m_pCurPointer;
			m_nLength--;
			return 1;
		}
		diter.Next();
	}
	return 0;
}


// 데이터를 리스트에서 치환
template <typename T>
int DoublySortedLinkedList<T>::Replace(T item) {
	DoublyIterator<T> diter(*this);
	while (diter.NotNull()) {
		if (diter.m_pCurPointer->data == item) {
			diter.m_pCurPointer->data = item;
			return 1;
		}
		diter.Next();
	}
	return 0;
}


// 리스트에서 검색
template <typename T>
int DoublySortedLinkedList<T>::Get(T& item) {
	DoublyIterator<T> diter(*this);
	while (diter.NotNull()) {
		if (diter.m_pCurPointer->data == item) {
			item = diter.m_pCurPointer->data;
			return 1;
		}
		diter.Next();
	}
	return 0;
}
