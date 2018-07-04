#include "table.h"
#include "GLOBAL.h"
#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <iomanip>
using namespace std;


Table::Table()
{
         packed=0;
         table_no=0;
         variety=0;
         foodcode=new int[10];
         quantity=new int[10];
         tempfoodname=new char[20];
         tempfoodprice=0;
         totalprice=0;
}

Table::~Table()
{
         delete[]foodcode;
         delete[]quantity;
         delete[]tempfoodname;
}

void Table::settableno(int x)
{
         table_no=x;
}
void Table::takeorder()
{
        // char date[40];
        // times(date);
         packed=1;
         char choice='y';
         while(choice=='y')
         {
         cout<<endl;
         cout<<"Enter the code of food  ";
         cin>>foodcode[variety];
         // times(date);
         global->return_food_name(tempfoodname,foodcode[variety]);
         cout<<tempfoodname<<" has been ordered"<<endl;
         cout<<"Enter the quantity of food  ";
         cin>>quantity[variety];
         fstream writee("data.txt",ios::out|ios::app);
        // writee.write(reinterpret_cast<char*>(date),sizeof(date));
         writee.write(reinterpret_cast<char*>(&table_no),sizeof(table_no));
         writee.write(reinterpret_cast<char*>(&foodcode[variety]),sizeof(foodcode[variety]));
         writee.write(reinterpret_cast<char*>(&quantity[variety]),sizeof(quantity[variety]));
         writee.close();
         cout<<"DO you want to order more[y/n]   ";
         cin>>choice;
         cout<<endl;
         if(choice=='y'||'Y')
                  variety++;
         }
}




void Table::displaytable()
{
         cout<<setw(20)<<"FOOD"<<setw(12)<<"QUANTITY"<<setw(8)<<"PRICE"<<endl;
         for(int i=0;i<variety;i++)
         {
                  global->return_food_name(tempfoodname,foodcode[i]);
                  tempfoodprice=(quantity[i])*global->return_food_price(foodcode[i]);
                  cout<<setw(20)<< tempfoodname <<setw(12)<<quantity[i]<<setw(4)<<"Rs"<<setw(4)<<tempfoodprice<<endl;
                  totalprice+=tempfoodprice;
         }
         cout<<"The total price is "<<totalprice<<endl;
        getche();

}
char Table::ispacked()
{
         char yes='y';
         char no='n';
         if(packed==1)
                  return(yes);
         else
                  return(no);

}
void Table::cleartable()
{
         packed=0;
         variety=0;
         delete[]foodcode;
         delete[]quantity;
         delete[]tempfoodname;

}



/*void Table::times(char date[])
      {
         time_t now=time(0);
          date=ctime(&now);
          //cout<<date;
          //getche();
      }*/
