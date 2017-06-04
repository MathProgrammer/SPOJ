#include <stdio.h>
#define true 1

int main(void) 
{
	int a_goals, b_goals;
	
	while(true)
	{
		scanf("%d %d", &a_goals, &b_goals);
		if(a_goals == -1 || b_goals == -1)
			break;
			
		printf("%d+%d%s%d \n",a_goals, b_goals, (a_goals == 1 || b_goals == 1 ? "=" : "!="), (a_goals+b_goals));
	}
	return 0;
  }
