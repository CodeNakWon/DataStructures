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
	
	//생성자 
	AddCon::AddCon(QWidget* parent);
	
	AddCon::AddCon(QWidget* parent, Content c, int n);

	AddCon::~AddCon() {
	}

	/**
	*	@brief	컨텐츠를 창에 표시
	*	@pre	컨텐츠가 초기화됨
	*	@post	컨텐츠정보가 창에 보여짐
	*/
	void view_Content();

	/**
	*	@brief	컨텐츠를 수정
	*	@pre	수정할 컨텐츠와 primary key가 일치하는 컨텐츠가 존재
	*	@post	컨텐츠정보를 수정
	*/
	void replace_Content();
private:
	Content m_con;
	Ui::Dialog ui;
	QString filePath = "";
	int state = -1;

public slots:
	//ok 버튼 클릭했을 때 호출
	void okClicked();
	//이미지를 파일탐색기로 찾는 함수
	void load_image();
};
