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
			ReplaceContents ();
			break;
		case 4:		// �̸��� �Է¹޾Ƽ� ����Ʈ���� �ش� �������� ã�� ȭ�� ���			
			RetrieveContents ();
			break;
		case 5:		// ����Ʈ�� ����� ��� �������� ȭ�鿡 ���
			DisplayAllContents();
			break;
		case 6: 		// �̸��� �Է¹޾Ƽ� ����Ʈ���� �ش��������� ����Ž������ ã�� ȭ�� ���
			RetrieveContents_Binary();
			break;
		case 7:		// ������ �̸��� �Է¹޾� �ش� ���������� �����ϰ� �ִ� ��� ������ ���
			SearchByName();
			break;
		case 8:    //�������� ���Ե� ����� �Է¹޾Ƽ� �� ����� ����ִ� ��� �������� �ڼ��� ������ ȭ�鿡 ���
			SearchByPerson();
			break;
		case 9: 		// ����Ʈ�� �Էµ� ��� ������ ����
			MakeEmpty();
			break;
		case 10: 		// �����ϴ� ��� �޴� ����
			m_appFC.Run(m_List);
			break;
		case 11: 		// �̺�Ʈ �޴� ����
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



// ���ο� ���ڵ带 ����Ʈ�� �߰�
int Application::AddContents() {
	MultimediaContent item;
	item.SetRecordFromKB();
	if (Add(item) == 1) {
		return 1;
	}
	else if(Add(item) == -1) {
		cout << "\t������ �̸��� ���� �������� �̹� �����մϴ�" << endl;
		return 0;
	}
	else {
		cout << "\t�� �̻� �������� �߰��� �� �����ϴ�." << endl;
		return 0;
	}
}


// ���ο� �������� �߰�
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


// �������� ����
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

// ����Ʈ�� ��� �����͸� ȭ�鿡 ���
void Application::DisplayAllContents() {
	MultimediaContent item;
	m_List.ResetList();
	cout << "\t=====��� ������=====" << endl;
	cout << "\t�� " <<m_List.GetLength()<<"���� ������" <<endl<<endl;
	while (m_List.GetNextItem(item) != -1) {
		item.DisplayRecordOnScreen();
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
	MultimediaContent item;
	char fileName[32];
	cout << "\tFileName : ";
	cin >> fileName;
	if (!OpenInFile(fileName)) {  // ������ �������� ���� �� 0�� ��ȯ
		cout << "\t�ش� ������ �������� �ʽ��ϴ�." << endl;
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


// ����Ʈ ���� ������ ���Ϸ� ����
int Application::WriteDataToFile() {
	char fileName[32];
	MultimediaContent item;
	cout << "\tFileName : ";
	cin >> fileName;
	if (!OpenOutFile(fileName)) {
		cout << "\t���Ͼ��⿡ �����Ͽ����ϴ�." << endl;
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


// ������ �̸����� ����Ʈ ���� �˻��Ͽ� ����� �ش� ���ڵ带 ����
int Application::DeleteContents() {
	MultimediaContent item; // �˻��� �ӽ� ����
	item.SetNameFromKB();
	if (Delete(item)) {
		cout << "\t�������� �����Ͽ����ϴ�." << endl;
		return 1;
	}
	else {
		cout << "\t�Է��� �̸��� ��ġ�ϴ� �������� ã�� �� �����ϴ�." << endl;
		return 0;
	}
}



// ���ο� �������� ����� �ش� �������� ���� �̸��� ���� �������� ����Ʈ �ȿ� ����� ��ü
int Application::ReplaceContents() {
	MultimediaContent item;
	cout << "\tReplace contents" << endl;
	item.SetRecordFromKB();
	if (m_List.Replace(item)) {
		cout << "\t�Է��� ������ �������� ������ �����Ͽ����ϴ�." << endl;
		return 1;
	}
	else { // ���� �̸��� �������� ���� �� 0�� ����
		cout << "\t�Է��� �̸��� ��ġ�ϴ� �������� ã�� �� �����ϴ�." << endl;
		return 0;
	}
}

// �������� �̸����� ����Ʈ ���� �˻��ϰ� ����� ����ϰ� 1�� ��ȯ
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
		cout << "\t�ش��������� �������� �ʽ��ϴ�." << endl;
		return 0;
	}
}

// �������� �̸����� ����Ʈ ���� �˻��ϰ� ����� ����ϰ� 1�� ��ȯ
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
		cout << "\t�ش��������� �������� �ʽ��ϴ�." << endl;
		return 0;
	}
}

// ����Ʈ�� ����
int Application::MakeEmpty() {
	m_List.MakeEmpty();
	cout << "\t��� �������� �����Ͽ����ϴ�." << endl;
	return 1;
}


// �̸��� �Է¹޾� �ش� �̸��� �����ϴ� ��� �������� ǥ��
int Application::SearchByName() {
	int count = 0;
	string keyWord;
	MultimediaContent item;
	cout << "\t�˻��� �̸� :";
	cin >> keyWord;
	m_List.ResetList();
	while (m_List.GetNextItem(item) != -1){
		if (item.GetName().find(keyWord) != string::npos) {
			item.DisplayRecordOnScreen();
			count++;
		}
	}
	if (count) {
		cout << "\t�� " << count << "���� �׸��� �߰ߵ�" << endl;
		return 1;
	}
	else {
		cout << "\t�߰� �׸� ����"<< endl;
		return 0;
	}
}

// ����� �Է¹޾� �ش� ����� ���Ե� ��� �������� ���
int Application::SearchByPerson() {
	int count = 0;
	string pName;
	MultimediaContent item;
	cout << "\t�˻��� ���Ե� ��� : ";
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
		cout << "\t�� " << count << "���� �׸��� �߰ߵ�" << endl;
		return 1;
	}
	else {
		cout << "\t�߰� �׸� ����" << endl;
		return 0;
	}
}


