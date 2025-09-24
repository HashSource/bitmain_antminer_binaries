
undefined4 oid_module_init(CONF_IMODULE *param_1,CONF *param_2)

{
  char *pcVar1;
  stack_st_CONF_VALUE *psVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  int iVar7;
  char *sn;
  size_t __n;
  
  pcVar1 = CONF_imodule_get_value(param_1);
  psVar2 = NCONF_get_section(param_2,pcVar1);
  if (psVar2 == (stack_st_CONF_VALUE *)0x0) {
    ERR_put_error(0xd,0xae,0xac,"crypto/asn1/asn_moid.c",0x20);
    return 0;
  }
  iVar7 = 0;
  iVar3 = OPENSSL_sk_num(psVar2);
  if (0 < iVar3) {
    do {
      iVar3 = OPENSSL_sk_value(psVar2,iVar7);
      pcVar5 = *(char **)(iVar3 + 8);
      sn = *(char **)(iVar3 + 4);
      pcVar1 = strrchr(pcVar5,0x2c);
      if (pcVar1 == (char *)0x0) {
        pcVar1 = (char *)0x0;
        pcVar4 = sn;
      }
      else {
        pcVar6 = pcVar1;
        if (pcVar1[1] == '\0') goto LAB_001d7afa;
        do {
          pcVar6 = pcVar6 + 1;
          iVar3 = ossl_ctype_check(*pcVar6,8);
        } while (iVar3 != 0);
        do {
          pcVar4 = pcVar5;
          iVar3 = ossl_ctype_check(*pcVar4,8);
          pcVar5 = pcVar4 + 1;
        } while (iVar3 != 0);
        while( true ) {
          pcVar5 = pcVar1 + -1;
          iVar3 = ossl_ctype_check(*pcVar5,8);
          if (iVar3 == 0) break;
          pcVar1 = pcVar5;
          if (pcVar4 == pcVar5) goto LAB_001d7afa;
        }
        __n = (int)pcVar1 - (int)pcVar4;
        pcVar1 = (char *)CRYPTO_malloc(__n + 1,"crypto/asn1/asn_moid.c",0x56);
        if (pcVar1 == (char *)0x0) {
          ERR_put_error(0xd,0x7c,0x41,"crypto/asn1/asn_moid.c",0x57);
          goto LAB_001d7afa;
        }
        memcpy(pcVar1,pcVar4,__n);
        pcVar1[__n] = '\0';
        pcVar4 = pcVar1;
        pcVar5 = pcVar6;
      }
      iVar3 = OBJ_create(pcVar5,sn,pcVar4);
      CRYPTO_free(pcVar1);
      if (iVar3 == 0) {
LAB_001d7afa:
        ERR_put_error(0xd,0xae,0xab,"crypto/asn1/asn_moid.c",0x26);
        return 0;
      }
      iVar7 = iVar7 + 1;
      iVar3 = OPENSSL_sk_num(psVar2);
    } while (iVar7 < iVar3);
  }
  return 1;
}

