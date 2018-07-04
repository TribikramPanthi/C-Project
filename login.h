#ifndef LOGIN_H_INCLUDED
#define LOGIN_H_INCLUDED
#include <string>
#include<iostream>
class Password
{

std::string hotelname;
std::string owner_username;
std::string owner_password;
std::string staff_username;
std::string staff_password;
std::string owner_password2;
std::string staff_password2;


 public:
         Password();
         Password operator =(Password &temp);
         void registeration();
         void ownerpasswordregister();
         void staffregisteration();
         void encrypt(std::string &original);
        void decrypt(std::string &encrypt);
         void encrypteddata();
         void decrypteddata();
         void load(std::istream &ins);
         void save(std::ostream &outs);
         void output(std::ostream & outs);
         void input (std::istream & ins);
         std::string gethotelname() const {return hotelname;}
         std::string getowner_username() const {return owner_username;}
         std::string getowner_password() const {return owner_password;}
         std::string getstaff_username() const {return staff_username;}
         std::string getstaff_password() const {return staff_password;}
         void set_hotel_name(std::string &temps){hotelname=temps;}
         void set_owner_username(std::string &temps){owner_username=temps;}
         void set_owner_password(std::string &temps){owner_password=temps;}
         void set_staff_username(std::string &temps){staff_username=temps;}
         void set_staff_password(std::string &temps){staff_password=temps;}

};
         std::ostream& operator <<(std::ostream & outs, Password &temp);
         std::istream& operator >>(std::istream & ins,  Password &temp);
#endif // LOGIN_H_INCLUDED
