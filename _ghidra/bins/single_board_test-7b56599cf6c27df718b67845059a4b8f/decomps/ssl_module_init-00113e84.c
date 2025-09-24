
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4 ssl_module_init(CONF_IMODULE *param_1,CONF *param_2)

{
  char *pcVar1;
  stack_st_CONF_VALUE *psVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  stack_st_CONF_VALUE *psVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  char *__s;
  int iVar10;
  int local_3c;
  uint local_34;
  
  pcVar1 = CONF_imodule_get_value(param_1);
  psVar2 = NCONF_get_section(param_2,pcVar1);
  iVar3 = OPENSSL_sk_num();
  if (iVar3 < 1) {
    if (psVar2 == (stack_st_CONF_VALUE *)0x0) {
      ERR_put_error(0xe,0x7b,0x78,"crypto/conf/conf_ssl.c",0x48);
    }
    else {
      ERR_put_error(0xe,0x7b,0x77,"crypto/conf/conf_ssl.c",0x4a);
    }
    ERR_add_error_data(2,"section=",pcVar1);
  }
  else {
    uVar4 = OPENSSL_sk_num(psVar2);
    ssl_module_free(param_1);
    ssl_names = CRYPTO_zalloc(uVar4 * 0xc,"crypto/conf/conf_ssl.c",0x50);
    if (ssl_names != 0) {
      ssl_names_count = uVar4;
      if (uVar4 != 0) {
        local_34 = 0;
        local_3c = 0;
        do {
          iVar3 = ssl_names;
          iVar5 = OPENSSL_sk_value(psVar2,local_34);
          iVar10 = iVar3 + local_3c;
          psVar6 = NCONF_get_section(param_2,*(char **)(iVar5 + 8));
          iVar7 = OPENSSL_sk_num();
          if (iVar7 < 1) {
            if (psVar6 == (stack_st_CONF_VALUE *)0x0) {
              ERR_put_error(0xe,0x7b,0x76,"crypto/conf/conf_ssl.c",0x5c);
            }
            else {
              ERR_put_error(0xe,0x7b,0x75,"crypto/conf/conf_ssl.c",0x5f);
            }
            ERR_add_error_data(4,"name=",*(undefined4 *)(iVar5 + 4),", value=",
                               *(undefined4 *)(iVar5 + 8));
            goto LAB_00113fa2;
          }
          pcVar1 = CRYPTO_strdup(*(char **)(iVar5 + 4),"crypto/conf/conf_ssl.c",99);
          *(char **)(iVar3 + local_3c) = pcVar1;
          if (pcVar1 == (char *)0x0) goto LAB_00113fa2;
          iVar3 = OPENSSL_sk_num(psVar6);
          iVar5 = CRYPTO_zalloc(iVar3 << 3,"crypto/conf/conf_ssl.c",0x67);
          *(int *)(iVar10 + 4) = iVar5;
          if (iVar5 == 0) goto LAB_00113fa2;
          *(int *)(iVar10 + 8) = iVar3;
          iVar5 = 0;
          if (iVar3 != 0) {
            do {
              iVar7 = OPENSSL_sk_value(psVar6,iVar5);
              __s = *(char **)(iVar7 + 4);
              iVar8 = iVar5 * 8;
              iVar9 = *(int *)(iVar10 + 4);
              iVar5 = iVar5 + 1;
              pcVar1 = strchr(__s,0x2e);
              if (pcVar1 != (char *)0x0) {
                __s = pcVar1 + 1;
              }
              pcVar1 = CRYPTO_strdup(__s,"crypto/conf/conf_ssl.c",0x76);
              *(char **)(iVar9 + iVar8) = pcVar1;
              pcVar1 = CRYPTO_strdup(*(char **)(iVar7 + 8),"crypto/conf/conf_ssl.c",0x77);
              iVar7 = *(int *)(iVar9 + iVar8);
              *(char **)(iVar9 + iVar8 + 4) = pcVar1;
              if (pcVar1 == (char *)0x0 || iVar7 == 0) goto LAB_00113fa2;
            } while (iVar3 != iVar5);
          }
          local_34 = local_34 + 1;
          local_3c = local_3c + 0xc;
        } while (local_34 < ssl_names_count);
      }
      return 1;
    }
  }
LAB_00113fa2:
  ssl_module_free(param_1);
  return 0;
}

