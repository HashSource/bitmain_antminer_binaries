
int EVP_DigestUpdate(EVP_MD_CTX *ctx,void *d,size_t cnt)

{
  int iVar1;
  
  if (cnt == 0) {
    return 1;
  }
                    /* WARNING: Could not recover jumptable at 0x00129508. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*ctx->update)(ctx,d,cnt);
  return iVar1;
}

