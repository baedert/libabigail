// test arrays type definitions
struct S
{
  int a[5];
  char *b[7];
  double c[5][3];
  int *(*d[10])[4];
  char e[1];
};

int foo(struct S*)
{
}
