
void * X509V3_EXT_d2i(X509_EXTENSION *ext)

{
  _STACK **pp_Var1;
  void **ppvVar2;
  void *pvVar3;
  ASN1_VALUE *pAVar4;
  int iVar5;
  ASN1_OCTET_STRING *pAVar6;
  int *local_54;
  int local_50 [15];
  
  local_50[0] = OBJ_obj2nid(ext->object);
  if ((local_50[0] != 0) && (-1 < local_50[0])) {
    local_54 = local_50;
    ppvVar2 = (void **)OBJ_bsearch_(&local_54,DAT_000c6924,0x2a,4,DAT_000c6920);
    pp_Var1 = DAT_000c6928;
    if (ppvVar2 == (void **)0x0) {
      if (*DAT_000c6928 == (_STACK *)0x0) {
        return (void *)0x0;
      }
      iVar5 = sk_find(*DAT_000c6928,local_50);
      if (iVar5 == -1) {
        return (void *)0x0;
      }
      pvVar3 = sk_value(*pp_Var1,iVar5);
    }
    else {
      pvVar3 = *ppvVar2;
    }
    if (pvVar3 != (void *)0x0) {
      pAVar6 = ext->value;
      local_54 = (int *)pAVar6->data;
      if (*(ASN1_ITEM **)((int)pvVar3 + 8) == (ASN1_ITEM *)0x0) {
        pvVar3 = (void *)(**(code **)((int)pvVar3 + 0x14))(0,&local_54,pAVar6->length);
        return pvVar3;
      }
      pAVar4 = ASN1_item_d2i((ASN1_VALUE **)0x0,(uchar **)&local_54,pAVar6->length,
                             *(ASN1_ITEM **)((int)pvVar3 + 8));
      return pAVar4;
    }
  }
  return (void *)0x0;
}

