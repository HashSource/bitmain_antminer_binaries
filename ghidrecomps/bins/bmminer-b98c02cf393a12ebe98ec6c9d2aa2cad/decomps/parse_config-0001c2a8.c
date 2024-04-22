
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char * parse_config(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  char *__s;
  char *pcVar3;
  int *piVar4;
  undefined4 *__ptr;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  char acStack_828 [2052];
  
  if ((param_2 != 0) && (fileconf_load == 0)) {
    fileconf_load = 1;
  }
  if (DAT_0007d6ac != 0x10) {
    iVar9 = DAT_0007d6ac << 0x1c;
    piVar7 = &opt_config_table;
    do {
      if (iVar9 < 0) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("!(opt->type & OPT_SUBTABLE)","cgminer.c",0x775,DAT_0001c510);
      }
      if (*piVar7 != 0) {
        __s = (char *)__strdup();
        pcVar3 = strtok(__s,(char *)&DAT_00057a28);
joined_r0x0001c31e:
        if (pcVar3 != (char *)0x0) {
          do {
            if ((pcVar3[1] == '-') &&
               (piVar4 = (int *)json_object_get(param_1,pcVar3 + 2), piVar4 != (int *)0x0)) {
              if ((piVar7[1] & 6U) == 0) {
LAB_0001c35e:
                if ((piVar7[1] << 0x1f < 0) && (*piVar4 == 5)) {
                  __ptr = (undefined4 *)(*(code *)piVar7[2])(piVar7[5]);
                }
                else {
                  __ptr = (undefined4 *)malloc(0xe);
                  uVar2 = ram0x0005c4dc;
                  uVar1 = s_Invalid_value_0005c4d0._8_4_;
                  uVar8 = s_Invalid_value_0005c4d0._4_4_;
                  if (__ptr == (undefined4 *)0x0) goto LAB_0001c322;
                  *__ptr = s_Invalid_value_0005c4d0._0_4_;
                  __ptr[1] = uVar8;
                  __ptr[2] = uVar1;
                  *(short *)(__ptr + 3) = (short)uVar2;
                }
              }
              else {
                if (*piVar4 != 2) {
                  if (*piVar4 == 1) {
                    uVar10 = 0;
                    while ((uVar5 = json_array_size(piVar4), uVar10 < uVar5 &&
                           (piVar6 = (int *)json_array_get(piVar4,uVar10), piVar6 != (int *)0x0))) {
                      if (*piVar6 == 2) {
                        uVar8 = json_string_value();
                        __ptr = (undefined4 *)(*(code *)piVar7[3])(uVar8,piVar7[5]);
                        if (piVar7[1] == 4) {
                          opt_set_charp(uVar8,piVar7[5]);
                        }
joined_r0x0001c49e:
                        if (__ptr != (undefined4 *)0x0) goto joined_r0x0001c452;
                      }
                      else if (*piVar6 == 0) {
                        __ptr = (undefined4 *)parse_config();
                        goto joined_r0x0001c49e;
                      }
                      uVar10 = uVar10 + 1;
                    }
                    goto LAB_0001c322;
                  }
                  goto LAB_0001c35e;
                }
                uVar8 = json_string_value();
                __ptr = (undefined4 *)(*(code *)piVar7[3])(uVar8,piVar7[5]);
                if (piVar7[1] == 4) {
                  opt_set_charp(uVar8,piVar7[5]);
                }
              }
              if (__ptr != (undefined4 *)0x0) goto joined_r0x0001c452;
            }
LAB_0001c322:
            pcVar3 = strtok((char *)0x0,(char *)&DAT_00057a28);
            if (pcVar3 == (char *)0x0) break;
          } while( true );
        }
        free(__s);
      }
      if (piVar7[8] == 0x10) break;
      iVar9 = piVar7[8] << 0x1c;
      piVar7 = piVar7 + 7;
    } while( true );
  }
  piVar7 = (int *)json_object_get(param_1,"include");
  if ((piVar7 != (int *)0x0) && (*piVar7 == 2)) {
    uVar8 = json_string_value(piVar7);
    pcVar3 = (char *)load_config(uVar8,0);
    return pcVar3;
  }
  return (char *)0x0;
joined_r0x0001c452:
  if (param_2 == 0) {
    snprintf(DAT_0001c514,200,"Parsing JSON option %s: %s",pcVar3,__ptr);
    return DAT_0001c514;
  }
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
    snprintf(acStack_828,0x800,"Invalid config option %s: %s",pcVar3,__ptr);
    _applog(3,acStack_828,0);
  }
  free(__ptr);
  fileconf_load = -1;
  pcVar3 = strtok((char *)0x0,(char *)&DAT_00057a28);
  goto joined_r0x0001c31e;
}

