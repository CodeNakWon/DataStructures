#include "pch.h"
#include "GUIprogramming.h"


GUIprogramming::GUIprogramming(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    ui.tableWidget->setSortingEnabled(true);
    ui.tabWidget->setTabText(0, "Person");
    ui.tabWidget->setTabText(1, "Location");
    ui.tabWidget->setTabText(2, "Event");
    ui.tabWidget_2->setTabText(0, "Photo");
    ui.tabWidget_2->setTabText(1, "Video");
}



void GUIprogramming::Update_Group(int n) {
    Group g;
    if (n == 1) {
        m_person.ResetList();
        for (int i = 0; i < m_person.GetLength(); i++) {
            m_person.GetNextItem(g);
            ui.table_Person->item(i, 0)->setText(g.GetTitle());
            ui.table_Person->item(i, 1)->setText(g.GetDescription());
            ui.table_Person->item(i, 2)->setText(QString::number(g.GetLenght()));
        }
    }
    if (n == 2) {
        m_location.ResetList();
        for (int i = 0; i < m_location.GetLength(); i++) {
            m_location.GetNextItem(g);
            ui.table_Location->item(i, 0)->setText(g.GetTitle());
            ui.table_Location->item(i, 1)->setText(g.GetDescription());
            ui.table_Location->item(i, 2)->setText(QString::number(g.GetLenght()));
        }
    }
    if (n == 3) {
        m_event.ResetList();
        for (int i = 0; i < m_event.GetLength(); i++) {
            m_event.GetNextItem(g);
            ui.table_Event->item(i, 0)->setText(g.GetTitle());
            ui.table_Event->item(i, 1)->setText(g.GetDescription());
            ui.table_Event->item(i, 2)->setText(QString::number(g.GetLenght()));
        }
    }
}

void GUIprogramming::DrawTable() {
    Content con;
    m_MList.ResetList();
   for (int i = 0; i < m_MList.GetLength(); i++) {
       m_MList.GetNextItem(con);
       ui.tableWidget->item(i, 0)->setText(con.GetName());
       ui.tableWidget->item(i, 1)->setText(con.GetType());
       ui.tableWidget->item(i, 2)->setText(con.GetDate());
       ui.tableWidget->item(i, 3)->setText(con.GetPerson());
       ui.tableWidget->item(i, 4)->setText(con.GetLocation());
       ui.tableWidget->item(i, 5)->setText(con.GetEventName());
   }
}

void GUIprogramming::Add_Group(Content con) {
    Group P;
    P.SetTitle(con.GetPerson());
    if (m_person.Retrieve(P) == 1) {
        P.Add(con);
        m_person.Replace(P);
    }
    else {
        P.Add(con);
        m_person.Add(P);
        ui.table_Person->insertRow(ui.table_Person->rowCount());
        ui.table_Person->setItem(ui.table_Person->rowCount() - 1, 0, new QTableWidgetItem(""));
        ui.table_Person->setItem(ui.table_Person->rowCount() - 1, 1, new QTableWidgetItem(""));
        ui.table_Person->setItem(ui.table_Person->rowCount() - 1, 2, new QTableWidgetItem(""));
    }
    
    Group L;
    L.SetTitle(con.GetLocation());
    if (m_location.Retrieve(L)==1) {
        L.Add(con);
        m_location.Replace(L);
    }
    else {
        L.Add(con);
        m_location.Add(L);
        ui.table_Location->insertRow(ui.table_Location->rowCount());
        ui.table_Location->setItem(ui.table_Location->rowCount() - 1, 0, new QTableWidgetItem(""));
        ui.table_Location->setItem(ui.table_Location->rowCount() - 1, 1, new QTableWidgetItem(""));
        ui.table_Location->setItem(ui.table_Location->rowCount() - 1, 2, new QTableWidgetItem(""));
    }
    
    Group E;
    E.SetTitle(con.GetEventName());
    if (m_event.Retrieve(E)==1) {
        E.Add(con);
        m_event.Replace(E);
    }
    else {
        E.Add(con);
        m_event.Add(E);
        ui.table_Event->insertRow(ui.table_Event->rowCount());
        ui.table_Event->setItem(ui.table_Event->rowCount() - 1, 0, new QTableWidgetItem(""));
        ui.table_Event->setItem(ui.table_Event->rowCount() - 1, 1, new QTableWidgetItem(""));
        ui.table_Event->setItem(ui.table_Event->rowCount() - 1, 2, new QTableWidgetItem(""));
    }
    
}

