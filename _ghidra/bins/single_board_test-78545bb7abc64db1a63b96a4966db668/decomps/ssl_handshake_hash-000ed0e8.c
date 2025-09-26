
undefined4 ssl_handshake_hash(int param_1,uchar *param_2,uint param_3,uint *param_4)

{
  EVP_MD *md;
  uint uVar1;
  EVP_MD_CTX *out;
  int iVar2;
  undefined4 uVar3;
  EVP_MD_CTX *ctx;
  
  ctx = *(EVP_MD_CTX **)(*(int *)(param_1 + 0x7c) + 0xd8);
  md = EVP_MD_CTX_md(ctx);
  uVar1 = EVP_MD_size(md);
  if (param_3 < uVar1 || (int)uVar1 < 0) {
    ossl_statem_fatal(param_1,0x50,0x230,0x44,"ssl/ssl_lib.c",0x11e2);
    EVP_MD_CTX_free(0);
    return 0;
  }
  out = (EVP_MD_CTX *)EVP_MD_CTX_new();
  if (out == (EVP_MD_CTX *)0x0) {
    uVar3 = 0x11e9;
  }
  else {
    iVar2 = EVP_MD_CTX_copy_ex(out,ctx);
    if ((iVar2 != 0) && (iVar2 = EVP_DigestFinal_ex(out,param_2,(uint *)0x0), 0 < iVar2)) {
      *param_4 = uVar1;
      EVP_MD_CTX_free(out);
      return 1;
    }
    uVar3 = 0x11f0;
  }
  ossl_statem_fatal(param_1,0x50,0x230,0x44,"ssl/ssl_lib.c",uVar3);
  EVP_MD_CTX_free(out);
  return 0;
}

