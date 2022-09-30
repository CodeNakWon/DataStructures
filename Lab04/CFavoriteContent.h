#pragma once
class FavoriteContent {
private:
	string m_cName; // FC 이름을 저장 (primery_key)
	ContentType m_cType; // FC 종류를 저장
	int m_views;

public:

	//생성자
	FavoriteContent() {
		m_views = 0;
	};
	
	//소멸자
	~FavoriteContent() {};


	/**
	*	@brief	FC 이름을 가져옴
	*	@pre	FC 이름이 설정됨
	*	@post	없음
	*	@return	FC 이름
	*/
	string GetName() const;
	

	/**
	*	@brief	FC 종류를 가져옴
	*	@pre	FC 종류가 설정됨
	*	@post	없음
	*	@return	FC 종류
	*/
	ContentType GetType() const;

	/**
	*	@brief	FC 조회수를 가져옴
	*	@pre	FC 조회수가 설정됨
	*	@post	없음
	*	@return	FC 조회수
	*/
	int GetViews() const;


	/**
	*	@brief	FC 이름을 설정
	*	@pre	없음
	*	@post	FC 이름이 설정됨
	*	@param	inName	FC 이름
	*/
	void SetName(string inName);


	/**
	*	@brief	FC 종류를 설정
	*	@pre	없음
	*	@post	FC 종류가 설정됨
	*	@param	inType	FC 종류
	*/
	void SetType(ContentType inType);


	/**
	*	@brief	FC 종류를 설정
	*	@pre	없음
	*	@post	FC 종류가 설정됨
	*	@param	inName FC 이름
	*	@param	inType FC 종류
	*/
	void SetRecord(string inName, ContentType inType);
	

	/**
	*	@brief	FC 이름을 화면에 출력
	*	@pre	FC 이름이 설정됨
	*	@post	FC 이름이 화면에 출력됨
	*/
	void DisplayNameOnScreen() const;

	/**
	*	@brief	FC 종류를 화면에 출력
	*	@pre	FC 종류가 설정됨
	*	@post	FC 종류를가 화면에 출력됨
	*/
	void DisplayTypeOnScreen() const;
	
	/**
	*@brief	FC 레코드를 화면에 출력
	*@pre	FC 레코드가 설정됨
	*@post	FC 레코드가 화면에 출력됨
	*/
	void DisplayRecordOnScreen() const;


	/**
	*	@brief	FC 조회수를 1증가시킴
	*	@pre	FC 조회수가 초기화됨
	*	@post	FC 조회수를 1증가함
	*/
	void View();


	bool operator< (const FavoriteContent &fc) const {
		if (GetName() < fc.GetName()) {
			return true;
		}
		else {
			return false;
		}
	}

	bool operator> (const FavoriteContent &fc) const {
		if (GetName() > fc.GetName()) {
			return true;
		}
		else {
			return false;
		}
	}

	bool operator== (const FavoriteContent &fc) const {
		if (GetName() == fc.GetName()) {
			return true;
		}
		else {
			return false;
		}
	}

};

