
stack_st_OPENSSL_STRING * X509_REQ_get1_email(X509_REQ *x)

{
  _STACK *st;
  _STACK *st_00;
  stack_st_OPENSSL_STRING *psVar1;
  
  st = &X509_REQ_get_extensions(x)->stack;
  st_00 = (_STACK *)X509V3_get_d2i((stack_st_X509_EXTENSION *)st,0x55,(int *)0x0,(int *)0x0);
  psVar1 = (stack_st_OPENSSL_STRING *)get_email(x->req_info->subject,st_00);
  sk_pop_free(st_00,GENERAL_NAME_free + 1);
  sk_pop_free(st,X509_EXTENSION_free + 1);
  return psVar1;
}

