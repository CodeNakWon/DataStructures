#pragma once

class Application
{
public:
	/**
	*	@brief	���α׷� ����̹�
	*	@pre	���α׷��� ���۵�
	*	@post	���α׷��� �����
	*/
	void Run();

	/**
	*	@brief	��ɾ ȭ�鿡 ��� �� Ű����� �Է��� ����
	*	@pre	����
	*	@post	����
	*	@return	����ڰ� �Է��� ��ɾ� 
	*/
	int GetCommand();

	/**
	*	@brief	���ο� ���ڵ带 ����Ʈ�� �߰�
	*	@pre	����Ʈ�� �ʰ�ȭ��
	*	@post	���ο� ���ڵ尡 ����Ʈ�� �߰���
	*	@return	���������� �۵��ϸ� 1, �׷��� ������ 0�� ��ȯ��
	*/
	int AddContents();
	
	/**
	*	@brief	���� �Է��� ���� ������ ���� ��ũ���ͷ� ����
	*	@pre	���� ������ ������
	*	@post	�б� ���� ������ ����
	*	@param	fileName	�б� ���� ���� �̸�
	*	@return	����� �����ϸ� 1, �׷��� ������ 0�� ��ȯ
	*/
	int OpenInFile(char* fileName);

	/**
	*	@brief	���� ����� ���� ������ ���� ��ũ���ͷ� ����
	*	@pre	���⸦ �� ������ ������
	*	@post	���� ���� ������ ����
	*	@param	fileName	���� ���� ���� �̸�
	*	@return	����� �����ϸ� 1, �׷��� ������ 0�� ��ȯ
	*/
	int OpenOutFile(char* fileName);

	/**
	*	@brief	������ ���� �а� ������ �����͸� ������� ����Ʈ�� ����
	*	@pre	������ ������ ����
	*	@post	����Ʈ�� ������ �����͸� ������
	*	@return	����� �����ϸ� 1, �׷��� ������ 0�� ��ȯ
	*/
	int ReadDataFromFile();

	/**
	*	@brief	������ ���� ����Ʈ�� �����͸� ���Ͽ� ����.
	*	@pre	������ ������ ����
	*	@post	����Ʈ�� ���Ͽ� �����
	*	@return	����� �����ϸ� 1, �׷��� ������ 0�� ��ȯ
	*/
	int WriteDataToFile();

	/**
	*	@brief	�������� �̸��� �Է� �޾� ����Ʈ���� ����
	*	@pre	����Ʈ�� �ʱ�ȭ ��
	*	@post	����Ʈ���� �ش� ������ ���ڵ尡 ������
	*	@return	����� �����ϸ� 1, �׷��� ������ 0�� ��ȯ
	*/
	int DeleteContents();	

	/**
	*	@brief	�������� ������ ���� �Էµ� ������ ����
	*	@pre	����Ʈ�� �ʱ�ȭ ��
	*	@post	����Ʈ���� �ش� ������ ���ڵ尡 ��ü��
	*	@return	����� �����ϸ� 1, �׷��� ������ 0�� ��ȯ
	*/
	int ReplaceContents();

	/**
	*	@brief	�̸��� �Է¹޾Ƽ� ����Ʈ���� �ش� ����Ʈ�� ã�� ȭ�� ���
	*	@pre	����Ʈ�� �ʱ�ȭ ��
	*	@post	�ش� ����Ʈ�� ȭ�鿡 ��µ�
	*	@return	����� �����ϸ� 1, �׷��� ������ 0�� ��ȯ
	*/
	int RetrieveContents();

	/**
	*	@brief	�̸��� �Է¹޾Ƽ� ����Ʈ���� �ش� ����Ʈ�� ����Ž������ ã�� ȭ�� ���
	*	@pre	����Ʈ�� �ʱ�ȭ ��
	*	@post	�ش� ����Ʈ�� ȭ�鿡 ��µ�
	*	@return	����� �����ϸ� 1, �׷��� ������ 0�� ��ȯ
	*/
	int RetrieveContents_Binary();

	/**
	*	@brief	����Ʈ ���� ��� ������ ȭ�鿡 ���
	*	@pre	����Ʈ�� �ʱ�ȭ ��
	*	@post	����Ʈ ���� ��� ������ ȭ�鿡 ��µ�
	*/
	void DisplayAllContents();

	/**
	*	@brief	����Ʈ�� ���
	*	@pre	����
	*	@post	����Ʈ�� �����
	*/
	int MakeEmpty();

	/**
	*	@brief	�̸��� �Է¹ް� �ش� �̸��� ���Ե� ��� �׸��� ��� 
	*	@pre	����Ʈ�� �ʱ�ȭ ��
	*	@post	�ش� �̸��� ���Ե� ��� �׸��� ȭ�鿡 ��µ�
	*/
	int SearchByName();

	/**
	*	@brief	�������� ���Ե� ����� �Է¹޾Ƽ� �� ����� ����ִ� ��� �������� �ڼ��� ������ ȭ�鿡 ��� 
	*	@pre	����Ʈ�� �ʱ�ȭ ��
	*	@post	�ش� �������� ���Ե� ����� ���Ե� ��� �׸��� ȭ�鿡 ��µ�
	*/
	int SearchByPerson();

	/**
	*	@brief	�̺�Ʈ �޴��� ��� 
	*	@pre	event�� �ʱ�ȭ��
	*	@post	�̺�Ʈ �޴��� ȭ�鿡 ��µ�
	*/
	void EventMenu();
	
	/**
	*	@brief	�̺�Ʈ ������ ����
	*	@pre	event�� �ʱ�ȭ��
	*	@post	�̺�Ʈ ������ ������
	*/
	void ModifyEvent();

	/**
	*	@brief	�̺�Ʈ ����Ʈ���� �̺�Ʈ�� ã�� ������ ���
	*	@pre	�̺�Ʈ ����Ʈ�� �ʱ�ȭ��
	*	@post	�ش� �̺�Ʈ ������ ��µ�
	*/
	void FindNDisplayEvent();

	/**
	*	@brief	�̺�Ʈ ������ ����
	*	@pre	event�� �ʱ�ȭ��
	*	@post	�̺�Ʈ ������ ������
	*/
	void DisplayAllEvents();

	/**
	*	@brief	�������� �Է¹޾� �̺�Ʈ, �ι�, ��� �� ������ ����Ʈ�� �ش� �����͸� �߰�
	*	@pre	����
	*	@post	�̺�Ʈ, �ι�, ��� �� ������ ����Ʈ�� �ش� �����Ͱ� �߰���
	*	@param	mc �߰��� ������
	*	@return	����Ʈ�� �߰��ϸ� 1 �׷��� ������ 0�� ��ȯ
	*/
	int Add(MultimediaContent &mc);

	/**
	*	@brief	�������� �Է¹޾� �̺�Ʈ, �ι�, ��� �� ������ ����Ʈ�� �ش� �����͸� ����
	*	@pre	����
	*	@post	�̺�Ʈ, �ι�, ��� �� ������ ����Ʈ�� �ش� �����Ͱ� ���ŵ�
	*	@param	mc ������ ������
	*	@return	����Ʈ�� �߰��ϸ� 1 �׷��� ������ 0�� ��ȯ
	*/
	int Delete(MultimediaContent& mc);


private:
	ifstream m_InFile;///< input file descriptor.
	ofstream m_OutFile;///< output file descriptor.
	SortedList<MultimediaContent> m_List;///< item list.
	int m_Command;///< current command number.
	Application_FC m_appFC;// FC����
	SortedLinkedList<Event> eventList;
};