
int X509_VERIFY_PARAM_add0_policy(X509_VERIFY_PARAM *param,ASN1_OBJECT *policy)

{
  _STACK *st;
  int iVar1;
  
  st = &param->policies->stack;
  if (st == (_STACK *)0x0) {
    st = sk_new_null();
    param->policies = (stack_st_ASN1_OBJECT *)st;
    if (st == (_STACK *)0x0) {
      return 0;
    }
  }
  iVar1 = sk_push(st,policy);
  if (iVar1 != 0) {
    iVar1 = 1;
  }
  return iVar1;
}

