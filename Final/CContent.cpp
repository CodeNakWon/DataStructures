#include "pch.h"
#include "CContent.h"

// 콘텐츠 이름 반환
QString Content::GetName() const {
	return m_cName;
}


// 콘텐츠 종류 반환
QString Content::GetType() const {
	return m_cType;
}


// 콘텐츠 생성날짜와 시간 반환
QString Content::GetDate() const {
	return m_Date;
}

// 콘텐츠 장소 반환
QString Content::GetLocation() const {
	return m_location;
}

// 콘텐츠에 포함된 사람 반환
QString Content::GetPerson() const {
	return m_Person;
}

//이벤트 명 반환
QString Content::GetEventName() const {
	return m_EventName;
}

int Content::GetViews() const {
	return m_views;
}

QString Content::GetPath() const {
	return m_Path;
}


// 콘텐츠 이름 저장
void Content::SetName(QString inName) {
	m_cName = inName;
}


// 콘텐츠 종류 저장
void Content::SetType(QString inType) {
	m_cType = inType;

}


// 콘텐츠 생성날짜와 시간 저장
void Content::SetDate(QString inDate) {
	m_Date = inDate;
}

void Content::SetLocation(QString inLocation) {

	m_location = inLocation;

}


// 콘텐츠에 포함된 사람 저장
void Content::SetPerson(QString inPerson) {

	m_Person = inPerson;

}


// 이벤트명 저장
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