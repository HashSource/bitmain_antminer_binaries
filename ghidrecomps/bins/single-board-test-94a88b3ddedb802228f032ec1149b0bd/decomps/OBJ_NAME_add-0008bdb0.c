
int OBJ_NAME_add(char *name,int type,char *data)

{
  _STACK **pp_Var1;
  uint *data_00;
  int *ptr;
  int iVar2;
  _LHASH *p_Var3;
  void *pvVar4;
  
  pp_Var1 = DAT_0008be48;
  if (DAT_0008be48[2] == (_STACK *)0x0) {
    CRYPTO_mem_ctrl(3);
    p_Var3 = lh_new(DAT_0008be54,DAT_0008be50);
    pp_Var1[2] = (_STACK *)p_Var3;
    CRYPTO_mem_ctrl(2);
    if (pp_Var1[2] == (_STACK *)0x0) {
      return 0;
    }
  }
  data_00 = (uint *)CRYPTO_malloc(0x10,DAT_0008be4c,0xbf);
  if (data_00 == (uint *)0x0) {
    return 0;
  }
  *data_00 = type & 0xffff7fff;
  data_00[1] = type & 0x8000;
  data_00[2] = (uint)name;
  data_00[3] = (uint)data;
  ptr = (int *)lh_insert((_LHASH *)pp_Var1[2],data_00);
  pp_Var1 = DAT_0008be48;
  if (ptr == (int *)0x0) {
    iVar2 = 1 - DAT_0008be48[2][4].num_alloc;
    if (1 < (uint)DAT_0008be48[2][4].num_alloc) {
      iVar2 = 0;
    }
    return iVar2;
  }
  if (*DAT_0008be48 != (_STACK *)0x0) {
    iVar2 = sk_num(*DAT_0008be48);
    if (*ptr < iVar2) {
      pvVar4 = sk_value(*pp_Var1,*ptr);
      (**(code **)((int)pvVar4 + 8))(ptr[2],*ptr,ptr[3]);
    }
  }
  CRYPTO_free(ptr);
  return 1;
}

