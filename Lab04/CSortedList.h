#pragma once

template <class T >
class SortedList
{
public:
	SortedList() {
		m_Length = 0;
		m_CurPointer = -1;
		m_Maxsize = MAXSLIST;
		m_Array = new T[m_Maxsize];
	}

	SortedList(const SortedList& obj) { //���������
		m_Length = obj.m_Length;
		m_CurPointer = obj.m_CurPointer;
		m_Maxsize = obj.m_Maxsize;
		m_Array = new T[m_Maxsize];
		for (int i = 0; i < m_Maxsize; i++) {
			m_Array[i] = obj.m_Array[i];
		}
	}

	SortedList& operator =(const SortedList& obj) { //���Կ����� �����ε�
		m_Length = obj.m_Length;
		m_CurPointer = obj.m_CurPointer;
		m_Maxsize = obj.m_Maxsize;
		m_Array = new T[m_Maxsize];
		for (int i = 0; i < m_Maxsize; i++) {
			m_Array[i] = obj.m_Array[i];
		}
		return *this;
	}

	SortedList(int max) {
		m_Length = 0;
		m_CurPointer = -1;
		m_Maxsize = max;
		m_Array = new T[m_Maxsize];
	}
	~SortedList() {
		delete[] m_Array;
	}

	/**
	*	@brief	����Ʈ�� ���
	*	@pre	����
	*	@post	����Ʈ�� �����
	*/
	void MakeEmpty();

	/**
	*	@brief	���� ����Ʈ�� ����� ����Ʈ�� ������ ������
	*	@pre	none.
	*	@post	none.
	*	@return	���� ����� ���ڵ��� ������ ��ȯ
	*/
	int GetLength() const;

	/**
	*	@brief	����Ʈ�� ���̰� �ִ뿡 ���ߴ��� Ȯ��
	*	@pre	none.
	*	@post	none.
	*	@return	����Ʈ�� ���̰� �ִ뿡 �������� true, �׷��� ������ false�� ��ȯ
	*/
	bool IsFull() const;

	/**
	*	@brief	����Ʈ�� ���ο� ItemType�� �߰�
	*	@pre	����Ʈ�� �ʱ�ȭ ��
	*	@post	����Ʈ�� ���ο� ���ڵ尡 �߰���
	*	@param	data	���� �߰� �� ItemType
	*	@return	�߰��� �����ϸ� 1, �Ȱ��� �̸��� ItemType������ 0, ����Ʈ�� �ִ�ġ�� -1�� ��ȯ
	*/
	int Add(T data);

	/**
	*	@brief	���� ����Ʈ�� �а��ִ� �������� index�� �ʱ�ȭ
	*	@pre	����Ʈ�� �ʱ�ȭ ��
	*	@post	���� ����Ʈ�� �а��ִ� �������� index�� �ʱ�ȭ��
	*/
	void ResetList();

	/**
	*	@brief	�ݺ��ڰ� ����Ʈ�� ���� �׸��� ����Ű�� �ϰ� �ش� ItemType�� ������
	*	@pre	����Ʈ�� ����Ʈ �ݺ��ڰ� �ʱ�ȭ �Ǿ����
	*	@post	�ݺ��ڰ� ���� �׸����� �̵���
	*	@param	data	�ݺ��ڿ� �ش��ϴ� ItemType�� ������, �ʱ�ȭ �� �ʿ䰡 ����
	*	@return	���� �ݺ����� index�� ��ȯ, �ݺ��ڰ� ����Ʈ�� ���� �ٴٶ��� ��� -1�� ��ȯ
	*/
	int GetNextItem(T& data);

	/**
	*	@brief	����Ʈ�� ����ִ��� Ȯ��
	*	@pre	����Ʈ�� �ʱ�ȭ��
	*	@post	����
	*	@return	����Ʈ�� ��������� ture, �ƴϸ� false�� ��ȯ
	*/
	bool isEmpty();

