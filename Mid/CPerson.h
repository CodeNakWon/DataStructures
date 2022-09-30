#pragma once

class Person: public Group
{
public:
	/**
	*	@brief	Ű����� �ι����� ����
	*	@pre	����
	*	@post	�ι����� ������
	*/
	void SetTitlefromKB() override;


	/**
	*	@brief	Ű����� �ι� ������ ����
	*	@pre	����
	*	@post	�ι� ������ ������
	*/
	void SetDescriptionfromKB() override;


	/**
	*@brief	�ι����� ȭ�鿡 ���
	*@pre	�ι����� ������
	*@post	�ι����� ȭ�鿡 ��µ�
	*/
	void DisplayTitle() override;


	/**
	*@brief	�ι� ������ ȭ�鿡 ���
	*@pre	����.
	*@post	�ι� ������ ȭ�鿡 ��µ�
	*/
	void DisplayDescriptionOnScreen() override;


	/**
	*@brief	�ι� ������ ȭ�鿡 ���
	*@pre	�ι� ���ڵ尡 �ʱ�ȭ ��
	*@post	�ι� ������ ȭ�鿡 ��µ�
	*/
	void DisplayRecordOnScreen() override;

};

