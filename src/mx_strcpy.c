char *mx_strcpy(char *dst, const char *src)
{
    while(*src)
        *dst++ = *src++;
    return dst;
}
