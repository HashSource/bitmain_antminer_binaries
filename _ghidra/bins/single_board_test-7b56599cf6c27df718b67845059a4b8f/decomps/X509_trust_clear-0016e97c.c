
void X509_trust_clear(X509 *x)

{
  if (x[1].rfc3779_asid != (ASIdentifiers_st *)0x0) {
    OPENSSL_sk_pop_free((x[1].rfc3779_asid)->asnum,0x17fc45);
    (x[1].rfc3779_asid)->asnum = (ASIdentifierChoice *)0x0;
    return;
  }
  return;
}

