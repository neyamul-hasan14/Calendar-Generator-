import java.util.Scanner;

public class UnivarsalCalendar {

    static int getFirstDayofYear(int year) {
        return (year * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400) % 7;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter a year that you want to see the calendar:");
        int year = scanner.nextInt();

        System.out.println("**************************** Welcome to " + year + " ****************************\n");

        int[] DayM = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int tday;
        int wd = 0;
        int sp;

        // Leap year check
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            DayM[1] = 29;
        }

        wd = getFirstDayofYear(year);

        String[] month = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

        for (int i = 0; i < 12; i++) {
            System.out.println("\n-----------------------------[" + month[i] + "]-----------------------------\n");
            System.out.println("\n    Sun    Mon    Tue    Wed    Thu    Fri    Sat\n");

            for (sp = 1; sp <= wd; sp++) {
                System.out.print("       ");
            }

            tday = DayM[i];
            for (int j = 1; j <= tday; j++) {
                System.out.printf("%7d", j);
                wd++;
                if (wd > 6) {
                    System.out.println();
                    wd = 0;
                }
            }
        }

        scanner.close();
    }
}
