
int SCT_CTX_new(void)

{
  int iVar1;
  
  iVar1 = CRYPTO_zalloc(0x30,"crypto/ct/ct_sct_ctx.c",0x19);
  if (iVar1 != 0) {
    return iVar1;
  }
  ERR_put_error(0x32,0x7e,0x41,"crypto/ct/ct_sct_ctx.c",0x1c);
  return 0;
}

