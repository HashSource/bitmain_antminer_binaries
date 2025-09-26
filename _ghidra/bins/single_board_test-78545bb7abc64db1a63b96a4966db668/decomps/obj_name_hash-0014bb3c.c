
uint obj_name_hash(uint *param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  if (name_funcs_stack != 0) {
    iVar1 = OPENSSL_sk_num();
    if ((int)*param_1 < iVar1) {
      puVar3 = (undefined4 *)OPENSSL_sk_value(name_funcs_stack);
      uVar2 = (*(code *)*puVar3)(param_1[2]);
      return uVar2 ^ *param_1;
    }
  }
  uVar2 = openssl_lh_strcasehash(param_1[2]);
  return uVar2 ^ *param_1;
}

