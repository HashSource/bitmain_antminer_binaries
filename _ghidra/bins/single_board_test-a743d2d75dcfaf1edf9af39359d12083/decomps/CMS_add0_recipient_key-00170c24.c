
CMS_RecipientInfo *
CMS_add0_recipient_key
          (CMS_ContentInfo *cms,int nid,uchar *key,size_t keylen,uchar *id,size_t idlen,
          ASN1_GENERALIZEDTIME *date,ASN1_OBJECT *otherTypeId,ASN1_TYPE *otherType)

{
  int iVar1;
  ASN1_VALUE *val;
  ASN1_VALUE *pAVar2;
  ASN1_VALUE *pAVar3;
  ASN1_STRING *str;
  ASN1_OBJECT *aobj;
  int iVar4;
  undefined4 *puVar5;
  X509_ALGOR *alg;
  int iVar6;
  
  iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
  if (iVar1 != 0x17) {
    ERR_put_error(0x2e,0x83,0x6b,"cms_env.c",0x4f);
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
        goto LAB_00170c5a;
      }
      nid = 0x314;
    }
  }
  else {
    if ((2 < nid - 0x314U) || (*(size_t *)(&CSWTCH_9 + (nid - 0x314U) * 4) == 0)) {
      ERR_put_error(0x2e,100,0x99,"cms_env.c",0x236);
      return (CMS_RecipientInfo *)0x0;
    }
    if (keylen != *(size_t *)(&CSWTCH_9 + (nid - 0x314U) * 4)) {
      iVar1 = 0x23b;
LAB_00170c5a:
      ERR_put_error(0x2e,100,0x76,"cms_env.c",iVar1);
      return (CMS_RecipientInfo *)0x0;
    }
  }
  val = ASN1_item_new((ASN1_ITEM *)CMS_RecipientInfo_it);
  if (val == (ASN1_VALUE *)0x0) {
    ERR_put_error(0x2e,100,0x41,"cms_env.c",0x26c);
    return (CMS_RecipientInfo *)0x0;
  }
  pAVar2 = ASN1_item_new((ASN1_ITEM *)CMS_KEKRecipientInfo_it);
  *(ASN1_VALUE **)(val + 4) = pAVar2;
  if (pAVar2 != (ASN1_VALUE *)0x0) {
    *(undefined4 *)val = 2;
    if (otherTypeId != (ASN1_OBJECT *)0x0) {
      iVar6 = *(int *)(pAVar2 + 4);
      pAVar3 = ASN1_item_new((ASN1_ITEM *)CMS_OtherKeyAttribute_it);
      iVar4 = *(int *)(pAVar2 + 4);
      *(ASN1_VALUE **)(iVar6 + 8) = pAVar3;
      if (*(int *)(iVar4 + 8) == 0) goto LAB_00170ce6;
    }
    iVar1 = sk_push(*(_STACK **)(iVar1 + 8),val);
    if (iVar1 != 0) {
      str = (ASN1_STRING *)**(undefined4 **)(pAVar2 + 4);
      *(uchar **)(pAVar2 + 0x10) = key;
      *(undefined4 *)pAVar2 = 4;
      *(size_t *)(pAVar2 + 0x14) = keylen;
      ASN1_STRING_set0(str,id,idlen);
      puVar5 = *(undefined4 **)(*(int *)(pAVar2 + 4) + 8);
      *(ASN1_GENERALIZEDTIME **)(*(int *)(pAVar2 + 4) + 4) = date;
      if (puVar5 != (undefined4 *)0x0) {
        *puVar5 = otherTypeId;
        puVar5[1] = otherType;
      }
      alg = *(X509_ALGOR **)(pAVar2 + 8);
      aobj = OBJ_nid2obj(nid);
      X509_ALGOR_set0(alg,aobj,-1,(void *)0x0);
      return (CMS_RecipientInfo *)val;
    }
  }
LAB_00170ce6:
  ERR_put_error(0x2e,100,0x41,"cms_env.c",0x26c);
  ASN1_item_free(val,(ASN1_ITEM *)CMS_RecipientInfo_it);
  return (CMS_RecipientInfo *)0x0;
}

