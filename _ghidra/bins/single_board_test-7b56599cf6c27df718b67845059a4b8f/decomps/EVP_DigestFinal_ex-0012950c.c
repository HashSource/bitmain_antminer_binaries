
int EVP_DigestFinal_ex(EVP_MD_CTX *ctx,uchar *md,uint *s)

{
  int iVar1;
  EVP_MD *pEVar2;
  
  if (ctx->digest->md_size < 0x41) {
    iVar1 = (*ctx->digest->final)(ctx,md);
    pEVar2 = ctx->digest;
    if (s != (uint *)0x0) {
      *s = pEVar2->md_size;
    }
    if (pEVar2->cleanup != (_func_1224 *)0x0) {
      (*pEVar2->cleanup)(ctx);
      EVP_MD_CTX_set_flags(ctx,2);
      pEVar2 = ctx->digest;
    }
    OPENSSL_cleanse(ctx->md_data,(size_t)pEVar2->verify);
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  OPENSSL_die("assertion failed: ctx->digest->md_size <= EVP_MAX_MD_SIZE","crypto/evp/digest.c",0xb7
             );
}

