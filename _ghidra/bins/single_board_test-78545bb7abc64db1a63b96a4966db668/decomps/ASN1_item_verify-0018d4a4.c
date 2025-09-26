
int ASN1_item_verify(ASN1_ITEM *it,X509_ALGOR *algor1,ASN1_BIT_STRING *signature,void *data,
                    EVP_PKEY *pkey)

{
  EVP_MD_CTX *ctx;
  int iVar1;
  int iVar2;
  char *name;
  EVP_MD *type;
  code *pcVar3;
  uchar *local_34;
  int local_30;
  int local_2c [2];
  
  local_34 = (uchar *)0x0;
  if (pkey == (EVP_PKEY *)0x0) {
    ERR_put_error(0xd,0xc5,0x43,"crypto/asn1/a_verify.c",0x62);
    return -1;
  }
  if ((signature->type == 3) && ((signature->flags & 7U) != 0)) {
    ERR_put_error(0xd,0xc5,0xdc,"crypto/asn1/a_verify.c",0x67);
    return -1;
  }
  ctx = (EVP_MD_CTX *)EVP_MD_CTX_new();
  if (ctx == (EVP_MD_CTX *)0x0) {
    iVar2 = 0x6d;
    iVar1 = 0x41;
  }
  else {
    iVar1 = OBJ_obj2nid(algor1->algorithm);
    iVar1 = OBJ_find_sigid_algs(iVar1,&local_30,local_2c);
    if (iVar1 == 0) {
      iVar2 = -1;
      ERR_put_error(0xd,0xc5,199,"crypto/asn1/a_verify.c",0x73);
      iVar1 = 0;
      goto LAB_0018d510;
    }
    if (local_30 == 0) {
      if ((pkey->ameth == (EVP_PKEY_ASN1_METHOD *)0x0) ||
         (pcVar3 = *(code **)(pkey->ameth + 0x68), pcVar3 == (code *)0x0)) {
        iVar2 = 0x79;
        iVar1 = 199;
      }
      else {
        iVar2 = (*pcVar3)(ctx,it,data,algor1,signature,pkey);
        iVar1 = 0;
        if (iVar2 != 2) goto LAB_0018d510;
LAB_0018d59a:
        iVar1 = ASN1_item_i2d((ASN1_VALUE *)data,&local_34,it);
        if (0 < iVar1) {
          if (local_34 == (uchar *)0x0) {
            iVar2 = -1;
            ERR_put_error(0xd,0xc5,0x41,"crypto/asn1/a_verify.c",0xa2);
            iVar1 = 0;
          }
          else {
            iVar2 = EVP_DigestVerify(ctx,signature->data,signature->length,local_34,iVar1);
            if (iVar2 < 1) {
              ERR_put_error(0xd,0xc5,6,"crypto/asn1/a_verify.c",0xaa);
            }
            else {
              iVar2 = 1;
            }
          }
          goto LAB_0018d510;
        }
        iVar2 = 0x9e;
        iVar1 = 0x44;
      }
    }
    else {
      name = OBJ_nid2sn(local_30);
      type = EVP_get_digestbyname(name);
      if (type == (EVP_MD *)0x0) {
        iVar2 = -1;
        ERR_put_error(0xd,0xc5,0xa1,"crypto/asn1/a_verify.c",0x8a);
        iVar1 = 0;
        goto LAB_0018d510;
      }
      iVar1 = EVP_PKEY_type(local_2c[0]);
      if (iVar1 == *(int *)pkey->ameth) {
        iVar1 = EVP_DigestVerifyInit(ctx,(EVP_PKEY_CTX **)0x0,type,(ENGINE *)0x0,pkey);
        if (iVar1 == 0) {
          ERR_put_error(0xd,0xc5,6,"crypto/asn1/a_verify.c",0x95);
          iVar2 = 0;
          iVar1 = 0;
          goto LAB_0018d510;
        }
        goto LAB_0018d59a;
      }
      iVar2 = 0x90;
      iVar1 = 200;
    }
  }
  ERR_put_error(0xd,0xc5,iVar1,"crypto/asn1/a_verify.c",iVar2);
  iVar1 = 0;
  iVar2 = -1;
LAB_0018d510:
  CRYPTO_clear_free(local_34,iVar1,"crypto/asn1/a_verify.c",0xaf);
  EVP_MD_CTX_free(ctx);
  return iVar2;
}

