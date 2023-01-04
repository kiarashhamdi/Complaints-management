#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void admin(char *username, long int ID_number);
void main_window(WINDOW *win);
void start();
void menu(char *username, long int ID_number);
void user(char *username, long int ID_number);
void admin_menu(char *username, long int ID_number);
void new_report(char *username, long int ID_number);
void accepted_reporsts(char *username, long int ID_number);
void rejected_reporsts(char *username, long int ID_number);
void history(char *username, long int ID_number);
void ban_users(char *username, long int ID_number);
void reasons(char *username, long int ID_number);
void rewards(char *username, long int ID_number);
void sign_up();
void sign_in();
void user_menu();
void inbox();
void history_user();
void add_new_report(char *username, long int ID_number);
void ordering_reports(char *username, long int ID_number);
void edit_reports(char *username, long int ID_number);
void delete_reports(char *username, long int ID_number);
void related_reports(char *username, long int ID_number);
void important_reports(char *username, long int ID_number);
void answering_reports(char *username, long int ID_number);
void time_now();
void delete_all(char *username, long int ID_number);
void show_important_reports();
void delete_importants(char *username, long int ID_number);
void show_information(char *username, long int ID_number,int money);
void delete_struct(char *username, long int ID_number);
void forget_password();
void unblock();
void prograss(WINDOW *win, int y, int began_x, int end_x, int speed);
void related_reports_admin(char *username, long int ID_number);

struct user {
    long int id_number;
    char name[30]; 
    char username[30];
    char password[30];
    char status[20];
    int money;
};

struct new_report{
    char user [30];
    long int ID_number;
    int number;
    char report_name[30];
    char reason[20];
    char explanation[1000];
    char reason_of_reject[1000];
    int hour;
    int minute;
    int second;
    int day;
    int month;
    int year;
    int ahour;
    int aminute;
    int asecond;
    int aday;
    int amonth;
    int ayear;
};


int main(char *username, long int ID_number){   //start of the program
    initscr();
    curs_set(0);
    start_color();
     menu(username,ID_number);
    FILE *fp = fopen("file.txt" , "w");
    endwin();
    return 0;
}
//admin
void admin(char *username, long int ID_number){     //check admin password
    time_now();
    char pass[10],password[10]="1234";
    int i=0;
    WINDOW *win;
    win = newwin(55 , 120 , 0 , 35);
    refresh();
    box(win , 0, 0);
    main_window(win);  
    mvprintw(13, 85,"Enter password: " );
    scanw("%s",pass);
     if (strcmp(pass,password)==0){
     
        mvprintw(18, 85 ,"Password Match");
        getch;
        prograss(win, 40, 40, 80, 80);
        admin_menu(username,ID_number);
        }
     else
        mvprintw(18, 85 ,"Wrong password!!");
        getch();
   
}

void user(char *username, long int ID_number){  //menu for log in
    int c;
    time_now();
    mvprintw(14,85,"1.Sign up");
    mvprintw(15,85,"2.Sign in");
    mvprintw(16,85,"3.Forget password");
    c = getch();
     switch (c)
    {
    case '1':
    sign_up();
        break;

    case '2':
    sign_in();
        break;

    case '3':
    forget_password();
        break;
    }

}

void main_window(WINDOW *win){      //make window
    
    win = newwin(55 , 120 , 0 , 35);
    refresh();
    box(win , 0, 0);
    wrefresh(win);
}

void clean_text(){      //to remove stuff
mvprintw(4 ,37,"                                                                                                                    ");
mvprintw(5 ,37,"                                                                                                                    ");
mvprintw(6 ,37,"                                                                                                                    ");
mvprintw(7 ,37,"                                                                                                                    ");
mvprintw(8 ,37,"                                                                                                                    ");
mvprintw(9 ,37,"                                                                                                                    ");
mvprintw(10,37,"                                                                                                                    ");
mvprintw(11,37,"                                                                                                                    ");
mvprintw(12,37,"                                                                                                                    ");
mvprintw(13,37,"                                                                                                                    ");
mvprintw(14,37,"                                                                                                                    ");
mvprintw(15,37,"                                                                                                                    ");
mvprintw(16,37,"                                                                                                                    ");
mvprintw(17,37,"                                                                                                                    ");
mvprintw(18,37,"                                                                                                                    ");
mvprintw(18,37,"                                                                                                                    ");
mvprintw(19,37,"                                                                                                                    ");
mvprintw(20,37,"                                                                                                                    ");
mvprintw(21,37,"                                                                                                                    ");
mvprintw(22,37,"                                                                                                                    ");
mvprintw(23,37,"                                                                                                                    ");
mvprintw(24,37,"                                                                                                                    ");
mvprintw(25,37,"                                                                                                                    ");
mvprintw(26,37,"                                                                                                                    ");
mvprintw(27,37,"                                                                                                                    ");
mvprintw(28,37,"                                                                                                                    ");
mvprintw(29,37,"                                                                                                                    ");
mvprintw(30,37,"                                                                                                                    ");
mvprintw(31,37,"                                                                                                                    ");
mvprintw(32,37,"                                                                                                                    ");
mvprintw(33,37,"                                                                                                                    ");
mvprintw(34,37,"                                                                                                                    ");
mvprintw(35,37,"                                                                                                                    ");
mvprintw(36,37,"                                                                                                                    ");
mvprintw(37,37,"                                                                                                                    ");
mvprintw(38,37,"                                                                                                                    ");
mvprintw(39,37,"                                                                                                                    ");
mvprintw(40,37,"                                                                                                                    ");
mvprintw(41,37,"                                                                                                                    ");
mvprintw(42,37,"                                                                                                                    ");
mvprintw(43,37,"                                                                                                                    ");
} 

