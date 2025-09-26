
X509_EXTENSION * X509V3_EXT_nconf(CONF *conf,X509V3_CTX *ctx,char *name,char *value)

{
  char *pcVar1;
  size_t sVar2;
  int iVar3;
  X509_EXTENSION *pXVar4;
  char *pcVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  sVar2 = strlen(value);
  if (sVar2 < 9) {
    uVar6 = 0;
LAB_0017d158:
    if (sVar2 < 4) goto LAB_0017d15c;
  }
  else {
    iVar3 = strncmp(value,"critical,",9);
    if (iVar3 == 0) {
      pcVar1 = value + 9;
      do {
        value = pcVar1;
        iVar3 = ossl_ctype_check(*value,8);
        pcVar1 = value + 1;
      } while (iVar3 != 0);
      uVar6 = 1;
      sVar2 = strlen(value);
      goto LAB_0017d158;
    }
    uVar6 = 0;
  }
  iVar3 = strncmp(value,"DER:",4);
  if (iVar3 == 0) {
    uVar7 = 1;
    pcVar1 = value + 4;
  }
  else {
    if ((sVar2 == 4) || (iVar3 = strncmp(value,"ASN1:",5), iVar3 != 0)) {
LAB_0017d15c:
      iVar3 = OBJ_sn2nid(name);
      pXVar4 = (X509_EXTENSION *)do_ext_nconf(conf,ctx,iVar3,uVar6,value);
      if (pXVar4 == (X509_EXTENSION *)0x0) {
        ERR_put_error(0x22,0x98,0x80,"crypto/x509v3/v3_conf.c",0x2f);
        ERR_add_error_data(4,"name=",name,", value=",value);
      }
      return pXVar4;
    }
    uVar7 = 2;
    pcVar1 = value + 5;
  }
  do {
    pcVar5 = pcVar1;
    iVar3 = ossl_ctype_check(*pcVar5,8);
    pcVar1 = pcVar5 + 1;
  } while (iVar3 != 0);
  pXVar4 = (X509_EXTENSION *)v3_generic_extension(name,pcVar5,uVar6,uVar7,ctx);
  return pXVar4;
}

