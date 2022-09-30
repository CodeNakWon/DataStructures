#pragma once

template <class T >
class List
{
public:
	List() {
		m_Length = 0;
		m_CurPointer = -1;
		m_Maxsize = MAXLIST;
		m_Array = new T[m_Maxsize];
	}

	List(int max) {
		m_Length = 0;
		m_CurPointer = -1;
		m_Maxsize = max;
		m_Array = new T[m_Maxsize];
	}
	~List() {
		delete[] m_Array;
	}

	List(const List& obj) {//생성자
		m_Length = obj.m_Length;
		m_CurPointer = obj.m_CurPointer;
		m_Maxsize = obj.m_Maxsize;
		m_Array = new T[m_Maxsize];
		for (int i = 0; i < m_Maxsize; i++) {
			m_Array[i] = obj.m_Array[i];
		}
	}

	List& operator =(const List& obj) {//생성자
		m_Length = obj.m_Length;
		m_CurPointer = obj.m_CurPointer;
		m_Maxsize = obj.m_Maxsize;
		m_Array = new T[m_Maxsize];
		for (int i = 0; i < m_Maxsize; i++) {
			m_Array[i] = obj.m_Array[i];
		}
		return *this;
	}

	/**
	*	@brief	리스트를 비움
	*	@pre	없음
	*	@post	리스트가 비워짐
	*/
	void MakeEmpty();

	/**
	*	@brief	현재 리스트에 저장된 리스트의 개수를 가져옴
	*	@pre	none.
	*	@post	none.
	*	@return	현재 저장된 레코드의 개수를 반환
	*/
	int GetLength() const;

	/**
	*	@brief	리스트의 길이가 최대에 달했는지 확인
	*	@pre	none.
	*	@post	none.
	*	@return	리스트의 길이가 최대에 달했으면 true, 그렇지 않으면 false를 반환
	*/
	bool IsFull() const;

	/**
	*	@brief	리스트에 새로운 ItemType을 추가
	*	@pre	리스트가 초기화 됨
	*	@post	리스트에 새로운 레코드가 추가됨
	*	@param	data	새로 추가 할 ItemType
	*	@return	추가에 성공하면 1, 똑같은 이름의 ItemType있으면 0, 리스트가 최대치면 -1을 반환
	*/
	int Add(T data);

	/**
	*	@brief	현재 리스트를 읽고있는 포인터의 index를 초기화
	*	@pre	리스트가 초기화 됨
	*	@post	현재 리스트를 읽고있는 포인터의 index가 초기화됨
	*/
	void ResetList();

	/**
	*	@brief	반복자가 리스트의 다음 항목을 가리키게 하고 해당 ItemType을 가져옴
	*	@pre	리스트와 리스트 반복자가 초기화 되어야함
	*	@post	반복자가 다음 항목으로 이동함
	*	@param	data	반복자에 해당하는 ItemType을 가져감, 초기화 될 필요가 없다
	*	@return	현재 반복자의 index를 반환, 반복자가 리스트에 끝에 다다랐을 경우 -1을 반환
	*/
	int GetNextItem(T& data);

	/**
	*	@brief	리스트가 비어있는지 확인
	*	@pre	리스트가 초기화됨
	*	@post	없음
	*	@return	리스트가 비어있으면 ture, 아니면 false를 반환
	*/
	bool isEmpty();

	/**
	*	@brief	입력된 데이터와 같은 이름의 ItemType이 있는지 리스트안에서 찾은 후 가져옴
	*	@pre	리스트가 초기화 됨
	*	@post	찾은 item type의 정보를 가져옴
	*	@param	data	찾을 데이터의 이름을 가진 ItemType
	*	@return	ItemType의 정보를 찾아 가져오면 1을, 그러지 못하면 0을 반환
	*/
	int Retrieve(T& data);


	/**
	*	@brief	입력된 데이터와 같은 이름의 ItemType이 있는지 리스트안에서 찾은 후 삭제
	*	@pre	리스트가 초기화 됨
	*	@post	리스트 안의 해당 데이터가 삭제됨
	*	@param	data	찾을 데이터의 이름을 가진 ItemType
	*	@return	ItemType의 정보를 찾아 삭제하면 1을, 그러지 못하면 0을 반환
	*/
	int Delete(T data);


	/**
	*	@brief	입력된 데이터와 같은 이름의 ItemType이 있는지 리스트안에서 찾은 후 치환
	*	@pre	리스트가 초기화 됨
	*	@post	리스트 안의 해당 데이터가 치환됨
	*	@param	data	찾을 데이터의 이름을 가진 ItemType
	*	@return	ItemType의 정보를 찾아 치환하면 1을, 그러지 못하면 0을 반환
	*/
	int Replace(T data);
private:
	T* m_Array;// 레코드 배열
	int m_Length; // 리스트에 저장된 레코드 수
	int m_CurPointer; // current pointer
	int m_Maxsize;
};


//리스트를 비움
template <class T >
void List<T>::MakeEmpty() {
	m_Length = 0;
}


// 리스트의 길이를 반환
template <class T >
int List<T>::GetLength() const {
	return m_Length;
}


// 리스트의 길이가 최대에 달했는지 확인
template <class T >
bool List<T>::IsFull() const {
	if (m_Length == m_Maxsize) {
		return true;
	}
	return false;
}


// 리스트에 새로운 ItemType을 추가
template <class T >
int List<T>::Add(T data) {
	if (!IsFull()) {
		if (Retrieve(data)) {
			return -1;//중복되는 이름(primary key)가 있을경우 -1을 반환
		}
		m_Array[m_Length] = data;
		m_Length++;
		return 1;
		
	}
	return 0; // 리스트가 이미 꽉 차 있을 시 0을 반환
}


// 반복자를 초기화
template <class T >
void List<T>::ResetList() {
	m_CurPointer = -1;
}


// 반복자를 리스트의 다음 ItemType으로 옮기고 해당 ItemTpye을 가져옴
template <class T >
int List<T>::GetNextItem(T& data) {
	m_CurPointer++;
	if (m_CurPointer == m_Length) {
		return -1; // 리스트의 끝이면 -1로 초기화
	}
	data = m_Array[m_CurPointer];
	return m_CurPointer;
}


// 리스트가 비었는지 확인
template <class T >
bool List<T>::isEmpty() {
	if (m_Length) {
		return false;
	}
	return true;
}


// 입력된 Itemtype의 이름으로 해당 레코드가 있는지 리스트안에서 찾은 후 가져옴
template <class T >
int List<T>::Retrieve(T& data) {
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


// 입력된 Itemtype의 이름으로 해당 레코드가 있는지 리스트안에서 찾은 후 삭제
template <class T >
int List<T>::Delete(T data) {
	for (int i = 0; i < m_Length; i++)
	{
		if (m_Array[i] == data)
		{
			for (int j = i; j < m_Length - 1; j++)
			{
				m_Array[j] = m_Array[j + 1];
			}
			m_Length--;
			return 1;
		}
	}
	return 0;
}


// 입력된 Itemtype의 이름으로 해당 레코드가 있는지 리스트안에서 찾은 후 대체
template <class T >
int List<T>::Replace(T data) {
	T item;
	int n;
	ResetList();
	while (1) {
		n = GetNextItem(item);
		if (n == -1) {
			return 0;
		}
		if (data == item) {
			m_Array[n] = data;
			return 1;
		}
	}
}

