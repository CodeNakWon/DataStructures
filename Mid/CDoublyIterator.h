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

	// ������
	DoublyIterator(const DoublySortedLinkedList < T>& list) : m_List(list), m_pCurPointer(list.m_pFirst) {}


	/**
	*	@brief	���� ��带 ����Ű�� �����Ͱ� null���� �ƴ��� �Ǵ�
	*	@pre	iterator�� �ʱ�ȭ ��
	*	@post	None.
	*	@return	nullptr�̸� true, �׷��� ������ false.
	*/
	bool NotNull();
	

	/**
	*	@brief	���� ��带 ����Ű�� �����Ͱ� null���� �ƴ��� �Ǵ�
	*	@pre	iterator�� �ʱ�ȭ ��
	*	@post	None.
	*	@return	nullptr�̸� true, �׷��� ������ false.
	*/
	bool NextNotNull();


	/**
	*	@brief �����Ͱ� ù��°���� �̵��ϸ� �ش� ��带 ��ȯ
	*	@pre	iterator�� �ʱ�ȭ ��
	*	@post	�����Ͱ� ù��° ���� �̵�
	*	@return	ù��° ��带 ��ȯ
	*/
	T First();


	/**
	*	@brief	�����Ͱ� ���� ���� �̵��ϸ� �ش��带 ��ȯ
	*	@pre	iterator�� �ʱ�ȭ ��
	*	@post	�����Ͱ� ���� ���� �̵�
	*	@return	����Ʈ�� ���� ���
	*/
	T Next();


	/**
	*	@brief	�����Ͱ� ����Ű�� ��带 ������
	*	@pre	iterator�� �ʱ�ȭ ��
	*	@post	�����Ͱ� ����Ű�� ��尡 ��ȯ��
	*	@return	�����Ͱ� ����Ű�� ���
	*/
	DoublyNodeType<T> GetCurrentNode();

};

// ���� ��尡 nullptr���� Ȯ��
template<class T>
bool DoublyIterator<T>::NotNull() {
	if (m_pCurPointer == nullptr) {
		return false;
	}
	else {
		return true;
	}
}

// ������尡 nullptr���� Ȯ��
template<class T>
bool DoublyIterator<T>::NextNotNull() {
	if (m_pCurPointer->next != nullptr) {
		return true;
	}
	else {
		return false;
	}
}


// �����͸� ù��° ���� �̵���Ű�� �ش� ��带 ��ȯ
template<class T>
T DoublyIterator<T>::First() {
	if (m_List.IsEmpty()) {
		m_pCurPointer = m_List.m_pFirst;
		return m_pCurPointer->data;
	}
}

// �����͸� ���� ���� �̵���Ű�� �ش� ��带 ��ȯ
template<class T>
T DoublyIterator<T>::Next() {
	T output = m_pCurPointer->data;
	if (NotNull()) {
		m_pCurPointer = m_pCurPointer->next;
	}
	return output;
}

// ���� ��带 ��ȯ
template<class T>
DoublyNodeType<T> DoublyIterator<T>::GetCurrentNode() {
	if (m_pCurPointer != nullptr) {
		return *m_pCurPointer;
	}
}