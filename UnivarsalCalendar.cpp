
#include <iostream>
#include <iomanip>

int getFirstDayofYear(int year) {
    int day = (year * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400) % 7;
    return day;
}

int main() {
    int year;
    const char *month[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int DayM[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int tday;
    int wd = 0;
    int sp = 0;

    std::cout << "##Enter a year that you want to see the calendar##\n";
    std::cin >> year;

    std::cout << "****************************welcome to " << year << "****************************\n\n";

    // Leap year check
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        DayM[1] = 29;
    }

    wd = getFirstDayofYear(year);

    for (int i = 0; i < 12; i++) {
        std::cout << "\n-----------------------------[" << month[i] << "]-----------------------------\n";
        std::cout << "\n    Sun    Mon    Tue    Wed    Thu    Fri    Sat\n\n";

        for (sp = 1; sp <= wd; sp++) {
            std::cout << std::setw(7) << " ";
        }

        tday = DayM[i];
        for (int j = 1; j <= tday; j++) {
            std::cout << std::setw(7) << j;
            wd++;
            if (wd > 6) {
                std::cout << "\n";
                wd = 0;
            }
        }
    }

    return 0;
}
