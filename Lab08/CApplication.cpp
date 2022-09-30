#include "pch.h"
#include "CApplication.h"

//���α׷� ����̹�
void Application::Run() {
	while (1) {
		m_Command = GetCommand();
		switch (m_Command)
		{
		case 1:							
			Add();
			break;
		case 2:						
			Delete();
			break;
		case 3:					                 
			Retrieve();
			break;
		case 4:
			MakeEmpty();
			break;
		case 5:
			DisplayAll();
			break;
		case 0:
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}


// ȭ�鿡 ��ɾ ���
int Application::GetCommand() {
	int command;

	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t 1 : Add Content" << endl;
	cout << "\t 2 : Delete Content" << endl;
	cout << "\t 3 : Retrieve Video" << endl;
	cout << "\t 4 : MakeEmpty" << endl;
	cout << "\t 5 : Display all Content" << endl;
	cout << "\t 0 : Quit" << endl;
	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;
	return command;
}

// ������ ���� �������� ���
void Application::DisplayAll() {
	cout << "\t�� " << m_Tree.GetLength() << "���� ������" << endl;
	m_Tree.PrintTree(cout);
}

void Application::Add() {
	Photo newCon;
	cout << "\t������ �߰�" << endl;
	newCon.Read();
	m_Tree.Add(newCon);
}


void Application::Delete() {
	string title;
	Photo newCon;
	cout << "\t������ ������ : ";
	cin >> title;
	newCon.SetTitle(title);
	m_Tree.Delete(newCon);

}

void Application::Retrieve() {
	string title;
	Photo newCon;
	bool found;
	cout << "\t�˻��� ������ : ";
	cin >> title;
	newCon.SetTitle(title);
	m_Tree.Retrieve(newCon,found);
	if (found == true) {
		newCon.play();
	}
	else {
		cout << endl;
		cout << "\t�ش� �������� ã�� �� �����ϴ�." << endl;
	}
}

void Application::MakeEmpty() {
	m_Tree.MakeEmpty();
	cout << "\t����� ��� �������� �����߽��ϴ�."<<endl;
 }