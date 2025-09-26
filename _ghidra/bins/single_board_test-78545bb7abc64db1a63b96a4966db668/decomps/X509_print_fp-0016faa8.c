
int X509_print_fp(FILE *bp,X509 *x)

{
  int iVar1;
  
  iVar1 = X509_print_ex_fp(bp,x,0,0);
  return iVar1;
}

