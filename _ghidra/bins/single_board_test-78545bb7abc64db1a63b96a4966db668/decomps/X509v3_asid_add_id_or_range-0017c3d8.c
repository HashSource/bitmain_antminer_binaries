
undefined4 X509v3_asid_add_id_or_range(int *param_1,int param_2,_union_929 param_3,int param_4)

{
  ASIdOrRange *a;
  ASRange *pAVar1;
  int iVar2;
  ASIdentifierChoice *pAVar3;
  ASN1_NULL *pAVar4;
  int *piVar5;
  _union_929 *p_Var6;
  
  if (param_1 == (int *)0x0) {
    return 0;
  }
  if (param_2 == 0) {
    piVar5 = (int *)*param_1;
  }
  else {
    if (param_2 != 1) {
      return 0;
    }
    piVar5 = (int *)param_1[1];
    param_1 = param_1 + 1;
  }
  if (piVar5 == (int *)0x0) {
    pAVar3 = ASIdentifierChoice_new();
    *param_1 = (int)pAVar3;
    if (pAVar3 == (ASIdentifierChoice *)0x0) {
      return 0;
    }
    pAVar4 = (ASN1_NULL *)OPENSSL_sk_new(0x17bbb9);
    (pAVar3->u).inherit = pAVar4;
    if (((undefined4 *)*param_1)[1] == 0) {
      return 0;
    }
    *(undefined4 *)*param_1 = 1;
  }
  else if (*piVar5 == 0) {
    return 0;
  }
  a = ASIdOrRange_new();
  if (a == (ASIdOrRange *)0x0) {
    return 0;
  }
  if (param_4 == 0) {
    a->type = 0;
    a->u = param_3;
  }
  else {
    a->type = 1;
    pAVar1 = ASRange_new();
    (a->u).range = pAVar1;
    if (pAVar1 == (ASRange *)0x0) goto LAB_0017c43a;
    ASN1_INTEGER_free(pAVar1->min);
    p_Var6 = (_union_929 *)(a->u).range;
    *p_Var6 = param_3;
    ASN1_INTEGER_free(p_Var6[1].id);
    ((a->u).id)->type = param_4;
  }
  iVar2 = OPENSSL_sk_push(*(undefined4 *)(*param_1 + 4),a);
  if (iVar2 != 0) {
    return 1;
  }
LAB_0017c43a:
  ASIdOrRange_free(a);
  return 0;
}

