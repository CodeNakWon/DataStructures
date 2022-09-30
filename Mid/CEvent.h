#pragma once
class Event: public Group{

public:

	/**
	*	@brief	Ű����� �̺�Ʈ���� ����
	*	@pre	����
	*	@post	�̺�Ʈ���� ������
	*/
	void SetTitlefromKB() override;


	/**
	*	@brief	Ű����� �̺�Ʈ ������ ����
	*	@pre	����
	*	@post	�̺�Ʈ ������ ������
	*/
	void SetDescriptionfromKB() override;


	/**
	*@brief	�̺�Ʈ���� ȭ�鿡 ���
	*@pre	�̺�Ʈ���� ������
	*@post	�̺�Ʈ���� ȭ�鿡 ��µ�
	*/
	void DisplayTitle() override;


	/**
	*@brief	�̺�Ʈ ������ ȭ�鿡 ���
	*@pre	����.
	*@post	�̺�Ʈ ������ ȭ�鿡 ��µ�
	*/
	void DisplayDescriptionOnScreen() override;


	/**
	*@brief	�̺�Ʈ ������ ȭ�鿡 ���
	*@pre	�̺�Ʈ ���ڵ尡 �ʱ�ȭ ��
	*@post	�̺�Ʈ ������ ȭ�鿡 ��µ�
	*/
	void DisplayRecordOnScreen() override;

};
