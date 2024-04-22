
void X509_OBJECT_free_contents(X509_OBJECT *a)

{
  if (a->type == 1) {
    X509_free((a->data).x509);
    return;
  }
  if (a->type != 2) {
    return;
  }
  X509_CRL_free((a->data).crl);
  return;
}

