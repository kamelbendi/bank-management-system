Project Report 
Deadline of the exercise : 31st of January 2022. 

Name and Surname : 
	Kamel Bendimerad. 

















Project’s topic : Bank management system with a trading and a savings account.



Task Topic :
The idea behind this project was to create a bank management system that will give the user the ability to log in and register for three different account types, using a graphical user interface made from the Qt open source library . 

Project analysis :
Data structures used in the project :
In the bank class there was a preference of choosing a map, the keys being the account username and referring to account objects which are pointers since it is a better approach towards accessing child classes, and according to my research, probably the only way possible.
Stocks are in the form of a data structure in order to unite all the available stocks with the same set of variables. (Share, stock symbol..)
All of the account informations are stored in a file, instead of a database, in order to integrate the use of the streams which was a new concept for students from this semester.

Algorithms which are used to solve the problem :
For this project we only used an algorithm to log in which had some level of complexity to come up with since it needed the polymorphism integration.
Log in Algorithm : 
Scans through the Bank’s file and checks the account type of this user and therefore open the exact window in order to access the account’s functionalities in its window.


External specification : (user’s manual) :
With this program, each user can create an account in this Bank by registering and providing the necessary data, and specifying the account type they wish to create. (accessible after clicking on the register and create an account button).







      



After registering, each account has to login to their specific windows, so they need to sign up using the login dialog, with the same password they used while registering.














After that, for the Normal account, only simple functionalities are present in their interfaces, each normal account window will present to the user their username, balance, the transfer option and the ability to log out from the window.  


For the savings and salary account, each user will have the ability to control his financial situation, after they earn their salary, taking a margin from their balance to the savings balance and take away their monthly expanses, they can know which is the final balance that they can currently use :




And for the investment account we have the following :

You can buy stocks, which their share values are being randomized according to the time, and sell them afterwards.


Internal specification : 
(function headers and what do the functions do, and how they should be used, list of parameters and their roles, results)
In the Bank class we have two main functionalities :


1) update stock function : 




2) saving all the accounts from a file :

3) in the mainWindow 

Testing :
Concerning the memory leaks, since we are using the IDE from the QT library where it is easier to manage both your designs and code, we have the ability to test our memory leaks without the need of external libraries.
After getting the coding done, we tested all the possibilities from our program : 

Topics :
The topics from the laboratories which are used in this program are :
streams : (to read and write the accounts which are present in the bank, or the ones which are being created)
Exceptions : handling the cases where :  -the username wants to create an account with an already existing username, - the user has not filled all the data for the of successful creation of the account, or for example when a user wants to buy a number of shares of a stock, but doesn’t has sufficient balance to do so, and so on.




Inheritance : Both the investment account and the saving account are inherited from the class NormalAccount, we used this concept since all of the account have similar core structure and functionalities.
Polymorphism : in order to show the correct window after log in, polymorphism was used in order to return the correct data type of the account from one single virtual function “getAccount”


As you can see after checking the results of each account type, a new QMainWindow object (w) will be created, pointing at the correct account window, and it is getting executed after we get the correct account type from the user.


Conclusions :

Learning to code such program, will give any programmer a good understanding of the Qt library and how it can be used for different graphical user interfaces development while enforcing their knowledge in c++. 
Qt is one of the libraries which are the most used for graphical user interface programming, since it is well documented and easy to install and run on every platform, which was not the case with my recent trial with wxWidgets.
This program can be used to simplify the way a modern bank may handle their data to run their institution, and give an understanding on how buying and selling stock markets work.

References used in order to achieve this project :
Lectures slides from our course.
cplusplus.com 
geekforgeek.com
doc.qt.io
stackoverflow.com
Qt YouTube channel for design tips and code integration.


