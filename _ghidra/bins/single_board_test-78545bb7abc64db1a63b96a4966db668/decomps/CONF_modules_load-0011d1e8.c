
int CONF_modules_load(CONF *cnf,char *appname,ulong flags)

{
  char *pcVar1;
  stack_st_CONF_VALUE *psVar2;
  int iVar3;
  int iVar4;
  DSO *dso;
  DSO_FUNC_TYPE pDVar5;
  DSO_FUNC_TYPE pDVar6;
  undefined4 *ptr;
  char *pcVar7;
  undefined4 *ptr_00;
  code *pcVar8;
  char *group;
  void *ptr_01;
  char *__s;
  int iVar9;
  size_t __n;
  bool bVar10;
  char acStack_38 [20];
  
  if (cnf == (CONF *)0x0) {
    return 1;
  }
  if (appname != (char *)0x0) {
    pcVar1 = NCONF_get_string(cnf,(char *)0x0,appname);
    if (pcVar1 != (char *)0x0) goto LAB_0011d20c;
    if (-1 < (int)(flags << 0x1a)) goto LAB_0011d4e4;
  }
  pcVar1 = NCONF_get_string(cnf,(char *)0x0,"openssl_conf");
  if (pcVar1 == (char *)0x0) {
LAB_0011d4e4:
    ERR_clear_error();
    return 1;
  }
LAB_0011d20c:
  psVar2 = NCONF_get_section(cnf,pcVar1);
  if (psVar2 == (stack_st_CONF_VALUE *)0x0) {
    return 0;
  }
  iVar9 = 0;
  iVar3 = OPENSSL_sk_num(psVar2);
  if (0 < iVar3) {
    do {
      iVar3 = OPENSSL_sk_value(psVar2,iVar9);
      __s = *(char **)(iVar3 + 4);
      group = *(char **)(iVar3 + 8);
      pcVar1 = strrchr(__s,0x2e);
      __n = (int)pcVar1 - (int)__s;
      if (pcVar1 == (char *)0x0) {
        __n = strlen(__s);
      }
      iVar3 = 0;
      do {
        iVar4 = OPENSSL_sk_num(supported_modules);
        if (iVar4 <= iVar3) {
          if ((flags & 8) == 0) {
            pcVar1 = NCONF_get_string(cnf,group,"path");
            if (pcVar1 == (char *)0x0) {
              ERR_clear_error();
              pcVar1 = __s;
            }
            dso = DSO_load((DSO *)0x0,pcVar1,(DSO_METHOD *)0x0,0);
            if (dso == (DSO *)0x0) {
              iVar3 = 0x6e;
            }
            else {
              pDVar5 = DSO_bind_func(dso,"OPENSSL_init");
              if (pDVar5 == (DSO_FUNC_TYPE)0x0) {
                iVar3 = 0x70;
              }
              else {
                pDVar6 = DSO_bind_func(dso,"OPENSSL_finish");
                if ((supported_modules != 0) ||
                   (supported_modules = OPENSSL_sk_new_null(), supported_modules != 0)) {
                  ptr = (undefined4 *)CRYPTO_zalloc(0x18,"crypto/conf/conf_mod.c",0xee);
                  if (ptr == (undefined4 *)0x0) {
                    ERR_put_error(0xe,0x7a,0x41,"crypto/conf/conf_mod.c",0xef);
                  }
                  else {
                    *ptr = dso;
                    pcVar7 = CRYPTO_strdup(__s,"crypto/conf/conf_mod.c",0xf4);
                    ptr[1] = pcVar7;
                    ptr[2] = pDVar5;
                    ptr[3] = pDVar6;
                    if (pcVar7 == (char *)0x0) {
                      CRYPTO_free(ptr);
                    }
                    else {
                      iVar3 = OPENSSL_sk_push(supported_modules,ptr);
                      if (iVar3 != 0) break;
                      CRYPTO_free((void *)ptr[1]);
                      CRYPTO_free(ptr);
                    }
                  }
                }
                iVar3 = 0;
              }
            }
            DSO_free(dso);
            ERR_put_error(0xe,0x75,iVar3,"crypto/conf/conf_mod.c",0xe0);
            ERR_add_error_data(4,"module=",__s,", path=",pcVar1);
          }
          if ((flags & 4) == 0) {
            ERR_put_error(0xe,0x76,0x71,"crypto/conf/conf_mod.c",0xa5);
            ERR_add_error_data(2,"module=",__s);
          }
          goto joined_r0x0011d2a6;
        }
        ptr = (undefined4 *)OPENSSL_sk_value(supported_modules,iVar3);
        iVar4 = strncmp((char *)ptr[1],__s,__n);
        iVar3 = iVar3 + 1;
      } while (iVar4 != 0);
      ptr_00 = (undefined4 *)CRYPTO_malloc(0x14,"crypto/conf/conf_mod.c",0x12a);
      if (ptr_00 == (undefined4 *)0x0) {
LAB_0011d42c:
        if ((flags & 4) == 0) {
          ERR_put_error(0xe,0x76,0x6d,"crypto/conf/conf_mod.c",0xb1);
          BIO_snprintf(acStack_38,0xd,"%-8d",0xffffffff);
          ERR_add_error_data(6,"module=",__s,", value=",group,", retcode=",acStack_38);
        }
joined_r0x0011d2a6:
        if ((flags & 1) == 0) {
          return -1;
        }
      }
      else {
        *ptr_00 = ptr;
        pcVar1 = CRYPTO_strdup(__s,"crypto/conf/conf_mod.c",0x12f);
        ptr_00[1] = pcVar1;
        pcVar1 = CRYPTO_strdup(group,"crypto/conf/conf_mod.c",0x130);
        ptr_01 = (void *)ptr_00[1];
        ptr_00[2] = pcVar1;
        ptr_00[4] = 0;
        if (pcVar1 == (char *)0x0 || ptr_01 == (void *)0x0) {
LAB_0011d402:
          CRYPTO_free(ptr_01);
          CRYPTO_free((void *)ptr_00[2]);
          CRYPTO_free(ptr_00);
          goto LAB_0011d42c;
        }
        bVar10 = false;
        if ((code *)ptr[2] != (code *)0x0) {
          iVar3 = (*(code *)ptr[2])(ptr_00,cnf);
          if (0 < iVar3) {
            bVar10 = true;
            goto LAB_0011d3be;
          }
          pcVar8 = (code *)ptr[3];
          if (pcVar8 != (code *)0x0) goto LAB_0011d3fa;
LAB_0011d3fe:
          ptr_01 = (void *)ptr_00[1];
          goto LAB_0011d402;
        }
LAB_0011d3be:
        if ((initialized_modules == 0) &&
           (initialized_modules = OPENSSL_sk_new_null(), initialized_modules == 0)) {
          iVar3 = 0x142;
LAB_0011d3e0:
          ERR_put_error(0xe,0x73,0x41,"crypto/conf/conf_mod.c",iVar3);
          pcVar8 = (code *)ptr[3];
          if (pcVar8 == (code *)0x0) {
            bVar10 = false;
          }
          if (bVar10) {
LAB_0011d3fa:
            (*pcVar8)(ptr_00);
          }
          goto LAB_0011d3fe;
        }
        iVar3 = OPENSSL_sk_push(initialized_modules,ptr_00);
        if (iVar3 == 0) {
          iVar3 = 0x148;
          goto LAB_0011d3e0;
        }
        ptr[4] = ptr[4] + 1;
      }
      iVar9 = iVar9 + 1;
      iVar3 = OPENSSL_sk_num(psVar2);
    } while (iVar9 < iVar3);
  }
  return 1;
}

