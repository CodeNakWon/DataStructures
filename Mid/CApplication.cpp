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
			ReplaceContents();
			break;
		case 4:		// 이름을 입력받아서 리스트에서 해당 콘텐츠를 찾아 화면 출력			
			RetrieveContents();
			break;
		case 5:		// 리스트에 저장된 모든 콘텐츠를 화면에 출력
			DisplayAllContents();
			break;
		case 6: 		// 이름을 입력 해당 이름을 포함하고 있는 모든 컨텐츠를 출력
			SearchByName();
			break;
		case 7:		// 키워드로 검색하여 해당 키워드를 모두 가지고 있는 모든 컨텐츠를 출력 
			SearchByKeyWords();
			break;
		case 8:   // 전체 리스트를 비움
			MakeEmpty();
			break;
		case 9:    //그룹(이벤트, 장소, 인물) 메뉴
			GApp.Run();
			break;
		case 10:    // 자주보는 컨텐츠 메뉴
			FavoriteMenu();
			break;
		case 11:    // 파일읽기
			ReadDataFromFile();
			break;
		case 12: 		// 파일쓰기
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
	cout << "\t 6 : Search Item by name " << endl;
	cout << "\t 7 : Search Item by keywords" << endl;
	cout << "\t 8 : Make empty" << endl;
	cout << "\t 9 : Group menu" << endl;
	cout << "\t 10 : Favorite menu" << endl;
	cout << "\t 11 : ReadDataFromFile " << endl;
	cout << "\t 12 : WriteDataToFile " << endl;
	cout << "\t 0 : Quit" << endl;
	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;
	return command;
}


// 마스터 리스트를 이름순으로 정렬하기 위한 inline 함수
inline bool SortByName(const Content &a,const Content &b) {
	return a.GetName() < b.GetName();
}

// 마스터 리스트를 최신 순으로 정렬하기 위한 inline 함수
inline bool SortByDateNew(const Content &a,const Content &b) {
	return a.GetDate() > b.GetDate();
}

// 마스터 리스트를 오래된 순으로 정렬하기 위한 inline 함수
inline bool SortByDateOld(const Content& a, const Content& b) {
	return a.GetDate() < b.GetDate();
}

// 마스터 리스트를 이벤트 순으로 정렬하기 위한 inline 함수
inline bool SortByEvent(const Content& a, const Content& b) {
	return a.GetEventName() < b.GetEventName();
}

// 마스터 리스트를 장소 순으로 정렬하기 위한 inline 함수
inline bool SortByPerson(const Content& a, const Content& b) {
	return a.GetPerson() < b.GetPerson();
}

// 마스터 리스트를 인물 순으로 정렬하기 위한 inline 함수
inline bool SortByLocation(const Content& a, const Content& b) {
	return a.GetLocation() < b.GetLocation();
}

// 마스터 리스트를 조회수 순으로 정렬하기 위한 inline 함수
inline bool SortByViews(const Content &a,const Content &b) {
	return a.GetViews() > b.GetViews();
}

// 현재 정렬기준에 따라 마스터 리스트를 정렬
void Application::SortMList() {
	switch (order)
	{
	case 1:
		m_List.Sort(SortByName);
		break;
	case 2:
		m_List.Sort(SortByDateNew);
		break;
	case 3:
		m_List.Sort(SortByDateOld);
		break;
	case 4:
		m_List.Sort(SortByEvent);
		break;
	case 5:
		m_List.Sort(SortByPerson);
		break;
	case 6:
		m_List.Sort(SortByLocation);
		break;
	default:
		m_List.Sort(SortByDateNew);
	}
}


// 새로운 컨텐츠를 추가할때 그룹, 자주보는 리스트, 마스터 리스트에 추가
int Application::Add(Content& mc) { 
	int added = m_List.Add(mc);
	if (added == 1) {
		GApp.AddContent(mc);
		return 1;
	}
	SortMList();
	return added;
}


