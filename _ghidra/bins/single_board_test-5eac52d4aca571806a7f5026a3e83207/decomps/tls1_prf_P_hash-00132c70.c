
int tls1_prf_P_hash(EVP_MD *param_1,undefined4 param_2,undefined4 param_3,void *param_4,
                   size_t param_5,uchar *param_6,uint param_7)

{
  uint uVar1;
  EVP_MD_CTX *out;
  EVP_MD_CTX *out_00;
  EVP_MD_CTX *ctx;
  EVP_PKEY *pkey;
  int iVar2;
  size_t local_70;
  size_t local_6c;
  uchar auStack_68 [68];
  
  uVar1 = EVP_MD_size(param_1);
  if ((int)uVar1 < 1) {
    iVar2 = 0;
    pkey = (EVP_PKEY *)0x0;
    ctx = (EVP_MD_CTX *)0x0;
    out_00 = (EVP_MD_CTX *)0x0;
    out = (EVP_MD_CTX *)0x0;
  }
  else {
    out = (EVP_MD_CTX *)EVP_MD_CTX_new();
    out_00 = (EVP_MD_CTX *)EVP_MD_CTX_new();
    ctx = (EVP_MD_CTX *)EVP_MD_CTX_new();
    if (out_00 == (EVP_MD_CTX *)0x0 || out == (EVP_MD_CTX *)0x0) {
      iVar2 = 0;
      pkey = (EVP_PKEY *)0x0;
    }
    else if (ctx == (EVP_MD_CTX *)0x0) {
      iVar2 = 0;
      pkey = (EVP_PKEY *)0x0;
    }
    else {
      EVP_MD_CTX_set_flags(ctx,8);
      pkey = (EVP_PKEY *)EVP_PKEY_new_raw_private_key(0x357,0,param_2,param_3);
      if (pkey == (EVP_PKEY *)0x0) {
        iVar2 = 0;
      }
      else {
        iVar2 = EVP_DigestSignInit(ctx,(EVP_PKEY_CTX **)0x0,param_1,(ENGINE *)0x0,pkey);
        if (((iVar2 != 0) && (iVar2 = EVP_MD_CTX_copy_ex(out,ctx), iVar2 != 0)) &&
           ((param_4 == (void *)0x0 || (iVar2 = EVP_DigestUpdate(out,param_4,param_5), iVar2 != 0)))
           ) {
          iVar2 = EVP_DigestSignFinal(out,auStack_68,&local_70);
          if (iVar2 != 0) {
            while( true ) {
              iVar2 = EVP_MD_CTX_copy_ex(out,ctx);
              if ((iVar2 == 0) || (iVar2 = EVP_DigestUpdate(out,auStack_68,local_70), iVar2 == 0))
              goto LAB_00132d82;
              if (param_7 <= uVar1) break;
              iVar2 = EVP_MD_CTX_copy_ex(out_00,out);
              if (((iVar2 == 0) ||
                  ((param_4 != (void *)0x0 &&
                   (iVar2 = EVP_DigestUpdate(out,param_4,param_5), iVar2 == 0)))) ||
                 (iVar2 = EVP_DigestSignFinal(out,param_6,&local_6c), iVar2 == 0))
              goto LAB_00132d82;
              param_6 = param_6 + local_6c;
              param_7 = param_7 - local_6c;
              iVar2 = EVP_DigestSignFinal(out_00,auStack_68,&local_70);
              if (iVar2 == 0) goto LAB_00132d82;
            }
            if (((param_4 == (void *)0x0) ||
                (iVar2 = EVP_DigestUpdate(out,param_4,param_5), iVar2 != 0)) &&
               (iVar2 = EVP_DigestSignFinal(out,auStack_68,&local_70), iVar2 != 0)) {
              iVar2 = 1;
              memcpy(param_6,auStack_68,param_7);
              goto LAB_00132cea;
            }
          }
LAB_00132d82:
          iVar2 = 0;
        }
      }
    }
  }
LAB_00132cea:
  EVP_PKEY_free(pkey);
  EVP_MD_CTX_free(out);
  EVP_MD_CTX_free(out_00);
  EVP_MD_CTX_free(ctx);
  OPENSSL_cleanse(auStack_68,0x40);
  return iVar2;
}

