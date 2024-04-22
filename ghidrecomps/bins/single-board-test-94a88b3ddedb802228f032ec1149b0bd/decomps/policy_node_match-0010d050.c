
int policy_node_match(int param_1,uint **param_2,ASN1_OBJECT *param_3)

{
  uint uVar1;
  int iVar2;
  ASN1_OBJECT *a;
  int iVar3;
  uint *puVar4;
  
  puVar4 = *param_2;
  if (((*(uint *)(param_1 + 0xc) & 0x400) == 0) && (iVar2 = 0, (*puVar4 & 3) != 0)) {
    do {
      iVar3 = sk_num((_STACK *)puVar4[3]);
      if (iVar3 <= iVar2) {
        return 0;
      }
      a = (ASN1_OBJECT *)sk_value((_STACK *)puVar4[3],iVar2);
      iVar3 = OBJ_cmp(a,param_3);
      iVar2 = iVar2 + 1;
    } while (iVar3 != 0);
    return 1;
  }
  uVar1 = OBJ_cmp((ASN1_OBJECT *)puVar4[1],param_3);
  iVar2 = 1 - uVar1;
  if (1 < uVar1) {
    iVar2 = 0;
  }
  return iVar2;
}

