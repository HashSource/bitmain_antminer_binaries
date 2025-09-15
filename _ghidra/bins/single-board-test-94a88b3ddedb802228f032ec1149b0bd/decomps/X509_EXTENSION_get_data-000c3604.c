
ASN1_OCTET_STRING * X509_EXTENSION_get_data(X509_EXTENSION *ne)

{
  if (ne != (X509_EXTENSION *)0x0) {
    ne = (X509_EXTENSION *)ne->value;
  }
  return (ASN1_OCTET_STRING *)ne;
}