void admin_menu(char *username, long int ID_number){       //show user menu
     int c;
     while(1){
     clean_text();
     time_now();
     mvprintw(12,80,"1.New reports");
     mvprintw(13,80,"2.Answring reporst");
     mvprintw(14,80,"3.Reports that are accepted");
     mvprintw(15,80,"4.Reports that are rejected");
     mvprintw(16,80,"5.History");
     mvprintw(17,80,"6.Ban users");
     mvprintw(18,80,"7.Reasons for rejecting");
     mvprintw(19,80,"8.Rewards for reporter");
     mvprintw(20,80,"9.Unblock user");
     mvprintw(21,80,"0.Log out");
     mvprintw(22,80,"r.Related reports");
     c = getch();
     switch (c)
    {
    case '1':
    new_report(username,ID_number);
        break;

    case '2':
    answering_reports(username,ID_number);
        break;

    case '3':
    accepted_reporsts(username,ID_number);
        break;
    case '4':
    rejected_reporsts(username,ID_number);
        break;

    case '5':
    history(username,ID_number);
        break;

    case '6':
    ban_users(username,ID_number);
        break;

    case '7':
    reasons(username,ID_number);
        break;

    case '8':
     rewards(username,ID_number);
        break;

    case '9':
    unblock();
        break;

    case '0':
     menu(username,ID_number);
        break; 

    case 'r':
     related_reports_admin(username,ID_number);
        break;        

    default:
    clean_text();
    mvprintw(5, 75,"you press wrong key");
    mvprintw(6, 75,"press ane key to try again");
    getch();
    admin_menu(username,ID_number);

            break;
    }
     }
}

void new_report(char *username, long int ID_number){    //show report that are not answered
    FILE *fp;
    time_now();
    struct new_report report;
    struct user n1;
    int i=0;
    clean_text();
    fp=fopen("reports.txt","ab+");
    int xaxis ;
    xaxis = 15;
    int xcounter =0; 
     mvprintw(12 , 45, "    name \t\t     reason\t\t explanation \t\t    user \t   date       time");
     while((fread(&report,sizeof(struct new_report),1,fp))==1)
    {
        i++;
        mvprintw(xaxis+xcounter,115," ");
        printw("%s",report.user);
        mvprintw(xaxis+xcounter,39," ");
        printw("%d.",i);
        mvprintw(xaxis+xcounter,48," ");
        printw("%s",report.report_name);
        mvprintw(xaxis+xcounter,68," ");
        printw("%s",report.reason);
        mvprintw(xaxis+xcounter,88," ");
        printw("%s",report.explanation);
        mvprintw(xaxis+xcounter,130," ");
        printw("%d/%d/%d  %d:%d:%d",report.day,report.month,report.year,report.hour,report.minute,report.second);
        xcounter++;
    }
    getch();
    fclose(fp);
    admin_menu(username,ID_number);
}

void answering_reports(char *username, long int ID_number){     //to answer report
clean_text();
time_now();
struct new_report report;
FILE *fp;
FILE *fa;  //accepted
FILE *fr;  //rejected
FILE *fh;  //history
mvprintw(12, 85 , "important reports");
show_important_reports();
clean_text();
fp=fopen("reports.txt","ab+");
fa=fopen("accepted.txt","ab+");
fr=fopen("rejected.txt","ab+");
fh=fopen("history.txt","ab+");
rewind(fp);
  while((fread(&report,sizeof(struct new_report),1,fp))==1)
    {
clean_text();
mvprintw(16, 60 , "report number is: %d",report.number);
mvprintw(17, 60 , "report name is: %s",report.report_name);
mvprintw(18, 60 , "report reason is: %s",report.reason);
mvprintw(19, 60 , "report explanation is: %s",report.explanation);
mvprintw(20, 60 , "date: %d/%d/%d  ",report.day,report.month,report.year);
mvprintw(21, 60 , "time: %d:%d:%d",report.hour,report.minute,report.second);
int number, c;
mvprintw(25, 60 ,"If answer is accpted press 1  ");
mvprintw(26, 60 ,"If answer is rejected press 2 ");
c = getch();
char buff[100];
time_t now = time(0);
struct tm now_t = *localtime(&now);
strftime (buff, 100, "%d-%m-%Y %H:%M:%S", &now_t);

report.ayear= now_t.tm_year + 1900;
report.amonth = now_t.tm_mon + 1;  
report.aday = now_t.tm_mday;  

report.ahour = now_t.tm_hour;
report.aminute = now_t.tm_min;
report.asecond = now_t.tm_sec;
switch (c)
{
case '1':
fwrite(&report,sizeof(report),1,fa);
fwrite(&report,sizeof(report),1,fh);
break;
case '2':
clean_text();
mvprintw(12, 60 , "Please enter reason of rejecting:");
getstr(report.reason_of_reject);
fwrite(&report,sizeof(report),1,fr);
fwrite(&report,sizeof(report),1,fh);
break;

getch();
}
getch();
 }
mvprintw(20, 60 , "all reports answered press any key to continue:");
fclose(fp);
fclose(fr);
fclose(fa);
fclose(fh);
delete_all(username,ID_number);
remove("important.txt");
admin_menu(username,ID_number);
getch();

} 

