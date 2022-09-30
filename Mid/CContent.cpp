#include "pch.h"
#include "CContent.h"

// 콘텐츠 이름 반환
string Content::GetName() const {
	return m_cName;
}


// 콘텐츠 종류 반환
ContentType Content::GetType() const {
	return m_cType;
}


// 콘텐츠 생성날짜와 시간 반환
string Content::GetDate() const {
	return m_Date;
}

// 콘텐츠 장소 반환
string Content::GetLocation() const {
	return m_location;
}

// 콘텐츠에 포함된 사람 반환
string Content::GetPerson() const {
	return m_Person;
}

// 콘텐츠 구분 반환
int Content::GetCategory() const {
	return m_Category;
}

//이벤트 명 반환
string Content::GetEventName() const {
	return m_EventName;
}

int Content::GetViews() const {
	return m_views;
}


// 콘텐츠 이름 저장
void Content::SetName(string inName) {
	m_cName = inName;
}


// 콘텐츠 종류 저장
void Content::SetType(ContentType inType) {
	m_cType = inType;

}


// 콘텐츠 생성날짜와 시간 저장
void Content::SetDate(string inDate) {
	m_Date = inDate;
}

void Content::SetLocation(string inLocation) {
	m_keywords.Delete(m_location);
	m_location = inLocation;
	m_keywords.Add(m_location);
}


// 콘텐츠에 포함된 사람 저장
void Content::SetPerson(string inPerson) {
	m_keywords.Delete(m_Person);
	m_Person = inPerson;
	m_keywords.Add(m_Person);
}

// 콘텐츠 구분 저장
void Content::SetCategory(int inCategory) {
	m_Category = inCategory;
}

// 이벤트명 저장
void Content::SetEventName(string inEventName) {
	m_keywords.Delete(m_EventName);
	m_EventName = inEventName;
	m_keywords.Add(m_EventName);
}


// 이벤트 정보 저장
void Content::SetRecord(string inName, ContentType inType, string inDate,string inLocation, string inPerson,int inCategory ,string inEventName) {
	SetName(inName);
	SetType(inType);
	SetDate(inDate);
	SetLocation(inLocation);
	SetPerson(inPerson);
	SetCategory(inCategory);
	SetEventName(inEventName);
}


// 콘텐츠 이름 출력
void Content::DisplayNameOnScreen() const {
	cout << "\tContent name : " << m_cName << endl;
}


// 콘텐츠 종류 출력
void Content::DisplayTypeOnScreen() const {
	if (m_cType == VIDEO) {
		cout << "\tContent type: " << "Video" << endl;
	}
	else if (m_cType == PHOTO) {
		cout << "\tContent type : " << "Picture" << endl;
	}
	else {
		cout << "\tContent type : " << "Unknown" << endl;
	}
}


// 콘텐츠 생성날짜와 시간 출력
void Content::DisplayDateOnScreen() const {
	cout << "\tContent generated date : " << m_Date << endl;
}

// 콘텐츠 장소 출력
void Content::DisplayLocationOnScreen() const {
	cout << "\tLocation : " << m_location << endl;
}


// 콘텐츠에 포함된 사람 출력
void Content::DisplayPersonOnScreen() const {
	cout << "\tContent included person : " << m_Person << endl;
}

