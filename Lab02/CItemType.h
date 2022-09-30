#pragma once
#include <iostream>
#include <fstream>
using namespace std;

enum RelationType { LESS, GREATER, EQUAL };
enum ContentType { PICTURE = 0, VIDEO = 1, UNKNOWN = -1 };

class ItemType {
public:
	ItemType() {}
	~ItemType() {}

	/**
	*	@brief	������ �̸��� ������
	*	@pre	������ �̸��� ������
	*	@post	����
	*	@return	������ �̸�
	*/
	string GetName() const;

	/**
	*	@brief	������ ������ ������
	*	@pre	������ ������ ������
	*	@post	����
	*	@return	������ ����
	*/
	ContentType GetType() const;

	/**
	*	@brief	������ ���� ��¥�� �ð��� ������
	*	@pre	������ ���� ��¥�� �ð��� ������
	*	@post	����
	*	@return	������ ���� ��¥�� �ð�
	*/
	string GetDate() const;

	/**
	*	@brief	�������� ���Ե� �ι����� ������
	*	@pre	�������� ���Ե� �ι����� ������
	*	@post	����
	*	@return	�������� ���Ե� �ι���
	*/
	string GetPerson() const;


	/**
	*	@brief	������ ������ ������
	*	@pre	������ ������ ������
	*	@post	����
	*	@return	������ ����
	*/
	int GetCategory() const;

	/**
	*	@brief	������ �̺�Ʈ���� ������
	*	@pre	������ �̺�Ʈ���� ������
	*	@post	����
	*	@return	������ �̺�Ʈ��
	*/
	string GetEventName() const;

	/**
	*	@brief	������ �̸��� ����
	*	@pre	����
	*	@post	������ �̸��� ������
	*	@param	inName	������ �̸�
	*/
	void SetName(string inName);

	/**
	*	@brief	������ ������ ����
	*	@pre	����
	*	@post	������ ������ ������
	*	@param	inType	������ ����
	*/
	void SetType(ContentType inType);

	/**
	*	@brief	�������� ������ ��¥�� �ð��� ����
	*	@pre	����
	*	@post	�������� ������ ��¥�� �ð��� ������
	*	@param	inDate	�������� ������ ��¥�� �ð�
	*/
	void SetDate(string inDate);

	/**
	*	@brief	�������� ���Ե� �ι����� ����
	*	@pre	����
	*	@post	�������� ���Ե� �ι����� ������
	*	@param	inPerson  �������� ���Ե� �ι���
	*/
	void SetPerson(string inPerson);

	/**
	*	@brief	������ ���и��� ����
	*	@pre	����
	*	@post	������ ������ ������
	*	@param	inCategory  ������ ����
	*/
	void SetCategory(int inCategory);

	/**
	*	@brief	������ �̺�Ʈ���� ����
	*	@pre	����
	*	@post	������ �̺�Ʈ���� ������
	*	@param	inEventName	������ �̺�Ʈ��
	*/
	void SetEventName(string inEventName);

	/**
	*	@brief	������ ���ڵ带 ����
	*	@pre	����
	*	@post	������ ���ڵ尡 ������
	*	@param	inName	������ �̸�
	*	@param	inType	������ ����
	*	@param	inDate	�������� ������ ��¥�� �ð�
	*	@param	inPerson  �������� ���Ե� �ι���
	*	@param	inEventName	������ �̺�Ʈ��
	*/
	void SetRecord(string inName, ContentType inType, string inDate, string inPerson, string inEventName); // �̺�Ʈ ���� ����

	/**
	*	@brief	������ �̸��� ȭ�鿡 ���
	*	@pre	������ �̸��� ������
	*	@post	������ �̸��� ȭ�鿡 ��µ�
	*/
	void DisplayNameOnScreen() const;

	/**
	*	@brief	������ ������ ȭ�鿡 ���
	*	@pre	������ ������ ������
	*	@post	������ �������� ȭ�鿡 ��µ�
	*/
	void DisplayTypeOnScreen() const;

	/**
	*@brief	������ ���� ��¥�� �ð��� ȭ�鿡 ���
	*@pre	������ ���� ��¥�� �ð��� ������
	*@post	������ ���� ��¥�� �ð��� ȭ�鿡 ��µ�
	*/
	void DisplayDateOnScreen() const;