// 새로운 컨텐츠를 추가할때 그룹, 자주보는 리스트, 마스터 리스트에서 삭제
int Application::Delete(Content& mc) {
	if (m_List.Delete(mc) == 1) {
		GApp.DeleteContent(mc);
		string iname = mc.GetName();
		m_FPList.Delete(iname);
		m_FVList.Delete(iname);
		return 1;
	}
	return 0;
}


// 새로운 레코드를 리스트에 추가
int Application::AddContents() {
	curr_time = time(NULL);
	localtime_s(&curr_tm, &curr_time);
	string str;
	str = to_string(curr_tm.tm_year + 1900) + "년" + to_string(curr_tm.tm_mon + 1) + "월" + to_string(curr_tm.tm_mday) + "일"
		+ to_string(curr_tm.tm_hour) + "시" + to_string(curr_tm.tm_min) + "분" + to_string(curr_tm.tm_sec) + "초";

	Content item;
	item.SetRecordFromKB(str);
	
	if (Add(item) == 1) {
		cout << "\t성공적으로 컨텐츠를 추가했습니다." << endl;
		return 1;
	}
	else if (Add(item) == -1) {
		cout << "\t동일한 이름을 가진 콘텐츠가 이미 존재합니다" << endl;
		return 0;
	}
	else {
		cout << "\t더 이상 콘텐츠를 추가할 수 없습니다." << endl;
		return 0;
	}
}


