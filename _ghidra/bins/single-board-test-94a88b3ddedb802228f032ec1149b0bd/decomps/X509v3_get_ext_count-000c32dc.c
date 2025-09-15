
int X509v3_get_ext_count(stack_st_X509_EXTENSION *x)

{
  int iVar1;
  
  if (x != (stack_st_X509_EXTENSION *)0x0) {
    iVar1 = sk_num(&x->stack);
    return iVar1;
  }
  return 0;
}

