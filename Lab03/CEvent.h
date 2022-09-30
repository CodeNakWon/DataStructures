#pragma once
class Event {
private:
	string m_eName;
	string m_eDes;
	int m_eLen;
	SortedList<string> m_MCKeys;

public:
	// 생성자
	Event() {
		m_eLen = 0;
		m_eDes = "";
	}

	
	/**
	*	@brief	이벤트 이름을 설정
	*	@pre	없음
	*	@post	이벤트 이름이 설정됨
	*	@param	name 이벤트 이름
	*/
	void setEventName(string name);
	/**
	*	@brief	이벤트 설명을 설정
	*	@pre	없음
	*	@post	이벤트 설명이 설정됨
	*	@param	des 이벤트 설명
	*/
	void setEventDescription(string des);

	/**
	*	@brief	이벤트 이름을 가져옴
	*	@pre	이벤트 이름이 설정됨
	*	@post	없음
	*	@return	이벤트 이름
	*/
	string getEventName() const;
	
	/**
	*	@brief	이벤트 설명을 가져옴
	*	@pre	이벤트 설명이 설정됨
	*	@post	없음
	*	@return	이벤트 이름
	*/
	string setEventDescription() const;

	
	/**
	*	@brief	키보드로 이벤트명을 설정
	*	@pre	없음
	*	@post	이벤트명이 설정됨
	*/
	void setEventNamefromKB();

	/**
	*	@brief	키보드로 이벤트 설명을 설정
	*	@pre	없음
	*	@post	이벤트 설명이 설정됨
	*/
	void setEventDescriptionfromKB();

	/**
	*@brief	이벤트명을 화면에 출력
	*@pre	이벤트명이 설정됨
	*@post	이벤트명이 화면에 출력됨
	*/
	void DisplayEventName();
	
	/**
	*@brief	이벤트에 포함된 콘텐츠명을 화면에 출력
	*@pre	없음.
	*@post	이벤트에 포함된 콘텐츠명이 화면에 출력됨
	*/
	void DisplayIncludedContents();

	/**
	*@brief	이벤트 정보를 화면에 출력
	*@pre	이벤트 레코드가 초기화 됨
	*@post	이벤트 정보가 화면에 출력됨
	*/
	void DisplayRecordOnScreen();

	/**
	*	@brief	MC를 입력받아 해당MC의 이름(primary key)를 이벤트 리스트에 저장
	*	@pre	리스트가 초기화 됨
	*	@post	리스트에 MC가 저장됨
	*	@param	mc	찾을 데이터의 이름을 가진 MC
	*	@return	리스트 저장에 성공하면 1, 리스트에 같은 이름이 존재하면 -1, 리스트가 꽉차있으면 0을 반환
	*/
	int AddMC(MultimediaContent mc);

	/**
	*	@brief	MC를 입력받아 해당MC의 이름(primary key)를 이벤트 리스트에서 찾아 삭제
	*	@pre	리스트가 초기화 됨
	*	@post	리스트에서 해당MC를 찾아 삭제
	*	@param	삭제할	데이터의 이름을 가진 MC
	*	@return	삭제에 성공하면 1, 그렇지 않으면 0을 반환
	*/
	int Delete(MultimediaContent& mc);
	
	/**
	*	@brief	MC를 입력받아 해당MC의 이름(primary key)를 이벤트 리스트에서 찾음
	*	@pre	리스트가 초기화 됨
	*	@post	이벤트 리스트에서 해당 MC의 이름(primary key)을 찾아서 존재하면 그 이름을 가진 MC로 가져옴
	*	@param	mc	찾을 데이터의 이름을 가진 MC
	*	@return	리스트에서 해당 데이터를 찾으면 1 그렇지 않으면 0을 반환
	*/
	int Retrieve(MultimediaContent& mc);
	
	/**
	*	@brief  이벤트 리스트가 비었는지 확인
	*	@pre	이벤트 리스트가 초기화 됨
	*	@post	없음
	*	@return	이벤트 리스트가 비어있으면 1, 그렇지 않으면 0을 반환
	*/
	bool isEmpty();


	//연산자 오버로딩 >, <, ==
	bool operator< (const Event &event) const{
		if (getEventName() < event.getEventName()) {
			return true;
		}
		else {
			return false;
		}
	}
	bool operator> (const Event &event) const{
		if (getEventName() > event.getEventName()) {
			return true;
		}
		else {
			return false;
		}
	}
	bool operator== (const Event &event) const{
		if (getEventName() == event.getEventName()) {
			return true;
		}
		else {
			return false;
		}
	}

};
