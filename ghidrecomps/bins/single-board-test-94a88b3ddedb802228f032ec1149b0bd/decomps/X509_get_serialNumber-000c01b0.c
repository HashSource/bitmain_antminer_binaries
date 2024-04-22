
ASN1_INTEGER * X509_get_serialNumber(X509 *x)

{
  return x->cert_info->serialNumber;
}

