#ifndef PCH_H
#define PCH_H

// TODO: 여기에 미리 컴파일하려는 헤더 추가
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

enum RelationType { LESS, GREATER, EQUAL };
enum ContentType { PICTURE = 0, VIDEO = 1, UNKNOWN = -1 };

#define FILENAMESIZE 1024
#define MAXSLIST 5
#define MAXLIST 5
#define MAXQUEUE 5

// Type
#include "CMultimediaContent.h"
#include "CFavoriteContent.h"


//List
#include "CSortedList.h"
#include "CList.h"
#include "CCircularQueueType.h"
#include "CEvent.h"
#include "CSortedLinkedList.h"

// App
#include "CApplication_FC.h"
#include "CApplication.h"




#endif //PCH_H
