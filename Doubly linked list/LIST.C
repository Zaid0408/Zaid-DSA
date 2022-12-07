  
  #include<stdio.h>
  #include<string.h>
  int main()
  {
	char str1[100],str2[100],str3[100],str4[100];
	int i,j;
	printf("enter the first name\n");
	gets(str1);
	printf("enter the last name\n");
	gets(str2);
	printf("enter the last name\n");
	gets(str3);
    for(i=0;i<strlen(str1);i++)
	{
		for(j=strlen(str1);j<strlen(str2);j++)
		{
			str4[100]=str1[i]+str2[j];
		}
	}
	printf("%s",str3);
  }