void accepted_reporsts(char *username, long int ID_number){    // show rejected reports
clean_text();
time_now();
struct new_report report;
FILE *fa;
fa=fopen("accepted.txt","r");
rewind(fa);
int xaxis ;
    xaxis = 15;
    int i=0;
    int xcounter =0; 
    mvprintw(12 , 45, "    name \t\t     reason\t\t explanation \t\t    user \t   date       time");
  while((fread(&report,sizeof(struct new_report),1,fa))==1)
    {
      i++;
        mvprintw(xaxis+xcounter,115," ");
        printw("%s",report.user);
        mvprintw(xaxis+xcounter,39," ");
        printw("%d.",i);
        mvprintw(xaxis+xcounter,48," ");
        printw("%s",report.report_name);
        mvprintw(xaxis+xcounter,68," ");
        printw("%s",report.reason);
        mvprintw(xaxis+xcounter,88," ");
        printw("%s",report.explanation);
        mvprintw(xaxis+xcounter,130," ");
        printw("%d/%d/%d  %d:%d:%d",report.aday,report.amonth,report.ayear,report.ahour,report.aminute,report.asecond);
        xcounter++;
 }
fclose(fa);
getch();
}

void rejected_reporsts(char *username, long int ID_number){     //show rejected reports
clean_text();
time_now();
struct new_report report;
FILE *fr;
fr=fopen("rejected.txt","r");
rewind(fr);
int xaxis ;
    xaxis = 15;
    int i=0;
    int xcounter =0; 
    mvprintw(12 , 45, "    name \t\t     reason\t\t explanation \t\t    user \t   date       time");
  while((fread(&report,sizeof(struct new_report),1,fr))==1)
    {
      i++;
        mvprintw(xaxis+xcounter,115," ");
        printw("%s",report.user);
        mvprintw(xaxis+xcounter,39," ");
        printw("%d.",i);
        mvprintw(xaxis+xcounter,48," ");
        printw("%s",report.report_name);
        mvprintw(xaxis+xcounter,68," ");
        printw("%s",report.reason);
        mvprintw(xaxis+xcounter,88," ");
        printw("%s",report.explanation);
        mvprintw(xaxis+xcounter,130," ");
        printw("%d/%d/%d  %d:%d:%d",report.aday,report.amonth,report.ayear,report.ahour,report.aminute,report.asecond);
        xcounter++;
 }
fclose(fr);
getch();
}

void related_reports_admin(char *username, long int ID_number){     //show all related reports
    clean_text();
    FILE *fp;
    time_now();
    char reason[30];
    struct new_report report;
    struct user n1;
    int i=0;
    clean_text();
    fp=fopen("reports.txt","ab+");
    int xaxis ;
    xaxis = 15;
    int xcounter =0; 
    mvprintw(25,60,"enter reason of file that you want to check:");
    getstr(reason);
    fseek (fp,0,SEEK_SET);
    while (fread(&report,sizeof (struct new_report),1, fp)) {
        if (strcmp(reason,report.reason )==0) {

        i++;
        mvprintw(12 , 45, "    name \t\t     reason\t\t explanation \t\t    user \t   date       time");
        mvprintw(xaxis+xcounter,115," ");
        printw("%s",report.user);
        mvprintw(xaxis+xcounter,39," ");
        printw("%d.",i);
        mvprintw(xaxis+xcounter,48," ");
        printw("%s",report.report_name);
        mvprintw(xaxis+xcounter,68," ");
        printw("%s",report.reason);
        mvprintw(xaxis+xcounter,88," ");
        printw("%s",report.explanation);
        mvprintw(xaxis+xcounter,130," ");
        printw("%d/%d/%d  %d:%d:%d",report.day,report.month,report.year,report.hour,report.minute,report.second);
        xcounter++;
        }

        }
getch();



}

void history(char *username, long int ID_number){
    time_now();
    FILE *fa;
    struct new_report report;
    int i=0;
    clean_text();
    fa=fopen("history.txt","ab+");
    int xaxis ;
    xaxis = 15;
    int xcounter =0; 
     mvprintw(12 , 45, "    name \t\t     reason\t\t explanation \t\t    user \t   date       time");
     while((fread(&report,sizeof(struct new_report),1,fa))==1)
    {   
        i++;
        mvprintw(xaxis+xcounter,115," ");
        printw("%s",report.user);
        mvprintw(xaxis+xcounter,39," ");
        printw("%d.",i);
        mvprintw(xaxis+xcounter,48," ");
        printw("%s",report.report_name);
        mvprintw(xaxis+xcounter,68," ");
        printw("%s",report.reason);
        mvprintw(xaxis+xcounter,88," ");
        printw("%s",report.explanation);
        mvprintw(xaxis+xcounter,130," ");
        printw("%d/%d/%d  %d:%d:%d",report.day,report.amonth,report.ayear,report.ahour,report.aminute,report.asecond);
        xcounter++;
    }
    fclose(fa);
    getch();
}

