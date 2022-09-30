#pragma once

template<typename T>
struct DoublyNodeType {
	T data;
	DoublyNodeType* prev;
	DoublyNodeType* next;
};


template<typename T>
class DoublyLinkedList {
	friend class DoublyIterator<T>;
private:
	DoublyNodeType<T>* m_pFirst;
	DoublyNodeType<T>* m_pLast;
	int m_nLength;
public:

	//������
	DoublyLinkedList() {
		m_pFirst = nullptr;
		m_pLast = nullptr;
		m_nLength = 0;
	}

	//�Ҹ���
	~DoublyLinkedList() {
		MakeEmpty();// �Ҵ� ����
	}

	/**
	*	@brief	����Ʈ�� ������� Ȯ��
	*	@pre	����Ʈ�� �ʱ�ȭ ��
	*	@post	����.
	*	@return	������ ������� true, �׷��� ������ false�� ��ȯ
	*/
	bool IsEmpty();


	/**
	*	@brief	����Ʈ�� ���
	*	@pre	����
	*	@post	����Ʈ�� �����
	*/
	void MakeEmpty();


	/**
	*	@brief	����Ʈ�� ���̸� �����´�
	*	@pre	����
	*	@post	����
	*	@return	����Ʈ�� ����
	*/
	int GetLength() const;


	/**
	*	@brief	����Ʈ�� ���Ҹ� �߰�
	*	@pre	����
	*	@post	����Ʈ�� ���ο� ��ü�� �߰���
	*	@param	item	�߰��� ��ü
	*	@return	�߰��� �����ϸ� 1, ���� ���Ұ� ����� 0�� ��ȯ
	*/
	int Add(T item);


	/**
	*	@brief	����Ʈ���� ���Ҹ� ����
	*	@pre	����Ʈ�� �ʱ�ȭ��
	*	@post	��ġ�ϴ� �����Ͱ� ����Ʈ�� ���� ��� ������.
	*	@param	item	������ ��ü
	*	@return ������ ��ġ�ϴ� �����Ͱ� ������ ���� �� 1, ������ 0�� ��ȯ.
	*/
	int Delete(T item);

	/**
	*	@brief	Primary key(�й�)�� �������� �˻��Ͽ� �ش��ϴ� ������ ���� ä������.
	*	@pre	����Ʈ�� ����/�ʱ�ȭ �Ϸ�Ǿ��ִ� ���¿��� ��.
	*	@post	��ġ�ϴ� �����Ͱ� ����Ʈ�� ���� ��� ���ο� �����ͷ� ��ü��.
	*	@param	item	��ü�� ��ü
	*	@return ��ü�� �����ϸ� 1, ������ 0�� ��ȯ
	*/
	int Replace(T item);

	/**
	*	@brief	��ü�� �˻��ؼ� ������
	*	@pre	����Ʈ�� �ʱ�ȭ��
	*	@post	��ġ�ϴ� �׸��� �߰��ϸ� �����ؼ� ������
	*	@param	item	�˻��Ͽ� �����ؼ� ������ ��ü
	*	@return	�ش� �׸��� �߰��ϸ�1, �׷��� ������ 0�� ��ȯ
	*/
	int Get(T& item);
};


// ����Ʈ�� ������� Ȯ��
template <typename T>
bool DoublyLinkedList<T>::IsEmpty() {
	if (m_nLength == 0) {
		return true;
	}
	else {
		return false;
	}
}

// ����Ʈ�� ���
template <typename T>
void DoublyLinkedList<T>::MakeEmpty() {
	DoublyIterator<T> diter(*this);
	DoublyNodeType<T>* tmp;
	while (diter.NotNull()) { // ��� ��� �Ҵ�����
		tmp = diter.m_pCurPointer;
		diter.Next();
		delete tmp;
	}
	m_nLength = 0;
	m_pFirst = nullptr;
	m_pLast = nullptr;
}


// ����Ʈ�� ���̸� Ȯ��
template <typename T>
int DoublyLinkedList<T>::GetLength() const {
	return m_nLength;
}


// ����Ʈ�� ���ο� �����͸� �߰�
template <typename T>
int DoublyLinkedList<T>::Add(T item) {
	DoublyIterator<T> diter(*this);
	DoublyNodeType<T>* node = new DoublyNodeType<T>;
	node->prev = nullptr;
	node->next = nullptr;
	node->data = item;
	// ����Ʈ�� ����� �� �߰�
	if (m_nLength == 0) {
		m_pFirst = node;
		m_pLast = node;
		m_nLength++;
		return 1;
	}
	else {
		while (1) {
			if (!diter.NextNotNull()) {
				//  �������� �߰�
				diter.m_pCurPointer->next = node;
				node->prev = diter.m_pCurPointer;
				m_pLast = node;
				return 0;
			}
			diter.Next();
		}
	}
}

// ����Ʈ���� ����
template <typename T>
int DoublyLinkedList<T>::Delete(T item) {
	DoublyIterator<T> diter(*this);
	while (diter.NotNull()) {
		if (diter.m_pCurPointer->data == item) {
			if (m_nLength == 1) { //���̰� 1�϶�
				m_pFirst = nullptr;
				m_pLast = nullptr;
			}
			else {
				if (diter.m_pCurPointer == m_pFirst) { //ù��° ��� ����
					diter.m_pCurPointer->next->prev = nullptr;
					m_pFirst = diter.m_pCurPointer->next;
				}
				else if (diter.m_pCurPointer == m_pLast) { // ������ ��� ����
					diter.m_pCurPointer->prev->next = nullptr;
					m_pLast = diter.m_pCurPointer->prev;
				}
				else { // �߰� ��� ����
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


// �����͸� ����Ʈ���� ġȯ
template <typename T>
int DoublyLinkedList<T>::Replace(T item) {
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


// ����Ʈ���� �˻�
template <typename T>
int DoublyLinkedList<T>::Get(T& item) {
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
