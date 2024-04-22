
CMS_RecipientInfo *
CMS_add0_recipient_key
          (CMS_ContentInfo *cms,int nid,uchar *key,size_t keylen,uchar *id,size_t idlen,
          ASN1_GENERALIZEDTIME *date,ASN1_OBJECT *otherTypeId,ASN1_TYPE *otherType)

{
  int iVar1;
  undefined4 *val;
  undefined4 *puVar2;
  ASN1_VALUE *pAVar3;
  ASN1_STRING *str;
  ASN1_OBJECT *aobj;
  size_t sVar4;
  int iVar5;
  ASN1_OBJECT **ppAVar6;
  X509_ALGOR *alg;
  int iVar7;
  
  iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
  if (iVar1 != 0x17) {
    ERR_put_error(0x2e,0x83,0x6b,DAT_000d5af4,0x4f);
    return (CMS_RecipientInfo *)0x0;
  }
  iVar1 = *(int *)(cms + 4);
  if (iVar1 == 0) {
    return (CMS_RecipientInfo *)0x0;
  }
  if (nid == 0) {
    if (keylen == 0x18) {
      nid = 0x315;
    }
    else if (keylen == 0x20) {
      nid = 0x316;
    }
    else {
      if (keylen != 0x10) {
        iVar1 = 0x22c;
        goto LAB_000d59d6;
      }
      nid = 0x314;
    }
  }
  else {
    if ((2 < nid - 0x314U) || (sVar4 = *(size_t *)(DAT_000d5af8 + (nid - 0x314U) * 4), sVar4 == 0))
    {
      ERR_put_error(0x2e,100,0x99,DAT_000d5af4,0x236);
      return (CMS_RecipientInfo *)0x0;
    }
    if (keylen != sVar4) {
      iVar1 = 0x23b;
LAB_000d59d6:
      ERR_put_error(0x2e,100,0x76,DAT_000d5af4,iVar1);
      return (CMS_RecipientInfo *)0x0;
    }
  }
  val = (undefined4 *)ASN1_item_new(DAT_000d5afc);
  if (val == (undefined4 *)0x0) {
    ERR_put_error(0x2e,100,0x41,DAT_000d5af4,0x26c);
    return (CMS_RecipientInfo *)0x0;
  }
  puVar2 = (undefined4 *)ASN1_item_new(DAT_000d5b00);
  val[1] = puVar2;
  if (puVar2 != (undefined4 *)0x0) {
    *val = 2;
    if (otherTypeId != (ASN1_OBJECT *)0x0) {
      iVar7 = puVar2[1];
      pAVar3 = ASN1_item_new(DAT_000d5b04);
      iVar5 = puVar2[1];
      *(ASN1_VALUE **)(iVar7 + 8) = pAVar3;
      if (*(int *)(iVar5 + 8) == 0) goto LAB_000d5a62;
    }
    iVar1 = sk_push(*(_STACK **)(iVar1 + 8),val);
    if (iVar1 != 0) {
      str = *(ASN1_STRING **)puVar2[1];
      puVar2[4] = key;
      *puVar2 = 4;
      puVar2[5] = keylen;
      ASN1_STRING_set0(str,id,idlen);
      ppAVar6 = *(ASN1_OBJECT ***)(puVar2[1] + 8);
      *(ASN1_GENERALIZEDTIME **)(puVar2[1] + 4) = date;
      if (ppAVar6 != (ASN1_OBJECT **)0x0) {
        *ppAVar6 = otherTypeId;
        ppAVar6[1] = (ASN1_OBJECT *)otherType;
      }
      alg = (X509_ALGOR *)puVar2[2];
      aobj = OBJ_nid2obj(nid);
      X509_ALGOR_set0(alg,aobj,-1,(void *)0x0);
      return (CMS_RecipientInfo *)val;
    }
  }
LAB_000d5a62:
  ERR_put_error(0x2e,100,0x41,DAT_000d5af4,0x26c);
  ASN1_item_free((ASN1_VALUE *)val,DAT_000d5afc);
  return (CMS_RecipientInfo *)0x0;
}

