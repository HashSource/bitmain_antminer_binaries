
int EVP_SignFinal(EVP_MD_CTX *ctx,uchar *md,uint *s,EVP_PKEY *pkey)

{
  uint uVar1;
  int iVar2;
  EVP_MD *p2;
  EVP_MD_CTX *out;
  uint extraout_r3;
  uint uVar3;
  EVP_PKEY_CTX *ctx_00;
  uint local_70;
  uint local_6c;
  uchar auStack_68 [68];
  
  *s = 0;
  local_70 = 0;
  iVar2 = EVP_MD_CTX_test_flags(ctx,0x200);
  if (iVar2 == 0) {
    out = (EVP_MD_CTX *)EVP_MD_CTX_new();
    if (out == (EVP_MD_CTX *)0x0) {
      ERR_put_error(6,0x6b,0x41,"crypto/evp/p_sign.c",0x22);
      return 0;
    }
    iVar2 = EVP_MD_CTX_copy_ex(out,ctx);
    if (iVar2 == 0) {
      EVP_MD_CTX_free(out);
      return 0;
    }
    iVar2 = EVP_DigestFinal_ex(out,auStack_68,&local_70);
    EVP_MD_CTX_free(out);
    if (iVar2 == 0) {
      return 0;
    }
LAB_001c0966:
    local_6c = EVP_PKEY_size(pkey);
    ctx_00 = EVP_PKEY_CTX_new(pkey,(ENGINE *)0x0);
    if (ctx_00 != (EVP_PKEY_CTX *)0x0) {
      iVar2 = EVP_PKEY_sign_init(ctx_00);
      if (iVar2 < 1) {
        uVar3 = 0;
      }
      else {
        uVar3 = 0;
        p2 = EVP_MD_CTX_md(ctx);
        iVar2 = EVP_PKEY_CTX_ctrl(ctx_00,-1,0xf8,1,0,p2);
        if (0 < iVar2) {
          iVar2 = EVP_PKEY_sign(ctx_00,md,&local_6c,auStack_68,local_70);
          uVar1 = extraout_r3;
          if (0 < iVar2) {
            uVar1 = local_6c;
          }
          uVar3 = (uint)(0 < iVar2);
          if (0 < iVar2) {
            *s = uVar1;
          }
        }
      }
      goto LAB_001c093c;
    }
  }
  else {
    iVar2 = EVP_DigestFinal_ex(ctx,auStack_68,&local_70);
    if (iVar2 != 0) goto LAB_001c0966;
  }
  ctx_00 = (EVP_PKEY_CTX *)0x0;
  uVar3 = 0;
LAB_001c093c:
  EVP_PKEY_CTX_free(ctx_00);
  return uVar3;
}

