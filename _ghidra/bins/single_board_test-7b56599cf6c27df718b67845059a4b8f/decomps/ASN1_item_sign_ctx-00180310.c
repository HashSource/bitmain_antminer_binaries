
int ASN1_item_sign_ctx(ASN1_ITEM *it,X509_ALGOR *algor1,X509_ALGOR *algor2,
                      ASN1_BIT_STRING *signature,void *asn,EVP_MD_CTX *ctx)

{
  EVP_MD *md;
  EVP_PKEY_CTX *ctx_00;
  EVP_PKEY *pkey;
  int iVar1;
  uchar *puVar2;
  uchar *puVar3;
  uchar *puVar4;
  ASN1_OBJECT *pAVar5;
  uchar *num;
  code *pcVar6;
  int line;
  uchar *local_34;
  uchar *local_30;
  int local_2c [2];
  
  num = (uchar *)0x0;
  local_34 = (uchar *)0x0;
  local_30 = (uchar *)0x0;
  md = EVP_MD_CTX_md(ctx);
  ctx_00 = (EVP_PKEY_CTX *)EVP_MD_CTX_pkey_ctx(ctx);
  pkey = EVP_PKEY_CTX_get0_pkey(ctx_00);
  if (pkey == (EVP_PKEY *)0x0) {
    line = 0x9a;
    iVar1 = 0xd9;
  }
  else if (pkey->ameth == (EVP_PKEY_ASN1_METHOD *)0x0) {
    line = 0x9f;
    iVar1 = 0xc6;
  }
  else {
    pcVar6 = *(code **)(pkey->ameth + 0x6c);
    if (pcVar6 == (code *)0x0) {
LAB_00180406:
      if (md == (EVP_MD *)0x0) {
        line = 0xb8;
        iVar1 = 0xd9;
      }
      else {
        iVar1 = EVP_MD_type(md);
        iVar1 = OBJ_find_sigid_by_algs(local_2c,iVar1,*(int *)pkey->ameth);
        if (iVar1 != 0) {
          if ((*(uint *)(pkey->ameth + 8) & 4) == 0) {
            iVar1 = -1;
          }
          else {
            iVar1 = 5;
          }
          if (algor1 != (X509_ALGOR *)0x0) {
            pAVar5 = OBJ_nid2obj(local_2c[0]);
            X509_ALGOR_set0(algor1,pAVar5,iVar1,(void *)0x0);
          }
          if (algor2 != (X509_ALGOR *)0x0) {
            pAVar5 = OBJ_nid2obj(local_2c[0]);
            X509_ALGOR_set0(algor2,pAVar5,iVar1,(void *)0x0);
          }
LAB_0018036e:
          puVar2 = (uchar *)ASN1_item_i2d((ASN1_VALUE *)asn,&local_34,it);
          if ((int)puVar2 < 1) {
            num = (uchar *)0x0;
            local_30 = (uchar *)0x0;
            ERR_put_error(0xd,0xdc,0x44,"crypto/asn1/a_sign.c",0xd2);
            puVar3 = (uchar *)0x0;
            puVar2 = (uchar *)0x0;
          }
          else {
            num = (uchar *)EVP_PKEY_size(pkey);
            local_30 = num;
            puVar3 = (uchar *)CRYPTO_malloc((int)num,"crypto/asn1/a_sign.c",0xd7);
            if (local_34 == (uchar *)0x0 || puVar3 == (uchar *)0x0) {
              local_30 = (uchar *)0x0;
              ERR_put_error(0xd,0xdc,0x41,"crypto/asn1/a_sign.c",0xda);
            }
            else {
              puVar4 = (uchar *)EVP_DigestSign(ctx,puVar3,&local_30,local_34,puVar2);
              if (puVar4 == (uchar *)0x0) {
                local_30 = puVar4;
                ERR_put_error(0xd,0xdc,6,"crypto/asn1/a_sign.c",0xe0);
              }
              else {
                CRYPTO_free(signature->data);
                signature->data = puVar3;
                signature->length = (int)local_30;
                signature->flags = signature->flags & 0xfffffff0U | 8;
                puVar3 = (uchar *)0x0;
              }
            }
          }
          goto LAB_001803e2;
        }
        line = 0xbf;
        iVar1 = 0xc6;
      }
    }
    else {
      iVar1 = (*pcVar6)(ctx,it,asn,algor1,algor2,signature);
      if (iVar1 == 1) {
        local_30 = (uchar *)signature->length;
        puVar2 = (uchar *)0x0;
        puVar3 = (uchar *)0x0;
        goto LAB_001803e2;
      }
      if (0 < iVar1) {
        if (iVar1 == 2) goto LAB_00180406;
        goto LAB_0018036e;
      }
      iVar1 = 6;
      line = 0xaf;
    }
  }
  num = (uchar *)0x0;
  ERR_put_error(0xd,0xdc,iVar1,"crypto/asn1/a_sign.c",line);
  puVar3 = num;
  puVar2 = num;
LAB_001803e2:
  CRYPTO_clear_free(local_34,puVar2,"crypto/asn1/a_sign.c",0xee);
  CRYPTO_clear_free(puVar3,num,"crypto/asn1/a_sign.c",0xef);
  return (int)local_30;
}

