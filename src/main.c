#include <stdio.h>
void application_title() {
  char *title = "\
In  most  applications,  buffer overruns can be quite subtle, and\n\
would probably result from dereferencing a pointer with  calcula‐\n\
ted  offset,  or  function  call result, or similar causes, which\n\
compiler woulnd’t be able to preemptively check.\n\
\n\
Runtime libraries exist, as well as other mechanisms, which  help\n\
reduce  the consequences of such behaviours, although is possible\n\
to overwrite selectively sensitive addresses, such as return  ad‐\n\
dress of the running function, which is stored on stack.\n\
\n\
This  minimal  example prepares two char arrays  of size 10+1 for\n\
null char termination. If the OS places  them  adjacent  to  each\n\
other,  a  simple  write beyond boundary will write into the each\n\
other’s content, as can probably demonstrated on you  architecure\n\
by running this 4 liner snippet.\n\n";
  printf(title);
}
void check(char* title, char *c1, char *c2) {
  printf(title);
  printf("  %p: <%s>\n", &c1, c1);
  printf("  %p: <%s>\n", &c2, c2);
  printf("\n");
}
int main() {
  application_title();
  char c1[11] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '\0'};
  char c2[11] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', '\0'};
  check("c1 & c2 at initializaion:\n", c1, c2);
  // Writing bassed arrays ends.
  c1[-5] = '7';  // Writing digit 7 into c1 underrunned
                 // probably goes into c2.
  c2[+15] = 'x'; // Writing character x into c2 overunned
                 // probably goes into c1
  check("c1 & c2 after overruns:\n", c1, c2);
}