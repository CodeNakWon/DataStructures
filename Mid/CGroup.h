#pragma once
class Group
{
protected:
	string m_cName;
	string m_cDes;
	int m_cLen;
	SortedList<string> m_mcList;

public:

	/**
	*	@brief	그룹 이름을 설정
	*	@pre	없음
	*	@post	그룹 이름이 설정됨
	*	@param	name 그룹 이름
	*/
	virtual void SetTitle(string name);


	/**
	*	@brief	그룹 설명을 설정
	*	@pre	없음
	*	@post	그룹 설명이 설정됨
	*	@param	des 이벤트 설명
	*/
	virtual void SetDescription(string des);


	/**
	*	@brief	그룹 이름을 가져옴
	*	@pre	그룹 이름이 설정됨
	*	@post	없음
	*	@return	이벤트 이름
	*/
	virtual string GetTitle() const;


	/**
	*	@brief	그룹 설명을 가져옴
	*	@pre	그룹 설명이 설정됨
	*	@post	없음
	*	@return	그룹 설명
	*/
	virtual string GetDescription() const;


	/**
	*	@brief	키보드로 그룹명을 설정
	*	@pre	없음
	*	@post	그룹명이 설정됨
	*/
	virtual void SetTitlefromKB();


	/**
	*	@brief	키보드로 그룹 설명을 설정
	*	@pre	없음
	*	@post	그룹 설명이 설정됨
	*/
	virtual void SetDescriptionfromKB();


	/**
	*@brief	그룹명을 화면에 출력
	*@pre	그룹명이 설정됨
	*@post	그룹명이 화면에 출력됨
	*/
	virtual void DisplayTitle();


	/**
	*@brief	그룹에 포함된 콘텐츠명을 화면에 출력
	*@pre	없음.
	*@post	그룹에 포함된 콘텐츠명이 화면에 출력됨
	*/
	virtual void DisplayIncludedContents();


	/**
	*@brief	그룹 설명을 화면에 출력
	*@pre	없음.
	*@post	그룹 설명이 화면에 출력됨
	*/
	virtual void DisplayDescriptionOnScreen();


	/**
	*@brief	그룹 정보를 화면에 출력
	*@pre	그룹 레코드가 초기화 됨
	*@post	그룹 정보가 화면에 출력됨
	*/
	virtual void DisplayRecordOnScreen();


	/**
	*	@brief	MC를 입력받아 해당MC의 이름(primary key)를 그룹 리스트에 저장
	*	@pre	리스트가 초기화 됨
	*	@post	리스트에 MC가 저장됨
	*	@param	mc	찾을 데이터의 이름을 가진 MC
	*	@return	리스트 저장에 성공하면 1, 리스트에 같은 이름이 존재하면 -1, 리스트가 꽉차있으면 0을 반환
	*/
	virtual int AddMC(Content& mc);


	/**
	*	@brief	MC를 입력받아 해당MC의 이름(primary key)를 그룹 리스트에서 찾아 삭제
	*	@pre	리스트가 초기화 됨
	*	@post	리스트에서 해당MC를 찾아 삭제
	*	@param	삭제할	데이터의 이름을 가진 MC
	*	@return	삭제에 성공하면 1, 그렇지 않으면 0을 반환
	*/
	virtual int Delete(Content& mc);


	/**
	*	@brief	MC를 입력받아 해당MC의 이름(primary key)를 그룹 리스트에서 찾음
	*	@pre	리스트가 초기화 됨
	*	@post	콘텐츠 리스트에서 해당 MC의 이름(primary key)을 찾아서 존재하면 그 이름을 가진 MC로 가져옴
	*	@param	mc	찾을 데이터의 이름을 가진 MC
	*	@return	리스트에서 해당 데이터를 찾으면 1 그렇지 않으면 0을 반환
	*/
	virtual int Retrieve(Content& mc);


	/**
	*	@brief  리스트가 비었는지 확인
	*	@pre    리스트가 초기화 됨
	*	@post	없음
	*	@return	리스트가 비어있으면 1, 그렇지 않으면 0을 반환
	*/
	virtual bool isEmpty();


	/**
	*	@brief  그룹에 속한 모든 콘텐츠의 자세한 정보를 출력
	*	@pre	그룹 리스트가 초기화됨
	*	@post	그룹에 속한 모든 콘텐츠의 자세한 정보가 츨력됨
	*	@param	lst	마스터 리스트
	*/
	virtual void DisplayDetailAll(List<Content>& lst);


	/**
	*	@brief  그룹에 속한 모든 콘텐츠의 자세한 정보를 출력
	*	@pre	콘텐츠 리스트가 초기화됨
	*	@post	그룹에 속한 모든 콘텐츠의 자세한 정보가 츨력됨
	*	@param	lst	마스터 리스트,
	*/
	virtual int DisplayDetail(string inname, List<Content>& lst);

	bool operator< (const Group& event) const {
		if (GetTitle() < event.GetTitle()) {
			return true;
		}
		else {
			return false;
		}
	}
	bool operator> (const Group& event) const {
		if (GetTitle() > event.GetTitle()) {
			return true;
		}
		else {
			return false;
		}
	}
	bool operator== (const Group& event) const {
		if (GetTitle() == event.GetTitle()) {
			return true;
		}
		else {
			return false;
		}
	}

};

