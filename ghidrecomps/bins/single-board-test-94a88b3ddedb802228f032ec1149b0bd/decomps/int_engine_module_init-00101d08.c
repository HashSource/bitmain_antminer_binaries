
undefined4 int_engine_module_init(CONF_IMODULE *param_1,CONF *param_2)

{
  _STACK **pp_Var1;
  char *pcVar2;
  _STACK *p_Var3;
  int iVar4;
  void *pvVar5;
  char *section;
  char *pcVar6;
  _STACK *p_Var7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  _STACK *st;
  uint uVar11;
  char *__s;
  bool bVar12;
  ENGINE *e;
  uint local_44;
  int local_40;
  int local_2c [2];
  
  pcVar2 = CONF_imodule_get_value(param_1);
  p_Var3 = &NCONF_get_section(param_2,pcVar2)->stack;
  if (p_Var3 == (_STACK *)0x0) {
    ERR_put_error(0x26,0xbb,0x94,DAT_00101fd0,0xd8);
    uVar10 = 0;
  }
  else {
    local_40 = 0;
    iVar4 = sk_num(p_Var3);
    if (0 < iVar4) {
      do {
        pvVar5 = sk_value(p_Var3,local_40);
        pcVar2 = *(char **)((int)pvVar5 + 4);
        section = *(char **)((int)pvVar5 + 8);
        local_2c[0] = -1;
        pcVar6 = strchr(pcVar2,0x2e);
        if (pcVar6 != (char *)0x0) {
          pcVar2 = pcVar6 + 1;
        }
        p_Var7 = &NCONF_get_section(param_2,section)->stack;
        if (p_Var7 == (_STACK *)0x0) {
          ERR_put_error(0x26,0xbc,0x95,DAT_00101fd0,0x6f);
          return 0;
        }
        local_44 = 0;
        e = (ENGINE *)0x0;
        for (iVar4 = 0; iVar8 = sk_num(p_Var7), iVar4 < iVar8; iVar4 = iVar4 + 1) {
          puVar9 = (undefined4 *)sk_value(p_Var7,iVar4);
          __s = (char *)puVar9[1];
          pcVar6 = strchr(__s,0x2e);
          if (pcVar6 != (char *)0x0) {
            __s = pcVar6 + 1;
          }
          pcVar6 = (char *)puVar9[2];
          iVar8 = strcmp(__s,DAT_00101fb8);
          if (iVar8 != 0) {
            iVar8 = strcmp(__s,DAT_00101fa4);
            if (iVar8 != 0) {
              iVar8 = strcmp(__s,DAT_00101fa8);
              if (iVar8 == 0) {
                e = ENGINE_by_id(DAT_00101fbc);
                if (e == (ENGINE *)0x0) {
LAB_00101efc:
                  e = (ENGINE *)0x0;
                }
                else {
                  iVar8 = ENGINE_ctrl_cmd_string(e,DAT_00101fc0,pcVar6,0);
                  if ((iVar8 != 0) &&
                     (iVar8 = ENGINE_ctrl_cmd_string(e,DAT_00101fc4,DAT_00101fc8,0), iVar8 != 0)) {
                    iVar8 = ENGINE_ctrl_cmd_string(e,DAT_00101fcc,(char *)0x0,0);
                    goto joined_r0x00101e38;
                  }
                }
              }
              else {
                if (e == (ENGINE *)0x0) {
                  e = ENGINE_by_id(pcVar2);
                  uVar11 = 1 - (int)e;
                  if ((ENGINE *)0x1 < e) {
                    uVar11 = 0;
                  }
                  if ((uVar11 & local_44) != 0) {
                    ERR_clear_error();
                    goto LAB_00101e76;
                  }
                  if (uVar11 != 0) goto LAB_00101efc;
                }
                iVar8 = strcmp(pcVar6,DAT_00101fac);
                if (iVar8 == 0) {
                  pcVar6 = (char *)0x0;
                }
                iVar8 = strcmp(__s,DAT_00101fb0);
                if (iVar8 == 0) {
                  iVar8 = NCONF_get_number_e(param_2,section,DAT_00101fb0,local_2c);
                  if (iVar8 != 0) {
                    if (local_2c[0] == 1) {
                      iVar8 = ENGINE_init(e);
                      pp_Var1 = DAT_00101fe0;
                      if (iVar8 != 0) {
                        st = *DAT_00101fe0;
                        if (st == (_STACK *)0x0) {
                          st = sk_new_null();
                          *pp_Var1 = st;
                          if (st != (_STACK *)0x0) goto LAB_00101f12;
                        }
                        else {
LAB_00101f12:
                          iVar8 = sk_push(st,e);
                          pcVar6 = pcVar2;
                          if (iVar8 != 0) goto LAB_00101dc8;
                        }
                        ENGINE_finish(e);
                      }
                    }
                    else {
                      pcVar6 = pcVar2;
                      if (local_2c[0] == 0) goto LAB_00101dc8;
                      ERR_put_error(0x26,0xbc,0x97,DAT_00101fd0,0xac);
                    }
                  }
                }
                else {
                  iVar8 = strcmp(__s,DAT_00101fb4);
                  if (iVar8 == 0) {
                    iVar8 = ENGINE_set_default_string(e,pcVar6);
                  }
                  else {
                    iVar8 = ENGINE_ctrl_cmd_string(e,__s,pcVar6,0);
                  }
joined_r0x00101e38:
                  pcVar6 = pcVar2;
                  if (iVar8 != 0) goto LAB_00101dc8;
                }
              }
              ERR_put_error(0x26,0xbc,0x66,DAT_00101fd0,0xbf);
              bVar12 = false;
              ERR_add_error_data(6,DAT_00101fd8,*puVar9,DAT_00101fdc,puVar9[1],DAT_00101fd4,
                                 puVar9[2]);
              goto LAB_00101e64;
            }
            local_44 = 1;
            pcVar6 = pcVar2;
          }
LAB_00101dc8:
          pcVar2 = pcVar6;
        }
        if ((e == (ENGINE *)0x0) || (local_2c[0] != -1)) {
LAB_00101edc:
          bVar12 = true;
LAB_00101e64:
          if (e != (ENGINE *)0x0) goto LAB_00101e6a;
        }
        else {
          iVar4 = ENGINE_init(e);
          pp_Var1 = DAT_00101fe0;
          if (iVar4 != 0) {
            p_Var7 = *DAT_00101fe0;
            if (p_Var7 == (_STACK *)0x0) {
              p_Var7 = sk_new_null();
              *pp_Var1 = p_Var7;
              if (p_Var7 != (_STACK *)0x0) goto LAB_00101f34;
            }
            else {
LAB_00101f34:
              iVar4 = sk_push(p_Var7,e);
              if (iVar4 != 0) goto LAB_00101edc;
            }
            ENGINE_finish(e);
          }
          ERR_put_error(0x26,0xbc,0x66,DAT_00101fd0,0xbf);
          bVar12 = false;
LAB_00101e6a:
          ENGINE_free(e);
        }
        if (!bVar12) {
          return 0;
        }
LAB_00101e76:
        local_40 = local_40 + 1;
        iVar4 = sk_num(p_Var3);
      } while (local_40 < iVar4);
    }
    uVar10 = 1;
  }
  return uVar10;
}

