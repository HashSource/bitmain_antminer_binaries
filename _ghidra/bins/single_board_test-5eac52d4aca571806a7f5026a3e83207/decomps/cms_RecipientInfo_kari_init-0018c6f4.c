
undefined4
cms_RecipientInfo_kari_init(undefined4 *param_1,undefined4 param_2,EVP_PKEY *param_3,uint param_4)

{
  ASN1_VALUE *pAVar1;
  ASN1_VALUE *val;
  int iVar2;
  ASN1_VALUE *pAVar3;
  EVP_PKEY_CTX *ctx;
  undefined4 *puVar4;
  EVP_PKEY *local_2c [2];
  
  pAVar1 = ASN1_item_new((ASN1_ITEM *)CMS_KeyAgreeRecipientInfo_it);
  param_1[1] = pAVar1;
  if (pAVar1 == (ASN1_VALUE *)0x0) {
    return 0;
  }
  *param_1 = 1;
  *(undefined4 *)pAVar1 = 3;
  val = ASN1_item_new((ASN1_ITEM *)CMS_RecipientEncryptedKey_it);
  if (val == (ASN1_VALUE *)0x0) {
    return 0;
  }
  iVar2 = OPENSSL_sk_push(*(undefined4 *)(pAVar1 + 0x10),val);
  if (iVar2 == 0) {
    ASN1_item_free(val,(ASN1_ITEM *)CMS_RecipientEncryptedKey_it);
    return 0;
  }
  if ((param_4 & 0x10000) == 0) {
    puVar4 = *(undefined4 **)val;
    *puVar4 = 0;
    iVar2 = cms_set1_ias(puVar4 + 1,param_2);
  }
  else {
    puVar4 = *(undefined4 **)val;
    *puVar4 = 1;
    pAVar3 = ASN1_item_new((ASN1_ITEM *)CMS_RecipientKeyIdentifier_it);
    puVar4[1] = pAVar3;
    if (*(int *)(*(int *)val + 4) == 0) {
      return 0;
    }
    iVar2 = cms_set1_keyid(*(int *)(*(int *)val + 4),param_2);
  }
  if (iVar2 == 0) {
    return 0;
  }
  local_2c[0] = (EVP_PKEY *)0x0;
  ctx = EVP_PKEY_CTX_new(param_3,(ENGINE *)0x0);
  if (ctx != (EVP_PKEY_CTX *)0x0) {
    iVar2 = EVP_PKEY_keygen_init(ctx);
    if ((iVar2 < 1) || (iVar2 = EVP_PKEY_keygen(ctx,local_2c), iVar2 < 1)) goto LAB_0018c7f8;
    EVP_PKEY_CTX_free(ctx);
    ctx = EVP_PKEY_CTX_new(local_2c[0],(ENGINE *)0x0);
    if (ctx != (EVP_PKEY_CTX *)0x0) {
      iVar2 = EVP_PKEY_derive_init(ctx);
      if (0 < iVar2) {
        *(EVP_PKEY_CTX **)(pAVar1 + 0x14) = ctx;
        EVP_PKEY_free(local_2c[0]);
        EVP_PKEY_up_ref(param_3);
        *(EVP_PKEY **)(val + 8) = param_3;
        return 1;
      }
      goto LAB_0018c7f8;
    }
  }
  ctx = (EVP_PKEY_CTX *)0x0;
LAB_0018c7f8:
  EVP_PKEY_CTX_free(ctx);
  EVP_PKEY_free(local_2c[0]);
  return 0;
}

