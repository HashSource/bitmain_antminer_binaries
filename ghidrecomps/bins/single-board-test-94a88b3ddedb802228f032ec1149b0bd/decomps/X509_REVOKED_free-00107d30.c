
void X509_REVOKED_free(X509_REVOKED *a)

{
  ASN1_item_free((ASN1_VALUE *)a,DAT_00107d38);
  return;
}

