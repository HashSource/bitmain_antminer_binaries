
void ASN1_BIT_STRING_free(ASN1_STRING *a)

{
  if (a != (ASN1_STRING *)0x0) {
    asn1_string_embed_free(a,a->flags & 0x80);
    return;
  }
  return;
}

