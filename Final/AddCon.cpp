#include "AddCon.h"
#include "GUIprogramming.h"

AddCon::AddCon(QWidget* parent) :
	QDialog(parent) {
	setWindowFlags(Qt::Window);
	ui.setupUi(this);
	QString time = QDateTime::currentDateTime().toString("yyyy/MM/dd") + " " + QTime::currentTime().toString("hh:mm:ss");
	ui.line_date->setText(time);
}
AddCon::AddCon(QWidget* parent, Content c, int n)
	:QDialog(parent), m_con(c), state(n) {
	setWindowFlags(Qt::Window);
	ui.setupUi(this);
	if (n == 0) {
		view_Content();
	}
	else if (n == 1) {
		replace_Content();
	}
}


void AddCon::replace_Content() {
	ui.line_name->setText(m_con.GetName());
	ui.line_name->setEnabled(false);
	ui.line_date->setText(m_con.GetDate());
	ui.line_person->setText(m_con.GetPerson());
	ui.line_location->setText(m_con.GetLocation());
	ui.line_event->setText(m_con.GetEventName());
	QPixmap img;
	img.load(m_con.GetPath());
	int w = ui.label_Display->width();
	int h = ui.label_Display->height();
	ui.label_Display->setPixmap(img.scaled(w, h, Qt::KeepAspectRatio));
}

void AddCon::view_Content() {

	ui.line_name->setText(m_con.GetName());
	ui.line_name->setEnabled(false);
	ui.line_date->setText(m_con.GetDate());
	ui.line_type->setCurrentText(m_con.GetType());
	ui.line_type->setEnabled(false);
	ui.line_person->setText(m_con.GetPerson());
	ui.line_person->setEnabled(false);
	ui.line_location->setText(m_con.GetLocation());
	ui.line_location->setEnabled(false);
	ui.line_event->setText(m_con.GetEventName());
	ui.line_event->setEnabled(false);
	QPixmap img;
	img.load(m_con.GetPath());
	int w = ui.label_Display->width();
	int h = ui.label_Display->height();
	ui.label_Display->setPixmap(img.scaled(w, h, Qt::KeepAspectRatio));
	ui.toolButton->setEnabled(false);
}

void AddCon::okClicked() {
	if (state == -1) {
		Content con;
		con.SetName(ui.line_name->text());
		con.SetDate(ui.line_date->text());
		con.SetType(ui.line_type->currentText());
		con.SetPerson(ui.line_person->text());
		con.SetLocation(ui.line_location->text());
		con.SetEventName(ui.line_event->text());
		con.SetPath(filePath);
		((GUIprogramming*)parent())->Add(con);
	}
	else if (state == 1) {
		Content con;
		con.SetName(ui.line_name->text());
		con.SetDate(ui.line_date->text());
		con.SetType(ui.line_type->currentText());
		con.SetPerson(ui.line_person->text());
		con.SetLocation(ui.line_location->text());
		con.SetEventName(ui.line_event->text());
		con.SetPath(filePath);
		((GUIprogramming*)parent())->Replace(con);
	}
	close();
}

//이미지를 파일 탐색기로 찾음
void AddCon::load_image() {
	
	QFileDialog dlg;
	filePath = dlg.getOpenFileName(this, "Load Image", "", "Image Files (*.png *.jpg *.bmp)");
	QPixmap img;
	img.load(filePath);
	int w = ui.label_Display->width();
	int h = ui.label_Display->height();
	ui.label_Display->setPixmap(img.scaled(w, h, Qt::KeepAspectRatio));
}

