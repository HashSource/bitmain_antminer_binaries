
undefined4 X509V3_EXT_free(int param_1,ASN1_VALUE *param_2)

{
  _STACK **pp_Var1;
  void **ppvVar2;
  void *pvVar3;
  int iVar4;
  int *local_54;
  int local_50 [15];
  
  local_54 = local_50;
  if (-1 < param_1) {
    local_50[0] = param_1;
    ppvVar2 = (void **)OBJ_bsearch_(&local_54,DAT_000c6710,0x2a,4,DAT_000c670c);
    pp_Var1 = DAT_000c6714;
    if (ppvVar2 == (void **)0x0) {
      if ((*DAT_000c6714 == (_STACK *)0x0) || (iVar4 = sk_find(*DAT_000c6714,local_50), iVar4 == -1)
         ) goto LAB_000c66f6;
      pvVar3 = sk_value(*pp_Var1,iVar4);
    }
    else {
      pvVar3 = *ppvVar2;
    }
    if (pvVar3 != (void *)0x0) {
      if (*(ASN1_ITEM **)((int)pvVar3 + 8) != (ASN1_ITEM *)0x0) {
        ASN1_item_free(param_2,*(ASN1_ITEM **)((int)pvVar3 + 8));
        return 1;
      }
      if (*(code **)((int)pvVar3 + 0x10) != (code *)0x0) {
        (**(code **)((int)pvVar3 + 0x10))(param_2);
        return 1;
      }
      ERR_put_error(0x22,0xa5,0xa8,DAT_000c6718,0x8c);
      return 0;
    }
  }
LAB_000c66f6:
  ERR_put_error(0x22,0xa5,0xa8,DAT_000c6718,0x82);
  return 0;
}

