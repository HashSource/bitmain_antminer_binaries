
bool policy_node_match(int param_1,undefined4 *param_2,ASN1_OBJECT *param_3)

{
  int iVar1;
  ASN1_OBJECT *a;
  int iVar2;
  uint *puVar3;
  
  puVar3 = (uint *)*param_2;
  if (((*(uint *)(param_1 + 0xc) & 0x400) == 0) && (iVar1 = 0, (*puVar3 & 3) != 0)) {
    do {
      iVar2 = OPENSSL_sk_num(puVar3[3]);
      if (iVar2 <= iVar1) {
        return false;
      }
      a = (ASN1_OBJECT *)OPENSSL_sk_value(puVar3[3],iVar1);
      iVar2 = OBJ_cmp(a,param_3);
      iVar1 = iVar1 + 1;
    } while (iVar2 != 0);
    return true;
  }
  iVar1 = OBJ_cmp((ASN1_OBJECT *)puVar3[1],param_3);
  return iVar1 == 0;
}

