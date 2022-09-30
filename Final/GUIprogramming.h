#pragma once
#include "ui_GUIprogramming.h"
#include "pch.h"



class GUIprogramming : public QMainWindow
{
    Q_OBJECT

public:
    GUIprogramming(QWidget *parent = Q_NULLPTR);


    /**
    *	@brief	�������� �߰��Ѵ�
    *	@pre	����
    *	@post	�������� �����͸���Ʈ�� �߰���
    *	@param	con �߰��� ������
    */
    void Add(Content con);


    /**
    *	@brief	�������� �߰��Ѵ�
    *	@pre	����
    *	@post	�������� �����͸���Ʈ�� �߰���
    *	@param	con �߰��� ������
    */
    void Delete(Content con);


    /**
    *	@brief	�������� �����Ѵ�.
    *	@pre	
    *	@post	�������� ������
    *	@param	con �߰��� ������
    */
    void Replace(Content con);

    /**
    *	@brief	���� ���̺��� �׸���.
    *	@pre    �����͸���Ʈ�� �ʱ�ȭ��
    *	@post	���� ���̺��� �׷���
    */
    void DrawTable();

    /**
    *	@brief	�׷� ���̺��� �ٽ� �׸���.
    *	@pre    �׷츮��Ʈ�� �ʱ�ȭ��
    *	@post	�׷� ���̺��� �׷���
    *	@param	n �ٽñ׸� ���̺��� index
    */
    void Update_Group(int n);

    /**
    *	@brief	�������� �׷쿡 �߰��Ѵ�.
    *	@pre    ����
    *	@post	�������� �׷� ����Ʈ�� �߰���
    *	@param	con �߰��� ������
    */
    void Add_Group(Content con);

    /**
    *	@brief	�������� �׷쿡�� �����Ѵ�.
    *	@pre    ����
    *	@post	�������� �׷� ����Ʈ���� ������
    *	@param	con ������ ������
    */
    void Delete_Group(Content con);

    /**
    *	@brief	�������� ȭ�鼭 �����ش�.
    *	@pre    �������� �ʱ�ȭ��
    *	@post	�������� ȭ�鿡 ������
    *	@param	con ������ ������
    */
    void Display(Content con);

    /**
    *	@brief	�׷� ������ �����Ѵ�
    *	@pre    ����
    *	@post	�׷� ������ ������
    *	@param	g �׷켳���� ������ �׷�
    *  	@param	n ������ �׷��� index
    */
    void SetDescription(Group g, int n);

    /**
    *	@brief	üũ�ڽ��� �Է��� �������� �׷��� ã�´�.
    *	@pre    ����
    *	@post	�׷��� ã��
    *  	@return ��ġ�ϴ� �׷��� �����ϸ� ture �׷��� ������ false �� ��ȯ 
    */
    bool Find_Group();

private:
    Ui::GUIprogrammingClass ui;
    AddCon* newWin_Add = Q_NULLPTR;
    Widget* newWin_Group = Q_NULLPTR;
    bool isOpened_Add = false;
    SortedList<Content> m_MList; // ������ ����Ʈ
    int m_HiRow = 0; // ������ ���̺��� ���õ� ��
    int m_Hif = 0; // �����ϴ� ���̺��� ���õ� ��
    int m_GRow = 0; // �׷� ���̺��� ���õ� ��
    SortedList<Group> m_event; // �̺�Ʈ ����Ʈ
    SortedList<Group> m_person; // ��� ����Ʈ
    SortedList<Group> m_location; // ��� ����Ʈ
    SortedList<QString> m_keys; // �˻��� ���� ����Ʈ
    SortedList<QString> m_fp; // �����ϴ� ���� ����Ʈ
    SortedList<QString> m_fv; // �����ϴ� ���� ����Ʈ
public slots:
    // �������̺��� ����� �������� �� ȣ��
    void select_Row(int row, int col);

    // �߰���ư�� ������ �� ȣ��
    void open_Add();

    // ���� ��ư�� ������ �� ȣ��
    void open_delete();

    // ���� �׸��� ������ �� ȣ��
    void open_Replace();

    // �������̺��� �׸��� ����Ŭ�� ���� �� ȣ��
    void display_content(int row, int col);

    // �׷����̺��� �׸��� ����Ŭ�� ���� �� ȣ��
    void display_content_g(int row, int col);

    // �����ϴ� ������ ���̺��� �׸��� ����Ŭ�� ���� �� ȣ��
    void display_content_f(int row, int col);

    //�˻��� ������ �� ȣ��
    void search_con();

    //�׷����̺��� �׸��� ���� Ŭ������ �� ȣ��
    void open_group(int row, int col);

    //�� �˻���
    void search_advanced();

    //���ƿ並 �������� ȣ��
    void add_favorite();

    //-��ư�� �������� ȣ��
    void delete_favorite();

    //�����ϴ� ����Ʈ���� ���ý� ȣ��
    void selet_FRow(int row, int col);
};
