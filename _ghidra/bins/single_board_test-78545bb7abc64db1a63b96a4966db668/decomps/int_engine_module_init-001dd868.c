
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4 int_engine_module_init(CONF_IMODULE *param_1,CONF *param_2)

{
  bool bVar1;
  bool bVar2;
  char *pcVar3;
  stack_st_CONF_VALUE *psVar4;
  int iVar5;
  char *pcVar6;
  stack_st_CONF_VALUE *psVar7;
  int iVar8;
  undefined4 *puVar9;
  char *__s;
  ENGINE *e;
  char *local_54;
  int local_44;
  long local_2c [2];
  
  pcVar3 = CONF_imodule_get_value(param_1);
  psVar4 = NCONF_get_section(param_2,pcVar3);
  if (psVar4 == (stack_st_CONF_VALUE *)0x0) {
    ERR_put_error(0x26,0xbb,0x94,"crypto/engine/eng_cnf.c",0xa5);
    return 0;
  }
  local_44 = 0;
  iVar5 = OPENSSL_sk_num(psVar4);
  if (0 < iVar5) {
    do {
      iVar5 = OPENSSL_sk_value(psVar4,local_44);
      local_54 = *(char **)(iVar5 + 4);
      pcVar3 = *(char **)(iVar5 + 8);
      local_2c[0] = -1;
      pcVar6 = strchr(local_54,0x2e);
      if (pcVar6 != (char *)0x0) {
        local_54 = pcVar6 + 1;
      }
      psVar7 = NCONF_get_section(param_2,pcVar3);
      if (psVar7 == (stack_st_CONF_VALUE *)0x0) {
        ERR_put_error(0x26,0xbc,0x95,"crypto/engine/eng_cnf.c",0x3d);
        return 0;
      }
      bVar2 = false;
      e = (ENGINE *)0x0;
      for (iVar5 = 0; iVar8 = OPENSSL_sk_num(psVar7), iVar5 < iVar8; iVar5 = iVar5 + 1) {
        puVar9 = (undefined4 *)OPENSSL_sk_value(psVar7,iVar5);
        __s = (char *)puVar9[1];
        pcVar6 = strchr(__s,0x2e);
        if (pcVar6 != (char *)0x0) {
          __s = pcVar6 + 1;
        }
        pcVar6 = (char *)puVar9[2];
        iVar8 = strcmp(__s,"engine_id");
        if (iVar8 != 0) {
          iVar8 = strcmp(__s,"soft_load");
          if (iVar8 != 0) {
            iVar8 = strcmp(__s,"dynamic_path");
            if (iVar8 == 0) {
              e = ENGINE_by_id("dynamic");
              if (e != (ENGINE *)0x0) {
                iVar8 = ENGINE_ctrl_cmd_string(e,"SO_PATH",pcVar6,0);
                if (((iVar8 == 0) ||
                    (iVar8 = ENGINE_ctrl_cmd_string(e,"LIST_ADD","2",0), iVar8 == 0)) ||
                   (iVar8 = ENGINE_ctrl_cmd_string(e,"LOAD",(char *)0x0,0), pcVar6 = local_54,
                   iVar8 == 0)) goto LAB_001ddae2;
                goto LAB_001dd950;
              }
LAB_001dda76:
              e = (ENGINE *)0x0;
              ERR_put_error(0x26,0xbc,0x66,"crypto/engine/eng_cnf.c",0x8d);
            }
            else {
              if (e == (ENGINE *)0x0) {
                e = ENGINE_by_id(local_54);
                bVar1 = bVar2;
                if (e != (ENGINE *)0x0) {
                  bVar1 = false;
                }
                if (bVar1) {
                  ERR_clear_error();
                  goto LAB_001dda3c;
                }
                if (e == (ENGINE *)0x0) goto LAB_001dda76;
              }
              iVar8 = strcmp(pcVar6,"EMPTY");
              if (iVar8 == 0) {
                pcVar6 = (char *)0x0;
              }
              iVar8 = strcmp(__s,"init");
              if (iVar8 == 0) {
                iVar8 = NCONF_get_number_e(param_2,pcVar3,"init",local_2c);
                if (iVar8 != 0) {
                  if (local_2c[0] == 1) {
                    iVar8 = ENGINE_init(e);
                    if (iVar8 != 0) {
                      if (((initialized_engines != 0) ||
                          (initialized_engines = OPENSSL_sk_new_null(), initialized_engines != 0))
                         && (iVar8 = OPENSSL_sk_push(initialized_engines,e), pcVar6 = local_54,
                            iVar8 != 0)) goto LAB_001dd950;
                      ENGINE_finish(e);
                    }
                  }
                  else {
                    pcVar6 = local_54;
                    if (local_2c[0] == 0) goto LAB_001dd950;
                    ERR_put_error(0x26,0xbc,0x97,"crypto/engine/eng_cnf.c",0x7a);
                  }
                }
              }
              else {
                iVar8 = strcmp(__s,"default_algorithms");
                if (iVar8 == 0) {
                  iVar8 = ENGINE_set_default_string(e,pcVar6);
                }
                else {
                  iVar8 = ENGINE_ctrl_cmd_string(e,__s,pcVar6,0);
                }
                pcVar6 = local_54;
                if (iVar8 != 0) goto LAB_001dd950;
              }
LAB_001ddae2:
              ERR_put_error(0x26,0xbc,0x66,"crypto/engine/eng_cnf.c",0x8d);
            }
            ERR_add_error_data(6,"section=",*puVar9,", name=",puVar9[1],", value=",puVar9[2]);
            goto LAB_001ddaaa;
          }
          bVar2 = true;
          pcVar6 = local_54;
        }
LAB_001dd950:
        local_54 = pcVar6;
      }
      if ((e != (ENGINE *)0x0) && (local_2c[0] == -1)) {
        iVar5 = ENGINE_init(e);
        if (iVar5 == 0) {
LAB_001ddb0c:
          ERR_put_error(0x26,0xbc,0x66,"crypto/engine/eng_cnf.c",0x8d);
LAB_001ddaaa:
          ENGINE_free(e);
          return 0;
        }
        if (((initialized_engines == 0) &&
            (initialized_engines = OPENSSL_sk_new_null(), initialized_engines == 0)) ||
           (iVar5 = OPENSSL_sk_push(initialized_engines,e), iVar5 == 0)) {
          ENGINE_finish(e);
          goto LAB_001ddb0c;
        }
      }
      ENGINE_free(e);
LAB_001dda3c:
      local_44 = local_44 + 1;
      iVar5 = OPENSSL_sk_num(psVar4);
    } while (local_44 < iVar5);
  }
  return 1;
}

