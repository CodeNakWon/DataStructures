#pragma once
class FavoriteContent {
private:
	string m_cName; // FC �̸��� ���� (primery_key)
	ContentType m_cType; // FC ������ ����
	int m_views;

public:

	//������
	FavoriteContent() {
		m_views = 0;
	};
	
	//�Ҹ���
	~FavoriteContent() {};


	/**
	*	@brief	FC �̸��� ������
	*	@pre	FC �̸��� ������
	*	@post	����
	*	@return	FC �̸�
	*/
	string GetName() const;
	

	/**
	*	@brief	FC ������ ������
	*	@pre	FC ������ ������
	*	@post	����
	*	@return	FC ����
	*/
	ContentType GetType() const;

	/**
	*	@brief	FC ��ȸ���� ������
	*	@pre	FC ��ȸ���� ������
	*	@post	����
	*	@return	FC ��ȸ��
	*/
	int GetViews() const;


	/**
	*	@brief	FC �̸��� ����
	*	@pre	����
	*	@post	FC �̸��� ������
	*	@param	inName	FC �̸�
	*/
	void SetName(string inName);


	/**
	*	@brief	FC ������ ����
	*	@pre	����
	*	@post	FC ������ ������
	*	@param	inType	FC ����
	*/
	void SetType(ContentType inType);


	/**
	*	@brief	FC ������ ����
	*	@pre	����
	*	@post	FC ������ ������
	*	@param	inName FC �̸�
	*	@param	inType FC ����
	*/
	void SetRecord(string inName, ContentType inType);
	

	/**
	*	@brief	FC �̸��� ȭ�鿡 ���
	*	@pre	FC �̸��� ������
	*	@post	FC �̸��� ȭ�鿡 ��µ�
	*/
	void DisplayNameOnScreen() const;

	/**
	*	@brief	FC ������ ȭ�鿡 ���
	*	@pre	FC ������ ������
	*	@post	FC �������� ȭ�鿡 ��µ�
	*/
	void DisplayTypeOnScreen() const;
	
	/**
	*@brief	FC ���ڵ带 ȭ�鿡 ���
	*@pre	FC ���ڵ尡 ������
	*@post	FC ���ڵ尡 ȭ�鿡 ��µ�
	*/
	void DisplayRecordOnScreen() const;


	/**
	*	@brief	FC ��ȸ���� 1������Ŵ
	*	@pre	FC ��ȸ���� �ʱ�ȭ��
	*	@post	FC ��ȸ���� 1������
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

