#include "file_to_str.h"

int mx_strlen(const char *s);
char *mx_strcpy(char *dst, const char *src);
char *mx_strnew(const int size);

char *mx_strdup(const char *str) {
    
     if (*str) {
        char *str2 = mx_strnew(mx_strlen(str));
         
         mx_strcpy(str2, str);
        return str2;
     } 
     else {
         return 0;
     }
 }