	/**
	*@brief	�������� ���Ե� �ι����� ȭ�鿡 ���
	*@pre	�������� ���Ե� �ι����� ������
	*@post	�������� ���Ե� �ι����� ȭ�鿡 ��µ�
	*/
	void DisplayPersonOnScreen() const;

	/**
	*@brief	������ ������ ȭ�鿡 ���
	*@pre	������ ������ ������
	*@post	������ ������ ȭ�鿡 ��µ�
	*/
	void DisplayCategoryOnScreen() const;

	/**
	*@brief	������ �̺�Ʈ���� ȭ�鿡 ���
	*@pre	������ �̺�Ʈ���� ������
	*@post	������ �̺�Ʈ���� ȭ�鿡 ��µ�
	*/
	void DisplayEventNameOnScreen() const;

	/**
	*@brief	������ ���ڵ带 ȭ�鿡 ���
	*@pre	������ ���ڵ尡 ������
	*@post	������ ���ڵ尡 ȭ�鿡 ��µ�
	*/
	void DisplayRecordOnScreen() const;


	/**
	*	@brief	Ű����� ������ �̸��� ����
	*	@pre	����
	*	@post	������ �̸��� ������
	*/
	void SetNameFromKB();

	/**
	*	@brief	Ű����� ������ ������ ����
	*	@pre	����
	*	@post	������ ������ ������
	*/
	void SetTypeFromKB();

	/**
	*	@brief	Ű����� ������ ���� ��¥�� �ð��� ����
	*	@pre	����
	*	@post	������ ���� ��¥�� �ð��� ������
	*/
	void SetDateFromKB();

	/**
	*	@brief	Ű����� �������� ���Ե� �ι��� ����
	*	@pre	����
	*	@post	�������� ���Ե� �ι��� ������
	*/
	void SetPersonFromKB();

	/**
	*	@brief	Ű����� ������ ������ ����
	*	@pre	����
	*	@post	������ ������ ������
	*/
	void SetCategoryFromKB();

	/**
	*	@brief	Ű����� ������ �̺�Ʈ���� ����
	*	@pre	����
	*	@post	������ �̺�Ʈ���� ������
	*/
	void SetEventNameFromKB();

	/**
	*	@brief	Ű����� ������ ���ڵ带 ����
	*	@pre	����
	*	@post	������ ���ڵ尡 ������
	*/
	void SetRecordFromKB();

	/**
	*	@brief	���Ϸκ��� ���ڵ带 �о����
	*	@pre	���������ϴ� ������ ����
	*	@post	������ ���ڵ尡 ������
	*	@param	fin	���� ��ũ����
	*	@return	���������� �۵��ҽ� 1�� ��ȯ, �ƴҽ� 0�� ��ȯ
	*/
	int ReadDataFromFile(ifstream& fin);

	/**
	*	@brief	���Ͽ� ���ڵ带 �ۼ�
	*	@pre	���� ������ ����, ���ڵ��� �� �׸��� �ʱ�ȭ ��
	*	@post	���������� �� ���ڵ��� ������ ����
	*	@param	fout	���� ��ũ����
	*	@return	���������� �۵��ҽ� 1�� ��ȯ, �ƴҽ� 0�� ��ȯ
	*/
	int WriteDataToFile(ofstream& fout);

	/**
	*	�� itemtypes�� ��
	*	@brief	�� item type�� �̸����� ��
	*	@pre	�� item type�� �ʱ�ȭ ��
	*	@param	data	�񱳴���� �Ǵ� itemType��ü
	*	@return	return EQUAL if this.name == data.name,
	*			return LESS if this.id < data.id
	*			return GREATER if this.id > data.id
	*/
	RelationType CompareByName(const ItemType& data);

private:
	string m_cName; // ������ ���ϸ�
	ContentType m_cType; //������ ����
	string m_Date; // ������¥�� �ð� YYYY/MM/DD/HH/mm���� ����
	string m_Person; // �������� ���Ե� ���
	int m_Category; // ������ ����
	string m_EventName; // �̺�Ʈ��
};