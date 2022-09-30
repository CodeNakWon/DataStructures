#pragma once

// Base class
class Content
{
protected:
	string title; // 컨텐츠 타이틀

public:
	virtual void SetTitle(string str) {
		title = str;
	}
	virtual void play() = 0;
	virtual void Read() = 0;
	
	// 연산자 오버로딩
	friend ostream& operator << (ostream& out, Content& con)
	{
		con.play();
		return out;
	}
	bool operator< (const Content& mc) const {
		if (title < mc.title) {
			return true;
		}
		else {
			return false;
		}
	}
	bool operator> (const Content& mc) const {
		if (title > mc.title) {
			return true;
		}
		else {
			return false;
		}
	}
	bool operator== (const Content& mc) const {
		if (title == mc.title) {
			return true;
		}
		else {
			return false;
		}
	}


};


// 사진 컨텐츠
class Photo : public Content {
private:
	string person; //인물
	string location; //장소
	string event; // 이벤트
public:
	void play() override {
		cout << "\t--Photo--" << endl;
		cout << "\tTitle : " << title << endl;
		cout << "\tPerson : " << person << endl;
		cout << "\tLocation : " << location << endl;
		cout << "\tEvent : " << event << endl;
	}

	void Read() override {
		cout << "\tTitle -> ";
		cin >> title;
		cout << "\tPerson -> ";
		cin >> person;
		cout << "\tLocation -> ";
		cin >> location;
		cout << "\tEvent -> ";
		cin >> event;
	}

};

// 동영상 컨텐츠
class Video : public Content {
private:
	string person; // 인물
	string location; // 장소
	string event; // 이벤트
	string len; // 재생시간 ex) "4:30"
public:
	void play() override {
		cout << "\t--Video--" << endl;
		cout << "\tTitle : " << title << endl;
		cout << "\tPerson : " << person << endl;
		cout << "\tLocation : " << location << endl;
		cout << "\tEvent : " << event << endl;
		cout << "\tPlaying time : " << len << endl;
	}
	void Read() override {
		cout << "\tTitle -> ";
		cin >> title;
		cout << "\tPerson -> ";
		cin >> person;
		cout << "\tLocation -> ";
		cin >> location;
		cout << "\tEvent -> ";
		cin >> event;
		cout << "\tplaying time -> ";
		cin >> len;
	}

};

