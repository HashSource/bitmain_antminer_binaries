
void * X509V3_EXT_d2i(X509_EXTENSION *ext)

{
  int *piVar1;
  void *pvVar2;
  ASN1_VALUE *pAVar3;
  int iVar4;
  ASN1_OCTET_STRING *pAVar5;
  int *local_54;
  int local_50 [15];
  
  local_50[0] = OBJ_obj2nid(ext->object);
  if ((local_50[0] != 0) && (-1 < local_50[0])) {
    local_54 = local_50;
    piVar1 = (int *)OBJ_bsearch_(&local_54,&standard_exts,0x2a,4,(cmp *)0xc656d);
    if (piVar1 == (int *)0x0) {
      if (ext_list == (_STACK *)0x0) {
        return (void *)0x0;
      }
      iVar4 = sk_find(ext_list,local_50);
      if (iVar4 == -1) {
        return (void *)0x0;
      }
      pvVar2 = sk_value(ext_list,iVar4);
    }
    else {
      pvVar2 = (void *)*piVar1;
    }
    if (pvVar2 != (void *)0x0) {
      pAVar5 = ext->value;
      local_54 = (int *)pAVar5->data;
      if (*(ASN1_ITEM **)((int)pvVar2 + 8) == (ASN1_ITEM *)0x0) {
        pvVar2 = (void *)(**(code **)((int)pvVar2 + 0x14))(0,&local_54,pAVar5->length);
        return pvVar2;
      }
      pAVar3 = ASN1_item_d2i((ASN1_VALUE **)0x0,(uchar **)&local_54,pAVar5->length,
                             *(ASN1_ITEM **)((int)pvVar2 + 8));
      return pAVar3;
    }
  }
  return (void *)0x0;
}

