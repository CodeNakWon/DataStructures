#pragma once
#include <QWidget>
#include "pch.h"
#include "ui_Widget.h"

class Widget : public QWidget
{
	Q_OBJECT

public:
	Widget(QWidget* parent, int n, Group G);
	~Widget();
	void display();
	
private:
	Ui::Form ui;
	int n;
	Group gr;
	SortedList<QString> groups;
public slots:
	void open_con(int row, int col);
	void setDes();
};
