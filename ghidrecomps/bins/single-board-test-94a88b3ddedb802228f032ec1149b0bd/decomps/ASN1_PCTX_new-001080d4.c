
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ASN1_PCTX * ASN1_PCTX_new(void)

{
  ASN1_PCTX *pAVar1;
  
  pAVar1 = (ASN1_PCTX *)CRYPTO_malloc(0x14,"tasn_prn.c",0x57);
  if (pAVar1 == (ASN1_PCTX *)0x0) {
    ERR_put_error(0xd,0xcd,0x41,"tasn_prn.c",0x59);
  }
  else {
    *(undefined4 *)pAVar1 = 0;
    *(undefined4 *)(pAVar1 + 4) = 0;
    *(undefined4 *)(pAVar1 + 8) = 0;
    *(undefined4 *)(pAVar1 + 0xc) = 0;
    *(undefined4 *)(pAVar1 + 0x10) = 0;
  }
  return pAVar1;
}

