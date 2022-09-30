#include "pch.h"
#include "CApplication.h"

//프로그램 드라이버
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


// 화면에 명령어를 출력
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

// 마스터 안의 컨텐츠를 출력
void Application::DisplayAll() {
	Content* data;
	DoublyIterator<Content*> iter(m_List);
	while (iter.NotNull()) {
		data = iter.GetCurrentNode().data;
		data->play();
		iter.Next();
	}
}

// 마스터 리스트에 음악 컨텐츠를 추가 
void Application::AddMusic() {
	Content* newCon = new Music();
	newCon->Read();
	m_List.Add(newCon);
}

// 마스터 리스트에 사진 컨텐츠를 추가 
void Application::AddPhoto() {
	Content* newCon = new Photo();
	newCon->Read();
	m_List.Add(newCon);
}

// 마스터 리스트에 동영상 컨텐츠를 추가 
void Application::AddVideo() {
	Content* newCon = new Video();
	newCon->Read();
	m_List.Add(newCon);
}