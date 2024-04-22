
char ** SRP_get_default_gN(char *param_1)

{
  char **ppcVar1;
  int iVar2;
  
  ppcVar1 = DAT_000d782c;
  if (param_1 == (char *)0x0) {
    return DAT_000d782c;
  }
  iVar2 = strcmp(*DAT_000d782c,param_1);
  if (iVar2 != 0) {
    iVar2 = strcmp(ppcVar1[3],param_1);
    if (iVar2 == 0) {
      iVar2 = 1;
    }
    else {
      iVar2 = strcmp(ppcVar1[6],param_1);
      if (iVar2 == 0) {
        iVar2 = 2;
      }
      else {
        iVar2 = strcmp(ppcVar1[9],param_1);
        if (iVar2 == 0) {
          iVar2 = 3;
        }
        else {
          iVar2 = strcmp(ppcVar1[0xc],param_1);
          if (iVar2 == 0) {
            iVar2 = 4;
          }
          else {
            iVar2 = strcmp(ppcVar1[0xf],param_1);
            if (iVar2 == 0) {
              iVar2 = 5;
            }
            else {
              iVar2 = strcmp(ppcVar1[0x12],param_1);
              if (iVar2 != 0) {
                return (char **)0x0;
              }
              iVar2 = 6;
            }
          }
        }
      }
    }
  }
  return ppcVar1 + iVar2 * 3;
}

