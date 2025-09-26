
ASN1_INTEGER * X509_get_serialNumber(X509 *x)

{
  return (ASN1_INTEGER *)&x->sig_alg;
}

