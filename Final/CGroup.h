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
	*	@brief	�׷� �̸��� ����
	*	@pre	����
	*	@post	�׷� �̸��� ������
	*	@param	name �׷� �̸�
	*/
	void SetTitle(QString name);


	/**
	*	@brief	�׷� ������ ����
	*	@pre	����
	*	@post	�׷� ������ ������
	*	@param	des �̺�Ʈ ����
	*/
	void SetDescription(QString des);


	/**
	*	@brief	�׷� �̸��� ������
	*	@pre	�׷� �̸��� ������
	*	@post	����
	*	@return	�̺�Ʈ �̸�
	*/
	QString GetTitle() const;


	/**
	*	@brief	�׷� ������ ������
	*	@pre	�׷� ������ ������
	*	@post	����
	*	@return	�׷� ����
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
	*	@brief  ����Ʈ�� ������� Ȯ��
	*	@pre    ����Ʈ�� �ʱ�ȭ ��
	*	@post	����
	*	@return	����Ʈ�� ��������� 1, �׷��� ������ 0�� ��ȯ
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

