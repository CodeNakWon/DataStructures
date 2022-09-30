
#pragma once

//enum RelationType { LESS, GREATER, EQUAL };
//enum ContentType { PICTURE = 0, VIDEO = 1, UNKNOWN = -1 };

class Content {
private:
	QString m_cName; // ������ ���ϸ�
	QString m_cType; //������ ����
	QString m_Date; // ������¥�� �ð�
	QString m_location;// ���
	QString m_Person; // �������� ���Ե� ���
	QString m_EventName; // �̺�Ʈ��
	QString m_Path; //�������
	//SortedList<string> m_keywords; // Ű���� ����Ʈ
	int m_views; // ��ȸ��
public:
	Content() {
		int m_views = 0;
	}
	~Content() {
	}

	/**
	*	@brief	������ �̸��� ������
	*	@pre	������ �̸��� ������
	*	@post	����
	*	@return	������ �̸�
	*/
	QString GetName() const;

	/**
	*	@brief	������ ������ ������
	*	@pre	������ ������ ������
	*	@post	����
	*	@return	������ ����
	*/
	QString GetType() const;

	/**
	*	@brief	������ ���� ��¥�� �ð��� ������
	*	@pre	������ ���� ��¥�� �ð��� ������
	*	@post	����
	*	@return	������ ���� ��¥�� �ð�
	*/
	QString GetDate() const;

	/**
	*	@brief	������ ��Ҹ� ������
	*	@pre	������ ��Ұ� ������
	*	@post	����
	*	@return	������ ���
	*/
	QString GetLocation() const;


	/**
	*	@brief	�������� ���Ե� �ι����� ������
	*	@pre	�������� ���Ե� �ι����� ������
	*	@post	����
	*	@return	�������� ���Ե� �ι���
	*/
	QString GetPerson() const;


	/**
	*	@brief	������ �̺�Ʈ���� ������
	*	@pre	������ �̺�Ʈ���� ������
	*	@post	����
	*	@return	������ �̺�Ʈ��
	*/
	QString GetEventName() const;

	/**
	*	@brief	������ ���� ��ġ�� ������
	*	@pre	������ ���� ��ġ�� ������
	*	@post	����
	*	@return	������ ���� ��ġ
	*/
	QString GetPath() const;


	/**
	*	@brief	������ ��ȸ���� ������
	*	@pre	������ ��ȸ���� ������
	*	@post	����
	*	@return	������ ��ȸ��
	*/
	int GetViews() const;
	
	/**
	*	@brief	������ �̸��� ����
	*	@pre	����
	*	@post	������ �̸��� ������
	*	@param	inName	������ �̸�
	*/
	void SetName(QString inName);

	/**
	*	@brief	������ ������ ����
	*	@pre	����
	*	@post	������ ������ ������
	*	@param	inType	������ ����
	*/

	void SetType(QString inType);

	/**
	*	@brief	�������� ������ ��¥�� �ð��� ����
	*	@pre	����
	*	@post	�������� ������ ��¥�� �ð��� ������
	*	@param	inDate	�������� ������ ��¥�� �ð�
	*/
	void SetDate(QString inDate);


	/**
	*	@brief	�������� ��Ҹ� ����
	*	@pre	����
	*	@post	�������� ��Ұ� ������
	*	@param	inDate	������ ���
	*/
	void SetLocation(QString inLocation);


	/**
	*	@brief	�������� ���Ե� �ι����� ����
	*	@pre	����
	*	@post	�������� ���Ե� �ι����� ������
	*	@param	inPerson  �������� ���Ե� �ι���
	*/
	void SetPerson(QString inPerson);


	/**
	*	@brief	������ �̺�Ʈ���� ����
	*	@pre	����
	*	@post	������ �̺�Ʈ���� ������
	*	@param	inEventName	������ �̺�Ʈ��
	*/
	void SetEventName(QString inEventName);

	/**
	*	@brief	������ ���� ��ġ�� ����
	*	@pre	����
	*	@post	������ ���� ��ġ�� ������
	*	@param	inPath	������ ������ġ
	*/
	void SetPath(QString inPath);

	/**
	*	@brief	��ȸ���� ����
	*	@pre	����
	*	@post	������ ��ȸ���� ������
	*	@param	inView	��ȸ��
	*/
	void SetViews(int inViews);

	/**
	*	@brief	��ȸ���� ����
	*	@pre	����
	*	@post	������ ��ȸ���� ������
	*	@param	inView	��ȸ��
	*/
	void ViewCon();

	// Contents�� sortedList�� �ֱ� ���� ������ �����ε� 
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