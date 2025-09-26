
void X509_REVOKED_cmp(undefined4 *param_1,undefined4 *param_2)

{
  ASN1_STRING_cmp(*(ASN1_STRING **)*param_1,*(ASN1_STRING **)*param_2);
  return;
}

