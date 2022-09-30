#include "CArrayList.h"


//리스를 비움
void ArrayList::MakeEmpty() {
	m_Length = 0;
}


// 리스트의 길이를 반환
int ArrayList::GetLength() {
	return m_Length;
}


// 리스트의 길이가 최대에 달했는지 확인
bool ArrayList::IsFull() {
	if (m_Length == MAXSIZE) {
		return true;
	}
	return false;
}


// 리스트에 새로운 ItemType을 추가
int ArrayList::Add(ItemType data) {
	if (!this->IsFull()) {
		if (Get(data)) {
			return 0; // 같은 이름이 존재할 시 0을 반환
		}
		m_Array[m_Length] = data;
		m_Length++;
		return 1; // 정상적으로 추가했을 시 1을 반환
	}
	return -1; // 리스트가 이미 꽉 차 있을 시 -1을 반환
}


// 반복자를 초기화
void ArrayList::ResetList() {
	m_CurPointer = -1;
}


// 반복자를 리스트의 다음 ItemType으로 옮기고 해당 ItemTpye을 가져옴
int ArrayList::GetNextItem(ItemType& data) {
	m_CurPointer++;
	if (m_CurPointer == m_Length) {
		return -1; // 리스트의 끝이면 -1로 초기화
	}
	data = m_Array[m_CurPointer];
	return m_CurPointer;
}


// 리스트가 비었는지 확인
bool ArrayList::isEmpty() {
	if (m_Length) {
		return false;
	}
	return true;
}


// 입력된 Itemtype의 이름으로 해당 레코드가 있는지 리스트안에서 찾은 후 가져옴
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


// 입력된 Itemtype의 이름으로 해당 레코드가 있는지 리스트안에서 찾은 후 삭제
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


// 입력된 Itemtype의 이름으로 해당 레코드가 있는지 리스트안에서 찾은 후 대체
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