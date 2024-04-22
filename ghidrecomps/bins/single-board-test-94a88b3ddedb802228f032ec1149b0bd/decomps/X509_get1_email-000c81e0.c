
stack_st_OPENSSL_STRING * X509_get1_email(X509 *x)

{
  _STACK *st;
  X509_NAME *pXVar1;
  stack_st_OPENSSL_STRING *psVar2;
  
  st = (_STACK *)X509_get_ext_d2i(x,0x55,(int *)0x0,(int *)0x0);
  pXVar1 = X509_get_subject_name(x);
  psVar2 = (stack_st_OPENSSL_STRING *)get_email(pXVar1,st);
  sk_pop_free(st,GENERAL_NAME_free + 1);
  return psVar2;
}

