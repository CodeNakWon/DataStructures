#include <QWidget>
#include <QDialog>
#include <QDateTime>
#include <qfiledialog.h>
#include "ui_AddCon.h"
#include "CContent.h"
#pragma once



class AddCon : public QDialog
{
	Q_OBJECT

public:
	
	//������ 
	AddCon::AddCon(QWidget* parent);
	
	AddCon::AddCon(QWidget* parent, Content c, int n);

	AddCon::~AddCon() {
	}

	/**
	*	@brief	�������� â�� ǥ��
	*	@pre	�������� �ʱ�ȭ��
	*	@post	������������ â�� ������
	*/
	void view_Content();

	/**
	*	@brief	�������� ����
	*	@pre	������ �������� primary key�� ��ġ�ϴ� �������� ����
	*	@post	������������ ����
	*/
	void replace_Content();
private:
	Content m_con;
	Ui::Dialog ui;
	QString filePath = "";
	int state = -1;

public slots:
	//ok ��ư Ŭ������ �� ȣ��
	void okClicked();
	//�̹����� ����Ž����� ã�� �Լ�
	void load_image();
};
