#include "pch.h"
#include "CMultimediaContent.h"

// 콘텐츠 이름 반환
string MultimediaContent::GetName() const {
	return m_cName;
}


// 콘텐츠 종류 반환
ContentType MultimediaContent::GetType() const {
	return m_cType;
}


// 콘텐츠 생성날짜와 시간 반환
string MultimediaContent::GetDate() const {
	return m_Date;
}


// 콘텐츠에 포함된 사람 반환
string MultimediaContent::GetPerson() const {
	return m_Person;
}

// 콘텐츠 구분 반환
int MultimediaContent::GetCategory() const {
	return m_Category;
}

//이벤트 명 반환
string MultimediaContent::GetEventName() const {
	return m_EventName;
}


// 콘텐츠 이름 저장
void MultimediaContent::SetName(string inName) {
	m_cName = inName;
}


// 콘텐츠 종류 저장
void MultimediaContent::SetType(ContentType inType) {
	m_cType = inType;
}


// 콘텐츠 생성날짜와 시간 저장
void MultimediaContent::SetDate(string inDate) {
	m_Date = inDate;
}


// 콘텐츠에 포함된 사람 저장
void MultimediaContent::SetPerson(string inPerson) {
	m_Person = inPerson;
}

// 콘텐츠 구분 저장
void MultimediaContent::SetCategory(int inCategory) {
	m_Category = inCategory;
}

// 이벤트명 저장
void MultimediaContent::SetEventName(string inEventName) {
	m_EventName = inEventName;
}


// 이벤트 정보 저장
void MultimediaContent::SetRecord(string inName, ContentType inType, string inDate, string inPerson, string inEventName) {
	m_cName = inName;
	m_cType = inType;
	m_Date = inDate;
	m_Person = inPerson;
	m_EventName = inEventName;
}


// 콘텐츠 이름 출력
void MultimediaContent::DisplayNameOnScreen() const {
	cout << "\tContent name : " << m_cName << endl;
}


// 콘텐츠 종류 출력
void MultimediaContent::DisplayTypeOnScreen() const {
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


// 콘텐츠 생성날짜와 시간 출력
void MultimediaContent::DisplayDateOnScreen() const {
	cout << "\tContent generated date : " << m_Date << endl;
}


// 콘텐츠에 포함된 사람 출력
void MultimediaContent::DisplayPersonOnScreen() const {
	cout << "\tContent included person : " << m_Person << endl;
}

// 콘텐츠 구분 출력
void MultimediaContent::DisplayCategoryOnScreen() const {
	switch (m_Category) {
	case 0:// 인물
		cout << "\tCategory : 인물" << endl;
		break;
	case 1://동물
		cout << "\tCategory : 동물" << endl;
		break;
	case 2://사물
		cout << "\tCategory : 사물" << endl;
		break;
	case 3://배경
		cout << "\tCategory : 배경" << endl;
		break;
	default:
		cout << "\tCategory : 알 수 없음" << endl;
		break;
	}
}


// 이벤트명 출력
void MultimediaContent::DisplayEventNameOnScreen() const {
	cout << "\tEvent name : " << m_EventName << endl;
}



// 콘텐츠 정보 출력
void MultimediaContent::DisplayRecordOnScreen() const {
	DisplayNameOnScreen();
	DisplayTypeOnScreen();
	DisplayDateOnScreen();
	DisplayPersonOnScreen();
	DisplayCategoryOnScreen();
	DisplayEventNameOnScreen();
	cout << endl;
}



// 키보드로 콘텐츠 이름 입력 함수
void MultimediaContent::SetNameFromKB() {
	string inName;
	cout << "\t====Content name====" << endl;
	cout << "\t>>> ";
	cin >> inName;
	SetName(inName);
	cout << endl;
}


// 키보드로 콘텐츠 타입 입력 함수
void MultimediaContent::SetTypeFromKB() {
	string type;
	cout << "\t====Content type====" << endl;
	cout << "\t(Picture : 0 / Video : 1)>>> ";
	cin >> type;
	if (type == "0") {
		SetType(PICTURE);
	}
	else if (type == "1") {
		SetType(VIDEO);
	}
	else {
		SetType(UNKNOWN);
	}
	cout << endl;
}


// 키보드로 콘텐츠 생성 날짜와 시간 입력 함수
void MultimediaContent::SetDateFromKB() {
	string inDate;
	cout << "\t====Generated date====" << endl;
	cout << "\t>>> ";
	cin >> inDate;
	SetDate(inDate);
	cout << endl;
}


// 키보드로 콘텐츠에 포함된 사람 입력 함수
void MultimediaContent::SetPersonFromKB() {
	string inPerson;
	cout << "\t====Included person====" << endl;
	cout << "\t>>> ";
	cin >> inPerson;
	SetPerson(inPerson);
	cout << endl;
}

// 키보드로 콘텐츠에 포함된 사람 입력 함수
void MultimediaContent::SetCategoryFromKB() {
	int inCategory;
	cout << "\t====Category( 0:인물 / 1:동물 / 2:사물 / 3:배경 )====" << endl;
	cout << "\t>>> ";
	cin >> inCategory;
	SetCategory(inCategory);
	cout << endl;
}

// 키보드로 이벤트 명 입력 함수
void MultimediaContent::SetEventNameFromKB() {
	string inEvent;
	cout << "\t====Event name====" << endl;
	cout << "\t>>> ";
	cin >> inEvent;
	SetEventName(inEvent);
	cout << endl;
}


// 키보드로 콘텐츠 정보 입력 함수
void MultimediaContent::SetRecordFromKB() {
	cout << "\t===SetRecord===" << endl << endl;
	cout << "\t_1_ ";
	SetNameFromKB();
	cout << "\t_2_ ";
	SetTypeFromKB();
	cout << "\t_3_ ";
	SetDateFromKB();
	cout << "\t_4_ ";
	SetPersonFromKB();
	cout << "\t_5_ ";
	SetCategoryFromKB();
	cout << "\t_6_ ";
	SetEventNameFromKB();
	cout << endl;
}


// 콘텐츠 정보를 파일에서 읽는 함수
int MultimediaContent::ReadDataFromFile(ifstream& fin) {
	string inType;
	fin >> m_cName >> inType >> m_Date >> m_Person >> m_Category >> m_EventName;
	if (inType == "PICTURE") {
		SetType(PICTURE);
	}
	else if (inType == "VIDEO") {
		SetType(VIDEO);
	}
	if (fin) { return 1; }
	else { return 0; }
}


// 콘텐츠 정보를 파일로 출력하는 함수
int MultimediaContent::WriteDataToFile(ofstream& fout) {
	string outType;
	if (m_cType == PICTURE) {
		outType = "PICTURE";
	}
	else if (m_cType == VIDEO) {
		outType = "VIDEO";
	}
	else {
		outType = "UNKNOWN";
	}
	fout << m_cName << '\t' << outType << '\t' << m_Date << '\t' << m_Person << '\t' << m_Category << '\t' << m_EventName << endl;
	if (fout) { return 1; }
	else { return 0; }
}



