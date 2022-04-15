#ifndef DOCTOR_H
#define DOCTOR_H


class doctor
{
    public:
        doctor();
        void display_doctor();

    public:
         char first_name[50], last_name[50];
        char specialty[50];
        int phone;
		char availability[10];
};

#endif // DOCTOR_H
