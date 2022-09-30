#pragma once

class Application
{
private:
	ifstream m_InFile;///< input file descriptor.
	ofstream m_OutFile;///< output file descriptor.
	List<Content> m_List;///< item list.
	SortedList<string> m_FVList; // 자주보는 비디오 리스트
	SortedList<string> m_FPList; // 자주보는 사진 리스트
	GroupApplication GApp = GroupApplication(m_List); // 그룹App
	int m_Command;///< current command number.
	int fview = 10;//자주보는 리스트 기준 조회수
	int order = 1; // 정렬기준
	time_t curr_time;
	struct tm curr_tm;

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
	*	@brief	콘텐츠를 입력받아 이벤트, 인물, 장소 및 마스터 리스트에 해당 데이터를 추가
	*	@pre	없음
	*	@post	이벤트, 인물, 장소 및 마스터 리스트에 해당 데이터가 추가됨
	*	@param	mc 추가할 컨텐츠
	*	@return	리스트에 추가하면 1 그렇지 않으면 0을 반환
	*/
	int Add(Content& mc);


	/**
	*	@brief	콘텐츠를 입력받아 이벤트, 인물, 장소 및 마스터 리스트에 해당 데이터를 제거
	*	@pre	없음
	*	@post	이벤트, 인물, 장소 및 마스터 리스트에 해당 데이터가 제거됨
	*	@param	mc 삭제할 컨텐츠
	*	@return	리스트에 추가하면 1 그렇지 않으면 0을 반환
	*/
	int Delete(Content& mc);


	/**
	*	@brief	새로운 레코드를 리스트에 추가
	*	@pre	없음
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
	*	@brief	이름을 입력받아서 리스트에서 해당 리스트를 이진탐색으로 찾아 화면 출력
	*	@pre	리스트가 초기화 됨
	*	@post	해당 리스트가 화면에 출력됨
	*	@return	제대로 동작하면 1, 그렇지 않으면 0을 반환
	*/
	int RetrieveContents();


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
	*	@brief	띄어쓰기 없이 ','로 구분되는 키워드를 입력받아서 해당 키워드를 가진 콘텐츠를 모두 출력
	*	@pre	리스트가 초기화 됨
	*	@post	해당 키워드를 가진 콘텐츠가 모두 출력됨
	*/
	void SearchByKeyWords();


	/**
	*	@brief	자주보는 비디오를 출력
	*	@pre	리스트가 초기화 됨
	*	@post	자주보는 비디오가 출력됨
	*/
	void FViewedVideo();


	/*
	*	@brief	자주보는 사진을 출력
	*	@pre	리스트가 초기화 됨
	*	@post	자주보는 사진이 출력됨
	*/
	void FViewedPhoto();


	/**
	*	@brief	일정조회수 이상이고, 조회수가 상위권에 속하면 자주보는 리스트에 추가
	*	@pre	Content리스트가 초기화 됨
	*	@post	자주보는 콘텐츠 리스트가 업데이트 됨
	*	@param	Content	조회수를 올릴 Content
	*/
	void UpdateView();
	

	/**
	*	@brief	자주보는 리스트에서 컨텐츠를 검색
	*	@pre	Content가 초기화 됨
	*	@post	해당컨텐츠가 화면에 출려됨
	*/
	void FViewSearch();


	/**
	*	@brief	자주보는 컨텐츠 메뉴를 출력
	*	@pre	없음
	*	@post	메뉴 목록이 화면에 출력됨
	*/
	void FavoriteMenu();


	/**
	*	@brief	Content(마스터)리스트를 정렬기준에 따라 정렬시킴
	*	@pre	Content리스트가 초기화 됨
	*	@post	Content(마스터)리스트를 정렬기준에 따라 정렬됨
	*/
	void SortMList();

};