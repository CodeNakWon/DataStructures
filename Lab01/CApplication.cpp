#include "CApplication.h"



void Application::Run() {
	while (1) {
		m_Command = GetCommand();

		switch (m_Command)
		{
		case 1:		// 콘텐츠 정보를 입력 받아 리스트에 추가					
			AddContents();
			break;
		case 2:		// 콘텐츠의 이름을 입력 받아 리스트에서 삭제				
			DeleteContents();
			break;
		case 3:		// 콘텐츠의 정보를 새로 입력된 정보로 갱신			                 
			ReplaceContents ();
			break;
		case 4:		// 이름을 입력받아서 리스트에서 해당곡을 찾아 화면 출력			
			RetrieveContents ();
			break;
		case 5:		// 리스트에 저장된 모든 콘텐츠를 화면에 출력
			DisplayAllContents();
			break;
		case 6: 		// 리스트에 입력된 모든 내용을 삭제
			MakeEmpty();
			break;
		case 7:		// load list data from a file.
			ReadDataFromFile();
			break;
		case 8:		// save list data into a file.
			WriteDataToFile();
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
	cout << "\t 1 : Add content" << endl;
	cout << "\t 2 : Delete contents" << endl;
	cout << "\t 3 : Replace contents" << endl;
	cout << "\t 4 : Retrieve content" << endl;
	cout << "\t 5 : Display all contents " << endl;
	cout << "\t 6 : Make empty" << endl;
	cout << "\t 7 : ReadDataFromFile " << endl;
	cout << "\t 8 : WriteDataToFile " << endl;
	cout << "\t 0 : Quit" << endl;
	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;
	return command;
}



// 새로운 레코드를 리스트에 추가
int Application::AddContents() {
	ItemType item;
	item.SetRecordFromKB();
	if (m_List.Add(item) == 1) {
		cout << "\t새로운 콘텐츠를 추가하였습니다." << endl;
		return 1;
	}
	else if(m_List.Add(item) == 0) {
		cout << "\t동일한 이름을 가진 콘텐츠가 이미 존재합니다" << endl;
		return 0;
	}
	else {
		cout << "\t더 이상 콘텐츠를 추가할 수 없습니다." << endl;
	}
}


// 리스트의 모든 데이터를 화면에 출력
void Application::DisplayAllContents() {
	ItemType item;
	m_List.ResetList();
	cout << "\t=====모든 컨텐츠=====" << endl;
	cout << "\t총 " <<m_List.GetLength()<<"개의 컨텐츠" <<endl<<endl;
	while (m_List.GetNextItem(item) != -1) {
		item.DisplayRecordOnScreen();
	}
}


// 파일을 여는데 성공시 1, 실패시 0을 반환
int Application::OpenInFile(char* fileName) {
	m_InFile.open(fileName);
	if (!m_InFile) {
		return 0;
	}
	return 1;
}


// 파일을 여는데 성공시 1, 실패시 0을 반환
int Application::OpenOutFile(char* fileName) {
	m_OutFile.open(fileName);
	if (!m_OutFile) {
		return 0;
	}
	return 1;
}


// 파일을 읽어들어 리스트에 저장
int Application::ReadDataFromFile() {
	ItemType item;
	char fileName[32];
	cout << "\tFileName : ";
	cin >> fileName;
	if (!OpenInFile(fileName)) {  // 파일이 존재하지 않을 시 0을 반환
		cout << "\t해당 파일이 존재하지 않습니다." << endl;
		return 0;
	};
	while (item.ReadDataFromFile(m_InFile)) {
		m_List.Add(item);
	}
	m_InFile.close();
	cout << "\tsucceed!" << endl;
	return 1;
}


// 리스트 안의 정보를 파일로 저장
int Application::WriteDataToFile() {
	char fileName[32];
	ItemType item;
	cout << "\tFileName : ";
	cin >> fileName;
	if (!OpenOutFile(fileName)) {
		cout << "\t파일쓰기에 실패하였습니다." << endl;
		return 0;
	}
	m_List.ResetList();
	for (int i = 0; i < m_List.GetLength(); i++) {
		m_List.GetNextItem(item);
		item.WriteDataToFile(m_OutFile);
	}
	m_OutFile.close();
	cout << "\tsucceed!" << endl;
	return 1;
}


// 콘텐츠 이름으로 리스트 안을 검색하여 존재시 해당 레코드를 삭제
int Application::DeleteContents() {
	ItemType item; // 검색용 임시 변수
	item.SetNameFromKB();
	if (m_List.Delete(item)) {
		cout << "\t콘텐츠를 삭제하였습니다." << endl;
		return 1;
	}
	else {
		cout << "\t입력한 이름과 일치하는 콘텐츠를 찾을 수 없습니다." << endl;
		return 0;
	}
}


// 새로운 컨텐츠를 만들어 해당 컨텐츠와 같은 이름을 가진 컨텐츠가 리스트 안에 존재시 교체
int Application::ReplaceContents() {
	ItemType item;
	cout << "\tReplace contents" << endl;
	item.SetRecordFromKB();
	if (m_List.Replace(item)) {
		cout << "\t입력한 정보로 콘텐츠의 정보를 갱신하였습니다." << endl;
		return 1;
	}
	else { // 같은 이름의 컨텐츠가 없을 시 0을 리턴
		cout << "\t입력한 이름과 일치하는 콘텐츠를 찾을 수 없습니다." << endl;
		return 0;
	}
}

// 콘텐츠를 이름으로 리스트 안을 검색하고 존재시 출력하고 1을 반환
int Application::RetrieveContents() {
	string cName;
	ItemType item;
	cout << "\tContent name : ";
	cin >> cName;
	item.SetName(cName);
	if (m_List.Get(item)) {
		cout << endl;
		item.DisplayRecordOnScreen();
		return 1;
	}
	else {
		cout << "\t해당콘텐츠가 존재하지 않습니다." << endl;
		return 0;
	}
}


// 리스트를 비우기
int Application::MakeEmpty() {
	m_List.MakeEmpty();
	cout << "\t모든 콘텐츠를 삭제하였습니다." << endl;
	return 1;
}