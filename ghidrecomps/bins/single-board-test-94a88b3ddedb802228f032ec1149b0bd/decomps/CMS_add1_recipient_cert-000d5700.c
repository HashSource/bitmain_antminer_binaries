
/* WARNING: Type propagation algorithm not settling */

CMS_RecipientInfo * CMS_add1_recipient_cert(CMS_ContentInfo *cms,X509 *recip,uint flags)

{
  int iVar1;
  ASN1_VALUE *val;
  EVP_PKEY *pkey;
  int iVar2;
  undefined4 *puVar3;
  EVP_PKEY_CTX *ctx;
  undefined4 uVar4;
  code *pcVar5;
  int local_24 [2];
  
  iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
  if (iVar1 != 0x17) {
    ERR_put_error(0x2e,0x83,0x6b,DAT_000d5884,0x4f);
    return (CMS_RecipientInfo *)0x0;
  }
  iVar1 = *(int *)(cms + 4);
  if (iVar1 == 0) {
    return (CMS_RecipientInfo *)0x0;
  }
  val = ASN1_item_new(DAT_000d587c);
  if (val == (ASN1_VALUE *)0x0) {
    ERR_put_error(0x2e,0x65,0x41,DAT_000d5884,0x116);
    return (CMS_RecipientInfo *)0x0;
  }
  pkey = X509_get_pubkey(recip);
  if (pkey == (EVP_PKEY *)0x0) {
    ERR_put_error(0x2e,0x65,0x71,DAT_000d5884,0xf7);
    goto LAB_000d577e;
  }
  if ((((pkey->ameth == (EVP_PKEY_ASN1_METHOD *)0x0) ||
       (pcVar5 = *(code **)(pkey->ameth + 0x58), pcVar5 == (code *)0x0)) ||
      (iVar2 = (*pcVar5)(pkey,8,0,local_24), iVar2 < 1)) || (local_24[0] == 0)) {
    puVar3 = (undefined4 *)ASN1_item_new(DAT_000d5880);
    *(undefined4 **)(val + 4) = puVar3;
    if (puVar3 == (undefined4 *)0x0) goto LAB_000d577e;
    *(undefined4 *)&val->field_0x0 = 0;
    if ((flags & 0x10000) == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = 2;
    }
    *puVar3 = uVar4;
    iVar2 = cms_set1_SignerIdentifier(puVar3[1],recip);
    if (iVar2 == 0) goto LAB_000d577e;
    CRYPTO_add_lock(&recip->references,1,3,DAT_000d5884,0xd2);
    CRYPTO_add_lock(&pkey->references,1,10,DAT_000d5884,0xd3);
    puVar3[5] = pkey;
    puVar3[4] = recip;
    if ((flags & 0x40000) == 0) {
      iVar2 = cms_env_asn1_ctrl(val);
      goto joined_r0x000d5870;
    }
    ctx = EVP_PKEY_CTX_new(pkey,(ENGINE *)0x0);
    puVar3[6] = ctx;
    if ((ctx == (EVP_PKEY_CTX *)0x0) || (iVar2 = EVP_PKEY_encrypt_init(ctx), iVar2 < 1))
    goto LAB_000d577e;
  }
  else {
    if (local_24[0] != 1) {
      ERR_put_error(0x2e,0x65,0x7d,DAT_000d5884,0x109);
      goto LAB_000d577e;
    }
    iVar2 = cms_RecipientInfo_kari_init(val,recip,pkey,flags);
joined_r0x000d5870:
    if (iVar2 == 0) goto LAB_000d577e;
  }
  iVar1 = sk_push(*(_STACK **)(iVar1 + 8),val);
  if (iVar1 != 0) {
    EVP_PKEY_free(pkey);
    return (CMS_RecipientInfo *)val;
  }
  ERR_put_error(0x2e,0x65,0x41,DAT_000d5884,0x116);
LAB_000d577e:
  ASN1_item_free(val,DAT_000d587c);
  if (pkey != (EVP_PKEY *)0x0) {
    EVP_PKEY_free(pkey);
    return (CMS_RecipientInfo *)0x0;
  }
  return (CMS_RecipientInfo *)0x0;
}

