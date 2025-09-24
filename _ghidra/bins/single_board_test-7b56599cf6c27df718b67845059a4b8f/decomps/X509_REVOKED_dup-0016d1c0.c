
void X509_REVOKED_dup(void *param_1)

{
  ASN1_item_dup((ASN1_ITEM *)X509_REVOKED_it,param_1);
  return;
}

