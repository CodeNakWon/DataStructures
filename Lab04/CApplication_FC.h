#pragma once
class Application_FC {
private:
	List<FavoriteContent> m_FCList;
	//SortedList<MultimediaContent> MCList;
	SortedList<string> m_nameOrder;
	int m_CommandFC;
	int m_order = 0; // 0: ���� ������ ������, 1: �̸������� ������, 2: 
public:
	Application_FC() {};

	/**
	*	@brief	FC���α׷� ����̹�
	*	@pre	FC���α׷��� ���۵�
	*	@post	FC���α׷��� �����
	*/
	void Run(SortedList<MultimediaContent>& MCList);

	/**
	*	@brief	��ɾ ȭ�鿡 ��� �� Ű����� �Է��� ����
	*	@pre	����
	*	@post	����
	*	@return	����ڰ� �Է��� ��ɾ�
	*/
	int GetCommand();

	/**
	*	@brief	���������� �Է¹޾� �ش� ����Ʈ�� ������ ����Ʈ�� �����ϸ� FC����Ʈ�� �߰�
	*	@pre	����
	*	@post	FC����Ʈ�� �ش� �������� �߰���
	*	@param	MC ����Ʈ
	*	@return	����Ʈ�� �߰��ϸ� 1 �׷��� ������ 0�� ��ȯ
	*/
	int Add_FC(SortedList<MultimediaContent>& MCList);


	/**
	*	@brief	���������� �Է¹޾� �ش� �������� ����
	*	@pre	FC����Ʈ�� �ʱ�ȭ��
	*	@post	FC����Ʈ�� �ش� �������� ������
	*	@return	����Ʈ�� �����ϸ� 1 �׷��� ������ 0�� ��ȯ
	*/
	int Delete_FC();

	/**
	*	@brief	��� FC ������ ���
	*	@pre	FC����Ʈ�� �ʱ�ȭ��
	*	@post	��� FC������ ��µ�
	*/
	void Display_FC_list();
	
	/**
	*	@brief	���������� �Է¹޾� �ش� FC ������ �ڼ��ϰ� ���
	*	@pre	FC����Ʈ�� �ʱ�ȭ��
	*	@param	MC ����Ʈ
	*	@post	�ش� FC�� �ڼ��� ������ ��µ�
	*/
	int Display_Detail_FC(SortedList<MultimediaContent>& MCList);

	/**
	*	@brief	���������� �Է¹޾� �ش� FC ������ �ڼ��ϰ� ���
	*	@pre	FC����Ʈ�� �ʱ�ȭ��
	*	@param	MC ����Ʈ
	*/
	void  Rearrange_FC();

	/**
	*	@brief  �������� �Է¹޾� �ش� �������� FC����Ʈ���� ����
	*	@pre	FC����Ʈ�� �ʱ�ȭ��
	*	@param	MC ������ ������
	*	@post	�ش� MC�� FC����Ʈ���� ������
	*/
	int DeleteMContents(MultimediaContent &mc);
};
