#pragma once
#include <iostream>
#include <fstream>
using namespace std;

enum RelationType { LESS, GREATER, EQUAL };
enum ContentType { PICTURE = 0, VIDEO = 1, UNKNOWN = -1 };

class ItemType {
public:
	ItemType() {}
	~ItemType() {}

	/**
	*	@brief	컨텐츠 이름을 가져옴
	*	@pre	컨텐츠 이름이 설정됨
	*	@post	없음
	*	@return	컨텐츠 이름
	*/
	string GetName() const;

	/**
	*	@brief	컨텐츠 종류를 가져옴
	*	@pre	컨텐츠 종류가 설정됨
	*	@post	없음
	*	@return	컨텐츠 종류
	*/
	ContentType GetType() const;

	/**
	*	@brief	컨텐츠 생성 날짜와 시간을 가져옴
	*	@pre	컨텐츠 생성 날짜와 시간이 설정됨
	*	@post	없음
	*	@return	컨텐츠 생성 날짜와 시간
	*/
	string GetDate() const;

	/**
	*	@brief	컨텐츠에 포함된 인물명을 가져옴
	*	@pre	컨텐츠에 포함된 인물명이 설정됨
	*	@post	없음
	*	@return	컨텐츠에 포함된 인물명
	*/
	string GetPerson() const;


	/**
	*	@brief	컨텐츠 구분을 가져옴
	*	@pre	컨텐츠 구분이 설정됨
	*	@post	없음
	*	@return	컨텐츠 구분
	*/
	int GetCategory() const;

	/**
	*	@brief	컨텐츠 이벤트명을 가져옴
	*	@pre	컨텐츠 이벤트명을 설정됨
	*	@post	없음
	*	@return	컨텐츠 이벤트명
	*/
	string GetEventName() const;

	/**
	*	@brief	컨텐츠 이름을 설정
	*	@pre	없음
	*	@post	컨텐츠 이름이 설정됨
	*	@param	inName	컨텐츠 이름
	*/
	void SetName(string inName);

	/**
	*	@brief	컨텐츠 종류를 설정
	*	@pre	없음
	*	@post	컨텐츠 종류가 설정됨
	*	@param	inType	컨텐츠 종류
	*/
	void SetType(ContentType inType);

	/**
	*	@brief	컨텐츠가 생성된 날짜와 시간을 설정
	*	@pre	없음
	*	@post	컨텐츠가 생성된 날짜와 시간이 설정됨
	*	@param	inDate	컨텐츠가 생성된 날짜와 시간
	*/
	void SetDate(string inDate);

	/**
	*	@brief	컨텐츠에 포함된 인물명을 설정
	*	@pre	없음
	*	@post	컨텐츠에 포함된 인물명이 설정됨
	*	@param	inPerson  컨텐츠에 포함된 인물명
	*/
	void SetPerson(string inPerson);

	/**
	*	@brief	컨텐츠 구분명을 설정
	*	@pre	없음
	*	@post	컨텐츠 구분이 설정됨
	*	@param	inCategory  컨텐츠 구분
	*/
	void SetCategory(int inCategory);

	/**
	*	@brief	컨텐츠 이벤트명을 설정
	*	@pre	없음
	*	@post	컨텐츠 이벤트명이 설정됨
	*	@param	inEventName	컨텐츠 이벤트명
	*/
	void SetEventName(string inEventName);

	/**
	*	@brief	콘텐츠 레코드를 설정
	*	@pre	없음
	*	@post	콘텐츠 레코드가 설정됨
	*	@param	inName	컨텐츠 이름
	*	@param	inType	컨텐츠 종류
	*	@param	inDate	컨텐츠가 생성된 날짜와 시간
	*	@param	inPerson  컨텐츠에 포함된 인물명
	*	@param	inEventName	컨텐츠 이벤트명
	*/
	void SetRecord(string inName, ContentType inType, string inDate, string inPerson, string inEventName); // 이벤트 정보 저장

	/**
	*	@brief	콘텐츠 이름을 화면에 출력
	*	@pre	콘텐츠 이름이 설정됨
	*	@post	콘텐츠 이름이 화면에 출력됨
	*/
	void DisplayNameOnScreen() const;

	/**
	*	@brief	콘텐츠 종류를 화면에 출력
	*	@pre	콘텐츠 종류가 설정됨
	*	@post	콘텐츠 종류를가 화면에 출력됨
	*/
	void DisplayTypeOnScreen() const;