void GUIprogramming::Add(Content con) {
    if (m_MList.Add(con) == 1) {
        Add_Group(con);
        Update_Group(1);
        Update_Group(2);
        Update_Group(3);

        ui.tableWidget->insertRow(ui.tableWidget->rowCount());
        int index = ui.tableWidget->rowCount() - 1;
        ui.tableWidget->setItem(index, 0, new QTableWidgetItem(""));
        ui.tableWidget->setItem(index, 1, new QTableWidgetItem(""));
        ui.tableWidget->setItem(index, 2, new QTableWidgetItem(""));
        ui.tableWidget->setItem(index, 3, new QTableWidgetItem(""));
        ui.tableWidget->setItem(index, 4, new QTableWidgetItem(""));
        ui.tableWidget->setItem(index, 5, new QTableWidgetItem(""));
        DrawTable();
    }
}


void GUIprogramming::Replace(Content con) {
    Content tmp;
    
    tmp.SetName(con.GetName());
    
    m_MList.Retrieve(tmp);
    Delete_Group(tmp);

    Update_Group(1);
    Update_Group(2);
    Update_Group(3);
  
    Add_Group(con);

    Update_Group(1);
    Update_Group(2);
    Update_Group(3);
  
    m_MList.Replace(con);
    ui.tableWidget->item(m_HiRow, 0)->setText(con.GetName());
    ui.tableWidget->item(m_HiRow, 1)->setText(con.GetType());
    ui.tableWidget->item(m_HiRow, 3)->setText(con.GetPerson());
    ui.tableWidget->item(m_HiRow, 4)->setText(con.GetLocation());
    ui.tableWidget->item(m_HiRow, 5)->setText(con.GetEventName());

    
}

void GUIprogramming::Delete_Group(Content con) {
    Group P;
    P.SetTitle(con.GetPerson());
    if (m_person.Retrieve(P) == 1) {
        if (P.GetLenght() == 1) {
            for (int i = 0; i < m_person.GetLength(); i++) {
                if (ui.table_Person->item(i, 0)->text() == P.GetTitle()) {
                    ui.table_Person->removeRow(i);
                    break;
                }
            }
            m_person.Delete(P);
        }
        else{
            P.Delete(con);
            m_person.Replace(P);
        }
    }
    Group L;
    L.SetTitle(con.GetLocation());
    if (m_location.Retrieve(L) == 1) {
        if (L.GetLenght() == 1) {
            for (int i = 0; i < m_location.GetLength(); i++) {
                if (ui.table_Location->item(i, 0)->text() == L.GetTitle()) {
                    ui.table_Location->removeRow(i);
                    break;
                }
            }
            m_location.Delete(L);
        }
        else {
            L.Delete(con);
            m_location.Replace(L);
        }
    }
    Group E;
    E.SetTitle(con.GetEventName());
    if (m_event.Retrieve(E) == 1) {
        if (E.GetLenght() == 1) {
            for (int i = 0; i < m_event.GetLength(); i++) {
                if (ui.table_Event->item(i, 0)->text() == E.GetTitle()) {
                    ui.table_Event->removeRow(i);
                    break;
                }
            }
            m_event.Delete(E);
        }
        else {
            E.Delete(con);
            m_event.Replace(E);
        }
    }
}