void ban_users(char *username, long int ID_number){     //admid can ban users

    clean_text();
    time_now();
    FILE *ft;
    FILE *fp;
    char user_username [30];
    ft=fopen ("temp.dat","ab");
    fp=fopen("data.dat", "rb");

    struct user n1;
    mvprintw (25,60,"Enter the username :");
    getstr (user_username);
    while(fread(&n1, sizeof(struct user),1,fp)==1) {
        if (strcmp(n1.username,user_username)==0){
            strcpy(n1.status,"blocked");
        }
        fwrite(&n1,sizeof(struct user),1,ft);
        }
        fclose(fp);
    fclose(ft);
    remove("data.dat");
    FILE *fp2;
    FILE *ft2;
    fp2=fopen ("data.dat","ab");
    ft2=fopen ("temp.dat","rb");
    while (fread(&n1,sizeof(struct user),1,ft2)==1) {
        fwrite(&n1,sizeof(struct user),1,fp2);
    }
    fclose (ft2);
    fclose (fp2);
    remove("temp,dat");
    WINDOW *win;
    win = newwin(55 , 120 , 0 , 35);
    refresh();
    box(win , 0, 0);
    main_window(win);  
    prograss(win, 40, 40, 80, 80);
    mvprintw(25, 60 ,"User succssefully blocked");
    getch();
}

void unblock(){         //admin can unblock user 
clean_text();
    time_now();
    FILE *ft;
    FILE *fp;
    char user_username [30];
    ft=fopen ("temp.dat","ab");
    fp=fopen("data.dat", "rb");

    struct user n1;
    mvprintw (25,60,"Enter the username :");
    getstr (user_username);
    while(fread(&n1, sizeof(struct user),1,fp)==1) {
        if (strcmp(n1.username,user_username)==0){
            strcpy(n1.status,"not block");
        }
        fwrite(&n1,sizeof(struct user),1,ft);
        }
        fclose(fp);
    fclose(ft);
    remove("data.dat");
    FILE *fp2;
    FILE *ft2;
    fp2=fopen ("data.dat","ab");
    ft2=fopen ("temp.dat","rb");
    while (fread(&n1,sizeof(struct user),1,ft2)==1) {
        fwrite(&n1,sizeof(struct user),1,fp2);
    }
    WINDOW *win;
    win = newwin(55 , 120 , 0 , 35);
    refresh();
    box(win , 0, 0);
    main_window(win);  
    prograss(win, 40, 40, 80, 80);
    mvprintw(25, 60 ,"User succssefully unblocked");
    fclose (ft2);
    fclose (fp2);
    remove("temp,dat");
    getch();

}

void reasons(char *username, long int ID_number){       //show reason of rejecting reports
clean_text();
time_now();
struct new_report report;
FILE *fr;
fr=fopen("rejected.txt","r");
rewind(fr);
int xaxis ;
    xaxis = 15;
    int i=0;
    int xcounter =0; 
    mvprintw(12 , 45, "    name \t\t     reason\t\t reason of reject \t\t    user \t   date       time");
  while((fread(&report,sizeof(struct new_report),1,fr))==1)
    {
      i++;
        mvprintw(xaxis+xcounter,115," ");
        printw("%s",report.user);
        mvprintw(xaxis+xcounter,39," ");
        printw("%d.",i);
        mvprintw(xaxis+xcounter,48," ");
        printw("%s",report.report_name);
        mvprintw(xaxis+xcounter,68," ");
        printw("%s",report.reason);
        mvprintw(xaxis+xcounter,88," ");
        printw("%s",report.reason_of_reject);
        mvprintw(xaxis+xcounter,130," ");
        printw("%d/%d/%d  %d:%d:%d",report.day,report.month,report.year,report.hour,report.minute,report.second);
        xcounter++;
 }
fclose(fr);
getch();
}

void rewards(char *username, long int ID_number){       //to add rewards to users
    clean_text();
    time_now();
    int x=0;
    struct user n1;
    char user_username [30];
    mvprintw (25,60,"Enter the username :");
    getstr (user_username);
    FILE *ft;
    FILE *fp;
    ft=fopen ("temp.dat","ab");
    fp=fopen("data.dat", "rb");
    while(fread(&n1, sizeof(struct user),1,fp)==1) {
        if (strcmp(n1.username,user_username)==0){
            mvprintw (26,60,"Enter amount of money ?");
            scanw ("%d", &x);
            n1.money = n1.money + x;
        }
        fwrite (&n1,sizeof(struct user),1,ft);
    }
    fclose(fp);
    fclose(ft);
    remove("data.dat");
    FILE *fp2;
    FILE *ft2;
    fp2=fopen ("data.dat","ab");
    ft2=fopen ("temp.dat","rb");
    while (fread(&n1,sizeof(struct user),1,ft2)==1) {
        fwrite(&n1,sizeof(struct user),1,fp2);
    }
    fclose (ft2);
    fclose (fp2);
    remove("temp,dat");
}
//user
void sign_up(){     //sign up
    clean_text();
    char *username;
    char *password;
    struct user n1;
    time_now();
    FILE *fp;
    clean_text();
    fp=fopen("data.dat","a+b");
    strcpy(n1.status,"not block");
    mvprintw(17,80,"Enter your ID number: ");
    scanw("%ld", &n1.id_number);
    if(n1.id_number<1000000000){
    mvprintw(25,80,"Id number is must be 10 charctor ");
    getch();
    sign_up();
    }
    mvprintw(18,80,"Enter your name: ");
    getstr(n1.name);
    mvprintw(19,80,"Enter your username: ");
    getstr(n1.username);
    mvprintw(20,80,"Enter your password: ");
    getstr(n1.password);
    n1.money=0;
    fwrite(&n1,sizeof(struct user),1,fp);

   
    fclose(fp);
    clean_text();
    sign_in();
}

