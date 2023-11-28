#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#define TL 218
#define TR 191
#define TC 194
#define CL 195
#define CC 197
#define CR 180
#define BL 192
#define BC 193
#define BR 217
#define HL 196
#define VL 179
#define Xval 42
#define Yval 8
void create_row1(){
	printf("%c",TL);
	for(int itr=1;itr<35;itr++){
		if(itr%5==0){
			printf("%c",TC);
		}
		else{
			printf("%c",HL);
		}
	}
	printf("%c",TR);
}
void create_even_row(){
	for(int itr=0;itr<36;itr++){
		if(itr%5==0){
			printf("%c",VL);
		}
		else{
			printf("%c",' ');
		}
	}
}
void create_odd_row(){
	printf("%c",CL);
	for(int itr=1;itr<35;itr++){
		if(itr%5==0){
			printf("%c",CC);
		}
		else{
			printf("%c",HL);
		}
	}
	printf("%c",CR);
}
void create_row15(){
	printf("%c",BL);
	for(int itr=1;itr<35;itr++){
		if(itr%5==0){
			printf("%c",BC);
		}
		else{
			printf("%c",HL);
		}
	}
	printf("%c",BR);
}
void create_table(){
	gotoxy(Xval,Yval+1);
	create_row1();
	printf("\n");
	for(int row=2;row<=14;row++){
		gotoxy(Xval,Yval+row);
		if(row%2==0){
			create_even_row();
		}
		else{
			create_odd_row();
		}
		printf("\n");
	}
	gotoxy(Xval,Yval+15);
	create_row15();
}

void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void display_day_name(){
	char* day_name[] = {"SU","MO","TU","WE","TH","FR","SA"};
	int width = 5;
	gotoxy(Xval+2,Yval+2);
	int temp_Xval = Xval+2;
	int temp_Yval = Yval+2;
	printf("%s",day_name[0]);
	for(int day_name_ind=1;day_name_ind<7;day_name_ind++){
		temp_Xval += width;
		gotoxy(temp_Xval,temp_Yval);
		printf("%s",day_name[day_name_ind]);
	}
}
void display_date(int year,int month){
	int no_days = number_of_days_in_month(month);
	if(month==2 && is_leap_year(year)){
		no_days +=1;
	}
	//year = year%400;
	int odd_days = odd_days_in_previous_month(month) + odd_days_in_previous_year(year);
	odd_days++;
	odd_days %= 7;
	
	//printf("%d",odd_days);
	int date_val =1;
	int temp_Xval=Xval+2;
	int temp_Yval=Yval+4;
	temp_Xval = temp_Xval + (odd_days*5);
	gotoxy(temp_Xval,temp_Yval);
	printf("%02d",date_val++);
	
	for(;date_val<=no_days;date_val++){
		temp_Xval = temp_Xval + 5;
		if(temp_Xval>78){
			temp_Xval = Xval+2;
			temp_Yval +=2;
		}
		gotoxy(temp_Xval,temp_Yval);
		printf("%02d",date_val);
	} 
}
int is_leap_year(int year){
	if(year%100!=0 && year%4==0 || year%400==0){
		return 1;
	}
	return 0;
}
int odd_days_in_previous_year(int year){
	int odd_days=0;
	for(int y=1;y<year;y++){
		if(is_leap_year(y)){
			odd_days+=2;
		}
		else{
			odd_days+=1;
		}
	}
	return odd_days;
}
int odd_days_in_previous_month(int month){
	int nod_month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	int odd_days=0;
	for(int m=1;m<month;m++){
		odd_days += nod_month[m];
	}
	return odd_days;
}
int number_of_days_in_month(int month){
	int nod_month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	return nod_month[month];
}
void create_input_box(){
	int temp_Xval=Xval;
	int temp_Yval=Yval-6;
	//row 1
	gotoxy(temp_Xval,temp_Yval);
	printf("%c",TL);
	for(int itr=2;itr<36;itr++){
		printf("%c",HL);
	}
	printf("%c",TR);
	//row 2
	temp_Yval++;
	gotoxy(temp_Xval,temp_Yval);
	printf("%c",VL);
	for(int itr=2;itr<36;itr++){
		printf("%c",' ');
	}
	printf("%c",VL);
	//row 3
	temp_Yval++;
	gotoxy(temp_Xval,temp_Yval);
	printf("%c",VL);
	for(int itr=2;itr<36;itr++){
		printf("%c",' ');
	}
	printf("%c",VL);
	//row 4
	temp_Yval++;
	gotoxy(temp_Xval,temp_Yval);
	printf("%c",BL);
	for(int itr=2;itr<36;itr++){
		printf("%c",HL);
	}
	printf("%c",BR);
}

int main(){
	int year;
	int month;
	create_input_box();
	gotoxy(Xval+7,Yval-5);
	printf("Enter the Year :");
	scanf("%d",&year);
	gotoxy(Xval+7,Yval-4);
	printf("Enter the Month : ");
	scanf("%d",&month) ;
	create_table();
	display_day_name();
	display_date(year,month);
	gotoxy(Xval,Yval+17);
	//printf("\n\n\n\n");
	return 0;

}