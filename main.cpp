/* Sean Eriksson CSE 110-500 - Lab #3, payroll program

This program computes payroll using hours and pay rate.
Updates to the program include the following:
-The ability to compute the tax withholding amount.  */



#include <iostream>



using namespace std;


double compute_withholding (int dependents, double grossPay);


int main()

{

    int hoursWorked, overtimeHours, overtimeDBLHours, dependents;

    double hourlyRate, basePay, overtimePay, overtimeDBLPay, grossPay, netPay, taxesWithheld;

    cout << "Enter the hourly rate of pay: $";

    cin >> hourlyRate;

    cout << "Enter the number of hours worked, " << endl;

    cout << "rounded to a whole number of hours: ";

    cin >> hoursWorked;

    cout << "Enter the number of dependents you wish to claim: ";

    cin >> dependents;


    if (hoursWorked > 50)  // did the person work more than 50 hours

    {
        overtimeDBLHours = hoursWorked - 50;  //calculate the double overtime hours by subtracting the base and time and half hours

        overtimeHours = 10;  //time and half is always 10 hours if hours worked is greater than 50

        basePay = hourlyRate * 40;  //calculate the base pay

        overtimeDBLPay = overtimeDBLHours * (hourlyRate * 2);  //calculate the double overtime pay by multiplying the hourly rate by 2

        overtimePay = overtimeHours * (hourlyRate * 1.5);  //calculate the overtime pay by multiplying the hourly rate by 1.5

        grossPay = basePay + overtimePay + overtimeDBLPay; //add the base, overtime time and half, and double overtime to calculate the total gross pay

        taxesWithheld = compute_withholding (dependents, grossPay);   //call withholding function

        netPay = grossPay - taxesWithheld;  // calculate the netpay by subtracting the taxes withheld from the gross pay
    }



    else if (hoursWorked > 40)  // did the person work over 40 hours

        {

        overtimeHours = hoursWorked - 40;  //calculate the overtime hours by subtracting the base 40

        basePay = hourlyRate * 40;  //calculate the base pay

        overtimePay = overtimeHours * (hourlyRate * 1.5);  //calculate the overtime pay by multiplying the hourly rate by 1.5

        grossPay = basePay + overtimePay; //add the base and overtime to calculate the total gross pay

        overtimeDBLHours = 0;  //set overtime double hours to zero

        overtimeDBLPay = 0;  //set overtime double pay to zero

        taxesWithheld = compute_withholding (dependents, grossPay);   //call withholding function

        netPay = grossPay - taxesWithheld;  // calculate the netpay by subtracting the taxes withheld from the gross pay

        }



    else

        {

        grossPay = hourlyRate * hoursWorked;  // calculate gross pay

        basePay = grossPay; // no overtime, so they are the same

        overtimeDBLHours = 0;  // set overtime double hours to zero

        overtimeDBLPay = 0;  // set overtime double pay to zero

        overtimeHours = 0;  // set overtime hours to zero

        overtimePay = 0;  // set overtime pay to zero

        taxesWithheld = compute_withholding (dependents, grossPay);  //call withholding function

        netPay = grossPay - taxesWithheld;  // calculate the netpay by subtracting the taxes withheld from the gross pay

        }


    cout.setf(ios::fixed);  // use fixed point

    cout.setf(ios::showpoint);  //display the decimal

    cout.precision(2);  //display two decimal placed



    cout <<"Total Hours Worked = " << hoursWorked << endl;  //print hours worked

    cout <<"Hourly pay rate = $" <<hourlyRate << endl;    //print hourly rate

    cout <<"Base pay = $" <<basePay << endl;          //print base bay

    cout <<"Overtime hours at time and a half = " << overtimeHours << endl;  //print overtime hours at time and a half

    cout <<"Overtime pay at time and a half = $" << overtimePay << endl;  //print overtime hours at time and a half dollar value

    cout <<"Overtime hours at double time = " <<overtimeDBLHours << endl;  //print double overtime hours

    cout <<"Overtime pay at double time = $" <<overtimeDBLPay << endl;  //print over time double pay

    cout <<"Gross pay = $" <<grossPay << endl;        //print gross pay

    cout <<"Tax Withholding Amount = $" <<taxesWithheld << endl; //print withholding amount

    cout <<"Net pay = $" <<netPay << endl; //print net pay



    return 0;

}


double compute_withholding (int dependents, double grossPay)

{
    double taxPercent;

    switch (dependents)    //determine the tax percentage based upon the number of dependents

    {
    case 0: taxPercent = .28;
        break;
    case 1: taxPercent = .20;
        break;
    case 2: taxPercent = .18;
        break;
    case 3: taxPercent = .15;
        break;
    }

    double withholding = grossPay * taxPercent;   //calculate taxes withheld by using the withholding percentage

    return (withholding);  //return withholding amount

}
