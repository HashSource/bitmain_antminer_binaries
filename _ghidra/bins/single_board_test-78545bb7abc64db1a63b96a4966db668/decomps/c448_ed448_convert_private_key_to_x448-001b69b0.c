
undefined4 c448_ed448_convert_private_key_to_x448(undefined4 param_1,void *param_2)

{
  EVP_MD_CTX *ctx;
  EVP_MD *type;
  int iVar1;
  
  ctx = (EVP_MD_CTX *)EVP_MD_CTX_new();
  if (ctx != (EVP_MD_CTX *)0x0) {
    type = (EVP_MD *)EVP_shake256();
    iVar1 = EVP_DigestInit_ex(ctx,type,(ENGINE *)0x0);
    if (((iVar1 != 0) && (iVar1 = EVP_DigestUpdate(ctx,param_2,0x39), iVar1 != 0)) &&
       (iVar1 = EVP_DigestFinalXOF(ctx,param_1,0x38), iVar1 != 0)) {
      EVP_MD_CTX_free(ctx);
      return 0xffffffff;
    }
    EVP_MD_CTX_free(ctx);
  }
  return 0;
}

