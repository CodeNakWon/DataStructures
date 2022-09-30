#include "CItemType.h"
#pragma once

#define MAXSIZE 5
class ArrayList
{
public:
	ArrayList() {
		m_Length = 0;
		m_CurPointer = -1;
	}
	~ArrayList() {}

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
	int GetLength();

	/**
	*	@brief	리스트의 길이가 최대에 달했는지 확인
	*	@pre	none.
	*	@post	none.
	*	@return	리스트의 길이가 최대에 달했으면 true, 그렇지 않으면 false를 반환
	*/
	bool IsFull();

	/**
	*	@brief	리스트에 새로운 ItemType을 추가
	*	@pre	리스트가 초기화 됨
	*	@post	리스트에 새로운 레코드가 추가됨
	*	@param	data	새로 추가 할 ItemType
	*	@return	추가에 성공하면 1, 똑같은 이름의 ItemType있으면 0, 리스트가 최대치면 -1을 반환
	*/
	int Add(ItemType data);

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
	int GetNextItem(ItemType& data);

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
	int Get(ItemType& data);


	/**
	*	@brief	입력된 데이터와 같은 이름의 ItemType이 있는지 리스트안에서 찾은 후 삭제
	*	@pre	리스트가 초기화 됨
	*	@post	리스트 안의 해당 데이터가 삭제됨
	*	@param	data	찾을 데이터의 이름을 가진 ItemType
	*	@return	ItemType의 정보를 찾아 삭제하면 1을, 그러지 못하면 0을 반환
	*/
	int Delete(ItemType data);

	/**
	*	@brief	입력된 데이터와 같은 이름의 ItemType이 있는지 리스트안에서 찾은 후 치환
	*	@pre	리스트가 초기화 됨
	*	@post	리스트 안의 해당 데이터가 치환됨
	*	@param	data	찾을 데이터의 이름을 가진 ItemType
	*	@return	ItemType의 정보를 찾아 치환하면 1을, 그러지 못하면 0을 반환
	*/
	int Replace(ItemType data);
private:
	ItemType m_Array[MAXSIZE]; // 레코드 배열
	int m_Length; // 리스트에 저장된 레코드 수
	int m_CurPointer; // current pointer
};

