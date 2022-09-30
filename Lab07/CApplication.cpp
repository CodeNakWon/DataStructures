#include "pch.h"
#include "CApplication.h"

//���α׷� ����̹�
void Application::Run() {
	while (1) {
		m_Command = GetCommand();
		switch (m_Command)
		{
		case 1:							
			AddMusic();
			break;
		case 2:						
			AddPhoto();
			break;
		case 3:					                 
			AddVideo();
			break;
		case 4:
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
	cout << "\t 1 : Add Music" << endl;
	cout << "\t 2 : Add Photo" << endl;
	cout << "\t 3 : Add Video" << endl;
	cout << "\t 4 : Display all Content" << endl;
	cout << "\t 0 : Quit" << endl;
	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;
	return command;
}

// ������ ���� �������� ���
void Application::DisplayAll() {
	Content* data;
	DoublyIterator<Content*> iter(m_List);
	while (iter.NotNull()) {
		data = iter.GetCurrentNode().data;
		data->play();
		iter.Next();
	}
}

// ������ ����Ʈ�� ���� �������� �߰� 
void Application::AddMusic() {
	Content* newCon = new Music();
	newCon->Read();
	m_List.Add(newCon);
}

// ������ ����Ʈ�� ���� �������� �߰� 
void Application::AddPhoto() {
	Content* newCon = new Photo();
	newCon->Read();
	m_List.Add(newCon);
}

// ������ ����Ʈ�� ������ �������� �߰� 
void Application::AddVideo() {
	Content* newCon = new Video();
	newCon->Read();
	m_List.Add(newCon);
}