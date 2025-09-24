
EVP_ENCODE_CTX * t_tob64(uchar *param_1,uchar *param_2,int param_3)

{
  EVP_ENCODE_CTX *ctx;
  EVP_ENCODE_CTX *extraout_r0;
  EVP_ENCODE_CTX *extraout_r0_00;
  size_t __n;
  EVP_ENCODE_CTX *pEVar1;
  int inl;
  uchar local_2c [4];
  int local_28;
  int local_24;
  
  ctx = (EVP_ENCODE_CTX *)EVP_ENCODE_CTX_new();
  local_28 = 0;
  local_24 = 0;
  local_2c[0] = '\0';
  local_2c[1] = 0;
  pEVar1 = ctx;
  if (ctx != (EVP_ENCODE_CTX *)0x0) {
    EVP_EncodeInit(ctx);
    evp_encode_ctx_set_flags(ctx,3);
    inl = 3 - param_3 % 3;
    if (param_3 % 3 != 0) {
      EVP_EncodeUpdate(ctx,param_1,&local_28,local_2c,inl);
      pEVar1 = extraout_r0;
      if (extraout_r0 == (EVP_ENCODE_CTX *)0x0) goto LAB_00162c98;
    }
    EVP_EncodeUpdate(ctx,param_1 + local_28,&local_24,param_2,param_3);
    pEVar1 = extraout_r0_00;
    if (extraout_r0_00 == (EVP_ENCODE_CTX *)0x0) {
LAB_00162c98:
      EVP_ENCODE_CTX_free(ctx);
      return pEVar1;
    }
    local_28 = local_24 + local_28;
    EVP_EncodeFinal(ctx,param_1 + local_28,&local_24);
    local_28 = local_24 + local_28;
    if (inl != 3) {
      __n = local_28 - inl;
      memmove(param_1,param_1 + inl,__n);
      param_1[__n] = '\0';
    }
    pEVar1 = (EVP_ENCODE_CTX *)0x1;
    EVP_ENCODE_CTX_free(ctx);
  }
  return pEVar1;
}

