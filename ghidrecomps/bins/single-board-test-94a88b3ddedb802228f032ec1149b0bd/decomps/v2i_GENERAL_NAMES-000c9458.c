
GENERAL_NAMES *
v2i_GENERAL_NAMES(X509V3_EXT_METHOD *method,X509V3_CTX *ctx,stack_st_CONF_VALUE *nval)

{
  _STACK *st;
  CONF_VALUE *cnf;
  GENERAL_NAME *data;
  int iVar1;
  int iVar2;
  
  st = sk_new_null();
  if (st == (_STACK *)0x0) {
    ERR_put_error(0x22,0x76,0x41,DAT_000c94d0,0x197);
  }
  else {
    iVar2 = 0;
    while( true ) {
      iVar1 = sk_num(&nval->stack);
      if (iVar1 <= iVar2) break;
      cnf = (CONF_VALUE *)sk_value(&nval->stack,iVar2);
      data = v2i_GENERAL_NAME_ex((GENERAL_NAME *)0x0,method,ctx,cnf,0);
      if (data == (GENERAL_NAME *)0x0) {
        sk_pop_free(st,DAT_000c94cc);
        return (GENERAL_NAMES *)0x0;
      }
      sk_push(st,data);
      iVar2 = iVar2 + 1;
    }
  }
  return (GENERAL_NAMES *)st;
}