void sign_in(){         //sign in
    clean_text();
    time_now();
    int tmoney;
    struct user n1;
    char *username;
    char *password;
    char (ID_number);
    char usernamee[30];
    char passworde[30];
    long int ID_numbere;
    WINDOW *win;
    win = newwin(55 , 120 , 0 , 35);
    refresh();
    box(win , 0, 0);
    main_window(win);  
    
    mvprintw(18,80,"Username: ");
    scanw("%s",&usernamee);
    mvprintw(19,80,"Password: ");
    scanw("%s",&passworde);
    FILE *fp;
    fp=fopen("data.dat","rb");
    fseek(fp,0,SEEK_END);
    long int pos = ftell(fp);
    int count = (int) (pos / sizeof(struct user));
    fseek(fp,0,SEEK_SET);

    for(int i=0;i<count;i++){
        fread(&n1,sizeof(struct user),1,fp);
        if(strcmp(usernamee,n1.username)==0 && strcmp(passworde,n1.password)==0)
        {
            if (strcmp(n1.status,"not block")==0){
            tmoney=n1.money;
            ID_numbere = n1.id_number;
            fclose (fp);
            clean_text();
            prograss(win, 40, 40, 80, 80);
            show_information(usernamee, ID_numbere, tmoney);
            user_menu(usernamee, ID_numbere);
        }
        }
    }
        for(int i=0;i<count;i++){
        fread(&n1,sizeof(struct user),1,fp);
        if(strcmp(usernamee,n1.username)==0 && strcmp(passworde,n1.password)==0)
        {
            if (strcmp(n1.status,"not block")!=0){
            clean_text();
            mvprintw(25,60,"you are blocked from server");
            getch();
    }
        }
}
        for(int i=0;i<count;i++){
        fread(&n1,sizeof(struct user),1,fp);
        if(strcmp(usernamee,n1.username)!=0)
        {
            clean_text();
            mvprintw(25,60,"incorrect username");
              getch();
              menu(username,ID_number);

        }
    }
    for(int i=0;i<count;i++){
        fread(&n1,sizeof(struct user),1,fp);
        if(strcmp(usernamee,n1.username)==0 && strcmp(passworde,n1.password)!=0)
        {
            clean_text();
            mvprintw(25,60,"incorrect password");
            getch();
            menu(username,ID_number);
        }
    }
}

void user_menu(char *username, long int ID_number){ //show user menu after sign in
    int c,f;
    while(1){
    clean_text();
    time_now();
     mvprintw(12,80,"1.Inbox");
     mvprintw(13,80,"2.History");
     mvprintw(14,80,"3.Add new report");
     mvprintw(15,80,"4.Ordering");
     mvprintw(16,80,"5.Edit reports");
     mvprintw(17,80,"6.Delete reports");
     mvprintw(18,80,"7.Related reports");
     mvprintw(19,80,"8.Important reports");
     mvprintw(20,80,"9.Log out");
    c = getch();
      switch (c)
    {
    case '1':
    inbox(username,ID_number);
        break;

    case '2':
    history_user(username,ID_number);
        break;
    
    case '3':
    add_new_report(username,ID_number);
        break;

    case '4':
    ordering_reports(username,ID_number);
        break;

    case '5':
    edit_reports(username,ID_number);
        break;

    case '6':
    delete_struct(username,ID_number);
        break;
    
    case '7':
    related_reports(username,ID_number);
        break;
    
    case '8':
    important_reports(username,ID_number);
        break;

    case '9':
    menu(username,ID_number);
        break;

    default:
    clean_text();
    mvprintw(40, 75,"you press wrong key");
    mvprintw(41, 75,"press ane key to try again");
    getch();
    user_menu(username,ID_number);
        break;
    }
    }

}

void show_information(char *username, long int ID_number,int tmoney){   //show informathion of user
mvprintw (2,85, "WELLCOME  %s", username);
mvprintw (3,85, "ID : %ld", ID_number);
mvprintw (3,130, "Money : %d",tmoney);
refresh ();
}

void inbox(char *username, long int ID_number){ //show new and available reports
    FILE *fp;
    time_now();
    struct new_report report;
    struct user n1;
    int i=0;
    clean_text();
    fp=fopen("reports.txt","ab+");
    int xaxis ;
    xaxis = 15;
    int xcounter =0; 
     mvprintw(12 , 45, "    name \t\t     reason\t\t explanation \t\t    user \t   date       time");
     while((fread(&report,sizeof(struct new_report),1,fp))==1)
    {   
        if ((strcmp (report.user, username) == 0)) {
        i++;
        mvprintw(xaxis+xcounter,115," ");
        printw("%s",report.user);
        mvprintw(xaxis+xcounter,39," ");
        printw("%d.",i);
        mvprintw(xaxis+xcounter,48," ");
        printw("%s",report.report_name);
        mvprintw(xaxis+xcounter,68," ");
        printw("%s",report.reason);
        mvprintw(xaxis+xcounter,88," ");
        printw("%s",report.explanation);
        mvprintw(xaxis+xcounter,130," ");
        printw("%d/%d/%d  %d:%d:%d",report.day,report.month,report.year,report.hour,report.minute,report.second);
        xcounter++;
    }
    }
    getch();
    fclose(fp);
}

