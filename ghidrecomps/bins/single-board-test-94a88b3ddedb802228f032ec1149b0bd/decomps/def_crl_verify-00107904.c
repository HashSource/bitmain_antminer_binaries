
void def_crl_verify(void **param_1,EVP_PKEY *param_2)

{
  ASN1_item_verify((ASN1_ITEM *)&X509_CRL_INFO_it,(X509_ALGOR *)param_1[1],
                   (ASN1_BIT_STRING *)param_1[2],*param_1,param_2);
  return;
}