	/**
	*@brief	콘텐츠 생성 날짜와 시간을 화면에 출력
	*@pre	콘텐츠 생성 날짜와 시간이 설정됨
	*@post	콘텐츠 생성 날짜와 시간이 화면에 출력됨
	*/
	void DisplayDateOnScreen() const;

	/**
	*@brief	콘텐츠에 포함된 인물명을 화면에 출력
	*@pre	콘텐츠에 포함된 인물명이 설정됨
	*@post	콘텐츠에 포함된 인물명이 화면에 출력됨
	*/
	void DisplayPersonOnScreen() const;

	/**
	*@brief	콘텐츠 구분을 화면에 출력
	*@pre	콘텐츠 구분이 설정됨
	*@post	콘텐츠 구분이 화면에 출력됨
	*/
	void DisplayCategoryOnScreen() const;

	/**
	*@brief	콘텐츠 이벤트명을 화면에 출력
	*@pre	콘텐츠 이벤트명이 설정됨
	*@post	콘텐츠 이벤트명이 화면에 출력됨
	*/
	void DisplayEventNameOnScreen() const;

	/**
	*@brief	콘텐츠 레코드를 화면에 출력
	*@pre	콘텐츠 레코드가 설정됨
	*@post	콘텐츠 레코드가 화면에 출력됨
	*/
	void DisplayRecordOnScreen() const;


	/**
	*	@brief	키보드로 콘텐츠 이름을 설정
	*	@pre	없음
	*	@post	콘텐츠 이름이 설정됨
	*/
	void SetNameFromKB();

	/**
	*	@brief	키보드로 콘텐츠 종류를 설정
	*	@pre	없음
	*	@post	콘텐츠 종류가 설정됨
	*/
	void SetTypeFromKB();

	/**
	*	@brief	키보드로 콘텐츠 생성 날짜와 시간을 설정
	*	@pre	없음
	*	@post	콘텐츠 생성 날짜와 시간이 설정됨
	*/
	void SetDateFromKB();

	/**
	*	@brief	키보드로 컨텐츠에 포함된 인물을 설정
	*	@pre	없음
	*	@post	콘텐츠에 포함된 인물이 설정됨
	*/
	void SetPersonFromKB();

	/**
	*	@brief	키보드로 컨텐츠 구분을 설정
	*	@pre	없음
	*	@post	콘텐츠 구분이 설정됨
	*/
	void SetCategoryFromKB();

	/**
	*	@brief	키보드로 콘텐츠 이벤트명을 설정
	*	@pre	없음
	*	@post	콘텐츠 이벤트명이 설정됨
	*/
	void SetEventNameFromKB();

	/**
	*	@brief	키보드로 콘텐츠 레코드를 설정
	*	@pre	없음
	*	@post	콘텐츠 레코드가 설정됨
	*/
	void SetRecordFromKB();

	/**
	*	@brief	파일로부터 레코드를 읽어들임
	*	@pre	목적으로하는 파일이 열림
	*	@post	컨텐츠 레코드가 설정됨
	*	@param	fin	파일 디스크립터
	*	@return	정상적으로 작동할시 1을 반환, 아닐시 0을 반환
	*/
	int ReadDataFromFile(ifstream& fin);

	/**
	*	@brief	파일에 레코드를 작성
	*	@pre	목적 파일이 열림, 레코드의 각 항목이 초기화 됨
	*	@post	목적파일이 새 레코드의 정보를 포함
	*	@param	fout	파일 디스크립터
	*	@return	정상적으로 작동할시 1을 반환, 아닐시 0을 반환
	*/
	int WriteDataToFile(ofstream& fout);

	/**
	*	두 itemtypes를 비교
	*	@brief	두 item type을 이름으로 비교
	*	@pre	두 item type이 초기화 됨
	*	@param	data	비교대상이 되는 itemType객체
	*	@return	return EQUAL if this.name == data.name,
	*			return LESS if this.id < data.id
	*			return GREATER if this.id > data.id
	*/
	RelationType CompareByName(const ItemType& data);

private:
	string m_cName; // 콘텐츠 파일명
	ContentType m_cType; //콘텐츠 종류
	string m_Date; // 생성날짜와 시간 YYYY/MM/DD/HH/mm으로 저장
	string m_Person; // 콘텐츠에 포함된 사람
	int m_Category; // 콘텐츠 구분
	string m_EventName; // 이벤트명
};