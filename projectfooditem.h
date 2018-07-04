#ifndef PROJECTFOODITEM_H
#define PROJECTFOODITEM_H
#include <string>

using namespace std;

class Fooditem
{
private:
          char foodname[20];
         int price;
         int foodcode;
         int quantity;

public:
         Fooditem();
         Fooditem(char foodnames, float prices, int foodcodes);
          void operator =(Fooditem &other);
      //  std::string get_food() return foodname;
        // float get_price() return price;
        // int get_foodcode() return foodcode;
         void output(std::ostream & outs);
         void input (std::istream & ins);
     //    void foutput(std::ostream & outs);
      //   void finput (std::istream & ins);
         friend class Database;


};
std::ostream & operator <<(std::ostream& outs,Fooditem &temp);
std::istream & operator >>(std::istream& ins, Fooditem &temp);



#endif // FOODITEM_H
