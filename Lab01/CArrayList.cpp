#include "CArrayList.h"


//������ ���
void ArrayList::MakeEmpty() {
	m_Length = 0;
}


// ����Ʈ�� ���̸� ��ȯ
int ArrayList::GetLength() {
	return m_Length;
}


// ����Ʈ�� ���̰� �ִ뿡 ���ߴ��� Ȯ��
bool ArrayList::IsFull() {
	if (m_Length == MAXSIZE) {
		return true;
	}
	return false;
}


// ����Ʈ�� ���ο� ItemType�� �߰�
int ArrayList::Add(ItemType data) {
	if (!this->IsFull()) {
		if (Get(data)) {
			return 0; // ���� �̸��� ������ �� 0�� ��ȯ
		}
		m_Array[m_Length] = data;
		m_Length++;
		return 1; // ���������� �߰����� �� 1�� ��ȯ
	}
	return -1; // ����Ʈ�� �̹� �� �� ���� �� -1�� ��ȯ
}


// �ݺ��ڸ� �ʱ�ȭ
void ArrayList::ResetList() {
	m_CurPointer = -1;
}


// �ݺ��ڸ� ����Ʈ�� ���� ItemType���� �ű�� �ش� ItemTpye�� ������
int ArrayList::GetNextItem(ItemType& data) {
	m_CurPointer++;
	if (m_CurPointer == m_Length) {
		return -1; // ����Ʈ�� ���̸� -1�� �ʱ�ȭ
	}
	data = m_Array[m_CurPointer];
	return m_CurPointer;
}


// ����Ʈ�� ������� Ȯ��
bool ArrayList::isEmpty() {
	if (m_Length) {
		return false;
	}
	return true;
}


// �Էµ� Itemtype�� �̸����� �ش� ���ڵ尡 �ִ��� ����Ʈ�ȿ��� ã�� �� ������
int ArrayList::Get(ItemType& data) {
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


// �Էµ� Itemtype�� �̸����� �ش� ���ڵ尡 �ִ��� ����Ʈ�ȿ��� ã�� �� ����
int ArrayList::Delete(ItemType data) {
	ItemType item;
	int index;
	ResetList();
	while (1) {
		index = GetNextItem(item);
		if (index == -1) {
			return 0;
		}
		
		if (data.CompareByName(item) == EQUAL) {
			m_Length--;
			for (int i = index; i < m_Length; i++) { 
				m_Array[i] = m_Array[i + 1];
			}
			return 1;
		}
	}
}


// �Էµ� Itemtype�� �̸����� �ش� ���ڵ尡 �ִ��� ����Ʈ�ȿ��� ã�� �� ��ü
int ArrayList::Replace(ItemType data) {
	ItemType item;
	int index;
	ResetList();
	while (1) {
		index = GetNextItem(item);
		if (index == -1) {
			return 0;
		}
		if (data.CompareByName(item) == EQUAL) {
			item = data;
			m_Array[index] = item;
			return 1;
		}
	}
}