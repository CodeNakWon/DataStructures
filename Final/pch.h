#pragma once
#ifndef PCH_H
#define PCH_H

// TODO: 여기에 미리 컴파일하려는 헤더 추가

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
#include "CSortedList.h"

// Type
#include<qstring.h>
#include "CContent.h"
#include "CGroup.h"


//App
#include <QDateTime>
#include <QtWidgets/QMainWindow>

#include <QMessageBox>
#include <QTableWidget>
#include <QWidget>
#include <QDialog>
#include "Widget.h"
#include "AddCon.h"

#include <qfiledialog.h>




#endif //PCH_H
