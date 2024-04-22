
void failoveronly(undefined4 param_1,undefined4 param_2,byte *param_3)

{
  byte bVar1;
  __int32_t **pp_Var2;
  
  if ((param_3 != (byte *)0x0) && (bVar1 = *param_3, bVar1 != 0)) {
    pp_Var2 = __ctype_tolower_loc();
    bVar1 = *(byte *)(*pp_Var2 + bVar1);
    *param_3 = bVar1;
    if (bVar1 == 0x74 || bVar1 == 0x66) {
      opt_fail_only = bVar1 == 0x74;
      message(param_1,0x4d,opt_fail_only,0);
      return;
    }
    message(param_1,0x4c,0);
    return;
  }
  message(param_1,0x4b,0);
  return;
}

