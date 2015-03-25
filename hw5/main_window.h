#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QRadioButton>
#include <QListWidget>
#include <QGroupBox>
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
	//void search();


private:
	//stores all of the data
  	Data* ds;

	//main layout
	QHBoxLayout* overallLayout;

	//search
	QVBoxLayout* searchLayout;
	QLabel* searchTermDisplay;
	QLineEdit* searchTermInput;
	QPushButton* searchButton;
	QRadioButton* andButton;
	QRadioButton* orButton;
	QHxLayout* andOrLayout;
	//list of items
	QListWidget* itemListWidget;

	//form for search
};