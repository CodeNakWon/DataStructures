#pragma once
class Event: public Group{

public:

	/**
	*	@brief	키보드로 이벤트명을 설정
	*	@pre	없음
	*	@post	이벤트명이 설정됨
	*/
	void SetTitlefromKB() override;


	/**
	*	@brief	키보드로 이벤트 설명을 설정
	*	@pre	없음
	*	@post	이벤트 설명이 설정됨
	*/
	void SetDescriptionfromKB() override;


	/**
	*@brief	이벤트명을 화면에 출력
	*@pre	이벤트명이 설정됨
	*@post	이벤트명이 화면에 출력됨
	*/
	void DisplayTitle() override;


	/**
	*@brief	이벤트 설명을 화면에 출력
	*@pre	없음.
	*@post	이벤트 설명이 화면에 출력됨
	*/
	void DisplayDescriptionOnScreen() override;


	/**
	*@brief	이벤트 정보를 화면에 출력
	*@pre	이벤트 레코드가 초기화 됨
	*@post	이벤트 정보가 화면에 출력됨
	*/
	void DisplayRecordOnScreen() override;

};
