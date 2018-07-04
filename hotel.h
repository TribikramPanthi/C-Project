#ifndef HOTEL_H_INCLUDED
#define HOTEL_H_INCLUDED
#include "table.h"
//#include "milan'stable.cpp"
class Hotel
{
private:
         int total_table;
         Table *table;

public:
         ~Hotel();
         void settotaltable();
         void readtotaltable();
         void displaypackedtable();
         char checkreadoftable();
         Hotel();
         void take_order();
         void display();
         void cleartable();
         void settable();
         void cleardata();
         void displayall();
         void display(int x);
         void displayalltabledatatostaff();

};



#endif // HOTEL_H_INCLUDED
