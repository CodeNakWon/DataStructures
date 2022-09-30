#pragma once

template <typename T>
class CircularQueueType
{
private:
	int m_iFront; // ���� ť�� front index
	int m_iRear; // ���� ť�� rear index
	int m_nMaxQueue; // ���� ť�� �ִ�ũ��
	T* m_pItems; // item pointer

public:

	/**
	*	@brief	������, �⺻ũ��� ���� ť�� ����.
	*	@pre	����.
	*	@post	���� ť�� ������, �޸𸮰� �����Ҵ��.
	*/
	CircularQueueType();

	/**
	*	@brief	������, �������� ���� ť�� ����.
	*	@pre	����.
	*	@post	���� ť�� ������, �޸𸮰� �����Ҵ��.
	*	@param	max		������ ���� ť�� ũ��
	*/
	CircularQueueType(int max);

	/**
	*	@brief	�Ҹ���, �����ڿ��� �Ҵ��� �޸� ����
	*	@pre	���� ť�� ����
	*	@post	���� ť�� �Ҹ��. �޸� �Ҵ�����.
	*/
	~CircularQueueType();

	/**
	*	@brief	���� ť�� ���� á���� Ȯ��
	*	@pre	���� ť�� �ʱ�ȭ.\
	*	@post	����.
	*	@return	���� ť�� ���� á���� true, �׷��� ������ false�� ��ȯ.
	*/
	bool IsFull();

	/**
	*	@brief	���� ť�� ������� Ȯ��
	*	@pre	���� ť�� �ʱ�ȭ.
	*	@post	����.
	*	@return	���� ť�� ������� true, �׷��� ������ false�� ��ȯ.
	*/
	bool IsEmpty();

	/**
	*	@brief	���� ť�� ���
	*	@pre	����.
	*	@post	���� ť�� �����
	*/
	void MakeEmpty();

	/**
	*	@brief	���� ť �ȿ� ������ ������ �������� �������� �߰�
	*	@pre	���� ť�� �ʱ�ȭ
	*	@post	���� ť �������� �������� �߰���
	*	@param	item	�߰��� ������
	*/
	void EnQueue(T item);

	/**
	*	@brief	���� ť�� �ּ��� �������� �������� ����
	*	@pre	���� ť�� �ʱ�ȭ
	*	@post	���� ť���� �������� ���ŵ�, �������� ������
	*	@param	item	�������� ������ ����, �ʱ�ȭ �� �ʿ� ����
	*/
	void DeQueue(T& item);

	/**
	*	@brief	��� ť���� �����͸� ���
	*	@pre	���� ť�� �ʱ�ȭ
	*	@post	���� ť�� ��� ������ ȭ�鿡 ��µ�
	*/
	void Print();
};
template<typename T>
CircularQueueType<T>::CircularQueueType() {
	m_nMaxQueue = MAXQUEUE;
	m_iFront = MAXQUEUE - 1;
	m_iRear = MAXQUEUE - 1;
	m_pItems = new T[m_nMaxQueue];
}


// ������, �����Ҵ����� ����ť�� ����
template<typename T>
CircularQueueType<T>::CircularQueueType(int max) {
	m_nMaxQueue = max + 1;
	m_iFront = m_nMaxQueue - 1;
	m_iRear = m_nMaxQueue - 1;

	m_pItems = new T[m_nMaxQueue];
}


// �Ҹ���, �޸� �Ҵ� ����
template<typename T>
CircularQueueType<T>::~CircularQueueType() {
	delete[] m_pItems;
}

// ���� ť�� ��á���� Ȯ��
template<typename T>
bool CircularQueueType<T>::IsFull() {
	if (m_iFront == m_iRear + 1 || m_iFront + m_nMaxQueue - 1 == m_iRear) {
		return true;
	}
	return false;
}


// ���� ť�� ������� Ȯ��
template<typename T>
bool CircularQueueType<T>::IsEmpty() {
	if (m_iRear == m_iFront) {
		return true;
	}
	return false;
}


// ���� ť�� ��� 
template<typename T>
void CircularQueueType<T>::MakeEmpty() {
	m_iFront = 0;
	m_iRear = 0;
}


// ���� ť�� ������ ������ �������� �������� �߰�
template<typename T>
void CircularQueueType<T>::EnQueue(T item) {
	if (!IsFull()) {
		m_iRear++;
		if (m_iRear == m_nMaxQueue) {
			m_iRear = 0;
		}
		cout << "in_var: " << item << endl;
		m_pItems[m_iRear] = item;
		cout << "ch: " << m_pItems[m_iRear] << endl;
		return;
	}
	cout << "if full!" << endl;
}




// ���� ť �ȿ� �������� ����� �������� ť�ȿ��� ����
template<typename T>
void CircularQueueType<T>::DeQueue(T& item) {
	if (!IsEmpty()) {
		m_iFront++;
		if (m_iFront == m_nMaxQueue) {
			m_iFront = 0;

		}
		cout << m_iFront << endl;
		item = m_pItems[m_iFront];
	}
}

// ��� ť���� �����͸� ���
template<typename T>
void CircularQueueType<T>::Print() {
	int cur_Point = m_iFront;
	while (cur_Point != m_iRear) {
		cur_Point++;
		if (cur_Point == m_nMaxQueue) {
			cur_Point = 0;
		}
		cout << "value:" << m_pItems[cur_Point] << " index: " << cur_Point << endl;
	}
}