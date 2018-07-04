#ifndef PROJECTDATABASE_H
#define PROJECTDATABASE_H
#include "projectfooditem.h"


class Database
{
private:
         int capacity;
         int used;
public:         Fooditem *food;



public:
         Database();
         Database(const Database& other);
         void operator =(const Database &other);
         ~Database();
        // Database(Database & other);
         void make_bigger();
         void add(Fooditem & foods);
         void deletefood(int code);
         void edit();
         void display();
         void save(std::ostream & outs);
         friend class Fooditem;
         friend class Table;
         void load(std::istream & ins);
         void return_food_name(char tempfoodname[],int x);
         int return_food_price(int x);
};
#endif
