
uint obj_name_LHASH_HASH(uint *param_1)

{
  _STACK **pp_Var1;
  int iVar2;
  uint uVar3;
  code **ppcVar4;
  
  pp_Var1 = DAT_0008bab8;
  if (*DAT_0008bab8 != (_STACK *)0x0) {
    iVar2 = sk_num(*DAT_0008bab8);
    if ((int)*param_1 < iVar2) {
      ppcVar4 = (code **)sk_value(*pp_Var1,*param_1);
      uVar3 = (**ppcVar4)(param_1[2]);
      goto LAB_0008baa2;
    }
  }
  uVar3 = lh_strhash((char *)param_1[2]);
LAB_0008baa2:
  return uVar3 ^ *param_1;
}

