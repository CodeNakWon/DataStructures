#include "pch.h"
#include "CFavoriteContent.h"


// FC �̸� ����
void FavoriteContent::SetName(string inName) {
	m_cName = inName;
}


// FC ���� ����
void FavoriteContent::SetType(ContentType inType) {
	m_cType = inType;
}

// FC ���ڵ� ����
void FavoriteContent::SetRecord(string inName, ContentType inType) {
	m_cName = inName;
	m_cType = inType;
}

// FC �̸� ��ȯ
string FavoriteContent::GetName() const{
	return m_cName;
}


// FC ���� ��ȯ
ContentType FavoriteContent::GetType() const {
	return m_cType;
}

int FavoriteContent::GetViews() const {
	return m_views;
}

// FC �̸� ȭ�鿡 ���
void FavoriteContent::DisplayNameOnScreen() const{
	cout << "\tContent name : " << m_cName << endl;
}


// FC ���� ȭ�鿡 ���
void FavoriteContent::DisplayTypeOnScreen() const{
	if (m_cType == VIDEO) {
		cout << "\tContent type: " << "Video" << endl;
	}
	else if (m_cType == PICTURE) {
		cout << "\tContent type : " << "Picture" << endl;
	}
	else {
		cout << "\tContent type : " << "Unknown" << endl;
	}
}


// ��ȸ�� ����
void FavoriteContent::View() {
	m_views++;
}

// FC ���� ȭ�鿡 ���
void FavoriteContent::DisplayRecordOnScreen() const{
	DisplayNameOnScreen();
	DisplayTypeOnScreen();
	cout << "\t��ȸ�� : " << m_views << endl<<endl;
}