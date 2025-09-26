
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ASN1_PCTX * ASN1_PCTX_new(void)

{
  ASN1_PCTX *pAVar1;
  
  pAVar1 = (ASN1_PCTX *)CRYPTO_zalloc(0x14,"crypto/asn1/tasn_prn.c",0x27);
  if (pAVar1 == (ASN1_PCTX *)0x0) {
    ERR_put_error(0xd,0xcd,0x41,"crypto/asn1/tasn_prn.c",0x29);
  }
  return pAVar1;
}

