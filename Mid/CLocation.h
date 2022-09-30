#pragma once
class Location : public Group
{
public:
	/**
	*	@brief	Ű����� ��Ҹ��� ����
	*	@pre	����
	*	@post	��Ҹ��� ������
	*/
	void SetTitlefromKB() override;


	/**
	*	@brief	Ű����� ��� ������ ����
	*	@pre	����
	*	@post	��� ������ ������
	*/
	void SetDescriptionfromKB() override;


	/**
	*@brief	��Ҹ��� ȭ�鿡 ���
	*@pre	��Ҹ��� ������
	*@post	��Ҹ��� ȭ�鿡 ��µ�
	*/
	void DisplayTitle() override;


	/**
	*@brief	��� ������ ȭ�鿡 ���
	*@pre	����.
	*@post	��� ������ ȭ�鿡 ��µ�
	*/
	void DisplayDescriptionOnScreen() override;


	/**
	*@brief	��� ������ ȭ�鿡 ���
	*@pre	��� ���ڵ尡 �ʱ�ȭ ��
	*@post	��� ������ ȭ�鿡 ��µ�
	*/
	void DisplayRecordOnScreen() override;
};

