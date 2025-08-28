
uint obj_name_LHASH_HASH(uint *param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  if (name_funcs_stack != (_STACK *)0x0) {
    iVar1 = sk_num(name_funcs_stack);
    if ((int)*param_1 < iVar1) {
      puVar3 = (undefined4 *)sk_value(name_funcs_stack,*param_1);
      uVar2 = (*(code *)*puVar3)(param_1[2]);
      goto LAB_0008baa2;
    }
  }
  uVar2 = lh_strhash((char *)param_1[2]);
LAB_0008baa2:
  return uVar2 ^ *param_1;
}

