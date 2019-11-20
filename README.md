# C++Project
This project is uploaded to github two years later
It is a hotel management system implemented in C++ without gui
It actually has two previliage one for the owner and other for the staff.
The user can register his company, owner username and password, staff username and password
Three text files are used to store data. Password.txt store username and password in encrypted form.
I used very simply encryption algorithm.
table.txt file consists of list of all available tables.(total tables)
foodlist.txt file consists of all available foodlist on the given day
data.txt file consists of all the transaction (total sales made , total price of food ordered in a given table). It actually show the detail of food ordered and total price.
It also faciliate to clear the data on the given table once the customer leaves the hotel so that the table will be available for new costumer. The simple UI also shows the reserved table.


.h files are the header for the corresponding .c files
projectdatabase.c is a database to manage all the food items.
table.c manages the tables
global.h files makes projectdatabase file golbal to all other class.
projectfooditem.c contains class to structure different aspect of food items.
main.c file combines all other file to build a project