// �̺�Ʈ �޴�
void Application::EventMenu() {
	int command;
	while (1) {
		cout << endl << endl;
		cout << "\t---ID -- Command ----- " << endl;
		cout << "\t 1 : �̺�Ʈ ���� ����" << endl;
		cout << "\t 2 : �̺�Ʈ ��" << endl;;
		cout << "\t 3 : �̺�Ʈ ����Ʈ" << endl;;
		cout << "\t 0 : Quit" << endl;
		cout << endl << "\t Choose a Command--> ";
		cin >> command;
		cout << endl;
		switch (command)
		{
		case 1:		//�̺�Ʈ ���� ����
			ModifyEvent();
			break;
		case 2:		// �̺�Ʈ �̸��� �Է¹޾Ƽ� event����Ʈ���� ã��, ã�� event�� �Ҽӵ� �������� �ڼ��� ������ ȭ�鿡 ���	                 
			FindNDisplayEvent();
			break;
		case 3:		// �̺�Ʈ ����Ʈ�� ������ ���
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

// �̺�Ʈ ����Ʈ ���� ���
void Application::DisplayAllEvents() {
	Event event;
	MultimediaContent mc;
	eventList.ResetList();
	cout << "\t�̺�Ʈ ���" << endl;
	eventList.ResetList();
	for (int i = 0; i < eventList.GetLength(); i++) {
		eventList.GetNextItem(event);
		event.DisplayEventName();
		event.DisplayIncludedContents();
		cout << endl;
	}
}

// �̺�Ʈ ���� ����
void Application::ModifyEvent() {
	Event event;
	eventList.ResetList();
	cout << "\t�̺�Ʈ ���" << endl;
	for (int i = 0; i < eventList.GetLength(); i++) {
		eventList.GetNextItem(event);
		cout <<"\t"<<event.getEventName() << endl;
	}
	cout << endl;
	cout << "\t������ �̺�Ʈ : ";
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


// �̺�Ʈ ������ ���
void Application::FindNDisplayEvent() {
	Event event;
	eventList.ResetList();
	cout << "\t�̺�Ʈ ���" << endl;
	for (int i = 0; i < eventList.GetLength(); i++) {
		eventList.GetNextItem(event);
		cout << "\t" << event.getEventName() << endl;
	}
	cout << endl;
	cout << "\t�ڼ��� �� �̺�Ʈ : ";
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
		cout << "\t�ش��̺�Ʈ�� �������� �ʽ��ϴ�." << endl;
	}
}