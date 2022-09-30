#include "pch.h"
#include "CGroup.h"


// �׷���� ����
void Group::SetTitle(string name) {
	m_cName = name;
}


// �׷� ������ ����
void Group::SetDescription(string des) {
	m_cDes = des;
}


// �׷� �̸��� ��ȯ
string Group::GetTitle() const {
	return m_cName;
}


// �׷� ������ ��ȯ
string Group::GetDescription() const {
	return m_cDes;
}


//Ű����� �׷���� ����
void Group::SetTitlefromKB() {
	string str;
	cout << "\tGroupName : " << endl << "\t>> ";
	cin >> str;
	m_cName = str;
}


// Ű����� �׷� ������ ����
void Group::SetDescriptionfromKB() {
	string str;
	cout << "\tGroupDescription : " << endl << "\t>> ";
	cin.ignore();
	getline(cin, str);
	m_cDes = str;
}


// �׷���� ȭ�鿡 ���
void Group::DisplayTitle() {
	cout << "\t�׷�� : " << m_cName << endl;
}


// �׷� ������ ȭ�鿡 ���
void Group::DisplayDescriptionOnScreen() {
	cout << "\t�׷� ���� : " << m_cDes << endl;
}


// �׷� ������ ȭ�鿡 ���
void Group::DisplayRecordOnScreen() {
	DisplayTitle();
	DisplayDescriptionOnScreen();
	DisplayIncludedContents();
	cout << endl;
}


// �׷쿡 ���Ե� ���������� ���
void Group::DisplayIncludedContents() {
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


// MC�̸�(MC�� Pirmary key)�� �׷� ����Ʈ�� �߰�
int Group::AddMC(Content& mc) {
	string name = mc.GetName();
	if (m_mcList.Add(name) == 1) {
		m_cLen++;
		return 1;
	}
	else if (m_mcList.Add(name) == -1) {
		return -1;
	}
	else {
		return 0;
	}
}


// MC�̸�(MC�� Pirmary key)�� �׷� ����Ʈ���� ����
int Group::Delete(Content& mc) {
	string name = mc.GetName();
	if (m_mcList.Delete(name)) {
		m_cLen--;
		return 1;
	}
	return 0;
}


// �׷� ����Ʈ�� ������� Ȯ��
bool Group::isEmpty() {
	if (m_cLen == 0) {
		return true;
	}
	return false;
}


// �׷츮��Ʈ���� �˻�
int Group::Retrieve(Content& mc) {
	string str = mc.GetName();
	return m_mcList.Retrieve(str);
}


// �׷츮��Ʈ�� ���� �������� �ڼ��� ���� ���
void Group::DisplayDetailAll(List<Content>& lst) {
	m_mcList.ResetList();
	string str;
	Content con;
	DisplayTitle();
	DisplayDescriptionOnScreen();
	cout << endl;
	while (m_mcList.GetNextItem(str) != -1) {
		con.SetName(str);
		lst.Retrieve(con);
		con.DisplayRecordOnScreen();
	}
	cout << endl;
}


// �������� �ڼ��� ���
int Group::DisplayDetail(string str, List<Content>& lst) {
	Content con;
	if (m_mcList.Retrieve(str) == 1) {
		con.SetName(str);
		if (lst.Retrieve(con)) {
			con.DisplayRecordOnScreen();
			return 1;
		}
	}
	return 0;
	cout << endl;
}
