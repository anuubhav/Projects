#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QRadioButton>
#include <QListWidget>
#include <QGroupBox>
#include <QString>
#include <string>
#include <vector>
#include "data.h"

class MainWindow : public QWidget
{
	Q_OBJECT
public:
	MainWindow(Data* ds_original);
	~MainWindow();


private slots:
	void AndOrSearch();


private:
	//stores all of the data
  	Data* ds;

	//main layout
	QVBoxLayout* overallLayout;

	//search
	QHBoxLayout* searchLayout;
	QLabel* searchTermDisplay;
	QLineEdit* searchTermInput;
	QPushButton* searchButton;
	QRadioButton* andButton;
	QRadioButton* orButton;
	QHBoxLayout* andOrLayout;
	QListWidget* searchListWidget;
	//list of items
	//QListWidget* itemListWidget;

	//form for search
};