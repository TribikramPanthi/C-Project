#include <iostream>
#include "hotel.h"
#include "table.h"
#include "GLOBAL.h"
#include <stdlib.h>
#include <fstream>
#include <conio.h>
#include <iomanip>
using namespace std;

void Hotel::readtotaltable()
{
         ifstream tablefile("tablefile.txt",ios::in);
        // tablefile.open("tablefile.txt",ios::in);
         tablefile>>total_table;
         if(tablefile.fail())
         {
                  system("cls");
                  cout<<"OWNER MUST SET TOTAL TABLE FIRST"<<endl;
                  getche();
         }
         else
                  tablefile>>total_table;
         tablefile.close();
}

char Hotel::checkreadoftable()
{
         char yes='y';
         char no='n';
         if(total_table==0)
         return yes;
         else
         return no;
}

void Hotel::settotaltable()
{
         cout<<"ENTER THE TOTAL TABLE ";
         int temp;
         cin>>temp;
         total_table=temp;
          ofstream file("tablefile.txt",ios::out);
          file<<total_table;
          cout<<"TABLE ARE SET TO "<<total_table;
          getche();
          file.close();
}
void Hotel::settable()
{
         for(int i=1;i<=total_table;i++)
         {
                  table[i].settableno(i);
         }
}



Hotel::Hotel()
{
         total_table=10;
         table=new Table[total_table];
         for(int i=1;i<=total_table;i++)
         {
                  table[i].settableno(i);
         }
}


Hotel::~Hotel()
{
         delete[]table;
}


void Hotel::take_order()
{
         system("cls");
         global->display();
         cout<<"Enter the table no  ";
         int temp;
         cin>>temp;
         if(temp<total_table)
         {
         char choice=table[temp].ispacked();
         if(choice=='y')
         {
                  cout<<"Sorry the table is packed!!!Choose another  table:"<<endl;
                  getche();
                  take_order();
                  cout<<"THE ORDER IS SUCCESS"<<endl;
                  getche();
         }
         else
             {
                  table[temp].takeorder();
                  cout<<"THE ORDER IS SUCCESS"<<endl;
                  getche();
             }
         }
         else
         {
                   cout<<"Table number out of range";
                   getche();
         }
}


void Hotel::display()
{
         system("cls");
         cout<<"Enter the table no"<<endl;
         int temp;
         cin>>temp;
         if(temp<total_table)
         {
                char choice=table[temp].ispacked();
                if(choice=='y')
                   {
                  table[temp].displaytable();
                   }
                else{
                  cout<<"Sorry the table is empty"<<endl;
                  getche();
                  }
         }
         else
         {
                  cout<<"Table numher out of range";
                  getche();
         }





}


void Hotel::cleartable()
{
         cout<<"Enter the table no. "<<endl;
         int temp;
         cin>>temp;
         if(temp<total_table)
         {
             char choice=table[temp].ispacked();
             if(choice=='y')
                 {
                  cout<<"The data in table"<<temp<<"are"<<endl;
                   display(temp);
                  cout<<"Do you really want to clear the table[y/n]"<<endl;
                  char temp1;
                  cin>>temp1;
                  if(temp1=='y'||'Y')
                        {
                          table[temp].cleartable();
                          cout<<"The table is now cleared";
                          getche();
                        }

                  else
                        {
                           cout<<"The data are still on table "<<temp;
                           getche();
                        }

                 }
              else
              {
                       cout<<"The table is empty"<<endl;
                       getche();
              }

         }
         else
         {
                  cout<<"Table number out of range";
                  getche();
         }


}


void Hotel::display(int x)
{
         table[x].displaytable();
}


void Hotel :: displayall()
{
         //  char dates[30];
           system("cls");
           fstream readd;
           int temptable,tempcode;
           int tempquantity,tempfoodprice=0;
           char tempfoodname[20];
           int totalprice=0;
           readd.open("data.txt",ios::in);
           cout<<setw(6)<<"TABLE"<<setw(6)<<"CODE"<<setw(16)<<"FOOD"<<setw(10)<<"QUANTITY"<<setw(8)<<"PRICE"<<endl;
            readd.seekg(0,ios::beg);
           while(readd)
             {
               //   readd.read(reinterpret_cast<char*>(dates),sizeof(dates));
                  readd.read(reinterpret_cast<char*>(&temptable),sizeof(temptable));
                  readd.read(reinterpret_cast<char*>(&tempcode),sizeof(tempcode));
                  readd.read(reinterpret_cast<char*>(&tempquantity),sizeof(tempquantity));
                  global->return_food_name(tempfoodname,tempcode);
                  tempfoodprice=tempquantity*global->return_food_price(tempcode);
                  if(tempcode!=0)
                  cout<<setw(6)<<temptable<<setw(6)<<tempcode<<setw(16)<<tempfoodname<<setw(10)<<tempquantity<<setw(8)<<"Rs."<<setw(6)<<tempfoodprice<<endl;
                  totalprice+=tempfoodprice;
                  tempcode=0;
            }
         readd.close();
         cout<<endl<<"TOTAL PRICE= "<<totalprice;
         getche();

}


void Hotel::displaypackedtable()
{
         int free[total_table];
          int j=0;
         for(int i=0;i<total_table;i++)
         {
                  char choice;
                  choice=table[i].ispacked();
                  if(choice=='y')
                  {

                           free[j]=i;
                           j++;

                  }
         }
         cout<<"The packed table are"<<endl;
         for(int i=0;i<j;i++){
                  cout<<free[i]<<endl;
         }
         getche();

}


void Hotel::cleardata()
{
         cout<<"ARE YOU SURE [y/n] ";
         char choice;
         cin>>choice;
         if(choice=='y'||'Y'){
          {fstream writee ("data.txt",ios::out|ios::trunc);
           cout<<"ALL DATA ARE SUCCESSFULLY DELETER"<<endl;
            writee.close();
          }
        getche();
         }

}



void Hotel::displayalltabledatatostaff()
{
         system("cls");
         for(int i=0;i<total_table;i++)
         {
                  if(table[i].ispacked()=='y')
                  {
                           cout<<"TABLE "<<i<<endl;
                           table[i].displaytable();
                           cout<<endl<<endl;
                  }

         }
         getche();
}
