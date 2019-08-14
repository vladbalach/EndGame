int mx_strlen(const char *s) {
	 if(s) {
	int i=0;
	while(s[i]!='\0')
		i++;
	return i;
	 } 
	 else return 0; 
}
