#include "shapeParser.h"

string getStringFromFile(ifstream &file)
{
    string temp;

    file.ignore(numeric_limits<streamsize>::max(),' ');
    getline(file, temp, '\n');

    return temp;
}

Shape* getShapePtr(string shapeType)
{
	Shape* shapePtr = nullptr;

	if(shapeType == SHAPE_LIST[LINE])
	{
		shapePtr = new Line();
	}
	else if(shapeType == SHAPE_LIST[POLYLINE])
	{
		shapePtr = new Polyline();
	}
	else if(shapeType == SHAPE_LIST[POLYGON])
	{
		shapePtr = new Polygon();
	}
	else if(shapeType == SHAPE_LIST[RECTANGLE])
	{
		shapePtr = new Rectangle();
	}
	else if(shapeType == SHAPE_LIST[SQUARE])
	{
		shapePtr = new Square();
	}
	else if(shapeType == SHAPE_LIST[ELLIPSE])
	{
		shapePtr = new Ellipse();
	}
	else if(shapeType == SHAPE_LIST[CIRCLE])
	{
		shapePtr = new Circle();
	}
	else if(shapeType == SHAPE_LIST[TEXT])
	{
		shapePtr = new Text();
	}


	return shapePtr;
}

void parseShape(vector<Shape*>& vShapeList)
{
	int    tempId = 0;
	int    tempNumDimensions = 0;
	string tempName;
	string dimensionsString;

	ifstream dataFile;
	dataFile.open("Shapes");

	while(dataFile)
	{
		tempId = stoi(getStringFromFile(dataFile));

		dimensionsString = getStringFromFile(dataFile);

		Shape *shapePtr = nullptr;
		shapePtr = getShapePtr(tempName);

		int dimensions;

		vector<int> vDimensions;

		istringstream buffer(dimensionsString);

		while(buffer >> dimensions)
		{
			vDimensions.push_back(dimensions);

			char cTemp = buffer.peek();
			if(cTemp == ",")
			{
				buffer.ignore();
			}
		}

		tempNumDimensions = vDimensions.size();

		shapePtr ->setInfo(tempId, tempName, tempNumDimensions, vDimensions);

		QPen pen;

		string color = getStringFromFile(dataFile);
		int penWidth = stoi(getStringFromFile(dataFile));
		string penStyle = getStringFromFile(dataFile);
		string capStyle = getStringFromFile(dataFile);
		string joinStyle = getStringFromFile(dataFile);

		pen.setColor(QColor(color.c_str()));
		pen.setWidth(penWidth);
		pen.setStyle(penStyleConversion(penStyle));
		pen.setCapStyle(penCapConversion(capStyle));
		pen.setJoinStyle(penJoinConversion(joinStyle));

		shapePtr->setPen(pen);

        if(tempName != "Line" && tempName != "Polyline")
        {
        	Qbrush brush;

        	string brushColor = getStringFromFile(dataFile);
        	string brushStyle = getStringFromFile(dataFile);

        	brush.setColor(QColor(brushColor.c_str()));
        	brush.setStyle(brushStyleConversion(brushStyle));

        	shapePtr-> setBrush(brush);
        }

        vShapeList.push_back(shapePtr);

        dataFile.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}

Qt::PenStyle penStyleConversion(string style)
{
	Qt::PenStyle tempStyle;

	if(style == "NoPen")
	{
		tempStyle = Qt::NoPen;
	}
	else if(style == "SolidLine")
	{
		tempStyle = Qt::SolidLIne;
	}
	else if(style == "DashLine")
	{
		tempStyle = Qt::DashLine;
	}
	else if(style == "DotLine")
	{
		tempStyle = Qt::DotLine;
	}
	else if(style == "DashDotLine")
	{
		tempStyle = Qt::DashDotLine(3);
	}
	else if(style == "DashDotDotLine")
	{
		tempStyle = Qt::DashDotDotLine;
	}

	return tempStyle;
}

Qt::PenCapStyle penStyleConversion(string capStyle)
{
	Qt::PenCapStyle tempCap;

	if(capStyle == "FlatCap")
	{
		tempCap = Qt::FlatCap;
	}
	else if(capStyle == "SquareCap")
	{
		tempCap = Qt::SquareCap;
	}
	else if(capStyle == "RoundCap")
	{
		tempCap = Qt::RoundCap;
	}

	return tempCap;
}

Qt::PenJoinStyle penJoinConversion(string joinStyle)
{
	Qt::PenJoinStyle tempJoin;

	if(joinStyle == "MiterJoin")
	{
		tempJoin = Qt::MilterJoin;
	}
	else if(joinStyle == "BevelJoin")
	{
		tempJoin = Qt::BevelJoin;
	}
	else if(joinStyle == "RoundJoin")
	{
		tempJoin = Qt::RoundJoin;
	}
	else if(joinStyle == "SvgMiterJoin")
	{
		tempJoin = Qt::SvgMiterJoin;
	}

	return tempJoin;
}

Qt::BrushStyle brushStyleConversion(string brushStyle)
{
	Qt::BrushStyle tempBrush;

	if(brushStyle == "SolidPattern")
	{
		tempBrush = Qt::SolidPattern;
	}
	else if(brushStyle == "VerPattern")
	{
		tempBrush = Qt::VerPattern;
	}
	else if(brushStyle == "HorPattern")
	{
		tempBrush = Qt::HorPattern;
	}
	else if(brushStyle == "NoBrush")
	{
		tempBrush = Qt::NoBrush;
	}
	else if(brushStyle == "SolidPattern")
	{
		tempBrush = Qt::SolidPattern;
	}

	return tempBrush;
}