void GUIprogramming::Delete(Content con) {
    if (m_MList.Delete(con) == 1) {
        Delete_Group(con);
        Update_Group(1);
        Update_Group(2);
        Update_Group(3);
        ui.tableWidget->removeRow(m_HiRow);
        QString cname;
        cname = con.GetName();
        if (m_fp.Retrieve(cname)) {
            for (int i = 0; i < m_fp.GetLength(); i++) {
                if (ui.table_FP->item(i, 0)->text()==cname) {
                    ui.table_FP->removeRow(i);
                }
            }
            m_fp.Delete(cname);
        }
        else if (m_fv.Retrieve(cname)) {
            for (int i = 0; i < m_fv.GetLength(); i++) {
                if (ui.table_FV->item(i, 0)->text() == cname) {
                    ui.table_FV->removeRow(i);
                }
            }
             m_fv.Delete(cname);
        }
    }
}

void GUIprogramming::Display(Content con) {
    m_MList.Retrieve(con);
    delete newWin_Add;
    newWin_Add = new AddCon(this, con, 0);
    newWin_Add->exec();
}


void GUIprogramming::SetDescription(Group g, int n) {
    if (n == 0) {
        m_person.Replace(g);
        Update_Group(1);
    }
    else if (n == 1) {
        m_location.Replace(g);
        Update_Group(2);
    }
    else if (n == 2) {
        m_event.Replace(g);
        Update_Group(3);
    }
}

/// <summary>
/// --------Slot---------------------------------------------------
/// </summary>

void GUIprogramming::open_Add() {

        delete newWin_Add;
        newWin_Add = new AddCon(this);
        newWin_Add->exec();
        
}

void GUIprogramming::display_content(int row, int col) {
    Content con;
    con.SetName("");
    con.SetName(ui.tableWidget->item(row, 0)->text());
    Display(con);
}

void GUIprogramming::select_Row(int row, int col) {
    m_HiRow = row;
}

void GUIprogramming::open_Replace() {
    Content con;
    con.SetName(ui.tableWidget->item(m_HiRow, 0)->text());
    m_MList.Retrieve(con);
    delete newWin_Add;
    newWin_Add = new AddCon(this,con,1);
    newWin_Add->exec();
}



void GUIprogramming::open_delete() {
    Content con;
    con.SetName(ui.tableWidget->item(m_HiRow, 0)->text());
    m_MList.Retrieve(con);
    QMessageBox msgBox;
    msgBox.setWindowTitle("Delete");
    QString text = "Delete \""+ con.GetName() + "\"?";
    msgBox.setText(text);
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Ok);
    if (msgBox.exec() == QMessageBox::Ok) {
        Delete(con);
    }
}

void GUIprogramming::search_con() {
    Content con;
    con.SetName(ui.line_Msearch->text());
    if (m_MList.Retrieve(con) == 1) {
        delete newWin_Add;
        newWin_Add = new AddCon(this, con, 0);
        newWin_Add->exec();
    }
    else {
        QMessageBox::information(this, "Search", "can not find the content");
    }
}

void GUIprogramming::open_group(int row, int col) {
    delete newWin_Group;
    Group g;
    int index = ui.tabWidget->currentIndex();
    if (index == 0) {
        g.SetTitle(ui.table_Person->item(row,0)->text());
        m_person.Retrieve(g);
    }
    else if (index == 1) {
        g.SetTitle(ui.table_Location->item(row, 0)->text());
        m_location.Retrieve(g);
    }
    else if (index == 2) {
        g.SetTitle(ui.table_Event->item(row, 0)->text());
        m_event.Retrieve(g);
    }
    newWin_Group = new Widget(this,index,g);
    newWin_Group->show();
}

void GUIprogramming::search_advanced() {
    bool found = false;
    found = Find_Group();
    while (ui.tableW_search->rowCount() > 0) {
        ui.tableW_search->removeRow(0);
    }
    if (found) {
        ui.tableW_search->setRowCount(m_keys.GetLength());
        QString str;
        m_keys.ResetList();
        for (int i = 0; i < m_keys.GetLength(); i++) {
            m_keys.GetNextItem(str);
            ui.tableW_search->setItem(i, 0, new QTableWidgetItem(str));
        }
    }
    else {
        QMessageBox::information(this, "Search", "can not find the content");
    }
}

