
CMS_RecipientInfo * CMS_add1_recipient_cert(CMS_ContentInfo *cms,X509 *recip,uint flags)

{
  int iVar1;
  ASN1_VALUE *val;
  EVP_PKEY *pkey;
  int iVar2;
  ASN1_VALUE *pAVar3;
  EVP_PKEY_CTX *ctx;
  undefined4 uVar4;
  bool bVar5;
  
  iVar1 = cms_get0_enveloped(cms);
  if (iVar1 == 0) {
    val = (ASN1_VALUE *)0x0;
    goto LAB_00190314;
  }
  val = ASN1_item_new((ASN1_ITEM *)CMS_RecipientInfo_it);
  if (val != (ASN1_VALUE *)0x0) {
    pkey = (EVP_PKEY *)X509_get0_pubkey(recip);
    if (pkey == (EVP_PKEY *)0x0) {
      ERR_put_error(0x2e,0x65,0x71,"crypto/cms/cms_env.c",0xc3);
      goto LAB_00190314;
    }
    iVar2 = cms_pkey_get_ri_type();
    if (iVar2 == 0) {
      pAVar3 = ASN1_item_new((ASN1_ITEM *)CMS_KeyTransRecipientInfo_it);
      *(ASN1_VALUE **)(val + 4) = pAVar3;
      if (pAVar3 == (ASN1_VALUE *)0x0) goto LAB_00190314;
      *(undefined4 *)val = 0;
      bVar5 = (flags & 0x10000) != 0;
      if (bVar5) {
        uVar4 = 2;
      }
      else {
        uVar4 = 0;
      }
      *(undefined4 *)pAVar3 = uVar4;
      iVar2 = cms_set1_SignerIdentifier(*(undefined4 *)(pAVar3 + 4),recip,bVar5);
      if (iVar2 == 0) goto LAB_00190314;
      X509_up_ref(recip);
      EVP_PKEY_up_ref(pkey);
      *(EVP_PKEY **)(pAVar3 + 0x14) = pkey;
      *(X509 **)(pAVar3 + 0x10) = recip;
      if ((flags & 0x40000) == 0) {
        iVar2 = cms_env_asn1_ctrl(val);
        goto joined_r0x0019039e;
      }
      ctx = EVP_PKEY_CTX_new(pkey,(ENGINE *)0x0);
      *(EVP_PKEY_CTX **)(pAVar3 + 0x18) = ctx;
      if ((ctx == (EVP_PKEY_CTX *)0x0) || (iVar2 = EVP_PKEY_encrypt_init(ctx), iVar2 < 1))
      goto LAB_00190314;
    }
    else {
      if (iVar2 != 1) {
        ERR_put_error(0x2e,0x65,0x7d,"crypto/cms/cms_env.c",0xd5);
        goto LAB_00190314;
      }
      iVar2 = cms_RecipientInfo_kari_init(val,recip,pkey,flags);
joined_r0x0019039e:
      if (iVar2 == 0) goto LAB_00190314;
    }
    iVar1 = OPENSSL_sk_push(*(undefined4 *)(iVar1 + 8),val);
    if (iVar1 != 0) {
      return (CMS_RecipientInfo *)val;
    }
  }
  ERR_put_error(0x2e,0x65,0x41,"crypto/cms/cms_env.c",0xe0);
LAB_00190314:
  ASN1_item_free(val,(ASN1_ITEM *)CMS_RecipientInfo_it);
  return (CMS_RecipientInfo *)0x0;
}

