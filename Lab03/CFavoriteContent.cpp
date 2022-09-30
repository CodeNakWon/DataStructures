#include "pch.h"
#include "CFavoriteContent.h"


// FC 이름 설정
void FavoriteContent::SetName(string inName) {
	m_cName = inName;
}


// FC 종류 설정
void FavoriteContent::SetType(ContentType inType) {
	m_cType = inType;
}

// FC 레코드 설정
void FavoriteContent::SetRecord(string inName, ContentType inType) {
	m_cName = inName;
	m_cType = inType;
}

// FC 이름 반환
string FavoriteContent::GetName() const{
	return m_cName;
}


// FC 종류 반환
ContentType FavoriteContent::GetType() const {
	return m_cType;
}

int FavoriteContent::GetViews() const {
	return m_views;
}

// FC 이름 화면에 출력
void FavoriteContent::DisplayNameOnScreen() const{
	cout << "\tContent name : " << m_cName << endl;
}


// FC 종류 화면에 출력
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


// 조회수 증가
void FavoriteContent::View() {
	m_views++;
}

// FC 정보 화면에 출력
void FavoriteContent::DisplayRecordOnScreen() const{
	DisplayNameOnScreen();
	DisplayTypeOnScreen();
	cout << "\t조회수 : " << m_views << endl<<endl;
}