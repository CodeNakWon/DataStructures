#ifndef PCH_H
#define PCH_H

// TODO: 여기에 미리 컴파일하려는 헤더 추가
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
using namespace std;

enum RelationType { LESS, GREATER, EQUAL };
enum ContentType { PHOTO = 0, VIDEO = 1, UNKNOWN = -1 };

#define FILENAMESIZE 1024
#define MAXSLIST 20
#define MAXLIST 20

//List
#include "CDoublyIterator.h"
#include "CLinkedList.h"

#include "CSortedList.h"
#include "CUnsortedList.h"

// Type
#include "CContent.h"
#include "CGroup.h"
#include "CPerson.h"
#include "CLocation.h"
#include "CEvent.h"



//App
#include "CGroupApplication.h"
#include "CApplication.h"





#endif //PCH_H
