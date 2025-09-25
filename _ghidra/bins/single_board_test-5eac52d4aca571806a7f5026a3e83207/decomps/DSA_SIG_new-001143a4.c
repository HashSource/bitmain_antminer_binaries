
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

DSA_SIG * DSA_SIG_new(void)

{
  DSA_SIG *pDVar1;
  
  pDVar1 = (DSA_SIG *)CRYPTO_zalloc(8,"crypto/dsa/dsa_asn1.c",0x1a);
  if (pDVar1 != (DSA_SIG *)0x0) {
    return pDVar1;
  }
  ERR_put_error(10,0x66,0x41,"crypto/dsa/dsa_asn1.c",0x1c);
  return (DSA_SIG *)0x0;
}

