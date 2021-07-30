#include<stdio.h>

//C project prepared by Ayush Marasini department of electrical and electronics Roll number 43

//declaring a file pointer
FILE *ptr;

void main(){
	
	//declaring three variables for future use
	int i,num,yn;
	
	printf("\n\n\t\t\t**********Welcome to the employee details recorder**********");
	
	printf("\n\n\tPlease enter the number of employees that you want to record the data of : ");
	scanf("%d",&num);
	
	//creating a structure details which consisits of a character-string (char) integer and float with given variables
	struct details{
	char name[10];
	int age;
	float salary;
	}det[num]; //det is the variable used to access details structure

	printf("\n\nEntering the data of %d employees...\n\n\n",num);
	//this loop enters the data in the struct
	for(i=0;i<num;i++){
		printf("\nEnter the name : ");
		scanf("%s",&det[i].name);
		printf("Enter the age : ");
		scanf("%d",&det[i].age);
		printf("Enter the salary : ");
		scanf("%f",&det[i].salary);
	}


	//we open employeedetails.txt file in write mode and store data stored in structure into a file 
	//if a file doesnot exist, new file will be created
	// we can also open the file in read mode and append mode if we desire.
	ptr = fopen("employeedetails.txt","w");	
	
	//this loop enters the data inside the file using fprintf() method.
	for(i=0;i<num;i++){
	fprintf(ptr,"\n%s %d\n%0.2f",det[i].name,det[i].age,det[i].salary);
	}
	fclose(ptr);
	
	
	printf("\n\nPress any key to continue...");
	getch();
	
	system("cls");
	printf("Do you want to see the details?\n 1 for yes/ 0 for no?");
	
	scanf("\n%d",&yn);
	
		if(yn == 1){
					
			system("cls");
			printf("\n\n\tThe details that you have entered are : \n\n");
			ptr = fopen("employeedetails.txt","w");	
					
			for(i=0;i<num;i++){
				fscanf(ptr,"\n%s %d\n%f",&det[i].name,&det[i].age,&det[i].salary);
			}
						
			for(i=0;i<num;i++){
				printf("\n\n Name	:	%s \n Age	:	%d\n Salary	:	%0.2f",det[i].name,det[i].age,det[i].salary);
			}
		}
		
		else if(yn==0){
				printf("Press any key to exit");
			}
					
	}
	
	


