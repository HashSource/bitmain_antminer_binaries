
int ASN1_sign(undefined1 *i2d,X509_ALGOR *algor1,X509_ALGOR *algor2,ASN1_BIT_STRING *signature,
             char *data,EVP_PKEY *pkey,EVP_MD *type)

{
  EVP_MD_CTX *ctx;
  ASN1_OBJECT *pAVar1;
  ASN1_TYPE *cnt;
  ASN1_TYPE *d;
  ASN1_TYPE *md;
  ASN1_TYPE *pAVar2;
  ASN1_TYPE *impl;
  int iVar3;
  X509_ALGOR *pXVar4;
  int line;
  ASN1_TYPE *local_30;
  ASN1_TYPE *local_2c [2];
  
  ctx = (EVP_MD_CTX *)EVP_MD_CTX_new();
  local_2c[0] = (ASN1_TYPE *)0x0;
  if (ctx == (EVP_MD_CTX *)0x0) {
    ERR_put_error(0xd,0x80,0x41,"crypto/asn1/a_sign.c",0x25);
    pAVar2 = (ASN1_TYPE *)0x0;
    d = (ASN1_TYPE *)0x0;
    md = (ASN1_TYPE *)0x0;
    cnt = (ASN1_TYPE *)0x0;
    goto LAB_0017bf36;
  }
  if (algor2 == (X509_ALGOR *)0x0) {
    if (algor1 == (X509_ALGOR *)0x0) goto LAB_0017bea6;
    pAVar2 = algor1->parameter;
    if (type->pkey_type == 0x71) {
      ASN1_TYPE_free(pAVar2);
      algor1->parameter = (ASN1_TYPE *)0x0;
    }
    else if ((pAVar2 == (ASN1_TYPE *)0x0) || (pAVar2->type != 5)) {
      ASN1_TYPE_free(pAVar2);
      pAVar2 = ASN1_TYPE_new();
      algor1->parameter = pAVar2;
      d = pAVar2;
      md = pAVar2;
      cnt = pAVar2;
      if (pAVar2 == (ASN1_TYPE *)0x0) goto LAB_0017bf36;
      pAVar2->type = 5;
    }
    ASN1_OBJECT_free(algor1->algorithm);
    pAVar1 = OBJ_nid2obj(type->pkey_type);
    algor1->algorithm = pAVar1;
    if (pAVar1 == (ASN1_OBJECT *)0x0) {
LAB_0017c07c:
      line = 0x40;
      iVar3 = 0xa2;
    }
    else {
      if (pAVar1->length != 0) goto LAB_0017bea6;
LAB_0017c054:
      line = 0x45;
      iVar3 = 0x9a;
    }
  }
  else {
    iVar3 = 1;
    if (algor1 == (X509_ALGOR *)0x0) {
      do {
        do {
          iVar3 = iVar3 + 1;
        } while (iVar3 == 1);
        if (type->pkey_type == 0x71) {
          ASN1_TYPE_free(algor2->parameter);
          algor2->parameter = (ASN1_TYPE *)0x0;
        }
        else {
          pAVar2 = algor2->parameter;
          if ((pAVar2 == (ASN1_TYPE *)0x0) || (pAVar2->type != 5)) {
            ASN1_TYPE_free(pAVar2);
            pAVar2 = ASN1_TYPE_new();
            algor2->parameter = pAVar2;
            d = pAVar2;
            md = pAVar2;
            cnt = pAVar2;
            if (pAVar2 == (ASN1_TYPE *)0x0) goto LAB_0017bf36;
            pAVar2->type = 5;
          }
        }
        ASN1_OBJECT_free(algor2->algorithm);
        pAVar1 = OBJ_nid2obj(type->pkey_type);
        algor2->algorithm = pAVar1;
        if (pAVar1 == (ASN1_OBJECT *)0x0) goto LAB_0017c07c;
        if (pAVar1->length == 0) goto LAB_0017c054;
      } while (iVar3 != 2);
    }
    else {
      iVar3 = 0;
      do {
        pXVar4 = algor2;
        if (iVar3 == 0) {
          pXVar4 = algor1;
        }
        if (type->pkey_type == 0x71) {
          ASN1_TYPE_free(pXVar4->parameter);
          pXVar4->parameter = (ASN1_TYPE *)0x0;
        }
        else {
          pAVar2 = pXVar4->parameter;
          if ((pAVar2 == (ASN1_TYPE *)0x0) || (pAVar2->type != 5)) {
            ASN1_TYPE_free(pAVar2);
            pAVar2 = ASN1_TYPE_new();
            pXVar4->parameter = pAVar2;
            d = pAVar2;
            md = pAVar2;
            cnt = pAVar2;
            if (pAVar2 == (ASN1_TYPE *)0x0) goto LAB_0017bf36;
            pAVar2->type = 5;
          }
        }
        iVar3 = iVar3 + 1;
        ASN1_OBJECT_free(pXVar4->algorithm);
        pAVar1 = OBJ_nid2obj(type->pkey_type);
        pXVar4->algorithm = pAVar1;
        if (pAVar1 == (ASN1_OBJECT *)0x0) goto LAB_0017c07c;
        if (pAVar1->length == 0) goto LAB_0017c054;
      } while (iVar3 != 2);
    }
LAB_0017bea6:
    cnt = (ASN1_TYPE *)(*(code *)i2d)(data,0);
    if (0 < (int)cnt) {
      d = (ASN1_TYPE *)CRYPTO_malloc((int)cnt,"crypto/asn1/a_sign.c",0x4f);
      pAVar2 = (ASN1_TYPE *)EVP_PKEY_size(pkey);
      local_2c[0] = pAVar2;
      md = (ASN1_TYPE *)CRYPTO_malloc((int)pAVar2,"crypto/asn1/a_sign.c",0x51);
      impl = (ASN1_TYPE *)(uint)(md == (ASN1_TYPE *)0x0 || d == (ASN1_TYPE *)0x0);
      if (md == (ASN1_TYPE *)0x0 || d == (ASN1_TYPE *)0x0) {
        local_2c[0] = (ASN1_TYPE *)0x0;
        ERR_put_error(0xd,0x80,0x41,"crypto/asn1/a_sign.c",0x54);
      }
      else {
        local_30 = d;
        (*(code *)i2d)(data,&local_30);
        iVar3 = EVP_DigestInit_ex(ctx,type,(ENGINE *)impl);
        if (((iVar3 == 0) || (iVar3 = EVP_DigestUpdate(ctx,d,(size_t)cnt), iVar3 == 0)) ||
           (iVar3 = EVP_SignFinal(ctx,(uchar *)md,(uint *)local_2c,pkey), iVar3 == 0)) {
          local_2c[0] = (ASN1_TYPE *)0x0;
          ERR_put_error(0xd,0x80,6,"crypto/asn1/a_sign.c",0x5f);
        }
        else {
          CRYPTO_free(signature->data);
          signature->data = (uchar *)md;
          signature->length = (int)local_2c[0];
          signature->flags = signature->flags & 0xfffffff0U | 8;
          md = impl;
        }
      }
      goto LAB_0017bf36;
    }
    line = 0x4b;
    iVar3 = 0x44;
  }
  pAVar2 = (ASN1_TYPE *)0x0;
  ERR_put_error(0xd,0x80,iVar3,"crypto/asn1/a_sign.c",line);
  d = (ASN1_TYPE *)0x0;
  md = (ASN1_TYPE *)0x0;
  cnt = (ASN1_TYPE *)0x0;
LAB_0017bf36:
  EVP_MD_CTX_free(ctx);
  CRYPTO_clear_free(d,cnt,"crypto/asn1/a_sign.c",0x6e);
  CRYPTO_clear_free(md,pAVar2,"crypto/asn1/a_sign.c",0x6f);
  return (int)local_2c[0];
}

