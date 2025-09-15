
void ocsp_nonce_free(ASN1_STRING *a)

{
  if (a != (ASN1_STRING *)0x0) {
    if ((a->data != (uchar *)0x0) && (-1 < a->flags << 0x1b)) {
      CRYPTO_free(a->data);
    }
    CRYPTO_free(a);
    return;
  }
  return;
}

