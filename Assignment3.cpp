#include <iostream>      //declaring libaries
using namespace std;     //declaring namespaces

                                 //declaring procedures
int agereq();                                 //so age can be inputted for calculations
float weightreq();                            //so weight can be inputted for the bmr calculation
float heightreq();                            // so height can be inputted down to the decimal points for the bmr calculation
float activitychoice(int bmr,char activity);  //used in calorie calculation later
char activlvl();                              // so we can ask the user how much exercise they do and have it returned to main and brought to activity choice.
char helpcheck();                            // so users can use up the help screens
int endut=1;                                 //global variable for loop

int main()
{                                             //declaring variables
char gender;                                  //used for choosing male or female in the main
int age;                                      //used for calling agereq which affects calculations
float weight;                                 //used for calling weightreq which affects calculations
float height;                                 //used for calling heightreq which affects calculations                               
int bmr;                                      // used for giving the bmr calculator a variable identifier so it works.                    
char help;                                     // used in calling up the help menu

 
while (endut==1)                             //everlasting loop until you close the program
                                          
{
cout<<"Welcome to the calorie calculator"<<endl; //intro to the program
help=helpcheck();                               // calling the help menu can now press h to activate it


cout<<"Please enter Gender M/F"<<endl;
cin>>gender;

    if (gender == 'M' || gender== 'm')           //if statements using letters inputted m and f to identify to male and female genders 
    {
          cout<<"you are male"<<endl;

          age = agereq();                            //calling the choices from age height and weight 
          weight = weightreq();
          height = heightreq();

          bmr = 66 + (13.7*weight) + (5*height) - (6.8*age);          // calculations for working out bmr using previously aquired data
          cout<<"Your bmr is "<<bmr<<endl;                   // used for telling the user thier bmr
          system ("pause");                            //pausing so that the user has time to view thier bmr
}
    else if (gender == 'F' || gender== 'f')   // for comments here use the same as whats in male
    {
          cout<<"you are female"<<endl;

          age = agereq();
          weight = weightreq();
          height = heightreq();

          bmr = 655 + (9.6*weight) + (1.8*height) - (4.7*age);
          cout<<"Your bmr is "<<bmr<<endl;
          system ("pause");
}
else
{
	cout<<"Input invalid"<<endl;      // so if the user inputs anything but m or f it will display this
	main ();
}


char output=activlvl();                //calling your choice for the amount of activity youve done 
float result = activitychoice(bmr, output);  //calling the procedure for doing final calculation 
system ("cls");                              //clears the system so that after it loops to the start previous data is deleted
}


}

char helpcheck()
{
	char hic;               
cout<<"For help please enter the letter H"<<endl;
cout<<"If you do not require help please press any other character"<<endl;
cin>>hic;                              //allows the user to input data
if (hic =='h' || hic == 'H')           // so if h is pressed helpbox's  are displayed
{
system("start D:/College/proceduralprogramming/Assignment3/Help");     //uses the file in this directory to show help boxes
}
else if (hic == 'q' || hic == 'Q')     //gives the user the option to exit the program by pressing q
{
	endut = 0;         //ends the loop
}
return hic;         // returns users choice to main
}

char activlvl()
{
	char output1;

	cout<<"What is your activity level?"<<endl;                   // activity level choice for calculations displays
	cout<<"Press S for Sedentary (little or no exercise, desk job)"<<endl;
	cout<<"Press L for Lightly active (light exercise/sports 1-3 days/wk)"<<endl;
	cout<<"Press M forMod. active (moderate exercise/sports 3-5 days/wk)"<<endl;
	cout<<"Press V for Very active (hard exercise/sports 6-7 days/wk)"<<endl;
	cout<<"Press E for Extra active(hard daily exercise/sports & physical job or 2 x day training, i.e marathon, contest etc.)"<<endl;
	cin>> output1;        // user can input choice now
	return output1;       //returns choice to main for final calculation
}

int agereq()
{                           //functions for age ,height,weight for calculations, which asks for their details then allow users to input them and return the results
int age;
cout<<"How old are you in years?"<<endl;
cin>>age;
return age;
}

float weightreq()
{
float weight;
cout<<"How much do you weigh in kg?"<<endl;
cin>>weight;
return weight;
}

float heightreq()
{
float height;
cout<<"What is your height in cm?"<<endl;
cin>>height;
return height;
}

float activitychoice(int bmr,char activity) 
{
	int calorificneeds;     // function for the calculation to have something to adress the number to
	char output1;    //allows choice from activlvl to be used
	

switch (activity){                                    //doing the calculations for the activity levels
case 's' :calorificneeds = bmr * 1.2; ;       //it timeses the result that you got from bmr by a number and assignes it to the calorific needs variable
case 'S' :calorificneeds = bmr * 1.2 ;
break;                                      // breaking it off after your choice to save resources
case 'l' :calorificneeds = bmr * 1.375 ;
case 'L' :calorificneeds = bmr * 1.375 ;
break;
case 'm' :calorificneeds = bmr * 1.55 ;
case'M' :calorificneeds = bmr * 1.55 ;
break;
case 'v' :calorificneeds = bmr * 1.725 ;
case 'V' :calorificneeds = bmr * 1.725 ;
break ;
case 'e' :calorificneeds = bmr * 1.9 ;
case 'E' :calorificneeds = bmr * 1.9 ;
break;
}
         

cout<<"Your daily calorific needs are"<<endl;
cout << calorificneeds;       // displays your result from the above calculation
system ("pause");

return calorificneeds;               //sends the result back to main allowing the program to loop back to the start.
}