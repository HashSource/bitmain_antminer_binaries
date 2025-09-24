
int rsa_sig_info_set(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  RSA_PSS_PARAMS *a;
  int iVar2;
  int iVar3;
  RSA_PSS_PARAMS *a_00;
  X509_ALGOR *pXVar4;
  undefined4 uVar5;
  int local_24;
  EVP_MD *local_20;
  EVP_MD *local_1c;
  
  local_20 = (EVP_MD *)0x0;
  local_1c = (EVP_MD *)0x0;
  iVar1 = OBJ_obj2nid((ASN1_OBJECT *)*param_2);
  if (iVar1 != 0x390) {
    return 0;
  }
  a = (RSA_PSS_PARAMS *)ASN1_TYPE_unpack_sequence(RSA_PSS_PARAMS_it,param_2[1]);
  a_00 = a;
  if ((a != (RSA_PSS_PARAMS *)0x0) && (pXVar4 = a->maskGenAlgorithm, pXVar4 != (X509_ALGOR *)0x0)) {
    iVar1 = OBJ_obj2nid(pXVar4->algorithm);
    if (iVar1 == 0x38f) {
      pXVar4 = (X509_ALGOR *)ASN1_TYPE_unpack_sequence(X509_ALGOR_it,pXVar4->parameter);
      a[1].hashAlgorithm = pXVar4;
      if (pXVar4 != (X509_ALGOR *)0x0) goto LAB_0014ed1e;
    }
    else {
      a[1].hashAlgorithm = (X509_ALGOR *)0x0;
    }
    a_00 = (RSA_PSS_PARAMS *)0x0;
    RSA_PSS_PARAMS_free(a);
  }
LAB_0014ed1e:
  iVar1 = rsa_pss_get_param(a_00,&local_1c,&local_20,&local_24);
  if (iVar1 != 0) {
    iVar2 = EVP_MD_type(local_1c);
    if (((iVar2 - 0x2a0U < 3) && (iVar1 = EVP_MD_type(local_20), iVar2 == iVar1)) &&
       (iVar1 = EVP_MD_size(local_1c), iVar1 == local_24)) {
      uVar5 = 2;
    }
    else {
      uVar5 = 0;
    }
    iVar1 = 1;
    iVar3 = EVP_MD_size(local_1c);
    X509_SIG_INFO_set(param_1,iVar2,0x390,iVar3 << 2,uVar5);
  }
  RSA_PSS_PARAMS_free(a_00);
  return iVar1;
}

