
undefined4 int_engine_module_init(CONF_IMODULE *param_1,CONF *param_2)

{
  char *pcVar1;
  _STACK *p_Var2;
  int iVar3;
  void *pvVar4;
  char *section;
  char *pcVar5;
  _STACK *p_Var6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  uint uVar10;
  char *__s;
  bool bVar11;
  ENGINE *e;
  uint local_44;
  int local_40;
  long local_2c [2];
  
  pcVar1 = CONF_imodule_get_value(param_1);
  p_Var2 = &NCONF_get_section(param_2,pcVar1)->stack;
  if (p_Var2 == (_STACK *)0x0) {
    ERR_put_error(0x26,0xbb,0x94,"eng_cnf.c",0xd8);
    uVar9 = 0;
  }
  else {
    local_40 = 0;
    iVar3 = sk_num(p_Var2);
    if (0 < iVar3) {
      do {
        pvVar4 = sk_value(p_Var2,local_40);
        pcVar1 = *(char **)((int)pvVar4 + 4);
        section = *(char **)((int)pvVar4 + 8);
        local_2c[0] = -1;
        pcVar5 = strchr(pcVar1,0x2e);
        if (pcVar5 != (char *)0x0) {
          pcVar1 = pcVar5 + 1;
        }
        p_Var6 = &NCONF_get_section(param_2,section)->stack;
        if (p_Var6 == (_STACK *)0x0) {
          ERR_put_error(0x26,0xbc,0x95,"eng_cnf.c",0x6f);
          return 0;
        }
        local_44 = 0;
        e = (ENGINE *)0x0;
        for (iVar3 = 0; iVar7 = sk_num(p_Var6), iVar3 < iVar7; iVar3 = iVar3 + 1) {
          puVar8 = (undefined4 *)sk_value(p_Var6,iVar3);
          __s = (char *)puVar8[1];
          pcVar5 = strchr(__s,0x2e);
          if (pcVar5 != (char *)0x0) {
            __s = pcVar5 + 1;
          }
          pcVar5 = (char *)puVar8[2];
          iVar7 = strcmp(__s,"engine_id");
          if (iVar7 != 0) {
            iVar7 = strcmp(__s,"soft_load");
            if (iVar7 != 0) {
              iVar7 = strcmp(__s,"dynamic_path");
              if (iVar7 == 0) {
                e = ENGINE_by_id("dynamic");
                if (e == (ENGINE *)0x0) {
LAB_00101efc:
                  e = (ENGINE *)0x0;
                }
                else {
                  iVar7 = ENGINE_ctrl_cmd_string(e,"SO_PATH",pcVar5,0);
                  if ((iVar7 != 0) &&
                     (iVar7 = ENGINE_ctrl_cmd_string(e,"LIST_ADD","2",0), iVar7 != 0)) {
                    iVar7 = ENGINE_ctrl_cmd_string(e,"LOAD",(char *)0x0,0);
                    goto joined_r0x00101e38;
                  }
                }
              }
              else {
                if (e == (ENGINE *)0x0) {
                  e = ENGINE_by_id(pcVar1);
                  uVar10 = 1 - (int)e;
                  if ((ENGINE *)0x1 < e) {
                    uVar10 = 0;
                  }
                  if ((uVar10 & local_44) != 0) {
                    ERR_clear_error();
                    goto LAB_00101e76;
                  }
                  if (uVar10 != 0) goto LAB_00101efc;
                }
                iVar7 = strcmp(pcVar5,"EMPTY");
                if (iVar7 == 0) {
                  pcVar5 = (char *)0x0;
                }
                iVar7 = strcmp(__s,"init");
                if (iVar7 == 0) {
                  iVar7 = NCONF_get_number_e(param_2,section,"init",local_2c);
                  if (iVar7 != 0) {
                    if (local_2c[0] == 1) {
                      iVar7 = ENGINE_init(e);
                      if (iVar7 != 0) {
                        if (((initialized_engines != (_STACK *)0x0) ||
                            (initialized_engines = sk_new_null(),
                            initialized_engines != (_STACK *)0x0)) &&
                           (iVar7 = sk_push(initialized_engines,e), pcVar5 = pcVar1, iVar7 != 0))
                        goto LAB_00101dc8;
                        ENGINE_finish(e);
                      }
                    }
                    else {
                      pcVar5 = pcVar1;
                      if (local_2c[0] == 0) goto LAB_00101dc8;
                      ERR_put_error(0x26,0xbc,0x97,"eng_cnf.c",0xac);
                    }
                  }
                }
                else {
                  iVar7 = strcmp(__s,"default_algorithms");
                  if (iVar7 == 0) {
                    iVar7 = ENGINE_set_default_string(e,pcVar5);
                  }
                  else {
                    iVar7 = ENGINE_ctrl_cmd_string(e,__s,pcVar5,0);
                  }
joined_r0x00101e38:
                  pcVar5 = pcVar1;
                  if (iVar7 != 0) goto LAB_00101dc8;
                }
              }
              ERR_put_error(0x26,0xbc,0x66,"eng_cnf.c",0xbf);
              bVar11 = false;
              ERR_add_error_data(6,"section=",*puVar8,", name=",puVar8[1],", value=",puVar8[2]);
              goto LAB_00101e64;
            }
            local_44 = 1;
            pcVar5 = pcVar1;
          }
LAB_00101dc8:
          pcVar1 = pcVar5;
        }
        if ((e == (ENGINE *)0x0) || (local_2c[0] != -1)) {
LAB_00101edc:
          bVar11 = true;
LAB_00101e64:
          if (e != (ENGINE *)0x0) goto LAB_00101e6a;
        }
        else {
          iVar3 = ENGINE_init(e);
          if (iVar3 != 0) {
            if (((initialized_engines != (_STACK *)0x0) ||
                (initialized_engines = sk_new_null(), initialized_engines != (_STACK *)0x0)) &&
               (iVar3 = sk_push(initialized_engines,e), iVar3 != 0)) goto LAB_00101edc;
            ENGINE_finish(e);
          }
          ERR_put_error(0x26,0xbc,0x66,"eng_cnf.c",0xbf);
          bVar11 = false;
LAB_00101e6a:
          ENGINE_free(e);
        }
        if (!bVar11) {
          return 0;
        }
LAB_00101e76:
        local_40 = local_40 + 1;
        iVar3 = sk_num(p_Var2);
      } while (local_40 < iVar3);
    }
    uVar9 = 1;
  }
  return uVar9;
}

