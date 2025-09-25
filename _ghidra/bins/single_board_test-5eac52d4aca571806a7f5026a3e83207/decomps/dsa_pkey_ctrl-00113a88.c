
undefined4
dsa_pkey_ctrl(EVP_PKEY *param_1,undefined4 param_2,void *param_3,PKCS7_SIGNER_INFO *param_4)

{
  int iVar1;
  int pkey_nid;
  ASN1_OBJECT *aobj;
  int local_1c;
  X509_ALGOR *local_18;
  X509_ALGOR *local_14;
  
  switch(param_2) {
  case 1:
    if (param_3 != (void *)0x0) {
      return 1;
    }
    PKCS7_SIGNER_INFO_get0_algs(param_4,(EVP_PKEY **)0x0,&local_18,&local_14);
    break;
  default:
    return 0xfffffffe;
  case 3:
    param_4->version = (ASN1_INTEGER *)0x2a0;
    return 1;
  case 5:
    if (param_3 != (void *)0x0) {
      return 1;
    }
    CMS_SignerInfo_get0_algs
              ((CMS_SignerInfo *)param_4,(EVP_PKEY **)0x0,(X509 **)0x0,&local_18,&local_14);
    break;
  case 8:
    param_4->version = (ASN1_INTEGER *)0xffffffff;
    return 1;
  }
  if (((local_18 != (X509_ALGOR *)0x0) && (local_18->algorithm != (ASN1_OBJECT *)0x0)) &&
     (iVar1 = OBJ_obj2nid(local_18->algorithm), iVar1 != 0)) {
    pkey_nid = EVP_PKEY_id(param_1);
    iVar1 = OBJ_find_sigid_by_algs(&local_1c,iVar1,pkey_nid);
    if (iVar1 != 0) {
      aobj = OBJ_nid2obj(local_1c);
      X509_ALGOR_set0(local_14,aobj,-1,param_3);
      return 1;
    }
  }
  return 0xffffffff;
}

