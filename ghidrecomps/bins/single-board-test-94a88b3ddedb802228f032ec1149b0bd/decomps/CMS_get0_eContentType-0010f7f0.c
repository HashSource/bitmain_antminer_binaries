
ASN1_OBJECT * CMS_get0_eContentType(CMS_ContentInfo *cms)

{
  int iVar1;
  ASN1_OBJECT *pAVar2;
  
  iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
  if (iVar1 == 0x19) {
LAB_0010f83e:
    pAVar2 = *(ASN1_OBJECT **)(*(int *)(cms + 4) + 8);
  }
  else {
    if (iVar1 < 0x1a) {
      if (iVar1 == 0x16) goto LAB_0010f83e;
      if (iVar1 != 0x17) {
LAB_0010f812:
        ERR_put_error(0x2e,0x82,0x98,DAT_0010f850,0x10c);
        return (ASN1_OBJECT *)0x0;
      }
    }
    else {
      if (iVar1 == 0xcd) {
        pAVar2 = *(ASN1_OBJECT **)(*(int *)(cms + 4) + 0x14);
        goto LAB_0010f834;
      }
      if (iVar1 != 0x312) {
        if (iVar1 != 0x1a) goto LAB_0010f812;
        pAVar2 = *(ASN1_OBJECT **)(*(int *)(cms + 4) + 4);
        goto LAB_0010f834;
      }
    }
    pAVar2 = *(ASN1_OBJECT **)(*(int *)(cms + 4) + 0xc);
  }
LAB_0010f834:
  if (pAVar2 != (ASN1_OBJECT *)0x0) {
    pAVar2 = (ASN1_OBJECT *)pAVar2->sn;
  }
  return pAVar2;
}