// 리스트의 모든 데이터를 화면에 출력
void Application::DisplayAllContents() {

	Content item;
	int input;

	while (1) {
		m_List.ResetList();
		cout << "\t=====모든 컨텐츠=====" << endl;
		cout << "\t총 " << m_List.GetLength() << "개의 컨텐츠" << endl << endl;
		while (m_List.GetNextItem(item) != -1) {
			item.DisplayRecordOnScreen();
			m_List.Replace(item);
		}

		cout << "\t정렬 순서 (1:이름), (2:신규 순), (3:오래된 순), (4:이벤트), (5:인물), (6:장소), (0:뒤로가기)"<<endl;
		cout << "\t>>>";
		cin >> input;
		if (!input) {
			return;
		}
		else {
			order = input;
		}
		SortMList();
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
	Content item;
	char fileName[32];
	cout << "\tFileName : ";
	cin >> fileName;
	if (!OpenInFile(fileName)) {  // 파일이 존재하지 않을 시 0을 반환
		cout << "\t해당 파일이 존재하지 않습니다." << endl;
		system("pause");
		return 0;
	};
	GApp.ReadFile(m_InFile);
	while (item.ReadDataFromFile(m_InFile)) {
		Add(item);
	}
	m_InFile.close();
	SortMList();
	cout << "\tsucceed!" << endl;
	system("pause");
	return 1;
}


// 리스트 안의 정보를 파일로 저장
int Application::WriteDataToFile() {
	char fileName[32];
	Content item;
	cout << "\tFileName : ";
	cin >> fileName;
	if (!OpenOutFile(fileName)) {
		cout << "\t파일쓰기에 실패하였습니다." << endl;
		system("pause");
		return 0;
	}
	GApp.WriteFile(m_OutFile);
	m_List.ResetList();
	for (int i = 0; i < m_List.GetLength(); i++) {
		m_List.GetNextItem(item);
		item.WriteDataToFile(m_OutFile);
	}
	m_OutFile.close();
	cout << "\tsucceed!" << endl;
	system("pause");
	return 1;
}


// 콘텐츠 이름으로 리스트 안을 검색하여 존재시 해당 레코드를 삭제
int Application::DeleteContents() {
	Content item; // 검색용 임시 변수
	item.SetNameFromKB();
	if (Delete(item)) {
		cout << "\t콘텐츠를 삭제하였습니다." << endl;
		system("pause");
		return 1;
	}
	else {
		cout << "\t입력한 이름과 일치하는 콘텐츠를 찾을 수 없습니다." << endl;
		system("pause");
		return 0;
	}
}



// 새로운 컨텐츠를 만들어 해당 컨텐츠와 같은 이름을 가진 컨텐츠가 리스트 안에 존재시 교체
int Application::ReplaceContents() {

	Content item;
	cout << "\tReplace contents" << endl;

	item.SetNameFromKB();
	if (m_List.Retrieve(item)) {
		cout << endl;
		GApp.DeleteContent(item);
		item.ModifyRecord();
		m_List.Replace(item);
		GApp.AddContent(item);
		cout << "\t입력한 정보로 콘텐츠의 정보를 갱신하였습니다." << endl;
		system("pause");
		return 1;
	}
	else { // 같은 이름의 컨텐츠가 없을 시 0을 리턴
		cout << "\t입력한 이름과 일치하는 콘텐츠를 찾을 수 없습니다." << endl;
		system("pause");
		return 0;
	}
}


// 콘텐츠를 이름으로 리스트 안을 검색하고 존재시 출력하고 1을 반환
int Application::RetrieveContents() {
	string cName;
	Content item;
	cout << "\tContent name : ";
	cin >> cName;
	item.SetName(cName);
	if (m_List.Retrieve(item)) {
		cout << endl;
		item.DisplayRecordOnScreen();
		m_List.Replace(item);
		return 1;
	}
	else {
		cout << "\t해당콘텐츠가 존재하지 않습니다." << endl;
		system("pause");
		return 0;
	}
}


// 리스트를 비우기
int Application::MakeEmpty() {
	m_List.MakeEmpty();
	m_FPList.MakeEmpty();
	m_FVList.MakeEmpty();
	GApp.MakeEmpty();
	cout << "\t모든 콘텐츠를 삭제하였습니다." << endl;
	system("pause");
	return 1;
}


// 이름을 입력받아 해당 이름을 포함하는 모든 콘텐츠를 표시
int Application::SearchByName() {
	int count = 0;
	string keyWord;
	Content item;
	cout << "\t검색할 이름 :";
	cin >> keyWord;
	cout << endl;
	m_List.ResetList();
	while (m_List.GetNextItem(item) != -1) {
		if (item.GetName().find(keyWord) != string::npos) {
			item.DisplayRecordOnScreen();
			m_List.Replace(item);
			count++;
		}
	}
	if (count) {
		cout << "\t총 " << count << "개의 항목이 발견됨" << endl;
		system("pause");
		return 1;
	}
	else {
		cout << "\t발견 항목 없음" << endl;
		system("pause");
		return 0;
	}
}


// 이름을 입력받아 해당 이름을 포함하는 모든 콘텐츠를 표시
void Application::SearchByKeyWords() {
	string keywords;
	cout << "\t키워드 검색" << endl;
	cout << "\t','로 구분하여 키워드를 입력해주세요 : "; // ex) party,Seoul,Won  // ex) party // ex) Won,Seoul  --> 띄어쓰기가 있으면 안됨
	cin >> keywords;
	unsigned int st = 0;
	int end;
	SortedList<string> keys;
	while (1) { // ,를 기준으로 parsing
		if (st >= keywords.length()) {
			break;
		}
		end = keywords.find(",", st);
		if (end == string::npos) {
			keys.Add(keywords.substr(st));
			break;
		}
		else if (end != st) {
			keys.Add(keywords.substr(st, end - st));
		}
		st = end + 1;
	}
	Content item;
	string str;
	int count = 0;
	cout << endl;
	m_List.ResetList();
	while (m_List.GetNextItem(item) != -1) {
		if (item.KeyWordSearch(keys) == 1) {
			item.DisplayRecordOnScreen();
			m_List.Replace(item);
			count++;
		}
	}
	if (count) {
		cout << endl << "총 " << count << "개의 항목 발견" << endl;
	}
	else {
		cout << endl << "발견된 항목 없음" << endl;
	}
	system("pause");
}


// 자주보는 컨텐츠 메뉴
void Application::FavoriteMenu() {
	int command;
	UpdateView();
	while (1) {
		cout << endl << endl; 
		cout << "\t--- 자주보는 사진 --- " << endl;
		m_FPList.ResetList(); 
		string name;
		while (m_FPList.GetNextItem(name)!=-1) { // 자주보는 사진에 속해있는 컨테츠를 간력히 출력
			cout <<"\t"<< name;
		}
		cout << endl << endl;

		cout << "\t--- 자주보는 동영상 --- " << endl;
		m_FVList.ResetList();
		while (m_FVList.GetNextItem(name) != -1) { // 자주보는 동영상에 속해있는 컨테츠를 간력히 출력
			cout << "\t" << name;
		}
		cout << endl << endl;
		cout << endl;
		cout << "\t---ID -- Command ----- " << endl;
		cout << "\t 1 : 자주보는 사진 상세 " << endl;
		cout << "\t 2 : 자주보는 동영상 상세 " << endl;;
		cout << "\t 3 : 컨텐츠 자세히 보기 " << endl;;
		cout << "\t 0 : Quit" << endl;
		cout << endl << "\t Choose a Command--> ";
		cin >> command;
		cout << endl;
		switch (command)
		{
		case 1:		//이벤트 설명 수정
			FViewedPhoto();
			break;
		case 2:		// 이벤트 이름을 입력받아서 event리스트에서 찾고, 찾은 event에 소속된 콘텐츠의 자세한 정보를 화면에 출력	                 
			FViewedVideo();
			break;
		case 3:		// 이벤트 리스트의 정보를 출력
			FViewSearch();
			break;
		case 0:
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}


// 자주보는 동영상을 자세히 출력
void Application::FViewedVideo() {
	cout << "\t===자주보는 동영상===" << endl;
	m_FVList.ResetList();
	string name;
	Content con;
	while (m_FVList.GetNextItem(name) != -1) {
		con.SetName(name);
		m_List.Retrieve(con);
		con.DisplayRecordOnScreen();
		m_List.Replace(con);
	}
	system("pause");
}

// 자주보는 사진을 자세히 출력
void Application::FViewedPhoto() {
	cout << "\t===자주보는 사진===" << endl;
	m_FPList.ResetList();
	string name;
	Content con;
	while (m_FPList.GetNextItem(name) != -1) {
		con.SetName(name);
		m_List.Retrieve(con);
		con.DisplayRecordOnScreen();
		m_List.Replace(con);
	}
	system("pause");
}

// 자주보는 리스트에서 검색
void Application::FViewSearch() {
	string name;
	Content con;
	cout << "\t자세히 볼 컨텐츠 이름을 입력해주세요 : ";
	cin >> name;
	cout << endl << endl;
	if (m_FPList.Retrieve(name) || m_FVList.Retrieve(name)) {
		con.SetName(name);
		if (m_List.Retrieve(con)) {
			con.DisplayRecordOnScreen();
			m_List.Replace(con);
		}
	}
	else  {
		cout << "해당 컨텐츠는 존재하지 않습니다." << endl;
	}
	system("pause");
}


// 자주보는 리스트를 조회수를 기준으로 업데이트
void Application::UpdateView() {
	m_List.Sort(SortByViews);
	m_List.ResetList();
	Content con;
	m_FVList.MakeEmpty();
	m_FPList.MakeEmpty();
	for (int i = 0; i < 1 + m_List.GetLength() / 5; i++) {
		m_List.GetNextItem(con);
		if (con.GetType() == VIDEO && con.GetViews() >= fview) {
			m_FVList.Add(con.GetName());
		}
		else if (con.GetType() == PHOTO && con.GetViews() >= fview) {
			m_FPList.Add(con.GetName());
		}
	}
	SortMList();
}

