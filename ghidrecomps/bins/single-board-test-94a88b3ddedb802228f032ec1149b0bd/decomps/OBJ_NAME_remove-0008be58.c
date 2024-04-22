
int OBJ_NAME_remove(char *name,int type)

{
  _STACK **pp_Var1;
  int *ptr;
  _STACK *p_Var2;
  int iVar3;
  void *pvVar4;
  uint local_20 [2];
  char *local_18;
  
  pp_Var1 = DAT_0008beac;
  if ((_LHASH *)DAT_0008beac[2] != (_LHASH *)0x0) {
    local_20[0] = type & 0xffff7fff;
    local_18 = name;
    ptr = (int *)lh_delete((_LHASH *)DAT_0008beac[2],local_20);
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
      return 1;
    }
  }
  return 0;
}

