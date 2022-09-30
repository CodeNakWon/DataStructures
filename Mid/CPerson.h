#pragma once

class Person: public Group
{
public:
	/**
	*	@brief	키보드로 인물명을 설정
	*	@pre	없음
	*	@post	인물명이 설정됨
	*/
	void SetTitlefromKB() override;


	/**
	*	@brief	키보드로 인물 설명을 설정
	*	@pre	없음
	*	@post	인물 설명이 설정됨
	*/
	void SetDescriptionfromKB() override;


	/**
	*@brief	인물명을 화면에 출력
	*@pre	인물명이 설정됨
	*@post	인물명이 화면에 출력됨
	*/
	void DisplayTitle() override;


	/**
	*@brief	인물 설명을 화면에 출력
	*@pre	없음.
	*@post	인물 설명이 화면에 출력됨
	*/
	void DisplayDescriptionOnScreen() override;


	/**
	*@brief	인물 정보를 화면에 출력
	*@pre	인물 레코드가 초기화 됨
	*@post	인물 정보가 화면에 출력됨
	*/
	void DisplayRecordOnScreen() override;

};

