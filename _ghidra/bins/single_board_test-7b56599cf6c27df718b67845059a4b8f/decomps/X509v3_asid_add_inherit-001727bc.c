
bool X509v3_asid_add_inherit(undefined4 *param_1,int param_2)

{
  ASIdentifierChoice *pAVar1;
  ASN1_NULL *pAVar2;
  int *piVar3;
  
  if (param_1 != (undefined4 *)0x0) {
    if (param_2 == 0) {
      piVar3 = (int *)*param_1;
    }
    else {
      if (param_2 != 1) {
        return false;
      }
      piVar3 = (int *)param_1[1];
      param_1 = param_1 + 1;
    }
    if (piVar3 != (int *)0x0) {
      return *piVar3 == 0;
    }
    pAVar1 = ASIdentifierChoice_new();
    *param_1 = pAVar1;
    if (pAVar1 != (ASIdentifierChoice *)0x0) {
      pAVar2 = ASN1_NULL_new();
      (pAVar1->u).inherit = pAVar2;
      if (pAVar2 != (ASN1_NULL *)0x0) {
        *(undefined4 *)*param_1 = 0;
        return true;
      }
    }
  }
  return false;
}

