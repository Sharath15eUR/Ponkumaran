#include <stdio.h>
typedef struct
{ int A;
  char B;
  char C;
} InfoData;
int main(int argc, char *argv[])
{
	printf("\n Size of Structure = %d\n\n",sizeof(InfoData));
	return 0;
}
