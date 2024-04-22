
void names_lh_free_LHASH_DOALL(_STACK **param_1)

{
  _STACK **pp_Var1;
  int *ptr;
  _STACK *p_Var2;
  int iVar3;
  void *pvVar4;
  uint local_20 [2];
  _STACK *local_18;
  
  pp_Var1 = DAT_0008bb50;
  if (param_1 != (_STACK **)0x0) {
    if (((int)DAT_0008bb50[1] < 0) || (DAT_0008bb50[1] == *param_1)) {
      local_18 = param_1[2];
      if ((_LHASH *)DAT_0008bb50[2] != (_LHASH *)0x0) {
        local_20[0] = (uint)*param_1 & 0xffff7fff;
        ptr = (int *)lh_delete((_LHASH *)DAT_0008bb50[2],local_20);
        if (ptr != (int *)0x0) {
          p_Var2 = *pp_Var1;
          if (p_Var2 != (_STACK *)0x0) {
            iVar3 = sk_num(p_Var2);
            if (*ptr < iVar3) {
              pvVar4 = sk_value(*pp_Var1,*ptr);
              (**(code **)((int)pvVar4 + 8))(ptr[2],*ptr,ptr[3]);
            }
          }
          CRYPTO_free(ptr);
        }
      }
    }
  }
  return;
}

