#include "CItemType.h"
#pragma once

#define MAXSIZE 5
class ArrayList
{
public:
	ArrayList() {
		m_Length = 0;
		m_CurPointer = -1;
	}
	~ArrayList() {}

	/**
	*	@brief	����Ʈ�� ���
	*	@pre	����
	*	@post	����Ʈ�� �����
	*/
	void MakeEmpty();

	/**
	*	@brief	���� ����Ʈ�� ����� ����Ʈ�� ������ ������
	*	@pre	none.
	*	@post	none.
	*	@return	���� ����� ���ڵ��� ������ ��ȯ
	*/
	int GetLength();

	/**
	*	@brief	����Ʈ�� ���̰� �ִ뿡 ���ߴ��� Ȯ��
	*	@pre	none.
	*	@post	none.
	*	@return	����Ʈ�� ���̰� �ִ뿡 �������� true, �׷��� ������ false�� ��ȯ
	*/
	bool IsFull();

	/**
	*	@brief	����Ʈ�� ���ο� ItemType�� �߰�
	*	@pre	����Ʈ�� �ʱ�ȭ ��
	*	@post	����Ʈ�� ���ο� ���ڵ尡 �߰���
	*	@param	data	���� �߰� �� ItemType
	*	@return	�߰��� �����ϸ� 1, �Ȱ��� �̸��� ItemType������ 0, ����Ʈ�� �ִ�ġ�� -1�� ��ȯ
	*/
	int Add(ItemType data);

	/**
	*	@brief	���� ����Ʈ�� �а��ִ� �������� index�� �ʱ�ȭ
	*	@pre	����Ʈ�� �ʱ�ȭ ��
	*	@post	���� ����Ʈ�� �а��ִ� �������� index�� �ʱ�ȭ��
	*/
	void ResetList();

	/**
	*	@brief	�ݺ��ڰ� ����Ʈ�� ���� �׸��� ����Ű�� �ϰ� �ش� ItemType�� ������
	*	@pre	����Ʈ�� ����Ʈ �ݺ��ڰ� �ʱ�ȭ �Ǿ����
	*	@post	�ݺ��ڰ� ���� �׸����� �̵���
	*	@param	data	�ݺ��ڿ� �ش��ϴ� ItemType�� ������, �ʱ�ȭ �� �ʿ䰡 ����
	*	@return	���� �ݺ����� index�� ��ȯ, �ݺ��ڰ� ����Ʈ�� ���� �ٴٶ��� ��� -1�� ��ȯ
	*/
	int GetNextItem(ItemType& data);

	/**
	*	@brief	����Ʈ�� ����ִ��� Ȯ��
	*	@pre	����Ʈ�� �ʱ�ȭ��
	*	@post	����
	*	@return	����Ʈ�� ��������� ture, �ƴϸ� false�� ��ȯ
	*/
	bool isEmpty();

	/**
	*	@brief	�Էµ� �����Ϳ� ���� �̸��� ItemType�� �ִ��� ����Ʈ�ȿ��� ã�� �� ������
	*	@pre	����Ʈ�� �ʱ�ȭ ��
	*	@post	ã�� item type�� ������ ������
	*	@param	data	ã�� �������� �̸��� ���� ItemType
	*	@return	ItemType�� ������ ã�� �������� 1��, �׷��� ���ϸ� 0�� ��ȯ
	*/
	int Get(ItemType& data);


	/**
	*	@brief	�Էµ� �����Ϳ� ���� �̸��� ItemType�� �ִ��� ����Ʈ�ȿ��� ã�� �� ����
	*	@pre	����Ʈ�� �ʱ�ȭ ��
	*	@post	����Ʈ ���� �ش� �����Ͱ� ������
	*	@param	data	ã�� �������� �̸��� ���� ItemType
	*	@return	ItemType�� ������ ã�� �����ϸ� 1��, �׷��� ���ϸ� 0�� ��ȯ
	*/
	int Delete(ItemType data);

	/**
	*	@brief	�Էµ� �����Ϳ� ���� �̸��� ItemType�� �ִ��� ����Ʈ�ȿ��� ã�� �� ġȯ
	*	@pre	����Ʈ�� �ʱ�ȭ ��
	*	@post	����Ʈ ���� �ش� �����Ͱ� ġȯ��
	*	@param	data	ã�� �������� �̸��� ���� ItemType
	*	@return	ItemType�� ������ ã�� ġȯ�ϸ� 1��, �׷��� ���ϸ� 0�� ��ȯ
	*/
	int Replace(ItemType data);
private:
	ItemType m_Array[MAXSIZE]; // ���ڵ� �迭
	int m_Length; // ����Ʈ�� ����� ���ڵ� ��
	int m_CurPointer; // current pointer
};

