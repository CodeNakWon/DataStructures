#include "GUIprogramming.h"
#include "Widget.h"


Widget::Widget(QWidget* parent, int n, Group G)
	: QWidget(parent), n(n), groups(G.Getitems()), gr(G)
{
	setWindowFlags(Qt::Window);
	ui.setupUi(this);
	ui.text_description->setPlainText(G.GetDescription());
	display();
}

Widget::~Widget()
{
}

void Widget::display() {
	QString gname;
	groups.ResetList();
	while(groups.GetNextItem(gname) != -1){
		ui.tableWidget->insertRow(ui.tableWidget->rowCount());
		ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 0, new QTableWidgetItem(gname));
	}

}

void Widget::open_con(int row, int col) {
	Content con;
	con.SetName(ui.tableWidget->item(row,0)->text());
	((GUIprogramming*)parent())->Display(con);
}

void Widget::setDes() {
	gr.SetDescription(ui.text_description->toPlainText());
	QMessageBox::information(this, gr.GetTitle(), QString::number(n));
	((GUIprogramming*)parent())->SetDescription(gr, n);
	close();
}