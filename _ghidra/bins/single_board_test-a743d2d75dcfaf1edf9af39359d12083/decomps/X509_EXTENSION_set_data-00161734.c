
int X509_EXTENSION_set_data(X509_EXTENSION *ex,ASN1_OCTET_STRING *data)

{
  if ((ex != (X509_EXTENSION *)0x0) &&
     (ex = (X509_EXTENSION *)ASN1_STRING_set(ex->value,data->data,data->length),
     ex != (X509_EXTENSION *)0x0)) {
    ex = (X509_EXTENSION *)0x1;
  }
  return (int)ex;
}

