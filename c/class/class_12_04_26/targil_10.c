#include <stdio.h>

int main(void){
    typedef struct person_data{
        unsigned long id;
        double hourly_wage;
        unsigned int working_hours_per_day;
        unsigned int working_days_per_week;
        unsigned int current_year;
        unsigned int start_work_year;
    } person;
    
    person p;  // Declare a variable of type 'person'
    
    printf("Please enter the following data:\n");
    printf("---------------------------------\n");
    printf("Hourly wage:");
    scanf("%lf", &p.hourly_wage);
    printf("Working hours per day:");
    scanf("%u", &p.working_hours_per_day);
    printf("Working days per week:");
    scanf("%u", &p.working_days_per_week);
    printf("Current year:");
    scanf("%u", &p.current_year);
    printf("Start work year:");
    scanf("%u", &p.start_work_year);   
    double compensation_per_month= p.hourly_wage*p.working_hours_per_day*p.working_days_per_week*4; //get monthly compensation
    double compensation_per_years = (p.current_year - p.start_work_year) * compensation_per_month ; //get compensation for years of work
    printf("the compensation for worker:%.2lf\n", compensation_per_years);
    return 0;
}