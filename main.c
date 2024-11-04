#include <stdio.h>
#include <stdlib.h>
#include "struct_headr.h"
#include "function_struct_h.h"
std_t school[1000];
int main()
{
    char name_input[20]= {0};
    int search_press;
    int id;
    int index_found_search;
    int index_scan;
    int i;
    int x;
    int previous_press;
    int main_option;
    int skip;



    printf("\t\t\tHello on board wellcome to international school\n");
    while(1)
    {
        printf("______________________________________________________________________________\n");
        printf("***********************************KEEP GOING*******************************\n");
        printf("\t\t\"if you want to keep going in signing in system press[1]\"\n\t\"if you want to change your decision and to edit data of specific student press[2]\"\n\t\"if you want to\
 print student by name and Id press[3]\"\n\t\"if you want to search for specif student by name and Id press[4]\"\n\t\"if you\
 want to delete specif student press[5]\"\n\t\"if you want to print school press[6]\"\n\t\"if you want to show grade of specific student by name and grade press[7]\"\n\t\"if you \
 want to call student press[8]\"\n");
        printf("_______________________________________________________________________________\n");
        scanf("%d",&main_option);
        switch(main_option)
        {
        case 1://scan or entering student into system
            // index_scan=index_show();
            printf("______________________________________________________________________________\n");
            printf("***********************************KEEP GOING*******************************\n");
            scan_student_pro(school);
            break;
        case 2://edit student data
            index_scan=index_show();
            if(index_scan==0)
            {

                printf("\t\t\t\nnot found anything please enter student into system then apply what you want\n");
            }
            else
            {
                printf("pleaze enter name first: ");
                fflush(stdin);
                gets(name_input);
                printf("pleaze enter id : ");
                scanf("%d",&id);
                printf("\"let see if your data is correct or not?\"\n");
                if(student_search(school,name_input,id)==-1)
                {
                    printf("not found try with other name\n");
                }
                else
                {
                    printf("\t\t\t\"found suceessful process\"\n");
                    index_found_search=student_search(school,name_input,id);
                    printf("if you want to display previous data of this student press [1]\n\tif not press any button \n");
                    scanf("%d",&previous_press);
                    printf("\n__________________________________________________________________________\n");
                    if(previous_press==1)
                    {
                        struct_student_print_by_adress_pro(school+index_found_search);
                        edit_student_data(name_input,school,id);
                        printf("\n__________________________________________________________________________\n");
                        printf("\t\t\tthe modification is applied and the data after process: \n");
                        printf("\n__________________________________________________________________________\n");
                        printf("\"if you want to see modification and print it press [0]\n");
                        scanf("%d",&previous_press);
                        if(previous_press==0)
                        {
                            struct_student_print_by_adress_pro(school+index_found_search);
                        }
                        else
                        {
                            printf("incorrect process\n");
                        }
                    }
                    else
                    {
                        printf("\nlet modify it \n");
                        edit_student_data(name_input,school,id);
                        printf("\t\t\tthe modification is applied and the data after process: \n");
                        printf("\n__________________________________________________________________________\n");
                        printf("\"if you want to see modification and print it press [0]\n");
                        scanf("%d",&previous_press);
                        if(previous_press==0)
                        {
                            struct_student_print_by_adress_pro(school+index_found_search);
                        }
                    }
                }


                break;
            case 3://to print student by id and name
                index_scan=index_show();
                if(index_scan==0)
                {

                    printf("\t\t\t\nnot found anything please enter student into system then apply what you want\n");
                }
                else
                {
                    printf("pleaze enter name first: ");
                    fflush(stdin);
                    gets(name_input);
                    printf("pleaze enter id : ");
                    scanf("%d",&id);
                    printf("\"let see if your data is correct or not?\"\n");
                    if(student_search(school,name_input,id)==-1)
                    {
                        printf("not found try with other name\n");
                    }
                    else
                    {
                        printf("\t\t\t\"found suceessful process\"\n");
                        index_found_search=student_search(school,name_input,id);
                        struct_student_print_by_adress_pro(school+index_found_search);
                    }
                }

                break;
            case 4://to search for specific student
                index_scan=index_show();
                if(index_scan==0)
                {

                    printf("\t\t\t\nnot found anything please enter student into system then apply what you want\n");
                }
                else
                {
                    printf("pleaze enter name first: ");
                    fflush(stdin);
                    gets(name_input);
                    printf("pleaze enter id : ");
                    scanf("%d",&id);
                    printf("\"let see if your data is correct or not?\"\n");
                    if(student_search(school,name_input,id)==-1)
                    {
                        printf("not found try with other name\n");
                    }
                    else
                    {
                        printf("\t\t\t\"found suceessful process\"\n");
                        index_found_search=student_search(school,name_input,id);
                        printf("if you want to print its index in list press [1]\n\t*if you want to print all data of student press [2]\n");
                        scanf("%d",&previous_press);
                        if(previous_press==1)
                        {
                            printf("index = %d\n",index_found_search+1);
                        }
                        else if(previous_press==2)
                        {
                            struct_student_print_by_adress_pro(school+index_found_search);
                        }
                        else
                        {
                            printf("incorrect process\n");
                        }

                    }
                }

                break;
            case 5://to delete specific student
                index_scan=index_show();
                if(index_scan==0)
                {

                    printf("\t\t\t\nnot found anything please enter student into system then apply what you want\n");
                }
                else
                {
                    printf("pleaze enter name first: ");
                    fflush(stdin);
                    gets(name_input);
                    printf("pleaze enter id : ");
                    scanf("%d",&id);
                    delet_student(name_input,school,id);
                    printf("\t\t\nif you want to print school to ensure press [1]\n");
                    scanf("%d",&previous_press);
                    if(previous_press==1)
                    {
                        int x=index_show();
                        school_print_project(school,x);
                    }

                }


                break;
            case 6://to print school
                index_scan=index_show();
                if(index_scan==0)
                {

                    printf("\t\t\t\nnot found anything please enter student into system then apply what you want\n");
                }
                else
                {
                    index_found_search=index_show();
                    school_print_project(school,index_found_search);

                }

                break;
            case 7://to print grade of student by name and id
                index_scan=index_show();
                if(index_scan==0)
                {

                    printf("\t\t\t\nnot found anything please enter student into system then apply what you want\n");
                }
                else
                {
                    printf("pleaze enter name first: ");
                    fflush(stdin);
                    gets(name_input);
                    printf("pleaze enter id : ");
                    scanf("%d",&id);
                    show_all_grade_by_name(school,name_input,id);

                }

                break;
            case 8://to call student
                index_scan=index_show();
                if(index_scan==0)
                {

                    printf("\t\t\t\nnot found anything please enter student into system then apply what you want\n");
                }
                else
                {
                    printf("pleaze enter name first: ");
                    fflush(stdin);
                    gets(name_input);
                    printf("pleaze enter id : ");
                    scanf("%d",&id);
                    call_student(school,name_input,id);
                }

                break;
            default:
                printf("\t\t\t\"incorrect input please press [0] to return to previous menu\"\n");
                // printf("_______________________________________________________________________________\n");
                scanf("%d",&main_option);
                break;
            }


        }
    }

    return 0;
}
