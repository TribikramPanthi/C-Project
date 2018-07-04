#include "projectdatabase.h"
#include "projectfooditem.h"
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <windows.h>
#include <iomanip>
#include <fstream>

using namespace std;
   Database::Database()
      {
         capacity=5;
         used=0;
         food=new Fooditem[capacity];
      }
Database::Database(const Database& other)
{
	used = other.used;
	capacity = other.capacity;
	food = new Fooditem[capacity];
	copy(other.food,other.food+used,food);
}

void Database::operator=(const Database &other)
      {
         capacity=other.capacity;
         used=other.used;
         food=new Fooditem[capacity];
         copy(other.food,other.food+used,food);

      }


Database::~Database()
      {
         delete[]food;
      }

void Database::return_food_name(char tempfoodname[],int x)
       {
               // string temp;
                for(int i=0;i<used;i++)
                {
                         if(food[i].foodcode==x)
                         {
                                  strcpy(tempfoodname,food[i].foodname);
                         }
                }

       }
int Database:: return_food_price(int x)
         {
                  int temp;
                  for(int i=0;i<used;i++)
                  {
                           if(food[i].foodcode==x)
                           {
                                    temp=food[i].price;
                                    return temp;
                                    break;
                           }

                  }
         }


void Database::make_bigger()
      {
         Fooditem *temp;
         temp=new Fooditem[capacity+5];
         copy(food,food+used,temp);
         delete[]food;
         food=temp;
         capacity+=5;
      }


    void Database::add( Fooditem &foods)
      {
         if(used>=capacity)
                  make_bigger();

         food[used]=foods;
         used++;
      }


    void Database::deletefood(int code)
      {
         int foodfound=0;
         for(int i=0;i<used;i++)
             {
                  if(food[i].foodcode==code)
                  {
                           cout<<food[i]<<endl<<"DO YOU REALLY WANT TO DELETE ITEM[Y/N]";

                           char deletes;
                           cin>>deletes;
                           if(deletes=='y'||'Y')
                             {
                                    food[i]=food[used-1];
                                    foodfound=1;
                                    used--;
                             }
                  }
             }
         if(foodfound==1)
                  cout<<"DELETED SUCCESSFULLY";
         if(foodfound==0);
         cout<<"THE FOOD DOESN'T EXIST";

      }


    void Database::edit()
      {
         int code;
         int found=0;
         cout<<"Enter the code of food you want to edit.";
         cin>>code;
         for(int i=0;i<used;i++)
             {
                  if(food[i].foodcode==code)
                  {
                           Fooditem temp;
                           cout<<"Your current data is"<<endl;
                           cout<<food[i];
                             cout<<"Enter the new data"<<endl;
                             cin>>temp;
                             food[i]=temp;
                             found=1;
                  }
             }
         if(found==0)
                  cout<<"Couldn't find the data";
      }


    void Database::display()

      {
         cout<<setw(2)<<"CODE"<<setw(18)<<"FOOD"<<setw(8)<<"PRICE"<<endl;
         for(int i=0;i<used;i++)
            {

                  cout<<food[i];
            }
      }


    void Database::save(ostream &outs)
      {

         for(int i=0;i<used;i++)
            {
                  outs<<food[i];

            }

      }


    void Database::load(istream &ins)
      {
                ins.seekg(0,ios::beg);
         Fooditem foods;
      while(ins>>foods)

             {

                  if(used>=capacity)
                           make_bigger();

                  food[used]=foods;
                   ++used;

             }

      }