void history_user(char *username, long int ID_number){  //show reports that are answered 
    time_now();
    FILE *fa;
    struct new_report report;
    int i=0;
    clean_text();
    fa=fopen("history.txt","ab+");
    int xaxis ;
    xaxis = 15;
    int xcounter =0; 
     mvprintw(12 , 45, "    name \t\t     reason\t\t explanation \t\t    user \t   date       time");
     while((fread(&report,sizeof(struct new_report),1,fa))==1)
    {   
        i++;
        mvprintw(xaxis+xcounter,115," ");
        printw("%s",report.user);
        mvprintw(xaxis+xcounter,39," ");
        printw("%d.",i);
        mvprintw(xaxis+xcounter,48," ");
        printw("%s",report.report_name);
        mvprintw(xaxis+xcounter,68," ");
        printw("%s",report.reason);
        mvprintw(xaxis+xcounter,88," ");
        printw("%s",report.explanation);
        mvprintw(xaxis+xcounter,130," ");
        printw("%d/%d/%d  %d:%d:%d",report.aday,report.amonth,report.ayear,report.ahour,report.aminute,report.asecond);
        xcounter++;
    }
    fclose(fa);
    getch();
}

void add_new_report(char *username, long int ID_number){    //get new report
    clean_text();
    time_now();
    struct new_report report;
    FILE *fp;
    FILE *ft;
    int c=0;

    fp=fopen("reports.txt","ab+");
    ft=fopen("important.txt","ab+");
    mvprintw(15,60,"Please enter the number of report:");
    scanw("%d",&report.number);
    mvprintw(16,60,"Please enter the  report name:");
    getstr(report.report_name);
    mvprintw(17,60,"Please enter the reason of report:");
    getstr(report.reason);
    mvprintw(18,60,"Please enter the report explanation:");
    getstr(report.explanation);
    strcpy (report.user, username);
    char buff[100];
    time_t now = time(0);
    struct tm now_t = *localtime(&now);
    strftime (buff, 100, "%d-%m-%Y %H:%M:%S", &now_t);

    report.year= now_t.tm_year + 1900;
    report.month = now_t.tm_mon + 1;  
    report.day = now_t.tm_mday;  

    report.hour = now_t.tm_hour;
    report.minute = now_t.tm_min;
    report.second = now_t.tm_sec;
    
    mvprintw(19, 60 ,"If it is an important report press 1 if else press 2");
    c =getch();
   switch (c)
   {
   case '1':
       fwrite(&report,sizeof(report),1,ft);  
       break;
   
   case '2':
       fwrite(&report,sizeof(report),1,fp);
       break;
   }
      
    fclose(fp);
    fclose (ft);
    user_menu(username, ID_number);
}

void ordering_reports(char *username, long int ID_number){      // null
        clean_text();
mvprintw(18,80,"awdadwda");
getch();
}

void edit_reports(char *username, long int ID_number){  //edit report
clean_text();
time_now();
int i=0;
int xaxis ;
xaxis = 15;
int xcounter =0; 
char report_namee[30];
struct new_report report;
FILE *fp;
FILE *fa;  //accepted
FILE *fr;  //rejected
int c;
fp=fopen("reports.txt","ab+");
mvprintw(12 , 45, "   1.name \t\t     2.reason\t\t 3.explanation \t\t    5.hole");
  while((fread(&report,sizeof(struct new_report),1,fp))==1)
    {
if ((strcmp (report.user, username) == 0)) {
        i++;
        mvprintw(xaxis+xcounter,39," ");
        printw("%d.",i);
        mvprintw(xaxis+xcounter,48," ");
        printw("%s",report.report_name);
        mvprintw(xaxis+xcounter,68," ");
        printw("%s",report.reason);
        mvprintw(xaxis+xcounter,88," ");
        printw("%s",report.explanation);
        mvprintw(xaxis+xcounter,130," ");
        xcounter++;
    }
    }
mvprintw(8, 85 , "Edit mode");

 mvprintw(25,60,"Enter name of file that you want to edit:");
    getstr(report_namee);

    fseek (fp,0,SEEK_SET);
    while (fread(&report,sizeof (struct new_report),1, fp)) {
        if (strcmp(report_namee,report.report_name )==0) {
            

mvprintw(26, 60 , "Please enter number you want to edit:");
c= getch();
switch (c)
{
case '1':
clean_text();
mvprintw(15,60,"Please enter the number of report:");
scanw("%d",&report.number);
break;

case '2':
clean_text();
mvprintw(16,60,"Please enter the  report name:");
getstr(report.report_name);
    break;

case '3':
clean_text();
mvprintw(17,60,"Please enter the reason of report:");
getstr(report.reason);
    break;

case '4':
clean_text();
mvprintw(18,60,"Please enter the report explanation:");
getstr(report.explanation);
    break;

    case '5':
mvprintw(12,80,"Welcome to report center");
mvprintw(15,60,"Please enter the number of report:");
scanw("%d",&report.number);
mvprintw(16,60,"Please enter the  report name:");
getstr(report.report_name);
mvprintw(17,60,"Please enter the reason of report:");
getstr(report.reason);
mvprintw(18,60,"Please enter the report explanation:");
getstr(report.explanation);
    break;

}
fwrite(&report,sizeof(struct new_report),1,fp);
fclose(fp);
}
}

getch();
}

