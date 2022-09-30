#include "pch.h"
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
		case 4:		// 이름을 입력받아서 리스트에서 해당 콘텐츠를 찾아 화면 출력			
			RetrieveContents ();
			break;
		case 5:		// 리스트에 저장된 모든 콘텐츠를 화면에 출력
			DisplayAllContents();
			break;
		case 6: 		// 이름을 입력받아서 리스트에서 해당콘텐츠를 이진탐색으로 찾아 화면 출력
			RetrieveContents_Binary();
			break;
		case 7:		// 콘텐츠 이름을 입력받아 해당 콘텐츠명을 포함하고 있는 모든 정보를 출력
			SearchByName();
			break;
		case 8:    //콘텐츠에 포함된 사람을 입력받아서 그 사람이 들어있는 모든 콘텐츠의 자세한 정보를 화면에 출력
			SearchByPerson();
			break;
		case 9: 		// 리스트에 입력된 모든 내용을 삭제
			MakeEmpty();
			break;
		case 10: 		// 좋아하는 목록 메뉴 실행
			m_appFC.Run(m_List);
			break;
		case 11: 		// 이벤트 메뉴 실행
			EventMenu();
			break;
		case 12:		// load list data from a file.
			ReadDataFromFile();
			break;
		case 13:		// save list data into a file.
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
	cout << "\t 6 : Retrieve_Binary " << endl;
	cout << "\t 7 : Search Item by name " << endl;
	cout << "\t 8 : Search Item by included person" << endl;
	cout << "\t 9 : Make empty" << endl;
	cout << "\t 10 : Favorite List" << endl;
	cout << "\t 11 : Event menu" << endl;
	cout << "\t 12 : ReadDataFromFile " << endl;
	cout << "\t 13 : WriteDataToFile " << endl;
	cout << "\t 0 : Quit" << endl;
	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;
	return command;
}



// 새로운 레코드를 리스트에 추가
int Application::AddContents() {
	MultimediaContent item;
	item.SetRecordFromKB();
	if (Add(item) == 1) {
		return 1;
	}
	else if(Add(item) == -1) {
		cout << "\t동일한 이름을 가진 콘텐츠가 이미 존재합니다" << endl;
		return 0;
	}
	else {
		cout << "\t더 이상 콘텐츠를 추가할 수 없습니다." << endl;
		return 0;
	}
}


// 새로운 컨텐츠를 추가
int Application::Add(MultimediaContent& mc) {
	int added = m_List.Add(mc);
	if (added == 1) {
		Event event;
		event.setEventName(mc.GetEventName());
		if (eventList.Retrieve(event)) {
			event.AddMC(mc);
			eventList.Replace(event);
		}
		else {
			event.AddMC(mc);
			eventList.Add(event);
		}
		return 1;
	}
	return added;
}


// 컨텐츠를 삭제
int Application::Delete(MultimediaContent& mc) {
	if (m_List.Delete(mc) == 1) {
		m_appFC.DeleteMContents(mc);
		Event event;
		event.setEventName(mc.GetEventName());
		eventList.Retrieve(event);
		event.Delete(mc);
		eventList.Replace(event);
		return 1;
	}
	return 0;
}

// 리스트의 모든 데이터를 화면에 출력
void Application::DisplayAllContents() {
	MultimediaContent item;
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
	MultimediaContent item;
	char fileName[32];
	cout << "\tFileName : ";
	cin >> fileName;
	if (!OpenInFile(fileName)) {  // 파일이 존재하지 않을 시 0을 반환
		cout << "\t해당 파일이 존재하지 않습니다." << endl;
		return 0;
	};
	while (item.ReadDataFromFile(m_InFile)) {
		Add(item);
		item.DisplayRecordOnScreen();
	}
	m_InFile.close();
	cout << "\tsucceed!" << endl;
	return 1;
}


