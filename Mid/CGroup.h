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
	*	@brief	�׷� �̸��� ����
	*	@pre	����
	*	@post	�׷� �̸��� ������
	*	@param	name �׷� �̸�
	*/
	virtual void SetTitle(string name);


	/**
	*	@brief	�׷� ������ ����
	*	@pre	����
	*	@post	�׷� ������ ������
	*	@param	des �̺�Ʈ ����
	*/
	virtual void SetDescription(string des);


	/**
	*	@brief	�׷� �̸��� ������
	*	@pre	�׷� �̸��� ������
	*	@post	����
	*	@return	�̺�Ʈ �̸�
	*/
	virtual string GetTitle() const;


	/**
	*	@brief	�׷� ������ ������
	*	@pre	�׷� ������ ������
	*	@post	����
	*	@return	�׷� ����
	*/
	virtual string GetDescription() const;


	/**
	*	@brief	Ű����� �׷���� ����
	*	@pre	����
	*	@post	�׷���� ������
	*/
	virtual void SetTitlefromKB();


	/**
	*	@brief	Ű����� �׷� ������ ����
	*	@pre	����
	*	@post	�׷� ������ ������
	*/
	virtual void SetDescriptionfromKB();


	/**
	*@brief	�׷���� ȭ�鿡 ���
	*@pre	�׷���� ������
	*@post	�׷���� ȭ�鿡 ��µ�
	*/
	virtual void DisplayTitle();


	/**
	*@brief	�׷쿡 ���Ե� ���������� ȭ�鿡 ���
	*@pre	����.
	*@post	�׷쿡 ���Ե� ���������� ȭ�鿡 ��µ�
	*/
	virtual void DisplayIncludedContents();


	/**
	*@brief	�׷� ������ ȭ�鿡 ���
	*@pre	����.
	*@post	�׷� ������ ȭ�鿡 ��µ�
	*/
	virtual void DisplayDescriptionOnScreen();


	/**
	*@brief	�׷� ������ ȭ�鿡 ���
	*@pre	�׷� ���ڵ尡 �ʱ�ȭ ��
	*@post	�׷� ������ ȭ�鿡 ��µ�
	*/
	virtual void DisplayRecordOnScreen();


	/**
	*	@brief	MC�� �Է¹޾� �ش�MC�� �̸�(primary key)�� �׷� ����Ʈ�� ����
	*	@pre	����Ʈ�� �ʱ�ȭ ��
	*	@post	����Ʈ�� MC�� �����
	*	@param	mc	ã�� �������� �̸��� ���� MC
	*	@return	����Ʈ ���忡 �����ϸ� 1, ����Ʈ�� ���� �̸��� �����ϸ� -1, ����Ʈ�� ���������� 0�� ��ȯ
	*/
	virtual int AddMC(Content& mc);


	/**
	*	@brief	MC�� �Է¹޾� �ش�MC�� �̸�(primary key)�� �׷� ����Ʈ���� ã�� ����
	*	@pre	����Ʈ�� �ʱ�ȭ ��
	*	@post	����Ʈ���� �ش�MC�� ã�� ����
	*	@param	������	�������� �̸��� ���� MC
	*	@return	������ �����ϸ� 1, �׷��� ������ 0�� ��ȯ
	*/
	virtual int Delete(Content& mc);


	/**
	*	@brief	MC�� �Է¹޾� �ش�MC�� �̸�(primary key)�� �׷� ����Ʈ���� ã��
	*	@pre	����Ʈ�� �ʱ�ȭ ��
	*	@post	������ ����Ʈ���� �ش� MC�� �̸�(primary key)�� ã�Ƽ� �����ϸ� �� �̸��� ���� MC�� ������
	*	@param	mc	ã�� �������� �̸��� ���� MC
	*	@return	����Ʈ���� �ش� �����͸� ã���� 1 �׷��� ������ 0�� ��ȯ
	*/
	virtual int Retrieve(Content& mc);


	/**
	*	@brief  ����Ʈ�� ������� Ȯ��
	*	@pre    ����Ʈ�� �ʱ�ȭ ��
	*	@post	����
	*	@return	����Ʈ�� ��������� 1, �׷��� ������ 0�� ��ȯ
	*/
	virtual bool isEmpty();


	/**
	*	@brief  �׷쿡 ���� ��� �������� �ڼ��� ������ ���
	*	@pre	�׷� ����Ʈ�� �ʱ�ȭ��
	*	@post	�׷쿡 ���� ��� �������� �ڼ��� ������ ���µ�
	*	@param	lst	������ ����Ʈ
	*/
	virtual void DisplayDetailAll(List<Content>& lst);


	/**
	*	@brief  �׷쿡 ���� ��� �������� �ڼ��� ������ ���
	*	@pre	������ ����Ʈ�� �ʱ�ȭ��
	*	@post	�׷쿡 ���� ��� �������� �ڼ��� ������ ���µ�
	*	@param	lst	������ ����Ʈ,
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

