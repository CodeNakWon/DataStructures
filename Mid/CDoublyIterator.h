#pragma once

template <typename T>
class DoublySortedLinkedList;
template <typename T>
struct DoublyNodeType;

template<typename T>
class DoublyIterator {

	friend class DoublySortedLinkedList<T>;

private:
	const DoublySortedLinkedList<T>& m_List;
	DoublyNodeType<T>* m_pCurPointer;
public:

	// 생성자
	DoublyIterator(const DoublySortedLinkedList < T>& list) : m_List(list), m_pCurPointer(list.m_pFirst) {}


	/**
	*	@brief	현재 노드를 가리키는 포인터가 null인지 아닌지 판단
	*	@pre	iterator가 초기화 됨
	*	@post	None.
	*	@return	nullptr이면 true, 그렇지 않으면 false.
	*/
	bool NotNull();
	

	/**
	*	@brief	다음 노드를 가리키는 포인터가 null인지 아닌지 판단
	*	@pre	iterator가 초기화 됨
	*	@post	None.
	*	@return	nullptr이면 true, 그렇지 않으면 false.
	*/
	bool NextNotNull();


	/**
	*	@brief 포인터가 첫번째노드로 이동하며 해당 노드를 반환
	*	@pre	iterator가 초기화 됨
	*	@post	포인터가 첫번째 노드로 이동
	*	@return	첫번째 노드를 반환
	*/
	T First();


	/**
	*	@brief	포인터가 다음 노드로 이동하며 해당노드를 반환
	*	@pre	iterator가 초기화 됨
	*	@post	포인터가 다음 노드로 이동
	*	@return	리스트의 다음 노드
	*/
	T Next();


	/**
	*	@brief	포인터가 가르키는 노드를 가져옴
	*	@pre	iterator가 초기화 됨
	*	@post	포인터가 가르키는 노드가 반환됨
	*	@return	포인터가 가르키는 노드
	*/
	DoublyNodeType<T> GetCurrentNode();

};

// 현재 노드가 nullptr인지 확인
template<class T>
bool DoublyIterator<T>::NotNull() {
	if (m_pCurPointer == nullptr) {
		return false;
	}
	else {
		return true;
	}
}

// 다음노드가 nullptr인지 확인
template<class T>
bool DoublyIterator<T>::NextNotNull() {
	if (m_pCurPointer->next != nullptr) {
		return true;
	}
	else {
		return false;
	}
}


// 포인터를 첫번째 노드로 이동시키고 해당 노드를 반환
template<class T>
T DoublyIterator<T>::First() {
	if (m_List.IsEmpty()) {
		m_pCurPointer = m_List.m_pFirst;
		return m_pCurPointer->data;
	}
}

// 포인터를 다음 노드로 이동시키고 해당 노드를 반환
template<class T>
T DoublyIterator<T>::Next() {
	T output = m_pCurPointer->data;
	if (NotNull()) {
		m_pCurPointer = m_pCurPointer->next;
	}
	return output;
}

// 현재 노드를 반환
template<class T>
DoublyNodeType<T> DoublyIterator<T>::GetCurrentNode() {
	if (m_pCurPointer != nullptr) {
		return *m_pCurPointer;
	}
}