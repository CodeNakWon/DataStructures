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


// �̺�Ʈ�� ���Ե� ���������� ���
void Event::DisplayIncludedContents() {
	string str;
	int count = 0;
	cout << "\t���Ե� ������ : " << endl;
	cout << "\t";
	m_MCKeys.ResetList();
	while (m_MCKeys.GetNextItem(str) != -1) {
		cout << "\t" << str;
		count++;
	}
	if (!count) {
		cout << "\t����.";
	}
	cout << endl;
}


// �̺�Ʈ ������ ȭ�鿡 ���
void Event::DisplayRecordOnScreen() {
	DisplayEventName();
	cout << "\t�̺�Ʈ ���� : " << m_eDes << endl;
	DisplayIncludedContents();
	cout << endl;
}


// MC�̸�(MC�� Pirmary key)�� �̺�Ʈ ����Ʈ�� �߰�
int Event::AddMC(MultimediaContent mc) {
	string name = mc.GetName();
	cout << "AddMC" << endl;
	if (m_MCKeys.Add(name) == 1) {
		m_eLen++;
		m_MCKeys.ResetList();
		while (m_MCKeys.GetNextItem(name)!=-1) {
			cout << name;
		}
		return 1;
	}
	else if (m_MCKeys.Add(name) == -1) {
		return -1;
	}
	else {
		cout << "else" << endl;
		return 0;
	}
}


// MC�̸�(MC�� Pirmary key)�� �̺�Ʈ ����Ʈ���� ����
int Event::Delete(MultimediaContent& mc) {
	string name = mc.GetName();
	if (m_MCKeys.Delete(name)) {
		m_eLen--;
		return 1;
	}
	return 0;
}


// MC�̸�(MC�� Pirmary key)���� �̺�Ʈ ����Ʈ���� �˻�
int Event::Retrieve(MultimediaContent& mc) {
	string name = mc.GetName();
	return m_MCKeys.Retrieve_Binary(name);
}


// �̺�Ʈ ����Ʈ�� ������� Ȯ��
bool Event::isEmpty() {
	if (m_eLen == 0) {
		return true;
	}
	return false;
}