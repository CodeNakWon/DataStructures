#include "pch.h"
#include "CApplication.h"



void Application::Run() {
	while (1) {
		
		m_Command = GetCommand();
		switch (m_Command)
		{
		case 1:		// ������ ������ �Է� �޾� ����Ʈ�� �߰�					
			AddContents();
			break;
		case 2:		// �������� �̸��� �Է� �޾� ����Ʈ���� ����				
			DeleteContents();
			break;
		case 3:		// �������� ������ ���� �Էµ� ������ ����			                 
			ReplaceContents();
			break;
		case 4:		// �̸��� �Է¹޾Ƽ� ����Ʈ���� �ش� �������� ã�� ȭ�� ���			
			RetrieveContents();
			break;
		case 5:		// ����Ʈ�� ����� ��� �������� ȭ�鿡 ���
			DisplayAllContents();
			break;
		case 6: 		// �̸��� �Է� �ش� �̸��� �����ϰ� �ִ� ��� �������� ���
			SearchByName();
			break;
		case 7:		// Ű����� �˻��Ͽ� �ش� Ű���带 ��� ������ �ִ� ��� �������� ��� 
			SearchByKeyWords();
			break;
		case 8:   // ��ü ����Ʈ�� ���
			MakeEmpty();
			break;
		case 9:    //�׷�(�̺�Ʈ, ���, �ι�) �޴�
			GApp.Run();
			break;
		case 10:    // ���ֺ��� ������ �޴�
			FavoriteMenu();
			break;
		case 11:    // �����б�
			ReadDataFromFile();
			break;
		case 12: 		// ���Ͼ���
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


// ȭ�鿡 ��ɾ ���
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


// ������ ����Ʈ�� �̸������� �����ϱ� ���� inline �Լ�
inline bool SortByName(const Content &a,const Content &b) {
	return a.GetName() < b.GetName();
}

// ������ ����Ʈ�� �ֽ� ������ �����ϱ� ���� inline �Լ�
inline bool SortByDateNew(const Content &a,const Content &b) {
	return a.GetDate() > b.GetDate();
}

// ������ ����Ʈ�� ������ ������ �����ϱ� ���� inline �Լ�
inline bool SortByDateOld(const Content& a, const Content& b) {
	return a.GetDate() < b.GetDate();
}

// ������ ����Ʈ�� �̺�Ʈ ������ �����ϱ� ���� inline �Լ�
inline bool SortByEvent(const Content& a, const Content& b) {
	return a.GetEventName() < b.GetEventName();
}

// ������ ����Ʈ�� ��� ������ �����ϱ� ���� inline �Լ�
inline bool SortByPerson(const Content& a, const Content& b) {
	return a.GetPerson() < b.GetPerson();
}

// ������ ����Ʈ�� �ι� ������ �����ϱ� ���� inline �Լ�
inline bool SortByLocation(const Content& a, const Content& b) {
	return a.GetLocation() < b.GetLocation();
}

// ������ ����Ʈ�� ��ȸ�� ������ �����ϱ� ���� inline �Լ�
inline bool SortByViews(const Content &a,const Content &b) {
	return a.GetViews() > b.GetViews();
}

// ���� ���ı��ؿ� ���� ������ ����Ʈ�� ����
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


// ���ο� �������� �߰��Ҷ� �׷�, ���ֺ��� ����Ʈ, ������ ����Ʈ�� �߰�
int Application::Add(Content& mc) { 
	int added = m_List.Add(mc);
	if (added == 1) {
		GApp.AddContent(mc);
		return 1;
	}
	SortMList();
	return added;
}


// ���ο� �������� �߰��Ҷ� �׷�, ���ֺ��� ����Ʈ, ������ ����Ʈ���� ����
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


// ���ο� ���ڵ带 ����Ʈ�� �߰�
int Application::AddContents() {
	curr_time = time(NULL);
	localtime_s(&curr_tm, &curr_time);
	string str;
	str = to_string(curr_tm.tm_year + 1900) + "��" + to_string(curr_tm.tm_mon + 1) + "��" + to_string(curr_tm.tm_mday) + "��"
		+ to_string(curr_tm.tm_hour) + "��" + to_string(curr_tm.tm_min) + "��" + to_string(curr_tm.tm_sec) + "��";

	Content item;
	item.SetRecordFromKB(str);
	
	if (Add(item) == 1) {
		cout << "\t���������� �������� �߰��߽��ϴ�." << endl;
		return 1;
	}
	else if (Add(item) == -1) {
		cout << "\t������ �̸��� ���� �������� �̹� �����մϴ�" << endl;
		return 0;
	}
	else {
		cout << "\t�� �̻� �������� �߰��� �� �����ϴ�." << endl;
		return 0;
	}
}


// ����Ʈ�� ��� �����͸� ȭ�鿡 ���
void Application::DisplayAllContents() {

	Content item;
	int input;

	while (1) {
		m_List.ResetList();
		cout << "\t=====��� ������=====" << endl;
		cout << "\t�� " << m_List.GetLength() << "���� ������" << endl << endl;
		while (m_List.GetNextItem(item) != -1) {
			item.DisplayRecordOnScreen();
			m_List.Replace(item);
		}

		cout << "\t���� ���� (1:�̸�), (2:�ű� ��), (3:������ ��), (4:�̺�Ʈ), (5:�ι�), (6:���), (0:�ڷΰ���)"<<endl;
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


// ������ ���µ� ������ 1, ���н� 0�� ��ȯ
int Application::OpenInFile(char* fileName) {
	m_InFile.open(fileName);
	if (!m_InFile) {
		return 0;
	}
	return 1;
}


// ������ ���µ� ������ 1, ���н� 0�� ��ȯ
int Application::OpenOutFile(char* fileName) {
	m_OutFile.open(fileName);
	if (!m_OutFile) {
		return 0;
	}
	return 1;
}


// ������ �о��� ����Ʈ�� ����
int Application::ReadDataFromFile() {
	Content item;
	char fileName[32];
	cout << "\tFileName : ";
	cin >> fileName;
	if (!OpenInFile(fileName)) {  // ������ �������� ���� �� 0�� ��ȯ
		cout << "\t�ش� ������ �������� �ʽ��ϴ�." << endl;
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


// ����Ʈ ���� ������ ���Ϸ� ����
int Application::WriteDataToFile() {
	char fileName[32];
	Content item;
	cout << "\tFileName : ";
	cin >> fileName;
	if (!OpenOutFile(fileName)) {
		cout << "\t���Ͼ��⿡ �����Ͽ����ϴ�." << endl;
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


// ������ �̸����� ����Ʈ ���� �˻��Ͽ� ����� �ش� ���ڵ带 ����
int Application::DeleteContents() {
	Content item; // �˻��� �ӽ� ����
	item.SetNameFromKB();
	if (Delete(item)) {
		cout << "\t�������� �����Ͽ����ϴ�." << endl;
		system("pause");
		return 1;
	}
	else {
		cout << "\t�Է��� �̸��� ��ġ�ϴ� �������� ã�� �� �����ϴ�." << endl;
		system("pause");
		return 0;
	}
}



// ���ο� �������� ����� �ش� �������� ���� �̸��� ���� �������� ����Ʈ �ȿ� ����� ��ü
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
		cout << "\t�Է��� ������ �������� ������ �����Ͽ����ϴ�." << endl;
		system("pause");
		return 1;
	}
	else { // ���� �̸��� �������� ���� �� 0�� ����
		cout << "\t�Է��� �̸��� ��ġ�ϴ� �������� ã�� �� �����ϴ�." << endl;
		system("pause");
		return 0;
	}
}


// �������� �̸����� ����Ʈ ���� �˻��ϰ� ����� ����ϰ� 1�� ��ȯ
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
		cout << "\t�ش��������� �������� �ʽ��ϴ�." << endl;
		system("pause");
		return 0;
	}
}


// ����Ʈ�� ����
int Application::MakeEmpty() {
	m_List.MakeEmpty();
	m_FPList.MakeEmpty();
	m_FVList.MakeEmpty();
	GApp.MakeEmpty();
	cout << "\t��� �������� �����Ͽ����ϴ�." << endl;
	system("pause");
	return 1;
}


// �̸��� �Է¹޾� �ش� �̸��� �����ϴ� ��� �������� ǥ��
int Application::SearchByName() {
	int count = 0;
	string keyWord;
	Content item;
	cout << "\t�˻��� �̸� :";
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
		cout << "\t�� " << count << "���� �׸��� �߰ߵ�" << endl;
		system("pause");
		return 1;
	}
	else {
		cout << "\t�߰� �׸� ����" << endl;
		system("pause");
		return 0;
	}
}


// �̸��� �Է¹޾� �ش� �̸��� �����ϴ� ��� �������� ǥ��
void Application::SearchByKeyWords() {
	string keywords;
	cout << "\tŰ���� �˻�" << endl;
	cout << "\t','�� �����Ͽ� Ű���带 �Է����ּ��� : "; // ex) party,Seoul,Won  // ex) party // ex) Won,Seoul  --> ���Ⱑ ������ �ȵ�
	cin >> keywords;
	unsigned int st = 0;
	int end;
	SortedList<string> keys;
	while (1) { // ,�� �������� parsing
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
		cout << endl << "�� " << count << "���� �׸� �߰�" << endl;
	}
	else {
		cout << endl << "�߰ߵ� �׸� ����" << endl;
	}
	system("pause");
}


// ���ֺ��� ������ �޴�
void Application::FavoriteMenu() {
	int command;
	UpdateView();
	while (1) {
		cout << endl << endl; 
		cout << "\t--- ���ֺ��� ���� --- " << endl;
		m_FPList.ResetList(); 
		string name;
		while (m_FPList.GetNextItem(name)!=-1) { // ���ֺ��� ������ �����ִ� �������� ������ ���
			cout <<"\t"<< name;
		}
		cout << endl << endl;

		cout << "\t--- ���ֺ��� ������ --- " << endl;
		m_FVList.ResetList();
		while (m_FVList.GetNextItem(name) != -1) { // ���ֺ��� ������ �����ִ� �������� ������ ���
			cout << "\t" << name;
		}
		cout << endl << endl;
		cout << endl;
		cout << "\t---ID -- Command ----- " << endl;
		cout << "\t 1 : ���ֺ��� ���� �� " << endl;
		cout << "\t 2 : ���ֺ��� ������ �� " << endl;;
		cout << "\t 3 : ������ �ڼ��� ���� " << endl;;
		cout << "\t 0 : Quit" << endl;
		cout << endl << "\t Choose a Command--> ";
		cin >> command;
		cout << endl;
		switch (command)
		{
		case 1:		//�̺�Ʈ ���� ����
			FViewedPhoto();
			break;
		case 2:		// �̺�Ʈ �̸��� �Է¹޾Ƽ� event����Ʈ���� ã��, ã�� event�� �Ҽӵ� �������� �ڼ��� ������ ȭ�鿡 ���	                 
			FViewedVideo();
			break;
		case 3:		// �̺�Ʈ ����Ʈ�� ������ ���
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


// ���ֺ��� �������� �ڼ��� ���
void Application::FViewedVideo() {
	cout << "\t===���ֺ��� ������===" << endl;
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

// ���ֺ��� ������ �ڼ��� ���
void Application::FViewedPhoto() {
	cout << "\t===���ֺ��� ����===" << endl;
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

// ���ֺ��� ����Ʈ���� �˻�
void Application::FViewSearch() {
	string name;
	Content con;
	cout << "\t�ڼ��� �� ������ �̸��� �Է����ּ��� : ";
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
		cout << "�ش� �������� �������� �ʽ��ϴ�." << endl;
	}
	system("pause");
}


// ���ֺ��� ����Ʈ�� ��ȸ���� �������� ������Ʈ
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

