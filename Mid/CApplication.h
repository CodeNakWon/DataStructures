#pragma once

class Application
{
private:
	ifstream m_InFile;///< input file descriptor.
	ofstream m_OutFile;///< output file descriptor.
	List<Content> m_List;///< item list.
	SortedList<string> m_FVList; // ���ֺ��� ���� ����Ʈ
	SortedList<string> m_FPList; // ���ֺ��� ���� ����Ʈ
	GroupApplication GApp = GroupApplication(m_List); // �׷�App
	int m_Command;///< current command number.
	int fview = 10;//���ֺ��� ����Ʈ ���� ��ȸ��
	int order = 1; // ���ı���
	time_t curr_time;
	struct tm curr_tm;

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
	*	@brief	�������� �Է¹޾� �̺�Ʈ, �ι�, ��� �� ������ ����Ʈ�� �ش� �����͸� �߰�
	*	@pre	����
	*	@post	�̺�Ʈ, �ι�, ��� �� ������ ����Ʈ�� �ش� �����Ͱ� �߰���
	*	@param	mc �߰��� ������
	*	@return	����Ʈ�� �߰��ϸ� 1 �׷��� ������ 0�� ��ȯ
	*/
	int Add(Content& mc);


	/**
	*	@brief	�������� �Է¹޾� �̺�Ʈ, �ι�, ��� �� ������ ����Ʈ�� �ش� �����͸� ����
	*	@pre	����
	*	@post	�̺�Ʈ, �ι�, ��� �� ������ ����Ʈ�� �ش� �����Ͱ� ���ŵ�
	*	@param	mc ������ ������
	*	@return	����Ʈ�� �߰��ϸ� 1 �׷��� ������ 0�� ��ȯ
	*/
	int Delete(Content& mc);


	/**
	*	@brief	���ο� ���ڵ带 ����Ʈ�� �߰�
	*	@pre	����
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
	*	@brief	�̸��� �Է¹޾Ƽ� ����Ʈ���� �ش� ����Ʈ�� ����Ž������ ã�� ȭ�� ���
	*	@pre	����Ʈ�� �ʱ�ȭ ��
	*	@post	�ش� ����Ʈ�� ȭ�鿡 ��µ�
	*	@return	����� �����ϸ� 1, �׷��� ������ 0�� ��ȯ
	*/
	int RetrieveContents();


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
	*	@brief	���� ���� ','�� ���еǴ� Ű���带 �Է¹޾Ƽ� �ش� Ű���带 ���� �������� ��� ���
	*	@pre	����Ʈ�� �ʱ�ȭ ��
	*	@post	�ش� Ű���带 ���� �������� ��� ��µ�
	*/
	void SearchByKeyWords();


	/**
	*	@brief	���ֺ��� ������ ���
	*	@pre	����Ʈ�� �ʱ�ȭ ��
	*	@post	���ֺ��� ������ ��µ�
	*/
	void FViewedVideo();


	/*
	*	@brief	���ֺ��� ������ ���
	*	@pre	����Ʈ�� �ʱ�ȭ ��
	*	@post	���ֺ��� ������ ��µ�
	*/
	void FViewedPhoto();


	/**
	*	@brief	������ȸ�� �̻��̰�, ��ȸ���� �����ǿ� ���ϸ� ���ֺ��� ����Ʈ�� �߰�
	*	@pre	Content����Ʈ�� �ʱ�ȭ ��
	*	@post	���ֺ��� ������ ����Ʈ�� ������Ʈ ��
	*	@param	Content	��ȸ���� �ø� Content
	*/
	void UpdateView();
	

	/**
	*	@brief	���ֺ��� ����Ʈ���� �������� �˻�
	*	@pre	Content�� �ʱ�ȭ ��
	*	@post	�ش��������� ȭ�鿡 �����
	*/
	void FViewSearch();


	/**
	*	@brief	���ֺ��� ������ �޴��� ���
	*	@pre	����
	*	@post	�޴� ����� ȭ�鿡 ��µ�
	*/
	void FavoriteMenu();


	/**
	*	@brief	Content(������)����Ʈ�� ���ı��ؿ� ���� ���Ľ�Ŵ
	*	@pre	Content����Ʈ�� �ʱ�ȭ ��
	*	@post	Content(������)����Ʈ�� ���ı��ؿ� ���� ���ĵ�
	*/
	void SortMList();

};