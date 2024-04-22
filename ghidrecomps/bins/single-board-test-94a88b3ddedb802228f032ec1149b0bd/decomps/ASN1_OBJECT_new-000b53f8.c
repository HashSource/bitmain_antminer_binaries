
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ASN1_OBJECT * ASN1_OBJECT_new(void)

{
  ASN1_OBJECT *pAVar1;
  
  pAVar1 = (ASN1_OBJECT *)CRYPTO_malloc(0x18,DAT_000b5438,0x15a);
  if (pAVar1 == (ASN1_OBJECT *)0x0) {
    ERR_put_error(0xd,0x7b,0x41,DAT_000b5438,0x15c);
  }
  else {
    pAVar1->length = 0;
    pAVar1->data = (uchar *)0x0;
    pAVar1->nid = 0;
    pAVar1->sn = (char *)0x0;
    pAVar1->ln = (char **)0x0;
    pAVar1->flags = 1;
  }
  return pAVar1;
}

