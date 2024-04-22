
int ASN1_STRING_TABLE_add(int param_1,long param_2,long param_3,ulong param_4,ulong param_5)

{
  bool bVar1;
  _STACK **pp_Var2;
  _STACK **pp_Var3;
  int *data;
  int iVar4;
  _STACK *p_Var5;
  int local_3c [6];
  
  pp_Var2 = DAT_0010a57c;
  if (*DAT_0010a57c == (_STACK *)0x0) {
    p_Var5 = sk_new(DAT_0010a58c);
    *pp_Var2 = p_Var5;
    if (p_Var5 == (_STACK *)0x0) {
      iVar4 = 0xf2;
      goto LAB_0010a564;
    }
  }
  local_3c[0] = param_1;
  data = (int *)OBJ_bsearch_(local_3c,DAT_0010a584,0x13,0x14,DAT_0010a580);
  pp_Var3 = DAT_0010a57c;
  if ((data == (int *)0x0) &&
     (((*pp_Var2 == (_STACK *)0x0 || (iVar4 = sk_find(*pp_Var2,local_3c), iVar4 < 0)) ||
      (data = (int *)sk_value(*pp_Var3,iVar4), data == (int *)0x0)))) {
    data = (int *)CRYPTO_malloc(0x14,DAT_0010a588,0xf6);
    if (data == (int *)0x0) {
      iVar4 = 0xf8;
LAB_0010a564:
      ERR_put_error(0xd,0x81,0x41,DAT_0010a588,iVar4);
      return 0;
    }
    *data = param_1;
    data[4] = param_5 & 0xfffffffe | 1;
    bVar1 = true;
  }
  else {
    bVar1 = false;
    data[4] = param_5 & 0xfffffffe | data[4] & 1U;
  }
  data[3] = param_4;
  if (param_2 != -1) {
    data[1] = param_2;
  }
  if (param_3 != -1) {
    data[2] = param_3;
  }
  if (bVar1) {
    sk_push(*pp_Var2,data);
  }
  return 1;
}

