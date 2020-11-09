#include "mainwindow.h"

#include <QApplication>

#include "TemplateVector.h"
using namespace myStd;

#include <iostream>
#include <iomanip>      // std::setprecision
#include <algorithm>    // std::find, std::sort

using std::cout;
using std::endl;

using std::find;
using std::sort;

template <typename Iterator>
Iterator low(Iterator first, Iterator last);

template <typename Iterator>
void selection_sort(Iterator first, Iterator last);

template <typename type>
void print_vector(const vector<type>& v);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    const int initSize = 5;
    vector<double> myDoubleVector(initSize);

    // push ten doubles into my vector
    //for (int i=0; i<10; i++) myDoubleVector.push_back(i);

    // modify elements 2,3,4
    myDoubleVector[1] = -1.0;
    myDoubleVector[2] = -2.0;
    myDoubleVector[3] = -3.0;

    // print vector
    print_vector(myDoubleVector);

    myDoubleVector.erase(myDoubleVector.begin());

    // print vector
    print_vector(myDoubleVector);

    //myDoubleVector.insert(myDoubleVector.begin()+3,99.0);

    // print vector
    print_vector(myDoubleVector);

    // use fixed notation with precision 1
    cout << std::setprecision(1) << std::fixed;

    // find value 99.0
    //added<double> to vector on line 62
    vector<double>::iterator it = find(myDoubleVector.begin(),myDoubleVector.end(),99.0);
    cout << "found vector value: " << *it << endl;

    // find lowest value
    it = low(myDoubleVector.begin(),myDoubleVector.end());
    cout << "found vector lowest value: " << *it << endl;

    // sort vector
    selection_sort(myDoubleVector.begin(),myDoubleVector.end());
    //sort(myDoubleVector.begin(),myDoubleVector.end());
    print_vector(myDoubleVector);

    return a.exec();
}

template <typename Iterator>
Iterator low(Iterator first, Iterator last)
    // return an iterator to the element in [first:last) that has the lowest value
{
    Iterator low = first;
    for (Iterator p=first; p!=last; ++p)
        if (*low > *p) low = p;
    return low;
}

template <typename Iterator>
void selection_sort(Iterator first, Iterator last)
    // sort container elements from smallest to largest using the selection sort method
{
    int n = last - first;
    for(int x=0; x<n; x++)
    {
        int index_of_min = x;
        for(int y=x; y<n; y++)
        {
            if(*(first+index_of_min) > *(first+y))
            {
                index_of_min = y;
            }
        }

        auto temp = *(first+x);
        *(first+x) = *(first+index_of_min);
        *(first+index_of_min) = temp;
    }
}
template <typename type>
void print_vector(const vector<type>& v)
{
    for (int i=0; i<v.size(); i++) cout << v[i] << " ";
    cout << endl;
}
