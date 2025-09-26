
undefined4
cms_RecipientInfo_kari_init(undefined4 *param_1,undefined4 param_2,EVP_PKEY *param_3,uint param_4)

{
  bool bVar1;
  ASN1_VALUE *pAVar2;
  ASN1_VALUE *val;
  int iVar3;
  ASN1_VALUE *pAVar4;
  EVP_PKEY_CTX *ctx;
  undefined4 *puVar5;
  EVP_PKEY *local_24;
  
  pAVar2 = ASN1_item_new((ASN1_ITEM *)CMS_KeyAgreeRecipientInfo_it);
  param_1[1] = pAVar2;
  if (pAVar2 == (ASN1_VALUE *)0x0) {
    return 0;
  }
  *param_1 = 1;
  *(undefined4 *)pAVar2 = 3;
  val = ASN1_item_new((ASN1_ITEM *)CMS_RecipientEncryptedKey_it);
  iVar3 = sk_push(*(_STACK **)(pAVar2 + 0x10),val);
  if (iVar3 == 0) {
    ASN1_item_free(val,(ASN1_ITEM *)CMS_RecipientEncryptedKey_it);
    return 0;
  }
  if ((param_4 & 0x10000) == 0) {
    puVar5 = *(undefined4 **)val;
    *puVar5 = 0;
    iVar3 = cms_set1_ias(puVar5 + 1,param_2);
  }
  else {
    puVar5 = *(undefined4 **)val;
    *puVar5 = 1;
    pAVar4 = ASN1_item_new((ASN1_ITEM *)CMS_RecipientKeyIdentifier_it);
    puVar5[1] = pAVar4;
    if (*(int *)(*(int *)val + 4) == 0) {
      return 0;
    }
    iVar3 = cms_set1_keyid(*(int *)(*(int *)val + 4),param_2);
  }
  if (iVar3 == 0) {
    return 0;
  }
  local_24 = (EVP_PKEY *)0x0;
  ctx = EVP_PKEY_CTX_new(param_3,(ENGINE *)0x0);
  if (ctx == (EVP_PKEY_CTX *)0x0) {
LAB_0017209c:
    bVar1 = false;
  }
  else {
    iVar3 = EVP_PKEY_keygen_init(ctx);
    if ((0 < iVar3) && (iVar3 = EVP_PKEY_keygen(ctx,&local_24), 0 < iVar3)) {
      EVP_PKEY_CTX_free(ctx);
      ctx = EVP_PKEY_CTX_new(local_24,(ENGINE *)0x0);
      if (ctx == (EVP_PKEY_CTX *)0x0) goto LAB_0017209c;
      iVar3 = EVP_PKEY_derive_init(ctx);
      if (0 < iVar3) {
        bVar1 = true;
        *(EVP_PKEY_CTX **)(pAVar2 + 0x14) = ctx;
        goto LAB_00172074;
      }
    }
    bVar1 = false;
    EVP_PKEY_CTX_free(ctx);
  }
LAB_00172074:
  if (local_24 != (EVP_PKEY *)0x0) {
    EVP_PKEY_free(local_24);
  }
  if (!bVar1) {
    return 0;
  }
  CRYPTO_add_lock(&param_3->references,1,10,"cms_kari.c",0x17d);
  *(EVP_PKEY **)(val + 8) = param_3;
  return 1;
}

