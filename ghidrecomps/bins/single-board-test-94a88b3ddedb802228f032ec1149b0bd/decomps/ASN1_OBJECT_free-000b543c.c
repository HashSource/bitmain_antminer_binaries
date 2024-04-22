
void ASN1_OBJECT_free(ASN1_OBJECT *a)

{
  int iVar1;
  
  if (a != (ASN1_OBJECT *)0x0) {
    iVar1 = a->flags;
    if (iVar1 << 0x1d < 0) {
      if (a->sn != (char *)0x0) {
        CRYPTO_free(a->sn);
      }
      if (a->ln != (char **)0x0) {
        CRYPTO_free(a->ln);
      }
      iVar1 = a->flags;
      a->ln = (char **)0x0;
      a->sn = (char *)0x0;
    }
    if (iVar1 << 0x1c < 0) {
      if (a->data != (uchar *)0x0) {
        CRYPTO_free(a->data);
        iVar1 = a->flags;
      }
      a->data = (uchar *)0x0;
      a->length = 0;
    }
    if (iVar1 << 0x1f < 0) {
      CRYPTO_free(a);
      return;
    }
  }
  return;
}

