
undefined4
cms_RecipientInfo_kari_init(undefined4 *param_1,undefined4 param_2,EVP_PKEY *param_3,uint param_4)

{
  bool bVar1;
  ASN1_ITEM *pAVar2;
  undefined4 *puVar3;
  int *val;
  int iVar4;
  ASN1_VALUE *pAVar5;
  EVP_PKEY_CTX *ctx;
  undefined4 *puVar6;
  EVP_PKEY *local_24;
  
  puVar3 = (undefined4 *)ASN1_item_new(DAT_000d6e28);
  param_1[1] = puVar3;
  if (puVar3 == (undefined4 *)0x0) {
    return 0;
  }
  *param_1 = 1;
  pAVar2 = DAT_000d6e2c;
  *puVar3 = 3;
  val = (int *)ASN1_item_new(pAVar2);
  iVar4 = sk_push((_STACK *)puVar3[4],val);
  pAVar2 = DAT_000d6e30;
  if (iVar4 == 0) {
    ASN1_item_free((ASN1_VALUE *)val,DAT_000d6e2c);
    return 0;
  }
  if ((param_4 & 0x10000) == 0) {
    puVar6 = (undefined4 *)*val;
    *puVar6 = 0;
    iVar4 = cms_set1_ias(puVar6 + 1,param_2);
  }
  else {
    puVar6 = (undefined4 *)*val;
    *puVar6 = 1;
    pAVar5 = ASN1_item_new(pAVar2);
    puVar6[1] = pAVar5;
    if (*(int *)(*val + 4) == 0) {
      return 0;
    }
    iVar4 = cms_set1_keyid(*(int *)(*val + 4),param_2);
  }
  if (iVar4 == 0) {
    return 0;
  }
  local_24 = (EVP_PKEY *)0x0;
  ctx = EVP_PKEY_CTX_new(param_3,(ENGINE *)0x0);
  if (ctx == (EVP_PKEY_CTX *)0x0) {
LAB_000d6e18:
    bVar1 = false;
  }
  else {
    iVar4 = EVP_PKEY_keygen_init(ctx);
    if ((0 < iVar4) && (iVar4 = EVP_PKEY_keygen(ctx,&local_24), 0 < iVar4)) {
      EVP_PKEY_CTX_free(ctx);
      ctx = EVP_PKEY_CTX_new(local_24,(ENGINE *)0x0);
      if (ctx == (EVP_PKEY_CTX *)0x0) goto LAB_000d6e18;
      iVar4 = EVP_PKEY_derive_init(ctx);
      if (0 < iVar4) {
        bVar1 = true;
        puVar3[5] = ctx;
        goto LAB_000d6df0;
      }
    }
    bVar1 = false;
    EVP_PKEY_CTX_free(ctx);
  }
LAB_000d6df0:
  if (local_24 != (EVP_PKEY *)0x0) {
    EVP_PKEY_free(local_24);
  }
  if (!bVar1) {
    return 0;
  }
  CRYPTO_add_lock(&param_3->references,1,10,DAT_000d6e34,0x17d);
  val[2] = (int)param_3;
  return 1;
}

