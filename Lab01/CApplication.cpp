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
		case 4:		// �̸��� �Է¹޾Ƽ� ����Ʈ���� �ش���� ã�� ȭ�� ���			
			RetrieveContents ();
			break;
		case 5:		// ����Ʈ�� ����� ��� �������� ȭ�鿡 ���
			DisplayAllContents();
			break;
		case 6: 		// ����Ʈ�� �Էµ� ��� ������ ����
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
	cout << "\t 6 : Make empty" << endl;
	cout << "\t 7 : ReadDataFromFile " << endl;
	cout << "\t 8 : WriteDataToFile " << endl;
	cout << "\t 0 : Quit" << endl;
	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;
	return command;
}



// ���ο� ���ڵ带 ����Ʈ�� �߰�
int Application::AddContents() {
	ItemType item;
	item.SetRecordFromKB();
	if (m_List.Add(item) == 1) {
		cout << "\t���ο� �������� �߰��Ͽ����ϴ�." << endl;
		return 1;
	}
	else if(m_List.Add(item) == 0) {
		cout << "\t������ �̸��� ���� �������� �̹� �����մϴ�" << endl;
		return 0;
	}
	else {
		cout << "\t�� �̻� �������� �߰��� �� �����ϴ�." << endl;
	}
}


// ����Ʈ�� ��� �����͸� ȭ�鿡 ���
void Application::DisplayAllContents() {
	ItemType item;
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
	ItemType item;
	char fileName[32];
	cout << "\tFileName : ";
	cin >> fileName;
	if (!OpenInFile(fileName)) {  // ������ �������� ���� �� 0�� ��ȯ
		cout << "\t�ش� ������ �������� �ʽ��ϴ�." << endl;
		return 0;
	};
	while (item.ReadDataFromFile(m_InFile)) {
		m_List.Add(item);
	}
	m_InFile.close();
	cout << "\tsucceed!" << endl;
	return 1;
}


// ����Ʈ ���� ������ ���Ϸ� ����
int Application::WriteDataToFile() {
	char fileName[32];
	ItemType item;
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
	ItemType item; // �˻��� �ӽ� ����
	item.SetNameFromKB();
	if (m_List.Delete(item)) {
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
	ItemType item;
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