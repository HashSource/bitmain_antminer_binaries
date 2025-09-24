
uint rsa_sig_print(BIO *param_1,undefined4 *param_2,ASN1_STRING *param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  RSA_PSS_PARAMS *a;
  int iVar3;
  RSA_PSS_PARAMS *a_00;
  X509_ALGOR *pXVar4;
  
  iVar3 = param_4;
  iVar1 = OBJ_obj2nid((ASN1_OBJECT *)*param_2);
  if (iVar1 != 0x390) {
    if (param_3 == (ASN1_STRING *)0x0) {
      iVar3 = BIO_puts(param_1,"\n");
      return (uint)(0 < iVar3);
    }
    goto LAB_0014e82e;
  }
  a = (RSA_PSS_PARAMS *)ASN1_TYPE_unpack_sequence(RSA_PSS_PARAMS_it,param_2[1]);
  a_00 = a;
  if ((a != (RSA_PSS_PARAMS *)0x0) && (pXVar4 = a->maskGenAlgorithm, pXVar4 != (X509_ALGOR *)0x0)) {
    iVar1 = OBJ_obj2nid(pXVar4->algorithm);
    if (iVar1 == 0x38f) {
      pXVar4 = (X509_ALGOR *)ASN1_TYPE_unpack_sequence(X509_ALGOR_it,pXVar4->parameter);
      a[1].hashAlgorithm = pXVar4;
      if (pXVar4 != (X509_ALGOR *)0x0) goto LAB_0014e874;
    }
    else {
      a[1].hashAlgorithm = (X509_ALGOR *)0x0;
    }
    a_00 = (RSA_PSS_PARAMS *)0x0;
    RSA_PSS_PARAMS_free(a);
  }
LAB_0014e874:
  iVar3 = rsa_pss_param_print(param_1,0,a_00,param_4,iVar3);
  RSA_PSS_PARAMS_free(a_00);
  if (iVar3 == 0) {
    return 0;
  }
  if (param_3 == (ASN1_STRING *)0x0) {
    return 1;
  }
LAB_0014e82e:
  uVar2 = X509_signature_dump(param_1,param_3,param_4);
  return uVar2;
}