// 리스트 안의 정보를 파일로 저장
int Application::WriteDataToFile() {
	char fileName[32];
	MultimediaContent item;
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
	MultimediaContent item; // 검색용 임시 변수
	item.SetNameFromKB();
	if (Delete(item)) {
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
	MultimediaContent item;
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
	MultimediaContent item;
	cout << "\tContent name : ";
	cin >> cName;
	item.SetName(cName);
	if (m_List.Retrieve(item)) {
		cout << endl;
		item.DisplayRecordOnScreen();
		return 1;
	}
	else {
		cout << "\t해당콘텐츠가 존재하지 않습니다." << endl;
		return 0;
	}
}

// 콘텐츠를 이름으로 리스트 안을 검색하고 존재시 출력하고 1을 반환
int Application::RetrieveContents_Binary() {
	string cName;
	MultimediaContent item;
	cout << "\tContent name : ";
	cin >> cName;
	item.SetName(cName);
	if (m_List.Retrieve_Binary(item)) {
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


// 이름을 입력받아 해당 이름을 포함하는 모든 콘텐츠를 표시
int Application::SearchByName() {
	int count = 0;
	string keyWord;
	MultimediaContent item;
	cout << "\t검색할 이름 :";
	cin >> keyWord;
	m_List.ResetList();
	while (m_List.GetNextItem(item) != -1){
		if (item.GetName().find(keyWord) != string::npos) {
			item.DisplayRecordOnScreen();
			count++;
		}
	}
	if (count) {
		cout << "\t총 " << count << "개의 항목이 발견됨" << endl;
		return 1;
	}
	else {
		cout << "\t발견 항목 없음"<< endl;
		return 0;
	}
}

// 사람을 입력받아 해당 사람이 토함된 모든 콘텐츠를 출력
int Application::SearchByPerson() {
	int count = 0;
	string pName;
	MultimediaContent item;
	cout << "\t검색할 포함된 사람 : ";
	cin >> pName;
	cout << endl;
	m_List.ResetList();
	while (m_List.GetNextItem(item) != -1) {
		if (item.GetPerson() == pName) {
			item.DisplayRecordOnScreen();
			count++;
		}
	}
	if (count) {
		cout << "\t총 " << count << "개의 항목이 발견됨" << endl;
		return 1;
	}
	else {
		cout << "\t발견 항목 없음" << endl;
		return 0;
	}
}


// 이벤트 메뉴
void Application::EventMenu() {
	int command;
	while (1) {
		cout << endl << endl;
		cout << "\t---ID -- Command ----- " << endl;
		cout << "\t 1 : 이벤트 설명 수정" << endl;
		cout << "\t 2 : 이벤트 상세" << endl;;
		cout << "\t 3 : 이벤트 리스트" << endl;;
		cout << "\t 0 : Quit" << endl;
		cout << endl << "\t Choose a Command--> ";
		cin >> command;
		cout << endl;
		switch (command)
		{
		case 1:		//이벤트 설명 수정
			ModifyEvent();
			break;
		case 2:		// 이벤트 이름을 입력받아서 event리스트에서 찾고, 찾은 event에 소속된 콘텐츠의 자세한 정보를 화면에 출력	                 
			FindNDisplayEvent();
			break;
		case 3:		// 이벤트 리스트의 정보를 출력
			DisplayAllEvents();
			break;
		case 0:
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}

// 이벤트 리스트 정보 출력
void Application::DisplayAllEvents() {
	Event event;
	MultimediaContent mc;
	eventList.ResetList();
	cout << "\t이벤트 목록" << endl;
	eventList.ResetList();
	for (int i = 0; i < eventList.GetLength(); i++) {
		eventList.GetNextItem(event);
		event.DisplayEventName();
		event.DisplayIncludedContents();
		cout << endl;
	}
}

// 이벤트 설명 수정
void Application::ModifyEvent() {
	Event event;
	eventList.ResetList();
	cout << "\t이벤트 목록" << endl;
	for (int i = 0; i < eventList.GetLength(); i++) {
		eventList.GetNextItem(event);
		cout <<"\t"<<event.getEventName() << endl;
	}
	cout << endl;
	cout << "\t수정할 이벤트 : ";
	string name;
	cin >> name;
	cout << endl;
	event.setEventName(name);
	if (eventList.Retrieve(event)) {
		event.DisplayRecordOnScreen();
		cout << endl;
		event.setEventDescriptionfromKB();
		eventList.Replace(event);
	}
}


// 이벤트 상세정보 출력
void Application::FindNDisplayEvent() {
	Event event;
	eventList.ResetList();
	cout << "\t이벤트 목록" << endl;
	for (int i = 0; i < eventList.GetLength(); i++) {
		eventList.GetNextItem(event);
		cout << "\t" << event.getEventName() << endl;
	}
	cout << endl;
	cout << "\t자세히 볼 이벤트 : ";
	string name;
	cin >> name;
	event.setEventName(name);
	if (eventList.Retrieve(event)) {
		event.DisplayEventName();
		event.DisplayDescriptionOnScreen();
		cout << endl;
		event.DisplayDetailAll(m_List);
	}
	else {
		cout << "\t해당이벤트는 존재하지 않습니다." << endl;
	}
}