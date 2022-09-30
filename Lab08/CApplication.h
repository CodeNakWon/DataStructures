#pragma once

class Application
{
private:
	BinarySearchTree<Photo> m_Tree;

	
	int m_Command;
public:

	//생성자
	Application() {}

	//소멸자
	~Application() {}

	/**
	*	@brief	프로그램 드라이버
	*	@pre	프로그램이 시작됨
	*	@post	프로그램이 종료됨
	*/
	void Run();

	/**
	*	@brief	명령어를 화면에 출력 후 키보드로 입력을 받음
	*	@pre	없음
	*	@post	없음
	*	@return	사용자가 입력한 명령어
	*/
	int GetCommand();


	/**
	*	@brief	리스트 안의 모든 정보를 화면에 출력
	*	@pre	리스트가 초기화 됨
	*	@post	리스트 안의 모든 정보가 화면에 출력됨
	*/
	void DisplayAll();

	/**
	*	@brief	새로운 음악 컨텐츠를 리스트에 추가
	*	@pre	없음
	*	@post	리스트 안에 음악 컨텐츠가 추가됨
	*/
	void Add();

	void Retrieve();

	void Delete();

	void MakeEmpty();
};