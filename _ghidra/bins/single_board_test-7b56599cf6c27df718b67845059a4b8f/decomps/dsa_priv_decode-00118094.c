
undefined4 dsa_priv_decode(EVP_PKEY *param_1,PKCS8_PRIV_KEY_INFO *param_2)

{
  int iVar1;
  ASN1_INTEGER *ai;
  BIGNUM *pBVar2;
  undefined4 uVar3;
  DSA *r;
  BN_CTX *ctx;
  uchar *puStack_30;
  uchar *local_2c;
  long local_28;
  int local_24;
  long *local_20;
  X509_ALGOR *local_1c;
  
  iVar1 = PKCS8_pkey_get0((ASN1_OBJECT **)0x0,&puStack_30,&local_28,&local_1c,param_2);
  if (iVar1 == 0) {
    return 0;
  }
  X509_ALGOR_get0((ASN1_OBJECT **)0x0,&local_24,&local_20,local_1c);
  ai = d2i_ASN1_INTEGER((ASN1_INTEGER **)0x0,&puStack_30,local_28);
  if (((ai == (ASN1_INTEGER *)0x0) || (ai->type == 0x102)) || (local_24 != 0x10)) {
LAB_001180dc:
    r = (DSA *)0x0;
    ctx = (BN_CTX *)0x0;
    ERR_put_error(10,0x73,0x68,"crypto/dsa/dsa_ameth.c",0xc2);
  }
  else {
    local_2c = (uchar *)local_20[2];
    r = d2i_DSAparams((DSA **)0x0,&local_2c,*local_20);
    if (r == (DSA *)0x0) goto LAB_001180dc;
    pBVar2 = (BIGNUM *)BN_secure_new();
    r->pub_key = pBVar2;
    if ((pBVar2 == (BIGNUM *)0x0) ||
       (pBVar2 = ASN1_INTEGER_to_BN(ai,pBVar2), pBVar2 == (BIGNUM *)0x0)) {
      ctx = (BN_CTX *)0x0;
      ERR_put_error(10,0x73,0x6d,"crypto/dsa/dsa_ameth.c",0xa9);
    }
    else {
      pBVar2 = BN_new();
      r->g = pBVar2;
      if (pBVar2 == (BIGNUM *)0x0) {
        ERR_put_error(10,0x73,0x41,"crypto/dsa/dsa_ameth.c",0xae);
        ctx = (BN_CTX *)0x0;
      }
      else {
        ctx = BN_CTX_new();
        if (ctx == (BN_CTX *)0x0) {
          ERR_put_error(10,0x73,0x41,"crypto/dsa/dsa_ameth.c",0xb2);
        }
        else {
          BN_set_flags(r->pub_key,4);
          iVar1 = BN_mod_exp(r->g,r->q,r->pub_key,(BIGNUM *)r->write_params,ctx);
          if (iVar1 != 0) {
            uVar3 = 1;
            EVP_PKEY_assign(param_1,0x74,r);
            goto LAB_001180fa;
          }
          ERR_put_error(10,0x73,0x6d,"crypto/dsa/dsa_ameth.c",0xb8);
        }
      }
    }
  }
  uVar3 = 0;
  DSA_free(r);
LAB_001180fa:
  BN_CTX_free(ctx);
  ASN1_STRING_clear_free(ai);
  return uVar3;
}

