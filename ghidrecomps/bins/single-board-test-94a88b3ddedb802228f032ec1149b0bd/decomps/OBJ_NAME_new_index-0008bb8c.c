
int OBJ_NAME_new_index(hash_func *hash_func,cmp_func *cmp_func,free_func *free_func)

{
  _STACK **pp_Var1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  _STACK *p_Var5;
  int iVar6;
  undefined4 *data;
  hash_func **pphVar7;
  int iVar8;
  
  pp_Var1 = DAT_0008bc60;
  p_Var5 = *DAT_0008bc60;
  if (p_Var5 == (_STACK *)0x0) {
    CRYPTO_mem_ctrl(3);
    p_Var5 = sk_new_null();
    *pp_Var1 = p_Var5;
    CRYPTO_mem_ctrl(2);
    p_Var5 = *pp_Var1;
    if (p_Var5 == (_STACK *)0x0) {
      return 0;
    }
  }
  piVar2 = DAT_0008bc64;
  iVar8 = *DAT_0008bc64;
  *DAT_0008bc64 = iVar8 + 1;
  iVar6 = sk_num(p_Var5);
  uVar4 = DAT_0008bc70;
  uVar3 = DAT_0008bc68;
  if (iVar6 < *piVar2) {
    do {
      iVar6 = iVar6 + 1;
      CRYPTO_mem_ctrl(3);
      data = (undefined4 *)CRYPTO_malloc(0xc,DAT_0008bc6c,0x57);
      CRYPTO_mem_ctrl(2);
      if (data == (undefined4 *)0x0) {
        ERR_put_error(8,0x6a,0x41,DAT_0008bc6c,0x5a);
        return 0;
      }
      data[2] = 0;
      *data = uVar4;
      data[1] = uVar3;
      CRYPTO_mem_ctrl(3);
      sk_push(*pp_Var1,data);
      CRYPTO_mem_ctrl(2);
    } while (iVar6 < *piVar2);
  }
  pphVar7 = (hash_func **)sk_value(*pp_Var1,iVar8);
  if (hash_func != (hash_func *)0x0) {
    *pphVar7 = hash_func;
  }
  if (cmp_func != (cmp_func *)0x0) {
    pphVar7[1] = (hash_func *)cmp_func;
  }
  if (free_func != (free_func *)0x0) {
    pphVar7[2] = (hash_func *)free_func;
  }
  return iVar8;
}

