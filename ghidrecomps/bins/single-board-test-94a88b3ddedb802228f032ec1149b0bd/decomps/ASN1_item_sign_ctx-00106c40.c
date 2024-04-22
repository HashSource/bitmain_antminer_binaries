
int ASN1_item_sign_ctx(ASN1_ITEM *it,X509_ALGOR *algor1,X509_ALGOR *algor2,
                      ASN1_BIT_STRING *signature,void *asn,EVP_MD_CTX *ctx)

{
  EVP_MD *md;
  EVP_PKEY *pkey;
  int iVar1;
  uchar *puVar2;
  uchar *puVar3;
  ASN1_OBJECT *pAVar4;
  EVP_PKEY_ASN1_METHOD *pEVar5;
  uchar *sigret;
  uchar *local_34;
  uchar *local_30;
  int local_2c [2];
  
  local_34 = (uchar *)0x0;
  local_30 = (uchar *)0x0;
  md = EVP_MD_CTX_md(ctx);
  pkey = EVP_PKEY_CTX_get0_pkey(ctx->pctx);
  if (md == (EVP_MD *)0x0 || pkey == (EVP_PKEY *)0x0) {
    ERR_put_error(0xd,0xdc,0xd9,DAT_00106e3c,0xf7);
    return 0;
  }
  pEVar5 = pkey->ameth;
  if (*(code **)(pEVar5 + 0x68) == (code *)0x0) {
    if ((int)(md->flags << 0x1d) < 0) {
LAB_00106da6:
      iVar1 = EVP_MD_type(md);
      iVar1 = OBJ_find_sigid_by_algs(local_2c,iVar1,*(int *)pkey->ameth);
      if (iVar1 == 0) {
LAB_00106e26:
        ERR_put_error(0xd,0xdc,0xc6,DAT_00106e3c,0x114);
        return 0;
      }
      pEVar5 = pkey->ameth;
    }
    else {
LAB_00106dc6:
      local_2c[0] = md->pkey_type;
    }
    if ((*(uint *)(pEVar5 + 8) & 4) == 0) {
      iVar1 = -1;
    }
    else {
      iVar1 = 5;
    }
    if (algor1 != (X509_ALGOR *)0x0) {
      pAVar4 = OBJ_nid2obj(local_2c[0]);
      X509_ALGOR_set0(algor1,pAVar4,iVar1,(void *)0x0);
    }
    if (algor2 != (X509_ALGOR *)0x0) {
      pAVar4 = OBJ_nid2obj(local_2c[0]);
      X509_ALGOR_set0(algor2,pAVar4,iVar1,(void *)0x0);
    }
  }
  else {
    iVar1 = (**(code **)(pEVar5 + 0x68))(ctx,it,asn,algor1,algor2,signature);
    sigret = (uchar *)0x0;
    puVar3 = sigret;
    puVar2 = sigret;
    if (iVar1 == 1) {
      local_30 = (uchar *)signature->length;
      goto LAB_00106d2e;
    }
    if (iVar1 < 1) {
      ERR_put_error(0xd,0xdc,6,DAT_00106e3c,0x107);
      goto LAB_00106d2e;
    }
    if (iVar1 == 2) {
      pEVar5 = pkey->ameth;
      if ((int)(md->flags << 0x1d) < 0) {
        if (pEVar5 == (EVP_PKEY_ASN1_METHOD *)0x0) goto LAB_00106e26;
        goto LAB_00106da6;
      }
      goto LAB_00106dc6;
    }
  }
  puVar2 = (uchar *)ASN1_item_i2d((ASN1_VALUE *)asn,&local_34,it);
  puVar3 = (uchar *)EVP_PKEY_size(pkey);
  local_30 = puVar3;
  sigret = (uchar *)CRYPTO_malloc((int)puVar3,DAT_00106e3c,0x128);
  if ((local_34 == (uchar *)0x0) || (sigret == (uchar *)0x0)) {
    local_30 = (uchar *)0x0;
    ERR_put_error(0xd,0xdc,0x41,DAT_00106e3c,299);
  }
  else {
    iVar1 = EVP_DigestUpdate(ctx,local_34,(size_t)puVar2);
    if ((iVar1 == 0) || (iVar1 = EVP_DigestSignFinal(ctx,sigret,(size_t *)&local_30), iVar1 == 0)) {
      local_30 = (uchar *)0x0;
      ERR_put_error(0xd,0xdc,6,DAT_00106e3c,0x132);
    }
    else {
      if (signature->data != (uchar *)0x0) {
        CRYPTO_free(signature->data);
      }
      signature->data = sigret;
      sigret = (uchar *)0x0;
      signature->length = (int)local_30;
      signature->flags = signature->flags & 0xfffffff0U | 8;
    }
  }
LAB_00106d2e:
  EVP_MD_CTX_cleanup(ctx);
  if (local_34 != (uchar *)0x0) {
    OPENSSL_cleanse(local_34,(size_t)puVar2);
    CRYPTO_free(local_34);
  }
  if (sigret != (uchar *)0x0) {
    OPENSSL_cleanse(sigret,(size_t)puVar3);
    CRYPTO_free(sigret);
  }
  return (int)local_30;
}

