#include "main_window.h"
#include "db_parser.h"
#include <QApplication>

int main(int argc, char* argv[])
{
	
  Data ds;
  // Instantiate the parser
  DBParser parser;

  // Instantiate the individual product parsers we want
  parser.addProductParser(new ProductBookParser);
  parser.addProductParser(new ProductClothingParser);
  parser.addProductParser(new ProductMovieParser);

  // Now parse the database to populate the DataStore
  if( parser.parse(argv[1], ds) ){
    cerr << "Error parsing!" << endl;
    return 1;
  }

	QApplication app(argc, argv);

	MainWindow mainWindow(&ds);

	mainWindow.show();

	return app.exec();
}