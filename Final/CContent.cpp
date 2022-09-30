#include "pch.h"
#include "CContent.h"

// ������ �̸� ��ȯ
QString Content::GetName() const {
	return m_cName;
}


// ������ ���� ��ȯ
QString Content::GetType() const {
	return m_cType;
}


// ������ ������¥�� �ð� ��ȯ
QString Content::GetDate() const {
	return m_Date;
}

// ������ ��� ��ȯ
QString Content::GetLocation() const {
	return m_location;
}

// �������� ���Ե� ��� ��ȯ
QString Content::GetPerson() const {
	return m_Person;
}

//�̺�Ʈ �� ��ȯ
QString Content::GetEventName() const {
	return m_EventName;
}

int Content::GetViews() const {
	return m_views;
}

QString Content::GetPath() const {
	return m_Path;
}


// ������ �̸� ����
void Content::SetName(QString inName) {
	m_cName = inName;
}


// ������ ���� ����
void Content::SetType(QString inType) {
	m_cType = inType;

}


// ������ ������¥�� �ð� ����
void Content::SetDate(QString inDate) {
	m_Date = inDate;
}

void Content::SetLocation(QString inLocation) {

	m_location = inLocation;

}


// �������� ���Ե� ��� ����
void Content::SetPerson(QString inPerson) {

	m_Person = inPerson;

}


// �̺�Ʈ�� ����
void Content::SetEventName(QString inEventName) {

	m_EventName = inEventName;

}

void Content::SetPath(QString inPath) {
	m_Path = inPath;
}

void Content::SetViews(int inViews) {
	m_views = inViews;
}

void Content::ViewCon() {
	m_views++;
}