	/**
	*	@brief	�Էµ� �����Ϳ� ���� �̸��� ItemType�� �ִ��� ����Ʈ�ȿ��� ã�� �� ������
	*	@pre	����Ʈ�� �ʱ�ȭ ��
	*	@post	ã�� item type�� ������ ������
	*	@param	data	ã�� �������� �̸��� ���� ItemType
	*	@return	ItemType�� ������ ã�� �������� 1��, �׷��� ���ϸ� 0�� ��ȯ
	*/
	int Retrieve(T& data);


	/**
	*	@brief	�Էµ� �����Ϳ� ���� �̸��� ItemType�� �ִ��� ����Ʈ�ȿ��� ����Ž������ ã�� �� ������
	*	@pre	����Ʈ�� �ʱ�ȭ ��
	*	@post	ã�� item type�� ������ ������
	*	@param	data	ã�� �������� �̸��� ���� ItemType
	*	@return	ItemType�� ������ ã�� �������� 1��, �׷��� ���ϸ� 0�� ��ȯ
	*/
	int Retrieve_Binary(T& data);


	/**
	*	@brief	�Էµ� �����Ϳ� ���� �̸��� ItemType�� �ִ��� ����Ʈ�ȿ��� ã�� �� ����
	*	@pre	����Ʈ�� �ʱ�ȭ ��
	*	@post	����Ʈ ���� �ش� �����Ͱ� ������
	*	@param	data	ã�� �������� �̸��� ���� ItemType
	*	@return	ItemType�� ������ ã�� �����ϸ� 1��, �׷��� ���ϸ� 0�� ��ȯ
	*/
	int Delete(T& data);

	/**
	*	@brief	�Էµ� �����Ϳ� ���� �̸��� ItemType�� �ִ��� ����Ʈ�ȿ��� ã�� �� ġȯ
	*	@pre	����Ʈ�� �ʱ�ȭ ��
	*	@post	����Ʈ ���� �ش� �����Ͱ� ġȯ��
	*	@param	data	ã�� �������� �̸��� ���� ItemType
	*	@return	ItemType�� ������ ã�� ġȯ�ϸ� 1��, �׷��� ���ϸ� 0�� ��ȯ
	*/
	int Replace(T data);
private:
	T* m_Array;// ���ڵ� �迭
	int m_Length; // ����Ʈ�� ����� ���ڵ� ��
	int m_CurPointer; // current pointer
	int m_Maxsize;
};


//����Ʈ�� ���
template <class T >
void SortedList<T>::MakeEmpty() {
	m_Length = 0;
}


// ����Ʈ�� ���̸� ��ȯ
template <class T >
int SortedList<T>::GetLength() const {
	return m_Length;
}


// ����Ʈ�� ���̰� �ִ뿡 ���ߴ��� Ȯ��
template <class T >
bool SortedList<T>::IsFull() const {
	if (m_Length == m_Maxsize) {
		return true;
	}
	return false;
}


// ����Ʈ�� ���ο� ItemType�� �߰�
template <class T >
int SortedList<T>::Add(T data) {
	if (!this->IsFull()) {
		if (Retrieve_Binary(data)) {
			return -1;//�ߺ��Ǵ� �̸�(primary key)�� ������� -1�� ��ȯ
		}
		T item;
		int index;
		ResetList();
		while (1) {
			index = GetNextItem(item);
			if (index == -1) { // ����Ʈ�� ����ų� ���� ���ϸ� ����Ʈ �� �������� ���ڵ带 �߰�
				index = m_Length;
				m_Array[index] = data;
				m_Length++;
				return 1;
			}
			if (data <item) { // ����Ʈ ���� ���ҿ� �߰��Ϸ��� �������� primary key�� �̸��� ���ؼ�
				for (int i = m_Length; i > index; i--) {
					m_Array[i] = m_Array[i - 1];
				}
				m_Array[index] = data;
				m_Length++;
				return 1;
			}
		}
	}
	return 0; // ����Ʈ�� �̹� �� �� ���� �� 0�� ��ȯ
}


