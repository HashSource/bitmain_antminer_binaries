
undefined4
rsa_pss_get_param(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,long *param_4)

{
  int iVar1;
  char *pcVar2;
  EVP_MD *pEVar3;
  long lVar4;
  
  if (param_1 == (undefined4 *)0x0) {
    return 0;
  }
  if ((undefined4 *)*param_1 == (undefined4 *)0x0) {
    pEVar3 = EVP_sha1();
    *param_2 = pEVar3;
    if (pEVar3 == (EVP_MD *)0x0) {
      return 0;
    }
  }
  else {
    iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)*param_1);
    pcVar2 = OBJ_nid2sn(iVar1);
    pEVar3 = EVP_get_digestbyname(pcVar2);
    if (pEVar3 == (EVP_MD *)0x0) {
      ERR_put_error(4,0x9c,0xa6,"crypto/rsa/rsa_ameth.c",0x249);
      *param_2 = 0;
      return 0;
    }
    *param_2 = pEVar3;
  }
  if ((undefined4 *)param_1[4] == (undefined4 *)0x0) {
    pEVar3 = EVP_sha1();
    *param_3 = pEVar3;
    if (pEVar3 == (EVP_MD *)0x0) {
      return 0;
    }
  }
  else {
    iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)param_1[4]);
    pcVar2 = OBJ_nid2sn(iVar1);
    pEVar3 = EVP_get_digestbyname(pcVar2);
    if (pEVar3 == (EVP_MD *)0x0) {
      ERR_put_error(4,0x9c,0xa6,"crypto/rsa/rsa_ameth.c",0x249);
      *param_3 = 0;
      return 0;
    }
    *param_3 = pEVar3;
  }
  if ((ASN1_INTEGER *)param_1[2] == (ASN1_INTEGER *)0x0) {
    *param_4 = 0x14;
  }
  else {
    lVar4 = ASN1_INTEGER_get((ASN1_INTEGER *)param_1[2]);
    *param_4 = lVar4;
    if (lVar4 < 0) {
      ERR_put_error(4,0x97,0x96,"crypto/rsa/rsa_ameth.c",0x2db);
      return 0;
    }
  }
  if (((ASN1_INTEGER *)param_1[3] != (ASN1_INTEGER *)0x0) &&
     (lVar4 = ASN1_INTEGER_get((ASN1_INTEGER *)param_1[3]), lVar4 != 1)) {
    ERR_put_error(4,0x97,0x8b,"crypto/rsa/rsa_ameth.c",0x2e7);
    return 0;
  }
  return 1;
}

