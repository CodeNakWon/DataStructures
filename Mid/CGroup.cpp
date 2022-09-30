#include "pch.h"
#include "CGroup.h"


// 그룹명을 설정
void Group::SetTitle(string name) {
	m_cName = name;
}


// 그룹 설명을 설정
void Group::SetDescription(string des) {
	m_cDes = des;
}


// 그룹 이름을 반환
string Group::GetTitle() const {
	return m_cName;
}


// 그룹 설명을 반환
string Group::GetDescription() const {
	return m_cDes;
}


//키보드로 그룹명을 설정
void Group::SetTitlefromKB() {
	string str;
	cout << "\tGroupName : " << endl << "\t>> ";
	cin >> str;
	m_cName = str;
}


// 키보드로 그룹 설명을 설정
void Group::SetDescriptionfromKB() {
	string str;
	cout << "\tGroupDescription : " << endl << "\t>> ";
	cin.ignore();
	getline(cin, str);
	m_cDes = str;
}


// 그룹명을 화면에 출력
void Group::DisplayTitle() {
	cout << "\t그룹명 : " << m_cName << endl;
}


// 그룹 설명을 화면에 출력
void Group::DisplayDescriptionOnScreen() {
	cout << "\t그룹 설명 : " << m_cDes << endl;
}


// 그룹 정보를 화면에 출력
void Group::DisplayRecordOnScreen() {
	DisplayTitle();
	DisplayDescriptionOnScreen();
	DisplayIncludedContents();
	cout << endl;
}


// 그룹에 포함된 콘텐츠명을 출력
void Group::DisplayIncludedContents() {
	int count = 0;
	string item;
	cout << "\t포함된 컨텐츠 : " << endl;
	m_mcList.ResetList();
	while (m_mcList.GetNextItem(item) != -1) {
		cout << "\t\t\t - " << item << endl;
		count++;
	}
	if (!count) {
		cout << "\t\t없음.";
	}
	cout << endl;
}


// MC이름(MC의 Pirmary key)을 그룹 리스트에 추가
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


// MC이름(MC의 Pirmary key)을 그룹 리스트에서 삭제
int Group::Delete(Content& mc) {
	string name = mc.GetName();
	if (m_mcList.Delete(name)) {
		m_cLen--;
		return 1;
	}
	return 0;
}


// 그룹 리스트가 비었는지 확인
bool Group::isEmpty() {
	if (m_cLen == 0) {
		return true;
	}
	return false;
}


// 그룹리스트에서 검색
int Group::Retrieve(Content& mc) {
	string str = mc.GetName();
	return m_mcList.Retrieve(str);
}


// 그룹리스트에 속한 컨텐츠를 자세히 전부 출력
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


// 컨텐츠를 자세히 출력
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
