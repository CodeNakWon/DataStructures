#include "pch.h"
#include "CEvent.h"

// �̺�Ʈ���� ����
void Event::setEventName(string name) {
	m_eName = name;
}

// �̺�Ʈ ������ ����
void Event::setEventDescription(string des) {
	m_eDes = des;
}


// �̺�Ʈ �̸��� ��ȯ
string Event::getEventName() const{
	return m_eName;
}

// �̺�Ʈ ������ ��ȯ
string Event::setEventDescription() const{
	return m_eDes;
}


//Ű����� �̺�Ʈ���� ����
void Event::setEventNamefromKB() {
	string str;
	cout << "\tEventName : " << endl << "\t>> ";
	cin >> str;
	m_eName = str;
}


// Ű����� �̺�Ʈ ������ ����
void Event::setEventDescriptionfromKB() {
	string str;
	cout << "\tEventDescription : " << endl << "\t>> ";
	cin >> str;
	m_eDes = str;
}


// �̺�Ʈ���� ȭ�鿡 ���
void Event::DisplayEventName() {
	cout << "\t�̺�Ʈ�� : " << m_eName << endl;
}

void Event::DisplayDescriptionOnScreen() {
	cout << "\t�̺�Ʈ���� : " << m_eDes << endl;
}

// �̺�Ʈ�� ���Ե� ���������� ���
void Event::DisplayIncludedContents() {
	int count = 0;
	string item;
	cout << "\t���Ե� ������ : " << endl;
	m_mcList.ResetList();
	while (m_mcList.GetNextItem(item) != -1) {
		cout << "\t\t\t - " << item << endl;
		count++;
	}
	if (!count) {
		cout << "\t\t����.";
	}
	cout << endl;
}


// �̺�Ʈ ������ ȭ�鿡 ���
void Event::DisplayRecordOnScreen() {
	DisplayEventName();
	DisplayDescriptionOnScreen();
	DisplayIncludedContents();
	cout << endl;
}

int Event::Retrieve(MultimediaContent &mc) {
	string str = mc.GetName();
	return m_mcList.Retrieve(str);
}


// MC�̸�(MC�� Pirmary key)�� �̺�Ʈ ����Ʈ�� �߰�
int Event::AddMC(MultimediaContent &mc) {
	string name = mc.GetName();
	if (m_mcList.Add(name) == 1) {
		m_eLen++;
		return 1;
	}
	else if (m_mcList.Add(name) == -1) {
		return -1;
	}
	else {
		return 0;
	}
}


// MC�̸�(MC�� Pirmary key)�� �̺�Ʈ ����Ʈ���� ����
int Event::Delete(MultimediaContent &mc) {
	string name = mc.GetName();
	if (m_mcList.Delete(name)) {
		m_eLen--;
		return 1;
	}
	return 0;
}


// �̺�Ʈ ����Ʈ�� ������� Ȯ��
bool Event::isEmpty() {
	if (m_eLen == 0) {
		return true;
	}
	return false;
}

void Event::DisplayDetailAll(SortedList<MultimediaContent>& lst) {
	m_mcList.ResetList();
	string str;
	MultimediaContent con;
	while (m_mcList.GetNextItem(str) != -1) {
		con.SetName(str);
		lst.Retrieve(con);
		con.DisplayRecordOnScreen();
	}
}