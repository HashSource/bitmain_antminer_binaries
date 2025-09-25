
X509_EXTENSION * X509V3_EXT_nconf_nid(CONF *conf,X509V3_CTX *ctx,int ext_nid,char *value)

{
  size_t sVar1;
  int iVar2;
  X509_EXTENSION *pXVar3;
  char *pcVar4;
  char *pcVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  sVar1 = strlen(value);
  if (sVar1 < 9) {
    uVar6 = 0;
LAB_0016f438:
    if (sVar1 < 4) goto LAB_0016f43c;
  }
  else {
    iVar2 = strncmp(value,"critical,",9);
    if (iVar2 == 0) {
      pcVar4 = value + 9;
      do {
        value = pcVar4;
        iVar2 = ossl_ctype_check(*value,8);
        pcVar4 = value + 1;
      } while (iVar2 != 0);
      uVar6 = 1;
      sVar1 = strlen(value);
      goto LAB_0016f438;
    }
    uVar6 = 0;
  }
  iVar2 = strncmp(value,"DER:",4);
  if (iVar2 == 0) {
    uVar7 = 1;
    pcVar4 = value + 4;
  }
  else {
    if ((sVar1 == 4) || (iVar2 = strncmp(value,"ASN1:",5), iVar2 != 0)) {
LAB_0016f43c:
      pXVar3 = (X509_EXTENSION *)do_ext_nconf(conf,ctx,ext_nid,uVar6,value);
      return pXVar3;
    }
    uVar7 = 2;
    pcVar4 = value + 5;
  }
  do {
    pcVar5 = pcVar4;
    iVar2 = ossl_ctype_check(*pcVar5,8);
    pcVar4 = pcVar5 + 1;
  } while (iVar2 != 0);
  pcVar4 = OBJ_nid2sn(ext_nid);
  pXVar3 = (X509_EXTENSION *)v3_generic_extension(pcVar4,pcVar5,uVar6,uVar7,ctx);
  return pXVar3;
}

