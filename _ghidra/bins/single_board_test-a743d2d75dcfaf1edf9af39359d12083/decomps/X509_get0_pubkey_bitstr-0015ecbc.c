
ASN1_BIT_STRING * X509_get0_pubkey_bitstr(X509 *x)

{
  if (x != (X509 *)0x0) {
    x = (X509 *)x->cert_info->key->public_key;
  }
  return (ASN1_BIT_STRING *)x;
}