void delete_struct(char *username, long int ID_number){     //user delete any report 
    FILE *fp;
    FILE *fd;
    time_now();
    char report_namee[30];
    struct new_report report;
    struct user n1;
    int i=0;
    clean_text();
    fp=fopen("reports.txt","ab+");
    fd=fopen("temp.txt","ab+");
    int xaxis ;
    xaxis = 15;
    int xcounter =0; 
     mvprintw(12 , 45, "    name \t\t     reason\t\t explanation \t\t    user \t   date       time");
     while((fread(&report,sizeof(struct new_report),1,fp))==1)
    {
     if ((strcmp (report.user, username) == 0)) {
        i++;
        mvprintw(xaxis+xcounter,115," ");
        printw("%s",report.user);
        mvprintw(xaxis+xcounter,39," ");
        printw("%d.",i);
        mvprintw(xaxis+xcounter,48," ");
        printw("%s",report.report_name);
        mvprintw(xaxis+xcounter,68," ");
        printw("%s",report.reason);
        mvprintw(xaxis+xcounter,88," ");
        printw("%s",report.explanation);
        mvprintw(xaxis+xcounter,130," ");
        printw("%d/%d/%d  %d:%d:%d",report.day,report.month,report.year,report.hour,report.minute,report.second);
        xcounter++;
    }
    }
    getch();
    
    mvprintw(25,60,"Enter name of file that you want to delete:");
    getstr(report_namee);

    fseek (fp,0,SEEK_SET);
    while (fread(&report,sizeof (struct new_report),1, fp)) {
        if (strcmp(report_namee,report.report_name )!=0) {
            fwrite (&report,sizeof (struct new_report),1, fd);
        }
    }

    fclose (fp);
    fclose (fd);
    remove("reports.txt");

    FILE *fp2 = fopen("reports.txt", "ab+");
    FILE *fd2 = fopen("temp.txt", "ab+");
    
    while (fread(&report,sizeof (struct new_report),1, fd2)) {
            fwrite (&report,sizeof (struct new_report),1, fp2);
    }
    fclose (fp2);
    fclose (fd2);
    remove ("temp.txt");
    WINDOW *win;
    win = newwin(55 , 120 , 0 , 35);
    refresh();
    box(win , 0, 0);
    main_window(win);  
    prograss(win, 40, 40, 80, 80);
    mvprintw(25,60,"succssesfuly deleted");
}

void delete_reports(char *username, long int ID_number){        //null
clean_text();
struct new_report report;
time_now();
FILE *fp;
FILE *ft;
fp = fopen("reports.txt","wb");
rewind(fp);
  while((fread(&report,sizeof(struct new_report),1,fp))==1)
    {
clean_text();
mvprintw(16, 60 , "report number is: %d",report.number);
mvprintw(17, 60 , "report name is: %s",report.report_name);
mvprintw(18, 60 , "report reason is: %s",report.reason);
mvprintw(19, 60 , "report explanation is: %s",report.explanation);
int number, c;
mvprintw(25, 70 ,"if answer is accpted press 1  ");
mvprintw(26, 70 ,"if answer is rejected press 2 ");
c = getch();
ft = fopen("delet.txt","wb");
switch (c)
{
case '1':
rewind(fp);
while((fread(&report,sizeof(struct new_report),1,fp))==1){
fwrite(&report,sizeof(struct new_report),1,ft);
fclose(fp);
fclose(ft);
remove("report.txt");
rename("delet.txt","report.txt");
getch();
break;

}
getch();
 }

 
}
}

void delete_all(char *username, long int ID_number){    //delete reports after answer
clean_text();
struct new_report report;
FILE *fp;
FILE *ft;
fp = fopen("reports.txt","wb");    
ft = fopen("delet.txt","wb");
while((fread(&report,sizeof(struct new_report),1,fp))==1){
fwrite(&report,sizeof(struct new_report),1,ft);
fclose(fp);
fclose(ft);
remove("report.txt");
rename("delet.txt","report.dat");
}
}

void delete_importants(char *username, long int ID_number){ //delete important reports after answer
clean_text();
struct new_report report;
FILE *fp;
FILE *ft;
fp = fopen("important.txt","wb");    
ft = fopen("delet.txt","wb");
while((fread(&report,sizeof(struct new_report),1,fp))==1){
fwrite(&report,sizeof(struct new_report),1,ft);
fclose(fp);
fclose(ft);
remove("important.txt");
rename("delet.txt","important.dat");
}
}


void related_reports(char *username, long int ID_number){       //show users related reports
    clean_text();
    FILE *fp;
    time_now();
    char reason[30];
    struct new_report report;
    struct user n1;
    int i=0;
    clean_text();
    fp=fopen("reports.txt","ab+");
    int xaxis ;
    xaxis = 15;
    int xcounter =0; 
    mvprintw(25,60,"Enter reason of file that you want to check:");
    getstr(reason);
    fseek (fp,0,SEEK_SET);
    while (fread(&report,sizeof (struct new_report),1, fp)) {
        if (strcmp(reason,report.reason )==0) {
        if ((strcmp (report.user, username) == 0)) {
        mvprintw(12 , 45, "    name \t\t     reason\t\t explanation \t\t    user \t   date       time");
        i++;
        mvprintw(xaxis+xcounter,115," ");
        printw("%s",report.user);
        mvprintw(xaxis+xcounter,39," ");
        printw("%d.",i);
        mvprintw(xaxis+xcounter,48," ");
        printw("%s",report.report_name);
        mvprintw(xaxis+xcounter,68," ");
        printw("%s",report.reason);
        mvprintw(xaxis+xcounter,88," ");
        printw("%s",report.explanation);
        mvprintw(xaxis+xcounter,130," ");
        printw("%d/%d/%d  %d:%d:%d",report.day,report.month,report.year,report.hour,report.minute,report.second);
        xcounter++;
    }
        }

        }
getch();



}

