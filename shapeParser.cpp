#include <iostream>
#include <string>
#include <ios>
#include <limits>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

string getStringFromFile(fstream &file);

// This will be in shape.h
enum shapes { LINE, POLYLINE, POLYGON, RECTANGE, SQUARE, ELLIPSE, CIRCLE, TEXT};
const string SHAPE_LIST [8] {"Line", "Polyline", "Polyogon", "Rectangle", "Square", "Ellipse", "CIRCLE", "TEXT"};


int main()
{


	string filename = "shapes.txt";
	// I had to convert the string into a char, fstreams constructor takes in a char
	// so i converted filename to a char
	// Im a bit confused on the second parameter, i just followed an example, but some examples us ifstream::in or fstream::in,
	// I tried compiling without it and it also worked, so a bit confused there
	fstream dataFile(filename.c_str(), ios::in);

	// This uses stoi to convert the string into an int
	// This will be used to hold the shapes id
	int tempId = stoi(getStringFromFile(dataFile));

	// This takes the information returned from getStringFromFile;
	// For ex: The secons line in shapes.txt is ShapeType: Line, getStringFromFile will only return Line(only the info we need)
	string tempName = getStringFromFile(dataFile);
	// Same as the previous one but gets the dimensions ex: 20, 90, 100, 20 (dimensions of the line)
	string dimensions =  getStringFromFile(dataFile);


	// testing to see the output
	cout << tempId << endl;
	cout << tempName << endl;
	cout << dimensions;

	Shape *shapePtr = nullptr;

// This will return a Shape pointer that points to a new Shape
	shapePtr = getShapePtr(tempName);

	int d;
	vector<int> vDimensions;

	istringstream iss{dimensions};

//	  for (int n=0; n<5; n++)
//	  {
//	    int val;
//	    iss >> val;
//	    std::cout << val*2 << '\n';
//	  }

	  while(iss >> d)
	  {
		  vDimensions.push_back(d);

		  char cTemp = iss.peek();
          if(cTemp == ',')
		  {
			  iss.ignore();
		  }
	  }

	  cout << endl;

	  for(int i = 0; i < vDimensions.size(); i++)
	  {
		  cerr << vDimensions.at(i) << " ";
	  }

	  int tempNumDimensions = vDimensions.size();

	  shapePtr ->setInfo(tempId, tempName, tempNumDimensions, vDimensions);
	  shapePtr ->setPosition();
    return 0;
}

// The file goes into the parameter
// file.ignore(numeric_limits<streamsize>::max(),' '); <-- this will ignore all charachers in the shape file until it reaches a space
// ex: ShapeType: Line <-- is the second line in the file. it will ignore everything till it reaches a space
// so it will ignore this -> ShapeType:
// then after ignoring the useless information it will get the rest of the line until it reaches a new line
// "Line" will be stored into temp and returned
string getStringFromFile(fstream &file)
{
    string temp;

    file.ignore(numeric_limits<streamsize>::max(),' ');
    getline(file, temp, '\n');

    return temp;
}

// So I pass in the string that was returned from getStringFromFile
// It will look through the array SHAPE_List and if found it will creat a new object of that shape
Shape* getShapePtr(string shapeType)
{
	Shape* shapePtr = nullptr;

	if(shapeType == SHAPE_LIST[LINE])
	{
		shapePtr = new Line();
	}
	if(shapeT)

	return shapePtr;
}
