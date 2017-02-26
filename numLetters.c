#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int retVal = 0;

void onesPlace(int num);
void teens(int num);
void twentyPlus(int num);
void hunPlace(int num);
void thousPlace(int num);
void tenThousPlace(int num);
void hunThousPlace(int num);
void milPlace(int num);
void tenMilPlace(int num);
void hunMilPlace(int num);

int main(int argc, char** argv)
{
    int arg = atoi(argv[1]);   
    
    if(arg == 0)
    {
        retVal = 4;
    } 
    else if(arg > 0 && arg <= 10)
    {
        onesPlace(arg);
    }
    else if(arg > 10 && arg < 20)
    {
        teens(arg);        
    }
    else if(arg >= 20 && arg < 100)
    {
        twentyPlus(arg);
    }
    else if(arg >= 100 && arg < 1000)
    {
        hunPlace(arg);        
    }
    else if(arg >= 1000 && arg < 10000)
    {
        thousPlace(arg);
    }
    else if(arg >= 10000 && arg < 100000)
    {
        tenThousPlace(arg);
    }
    else if(arg >= 100000 && arg < 1000000)
    {
        hunThousPlace(arg);
    }
    else if(arg >= 1000000 && arg < 10000000)
    {
        milPlace(arg);
    }
    else if(arg >= 10000000 && arg < 100000000)
    {
        tenMilPlace(arg);
    }
    else if(arg >= 100000000 && arg < 1000000000)
    {
        hunMilPlace(arg);
    }
    else if(arg == 1000000000)
    {
        retVal = 10;
    } 
    else
    {
        printf("Invalid number given");
        return -1;
    }

    printf("%d takes %d letters \n", arg, retVal);
    return 0;
}

void hunMilPlace(int num)
{
    onesPlace(num/100000000); //get hunMilPlace and get count of that num
    if(num/100000000 != 0) { retVal += 7; } //hundred if hunMil place not 0
    if((num/100000000 != 0 && num%100000000)/10000000 == 0 && (num%100000000)/1000000 == 0)
    {
        retVal += 7; //million if hunMilPlace filled but tenMilPlace and milPlace both 0
    }
    tenMilPlace(num%100000000); //send all nums after hunMilPlace
}

void tenMilPlace(int num)
{
    if(num/10000000 == 1) //check if tenMilPlace is a teen
    {   
        teens(num/1000000); //send teens the tenMil + mil place
        retVal += 7; //million because milPlace will be skipped
        hunThousPlace(num%1000000); //send all nums after milPlace
    }
    else //if its 0 or not a teen
    {
        twentyPlus((num/10000000)*10); //send tenMilPlace + 0 (ex 20)
        milPlace(num%10000000); //send all nums after tenMilPlace
    }

}

void milPlace(int num)
{
    onesPlace(num/1000000); //get milPlace and get count of that num
    if(num/1000000 != 0) { retVal += 7; } //million
    hunThousPlace(num%1000000); //send all nums after milPlace
}

void hunThousPlace(int num)
{
    onesPlace(num/100000); //get hunThous place and get count of that num
    if(num/100000 != 0) { retVal += 7; } //hundred if hunThous place not 0
    if(num/100000 != 0 && (num%100000)/10000 == 0 && (num%100000)/1000 == 0)
    {
        retVal += 8; //thousand if hunThouPlace filled but tenThousPlace/thousPlace both 0
    }
    tenThousPlace(num%100000); //send all nums after hunThous place
}

void tenThousPlace(int num)
{
    if(num/10000 == 1) //check if tenThousPlace is a teen
    {
        teens(num/1000); //send teens the tenThous + thous place
        retVal += 8; //thousand because thousPlace will be skipped
        hunPlace(num%1000); //send all nums after thousPlace
    }
    else
    {
        twentyPlus((num/10000)*10); //send tenThousPlace + 0 (ex 30)
        thousPlace(num%10000); //send all nums after tenThousPlace
    }
}

void thousPlace(int num)
{
    onesPlace(num/1000); //get thous place and get count of that num
    if(num/1000 != 0) { retVal += 8; } //thousand
    hunPlace(num%1000);
}

void hunPlace(int num)
{
    onesPlace(num/100); //just a number comes before 'hundred'
    if(num/100 != 0) { retVal += 7; } //'hundred' is 7 letters long
    if((num%100)/10 == 0) 
    {
        onesPlace(num%10); 
    }
    else if((num%100)/10 == 1) { teens(num); }
    else { twentyPlus(num%100); }
}

void twentyPlus(int num)
{
    int tens = num/10;
    switch(tens)
    {
        case 4: case 5: case 6:
            retVal += 5;
            break;
        case 2: case 3: case 8: case 9:
            retVal += 6;
            break;
        case 7:
            retVal += 7;
            break;
    }
    onesPlace(num%10);
}

void teens(int num)
{
    int ones = num%10;
    switch(ones)
    {
        case 0:
            retVal += 3; //ten
            break;
        case 1: case 2:
            retVal += 6;
            break;
        case 5: case 6:
            retVal += 7;
            break;
        case 3: case 4: case 8: case 9:
            retVal += 8;
            break;
        case 7:
            retVal += 9;
            break;
    }      
}

void onesPlace(int num)
{
    switch(num)
    {
        case 1: case 2: case 6: 
            retVal += 3;
            break;
        case 4: case 5: case 9:
            retVal += 4;
            break;
        case 3: case 7: case 8:
            retVal += 5;
            break;
    } 
}
