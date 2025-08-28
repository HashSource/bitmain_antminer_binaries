
/* WARNING: Type propagation algorithm not settling */

int CONF_modules_load(CONF *cnf,char *appname,ulong flags)

{
  bool bVar1;
  _STACK *st;
  char *pcVar2;
  _STACK *p_Var3;
  int iVar4;
  void *pvVar5;
  int iVar6;
  DSO *dso;
  DSO_FUNC_TYPE pDVar7;
  DSO_FUNC_TYPE pDVar8;
  undefined4 *data;
  char *pcVar9;
  undefined4 *data_00;
  code *pcVar10;
  char *__s;
  int iVar11;
  size_t __n;
  char *group;
  char acStack_38 [20];
  
  if (cnf == (CONF *)0x0) {
    return 1;
  }
  if (appname != (char *)0x0) {
    pcVar2 = NCONF_get_string(cnf,(char *)0x0,appname);
    if (pcVar2 != (char *)0x0) goto LAB_000ce7da;
    if (-1 < (int)(flags << 0x1a)) goto LAB_000cea4a;
  }
  pcVar2 = NCONF_get_string(cnf,(char *)0x0,"openssl_conf");
  if (pcVar2 == (char *)0x0) {
LAB_000cea4a:
    ERR_clear_error();
    return 1;
  }
LAB_000ce7da:
  p_Var3 = &NCONF_get_section(cnf,pcVar2)->stack;
  if (p_Var3 == (_STACK *)0x0) {
    return 0;
  }
  iVar11 = 0;
  iVar4 = sk_num(p_Var3);
  if (0 < iVar4) {
    do {
      pvVar5 = sk_value(p_Var3,iVar11);
      __s = *(char **)((int)pvVar5 + 4);
      group = *(char **)((int)pvVar5 + 8);
      pcVar2 = strrchr(__s,0x2e);
      if (pcVar2 == (char *)0x0) {
        __n = strlen(__s);
      }
      else {
        __n = (int)pcVar2 - (int)__s;
      }
      iVar4 = 0;
      do {
        iVar6 = sk_num(supported_modules);
        if (iVar6 <= iVar4) {
          if ((flags & 8) == 0) {
            pcVar2 = NCONF_get_string(cnf,group,"path");
            if (pcVar2 == (char *)0x0) {
              ERR_clear_error();
              pcVar2 = __s;
            }
            dso = DSO_load((DSO *)0x0,pcVar2,(DSO_METHOD *)0x0,0);
            if (dso == (DSO *)0x0) {
              iVar4 = 0x6e;
            }
            else {
              pDVar7 = DSO_bind_func(dso,"OPENSSL_init");
              if (pDVar7 == (DSO_FUNC_TYPE)0x0) {
                iVar4 = 0x70;
              }
              else {
                pDVar8 = DSO_bind_func(dso,"OPENSSL_finish");
                if (((supported_modules != (_STACK *)0x0) ||
                    (supported_modules = sk_new_null(), supported_modules != (_STACK *)0x0)) &&
                   (data = (undefined4 *)CRYPTO_malloc(0x18,"conf_mod.c",0x11d),
                   data != (undefined4 *)0x0)) {
                  *data = dso;
                  pcVar9 = BUF_strdup(__s);
                  data[1] = pcVar9;
                  data[4] = 0;
                  data[2] = pDVar7;
                  st = supported_modules;
                  data[3] = pDVar8;
                  iVar4 = sk_push(st,data);
                  if (iVar4 != 0) break;
                  CRYPTO_free(data);
                }
                iVar4 = 0;
              }
              DSO_free(dso);
            }
            ERR_put_error(0xe,0x75,iVar4,"conf_mod.c",0x10f);
            ERR_add_error_data(4,"module=",__s,", path=",pcVar2);
          }
          if ((flags & 4) == 0) {
            ERR_put_error(0xe,0x76,0x71,"conf_mod.c",0xd4);
            ERR_add_error_data(2,"module=",__s);
          }
          goto joined_r0x000ce864;
        }
        data = (undefined4 *)sk_value(supported_modules,iVar4);
        iVar6 = strncmp((char *)data[1],__s,__n);
        iVar4 = iVar4 + 1;
      } while (iVar6 != 0);
      data_00 = (undefined4 *)CRYPTO_malloc(0x14,"conf_mod.c",0x154);
      if (data_00 == (undefined4 *)0x0) {
LAB_000ce9a0:
        if ((flags & 4) == 0) {
          ERR_put_error(0xe,0x76,0x6d,"conf_mod.c",0xdf);
          BIO_snprintf(acStack_38,0xd,"%-8d",0xffffffff);
          ERR_add_error_data(6,"module=",__s,", value=",group,", retcode=",acStack_38);
        }
joined_r0x000ce864:
        if ((flags & 1) == 0) {
          return -1;
        }
      }
      else {
        *data_00 = data;
        pcVar2 = BUF_strdup(__s);
        data_00[1] = pcVar2;
        pcVar2 = BUF_strdup(group);
        pvVar5 = (void *)data_00[1];
        data_00[2] = pcVar2;
        data_00[4] = 0;
        if (pvVar5 == (void *)0x0) {
LAB_000ce994:
          if (pcVar2 != (char *)0x0) {
            CRYPTO_free(pcVar2);
          }
          CRYPTO_free(data_00);
          goto LAB_000ce9a0;
        }
        if (pcVar2 == (char *)0x0) {
LAB_000ce98a:
          CRYPTO_free(pvVar5);
LAB_000ce990:
          pcVar2 = (char *)data_00[2];
          goto LAB_000ce994;
        }
        if ((code *)data[2] != (code *)0x0) {
          iVar4 = (*(code *)data[2])(data_00,cnf);
          if (0 < iVar4) {
            bVar1 = true;
            goto joined_r0x000ce950;
          }
          pcVar10 = (code *)data[3];
          if (pcVar10 == (code *)0x0) goto LAB_000ce97e;
LAB_000ce9fc:
          (*pcVar10)(data_00);
LAB_000ce984:
          pvVar5 = (void *)data_00[1];
          if (pvVar5 != (void *)0x0) goto LAB_000ce98a;
          goto LAB_000ce990;
        }
        bVar1 = false;
joined_r0x000ce950:
        if (initialized_modules == (_STACK *)0x0) {
          initialized_modules = sk_new_null();
          iVar4 = 0x16c;
          if (initialized_modules != (_STACK *)0x0) goto LAB_000ce952;
LAB_000ce966:
          ERR_put_error(0xe,0x73,0x41,"conf_mod.c",iVar4);
          pcVar10 = (code *)data[3];
          if ((pcVar10 != (code *)0x0) && (bVar1)) goto LAB_000ce9fc;
LAB_000ce97e:
          if (data_00 == (undefined4 *)0x0) goto LAB_000ce9a0;
          goto LAB_000ce984;
        }
LAB_000ce952:
        iVar4 = sk_push(initialized_modules,data_00);
        if (iVar4 == 0) {
          iVar4 = 0x172;
          goto LAB_000ce966;
        }
        data[4] = data[4] + 1;
      }
      iVar11 = iVar11 + 1;
      iVar4 = sk_num(p_Var3);
    } while (iVar11 < iVar4);
  }
  return 1;
}

