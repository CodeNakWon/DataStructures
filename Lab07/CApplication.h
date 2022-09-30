#pragma once

class Application
{
private:
	DoublyLinkedList<Content*> m_List;
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
	void AddMusic();

	/**
	*	@brief	���ο� ���� �������� ����Ʈ�� �߰�
	*	@pre	����
	*	@post	����Ʈ �ȿ� ���� �������� �߰���
	*/
	void AddPhoto();

	/**
	*	@brief	���ο� ������ �������� ����Ʈ�� �߰�
	*	@pre	����
	*	@post	����Ʈ ������ ���� �������� �߰���
	*/
	void AddVideo();
};