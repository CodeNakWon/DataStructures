#pragma once
#include "CArrayList.h"

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
	*	@brief	����Ʈ ���� ��� ������ ȭ�鿡 ���
	*	@pre	����Ʈ�� �ʱ�ȭ ��
	*	@post	����Ʈ ���� ��� ������ ȭ�鿡 ��µ�
	*/
	void DisplayAllContents();

	/**
	*	@brief	����Ʈ�� ���
	*	@pre	����
	*	@post	����Ʈ�� �����
	*	@return	����� �����ϸ� 1, �׷��� ������ 0�� ��ȯ
	*/
	int MakeEmpty();

private:
	ifstream m_InFile;///< input file descriptor.
	ofstream m_OutFile;///< output file descriptor.
	ArrayList m_List;///< item list.
	int m_Command;///< current command number.
};