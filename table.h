#ifndef TABLE_H_INCLUDED
#define TABLE_H_INCLUDED
#include <ctime>
class Table
{
private:
         int packed;
         int table_no;
         int *foodcode;
         int *quantity;
         int variety;
         char *tempfoodname;
         int tempfoodprice;
         int totalprice;

public:
         Table();
         ~Table();
         // void times(char date[]);
         void settableno(int x);
         void takeorder();
         void displaytable();
         char ispacked();
         void cleartable();



};




#endif // TABLE_H_INCLUDED
