
ASN1_OCTET_STRING * s2i_skey_id(X509V3_EXT_METHOD *param_1,X509V3_CTX *param_2,char *param_3)

{
  int iVar1;
  ASN1_OCTET_STRING *pAVar2;
  EVP_MD *type;
  X509_PUBKEY *pub;
  uchar *local_64;
  size_t local_60;
  uint local_5c;
  uchar auStack_58 [68];
  
  iVar1 = strcmp(param_3,"hash");
  if (iVar1 != 0) {
    pAVar2 = s2i_ASN1_OCTET_STRING(param_1,param_2,param_3);
    return pAVar2;
  }
  pAVar2 = ASN1_OCTET_STRING_new();
  if (pAVar2 == (ASN1_OCTET_STRING *)0x0) {
    ERR_put_error(0x22,0x73,0x41,"crypto/x509v3/v3_skey.c",0x45);
    return (ASN1_OCTET_STRING *)0x0;
  }
  if (param_2 == (X509V3_CTX *)0x0) {
LAB_00178de8:
    iVar1 = 0x4d;
  }
  else {
    if (param_2->flags == 1) {
      return pAVar2;
    }
    if (param_2->subject_req == (X509_REQ *)0x0) {
      if (param_2->subject_cert == (X509 *)0x0) goto LAB_00178de8;
      pub = (X509_PUBKEY *)param_2->subject_cert->ex_kusage;
    }
    else {
      pub = (X509_PUBKEY *)param_2->subject_req[1].sig_alg;
    }
    if (pub != (X509_PUBKEY *)0x0) {
      X509_PUBKEY_get0_param((ASN1_OBJECT **)0x0,&local_64,(int *)&local_60,(X509_ALGOR **)0x0,pub);
      type = EVP_sha1();
      iVar1 = EVP_Digest(local_64,local_60,auStack_58,&local_5c,type,(ENGINE *)0x0);
      if (iVar1 != 0) {
        iVar1 = ASN1_OCTET_STRING_set(pAVar2,auStack_58,local_5c);
        if (iVar1 != 0) {
          return pAVar2;
        }
        ERR_put_error(0x22,0x73,0x41,"crypto/x509v3/v3_skey.c",0x61);
      }
      goto LAB_00178dc0;
    }
    iVar1 = 0x57;
  }
  ERR_put_error(0x22,0x73,0x72,"crypto/x509v3/v3_skey.c",iVar1);
LAB_00178dc0:
  ASN1_OCTET_STRING_free(pAVar2);
  return (ASN1_OCTET_STRING *)0x0;
}

