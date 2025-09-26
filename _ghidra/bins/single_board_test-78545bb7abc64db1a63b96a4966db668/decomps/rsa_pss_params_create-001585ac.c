
RSA_PSS_PARAMS * rsa_pss_params_create(EVP_MD *param_1,EVP_MD *param_2,int param_3)

{
  RSA_PSS_PARAMS *a;
  ASN1_INTEGER *a_00;
  int iVar1;
  X509_ALGOR *pXVar2;
  
  a = RSA_PSS_PARAMS_new();
  if (a != (RSA_PSS_PARAMS *)0x0) {
    if (param_3 != 0x14) {
      a_00 = ASN1_INTEGER_new();
      a->saltLength = a_00;
      if ((a_00 == (ASN1_INTEGER *)0x0) || (iVar1 = ASN1_INTEGER_set(a_00,param_3), iVar1 == 0))
      goto LAB_00158612;
    }
    if ((param_1 != (EVP_MD *)0x0) && (iVar1 = EVP_MD_type(param_1), iVar1 != 0x40)) {
      pXVar2 = X509_ALGOR_new();
      a->hashAlgorithm = pXVar2;
      if (pXVar2 == (X509_ALGOR *)0x0) goto LAB_00158612;
      X509_ALGOR_set_md(pXVar2,param_1);
    }
    if (param_2 == (EVP_MD *)0x0) {
      iVar1 = rsa_md_to_mgf1(&a->maskGenAlgorithm,param_1);
      if (iVar1 == 0) goto LAB_00158612;
      if (param_1 == (EVP_MD *)0x0) {
        return a;
      }
    }
    else {
      iVar1 = rsa_md_to_mgf1(&a->maskGenAlgorithm,param_2);
      param_1 = param_2;
      if (iVar1 == 0) goto LAB_00158612;
    }
    iVar1 = EVP_MD_type(param_1);
    if (iVar1 != 0x40) {
      pXVar2 = X509_ALGOR_new();
      a[1].hashAlgorithm = pXVar2;
      if (pXVar2 == (X509_ALGOR *)0x0) goto LAB_00158612;
      X509_ALGOR_set_md(pXVar2,param_1);
    }
    return a;
  }
LAB_00158612:
  RSA_PSS_PARAMS_free(a);
  return (RSA_PSS_PARAMS *)0x0;
}

