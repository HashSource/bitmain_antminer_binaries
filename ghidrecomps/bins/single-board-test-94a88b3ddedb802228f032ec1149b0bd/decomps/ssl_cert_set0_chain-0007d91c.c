
undefined4 ssl_cert_set0_chain(int *param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (iVar1 != 0) {
    if (*(_STACK **)(iVar1 + 0xc) != (_STACK *)0x0) {
      sk_pop_free(*(_STACK **)(iVar1 + 0xc),DAT_0007d938);
    }
    *(undefined4 *)(iVar1 + 0xc) = param_2;
    return 1;
  }
  return 0;
}

