#include "projectfooditem.h"
#include <iostream>
#include <windows.h>
#include <iomanip>
#include <fstream>
using namespace std;

Fooditem::Fooditem()
{
         price=0;
         foodcode=0;

}

void Fooditem::output(ostream& outs)
{
         if(outs==cout)
         {

                  outs<<setw(2)<<foodcode<<setw(20)<<foodname<<setw(5)<<"Rs."<<setw(3)<<price<<endl;

         }
         else
         {
         outs.write(reinterpret_cast<char*>(&foodcode),sizeof(foodcode));
         outs.write(reinterpret_cast<char*>(foodname),sizeof(foodname));
         outs.write(reinterpret_cast<char*>(&price),sizeof(price));
         }
}

void Fooditem::input(istream& ins)

{
         if(ins==cin)
         {
                  ins.ignore();
                  cout<<"Enter the name of food item"<<endl;;
                  ins>>foodname;
                  cout<<"Enter the price of food item"<<endl;
                  ins>>price;
                  cout<<"Enter the code of food item"<<endl;;
                  ins>>foodcode;
         }
         else
            {
                   ins.read(reinterpret_cast<char*>(&foodcode),sizeof(foodcode));
                   ins.read(reinterpret_cast<char*>(foodname),sizeof(foodname));
                   ins.read(reinterpret_cast<char*>(&price),sizeof(price));
             }

}

 void Fooditem::operator =( Fooditem &other)
 {
          strcpy(foodname,other.foodname);
          foodcode=other.foodcode;
          price=other.price;
 }
ostream&operator <<(ostream & outs,Fooditem &temp)
  {

         temp.output(outs);

         return(outs);
   }
istream& operator >>(istream& ins, Fooditem &temp)
{
         temp.input(ins);
         return (ins);
}






