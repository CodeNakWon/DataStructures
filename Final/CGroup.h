#pragma once
class Group
{
protected:
	QString m_cName;
	QString m_cDes;
	int m_cLen = 0;
	SortedList<QString> m_mcList;

public:

	/**
	*	@brief	그룹 이름을 설정
	*	@pre	없음
	*	@post	그룹 이름이 설정됨
	*	@param	name 그룹 이름
	*/
	void SetTitle(QString name);


	/**
	*	@brief	그룹 설명을 설정
	*	@pre	없음
	*	@post	그룹 설명이 설정됨
	*	@param	des 이벤트 설명
	*/
	void SetDescription(QString des);


	/**
	*	@brief	그룹 이름을 가져옴
	*	@pre	그룹 이름이 설정됨
	*	@post	없음
	*	@return	이벤트 이름
	*/
	QString GetTitle() const;


	/**
	*	@brief	그룹 설명을 가져옴
	*	@pre	그룹 설명이 설정됨
	*	@post	없음
	*	@return	그룹 설명
	*/
	QString GetDescription() const;

	int GetLenght() const;


	void Add(Content& con) {
		QString name;
		name = con.GetName();
		if (m_mcList.Add(name)) {
			m_cLen++;
		}
	}

	void Delete(Content con) {
		QString name;
		name = con.GetName();
		if (m_mcList.Delete(name)) {
			m_cLen--;
		}
	}


	SortedList<QString>& Getitems() {
		return m_mcList;
	}

	/**
	*	@brief  리스트가 비었는지 확인
	*	@pre    리스트가 초기화 됨
	*	@post	없음
	*	@return	리스트가 비어있으면 1, 그렇지 않으면 0을 반환
	*/
	bool isEmpty();




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

