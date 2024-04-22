
uchar * HMAC(EVP_MD *evp_md,void *key,int key_len,uchar *d,size_t n,uchar *md,uint *md_len)

{
  uchar *puVar1;
  int iVar2;
  size_t local_134;
  uchar auStack_130 [64];
  HMAC_CTX local_f0;
  
  puVar1 = DAT_000977a4;
  EVP_MD_CTX_init(&local_f0.i_ctx);
  if (md == (uchar *)0x0) {
    md = puVar1;
  }
  EVP_MD_CTX_init(&local_f0.o_ctx);
  EVP_MD_CTX_init(&local_f0.md_ctx);
  local_f0.md = (EVP_MD *)0x0;
  if (key != (void *)0x0 && evp_md != (EVP_MD *)0x0) {
    EVP_MD_CTX_init(&local_f0.i_ctx);
    EVP_MD_CTX_init(&local_f0.o_ctx);
    EVP_MD_CTX_init(&local_f0.md_ctx);
  }
  local_f0.md = (EVP_MD *)0x0;
  iVar2 = HMAC_Init_ex(&local_f0,key,key_len,evp_md,(ENGINE *)0x0);
  if (((((iVar2 == 0) || (local_f0.md == (EVP_MD *)0x0)) ||
       (iVar2 = EVP_DigestUpdate(&local_f0.md_ctx,d,n), iVar2 == 0)) ||
      ((local_f0.md == (EVP_MD *)0x0 ||
       (iVar2 = EVP_DigestFinal_ex(&local_f0.md_ctx,auStack_130,&local_134), iVar2 == 0)))) ||
     ((iVar2 = EVP_MD_CTX_copy_ex(&local_f0.md_ctx,&local_f0.o_ctx), iVar2 == 0 ||
      ((iVar2 = EVP_DigestUpdate(&local_f0.md_ctx,auStack_130,local_134), iVar2 == 0 ||
       (iVar2 = EVP_DigestFinal_ex(&local_f0.md_ctx,md,md_len), iVar2 == 0)))))) {
    md = (uchar *)0x0;
    EVP_MD_CTX_cleanup(&local_f0.i_ctx);
    EVP_MD_CTX_cleanup(&local_f0.o_ctx);
    EVP_MD_CTX_cleanup(&local_f0.md_ctx);
    memset(&local_f0,0,0xd0);
  }
  else {
    EVP_MD_CTX_cleanup(&local_f0.i_ctx);
    EVP_MD_CTX_cleanup(&local_f0.o_ctx);
    EVP_MD_CTX_cleanup(&local_f0.md_ctx);
    memset(&local_f0,0,0xd0);
  }
  return md;
}

