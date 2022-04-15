#ifndef PATIENT_H
#define PATIENT_H


class patient
{
    public:
        patient();
        void display_patient();
    public:
        char first_name[50], last_name[50];
        char gender[2];
        char blood[4];
        char phone[15];
        int age[3];
};

#endif // PATIENT_H
