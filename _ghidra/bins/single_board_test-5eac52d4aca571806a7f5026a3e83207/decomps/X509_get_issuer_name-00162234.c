
X509_NAME * X509_get_issuer_name(X509 *a)

{
  return (X509_NAME *)(a->ex_data).dummy;
}

