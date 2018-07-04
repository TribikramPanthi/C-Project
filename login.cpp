#include "login.h"
#include<iostream>
#include<string>
#include<conio.h>
#include<windows.h>
#include <stdlib.h>
using namespace std;

         Password::Password()
         {
                  hotelname=" ";
                  owner_username=" ";
                  owner_password=" ";
                  staff_username=" ";
                  staff_password=" ";
                  owner_password2=" ";
                  staff_password2=" ";

         }




         void Password:: registeration()
         {
                  int registerchoice;
                  system("cls");
                  cout<<"HOTEL REGISTERATION"<<endl;
                  cin.ignore();
                  cout<<"ENTER THE NAME OF YOUR HOTEL"<<endl;
                  getline(cin,hotelname);//
                   //cin.ignore();
                  cout<<"ENTER USERNAME OF OWNER"<<endl;

                   getline(cin,owner_username);
                   system("cls");
                   cout<<"HOTELNAME:"<<hotelname<<endl<<"USERNAME:  "<<owner_username<<endl<<"PRESS 1 TO CONFIRM NAME OF YOUR HOTEL AND YOUR USERNAME!!! ";
                  cin>>registerchoice;
                  cin.ignore();
                  if(registerchoice!=1)
                  {
                          system("cls");
                          registeration();

                  }
                  else{
                           ownerpasswordregister();

                           }

         }
         void Password::ownerpasswordregister()
         {

                  int ownerchoice;
                  cout<<"ENTER YOUR PASSWORD"<<endl;
                 //
                  getline(cin,owner_password);
                  cout<<"CONFIRM YOUR PASSWORD"<<endl;
                 // ins.ignore();
                   getline(cin,owner_password2);
                  // cin.ignore();
                   if(owner_password!=owner_password2)
                   {
                            cout<<"PASSWORD DIDN'T MATCH  TRY AGAIN"<<endl;
                            system("cls");
                            cout<<"REENTER YOUR PASSWORD"<<endl;
                            ownerpasswordregister();

                   }
                   else
                     {
                          system("cls");
                     cout<<"DO YOU WANT TO REGISTER YOUR STAFF???"<<endl<<"PRESS 1 TO REIGSTER   ";
                      cin>>ownerchoice;
                     }
                     // cin.ignore();
                      if(ownerchoice==1)
                         staffregisteration();
                         else
                         {
                                  system("cls");
                                  cout<<"REISTERATION IS SUCCESSFUL"<<endl<<"PRESS ANY KEY TO CONTINUE";
                                 getche();
                         }

         }
         void Password::staffregisteration()
         {
                   cin.ignore();
                  cout<<"ENTER HIS USERNAME"<<endl;
                   getline(cin,staff_username);
                   cout<<"ENTER HIS PASSWORD"<<endl;
                    getline(cin,staff_password);
                    cout<<"CONFIRM HIS PASSWORD"<<endl;
                    getline(cin,staff_password2);
                    cin.ignore();
                    if(staff_password!=staff_password2)
                    {
                             cout<<"WRONG PASSWORD  TRY AGING"<<endl;
                             system("cls");
                             staffregisteration();
                    }
                    else
                    {
                             system("cls");
                           cout<<"REISTERATION COMPLETES"<<endl<<"PRESS ANY KEY TO CONTINUE";
                           getche();
                    }


         }
    void Password::encrypt(string &original)
         {

                  for(int i=0;i<original.size();i++)
                           original[i]=~original[i];
         }

    void Password::decrypt(string &encrypt)
         {

                  for(int i=0;i<encrypt.size();i++)
                          encrypt[i]=~encrypt[i];
         }

     void Password::encrypteddata()
         {

                  encrypt(hotelname) ;
                  encrypt(owner_username);
                  encrypt(owner_password);
                  encrypt(owner_password2);
                  encrypt(staff_username);
                  encrypt(staff_password);

         }
    void Password::decrypteddata()
         {
             decrypt(hotelname);
             decrypt(owner_username);
             decrypt(owner_password);
             decrypt(owner_password2);
             decrypt(staff_username);
             decrypt(staff_password);
             decrypt(staff_password2);
         }

   void Password::output(ostream& outs)
         {
           if(outs==cout)
           cout<<"HOTEL NAME="<<hotelname<<endl<<"OWNER USERNMAE="<<owner_username<<endl<<"OWNER PASSWORD="<<owner_password<<endl<<"STAFF USERNAME="<<staff_username<<endl<<"STAFF PASSWORD="<<staff_password<<endl;

           else
            {
             encrypteddata();
            outs<<hotelname<<endl<<owner_username<<endl<<owner_password<<endl<<owner_password2<<endl<<staff_username<<endl<<staff_password<<endl<<staff_password2<<endl;
            }

}

    void Password::input(istream& ins)
           {
            if(ins==cin)
              {
                 registeration();
              }
           else
              {
                   getline(ins,hotelname);
                   getline(ins,owner_username);
                   getline(ins,owner_password);
                   getline(ins,owner_password2);
                   getline(ins,staff_username);
                   getline(ins,staff_password);
                   getline(ins,staff_password2);
                   decrypteddata();
             }
          }


std::ostream& operator <<(std::ostream& outs,Password &temp)
     {
         temp.output(outs);
         return(outs);
     }
std::istream& operator >>(std::istream& ins, Password &temp)
     {
         temp.input(ins);
         return (ins);
     }

