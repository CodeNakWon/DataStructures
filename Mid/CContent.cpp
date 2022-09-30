#include "pch.h"
#include "CContent.h"

// ������ �̸� ��ȯ
string Content::GetName() const {
	return m_cName;
}


// ������ ���� ��ȯ
ContentType Content::GetType() const {
	return m_cType;
}


// ������ ������¥�� �ð� ��ȯ
string Content::GetDate() const {
	return m_Date;
}

// ������ ��� ��ȯ
string Content::GetLocation() const {
	return m_location;
}

// �������� ���Ե� ��� ��ȯ
string Content::GetPerson() const {
	return m_Person;
}

// ������ ���� ��ȯ
int Content::GetCategory() const {
	return m_Category;
}

//�̺�Ʈ �� ��ȯ
string Content::GetEventName() const {
	return m_EventName;
}

int Content::GetViews() const {
	return m_views;
}


// ������ �̸� ����
void Content::SetName(string inName) {
	m_cName = inName;
}


// ������ ���� ����
void Content::SetType(ContentType inType) {
	m_cType = inType;

}


// ������ ������¥�� �ð� ����
void Content::SetDate(string inDate) {
	m_Date = inDate;
}

void Content::SetLocation(string inLocation) {
	m_keywords.Delete(m_location);
	m_location = inLocation;
	m_keywords.Add(m_location);
}


// �������� ���Ե� ��� ����
void Content::SetPerson(string inPerson) {
	m_keywords.Delete(m_Person);
	m_Person = inPerson;
	m_keywords.Add(m_Person);
}

// ������ ���� ����
void Content::SetCategory(int inCategory) {
	m_Category = inCategory;
}

// �̺�Ʈ�� ����
void Content::SetEventName(string inEventName) {
	m_keywords.Delete(m_EventName);
	m_EventName = inEventName;
	m_keywords.Add(m_EventName);
}


// �̺�Ʈ ���� ����
void Content::SetRecord(string inName, ContentType inType, string inDate,string inLocation, string inPerson,int inCategory ,string inEventName) {
	SetName(inName);
	SetType(inType);
	SetDate(inDate);
	SetLocation(inLocation);
	SetPerson(inPerson);
	SetCategory(inCategory);
	SetEventName(inEventName);
}


// ������ �̸� ���
void Content::DisplayNameOnScreen() const {
	cout << "\tContent name : " << m_cName << endl;
}


// ������ ���� ���
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


// ������ ������¥�� �ð� ���
void Content::DisplayDateOnScreen() const {
	cout << "\tContent generated date : " << m_Date << endl;
}

// ������ ��� ���
void Content::DisplayLocationOnScreen() const {
	cout << "\tLocation : " << m_location << endl;
}


// �������� ���Ե� ��� ���
void Content::DisplayPersonOnScreen() const {
	cout << "\tContent included person : " << m_Person << endl;
}

// ������ ���� ���
void Content::DisplayCategoryOnScreen() const {
	switch (m_Category) {
	case 0:// �ι�
		cout << "\tCategory : �ι�" << endl;
		break;
	case 1://����
		cout << "\tCategory : ����" << endl;
		break;
	case 2://�繰
		cout << "\tCategory : �繰" << endl;
		break;
	case 3://���
		cout << "\tCategory : ���" << endl;
		break;
	default:
		cout << "\tCategory : �� �� ����" << endl;
		break;
	}
}


// �̺�Ʈ�� ���
void Content::DisplayEventNameOnScreen() const {
	cout << "\tEvent name : " << m_EventName << endl;
}



// ������ ���� ���
void Content::DisplayRecordOnScreen() {
	DisplayNameOnScreen();
	DisplayTypeOnScreen();
	DisplayDateOnScreen();
	DisplayLocationOnScreen();
	DisplayPersonOnScreen();
	DisplayCategoryOnScreen();
	DisplayEventNameOnScreen();
	cout <<"\t ��ȸ��: "<<++m_views << endl;
	cout << endl;
}



// Ű����� ������ �̸� �Է� �Լ�
void Content::SetNameFromKB() {
	string inName;
	cout << "\t====Content name====" << endl;
	cout << "\t>>> ";
	cin >> inName;
	SetName(inName);
	cout << endl;
}



// Ű����� ������ Ÿ�� �Է� �Լ�
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


// Ű����� ������ ���� ��¥�� �ð� �Է� �Լ�
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

// Ű����� �������� ���Ե� ��� �Է� �Լ�
void Content::SetPersonFromKB() {
	string inPerson;
	cout << "\t====Included person====" << endl;
	cout << "\t>>> ";
	cin >> inPerson;
	SetPerson(inPerson);
	cout << endl;
}

// Ű����� �������� ���Ե� ��� �Է� �Լ�
void Content::SetCategoryFromKB() {
	int inCategory;
	cout << "\t====Category( 0:�ι� / 1:���� / 2:�繰 / 3:��� )====" << endl;
	cout << "\t>>> ";
	cin >> inCategory;
	SetCategory(inCategory);
	cout << endl;
}

// Ű����� �̺�Ʈ �� �Է� �Լ�
void Content::SetEventNameFromKB() {
	string inEvent;
	cout << "\t====Event name====" << endl;
	cout << "\t>>> ";
	cin >> inEvent;
	SetEventName(inEvent);
	cout << endl;
}


// Ű����� ������ ���� �Է� �Լ�
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

// ������ ���� ����
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



// �ش� Ű���尡 �����ϴ��� Ȯ���ϴ� �Լ�
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


// ������ ������ ���Ͽ��� �д� �Լ�
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


// ������ ������ ���Ϸ� ����ϴ� �Լ�
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



