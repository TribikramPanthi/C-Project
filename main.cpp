#include "projectdatabase.h"
#include "login.h"
#include "projectdatabase.h"
#include "hotel.h"
#include "table.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include "GLOBAL.h"
#include <stdlib.h>
#include <fstream>
#include <iomanip>
int menu();
int admin_menu();
int change_registeration_data();
using namespace std;
 Database *global=new Database;

int main()
{
           Fooditem fooditem;
           Table table;
           Hotel hotel;

           Password passwords;
           string username,password;
           system("cls");
           ifstream read;//stream to read password and username
           read.open("password.txt");
           if(!read.fail())
            {
                  read>>passwords;
                  cout<<passwords<<endl;
                  read.close();

                  string hotelname=passwords.gethotelname();
                  string staff_username=passwords.getstaff_username();//LOAD username and database on ram
                  string staff_password=passwords.getstaff_password();
                  string owner_username=passwords.getowner_username();
                  string owner_password=passwords.getowner_password();



                              cout<<"WELCOME TO HOTEL  "<<hotelname<<endl<<"ENTER YOUR USERNAME"<<endl;
                              getline(cin,username);
                              cout<<"ENTER YOUR PASSAWORD"<<endl;
                              getline(cin,password);
                              if(!(username==staff_username&&password==staff_password)&&!(username==owner_username&&password==owner_password))//if user is illegal
                              cout<<"WRONG ENTRY";


                if((username==owner_username&& password==owner_password )|| (username==staff_username&&password==staff_password))//if user is legal

                   {
                            password=" ";//clear user entered password during login
                            username=" ";
                          ifstream finn("foodlist.txt");
                          if(!finn.fail())
                             {
                                global->load(finn);//load data form file on ram
                                finn.close();
                               hotel.readtotaltable();//read total table if is set
                               hotel.settable();
                                int choice=0;
                                while(choice!=7)
                                           {

                                            //cout<<endl;
                                      choice=menu();//main window
                                      switch(choice)
                                           {
                                              case 1:
                                                {
                                                             //  char temp=hotel.checkreadoftable();
                                                        /* if(temp!='y'||'Y')
                                                         {
                                                                  cout<<"TOTAL TABLE NOT SET";
                                                                  getche();
                                                                  exit(1);
                                                         }*/
                                                         hotel.take_order();
                                                         break;
                                                }
                                              case 2:
                                                 {
                                                         /*  if(hotel.checkreadoftable()=='y'||'Y')
                                                         {
                                                                  cout<<"TOTAL TABLE NOT SET";
                                                                  getche();
                                                                  exit(1);
                                                         }*/
                                                          hotel.displaypackedtable();
                                                          break;
                                                 }
                                              case 3:
                                                 {
                                                          /* if(hotel.checkreadoftable()=='y'||'Y')
                                                         {
                                                                  cout<<"TOTAL TABLE NOT SET";
                                                                  getche();
                                                                  exit(1);
                                                         }*/
                                                          hotel.display();
                                                          break;
                                                 }
                                              case 4:
                                                 {
                                                           /*if(hotel.checkreadoftable()=='y'||'Y')
                                                         {
                                                                  cout<<"TOTAL TABLE NOT SET";
                                                                  getche();
                                                                  exit(1);
                                                         }*/
                                                          hotel.cleartable();
                                                          break;

                                                  }
                                              case 5:
                                                      {/*
                                                                if(hotel.checkreadoftable()=='y'||'Y')
                                                                   {
                                                                  cout<<"TOTAL TABLE NOT SET";
                                                                  getche();
                                                                  exit(1);
                                                                   }*/
                                                               hotel.displayalltabledatatostaff();
                                                               break;

                                                      }

                                              case 6://open as owner
                                                   {
                                                      cin.ignore();
                                                      cout<<"PLEASE ENTER YOUR USERNAME"<<endl;
                                                      getline(cin,username);
                                                      cout<<"PLEASE ENTER YOUR PASSWORD"<<endl;
                                                      getline(cin,password);
                                                      if(username==owner_username&&password==owner_password)//make sure only owner could enter into the system
                                                      {
                                                      int admin_choice=0;
                                                      while(admin_choice!=8)
                                                          {
                                                              admin_choice=admin_menu();
                                                              switch(admin_choice)
                                                                       {
                                                                          case 1:
                                                                              {
                                                                                 system("cls");
                                                                                 global->display();
                                                                                 cin>>fooditem;//read food object from keyboard
                                                                                 global->add(fooditem);//add data to database
                                                                                 break;
                                                                              }
                                                                           case 2:
                                                                              {
                                                                                  system("cls");
                                                                                  global->display();
                                                                                  global->edit();//edit fooditem on database
                                                                                  break;
                                                                              }
                                                                           case 3:
                                                                              {
                                                                                  int codes;
                                                                                  system("cls");
                                                                                  global->display();
                                                                                  cout<<"ENTER THE CODE OF FOOD ITEM YOU WANT TO DELETE ";
                                                                                  cin>>codes;
                                                                                  global->deletefood(codes);
                                                                                   break;
                                                                              }
                                                                           case 4:
                                                                              {
                                                                                      system("cls");
                                                                                      hotel.displayall();
                                                                                      getche();

                                                                                    break;
                                                                              }
                                                                           case 5://CHAGNGING REGISTERATION DATA
                                                                                 {
                                                                                       int choose=0;
                                                                                       while(choose!=7)
                                                                                        {
                                                                                        choose=change_registeration_data();
                                                                                        switch(choose)
                                                                                         {
                                                                                         case 1:
                                                                                                 {
                                                                                                          cin.ignore();
                                                                                                        string temp;
                                                                                                        system("cls");
                                                                                                        cout<<"ENTER NEW HOTEL NAME"<<endl;
                                                                                                        getline(cin,temp);
                                                                                                        passwords.set_hotel_name(temp);
                                                                                                        cout<<"HOTEL NAME CHANGED"<<endl;
                                                                                                        getche();
                                                                                                        break;
                                                                                                  }
                                                                                         case 2:
                                                                                                  {
                                                                                                           cin.ignore();
                                                                                                           system("cls");
                                                                                                           cout<<"ENTER YOUR NEW USERNAME"<<endl;
                                                                                                           string temp;
                                                                                                           getline(cin,temp);
                                                                                                                    passwords.set_owner_username(temp);
                                                                                                                    cout<<"YOUR USERNAME CHANGED"<<endl;
                                                                                                                    getche();
                                                                                                                    break;

                                                                                                  }
                                                                                         case 3:
                                                                                                  {
                                                                                                           cin.ignore();
                                                                                                           system("cls");
                                                                                                           cout<<"ENTER YOUR NEW PASSWORD"<<endl;
                                                                                                           string temp;
                                                                                                           getline(cin,temp);
                                                                                                           passwords.set_owner_password(temp);
                                                                                                           cout<<"YOUR PASSWORD CHANGED"<<endl;
                                                                                                           getche();
                                                                                                           break;

                                                                                                  }
                                                                                         case 4:
                                                                                                  {
                                                                                                           cin.ignore();
                                                                                                           system("cls");
                                                                                                           cout<<"ENTER NEW USERNAME OF YOUR STAFF"<<endl;
                                                                                                           string temp;
                                                                                                           getline(cin,temp);
                                                                                                           passwords.set_staff_username(temp);
                                                                                                           cout<<"STAFF'S USERNAME CHANGED"<<endl;
                                                                                                           getche();
                                                                                                           break;
                                                                                                  }
                                                                                         case 5:
                                                                                                  {
                                                                                                           cin.ignore();
                                                                                                           system("cls");
                                                                                                           cout<<"ENTER NEW PASSWORD OF YOUR STAFF"<<endl;
                                                                                                           string temp;
                                                                                                           getline(cin,temp);
                                                                                                           passwords.set_staff_password(temp);
                                                                                                           cout<<"STAFF'S PASSWORD CHANGED"<<endl;
                                                                                                           getche();
                                                                                                           break;
                                                                                                  }
                                                                                         case 6:
                                                                                                  {
                                                                                                           hotel.settotaltable();
                                                                                                           break;
                                                                                                  }
                                                                                         case 7:
                                                                                                 {
                                                                                                   cout<<"WELCOME"<<endl;
                                                                                                   getche();
                                                                                                   break;

                                                                                                 }
                                                                                         default:
                                                                                                   {
                                                                                                            cout<<"WRONG CHOICE"<<endl;
                                                                                                            getche();
                                                                                                            break;
                                                                                                   }

                                                                                         }//end of registeration switch

                                                                                       }//end of registeration while loop

                                                                                       ofstream passwordfile;//write changed username and password to file
                                                                                       passwordfile.open("password.txt");
                                                                                       passwordfile<<passwords;
                                                                                       passwordfile.close();
                                                                                 }
                                                                        case 6:
                                                                                 {
                                                                                          hotel.cleardata();
                                                                                          break;
                                                                                 }
                                                                        case 7:
                                                                                 {
                                                                                          hotel.settotaltable();
                                                                                          break;
                                                                                 }



                                                                           case 8:
                                                                                 {
                                                                                    cout<<"BOSS KEEP UPLOADING DATA......";
                                                                                    break;
                                                                                 }
                                                                           default:
                                                                               {
                                                                                     cout<<"WRONG ENTRY!!!"<<endl<<"TRY AGAIN"<<endl;
                                                                                     getche();
                                                                                     break;
                                                                               }
                                                                         }//end to owner switch
                                                              }//end of owner while loop

                                                           ofstream out;//write fooditem to the database
                                                           out.open("foodlist.txt");
                                                           global->save(out);
                                                           if(out.fail())
                                                              {
                                                                cout<<"COULDN'T WRITE TO FILE"<<endl;
                                                               }
                                                           out.close();


                                                        }
                                                      else//if owner is fake owner
                                                               cout<<"YOU HAVEN'T ACCESS TO THIS PART";
                                                }

                                            case 7:
                                                {
                                                  cout<<"You are terminating.......";
                                                   getche();
                                                   break;
                                                 }
                                            default:
                                                 {
                                                   cout<<"INVALID ENTRY"<<endl;
                                                   cout<<"TRY AGAIN"<<endl;
                                                   getche();
                                                   break;
                                                 }



                                          }//end of main switch
                                  }//end of main while

                           }//end of file if read

                        else
                            {
                             cout<<"THE file doesn't exist . Creating new file"<<endl;//if foodlist database file is not created or accidentally deleted
                             ofstream newfile("foodlist.txt");
                             newfile.close();
                             main();
}

                  }//end of if entry is allowed

         }//end of password file if read

             else//if hotel is not registered
               {
                    int mainchoice;
                    cout<<"YOU ARE NOT REGISTERED."<<endl<<"PRESS 1 TO REGISTER YOUR COMPANY   ";
                    cin>>mainchoice;
                    cout<<endl;
                    if(mainchoice==1)
                           {
                       cin>>passwords;
                       ofstream file;
                       file.open("password.txt");
                       file<<passwords;
                       file.close();
                       main();}
                     else
                        {
                         cout<<"IT'S OK. YOU CAN REGISTER NEXT TIME";
                         getche();
                    }
               }

  }



