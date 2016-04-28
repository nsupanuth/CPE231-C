//
//  main.c
//  Calender
//
//  Created by NUTH on 4/21/2559 BE.
//  Copyright © 2559 NUTHYLL. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rd = 1;
int rm = 1;
int ry = 1;


int DayInMonthIs(int month, int year) {
    
    int dayInMonth;
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 0) {
        dayInMonth = 31;
    } else if (month == 2) {
        
        if (year % 4 == 0 && month%100!=0) {
            if(year%100==0 && year%400!=0)
                dayInMonth=28;
            else
                dayInMonth = 29;
        } else {
            dayInMonth = 28;
        }
        
    } else {
        dayInMonth = 30;
    }
    
    return dayInMonth;
}

int  checkDistance(int dd, int mm, int yy) {
    
    int distance = 0;
    int total = 0;
    
    if (mm == rm && yy == ry) {
        distance = dd - rd;
    } else if (yy >= ry) {
        
        int diffYear = yy - ry;
        int plusYear = ry;
        
        for (int i = rm; i < mm + (12 * diffYear); i++) {
            total += DayInMonthIs((i % 12), plusYear);
            
            if (i % 12 == 0) {
                plusYear++;
            }
            
        }
        
        distance = total + dd+rd;
        
    }
    
    int modValue = distance % 7;
    return modValue;
    
}

int Validate(int dd,int mm,int yy){
    
    if (dd > DayInMonthIs(mm%12, yy) || dd < 1 || mm<1 || mm>12 || yy<1)
        return 0;
    else {
        
        return 1;
    }
    
}


int main(int argc, const char * argv[]) {
    
    while (1) {
    
    int dd=0,mm=0,yy=0;
    
    printf("Input Date(dd/mm/yy) : ");
    scanf("%d/%d/%d",&dd,&mm,&yy);
   
    if (Validate(dd, mm, yy)==1) {
        int result = checkDistance(dd, mm, yy);
        switch (result) {
            case 0: printf("Saturday"); break;
            case 1: printf("Sunday"); break;
            case 2: printf("Monday"); break;
            case 3: printf("Tuesday"); break;
            case 4: printf("Wednesday"); break;
            case 5: printf("Thursday"); break;
            case 6: printf("Friday"); break;
            default:  break;
        }
    }else{
        printf("Invaid date,month or year!!!");
    }
    
    printf("\n\n");
    
    }
    

}







