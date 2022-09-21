/*ΑΓΓΕΛΟΣ ΠΟΥΛΟΣ ΣΑΜΑΡΤΖΗΣ Α.Μ.:2014030028*/
#include <time.h>
#include <stdlib.h.>
#include <stdio.h>
int main()
/*mastermind*/
{   
    int number,secret_number,i,j,flag,help_number,n,h,secret_num,basic,board_guess[6],board[6],guess_number,k,stop,counter,flag1,flag2;
    char answer,board_c_random[6],char_random(),board_c_guess[6],flag_char,answer1;
	printf("welcome to mastermind");
	printf("\nHow many digits do you want to use(3-5)? Or press negative number for end the game:"); 
	scanf("\n%d",&number);                            /*προσδιορισμος του πληθους των ψηφιων του μυστικου αριθμου*/
	while(number>=0&&number<3||number>5){
		printf("please give me a number between 3 an 5:");
		scanf("\n%d",&number);                        /*ελεγχος οτι ο αριθμος ειναι αναμεσα στο τρια και στο 5 ή ειναι αρνητικος.*/
	    }
	if(number>2){
     printf("Do you want to allow duplicate digits(y/n)?");
	 scanf("\n%c",&answer);
	 help_number=pow1(number);                        /*συναρτηση που γυρναει τον βοηθητικο αριθμο για τισ απαιτουμενες πραξεις*/
	  if(answer=='y'){
	 	secret_number=find_number(help_number);       /*συναρτηση που γυρναει εναν τυχαιο αριθμο!*/
	 	for(i=0; i<number; i++){                           
	 	 board[i]=secret_number/help_number;         /*<<σπασιμο>> του μυστικου αριθμου σε ξεριστα ψηφια και εισαγη των ψηφιων αυτων σε πινακα*/
	 	 secret_number=secret_number-board[i]*help_number;
	 	 help_number=help_number/10; 
	     }
	 } else{
	     	do{
	            secret_number=find_number(help_number); /*συναρτηση που γυναει εναν τυχαιο αριθμο!*/
	     		for(h=0; h<number; h++){
	     	        board[h]=secret_number/help_number; /*<<σπασιμο>> του μυστικου αριθμου σε ξεριστα ψηφια και εισαγη των ψηφιων αυτων σε πινακα*/
	     			secret_number=secret_number-board[h]*help_number;
	 	            help_number=help_number/10;      
	     		}
	     		flag=0;
	     		for(i=0; i<(number-1); i++){        
	     			for(j=number; j>i; ){            
	     				if(board[i]==board[j]){      /*ελεγχος ωστε αμα ο τυχαιος αριθμος εχει ομοια ψηφια,*/
	     					flag=1;                  /*να κανει το flag 1 */
	     				}
	     				j=j-1;	
	     			}
	     		}
	  		 help_number=pow1(number);
	     	}while(flag!=0);                     /*η συνθηκη ωστε αμα εχει επαναλλαμβανομενα ψηφια να δινει νεο αριθμο*/
	     }
	     printf("do you want to see the secret number (y/n)");
	     scanf("\n%c",&answer1);
	     if(answer1=='y'){
	     	for(i=0; i<number; i++){
	     		printf("%d",board[i]);
	     	}
	     }
	     for(i=0; i<number; i++){
	     	basic=board[i];
	     	board_c_random[i]=char_random(basic);
	     }
	     counter=0;
	     do{
	     	counter++;     /*μεταβλητη που μετραει το πληθος των προσπαθιων του παιχτη*/
	        printf("\nplease give me a number(negative to quit):");
	        help_number=pow1(number);
	        scanf("\n%d",&guess_number);         /*εισαγωγη του guess αριθμου*/
	        while(guess_number>=(help_number*10)){              /*ελεγχος οτι ο guess αριθμος δεν εχει πανω απο ν ψηφια*/
	        	printf("please give me a number(negative to quit):");
	        	scanf("\n%d",&guess_number);
	        }
	     	if(guess_number>=0){
	     	 help_number=pow1(number);
	     	 for(i=0; i<number; i++){                         /*εδω ο guess αριθμος εκχωριται σε πινακα*/
	     		board_guess[i]=guess_number/help_number;
	     		guess_number=guess_number-board_guess[i]*help_number;
	     		help_number=help_number/10;
	        	}
	        	for(i=0; i<number; i++){                      /*εδω γινεται ο πινακας αριθμνων σε αλφαριθμιτικο*/
	     		 basic=board_guess[i];
	     		 board_c_guess[i]=char_random(basic);
	        	}
	         flag=0;
			 for(basic=0; basic<10; basic++){                  /*εδω γινεται ελεγχος για το ποσα ψηφια εχουν κοινα ανεξαρτητα απο την θεση*/
			 	flag1=0;
			    flag2=0;
			 	flag_char=char_random(basic);
			 	for(i=0; i<number; i++){
			 		if(board_c_random[i]==flag_char){
			 			flag1=flag1+1;
			 		}
			 		if(board_c_guess[i]==flag_char){
			 		    flag2=flag2+1;
					}
				}
					if(flag2<flag1){
						flag=flag+flag2;
					}else{
						flag=flag+flag1;
					}
			 }	
	         	
	         	stop=0;                                           /*εδω γινεται ο ελεγχος για το ποσα ψηφια εχουν ιδια στην ιδια θεση*/
	            	for(i=0; i<number; i++){
		            if(board_c_random[i]==board_c_guess[i]){
						stop++;
		           	}
		           }
	     	    if(flag<=(number/2)){                             /*εδω βρισκονται τα μηνυματα τα οποια ανφερουν στον παιχτη ποσα και ποια ψηφια ειναι στη σωστη θεση*/
	     	    printf("\nno so good guess,try again");                
		     	 }else if(flag>(number/2)&&stop<(number/2)){
			 	printf("\ngood guess,try again");             
		     	 }else if(stop>(number/2)&&stop!=number){
			 	printf("\nyou are in the right path,try again");
		      	 }else if(stop==number){
		   	 	printf("\nExcelent you found it!!!!!!!!!!!\n");
		   	 	 printf("\nYou found the secretnumber with %d guesses!",counter);
		     	 }
			 printf("\nTotal number of digits found:%d",flag);    /*εδω εκτυπωνονται τα ψηφια που ειναι ιδια */
			 printf("\ndigits found in correct position :%d",stop);	/*εδω εκτυπωνονται τα ψηφια που ειναι ιδια στην ιδια θεση*/
	        }else{
			stop=number;
			printf("thanks,maybe some other day\n");
	    	}
	     }while(stop!=number);
}else{
	printf("thanks,maybe some other day\n");
}
system ("PAUSE");
return 0;
}
int find_number(help_number)                /*η συναρτηση αυτη βρισκει εναν τυχαιο αριθμο*/
{
	int sec_num;
	srand(time(NULL));
	sec_num=rand()%help_number*10;
	return sec_num;
}
int pow1(number)                            /*η συανρτηση αυτη βρησκει τον βοηθητικο αριθμο*/
{                                            
	int num;                                 
	    if (number==3){
		num=100;                  
		}else if(number==4){
			num=1000;
		}else{
			num=10000;
		}
return (num);
}                  
char char_random(basic)                   /*αυτη η συναρτηση μεταρεπει εναν αριθμο σε αλφαριθμητικο*/
{
	return (basic+48);
}
