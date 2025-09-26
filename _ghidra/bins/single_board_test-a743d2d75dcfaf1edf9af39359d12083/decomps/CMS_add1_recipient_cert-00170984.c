
/* WARNING: Type propagation algorithm not settling */

CMS_RecipientInfo * CMS_add1_recipient_cert(CMS_ContentInfo *cms,X509 *recip,uint flags)

{
  int iVar1;
  ASN1_VALUE *val;
  EVP_PKEY *pkey;
  int iVar2;
  ASN1_VALUE *pAVar3;
  EVP_PKEY_CTX *ctx;
  undefined4 uVar4;
  code *pcVar5;
  bool bVar6;
  int local_24 [2];
  
  iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
  if (iVar1 != 0x17) {
    ERR_put_error(0x2e,0x83,0x6b,"cms_env.c",0x4f);
    return (CMS_RecipientInfo *)0x0;
  }
  iVar1 = *(int *)(cms + 4);
  if (iVar1 == 0) {
    return (CMS_RecipientInfo *)0x0;
  }
  val = ASN1_item_new((ASN1_ITEM *)CMS_RecipientInfo_it);
  if (val == (ASN1_VALUE *)0x0) {
    ERR_put_error(0x2e,0x65,0x41,"cms_env.c",0x116);
    return (CMS_RecipientInfo *)0x0;
  }
  pkey = X509_get_pubkey(recip);
  if (pkey == (EVP_PKEY *)0x0) {
    ERR_put_error(0x2e,0x65,0x71,"cms_env.c",0xf7);
    goto LAB_00170a02;
  }
  if ((((pkey->ameth == (EVP_PKEY_ASN1_METHOD *)0x0) ||
       (pcVar5 = *(code **)(pkey->ameth + 0x58), pcVar5 == (code *)0x0)) ||
      (iVar2 = (*pcVar5)(pkey,8,0,local_24), iVar2 < 1)) || (local_24[0] == 0)) {
    pAVar3 = ASN1_item_new((ASN1_ITEM *)CMS_KeyTransRecipientInfo_it);
    *(ASN1_VALUE **)(val + 4) = pAVar3;
    if (pAVar3 == (ASN1_VALUE *)0x0) goto LAB_00170a02;
    *(undefined4 *)&val->field_0x0 = 0;
    bVar6 = (flags & 0x10000) != 0;
    if (bVar6) {
      uVar4 = 2;
    }
    else {
      uVar4 = 0;
    }
    *(undefined4 *)pAVar3 = uVar4;
    iVar2 = cms_set1_SignerIdentifier(*(undefined4 *)(pAVar3 + 4),recip,bVar6);
    if (iVar2 == 0) goto LAB_00170a02;
    CRYPTO_add_lock(&recip->references,1,3,"cms_env.c",0xd2);
    CRYPTO_add_lock(&pkey->references,1,10,"cms_env.c",0xd3);
    *(EVP_PKEY **)(pAVar3 + 0x14) = pkey;
    *(X509 **)(pAVar3 + 0x10) = recip;
    if ((flags & 0x40000) == 0) {
      iVar2 = cms_env_asn1_ctrl(val);
      goto joined_r0x00170af4;
    }
    ctx = EVP_PKEY_CTX_new(pkey,(ENGINE *)0x0);
    *(EVP_PKEY_CTX **)(pAVar3 + 0x18) = ctx;
    if ((ctx == (EVP_PKEY_CTX *)0x0) || (iVar2 = EVP_PKEY_encrypt_init(ctx), iVar2 < 1))
    goto LAB_00170a02;
  }
  else {
    if (local_24[0] != 1) {
      ERR_put_error(0x2e,0x65,0x7d,"cms_env.c",0x109);
      goto LAB_00170a02;
    }
    iVar2 = cms_RecipientInfo_kari_init(val,recip,pkey,flags);
joined_r0x00170af4:
    if (iVar2 == 0) goto LAB_00170a02;
  }
  iVar1 = sk_push(*(_STACK **)(iVar1 + 8),val);
  if (iVar1 != 0) {
    EVP_PKEY_free(pkey);
    return (CMS_RecipientInfo *)val;
  }
  ERR_put_error(0x2e,0x65,0x41,"cms_env.c",0x116);
LAB_00170a02:
  ASN1_item_free(val,(ASN1_ITEM *)CMS_RecipientInfo_it);
  if (pkey != (EVP_PKEY *)0x0) {
    EVP_PKEY_free(pkey);
    return (CMS_RecipientInfo *)0x0;
  }
  return (CMS_RecipientInfo *)0x0;
}