// �ݺ��ڸ� �ʱ�ȭ
template <class T >
void SortedList<T>::ResetList() {
	m_CurPointer = -1;
}


// �ݺ��ڸ� ����Ʈ�� ���� ItemType���� �ű�� �ش� ItemTpye�� ������
template <class T >
int SortedList<T>::GetNextItem(T& data) {
	m_CurPointer++;
	if (m_CurPointer == m_Length) {
		return -1; // ����Ʈ�� ���̸� -1�� �ʱ�ȭ
	}
	data = m_Array[m_CurPointer];
	return m_CurPointer;
}


// ����Ʈ�� ������� Ȯ��
template <class T >
bool SortedList<T>::isEmpty() {
	if (m_Length) {
		return false;
	}
	return true;
}


// �Էµ� Itemtype�� �̸����� �ش� ���ڵ尡 �ִ��� ����Ʈ�ȿ��� ã�� �� ������
template <class T >
int SortedList<T>::Retrieve(T& data) {
	T item;
	ResetList();
	while (GetNextItem(item) != -1) {
		if (data == item) {
			data = item;
			return 1;
		}
	}
	return 0;
}

// �Էµ� Itemtype�� �̸����� �ش� ���ڵ尡 �ִ��� ����Ʈ�ȿ��� ����Ž������ ã�� �� ������
template <class T >
int SortedList<T>::Retrieve_Binary(T& data) {
	if (m_Length) {
		int stPoint = 0;
		int endPoint = m_Length - 1;
		int benchmark;
		while (1) {
			benchmark = (stPoint + endPoint) / 2;
			if (stPoint > endPoint) {
				break;
			}
			if (m_Array[benchmark] < data) {
				stPoint = benchmark + 1;
			}
			else if (m_Array[benchmark] > data) {
				endPoint = benchmark - 1;
			}
			else if (m_Array[benchmark] == data) {
				data = m_Array[benchmark];
				return 1;
			}
		}
	}
	return 0;
}

// �Էµ� Itemtype�� �̸����� �ش� ���ڵ尡 �ִ��� ����Ʈ�ȿ��� ã�� �� ����
template <class T >
int SortedList<T>::Delete(T &data) {
	if (m_Length) {
		int stPoint = 0;
		int endPoint = m_Length - 1;
		int benchmark;
		while (1) {
			benchmark = (stPoint + endPoint) / 2;
			if (stPoint > endPoint) {
				break;
			}
			if (m_Array[benchmark] < data) {
				stPoint = benchmark + 1;
			}
			else if (m_Array[benchmark] > data) {
				endPoint = benchmark - 1;
			}
			else if (m_Array[benchmark]== data) {
				data = m_Array[benchmark];
				m_Length--;
				for (int i = benchmark; i < m_Length; i++) {
					m_Array[i] = m_Array[i + 1];
				}
				return 1;
			}
		}
	}
	return 0;
}


// �Էµ� Itemtype�� �̸����� �ش� ���ڵ尡 �ִ��� ����Ʈ�ȿ��� ã�� �� ��ü
template <class T >
int SortedList<T>::Replace(T data) {
	if (m_Length) {
		int stPoint = 0;
		int endPoint = m_Length - 1;
		int benchmark;
		while (1) {
			benchmark = (stPoint + endPoint) / 2;
			if (stPoint > endPoint) {
				break;
			}
			if (m_Array[benchmark] < data) {
				stPoint = benchmark + 1;
			}
			else if (m_Array[benchmark] > data) {
				endPoint = benchmark - 1;
			}
			else if (m_Array[benchmark]==data) {
				m_Array[benchmark] = data;
				return 1;
			}
		}
	}
	return 0;
}