int menu()//main window
 {
         system("cls");
         global->display();
         cout<<endl<<endl;
         int choice;
         cout<<endl<<"1. TAKE ORDER"<<endl;
         cout<<"2. DISPLAY PACKED TABLE NUMBER"<<endl;
         cout<<"3. SEE  PARTICULAT TABLE"<<endl;
         cout<<"4. CLEAR TABLE"<<endl;
         cout<<"5. DISPLAY ALL TABLE DATA"<<endl;
         cout<<"6. OPEN AS ADMIN"<<endl;
         cout<<"7. QUIT"<<endl;
         cin>>choice;
         return choice;

 }

int admin_menu()//owner general window
{
         system("cls");
         global->display();
         cout<<endl<<endl;
         int select;
         cout<<endl<<"1. ADD NEW FOOD ITEM"<<endl;
         cout<<"2. EDIT EXISTING ITEM"<<endl;
         cout<<"3. DELETE ITEM"<<endl;
         cout<<"4. DISPLAY ALL TRNASACTION"<<endl;
         cout<<"5. CHANGE THE REGISTERATION"<<endl;
         cout<<"6. CLEAR ALL DATA"<<endl;
         cout<<"7. SET TOTAL TABLE"<<endl;
         cout<<"8. EXIT"<<endl;
         cin>>select;
         return select;
}
int change_registeration_data()//registeration data modification window
{
         system("cls");
         int choicess;
         cout<<"1. CHANGE HOTEL NAME"<<endl;
         cout<<"2. CHANGE YOUR USERNAME"<<endl;
         cout<<"3. CHANGE YOUR PASSWORD"<<endl;
         cout<<"4. CHANGE YOUR STAFF USERNAME"<<endl;
         cout<<"5. CHANGE YOUR STAFF PASSWORD"<<endl;
         cout<<"6. SET TOTAL TABLE"<<endl;
         cout<<"7. EXIT"<<endl;
         cin>>choicess;
         return choicess;

}

