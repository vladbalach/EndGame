void mx_printchar(char c);

static int countOfSymbols(int n) {
    int count =0;
    if(n<0) n=-n;
        while (n > 0) {
        n /= 10;
        count++;
    }
    return count;
}

void  mx_printint(int n) {
    int count = countOfSymbols(n);
    char str[count+1];
    if( n == 0) mx_printchar('0');
    if( n == -2147483648) {
        mx_printint(-214748364);
        mx_printint(8);
    }
    else {
        if( n < 0) {
            n = -n;
            mx_printchar('-');
        }
        for (int i = count-1;i>=0;i--) {
            str[i] = n % 10 + 48;
            n/=10;
        }
        str[count+1] = '\0';
        for (int i=0;i<count;i++) {
            mx_printchar(str[i]);
        }
    }
}