bool GUIprogramming::Find_Group() {
    bool isInit = true;
    SortedList<QString> cons;
    SortedList<QString> tmp;
    SortedList<QString> keys;
    QString str;
    Group p;

    if (ui.checkBox_person->isChecked()) {
        isInit = false;
        p.SetTitle(ui.line_person->text());
        if (m_person.Retrieve(p) == 1) {
            keys = p.Getitems();
        }
        else {
            return false;
        }
    }
    if (ui.checkBox_location->isChecked()) {
        p.SetTitle(ui.line_location->text());
        if (m_location.Retrieve(p) == 1) {
            if (isInit) {
                isInit = false;
                keys = p.Getitems();
            }
            else {
                tmp = p.Getitems();
                tmp.ResetList();
                while (tmp.GetNextItem(str)!=-1) {
                    if (keys.Retrieve(str) == 1) {
                        cons.Add(str);
                    }
                }
                keys = cons;
                cons.MakeEmpty();
            }
        }
        else {
            return false;
        }
    }
    if (ui.checkBox_event->isChecked()) {
        p.SetTitle(ui.line_event->text());
        if (m_event.Retrieve(p) == 1) {
            if (isInit) {
                isInit = false;
                keys = p.Getitems();
            }
            else {
                tmp = p.Getitems();
                tmp.ResetList();
                while (tmp.GetNextItem(str) != -1) {
                    if (keys.Retrieve(str) == 1) {
                        cons.Add(str);
                    }
                }
                keys = cons;
            }
        }
        else {
            return false;
        }
    }
    m_keys = keys;
    return true;
}

void GUIprogramming::display_content_g(int row, int col) {
    Content con;
    con.SetName("");
    con.SetName(ui.tableW_search->item(row, 0)->text());
    Display(con);
}

void GUIprogramming::add_favorite() {
    QString cname = ui.tableWidget->item(m_HiRow, 0)->text();
    Content con;
    bool added_p;
    bool added_v;
    con.SetName(cname);
    if (m_MList.Retrieve(con)) {
        if (con.GetType() == "Photo") {
            added_p = m_fp.Add(cname);
        }
        else {
            added_v = m_fv.Add(cname);
        }
    }
    if (added_p) {
        while (ui.table_FP->rowCount() > 0) {
            ui.table_FP->removeRow(0);
        }
        ui.table_FP->setRowCount(m_fp.GetLength());
        QString str;
        m_fp.ResetList();
        for (int i = 0; i < m_fp.GetLength(); i++) {
            m_fp.GetNextItem(str);
            ui.table_FP->setItem(i, 0, new QTableWidgetItem(str));
        }
    }
    if (added_v) {
        while (ui.table_FV->rowCount() > 0) {
            ui.table_FV->removeRow(0);
        }
        ui.table_FV->setRowCount(m_fv.GetLength());
        QString str;
        m_fv.ResetList();
        for (int i = 0; i < m_fv.GetLength(); i++) {
            m_fv.GetNextItem(str);
            ui.table_FV->setItem(i, 0, new QTableWidgetItem(str));
        }
    }
}

void GUIprogramming::delete_favorite() {
    QString name;
    if (ui.tabWidget_2->currentIndex() == 0) {
        name = ui.table_FP->item(m_Hif, 0)->text();
        m_fp.Delete(name);
        ui.table_FP->removeRow(m_Hif);
    }
    else if (ui.tabWidget_2->currentIndex() == 1) {
        name = ui.table_FV->item(m_Hif, 0)->text();
        m_fv.Delete(name);
        ui.table_FV->removeRow(m_Hif);
    }
}

void GUIprogramming::selet_FRow(int row, int col) {
    m_Hif = row;
}

void GUIprogramming::display_content_f(int row, int col) {
    if (ui.tabWidget_2->currentIndex() == 0) {
        Content con;
        con.SetName("");
        con.SetName(ui.table_FP->item(row, 0)->text());
        Display(con);
    }
    else if (ui.tabWidget_2->currentIndex() == 1) {
        Content con;
        con.SetName("");
        con.SetName(ui.table_FV->item(row, 0)->text());
        Display(con);
    }
}