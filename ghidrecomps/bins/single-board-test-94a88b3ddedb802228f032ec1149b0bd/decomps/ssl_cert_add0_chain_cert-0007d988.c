
int ssl_cert_add0_chain_cert(int *param_1,void *param_2)

{
  _STACK *st;
  int iVar1;
  
  iVar1 = *param_1;
  if (iVar1 == 0) {
LAB_0007d9b0:
    iVar1 = 0;
  }
  else {
    st = *(_STACK **)(iVar1 + 0xc);
    if (st == (_STACK *)0x0) {
      st = sk_new_null();
      *(_STACK **)(iVar1 + 0xc) = st;
      if (st == (_STACK *)0x0) goto LAB_0007d9b0;
    }
    iVar1 = sk_push(st,param_2);
    if (iVar1 != 0) {
      iVar1 = 1;
    }
  }
  return iVar1;
}

