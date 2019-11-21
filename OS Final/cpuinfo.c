#include<stdio.h>
#include <stdlib.h>

int main()
{	
	int ch;
	printf("1.Print Kernel version");
	printf("\n2.Print CPU info");
	printf("\n3.Print Memory info");
	printf("\nEnter your choice : ");	scanf("%d",&ch);
	
	if(ch==1)
	{
		system("cat /proc/version | awk 'BEGIN { echo \"Kernel version :\"}{print $1,$3}'");
	}
	else
	{
		if(ch==2)
		{
						
			system("cat /proc/cpuinfo|awk 'NR==5'|awk ' BEGIN{ print \"CPU Type :\"}{print $4,$5,$6,$8,$9}'");
			system("cat /proc/cpuinfo|awk 'NR==4'|awk ' BEGIN{ print \"Model :\"}{print $3}'");		
		}
		else
		{
			system("cat /proc/meminfo|awk 'NR==1'|awk ' BEGIN{ print \"Configured Memory :\"}{print $2,$3}'");
			system("cat /proc/meminfo|awk 'NR==2'|awk ' BEGIN{ print \"Used Memory :\"}{print $2,$3}'");
			system("cat /proc/meminfo|awk 'NR==3'|awk ' BEGIN{ print \"Available Memory :\"}{print $2,$3}'");
		}
	}

	return 0;
}