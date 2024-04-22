
char * CRYPTO_get_lock_name(int type)

{
  _STACK **pp_Var1;
  int iVar2;
  char *pcVar3;
  
  pp_Var1 = DAT_00089758;
  if (type < 0) {
    return DAT_00089760;
  }
  if (type < 0x29) {
    return *(char **)(DAT_00089754 + type * 4);
  }
  iVar2 = sk_num(*DAT_00089758);
  if (iVar2 < type + -0x29) {
    return DAT_0008975c;
  }
  pcVar3 = (char *)sk_value(*pp_Var1,type + -0x29);
  return pcVar3;
}

