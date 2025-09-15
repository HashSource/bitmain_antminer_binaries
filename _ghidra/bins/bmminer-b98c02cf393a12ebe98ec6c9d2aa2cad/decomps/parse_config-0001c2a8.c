
/* WARNING: Type propagation algorithm not settling */

undefined1 * parse_config(undefined4 param_1,int param_2)

{
  char *__s;
  char *pcVar1;
  int *piVar2;
  char *__ptr;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined1 *puVar7;
  int iVar8;
  uint uVar9;
  char acStack_828 [2052];
  
  if ((param_2 != 0) && (fileconf_load == 0)) {
    fileconf_load = 1;
  }
  if (DAT_0007d6ac != 0x10) {
    iVar8 = DAT_0007d6ac << 0x1c;
    piVar5 = &opt_config_table;
    do {
      if (iVar8 < 0) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("!(opt->type & OPT_SUBTABLE)","cgminer.c",0x775,"parse_config");
      }
      if (*piVar5 != 0) {
        __s = (char *)__strdup();
        pcVar1 = strtok(__s,"|");
joined_r0x0001c31e:
        if (pcVar1 != (char *)0x0) {
          do {
            if ((pcVar1[1] == '-') &&
               (piVar2 = (int *)json_object_get(param_1,pcVar1 + 2), piVar2 != (int *)0x0)) {
              if ((piVar5[1] & 6U) == 0) {
LAB_0001c35e:
                if ((piVar5[1] << 0x1f < 0) && (*piVar2 == 5)) {
                  __ptr = (char *)(*(code *)piVar5[2])(piVar5[5]);
                }
                else {
                  __ptr = (char *)malloc(0xe);
                  if (__ptr == (char *)0x0) goto LAB_0001c322;
                  builtin_strncpy(__ptr,"Invalid value",0xe);
                }
              }
              else {
                if (*piVar2 != 2) {
                  if (*piVar2 == 1) {
                    uVar9 = 0;
                    while ((uVar3 = json_array_size(piVar2), uVar9 < uVar3 &&
                           (piVar4 = (int *)json_array_get(piVar2,uVar9), piVar4 != (int *)0x0))) {
                      if (*piVar4 == 2) {
                        uVar6 = json_string_value();
                        __ptr = (char *)(*(code *)piVar5[3])(uVar6,piVar5[5]);
                        if (piVar5[1] == 4) {
                          opt_set_charp(uVar6,piVar5[5]);
                        }
joined_r0x0001c49e:
                        if (__ptr != (char *)0x0) goto joined_r0x0001c452;
                      }
                      else if (*piVar4 == 0) {
                        __ptr = (char *)parse_config();
                        goto joined_r0x0001c49e;
                      }
                      uVar9 = uVar9 + 1;
                    }
                    goto LAB_0001c322;
                  }
                  goto LAB_0001c35e;
                }
                uVar6 = json_string_value();
                __ptr = (char *)(*(code *)piVar5[3])(uVar6,piVar5[5]);
                if (piVar5[1] == 4) {
                  opt_set_charp(uVar6,piVar5[5]);
                }
              }
              if (__ptr != (char *)0x0) goto joined_r0x0001c452;
            }
LAB_0001c322:
            pcVar1 = strtok((char *)0x0,"|");
            if (pcVar1 == (char *)0x0) break;
          } while( true );
        }
        free(__s);
      }
      if (piVar5[8] == 0x10) break;
      iVar8 = piVar5[8] << 0x1c;
      piVar5 = piVar5 + 7;
    } while( true );
  }
  piVar5 = (int *)json_object_get(param_1,"include");
  if ((piVar5 != (int *)0x0) && (*piVar5 == 2)) {
    uVar6 = json_string_value(piVar5);
    puVar7 = (undefined1 *)load_config(uVar6,0);
    return puVar7;
  }
  return (undefined1 *)0x0;
joined_r0x0001c452:
  if (param_2 == 0) {
    snprintf(err_buf_13672,200,"Parsing JSON option %s: %s",pcVar1,__ptr);
    return err_buf_13672;
  }
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
    snprintf(acStack_828,0x800,"Invalid config option %s: %s",pcVar1,__ptr);
    _applog(3,acStack_828,0);
  }
  free(__ptr);
  fileconf_load = -1;
  pcVar1 = strtok((char *)0x0,"|");
  goto joined_r0x0001c31e;
}

