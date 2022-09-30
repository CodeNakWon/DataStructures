#pragma once
//enum RelationType { LESS, GREATER, EQUAL };
//enum ContentType { PICTURE = 0, VIDEO = 1, UNKNOWN = -1 };

class Content {
private:
	string m_cName; // 콘텐츠 파일명
	ContentType m_cType; //콘텐츠 종류
	string m_Date; // 생성날짜와 시간
	string m_location;// 장소
	string m_Person; // 콘텐츠에 포함된 사람
	int m_Category; // 콘텐츠 구분
	string m_EventName; // 이벤트명
	SortedList<string> m_keywords; // 키워드 리스트
	int m_views; // 조회수
public:
	Content() {
		int m_views = 0;
	}
	~Content() {
	}

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
	*	@brief	컨텐츠 장소를 가져옴
	*	@pre	컨텐츠 장소가 설정됨
	*	@post	없음
	*	@return	컨텐츠 장소
	*/
	string GetLocation() const;


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

	int GetViews() const;


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
	*	@brief	컨텐츠의 장소를 설정, 해당 장소를 키워드에 추가
	*	@pre	없음
	*	@post	컨텐츠의 장소가 설정됨
	*	@param	inDate	컨텐츠 장소
	*/
	void SetLocation(string inLocation);


	/**
	*	@brief	컨텐츠에 포함된 인물명을 설정, 해당 인물명을 키워드에 추가
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
	*	@brief	컨텐츠 이벤트명을 설정, 해당 이벤트명을 키워드에 추가
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
	void SetRecord(string inName, ContentType inType, string inDate, string inLocation, string inPerson, int inCategory, string inEventName); // 이벤트 정보 저장

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
	*@brief	콘텐츠 장소를 화면에 출력
	*@pre	콘텐츠 장소가 설정됨
	*@post	콘텐츠 장소가 화면에 출력됨
	*/
	void DisplayLocationOnScreen() const;

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
	*@brief	콘텐츠 레코드를 화면에 출력하고 조회수를 1증가시킴
	*@pre	콘텐츠 레코드가 설정됨
	*@post	콘텐츠 레코드가 화면에 출력됨 조회수가 1증가됨
	*/
	void DisplayRecordOnScreen();


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
	*	@brief	키보드로 컨텐츠 장소를 설정
	*	@pre	없음
	*	@post	콘텐츠 장소가 설정됨
	*/
	void SetLocationFromKB();


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
	void SetRecordFromKB(string indate);

	/**
	*	@brief	키보드로 콘텐츠 레코드를 설정
	*	@pre	없음
	*	@post	콘텐츠 레코드가 설정됨
	*/
	void ModifyRecord();


	/**
	*	@brief	키워드를 리스트로 받아서 해당키워드가 this 키워드 리스트에 모두 존재하는지 확인 
	*	@pre	키워드 리스트가 초기화 됨
	*	@post	없음.
	*	@param	keys 키워드를 원소로 가지는 리스트
	*	@return	keys리스트안의 원소가 모두 키워드 리스트에 존재하면 1, 그렇지 않으면 0을 반환
	*/
	int KeyWordSearch(SortedList<string>& keys);

	
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


	// Contents를 sortedList에 넣기 위해 연산자 오버로딩 
	bool operator< (const Content& mc) const {
		if (GetName() < mc.GetName()) {
			return true;
		}
		else {
			return false;
		}
	}
	bool operator> (const Content& mc) const {
		if (GetName() > mc.GetName()) {
			return true;
		}
		else {
			return false;
		}
	}

	bool operator== (const Content& mc) const {
		if (GetName() == mc.GetName()) {
			return true;
		}
		else {
			return false;
		}
	}


};