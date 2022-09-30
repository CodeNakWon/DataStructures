#pragma once
class Event {
private:
	string m_eName;
	string m_eDes;
	int m_eLen;
	SortedList<string> m_MCKeys;

public:
	// ������
	Event() {
		m_eLen = 0;
		m_eDes = "";
	}

	
	/**
	*	@brief	�̺�Ʈ �̸��� ����
	*	@pre	����
	*	@post	�̺�Ʈ �̸��� ������
	*	@param	name �̺�Ʈ �̸�
	*/
	void setEventName(string name);
	/**
	*	@brief	�̺�Ʈ ������ ����
	*	@pre	����
	*	@post	�̺�Ʈ ������ ������
	*	@param	des �̺�Ʈ ����
	*/
	void setEventDescription(string des);

	/**
	*	@brief	�̺�Ʈ �̸��� ������
	*	@pre	�̺�Ʈ �̸��� ������
	*	@post	����
	*	@return	�̺�Ʈ �̸�
	*/
	string getEventName() const;
	
	/**
	*	@brief	�̺�Ʈ ������ ������
	*	@pre	�̺�Ʈ ������ ������
	*	@post	����
	*	@return	�̺�Ʈ �̸�
	*/
	string setEventDescription() const;

	
	/**
	*	@brief	Ű����� �̺�Ʈ���� ����
	*	@pre	����
	*	@post	�̺�Ʈ���� ������
	*/
	void setEventNamefromKB();

	/**
	*	@brief	Ű����� �̺�Ʈ ������ ����
	*	@pre	����
	*	@post	�̺�Ʈ ������ ������
	*/
	void setEventDescriptionfromKB();

	/**
	*@brief	�̺�Ʈ���� ȭ�鿡 ���
	*@pre	�̺�Ʈ���� ������
	*@post	�̺�Ʈ���� ȭ�鿡 ��µ�
	*/
	void DisplayEventName();
	
	/**
	*@brief	�̺�Ʈ�� ���Ե� ���������� ȭ�鿡 ���
	*@pre	����.
	*@post	�̺�Ʈ�� ���Ե� ���������� ȭ�鿡 ��µ�
	*/
	void DisplayIncludedContents();

	/**
	*@brief	�̺�Ʈ ������ ȭ�鿡 ���
	*@pre	�̺�Ʈ ���ڵ尡 �ʱ�ȭ ��
	*@post	�̺�Ʈ ������ ȭ�鿡 ��µ�
	*/
	void DisplayRecordOnScreen();

	/**
	*	@brief	MC�� �Է¹޾� �ش�MC�� �̸�(primary key)�� �̺�Ʈ ����Ʈ�� ����
	*	@pre	����Ʈ�� �ʱ�ȭ ��
	*	@post	����Ʈ�� MC�� �����
	*	@param	mc	ã�� �������� �̸��� ���� MC
	*	@return	����Ʈ ���忡 �����ϸ� 1, ����Ʈ�� ���� �̸��� �����ϸ� -1, ����Ʈ�� ���������� 0�� ��ȯ
	*/
	int AddMC(MultimediaContent mc);

	/**
	*	@brief	MC�� �Է¹޾� �ش�MC�� �̸�(primary key)�� �̺�Ʈ ����Ʈ���� ã�� ����
	*	@pre	����Ʈ�� �ʱ�ȭ ��
	*	@post	����Ʈ���� �ش�MC�� ã�� ����
	*	@param	������	�������� �̸��� ���� MC
	*	@return	������ �����ϸ� 1, �׷��� ������ 0�� ��ȯ
	*/
	int Delete(MultimediaContent& mc);
	
	/**
	*	@brief	MC�� �Է¹޾� �ش�MC�� �̸�(primary key)�� �̺�Ʈ ����Ʈ���� ã��
	*	@pre	����Ʈ�� �ʱ�ȭ ��
	*	@post	�̺�Ʈ ����Ʈ���� �ش� MC�� �̸�(primary key)�� ã�Ƽ� �����ϸ� �� �̸��� ���� MC�� ������
	*	@param	mc	ã�� �������� �̸��� ���� MC
	*	@return	����Ʈ���� �ش� �����͸� ã���� 1 �׷��� ������ 0�� ��ȯ
	*/
	int Retrieve(MultimediaContent& mc);
	
	/**
	*	@brief  �̺�Ʈ ����Ʈ�� ������� Ȯ��
	*	@pre	�̺�Ʈ ����Ʈ�� �ʱ�ȭ ��
	*	@post	����
	*	@return	�̺�Ʈ ����Ʈ�� ��������� 1, �׷��� ������ 0�� ��ȯ
	*/
	bool isEmpty();


	//������ �����ε� >, <, ==
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
