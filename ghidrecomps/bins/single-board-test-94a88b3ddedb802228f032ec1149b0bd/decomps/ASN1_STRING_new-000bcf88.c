
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ASN1_STRING * ASN1_STRING_new(void)

{
  ASN1_STRING *pAVar1;
  
  pAVar1 = (ASN1_STRING *)CRYPTO_malloc(0x10,DAT_000bcfc4,0x19c);
  if (pAVar1 == (ASN1_STRING *)0x0) {
    ERR_put_error(0xd,0x82,0x41,DAT_000bcfc4,0x19e);
  }
  else {
    pAVar1->length = 0;
    pAVar1->data = (uchar *)0x0;
    pAVar1->flags = 0;
    pAVar1->type = 4;
  }
  return pAVar1;
}

