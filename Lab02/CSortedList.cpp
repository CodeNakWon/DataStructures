#include "CSortedList.h"


//리스를 비움
void SortedList::MakeEmpty() {
	m_Length = 0;
}


// 리스트의 길이를 반환
int SortedList::GetLength() const {
	return m_Length;
}


// 리스트의 길이가 최대에 달했는지 확인
bool SortedList::IsFull() const {
	if (m_Length == MAXSIZE) {
		return true;
	}
	return false;
}


// 리스트에 새로운 ItemType을 추가
int SortedList::Add(ItemType data) {
	if (!this->IsFull()) {
		if (Retrieve_Binary(data)) {
			return -1;//중복되는 이름(primary key)가 있을경우 -1을 반환
		}
		ItemType item;
		int index;
		ResetList();
		while (1) {
			index = GetNextItem(item);
			if (index == -1) { // 리스트가 비었거나 끝에 다하면 리스트 맨 마지막에 레코드를 추가
				index = m_Length;
				m_Array[index] = data;
				m_Length++;
				return 1;
			}
			if (data.CompareByName(item) == LESS) { // 리스트 안의 원소와 추가하려는 아이템을 primary key인 이름과 비교해서
				for (int i = m_Length; i > index; i--) {
					m_Array[i] = m_Array[i - 1];
				}
				m_Array[index] = data;
				m_Length++;
				return 1;
			}
		}
	}
	return 0; // 리스트가 이미 꽉 차 있을 시 0을 반환
}


// 반복자를 초기화
void SortedList::ResetList() {
	m_CurPointer = -1;
}


// 반복자를 리스트의 다음 ItemType으로 옮기고 해당 ItemTpye을 가져옴
int SortedList::GetNextItem(ItemType& data) {
	m_CurPointer++;
	if (m_CurPointer == m_Length) {
		return -1; // 리스트의 끝이면 -1로 초기화
	}
	data = m_Array[m_CurPointer];
	return m_CurPointer;
}


// 리스트가 비었는지 확인
bool SortedList::isEmpty() {
	if (m_Length) {
		return false;
	}
	return true;
}


// 입력된 Itemtype의 이름으로 해당 레코드가 있는지 리스트안에서 찾은 후 가져옴
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

// 입력된 Itemtype의 이름으로 해당 레코드가 있는지 리스트안에서 이진탐색으로 찾은 후 가져옴
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

// 입력된 Itemtype의 이름으로 해당 레코드가 있는지 리스트안에서 찾은 후 삭제
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


// 입력된 Itemtype의 이름으로 해당 레코드가 있는지 리스트안에서 찾은 후 대체
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

