#ifndef function_struct_h
#define function_struct_h
void struct_student_print_by_value(struct student s);
void struct_student_print_by_adress(struct student *ps);
struct student student_scan_by_value(void);
void student_scan_by_address(struct student*ps);
void school_print_by_adress(struct student arr[],int size);
int school_search_max_age(std_t p[],int size);
int school_search_max_grade(std_t p[],int size);
int school_search_min_grade(std_t p[],int size);
void selection_sort_struct_name(std_t p[],int size);
void selection_sort_struct_grade(std_t p[],int size);
void selection_sort_struct_age(std_t p[],int size);
void struct_student_print_by_adress_pro(std_t *ps);
void scan_student_pro(std_t *p);
int index_show(void);
void edit_student_data(char*str,std_t*p,int id);
int student_search(std_t*p,char*str,int id);
void school_print_project(std_t*p,int size);
void delet_student(char*str,std_t*p,int id);
void show_all_grade_by_name(std_t *p,char*str,int id);
void struct_student_print_by_adress_pro_school(std_t *ps,int counter);
void call_student(std_t *p,char*str,int id);
#endif
