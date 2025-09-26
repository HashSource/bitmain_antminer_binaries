
undefined4 OCSP_resp_get1_id(int param_1,int *param_2,int *param_3)

{
  X509_NAME *pXVar1;
  ASN1_STRING *pAVar2;
  
  if (*(int *)(param_1 + 4) == 0) {
    pXVar1 = X509_NAME_dup(*(X509_NAME **)(param_1 + 8));
    *param_3 = (int)pXVar1;
    *param_2 = 0;
    if (*param_3 != 0) {
      return 1;
    }
  }
  else if (*(int *)(param_1 + 4) == 1) {
    pAVar2 = ASN1_OCTET_STRING_dup(*(ASN1_STRING **)(param_1 + 8));
    *param_2 = (int)pAVar2;
    *param_3 = 0;
    if (*param_2 != 0) {
      return 1;
    }
  }
  return 0;
}

