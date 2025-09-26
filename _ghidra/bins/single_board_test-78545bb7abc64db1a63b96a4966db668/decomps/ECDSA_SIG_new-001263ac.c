
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ECDSA_SIG * ECDSA_SIG_new(void)

{
  ECDSA_SIG *pEVar1;
  
  pEVar1 = (ECDSA_SIG *)CRYPTO_zalloc(8,"crypto/ec/ec_asn1.c",0x4f2);
  if (pEVar1 != (ECDSA_SIG *)0x0) {
    return pEVar1;
  }
  ERR_put_error(0x10,0x109,0x41,"crypto/ec/ec_asn1.c",0x4f4);
  return (ECDSA_SIG *)0x0;
}

