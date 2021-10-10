
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <iomanip>

using namespace std;
int main() {
    FILE *fp, *ft;
    char another, choice;

struct student {
        char first_name[50], last_name[50];
        char gender[2];
        char blood[4];
        int phone,age;
    };

    struct student e;
    char xfirst_name[50], xlast_name[50];
    long int recsize;

    fp=fopen("users.txt","rb+");

    if (fp == NULL) {
        fp = fopen("users.txt","wb+");

        if (fp==NULL)
        {
             puts("Cannot open file");
             return 0;
        }
    }


 recsize = sizeof(e);

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
     cout << "\n \t\t\t 5. Exit Program";
     cout << "\n\n";
     cout << "\t\t\t Select Your Choice : ";
     fflush(stdin);
     choice = getche();
     switch(choice)
     {
      case '1' :
            fseek(fp,0,SEEK_END);
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
                fwrite(&e,recsize,1,fp);
                cout << "\n Add Another Patient (Y/N) ";
                fflush(stdin);
                another = getchar();
            }
            break;
   case '2':
            system("cls");
           rewind(fp);
           cout << "=== View the Patients in the Database ===";
           cout << "\n";
           while (fread(&e,recsize,1,fp) == 1){
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

            rewind(fp);
            while (fread(&e,recsize,1,fp) == 1)
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
                fseek(fp, - recsize, SEEK_CUR);
                fwrite(&e,recsize,1,fp);
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

              ft = fopen("temp.dat", "wb");

              rewind(fp);
              while (fread (&e, recsize,1,fp) == 1)

                 if (strcmp(e.last_name,xlast_name) != 0)
                {
                    fwrite(&e,recsize,1,ft);
                }
                fclose(fp);
                fclose(ft);
                remove("users.txt");
                rename("temp.dat","users.txt");

                fp=fopen("users.txt","rb+");

                cout << "\n Delete Another Patient (Y/N) ";
                fflush(stdin);
                another = getchar();
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
