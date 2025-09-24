
undefined4 c448_ed448_derive_public_key(undefined4 param_1,void *param_2)

{
  EVP_MD_CTX *ctx;
  EVP_MD *type;
  int iVar1;
  undefined1 auStack_1a0 [268];
  undefined1 auStack_94 [56];
  byte local_5c [55];
  byte local_25;
  undefined1 local_24;
  
  ctx = (EVP_MD_CTX *)EVP_MD_CTX_new();
  if (ctx != (EVP_MD_CTX *)0x0) {
    type = (EVP_MD *)EVP_shake256();
    iVar1 = EVP_DigestInit_ex(ctx,type,(ENGINE *)0x0);
    if ((iVar1 != 0) && (iVar1 = EVP_DigestUpdate(ctx,param_2,0x39), iVar1 != 0)) {
      iVar1 = EVP_DigestFinalXOF(ctx,local_5c,0x39);
      if (iVar1 != 0) {
        EVP_MD_CTX_free(ctx);
        local_24 = 0;
        local_5c[0] = local_5c[0] & 0xfc;
        local_25 = local_25 | 0x80;
        curve448_scalar_decode_long(auStack_94,local_5c,0x39);
        curve448_scalar_halve(auStack_94,auStack_94);
        curve448_scalar_halve(auStack_94,auStack_94);
        curve448_precomputed_scalarmul(auStack_1a0,curve448_precomputed_base,auStack_94);
        curve448_point_mul_by_ratio_and_encode_like_eddsa(param_1,auStack_1a0);
        curve448_scalar_destroy(auStack_94);
        curve448_point_destroy(auStack_1a0);
        OPENSSL_cleanse(local_5c,0x39);
        return 0xffffffff;
      }
    }
    EVP_MD_CTX_free(ctx);
  }
  return 0;
}

