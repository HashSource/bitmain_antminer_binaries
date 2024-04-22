
int * parse_version_rolling_mask(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  char *__s1;
  size_t sVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 local_924 [23];
  undefined auStack_8c8 [160];
  char acStack_828 [2052];
  
  iVar1 = json_loads(param_2,0,local_924);
  if (iVar1 == 0) {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (5 < opt_log_level)) {
      snprintf(acStack_828,0x800,"JSON decode failed(%d): %s",local_924[0],auStack_8c8);
      _applog(6,acStack_828,0);
    }
    return (int *)0x0;
  }
  piVar2 = (int *)json_object_get(iVar1,"result");
  piVar3 = (int *)json_object_get(iVar1,"error");
  if (piVar2 != (int *)0x0) {
    if ((*piVar2 == 7) || ((piVar3 != (int *)0x0 && (*piVar3 != 7)))) {
      piVar2 = (int *)0x0;
    }
    else {
      json_object_iter(piVar2);
      __s1 = (char *)json_object_iter_key();
      while (__s1 != (char *)0x0) {
        json_object_key_to_iter(__s1);
        piVar3 = (int *)json_object_iter_value();
        if (piVar3 == (int *)0x0) break;
        iVar6 = strcasecmp(__s1,"version-rolling");
        if ((iVar6 == 0) && (sVar4 = strlen(__s1), sVar4 == 0xf)) {
          if (*piVar3 != 5) {
            *(undefined *)(param_1 + 0xa1) = 0;
            param_1[0xa2] = 1;
            piVar2 = (int *)0x0;
            goto LAB_00046c86;
          }
          if (((use_syslog != '\0') || (opt_log_output != '\0')) || (4 < opt_log_level)) {
            snprintf(acStack_828,0x800,"POOL %d support ab mode!",*param_1);
            _applog(5,acStack_828,0);
          }
        }
        else {
          iVar6 = strcasecmp(__s1,"version-rolling.mask");
          if (iVar6 == 0) {
            uVar5 = json_string_value(piVar3);
            process_version_mask(param_1,uVar5);
          }
          else if (((use_syslog != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
            snprintf(acStack_828,0x800,"JSON-RPC unexpected mining.configure value: %s",__s1);
            _applog(3,acStack_828,0);
          }
        }
        uVar5 = json_object_key_to_iter(__s1);
        json_object_iter_next(piVar2,uVar5);
        __s1 = (char *)json_object_iter_key();
      }
      piVar2 = (int *)0x1;
    }
  }
LAB_00046c86:
  if ((*(int *)(iVar1 + 4) != -1) &&
     (iVar6 = *(int *)(iVar1 + 4) + -1, *(int *)(iVar1 + 4) = iVar6, iVar6 == 0)) {
    json_delete(iVar1);
    return piVar2;
  }
  return piVar2;
}

