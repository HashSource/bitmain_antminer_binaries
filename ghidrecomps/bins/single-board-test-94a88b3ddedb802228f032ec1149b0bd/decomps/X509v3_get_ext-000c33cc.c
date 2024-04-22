
X509_EXTENSION * X509v3_get_ext(stack_st_X509_EXTENSION *x,int loc)

{
  int iVar1;
  X509_EXTENSION *pXVar2;
  
  if (((x != (stack_st_X509_EXTENSION *)0x0) && (iVar1 = sk_num(&x->stack), loc < iVar1)) &&
     (-1 < loc)) {
    pXVar2 = (X509_EXTENSION *)sk_value(&x->stack,loc);
    return pXVar2;
  }
  return (X509_EXTENSION *)0x0;
}

