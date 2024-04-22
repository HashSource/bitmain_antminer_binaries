
int DHparams_print(BIO *bp,DH *x)

{
  int iVar1;
  
  iVar1 = do_dh_print_isra_0(bp,x,4,0);
  return iVar1;
}

