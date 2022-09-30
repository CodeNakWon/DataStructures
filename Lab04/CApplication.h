#pragma once

class Application
{
public:
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
	*	@brief	새로운 레코드를 리스트에 추가
	*	@pre	리스트가 초가화됨
	*	@post	새로운 레코드가 리스트에 추가됨
	*	@return	정상적으로 작동하면 1, 그렇지 않으면 0을 반환함
	*/
	int AddContents();
	
	/**
	*	@brief	파일 입력을 위해 파일을 파일 디스크립터로 연다
	*	@pre	읽을 파일이 존재함
	*	@post	읽기 위해 파일이 열림
	*	@param	fileName	읽기 위한 파일 이름
	*	@return	제대로 동작하면 1, 그렇지 않으면 0을 반환
	*/
	int OpenInFile(char* fileName);

	/**
	*	@brief	파일 출력을 위해 파일을 파일 디스크립터로 연다
	*	@pre	쓰기를 할 파일이 존재함
	*	@post	쓰기 위해 파일이 열림
	*	@param	fileName	쓰기 위한 파일 이름
	*	@return	제대로 동작하면 1, 그렇지 않으면 0을 반환
	*/
	int OpenOutFile(char* fileName);

	/**
	*	@brief	파일을 열어 읽고 파일의 데이터를 기반으로 리스트에 저장
	*	@pre	파일이 열리지 않음
	*	@post	리스트가 파일의 데이터를 저장함
	*	@return	제대로 동작하면 1, 그렇지 않으면 0을 반환
	*/
	int ReadDataFromFile();

	/**
	*	@brief	파일을 열고 리스트의 데이터를 파일에 쓴다.
	*	@pre	파일이 열리지 않음
	*	@post	리스트가 파일에 저장됨
	*	@return	제대로 동작하면 1, 그렇지 않으면 0을 반환
	*/
	int WriteDataToFile();

	/**
	*	@brief	콘텐츠의 이름을 입력 받아 리스트에서 삭제
	*	@pre	리스트가 초기화 됨
	*	@post	리스트에서 해당 콘텐츠 레코드가 삭제됨
	*	@return	제대로 동작하면 1, 그렇지 않으면 0을 반환
	*/
	int DeleteContents();	

	/**
	*	@brief	콘텐츠의 정보를 새로 입력된 정보로 갱신
	*	@pre	리스트가 초기화 됨
	*	@post	리스트에서 해당 콘텐츠 레코드가 대체됨
	*	@return	제대로 동작하면 1, 그렇지 않으면 0을 반환
	*/
	int ReplaceContents();

	/**
	*	@brief	이름을 입력받아서 리스트에서 해당 리스트를 찾아 화면 출력
	*	@pre	리스트가 초기화 됨
	*	@post	해당 리스트가 화면에 출력됨
	*	@return	제대로 동작하면 1, 그렇지 않으면 0을 반환
	*/
	int RetrieveContents();

	/**
	*	@brief	이름을 입력받아서 리스트에서 해당 리스트를 이진탐색으로 찾아 화면 출력
	*	@pre	리스트가 초기화 됨
	*	@post	해당 리스트가 화면에 출력됨
	*	@return	제대로 동작하면 1, 그렇지 않으면 0을 반환
	*/
	int RetrieveContents_Binary();

	/**
	*	@brief	리스트 안의 모든 정보를 화면에 출력
	*	@pre	리스트가 초기화 됨
	*	@post	리스트 안의 모든 정보가 화면에 출력됨
	*/
	void DisplayAllContents();

	/**
	*	@brief	리스트를 비움
	*	@pre	없음
	*	@post	리스트가 비워짐
	*/
	int MakeEmpty();

	/**
	*	@brief	이름을 입력받고 해당 이름이 포함된 모든 항목을 출력 
	*	@pre	리스트가 초기화 됨
	*	@post	해당 이름이 포함된 모든 항목을 화면에 출력됨
	*/
	int SearchByName();

	/**
	*	@brief	콘텐츠에 포함된 사람을 입력받아서 그 사람이 들어있는 모든 콘텐츠의 자세한 정보를 화면에 출력 
	*	@pre	리스트가 초기화 됨
	*	@post	해당 콘텐츠에 포함된 사람이 포함된 모든 항목을 화면에 출력됨
	*/
	int SearchByPerson();

	/**
	*	@brief	이벤트 메뉴를 출력 
	*	@pre	event가 초기화됨
	*	@post	이벤트 메뉴가 화면에 출력됨
	*/
	void EventMenu();
	
	/**
	*	@brief	이벤트 설명을 수정
	*	@pre	event가 초기화됨
	*	@post	이벤트 설명이 수정됨
	*/
	void ModifyEvent();

	/**
	*	@brief	이벤트 리스트에서 이벤트를 찾아 정보를 출력
	*	@pre	이벤트 리스트가 초기화됨
	*	@post	해당 이벤트 정보가 출력됨
	*/
	void FindNDisplayEvent();

	/**
	*	@brief	이벤트 설명을 수정
	*	@pre	event가 초기화됨
	*	@post	이벤트 설명이 수정됨
	*/
	void DisplayAllEvents();

	/**
	*	@brief	콘텐츠를 입력받아 이벤트, 인물, 장소 및 마스터 리스트에 해당 데이터를 추가
	*	@pre	없음
	*	@post	이벤트, 인물, 장소 및 마스터 리스트에 해당 데이터가 추가됨
	*	@param	mc 추가할 컨텐츠
	*	@return	리스트에 추가하면 1 그렇지 않으면 0을 반환
	*/
	int Add(MultimediaContent &mc);

	/**
	*	@brief	콘텐츠를 입력받아 이벤트, 인물, 장소 및 마스터 리스트에 해당 데이터를 제거
	*	@pre	없음
	*	@post	이벤트, 인물, 장소 및 마스터 리스트에 해당 데이터가 제거됨
	*	@param	mc 삭제할 컨텐츠
	*	@return	리스트에 추가하면 1 그렇지 않으면 0을 반환
	*/
	int Delete(MultimediaContent& mc);


private:
	ifstream m_InFile;///< input file descriptor.
	ofstream m_OutFile;///< output file descriptor.
	SortedList<MultimediaContent> m_List;///< item list.
	int m_Command;///< current command number.
	Application_FC m_appFC;// FC관리
	SortedLinkedList<Event> eventList;
};