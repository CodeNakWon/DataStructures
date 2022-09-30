#include "pch.h"
#include "CApplication.h"

//프로그램 드라이버
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


// 화면에 명령어를 출력
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

// 마스터 안의 컨텐츠를 출력
void Application::DisplayAll() {
	cout << "\t총 " << m_Tree.GetLength() << "개의 컨텐츠" << endl;
	m_Tree.PrintTree(cout);
}

void Application::Add() {
	Photo newCon;
	cout << "\t콘텐츠 추가" << endl;
	newCon.Read();
	m_Tree.Add(newCon);
}


void Application::Delete() {
	string title;
	Photo newCon;
	cout << "\t삭제할 컨텐츠 : ";
	cin >> title;
	newCon.SetTitle(title);
	m_Tree.Delete(newCon);

}

void Application::Retrieve() {
	string title;
	Photo newCon;
	bool found;
	cout << "\t검색할 컨텐츠 : ";
	cin >> title;
	newCon.SetTitle(title);
	m_Tree.Retrieve(newCon,found);
	if (found == true) {
		newCon.play();
	}
	else {
		cout << endl;
		cout << "\t해당 컨텐츠를 찾을 수 없습니다." << endl;
	}
}

void Application::MakeEmpty() {
	m_Tree.MakeEmpty();
	cout << "\t저장된 모든 컨텐츠를 삭제했습니다."<<endl;
 }