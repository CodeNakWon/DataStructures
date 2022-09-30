#pragma once
#include "CArrayList.h"

class Application
{
public:
	/**
	*	@brief	프로그램 드라이버
	*	@pre	프로그램이 시작됨
	*	@post	프로그램이 종료됨
	*/
	void Run();

	/**
	*	@brief	명령어를 화면에 출력 후 키보드로 입력을 받음
	*	@pre	없음
	*	@post	없음
	*	@return	사용자가 입력한 명령어 
	*/
	int GetCommand();

	/**
	*	@brief	새로운 레코드를 리스트에 추가
	*	@pre	리스트가 초가화됨
	*	@post	새로운 레코드가 리스트에 추가됨
	*	@return	정상적으로 작동하면 1, 그렇지 않으면 0을 반환함
	*/
	int AddContents();
	
	/**
	*	@brief	파일 입력을 위해 파일을 파일 디스크립터로 연다
	*	@pre	읽을 파일이 존재함
	*	@post	읽기 위해 파일이 열림
	*	@param	fileName	읽기 위한 파일 이름
	*	@return	제대로 동작하면 1, 그렇지 않으면 0을 반환
	*/
	int OpenInFile(char* fileName);

	/**
	*	@brief	파일 출력을 위해 파일을 파일 디스크립터로 연다
	*	@pre	쓰기를 할 파일이 존재함
	*	@post	쓰기 위해 파일이 열림
	*	@param	fileName	쓰기 위한 파일 이름
	*	@return	제대로 동작하면 1, 그렇지 않으면 0을 반환
	*/
	int OpenOutFile(char* fileName);

	/**
	*	@brief	파일을 열어 읽고 파일의 데이터를 기반으로 리스트에 저장
	*	@pre	파일이 열리지 않음
	*	@post	리스트가 파일의 데이터를 저장함
	*	@return	제대로 동작하면 1, 그렇지 않으면 0을 반환
	*/
	int ReadDataFromFile();

	/**
	*	@brief	파일을 열고 리스트의 데이터를 파일에 쓴다.
	*	@pre	파일이 열리지 않음
	*	@post	리스트가 파일에 저장됨
	*	@return	제대로 동작하면 1, 그렇지 않으면 0을 반환
	*/
	int WriteDataToFile();

	/**
	*	@brief	콘텐츠의 이름을 입력 받아 리스트에서 삭제
	*	@pre	리스트가 초기화 됨
	*	@post	리스트에서 해당 콘텐츠 레코드가 삭제됨
	*	@return	제대로 동작하면 1, 그렇지 않으면 0을 반환
	*/
	int DeleteContents();	

	/**
	*	@brief	콘텐츠의 정보를 새로 입력된 정보로 갱신
	*	@pre	리스트가 초기화 됨
	*	@post	리스트에서 해당 콘텐츠 레코드가 대체됨
	*	@return	제대로 동작하면 1, 그렇지 않으면 0을 반환
	*/
	int ReplaceContents();

	/**
	*	@brief	이름을 입력받아서 리스트에서 해당 리스트를 찾아 화면 출력
	*	@pre	리스트가 초기화 됨
	*	@post	해당 리스트가 화면에 출력됨
	*	@return	제대로 동작하면 1, 그렇지 않으면 0을 반환
	*/
	int RetrieveContents();

	/**
	*	@brief	리스트 안의 모든 정보를 화면에 출력
	*	@pre	리스트가 초기화 됨
	*	@post	리스트 안의 모든 정보가 화면에 출력됨
	*/
	void DisplayAllContents();

	/**
	*	@brief	리스트를 비움
	*	@pre	없음
	*	@post	리스트가 비워짐
	*	@return	제대로 동작하면 1, 그렇지 않으면 0을 반환
	*/
	int MakeEmpty();

private:
	ifstream m_InFile;///< input file descriptor.
	ofstream m_OutFile;///< output file descriptor.
	ArrayList m_List;///< item list.
	int m_Command;///< current command number.
};