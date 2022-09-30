#pragma once

template <typename T>
class CircularQueueType
{
private:
	int m_iFront; // 원형 큐의 front index
	int m_iRear; // 원형 큐의 rear index
	int m_nMaxQueue; // 원형 큐의 최대크기
	T* m_pItems; // item pointer

public:

	/**
	*	@brief	생성자, 기본크기로 원형 큐를 생성.
	*	@pre	없음.
	*	@post	원형 큐가 생성됨, 메모리가 동적할당됨.
	*/
	CircularQueueType();

	/**
	*	@brief	생성자, 동적으로 원형 큐를 생성.
	*	@pre	없음.
	*	@post	원형 큐가 생성됨, 메모리가 동적할당됨.
	*	@param	max		생성할 원형 큐의 크기
	*/
	CircularQueueType(int max);

	/**
	*	@brief	소멸자, 생성자에서 할당한 메모리 해제
	*	@pre	원형 큐가 생성
	*	@post	원형 큐가 소멸됨. 메모리 할당해제.
	*/
	~CircularQueueType();

	/**
	*	@brief	원형 큐가 가득 찼는지 확인
	*	@pre	원형 큐가 초기화.\
	*	@post	없음.
	*	@return	원형 큐가 가득 찼으면 true, 그렇지 않으면 false를 반환.
	*/
	bool IsFull();

	/**
	*	@brief	원형 큐가 비었는지 확인
	*	@pre	원형 큐가 초기화.
	*	@post	없음.
	*	@return	원형 큐가 비었으면 true, 그렇지 않으면 false를 반환.
	*/
	bool IsEmpty();

	/**
	*	@brief	원형 큐를 비움
	*	@pre	없음.
	*	@post	원형 큐가 비워짐
	*/
	void MakeEmpty();

	/**
	*	@brief	원형 큐 안에 공간이 있으면 마지막에 아이템을 추가
	*	@pre	원형 큐가 초기화
	*	@post	원형 큐 마지막에 아이템이 추가됨
	*	@param	item	추가할 아이템
	*/
	void EnQueue(T item);

	/**
	*	@brief	원형 큐의 최선두 아이템을 가져오고 제거
	*	@pre	원형 큐가 초기화
	*	@post	원형 큐에서 아이템이 제거됨, 아이템을 가져감
	*	@param	item	아이템을 가져올 변수, 초기화 될 필요 없음
	*/
	void DeQueue(T& item);

	/**
	*	@brief	모든 큐안의 데이터를 출력
	*	@pre	원형 큐가 초기화
	*	@post	원형 큐의 모든 정보가 화면에 출력됨
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


// 생성자, 동적할당으로 원형큐를 생성
template<typename T>
CircularQueueType<T>::CircularQueueType(int max) {
	m_nMaxQueue = max + 1;
	m_iFront = m_nMaxQueue - 1;
	m_iRear = m_nMaxQueue - 1;

	m_pItems = new T[m_nMaxQueue];
}


// 소멸자, 메모리 할당 해제
template<typename T>
CircularQueueType<T>::~CircularQueueType() {
	delete[] m_pItems;
}

// 원형 큐가 꽉찼는지 확인
template<typename T>
bool CircularQueueType<T>::IsFull() {
	if (m_iFront == m_iRear + 1 || m_iFront + m_nMaxQueue - 1 == m_iRear) {
		return true;
	}
	return false;
}


// 원형 큐가 비었는지 확인
template<typename T>
bool CircularQueueType<T>::IsEmpty() {
	if (m_iRear == m_iFront) {
		return true;
	}
	return false;
}


// 원형 큐를 비움 
template<typename T>
void CircularQueueType<T>::MakeEmpty() {
	m_iFront = 0;
	m_iRear = 0;
}


// 원형 큐에 공간이 있으면 마지막에 아이템을 추가
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




// 원형 큐 안에 아이템이 존재시 가져오고 큐안에서 삭제
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

// 모든 큐안의 데이터를 출력
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