// 콘텐츠 구분 출력
void Content::DisplayCategoryOnScreen() const {
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
void Content::DisplayEventNameOnScreen() const {
	cout << "\tEvent name : " << m_EventName << endl;
}



// 콘텐츠 정보 출력
void Content::DisplayRecordOnScreen() {
	DisplayNameOnScreen();
	DisplayTypeOnScreen();
	DisplayDateOnScreen();
	DisplayLocationOnScreen();
	DisplayPersonOnScreen();
	DisplayCategoryOnScreen();
	DisplayEventNameOnScreen();
	cout <<"\t 조회수: "<<++m_views << endl;
	cout << endl;
}



// 키보드로 콘텐츠 이름 입력 함수
void Content::SetNameFromKB() {
	string inName;
	cout << "\t====Content name====" << endl;
	cout << "\t>>> ";
	cin >> inName;
	SetName(inName);
	cout << endl;
}



// 키보드로 콘텐츠 타입 입력 함수
void Content::SetTypeFromKB() {
	string type;
	cout << "\t====Content type====" << endl;
	cout << "\t(Picture : 0 / Video : 1)>>> ";
	cin >> type;
	if (type == "0") {
		SetType(PHOTO);
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
void Content::SetDateFromKB() {
	string inDate;
	cout << "\t====Generated date====" << endl;
	cout << "\t>>> ";
	cin >> inDate;
	SetDate(inDate);
	cout << endl;
}

void Content::SetLocationFromKB() {
	string inLocation;
	cout << "\t====Location====" << endl;
	cout << "\t>>> ";
	cin >> inLocation;
	SetLocation(inLocation);
	cout << endl;
}

// 키보드로 콘텐츠에 포함된 사람 입력 함수
void Content::SetPersonFromKB() {
	string inPerson;
	cout << "\t====Included person====" << endl;
	cout << "\t>>> ";
	cin >> inPerson;
	SetPerson(inPerson);
	cout << endl;
}

// 키보드로 콘텐츠에 포함된 사람 입력 함수
void Content::SetCategoryFromKB() {
	int inCategory;
	cout << "\t====Category( 0:인물 / 1:동물 / 2:사물 / 3:배경 )====" << endl;
	cout << "\t>>> ";
	cin >> inCategory;
	SetCategory(inCategory);
	cout << endl;
}

// 키보드로 이벤트 명 입력 함수
void Content::SetEventNameFromKB() {
	string inEvent;
	cout << "\t====Event name====" << endl;
	cout << "\t>>> ";
	cin >> inEvent;
	SetEventName(inEvent);
	cout << endl;
}


// 키보드로 콘텐츠 정보 입력 함수
void Content::SetRecordFromKB(string indate) {
	cout << "\t===SetRecord===" << endl << endl;
	cout << "\t_1_ ";
	SetDate(indate);
	DisplayDateOnScreen();
	cout << "\t_2_ ";
	SetNameFromKB();
	cout << "\t_3_ ";
	SetTypeFromKB();
	cout << "\t_4_ ";
	SetLocationFromKB();
	cout << "\t_5_ ";
	SetPersonFromKB();
	cout << "\t_6_ ";
	SetCategoryFromKB();
	cout << "\t_7_ ";
	SetEventNameFromKB();
	cout << endl;
}

// 콘텐츠 정보 수정
void Content::ModifyRecord() {
	cout << "\t===SetRecord===" << endl << endl;
	cout << "\t_1_ ";
	DisplayDateOnScreen();
	cout << "\t_2_ ";
	DisplayNameOnScreen();
	cout << "\t_3_ ";
	SetTypeFromKB();
	cout << "\t_4_ ";
	SetLocationFromKB();
	cout << "\t_5_ ";
	SetPersonFromKB();
	cout << "\t_6_ ";
	SetCategoryFromKB();
	cout << "\t_7_ ";
	SetEventNameFromKB();
	cout << endl;
}



// 해당 키워드가 존재하는지 확인하는 함수
int Content::KeyWordSearch(SortedList<string>& keys) {
	if (keys.GetLength() == 0) {
		return 0;
	}
	string str;
	keys.ResetList();
	while (keys.GetNextItem(str) != -1) {
		if (m_keywords.Retrieve(str) == 0 ) {
			return 0;
		}
	}
	return 1;
}


// 콘텐츠 정보를 파일에서 읽는 함수
int Content::ReadDataFromFile(ifstream& fin) {
	m_keywords.Delete(m_Person);
	m_keywords.Delete(m_location);
	m_keywords.Delete(m_EventName);
	string inType;
	fin >> m_cName >> inType >> m_Date >>m_location>>m_Person >> m_Category >> m_EventName >>m_views;
	m_keywords.Add(m_Person);
	m_keywords.Add(m_location);
	m_keywords.Add(m_EventName);
	if (inType == "PICTURE") {
		SetType(PHOTO);
	}
	else if (inType == "VIDEO") {
		SetType(VIDEO);
	}
	if (fin) { return 1; }
	else { return 0; }
}


// 콘텐츠 정보를 파일로 출력하는 함수
int Content::WriteDataToFile(ofstream& fout) {
	string outType;
	if (m_cType == PHOTO) {
		outType = "PICTURE";
	}
	else if (m_cType == VIDEO) {
		outType = "VIDEO";
	}
	else {
		outType = "UNKNOWN";
	}
	fout << m_cName << '\t' << outType << '\t' << m_Date << '\t'<<m_location<<'\t' << m_Person << '\t' << m_Category << '\t' << m_EventName <<'\t'<<m_views <<endl;
	if (fout) { return 1; }
	else { return 0; }
}



