
CMS_RecipientInfo *
CMS_add0_recipient_key
          (CMS_ContentInfo *cms,int nid,uchar *key,size_t keylen,uchar *id,size_t idlen,
          ASN1_GENERALIZEDTIME *date,ASN1_OBJECT *otherTypeId,ASN1_TYPE *otherType)

{
  int iVar1;
  ASN1_VALUE *pAVar2;
  ASN1_VALUE *pAVar3;
  ASN1_STRING *str;
  ASN1_OBJECT *aobj;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  ASN1_VALUE *val;
  X509_ALGOR *alg;
  
  iVar1 = cms_get0_enveloped(cms);
  if (iVar1 == 0) {
    val = (ASN1_VALUE *)0x0;
    goto LAB_0018fa58;
  }
  if (nid != 0) {
    if ((nid - 0x314U < 3) && (*(size_t *)(&CSWTCH_7 + (nid - 0x314U) * 4) != 0)) {
      if (keylen == *(size_t *)(&CSWTCH_7 + (nid - 0x314U) * 4)) goto LAB_0018f9b0;
      iVar1 = 0x20a;
LAB_0018f974:
      iVar4 = 0x76;
    }
    else {
      iVar1 = 0x205;
      iVar4 = 0x99;
    }
    ERR_put_error(0x2e,100,iVar4,"crypto/cms/cms_env.c",iVar1);
    val = (ASN1_VALUE *)0x0;
    goto LAB_0018fa58;
  }
  if (keylen == 0x18) {
    nid = 0x315;
  }
  else if (keylen == 0x20) {
    nid = 0x316;
  }
  else {
    if (keylen != 0x10) {
      iVar1 = 0x1fb;
      goto LAB_0018f974;
    }
    nid = 0x314;
  }
LAB_0018f9b0:
  val = ASN1_item_new((ASN1_ITEM *)CMS_RecipientInfo_it);
  if (val != (ASN1_VALUE *)0x0) {
    pAVar2 = ASN1_item_new((ASN1_ITEM *)CMS_KEKRecipientInfo_it);
    *(ASN1_VALUE **)(val + 4) = pAVar2;
    if (pAVar2 != (ASN1_VALUE *)0x0) {
      *(undefined4 *)val = 2;
      if (otherTypeId != (ASN1_OBJECT *)0x0) {
        iVar4 = *(int *)(pAVar2 + 4);
        pAVar3 = ASN1_item_new((ASN1_ITEM *)CMS_OtherKeyAttribute_it);
        iVar5 = *(int *)(pAVar2 + 4);
        *(ASN1_VALUE **)(iVar4 + 8) = pAVar3;
        if (*(int *)(iVar5 + 8) == 0) goto LAB_0018fa44;
      }
      iVar1 = OPENSSL_sk_push(*(undefined4 *)(iVar1 + 8),val);
      if (iVar1 != 0) {
        str = (ASN1_STRING *)**(undefined4 **)(pAVar2 + 4);
        *(uchar **)(pAVar2 + 0x10) = key;
        *(size_t *)(pAVar2 + 0x14) = keylen;
        *(undefined4 *)pAVar2 = 4;
        ASN1_STRING_set0(str,id,idlen);
        puVar6 = *(undefined4 **)(*(int *)(pAVar2 + 4) + 8);
        *(ASN1_GENERALIZEDTIME **)(*(int *)(pAVar2 + 4) + 4) = date;
        if (puVar6 != (undefined4 *)0x0) {
          *puVar6 = otherTypeId;
          puVar6[1] = otherType;
        }
        alg = *(X509_ALGOR **)(pAVar2 + 8);
        aobj = OBJ_nid2obj(nid);
        X509_ALGOR_set0(alg,aobj,-1,(void *)0x0);
        return (CMS_RecipientInfo *)val;
      }
    }
  }
LAB_0018fa44:
  ERR_put_error(0x2e,100,0x41,"crypto/cms/cms_env.c",0x23b);
LAB_0018fa58:
  ASN1_item_free(val,(ASN1_ITEM *)CMS_RecipientInfo_it);
  return (CMS_RecipientInfo *)0x0;
}

