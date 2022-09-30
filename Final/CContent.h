
#pragma once

//enum RelationType { LESS, GREATER, EQUAL };
//enum ContentType { PICTURE = 0, VIDEO = 1, UNKNOWN = -1 };

class Content {
private:
	QString m_cName; // 콘텐츠 파일명
	QString m_cType; //콘텐츠 종류
	QString m_Date; // 생성날짜와 시간
	QString m_location;// 장소
	QString m_Person; // 콘텐츠에 포함된 사람
	QString m_EventName; // 이벤트명
	QString m_Path; //사진경로
	//SortedList<string> m_keywords; // 키워드 리스트
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
	QString GetName() const;

	/**
	*	@brief	컨텐츠 종류를 가져옴
	*	@pre	컨텐츠 종류가 설정됨
	*	@post	없음
	*	@return	컨텐츠 종류
	*/
	QString GetType() const;

	/**
	*	@brief	컨텐츠 생성 날짜와 시간을 가져옴
	*	@pre	컨텐츠 생성 날짜와 시간이 설정됨
	*	@post	없음
	*	@return	컨텐츠 생성 날짜와 시간
	*/
	QString GetDate() const;

	/**
	*	@brief	컨텐츠 장소를 가져옴
	*	@pre	컨텐츠 장소가 설정됨
	*	@post	없음
	*	@return	컨텐츠 장소
	*/
	QString GetLocation() const;


	/**
	*	@brief	컨텐츠에 포함된 인물명을 가져옴
	*	@pre	컨텐츠에 포함된 인물명이 설정됨
	*	@post	없음
	*	@return	컨텐츠에 포함된 인물명
	*/
	QString GetPerson() const;


	/**
	*	@brief	컨텐츠 이벤트명을 가져옴
	*	@pre	컨텐츠 이벤트명을 설정됨
	*	@post	없음
	*	@return	컨텐츠 이벤트명
	*/
	QString GetEventName() const;

	/**
	*	@brief	컨텐츠 저장 위치를 가져옴
	*	@pre	컨텐츠 저장 위치가 설정됨
	*	@post	없음
	*	@return	컨텐츠 저장 위치
	*/
	QString GetPath() const;


	/**
	*	@brief	컨텐츠 조회수를 가져옴
	*	@pre	컨텐츠 조회수가 설정됨
	*	@post	없음
	*	@return	컨텐츠 조회수
	*/
	int GetViews() const;
	
	/**
	*	@brief	컨텐츠 이름을 설정
	*	@pre	없음
	*	@post	컨텐츠 이름이 설정됨
	*	@param	inName	컨텐츠 이름
	*/
	void SetName(QString inName);

	/**
	*	@brief	컨텐츠 종류를 설정
	*	@pre	없음
	*	@post	컨텐츠 종류가 설정됨
	*	@param	inType	컨텐츠 종류
	*/

	void SetType(QString inType);

	/**
	*	@brief	컨텐츠가 생성된 날짜와 시간을 설정
	*	@pre	없음
	*	@post	컨텐츠가 생성된 날짜와 시간이 설정됨
	*	@param	inDate	컨텐츠가 생성된 날짜와 시간
	*/
	void SetDate(QString inDate);


	/**
	*	@brief	컨텐츠의 장소를 설정
	*	@pre	없음
	*	@post	컨텐츠의 장소가 설정됨
	*	@param	inDate	컨텐츠 장소
	*/
	void SetLocation(QString inLocation);


	/**
	*	@brief	컨텐츠에 포함된 인물명을 설정
	*	@pre	없음
	*	@post	컨텐츠에 포함된 인물명이 설정됨
	*	@param	inPerson  컨텐츠에 포함된 인물명
	*/
	void SetPerson(QString inPerson);


	/**
	*	@brief	컨텐츠 이벤트명을 설정
	*	@pre	없음
	*	@post	컨텐츠 이벤트명이 설정됨
	*	@param	inEventName	컨텐츠 이벤트명
	*/
	void SetEventName(QString inEventName);

	/**
	*	@brief	컨텐츠 저장 위치를 설정
	*	@pre	없음
	*	@post	컨텐츠 저장 위치가 설정됨
	*	@param	inPath	컨텐츠 저장위치
	*/
	void SetPath(QString inPath);

	/**
	*	@brief	조회수를 설정
	*	@pre	없음
	*	@post	컨텐츠 조회수가 설정됨
	*	@param	inView	조회수
	*/
	void SetViews(int inViews);

	/**
	*	@brief	조회수를 설정
	*	@pre	없음
	*	@post	컨텐츠 조회수가 설정됨
	*	@param	inView	조회수
	*/
	void ViewCon();

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