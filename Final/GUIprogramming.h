#pragma once
#include "ui_GUIprogramming.h"
#include "pch.h"



class GUIprogramming : public QMainWindow
{
    Q_OBJECT

public:
    GUIprogramming(QWidget *parent = Q_NULLPTR);


    /**
    *	@brief	컨텐츠를 추가한다
    *	@pre	없음
    *	@post	컨텐츠가 마스터리스트에 추가됨
    *	@param	con 추가된 컨텐츠
    */
    void Add(Content con);


    /**
    *	@brief	컨텐츠를 추가한다
    *	@pre	없음
    *	@post	컨텐츠가 마스터리스트에 추가됨
    *	@param	con 추가된 컨텐츠
    */
    void Delete(Content con);


    /**
    *	@brief	컨텐츠를 수정한다.
    *	@pre	
    *	@post	컨텐츠가 수정됨
    *	@param	con 추가된 컨텐츠
    */
    void Replace(Content con);

    /**
    *	@brief	메인 테이블을 그린다.
    *	@pre    마스터리스트가 초기화됨
    *	@post	메인 테이블이 그려짐
    */
    void DrawTable();

    /**
    *	@brief	그룹 테이블을 다시 그린다.
    *	@pre    그룹리스트가 초기화됨
    *	@post	그룹 테이블이 그려짐
    *	@param	n 다시그릴 테이블의 index
    */
    void Update_Group(int n);

    /**
    *	@brief	컨텐츠를 그룹에 추가한다.
    *	@pre    없음
    *	@post	켄텐츠가 그룹 리스트에 추가됨
    *	@param	con 추가할 콘텐츠
    */
    void Add_Group(Content con);

    /**
    *	@brief	컨텐츠를 그룹에서 삭제한다.
    *	@pre    없음
    *	@post	켄텐츠가 그룹 리스트에서 삭제됨
    *	@param	con 삭제할 콘텐츠
    */
    void Delete_Group(Content con);

    /**
    *	@brief	컨텐츠를 화면서 보여준다.
    *	@pre    컨텐츠가 초기화됨
    *	@post	컨텐츠가 화면에 보여짐
    *	@param	con 보여줄 컨텐츠
    */
    void Display(Content con);

    /**
    *	@brief	그룹 설명을 설정한다
    *	@pre    없음
    *	@post	그룹 설명이 설정됨
    *	@param	g 그룹설명을 설정할 그룹
    *  	@param	n 설정할 그룹의 index
    */
    void SetDescription(Group g, int n);

    /**
    *	@brief	체크박스의 입력을 바탕으로 그룹을 찾는다.
    *	@pre    없음
    *	@post	그룹을 찾음
    *  	@return 일치하는 그룹이 존재하면 ture 그렇지 않으면 false 를 반환 
    */
    bool Find_Group();

private:
    Ui::GUIprogrammingClass ui;
    AddCon* newWin_Add = Q_NULLPTR;
    Widget* newWin_Group = Q_NULLPTR;
    bool isOpened_Add = false;
    SortedList<Content> m_MList; // 마스터 리스트
    int m_HiRow = 0; // 마스터 테이블에서 선택된 줄
    int m_Hif = 0; // 좋아하는 테이블에서 선택된 줄
    int m_GRow = 0; // 그룹 테이블에서 선택된 줄
    SortedList<Group> m_event; // 이벤트 리스트
    SortedList<Group> m_person; // 사람 리스트
    SortedList<Group> m_location; // 장소 리스트
    SortedList<QString> m_keys; // 검색용 저장 리스트
    SortedList<QString> m_fp; // 좋아하는 사진 리스트
    SortedList<QString> m_fv; // 좋아하는 비디오 리스트
public slots:
    // 메인테이블에서 헝목을 선택했을 때 호출
    void select_Row(int row, int col);

    // 추가버튼을 눌렀을 때 호출
    void open_Add();

    // 삭제 버튼을 눌렀을 때 호출
    void open_delete();

    // 수정 항목을 눌렀을 때 호출
    void open_Replace();

    // 메인테이블에서 항목을 더블클릭 했을 때 호출
    void display_content(int row, int col);

    // 그룹테이블에서 항목을 더블클릭 했을 때 호출
    void display_content_g(int row, int col);

    // 좋아하는 컨텐츠 테이블에서 항목을 더블클릭 했을 때 호출
    void display_content_f(int row, int col);

    //검색을 눌렀을 떄 호출
    void search_con();

    //그룹테이블에서 항목을 더블 클릭했을 때 호출
    void open_group(int row, int col);

    //상세 검색을
    void search_advanced();

    //좋아요를 눌렀을때 호출
    void add_favorite();

    //-버튼을 눌렀을때 호출
    void delete_favorite();

    //좋아하는 리스트에서 선택시 호출
    void selet_FRow(int row, int col);
};
