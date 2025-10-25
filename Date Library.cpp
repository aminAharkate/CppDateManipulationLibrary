#include <iostream>
#include "clsDate.h"

using namespace std;

int main()
{
    cout << "=== Date Manipulation Examples ===" << endl << endl;

    // 1. Create different date objects
    cout << "1. Creating Date Objects:" << endl;
    clsDate currentDate; // Default constructor (system date)
    clsDate customDate(15, 8, 2023); // Day, Month, Year
    clsDate stringDate("25/12/2023"); // From string
    clsDate dayOrderDate(100, 2023); // 100th day of 2023

    cout << "Current System Date: ";
    currentDate.Print();

    cout << "Custom Date (15/8/2023): ";
    customDate.Print();

    cout << "String Date (25/12/2023): ";
    stringDate.Print();

    cout << "100th day of 2023: ";
    dayOrderDate.Print();
    cout << endl;

    // 2. Date validation
    cout << "2. Date Validation:" << endl;
    clsDate invalidDate(31, 2, 2023); // Invalid date
    cout << "Is 31/2/2023 valid? " << (invalidDate.IsValid() ? "Yes" : "No") << endl;
    cout << "Is 15/8/2023 valid? " << (customDate.IsValid() ? "Yes" : "No") << endl;
    cout << endl;

    // 3. Date calculations
    cout << "3. Date Calculations:" << endl;
    cout << "Is 2023 leap year? " << (customDate.isLeapYear() ? "Yes" : "No") << endl;
    cout << "Days in February 2023: " << clsDate::NumberOfDaysInAMonth(2, 2023) << endl;
    cout << "Day of week for 15/8/2023: " << customDate.DayShortName() << endl;
    cout << endl;

    // 4. Increase/Decrease dates
    cout << "4. Date Manipulation:" << endl;

    clsDate testDate(1, 1, 2023);
    cout << "Original Date: ";
    testDate.Print();

    // Increase by 10 days
    testDate.IncreaseDateByXDays(10);
    cout << "After adding 10 days: ";
    testDate.Print();

    // Increase by 2 months
    testDate.IncreaseDateByXMonths(2);
    cout << "After adding 2 months: ";
    testDate.Print();

    // Increase by 1 year
    testDate.IncreaseDateByOneYear();
    cout << "After adding 1 year: ";
    testDate.Print();

    // Decrease by 5 days
    testDate.DecreaseDateByXDays(5);
    cout << "After subtracting 5 days: ";
    testDate.Print();
    cout << endl;

    // 5. Date difference
    cout << "5. Date Difference:" << endl;
    clsDate date1(1, 1, 2023);
    clsDate date2(1, 6, 2023);

    cout << "Date 1: ";
    date1.Print();
    cout << "Date 2: ";
    date2.Print();

    int diffDays = date1.GetDifferenceInDays(date2);
    cout << "Difference in days: " << diffDays << " days" << endl;
    cout << endl;

    // 6. Calendar display
    cout << "6. Calendar Display:" << endl;
    cout << "August 2023 calendar:" << endl;
    clsDate::PrintMonthCalendar(8, 2023);
    cout << endl;

    // 7. Business days and vacation calculation
    cout << "7. Business Days Calculation:" << endl;
    clsDate startDate(1, 8, 2023);
    clsDate endDate(31, 8, 2023);

    int businessDays = clsDate::CalculateBusinessDays(startDate, endDate);
    cout << "Business days between ";
    startDate.Print();
    cout << " and ";
    endDate.Print();
    cout << ": " << businessDays << " business days" << endl;

    // Vacation calculation
    clsDate vacationStart(1, 8, 2023);
    short vacationDays = 10;
    clsDate returnDate = clsDate::CalculateVacationReturnDate(vacationStart, vacationDays);

    cout << "Vacation starts: ";
    vacationStart.Print();
    cout << "Vacation days: " << vacationDays << endl;
    cout << "Return date: ";
    returnDate.Print();
    cout << endl;

    // 8. Date comparison
    cout << "8. Date Comparison:" << endl;
    clsDate compDate1(1, 1, 2023);
    clsDate compDate2(15, 1, 2023);
    clsDate compDate3(1, 1, 2023);

    cout << "Date1: ";
    compDate1.Print();
    cout << "Date2: ";
    compDate2.Print();
    cout << "Date3: ";
    compDate3.Print();

    cout << "Date1 vs Date2: ";
    switch (compDate1.CompareDates(compDate2)) {
    case clsDate::Before: cout << "Date1 is before Date2" << endl; break;
    case clsDate::After: cout << "Date1 is after Date2" << endl; break;
    case clsDate::Equal: cout << "Dates are equal" << endl; break;
    }

    cout << "Date1 vs Date3: ";
    switch (compDate1.CompareDates(compDate3)) {
    case clsDate::Before: cout << "Date1 is before Date3" << endl; break;
    case clsDate::After: cout << "Date1 is after Date3" << endl; break;
    case clsDate::Equal: cout << "Dates are equal" << endl; break;
    }
    cout << endl;

    // 9. Days until end of period
    cout << "9. Days Until End of Period:" << endl;
    clsDate sampleDate(15, 8, 2023);
    cout << "Sample date: ";
    sampleDate.Print();
    cout << "Days until end of week: " << sampleDate.DaysUntilTheEndOfWeek() << endl;
    cout << "Days until end of month: " << sampleDate.DaysUntilTheEndOfMonth() << endl;
    cout << "Days until end of year: " << sampleDate.DaysUntilTheEndOfYear() << endl;
    cout << endl;

    // 10. Age calculation
    cout << "10. Age Calculation:" << endl;
    clsDate birthDate(15, 5, 1990);
    int ageInDays = clsDate::CalculateMyAgeInDays(birthDate);
    cout << "Birth date: ";
    birthDate.Print();
    cout << "Current date: ";
    currentDate.Print();
    cout << "Age in days: " << ageInDays << " days" << endl;
    cout << "That's approximately " << ageInDays / 365 << " years!" << endl;

    return 0;
}

