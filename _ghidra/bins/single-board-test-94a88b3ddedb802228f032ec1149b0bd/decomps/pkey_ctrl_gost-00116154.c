
undefined4
pkey_ctrl_gost(EVP_PKEY *param_1,undefined4 param_2,X509_ALGOR *param_3,PKCS7_SIGNER_INFO *param_4)

{
  X509_ALGOR *pXVar1;
  ASN1_OBJECT *pAVar2;
  int n;
  void *pval;
  X509_ALGOR *local_20;
  X509_ALGOR *local_1c [2];
  
  local_20 = param_3;
  switch(param_2) {
  case 1:
    if (param_3 != (X509_ALGOR *)0x0) {
      return 1;
    }
    local_1c[0] = param_3;
    n = EVP_PKEY_base_id(param_1);
    PKCS7_SIGNER_INFO_get0_algs(param_4,(EVP_PKEY **)0x0,&local_20,local_1c);
    break;
  case 2:
    if (param_3 != (X509_ALGOR *)0x0) {
      return 1;
    }
    pval = (void *)encode_gost_algor_params();
    if (pval == (void *)0x0) {
      return 0xffffffff;
    }
    PKCS7_RECIP_INFO_get0_alg((PKCS7_RECIP_INFO *)param_4,local_1c);
    goto LAB_001161e2;
  case 3:
    param_4->version = (ASN1_INTEGER *)0x329;
    return 2;
  default:
    return 0xfffffffe;
  case 5:
    if (param_3 != (X509_ALGOR *)0x0) {
      return 1;
    }
    local_1c[0] = param_3;
    n = EVP_PKEY_base_id(param_1);
    CMS_SignerInfo_get0_algs
              ((CMS_SignerInfo *)param_4,(EVP_PKEY **)0x0,(X509 **)0x0,&local_20,local_1c);
    break;
  case 7:
    if (param_3 != (X509_ALGOR *)0x0) {
      return 1;
    }
    local_1c[0] = param_3;
    pval = (void *)encode_gost_algor_params();
    if (pval == (void *)0x0) {
      return 0xffffffff;
    }
    CMS_RecipientInfo_ktri_get0_algs
              ((CMS_RecipientInfo *)param_4,(EVP_PKEY **)0x0,(X509 **)0x0,local_1c);
LAB_001161e2:
    pXVar1 = local_1c[0];
    pAVar2 = OBJ_nid2obj(param_1->type);
    X509_ALGOR_set0(pXVar1,pAVar2,0x10,pval);
    return 1;
  }
  pXVar1 = local_20;
  pAVar2 = OBJ_nid2obj(0x329);
  X509_ALGOR_set0(pXVar1,pAVar2,5,param_3);
  pXVar1 = local_1c[0];
  if (n == 0) {
    return 0xffffffff;
  }
  pAVar2 = OBJ_nid2obj(n);
  X509_ALGOR_set0(pXVar1,pAVar2,5,param_3);
  return 1;
}

