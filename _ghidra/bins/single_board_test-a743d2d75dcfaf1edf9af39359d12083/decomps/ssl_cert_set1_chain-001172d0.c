
int ssl_cert_set1_chain(int *param_1,int param_2)

{
  _STACK *st;
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = *param_1;
    if (iVar1 != 0) {
      if (*(_STACK **)(iVar1 + 0xc) != (_STACK *)0x0) {
        sk_pop_free(*(_STACK **)(iVar1 + 0xc),(func *)0x1579c9);
      }
      *(undefined4 *)(iVar1 + 0xc) = 0;
      return 1;
    }
  }
  else {
    st = (_STACK *)X509_chain_up_ref(param_2);
    if (st == (_STACK *)0x0) {
      return 0;
    }
    iVar1 = *param_1;
    if (iVar1 != 0) {
      if (*(_STACK **)(iVar1 + 0xc) != (_STACK *)0x0) {
        sk_pop_free(*(_STACK **)(iVar1 + 0xc),(func *)0x1579c9);
      }
      *(_STACK **)(iVar1 + 0xc) = st;
      return 1;
    }
    sk_pop_free(st,(func *)0x1579c9);
    iVar1 = 0;
  }
  return iVar1;
}

