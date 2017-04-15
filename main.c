#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
int main()
{


struct process {

char *Pname;
int PID;
char *status;
float *s_time;
float *e_time;
};


struct process Plist[20];
int Ppointer = 0;
int runs = 0;

printf(" Hiham Bin Sajid -09383 \n Version 0.0.1 \n All rights reserved \n \n type [ls] for all commands \n \n");

int x = 10;
while(x>5)
 {
    char str[500];

    printf("Enter a command: ");
    printf("\n");
    fgets (str, 500, stdin);
    char space[2] = " ";
    strcat(str,space);


    const char s[2] = " \n";
    char *token;
    token = strtok(str,s);





    while(token != NULL) {

        if(strcmp(token,"exit")==0){
            exit(0);

        }

        if(strcmp(token,"kill")==0){
           char *PID_inchar = strtok(NULL,s);
           int PID;


            if(strcasecmp(PID_inchar,"notepad") == 0){
                int i=0;


                while(i<runs){
                    if(strcmp(Plist[i].Pname,"notepad")==0){
                        PID = Plist[i].PID;
                        Plist[i].status = "deactivated";
                        printf("%i \n",PID);
                        clock_t end = clock();


                        Plist[i].e_time = end;

                        printf("Process end time: %f ticks \n ",Plist[i].e_time);


                    }

                    i++;
                }


            }

            else if(strcmp(PID_inchar,"calc") == 0){
                int i=0;

                printf("number of processes: %i",runs);
                while(i<runs){
                    if(strcmp(Plist[i].Pname,"calc")==0){
                        Plist[i].status = "deactivated";
                        PID = Plist[i].PID;
                        printf("%i \n",PID);
                        clock_t end = clock();


                        Plist[i].e_time = end;


                        printf("Process end time: %f ticks \n",end);

                    }

                    i++;
                }


            }


             else {
            PID = atoi(PID_inchar); }
                printf("killed %d \n", PID);

                HANDLE process_to_delete = OpenProcess(PROCESS_ALL_ACCESS, TRUE, PID);

                TerminateProcess(process_to_delete,1234);

                CloseHandle(process_to_delete);


        }

         if(strcmp(token,"list")==0){
            int k;
            for(k = 0; k < Ppointer; k++) {
                printf("PID: %i \n", Plist[k].PID);

                printf("Process name: %s \n", Plist[k].Pname);

                printf("status: %s \n", Plist[k].status);
                printf("------------------");
                printf("\n");
            }

        }


        if(strcmp(token,"run") == 0) {
           char *application = strtok(NULL,s);

           printf("------------------");
           printf("\n");

            printf("Index no: %i \n",runs);
            runs++;

                 printf(application);

            PROCESS_INFORMATION pif;
            STARTUPINFO si;
            ZeroMemory(&si,sizeof(si));
            si.cb = sizeof(si);


            BOOL process = CreateProcess(
                NULL,
                application,
                NULL,
                NULL,
                FALSE,
                0,
                NULL,
                NULL,
                &si,
                &pif);



                clock_t start = clock();

                //STORING PROCESS TIME
                Plist[Ppointer].s_time = start;

                printf("Process start time: %f \n",Plist[Ppointer].s_time);

                int processID = (int)pif.dwProcessId;
                printf("Process ID: %i \n",processID);
                Plist[Ppointer].PID = (int)pif.dwProcessId;
                //PROCESS NAME
                Plist[Ppointer].Pname = malloc(100);
                strcpy(Plist[Ppointer].Pname, application);
                printf("%s \n",Plist[Ppointer].Pname);
                //PROCESS STATUS
                Plist[Ppointer].status = "active";
                printf("%s \n",Plist[Ppointer].status);



                //char ProcessName = (char)application;
                //printf(ProcessName);
                //Plist[Ppointer].Pname = (char[15])application;
                printf("PID in array: %i \n", Plist[Ppointer].PID);
                Ppointer++;

                if(process == FALSE) {

                    MessageBox(HWND_DESKTOP,"Unable to start program","",MB_OK);
                    return 1;
                }

                CloseHandle(pif.hProcess);   //Close handle to process
                CloseHandle(pif.hThread);





//            CreateProcess(NULL,ApplicationName, 0, 0, FALSE, 0, 0, 0, &si, &pi);
                printf("------------------");
                printf("\n");
         }




        if(strcmp(token,"ls") == 0) {

            printf("Following is a list commands we can execute \n \n");
            printf("add  => add [space] [1st variable] [space] [2nd variable] \n");
            printf("sub  => add [space] [1st variable] [space] [2nd variable] \n");
            printf("div  => add [space] [numerator] [space] [denominator] \n");
            printf("mult => add [space] [1st variable] [space] [2nd variable] \n");
            printf("kill => kill [PID] OR [NAME] \n");
            printf("list => lists all processes");
            printf("exit => exit program");


        }


         if(strcmp(token, "add") == 0){
            printf("An addition function \n \n");
            char *Cx = strtok(NULL, s);

            char *Cy = strtok(NULL, s);

            int x = atoi(Cx);
            int y = atoi(Cy);

            int result = x + y;

            printf("The sum is %d", result);



        }

        if(strcmp(token,"sub") == 0) {
            printf("A subtraction function \n \n");
            char *Cx = strtok(NULL,s);
            char *Cy = strtok(NULL,s);

            int x = atoi(Cx);
            int y = atoi(Cy);

            int result = x - y;

            printf("After subtraction we get: %d", result);

        }


        if(strcmp(token,"div") == 0) {
            printf("A division function \n \n");

            char *Cx = strtok(NULL,s);
            char *Cy = strtok(NULL,s);

            double x = atof(Cx);
            double y = atof(Cy);

            if(y == 0) {
                printf("Can't divide by zero");
                break;
            }

            double result = x/y;

            printf("After division we get: %lf", result);

        }

         if(strcmp(token,"mult") == 0) {
            printf("A multiplication function \n \n");

            char *Cx = strtok(NULL,s);
            char *Cy = strtok(NULL,s);

            double x = atof(Cx);
            double y = atof(Cy);

            double result = x*y;

            printf("After multiplication we get: %lf", result);

        }

        token = strtok(NULL, s);


}

    }
}




