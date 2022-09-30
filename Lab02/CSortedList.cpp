#include "CSortedList.h"


//������ ���
void SortedList::MakeEmpty() {
	m_Length = 0;
}


// ����Ʈ�� ���̸� ��ȯ
int SortedList::GetLength() const {
	return m_Length;
}


// ����Ʈ�� ���̰� �ִ뿡 ���ߴ��� Ȯ��
bool SortedList::IsFull() const {
	if (m_Length == MAXSIZE) {
		return true;
	}
	return false;
}


// ����Ʈ�� ���ο� ItemType�� �߰�
int SortedList::Add(ItemType data) {
	if (!this->IsFull()) {
		if (Retrieve_Binary(data)) {
			return -1;//�ߺ��Ǵ� �̸�(primary key)�� ������� -1�� ��ȯ
		}
		ItemType item;
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
			if (data.CompareByName(item) == LESS) { // ����Ʈ ���� ���ҿ� �߰��Ϸ��� �������� primary key�� �̸��� ���ؼ�
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
void SortedList::ResetList() {
	m_CurPointer = -1;
}


// �ݺ��ڸ� ����Ʈ�� ���� ItemType���� �ű�� �ش� ItemTpye�� ������
int SortedList::GetNextItem(ItemType& data) {
	m_CurPointer++;
	if (m_CurPointer == m_Length) {
		return -1; // ����Ʈ�� ���̸� -1�� �ʱ�ȭ
	}
	data = m_Array[m_CurPointer];
	return m_CurPointer;
}


// ����Ʈ�� ������� Ȯ��
bool SortedList::isEmpty() {
	if (m_Length) {
		return false;
	}
	return true;
}


// �Էµ� Itemtype�� �̸����� �ش� ���ڵ尡 �ִ��� ����Ʈ�ȿ��� ã�� �� ������
int SortedList::Retrieve(ItemType& data) {
	ItemType item;
	ResetList();
	while (GetNextItem(item)!=-1) {
		if (data.CompareByName(item) == EQUAL) {
			data = item;
			return 1;
		}
	}
	return 0;
}

// �Էµ� Itemtype�� �̸����� �ش� ���ڵ尡 �ִ��� ����Ʈ�ȿ��� ����Ž������ ã�� �� ������
int SortedList::Retrieve_Binary(ItemType& data) {
	if (m_Length) {
		int stPoint = 0;
		int endPoint = m_Length - 1;
		int benchmark;
		while (1) {
			benchmark = (stPoint + endPoint) / 2;
			if (stPoint > endPoint) {
				break;
			}
			if (m_Array[benchmark].CompareByName(data) == LESS) {
				stPoint = benchmark + 1;
			}
			else if (m_Array[benchmark].CompareByName(data) == GREATER) {
				endPoint = benchmark - 1;
			}
			else if (m_Array[benchmark].CompareByName(data) == EQUAL) {
				data = m_Array[benchmark];
				return 1;
			}
		}
	}
	return 0;
}

// �Էµ� Itemtype�� �̸����� �ش� ���ڵ尡 �ִ��� ����Ʈ�ȿ��� ã�� �� ����
int SortedList::Delete(ItemType data) {
	if (m_Length) {
		int stPoint = 0;
		int endPoint = m_Length - 1;
		int benchmark;
		while (1) {
			benchmark = (stPoint + endPoint) / 2;
			if (stPoint > endPoint) {
				break;
			}
			if (m_Array[benchmark].CompareByName(data) == LESS) {
				stPoint = benchmark + 1;
			}
			else if (m_Array[benchmark].CompareByName(data) == GREATER) {
				endPoint = benchmark - 1;
			}
			else if (m_Array[benchmark].CompareByName(data) == EQUAL) {
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
int SortedList::Replace(ItemType data) {
	if (m_Length) {
		int stPoint = 0;
		int endPoint = m_Length - 1;
		int benchmark;
		while (1) {
			benchmark = (stPoint + endPoint) / 2;
			if (stPoint > endPoint) {
				break;
			}
			if (m_Array[benchmark].CompareByName(data) == LESS) {
				stPoint = benchmark + 1;
			}
			else if (m_Array[benchmark].CompareByName(data) == GREATER) {
				endPoint = benchmark - 1;
			}
			else if (m_Array[benchmark].CompareByName(data) == EQUAL) {
				m_Array[benchmark] = data;
				return 1;
			}
		}
	}
	return 0;
}

