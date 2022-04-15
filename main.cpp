
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <iomanip>

#include <windows.h>
#include <mysql.h>

#include "patient.h"
#include "doctor.h"
#include <string>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;


// --------------- Affect Specialty to Doctor on CSV file ----------------

void create(char* first_name, char* last_name, char* d_specialty)
{
	// file pointer
	fstream fout;

	// opens an existing csv file or creates a new file.
	fout.open(d_specialty, ios::out | ios::app);


		// Insert the data to file
		fout << first_name << " "
			<< last_name << " "
			<< "\n";
fout.close();
	}






// ------------------ Display Available Doctor for each Specialty ---------------------

void read_record(char* medical_field)
{

	 ifstream fin;
    string line;
    // Open an existing file
    fin.open(medical_field);
     while(!fin.eof()){

                fin>>line;
            cout<<line;



            }





}





// ------------------- Set & Display Appointments  ---------------- --


int bookAppointment()
{
    system("cls");

     cout << "\t\t================================\n";
     cout << "\t\t======  Set Appointment   ======\n";
     cout << "\t\t================================\n\n\n";
                cout << "   1 - Pediatrician \n";
                cout << "   2 - Neurologist \n";
                cout << "   3 - Gynecologist \n";
                cout << "   4 - Cardiologist \n\n";
                fflush(stdin);
                char medical_field_choice = getche();
                char* medical_field;
                switch(medical_field_choice)
                {
                    case '1' :  {
                                    medical_field = "Pediatrician";
                                    break;
                                }
                    case '2' :  {
                                    medical_field = "Neurologist";
                                    break;
                                }
                    case '3' :  {
                                    medical_field = "Gynecologist";
                                    break;
                                }
                    case '4' :  {
                                    medical_field = "Cardiologist";
                                    break;
                                }
                }



    cout<<"\n ----- Book Your Appointment ---- \n";
    cout<<"\n ----- Availbale slots ---- \n";

    //check if record already exist..
    ifstream read;
    read.open(medical_field);

    int hoursbook = 8;

    int arr[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
    int recordFound =0;

    if(read)
    {
	string line;
	char key = 'A';
	int i = 9;

	while(getline(read, line)) {
	char temp = line[0];
	int index = (temp - 65);
	arr[index]=1;
	recordFound = 1;
	}
	if(recordFound == 1)
	{
	cout<<"\n Appointment Summary by hours:";
	char key = 'A';
	int hours = 9;
	for(int i = 0; i<=12; i++)
	{
	if(i == 0){
	if(arr[i] == 0)
	cout<<"\n "<<key<<"-> 0"<<hours<<" - Available";
	else
	cout<<"\n "<<key<<"-> 0"<<hours<<" - Booked";
	}

	else
	{
	if(arr[i] == 0)
	cout<<"\n "<<key<<"->"<<hours<<" - Available";
	else
	cout<<"\n "<<key<<"->"<<hours<<" - Booked";
	}
	hours++; key++;
	}

	}

	read.close();
    }
	if(recordFound == 0){
	cout<<"\n Appointment Available for following hours :";
	char key = 'A';
	for(int i = 9; i<=21; i++)
	{
		if(i==9)
		cout<<"\n "<<key<<" -> 0"<<i<<" - Available";
		else
		cout<<"\n "<<key<<" -> "<<i<<" - Available";
		key++;
	}

	}

   char choice;
   cout<<"\n\n Input your choice : ";
   cin>>choice;

   if( !(choice >= 'A' && choice <='Z'))
   {
	cout<<"\n Error : Invalid Selection";
	cout<<"\n Please selction correct value from menu A- Z";
	cout<<"\n Press any key to continue";
	getchar();getchar();
	system("cls");
	bookAppointment();
   }

   int index = (choice-65 );
   int isBooked = 1;
   if(arr[index] == 0)
      isBooked = 0;

   if(isBooked ==1)
   {
   	cout<<"\n Error : Appointment is already booked for this Hour";
   	cout<<"\n Please select different time !!";
   	cout<<"\n Press any key to continue!!";
   	getchar();getchar();
   	system("cls");
   	bookAppointment();
   }


   ofstream out;
   out.open(medical_field, ios::app);

   if(out){
	   out<<choice<<"\n";
       //out<<choice<<":"<<name.c_str()<<"\n";
	   out.close();
	   cout<<"\n Appointment booked for Hours : "<< (choice-65) + 9 <<" successfully !!";
    }
    else
    {
    	cout<<"\n Error while saving booking";
    }

    cout<<"\n Please any key to continue..";
	getchar(); getchar();
	return 0;
}

int existingAppointment()
{
    system("cls");
    cout<<"\n ----- Appointments Summary ---- \n";
    //check if record already exist..
    ifstream read;
    read.open("appointment.dat");

    int hoursbook = 8;

    int arr[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
     int recordFound =0;

    if(read)
    {
	string line;
	char key = 'A';
	int i = 9;

	   while(getline(read, line)) {
	   	   char temp = line[0];
	   	   int index = (temp - 65);
	   	   arr[index]=1;
		   recordFound = 1;
	  }
        if(recordFound == 1)
        {
        cout<<"\n Appointment Summary by hours:";
        char key = 'A';
        int hours = 9;
        for(int i = 0; i<=12; i++)
        {
        	if(arr[i] == 0)
        	cout<<"\n "<<key<<"->"<<hours<<" - Available";
        	else
        	cout<<"\n "<<key<<"->"<<hours<<" - Booked";
        	hours++; key++;
        }

	}

	read.close();
    }
    else
    {
    char key = 'A';
	for(int i = 9; i<=21; i++)
	{
	if(i==9)
	cout<<"\n "<<key<<" -> 0"<<i<<" - Available";
	else
	cout<<"\n "<<key<<" -> "<<i<<" - Available";
	key++;
	}
    }

    cout<<"\n Please any key to continue..";
    getchar(); getchar();
    return 0;
}





















// ----------------------------------- MAIN PROGRAM ------------------------------

int main() {
// MySQL CONNECTION

  MYSQL* conn;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "192.168.100.2", "admin", "admin", "", 0, NULL, 0);
    if(conn){
        cout<<"connected"<<endl;
    }
    else{
        cout<<"Not connected"<<endl;
    }

            //    mysql_query(conn, "INSERT INTO patients VALUES (  '1', 'John', 'Kennedy' ,'m','a', '04234234','20')");


FILE *fp_users, *ft_users , *fp, *ft;
    char another,another_doc, choice,medical_field_choice , doctor_speciality_choice;


    patient e;
    char xfirst_name[50], xlast_name[50];
    long int recsize;





    fp_users=fopen("patients.csv","rb+");

    if (fp_users == NULL) {
        fp_users = fopen("patients.csv","wb+");

        if (fp_users==NULL)
        {
             puts("Cannot open file");
             return 0;
        }
    }


    doctor d;
    char xdfirst_name[50], xdlast_name[50];
    long int drecsize;

    fp=fopen("doctors.csv","rb+");

    if (fp == NULL) {
        fp = fopen("doctors.csv","wb+");

        if (fp==NULL)
        {
             puts("Cannot open file");
             return 0;
        }
    }








 recsize = sizeof(e);
 drecsize = sizeof(d);



 while(1) {
     system("cls");

     cout << "\t\t=========================================\n";
     cout << "\t\t====== Hostpital Management System ======\n";
     cout << "\t\t=========================================";




     cout <<"\n\n                                          ";
     cout << "\n\n";
     cout << "\n \t\t\t 1. Add Patient";
     cout << "\n \t\t\t 2. List Of Patients";
     cout << "\n \t\t\t 3. Modify Patient";
     cout << "\n \t\t\t 4. Delete Patient";
     cout << "\n\n";

     cout << "\n \t\t\t 6. Add Doctor";
	 cout << "\n \t\t\t 7. List Of Doctors";
     cout << "\n \t\t\t 8. Modify Doctor";
     cout << "\n \t\t\t 9. Delete Doctor";

     cout << "\n\n";
     cout << "\n\n";
     cout << "\n \t\t\t 5. Exit Program";
     cout << "\n\n";
     cout << "\t\t\t Select Your Choice : ";
     fflush(stdin);
     choice = getche();
     switch(choice)
     {
        case 'a' : bookAppointment(); break;
      case '1' :
            fseek(fp_users,0,SEEK_END);
            another ='Y';
            while(another == 'Y' || another == 'y')
            {
                  system("cls");
                cout << "Enter the Firt Name : ";
                cin >> e.first_name;
                cout << "Enter the Last Name : ";
                cin >> e.last_name;
                cout << "Gender(m/f) : ";
                cin >> e.gender;
                cout << "Blood Type : ";
                cin >> e.blood;
                cout << "Age : ";
                cin >> e.age;
                cout << "Phone Number : ";
                cin >> e.phone;

               /* ICI PASTE */

                bookAppointment();


                fwrite(&e,recsize,1,fp_users);
                cout << "\n Add Another Patient (Y/N) ";
                fflush(stdin);
                another = getchar();
            }
            break;
   case '2':

             system("cls");
           rewind(fp_users);
           cout << "=== View the Patients in the Database ===";
           cout << "\n";
           while (fread(&e,recsize,1,fp_users) == 1){
	cout<<"\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
	cout<<"\n   Patient data:\n";
	cout<<"\n   First Name         : "<<e.first_name;
	cout<<"\n   Last Name          : "<<e.last_name;
	cout<<"\n   Gender             : "<<e.gender;
	cout<<"\n   Age                : "<<e.age;
	cout<<"\n   Blood Group        : "<<e.blood;
	cout<<"\n   Mobile Number      : "<<e.phone;
	cout<<"\n\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
           }
           cout << "\n\n";
           system("pause");
           break;

   case '3' :
            system("cls");
          another = 'Y';
          while (another == 'Y'|| another == 'y')
          {
              cout << "\n Enter the last name of the patient : ";
              cin >> xlast_name;

            rewind(fp_users);
            while (fread(&e,recsize,1,fp_users) == 1)
            {
                if (strcmp(e.last_name,xlast_name) == 0)
                {
                cout << "Enter Firt Name : ";
                cin >> e.first_name;
                cout << "Enter Last Name : ";
                cin >> e.last_name;
                cout << "Enter Gender    : ";
                cin >> e.gender;
                cout << "Enter Blood Type   : ";
                cin >> e.blood;
                cout << "Enter Age   : ";
                cin >> e.age;
                cout << "Enter Phone   : ";
                cin >> e.phone;
                fseek(fp_users, - recsize, SEEK_CUR);
                fwrite(&e,recsize,1,fp_users);
                break;
                }
                else
                cout<<"patient not found";
            }
            cout << "\n Modify Another Patient (Y/N) ";
                fflush(stdin);
                another = getchar();
            }
            break;


     case '4':
       system("cls");
           another = 'Y';
          while (another == 'Y'|| another == 'y')
          {
              cout << "\n Enter the last name of the patient to delete : ";
              cin >> xlast_name;

              ft_users = fopen("temp.dat", "wb");

              rewind(fp_users);
              while (fread (&e, recsize,1,fp_users) == 1)

                 if (strcmp(e.last_name,xlast_name) != 0)
                {
                    fwrite(&e,recsize,1,ft_users);
                }
                fclose(fp_users);
                fclose(ft_users);
                remove("patients.csv");
                rename("temp.dat","patients.csv");

                fp_users=fopen("patients.csv","rb+");

                cout << "\n Delete Another Patient (Y/N) ";
                fflush(stdin);
                another = getchar();
              }

              break;
	case '6':
           fseek(fp,0,SEEK_END);
            another_doc ='Y';
            while(another_doc == 'Y' || another_doc == 'y')
            {
                  system("cls");
                cout << "Enter the Firt Name : ";
                cin >> d.first_name;
                cout << "Enter the Last Name : ";
                cin >> d.last_name;
                cout << "Specialty : ";
                cout << "         \n ";
                cout << "   1 - Pediatrician ";
                cout << "   2 - Neurologist ";
                cout << "   3 - Gynecologist ";
                cout << "   4 - Cardiologist ";

                doctor_speciality_choice = getch();
                switch(doctor_speciality_choice)
                {
                case '1' :{
                            char* d_specialty = "Pediatrician";
                            create(d.first_name,d.last_name,d_specialty);
                            break;
                            }
                case '2' :{
                            char* d_specialty = "Neurologist";
                            create(d.first_name,d.last_name,d_specialty);
                            break;
                            }
                case '3' :{
                            char* d_specialty = "Gynecologist";
                            create(d.first_name,d.last_name,d_specialty);
                            break;
                            }
                case '4' :{
                            char* d_specialty = "Cardiologist";
                            create(d.first_name,d.last_name,d_specialty);
                            break;
                            }
                }

                cout << "Availability Day/Night : ";
                cin >> d.availability;
                cout << "Phone Number : ";
                cin >> d.phone;
                fwrite(&d,drecsize,1,fp);
                cout << "\n Add Another Doctor (Y/N) ";
                fflush(stdin);
                another_doc = getchar();
            }

	case '7':

            system("cls");
           rewind(fp);
           cout << "=== View the Doctors in the Database ===";
           cout << "\n";
           while (fread(&d,drecsize,1,fp) == 1){
	cout<<"\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
	cout<<"\n   Doctor data:\n";
	cout<<"\n   First Name         : "<<d.first_name;
	cout<<"\n   Last Name          : "<<d.last_name;
	cout<<"\n   Specialty          : "<<d.specialty;
	cout<<"\n   Availability       : "<<d.availability;
	cout<<"\n   Mobile Number      : "<<d.phone;
	cout<<"\n\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
           }
           cout << "\n\n";
           system("pause");
           break;

	case '8':
            system("cls");
          another_doc = 'Y';
          while (another_doc == 'Y'|| another_doc == 'y')
          {
              cout << "\n Enter the last name of the Doctor : ";
              cin >> xdlast_name;

            rewind(fp);
            while (fread(&d,drecsize,1,fp) == 1)
            {
                if (strcmp(d.last_name,xdlast_name) == 0)
                {
                cout << "Enter Firt Name : ";
                cin >> d.first_name;
                cout << "Enter Last Name : ";
                cin >> d.last_name;
                cout << "Enter Specialty    : ";
                cin >> d.specialty;
                cout << "Enter Availability   : ";
                cin >> d.availability;
                cout << "Enter Phone   : ";
                cin >> d.phone;
                fseek(fp, - drecsize, SEEK_CUR);
                fwrite(&d,drecsize,1,fp);
                break;
                }
                else
                cout<<"Doctor not found";
            }
            cout << "\n Modify Another Doctor (Y/N) ";
                fflush(stdin);
                another_doc = getchar();
            }
            break;

	case '9':
       system("cls");
           another_doc = 'Y';
          while (another_doc == 'Y'|| another_doc == 'y')
          {
              cout << "\n Enter the last name of the doctor to delete : ";
              cin >> xdlast_name;

              ft = fopen("temp.dat", "wb");

              rewind(fp);
              while (fread (&d, drecsize,1,fp) == 1)

                 if (strcmp(d.last_name,xdlast_name) != 0)
                {
                    fwrite(&d,drecsize,1,ft);
                }
                fclose(fp);
                fclose(ft);
                remove("doctors.csv");
                rename("temp.dat","doctors.csv");

                fp=fopen("doctors.csv","rb+");

                cout << "\n Delete Another Doctor (Y/N) ";
                fflush(stdin);
                another_doc = getchar();
              }

              break;


	case '5':
              fclose(fp);
              cout << "\n\n";
              cout << "\t\t     THANK YOU FOR USING THIS SOFTWARE";
              cout << "\n\n";
              exit(0);
          }
     }


system("pause");


return 0;
}
