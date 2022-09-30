#pragma once
class Location : public Group
{
public:
	/**
	*	@brief	키보드로 장소명을 설정
	*	@pre	없음
	*	@post	장소명이 설정됨
	*/
	void SetTitlefromKB() override;


	/**
	*	@brief	키보드로 장소 설명을 설정
	*	@pre	없음
	*	@post	장소 설명이 설정됨
	*/
	void SetDescriptionfromKB() override;


	/**
	*@brief	장소명을 화면에 출력
	*@pre	장소명이 설정됨
	*@post	장소명이 화면에 출력됨
	*/
	void DisplayTitle() override;


	/**
	*@brief	장소 설명을 화면에 출력
	*@pre	없음.
	*@post	장소 설명이 화면에 출력됨
	*/
	void DisplayDescriptionOnScreen() override;


	/**
	*@brief	장소 정보를 화면에 출력
	*@pre	장소 레코드가 초기화 됨
	*@post	장소 정보가 화면에 출력됨
	*/
	void DisplayRecordOnScreen() override;
};

