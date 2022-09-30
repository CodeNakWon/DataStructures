#pragma once
//enum RelationType { LESS, GREATER, EQUAL };
//enum ContentType { PICTURE = 0, VIDEO = 1, UNKNOWN = -1 };

class Content {
private:
	string m_cName; // ������ ���ϸ�
	ContentType m_cType; //������ ����
	string m_Date; // ������¥�� �ð�
	string m_location;// ���
	string m_Person; // �������� ���Ե� ���
	int m_Category; // ������ ����
	string m_EventName; // �̺�Ʈ��
	SortedList<string> m_keywords; // Ű���� ����Ʈ
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
	string GetName() const;

	/**
	*	@brief	������ ������ ������
	*	@pre	������ ������ ������
	*	@post	����
	*	@return	������ ����
	*/
	ContentType GetType() const;

	/**
	*	@brief	������ ���� ��¥�� �ð��� ������
	*	@pre	������ ���� ��¥�� �ð��� ������
	*	@post	����
	*	@return	������ ���� ��¥�� �ð�
	*/
	string GetDate() const;

	/**
	*	@brief	������ ��Ҹ� ������
	*	@pre	������ ��Ұ� ������
	*	@post	����
	*	@return	������ ���
	*/
	string GetLocation() const;


	/**
	*	@brief	�������� ���Ե� �ι����� ������
	*	@pre	�������� ���Ե� �ι����� ������
	*	@post	����
	*	@return	�������� ���Ե� �ι���
	*/
	string GetPerson() const;


	/**
	*	@brief	������ ������ ������
	*	@pre	������ ������ ������
	*	@post	����
	*	@return	������ ����
	*/
	int GetCategory() const;

	/**
	*	@brief	������ �̺�Ʈ���� ������
	*	@pre	������ �̺�Ʈ���� ������
	*	@post	����
	*	@return	������ �̺�Ʈ��
	*/
	string GetEventName() const;

	int GetViews() const;


	/**
	*	@brief	������ �̸��� ����
	*	@pre	����
	*	@post	������ �̸��� ������
	*	@param	inName	������ �̸�
	*/
	void SetName(string inName);

	/**
	*	@brief	������ ������ ����
	*	@pre	����
	*	@post	������ ������ ������
	*	@param	inType	������ ����
	*/

	void SetType(ContentType inType);

	/**
	*	@brief	�������� ������ ��¥�� �ð��� ����
	*	@pre	����
	*	@post	�������� ������ ��¥�� �ð��� ������
	*	@param	inDate	�������� ������ ��¥�� �ð�
	*/
	void SetDate(string inDate);


	/**
	*	@brief	�������� ��Ҹ� ����, �ش� ��Ҹ� Ű���忡 �߰�
	*	@pre	����
	*	@post	�������� ��Ұ� ������
	*	@param	inDate	������ ���
	*/
	void SetLocation(string inLocation);


	/**
	*	@brief	�������� ���Ե� �ι����� ����, �ش� �ι����� Ű���忡 �߰�
	*	@pre	����
	*	@post	�������� ���Ե� �ι����� ������
	*	@param	inPerson  �������� ���Ե� �ι���
	*/
	void SetPerson(string inPerson);

	/**
	*	@brief	������ ���и��� ����
	*	@pre	����
	*	@post	������ ������ ������
	*	@param	inCategory  ������ ����
	*/
	void SetCategory(int inCategory);

	/**
	*	@brief	������ �̺�Ʈ���� ����, �ش� �̺�Ʈ���� Ű���忡 �߰�
	*	@pre	����
	*	@post	������ �̺�Ʈ���� ������
	*	@param	inEventName	������ �̺�Ʈ��
	*/
	void SetEventName(string inEventName);

	/**
	*	@brief	������ ���ڵ带 ����
	*	@pre	����
	*	@post	������ ���ڵ尡 ������
	*	@param	inName	������ �̸�
	*	@param	inType	������ ����
	*	@param	inDate	�������� ������ ��¥�� �ð�
	*	@param	inPerson  �������� ���Ե� �ι���
	*	@param	inEventName	������ �̺�Ʈ��
	*/
	void SetRecord(string inName, ContentType inType, string inDate, string inLocation, string inPerson, int inCategory, string inEventName); // �̺�Ʈ ���� ����

	/**
	*	@brief	������ �̸��� ȭ�鿡 ���
	*	@pre	������ �̸��� ������
	*	@post	������ �̸��� ȭ�鿡 ��µ�
	*/
	void DisplayNameOnScreen() const;

	/**
	*	@brief	������ ������ ȭ�鿡 ���
	*	@pre	������ ������ ������
	*	@post	������ �������� ȭ�鿡 ��µ�
	*/
	void DisplayTypeOnScreen() const;

