
X509_ATTRIBUTE * X509at_delete_attr(stack_st_X509_ATTRIBUTE *x,int loc)

{
  int iVar1;
  X509_ATTRIBUTE *pXVar2;
  
  if (((x != (stack_st_X509_ATTRIBUTE *)0x0) && (iVar1 = sk_num(&x->stack), loc < iVar1)) &&
     (-1 < loc)) {
    pXVar2 = (X509_ATTRIBUTE *)sk_delete(&x->stack,loc);
    return pXVar2;
  }
  return (X509_ATTRIBUTE *)0x0;
}

