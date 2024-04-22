
undefined4 ssl_cert_add1_chain_cert(int *param_1,void *param_2)

{
  _STACK *st;
  int iVar1;
  
  iVar1 = *param_1;
  if (iVar1 != 0) {
    st = *(_STACK **)(iVar1 + 0xc);
    if (st == (_STACK *)0x0) {
      st = sk_new_null();
      *(_STACK **)(iVar1 + 0xc) = st;
      if (st == (_STACK *)0x0) {
        return 0;
      }
    }
    iVar1 = sk_push(st,param_2);
    if (iVar1 != 0) {
      CRYPTO_add_lock((int *)((int)param_2 + 0x10),1,3,DAT_0007d9f4,0x242);
      return 1;
    }
  }
  return 0;
}