	/**
	*@brief	������ ���� ��¥�� �ð��� ȭ�鿡 ���
	*@pre	������ ���� ��¥�� �ð��� ������
	*@post	������ ���� ��¥�� �ð��� ȭ�鿡 ��µ�
	*/
	void DisplayDateOnScreen() const;

	/**
	*@brief	������ ��Ҹ� ȭ�鿡 ���
	*@pre	������ ��Ұ� ������
	*@post	������ ��Ұ� ȭ�鿡 ��µ�
	*/
	void DisplayLocationOnScreen() const;

	/**
	*@brief	�������� ���Ե� �ι����� ȭ�鿡 ���
	*@pre	�������� ���Ե� �ι����� ������
	*@post	�������� ���Ե� �ι����� ȭ�鿡 ��µ�
	*/
	void DisplayPersonOnScreen() const;

	/**
	*@brief	������ ������ ȭ�鿡 ���
	*@pre	������ ������ ������
	*@post	������ ������ ȭ�鿡 ��µ�
	*/
	void DisplayCategoryOnScreen() const;


	/**
	*@brief	������ �̺�Ʈ���� ȭ�鿡 ���
	*@pre	������ �̺�Ʈ���� ������
	*@post	������ �̺�Ʈ���� ȭ�鿡 ��µ�
	*/
	void DisplayEventNameOnScreen() const;

	/**
	*@brief	������ ���ڵ带 ȭ�鿡 ����ϰ� ��ȸ���� 1������Ŵ
	*@pre	������ ���ڵ尡 ������
	*@post	������ ���ڵ尡 ȭ�鿡 ��µ� ��ȸ���� 1������
	*/
	void DisplayRecordOnScreen();


	/**
	*	@brief	Ű����� ������ �̸��� ����
	*	@pre	����
	*	@post	������ �̸��� ������
	*/
	void SetNameFromKB();

	/**
	*	@brief	Ű����� ������ ������ ����
	*	@pre	����
	*	@post	������ ������ ������
	*/
	void SetTypeFromKB();

	/**
	*	@brief	Ű����� ������ ���� ��¥�� �ð��� ����
	*	@pre	����
	*	@post	������ ���� ��¥�� �ð��� ������
	*/
	void SetDateFromKB();

	/**
	*	@brief	Ű����� ������ ��Ҹ� ����
	*	@pre	����
	*	@post	������ ��Ұ� ������
	*/
	void SetLocationFromKB();


	/**
	*	@brief	Ű����� �������� ���Ե� �ι��� ����
	*	@pre	����
	*	@post	�������� ���Ե� �ι��� ������
	*/
	void SetPersonFromKB();


	/**
	*	@brief	Ű����� ������ ������ ����
	*	@pre	����
	*	@post	������ ������ ������
	*/
	void SetCategoryFromKB();

	/**
	*	@brief	Ű����� ������ �̺�Ʈ���� ����
	*	@pre	����
	*	@post	������ �̺�Ʈ���� ������
	*/
	void SetEventNameFromKB();

	/**
	*	@brief	Ű����� ������ ���ڵ带 ����
	*	@pre	����
	*	@post	������ ���ڵ尡 ������
	*/
	void SetRecordFromKB(string indate);

	/**
	*	@brief	Ű����� ������ ���ڵ带 ����
	*	@pre	����
	*	@post	������ ���ڵ尡 ������
	*/
	void ModifyRecord();


	/**
	*	@brief	Ű���带 ����Ʈ�� �޾Ƽ� �ش�Ű���尡 this Ű���� ����Ʈ�� ��� �����ϴ��� Ȯ�� 
	*	@pre	Ű���� ����Ʈ�� �ʱ�ȭ ��
	*	@post	����.
	*	@param	keys Ű���带 ���ҷ� ������ ����Ʈ
	*	@return	keys����Ʈ���� ���Ұ� ��� Ű���� ����Ʈ�� �����ϸ� 1, �׷��� ������ 0�� ��ȯ
	*/
	int KeyWordSearch(SortedList<string>& keys);

	
	/**
	*	@brief	���Ϸκ��� ���ڵ带 �о����
	*	@pre	���������ϴ� ������ ����
	*	@post	������ ���ڵ尡 ������
	*	@param	fin	���� ��ũ����
	*	@return	���������� �۵��ҽ� 1�� ��ȯ, �ƴҽ� 0�� ��ȯ
	*/
	int ReadDataFromFile(ifstream& fin);


	/**
	*	@brief	���Ͽ� ���ڵ带 �ۼ�
	*	@pre	���� ������ ����, ���ڵ��� �� �׸��� �ʱ�ȭ ��
	*	@post	���������� �� ���ڵ��� ������ ����
	*	@param	fout	���� ��ũ����
	*	@return	���������� �۵��ҽ� 1�� ��ȯ, �ƴҽ� 0�� ��ȯ
	*/
	int WriteDataToFile(ofstream& fout);


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