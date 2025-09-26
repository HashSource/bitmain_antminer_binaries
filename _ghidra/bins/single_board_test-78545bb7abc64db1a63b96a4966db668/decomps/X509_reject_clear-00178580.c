
void X509_reject_clear(X509 *x)

{
  if (x[1].rfc3779_asid != (ASIdentifiers_st *)0x0) {
    OPENSSL_sk_pop_free((x[1].rfc3779_asid)->rdi,0x18981d);
    (x[1].rfc3779_asid)->rdi = (ASIdentifierChoice **)0x0;
    return;
  }
  return;
}

