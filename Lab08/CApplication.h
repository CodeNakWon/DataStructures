#pragma once

class Application
{
private:
	BinarySearchTree<Photo> m_Tree;

	
	int m_Command;
public:

	//������
	Application() {}

	//�Ҹ���
	~Application() {}

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
	*	@brief	����Ʈ ���� ��� ������ ȭ�鿡 ���
	*	@pre	����Ʈ�� �ʱ�ȭ ��
	*	@post	����Ʈ ���� ��� ������ ȭ�鿡 ��µ�
	*/
	void DisplayAll();

	/**
	*	@brief	���ο� ���� �������� ����Ʈ�� �߰�
	*	@pre	����
	*	@post	����Ʈ �ȿ� ���� �������� �߰���
	*/
	void Add();

	void Retrieve();

	void Delete();

	void MakeEmpty();
};