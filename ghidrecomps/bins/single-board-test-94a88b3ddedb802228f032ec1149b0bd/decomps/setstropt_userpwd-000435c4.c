
int * setstropt_userpwd(char *param_1,int *param_2,undefined4 *param_3)

{
  size_t sVar1;
  int *piVar2;
  undefined4 *puVar3;
  int local_20;
  undefined4 local_1c [2];
  
  local_20 = 0;
  local_1c[0] = 0;
  if (param_1 != (char *)0x0) {
    sVar1 = strlen(param_1);
    piVar2 = &local_20;
    if (param_2 == (int *)0x0) {
      piVar2 = (int *)0x0;
    }
    puVar3 = local_1c;
    if (param_3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    piVar2 = (int *)parse_login_details(param_1,sVar1,piVar2,puVar3,0);
    if (piVar2 != (int *)0x0) {
      return piVar2;
    }
  }
  piVar2 = param_2;
  if (param_2 != (int *)0x0) {
    if ((((local_20 == 0) && (param_1 != (char *)0x0)) && (*param_1 == ':')) &&
       (local_20 = (**DAT_0004364c)(DAT_00043650), local_20 == 0)) {
      piVar2 = (int *)0x1b;
    }
    else {
      piVar2 = (int *)0x0;
    }
    (**DAT_00043648)(*param_2);
    *param_2 = local_20;
  }
  if (param_3 != (undefined4 *)0x0) {
    (**DAT_00043648)(*param_3);
    *param_3 = local_1c[0];
  }
  return piVar2;
}