void important_reports(char *username, long int ID_number){ //show important reports for user
    FILE *ft;   
    time_now();
    struct new_report report;
    int i=0;
    clean_text();
    ft=fopen("important.txt","ab+");
    int xaxis ;
    xaxis = 15;
    int xcounter =0; 
     mvprintw(12 , 69, "name \t\t reason\t\t     explanation");
     while((fread(&report,sizeof(struct new_report),1,ft))==1)
    {       i++;
        mvprintw(xaxis+xcounter,63," ");
        printw("%d.",i);
        mvprintw(xaxis+xcounter,68," ");
        printw("%s",report.report_name);
        mvprintw(xaxis+xcounter,88," ");
        printw("%s",report.reason);
        mvprintw(xaxis+xcounter,108," ");
        printw("%s",report.explanation);


        xcounter++;
    }
    getch();
    fclose(ft);
}

void show_important_reports(char *username, long int ID_number){        //important reports for anser
clean_text();
time_now();
struct new_report report;
FILE *fp;
FILE *fa;  //accepted
FILE *fr;  //rejected
FILE *fh;  //history

fp=fopen("important.txt","ab+");
fa=fopen("accepted.txt","ab+");
fr=fopen("rejected.txt","ab+");
fh=fopen("history.txt","ab+");
rewind(fp);
  while((fread(&report,sizeof(struct new_report),1,fp))==1)
    {
clean_text();
mvprintw(16, 60 , "Report number is: %d",report.number);
mvprintw(17, 60 , "Report name is: %s",report.report_name);
mvprintw(18, 60 , "Report reason is: %s",report.reason);
mvprintw(19, 60 , "Report explanation is: %s",report.explanation);
int number, c;
mvprintw(25, 70 ,"If answer is accpted press 1  ");
mvprintw(26, 70 ,"If answer is rejected press 2 ");
c = getch();
switch (c)
{
case '1':
fwrite(&report,sizeof(report),1,fa);
fwrite(&report,sizeof(report),1,fh);
break;
case '2':
clean_text();
mvprintw(12, 60 , "Please enter reason of rejecting:");
getstr(report.reason_of_reject);
fwrite(&report,sizeof(report),1,fr);
fwrite(&report,sizeof(report),1,fh);
break;

getch();
}
getch();
}
mvprintw(20, 60 , "All reports answered press any key to continue:");
fclose(fp);
fclose(fr);
fclose(fa);
fclose(fh);
delete_importants(username,ID_number);

}
//end of user
void forget_password(){         //show password if password forget
    time_now();
    clean_text();
    
    struct user n1;
    FILE *fp;
    fp=fopen("data.dat","rb+");
    long int id;
    mvprintw(20,60,"Plaese enter your id:");
    scanw("%ld",&id);
    while((fread(&n1,sizeof(struct user),1,fp))==1){
    if(id==n1.id_number){
        mvprintw(21,60,"Your password is :%s",&n1.password);
    }
    }
    getch();
    fclose(fp);
}

void time_now()     //show time
{
        time_t time_now;
        time_now = time(NULL);
        char now[25];
        strcpy(now, ctime(&time_now));
        mvprintw( 6, 60, "        ");
        
        mvprintw( 6, 89, "%.*s", 8, now + 11);
        mvprintw( 5, 85, "%.*s", 10, now + 0);
        mvprintw( 5, 95, " %.*s", 4, now + 20);
        
}

void prograss(WINDOW *win, int y, int began_x, int end_x, int speed) //progress chart
{       
    win = newwin(55 , 120 , 0 , 35);
    refresh();
    box(win , 0, 0);
    main_window(win);  

        curs_set(0);
        float i = 0;
        init_pair(101, COLOR_GREEN, COLOR_GREEN);
        for (; i < end_x - began_x; i = i + 1)
        {
                napms(speed);
                mvwprintw(win, y - 1, began_x + (end_x - began_x) / 2, "%.f%%", (i / (end_x - began_x)) * 100);
                wattron(win, COLOR_PAIR(101));
                mvwprintw(win, y, began_x + i, " ");
                mvwprintw(win, y + 1, began_x + i, " ");
                wattroff(win, COLOR_PAIR(101));
                wrefresh(win);
        }
        mvwprintw(win, y - 1, began_x + (end_x - began_x) / 2 - 1, "100");
        wrefresh(win);
}

void menu(char *username,long int ID_number){  //main menu

    char c;
    while(1){
    WINDOW *  win;
    win = newwin(55 , 140 , 0 , 25);
    refresh();
    box(win , 0, 0);
    main_window(win);   
    mvprintw(3, 90,"Welcome");
    mvprintw(12, 90,"       ");
    mvprintw(13, 90,"1.Admin");
    mvprintw(14, 90,"2.User");
    mvprintw(15, 90,"3.About");
    wrefresh(win);
    time_now();
    c = getch();
    switch (c)
    {
    case '1':
    main_window(win);
    admin(username,ID_number);
    clear();

        break;

    case '2':
    main_window(win);
    user(username,ID_number);
    clear();
    break;

    case '3':

    mvprintw(50, 31, "Developed by Kiarash Hadmdi", 65);
    mvprintw(51, 31, "Feedback : kiarashhamdi@gmail.com", 65);
    mvprintw(52, 31, "Telegram : @kiarash_Hamdi", 65);
    getch();
    clear();
    menu(username,ID_number);
    default:
    main_window(win);
    mvprintw(5, 75,"you press wrong key");
    mvprintw(6, 75,"press ane key to try again");
    getch();
    clean_text();
    break; 
    }
    }

    getch();
}
