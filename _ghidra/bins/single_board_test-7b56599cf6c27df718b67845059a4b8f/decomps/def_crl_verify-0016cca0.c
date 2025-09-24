
void def_crl_verify(void *param_1,EVP_PKEY *param_2)

{
  ASN1_item_verify((ASN1_ITEM *)X509_CRL_INFO_it,(X509_ALGOR *)((int)param_1 + 0x2c),
                   (ASN1_BIT_STRING *)((int)param_1 + 0x34),param_1,param_2);
  return;
}

