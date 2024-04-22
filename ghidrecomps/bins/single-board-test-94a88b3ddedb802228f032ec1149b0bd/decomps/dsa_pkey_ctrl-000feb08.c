
undefined4
dsa_pkey_ctrl(EVP_PKEY *param_1,undefined4 param_2,void *param_3,PKCS7_SIGNER_INFO *param_4)

{
  int iVar1;
  int pkey_nid;
  ASN1_OBJECT *aobj;
  undefined4 uVar2;
  int local_1c;
  X509_ALGOR *local_18;
  X509_ALGOR *local_14;
  
  switch(param_2) {
  case 1:
    if (param_3 != (void *)0x0) {
      return 1;
    }
    PKCS7_SIGNER_INFO_get0_algs(param_4,(EVP_PKEY **)0x0,&local_18,&local_14);
    goto joined_r0x000feba6;
  default:
    uVar2 = 0xfffffffe;
    break;
  case 3:
    uVar2 = 2;
    param_4->version = (ASN1_INTEGER *)0x2a0;
    break;
  case 5:
    if (param_3 != (void *)0x0) {
      return 1;
    }
    CMS_SignerInfo_get0_algs
              ((CMS_SignerInfo *)param_4,(EVP_PKEY **)0x0,(X509 **)0x0,&local_18,&local_14);
joined_r0x000feba6:
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
    uVar2 = 0xffffffff;
    break;
  case 8:
    uVar2 = 1;
    param_4->version = (ASN1_INTEGER *)0xffffffff;
  }
  return uVar2;
}

