// employee managment system
#include <iostream>
#include <vector>
#include <map>
#include <deque>
#include <list>
#include <set>
#include <string>
#include <ctime>
#include <numeric>
struct Employee{
    int Employee_ID;
    std::string Employee_Name;
    double Salary;
};
void Employee_Details(const Employee & Emp){
    std::cout<<"Employee id: " << Emp.Employee_ID<<"\n";
    std::cout<<"Employee Name: " << Emp.Employee_Name<<"\n";
    std::cout<<"Employee salary: " << Emp.Salary<<"\n";
}
int main(){
    std::vector<Employee>Employees = {
        {1023 , "Aditya", 50000} , {1043,"Bob",30000} , {2003, "charlie",54302},{8942,"Tim",424114},{5423,"jam",787414}
    };
    std::sort(Employees.begin() , Employees.end() , [](const Employee &e1 , const Employee &e2){
        return e1.Salary > e2.Salary;
    });
    std::cout <<"Employee shorted by their salary \n";
    for_each(Employees.begin(),Employees.end() , Employee_Details);

    std::vector<Employee>high_Earners;
    copy_if(Employees.begin() , Employees.end() , back_inserter(high_Earners),[](const Employee &e){
        return e.Salary > 20000;
        std::cout<<std::endl;
    });
    std::cout <<"High Earners Employees \n";
    for_each(Employees.begin(),Employees.end() , Employee_Details);
    double total_Salary = std::accumulate(Employees.begin() , Employees.end() , 0.0 ,[](double sum , const Employee &e){
        return sum + e.Salary;
    });
    double Avg_Salary = total_Salary / Employees.size();
    std::cout <<"Average salary of Employees :- " << Avg_Salary<<std::endl;
   // for_each(Employees.begin(),Employees.end() , Employee_Details);
    return 0;
}