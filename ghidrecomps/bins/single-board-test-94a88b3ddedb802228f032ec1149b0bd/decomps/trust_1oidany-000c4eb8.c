
undefined4 trust_1oidany(int param_1,X509 *param_2)

{
  _STACK *p_Var1;
  int iVar2;
  ASN1_OBJECT *pAVar3;
  undefined4 uVar4;
  _STACK *p_Var5;
  int iVar6;
  _STACK **pp_Var7;
  int iVar8;
  
  pp_Var7 = *(_STACK ***)(param_2->sha1_hash + 0xc);
  if (pp_Var7 == (_STACK **)0x0) {
LAB_000c4f26:
    X509_check_purpose(param_2,-1,0);
    if ((param_2->ex_flags & 0x2000) == 0) {
      uVar4 = 3;
    }
    else {
      uVar4 = 1;
    }
    return uVar4;
  }
  p_Var5 = *pp_Var7;
  p_Var1 = pp_Var7[1];
  if (p_Var5 == (_STACK *)0x0) {
    if (p_Var1 == (_STACK *)0x0) goto LAB_000c4f26;
    iVar8 = *(int *)(param_1 + 0x10);
  }
  else {
    iVar8 = *(int *)(param_1 + 0x10);
    if (p_Var1 == (_STACK *)0x0) goto LAB_000c4ef4;
  }
  iVar6 = 0;
  while( true ) {
    iVar2 = sk_num(p_Var1);
    if (iVar2 <= iVar6) break;
    pAVar3 = (ASN1_OBJECT *)sk_value(pp_Var7[1],iVar6);
    iVar2 = OBJ_obj2nid(pAVar3);
    if (iVar8 == iVar2) {
      return 2;
    }
    p_Var1 = pp_Var7[1];
    iVar6 = iVar6 + 1;
  }
  p_Var5 = *pp_Var7;
  if (p_Var5 == (_STACK *)0x0) {
    return 3;
  }
LAB_000c4ef4:
  iVar6 = 0;
  while( true ) {
    iVar2 = sk_num(p_Var5);
    if (iVar2 <= iVar6) {
      return 3;
    }
    pAVar3 = (ASN1_OBJECT *)sk_value(*pp_Var7,iVar6);
    iVar2 = OBJ_obj2nid(pAVar3);
    if (iVar8 == iVar2) break;
    p_Var5 = *pp_Var7;
    iVar6 = iVar6 + 1;
  }
  return 1;
}

