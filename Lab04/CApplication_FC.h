#pragma once
class Application_FC {
private:
	List<FavoriteContent> m_FCList;
	//SortedList<MultimediaContent> MCList;
	SortedList<string> m_nameOrder;
	int m_CommandFC;
	int m_order = 0; // 0: 들어온 순으로 보여줌, 1: 이름순으로 보여줌, 2: 
public:
	Application_FC() {};

	/**
	*	@brief	FC프로그램 드라이버
	*	@pre	FC프로그램이 시작됨
	*	@post	FC프로그램이 종료됨
	*/
	void Run(SortedList<MultimediaContent>& MCList);

	/**
	*	@brief	명령어를 화면에 출력 후 키보드로 입력을 받음
	*	@pre	없음
	*	@post	없음
	*	@return	사용자가 입력한 명령어
	*/
	int GetCommand();

	/**
	*	@brief	콘텐츠명을 입력받아 해당 리스트가 마스터 리스트에 존재하면 FC리스트에 추가
	*	@pre	없음
	*	@post	FC리스트에 해당 콘텐츠가 추가됨
	*	@param	MC 리스트
	*	@return	리스트에 추가하면 1 그렇지 않으면 0을 반환
	*/
	int Add_FC(SortedList<MultimediaContent>& MCList);


	/**
	*	@brief	콘텐츠명을 입력받아 해당 콘텐츠를 삭제
	*	@pre	FC리스트가 초기화됨
	*	@post	FC리스트에 해당 콘텐츠가 삭제됨
	*	@return	리스트에 삭제하면 1 그렇지 않으면 0을 반환
	*/
	int Delete_FC();

	/**
	*	@brief	모든 FC 정보를 출력
	*	@pre	FC리스트가 초기화됨
	*	@post	모든 FC정보가 출력됨
	*/
	void Display_FC_list();
	
	/**
	*	@brief	컨텐츠명을 입력받아 해당 FC 정보를 자세하게 출력
	*	@pre	FC리스트가 초기화됨
	*	@param	MC 리스트
	*	@post	해당 FC의 자세한 정보가 출력됨
	*/
	int Display_Detail_FC(SortedList<MultimediaContent>& MCList);

	/**
	*	@brief	컨텐츠명을 입력받아 해당 FC 정보를 자세하게 출력
	*	@pre	FC리스트가 초기화됨
	*	@param	MC 리스트
	*/
	void  Rearrange_FC();

	/**
	*	@brief  컨텐츠를 입력받아 해당 컨텐츠를 FC리스트에서 삭제
	*	@pre	FC리스트가 초기화됨
	*	@param	MC 삭제할 컨텐츠
	*	@post	해당 MC가 FC리스트에서 삭제됨
	*/
	int DeleteMContents(MultimediaContent &mc);
};
