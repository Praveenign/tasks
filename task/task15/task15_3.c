/****************************************************
*
commands used for shared library gcc program mane -o output -lm flag
to check the shared library using command ldd output

Advantage 
 Reduced excutable size
 dynamic updates
 easy version management
Disadvantage
 Dependency on library availability
 Runtime linking overhead
 Potential compatability issues
 
 ***********************************************************************/

#include<stdio.h>
#include<math.h>
int main()
{

printf("square=%lf\n",sqrt(4));
printf("cosine=%lf\n",cos(4));
printf("sine=%lf\n",sin(4));
printf("power=%lf\n",pow(4,6));
}
