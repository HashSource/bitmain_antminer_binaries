
int ssl3_get_cipher_by_std_name(char *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_38 [6];
  
  iVar5 = 0;
  local_38[0] = DAT_002715c0;
  local_38[1] = DAT_002715c4;
  local_38[2] = DAT_002715c8;
  local_38[3] = 5;
  local_38[4] = 0xa4;
  local_38[5] = 2;
  do {
    iVar4 = local_38[iVar5 + 3];
    iVar2 = local_38[iVar5];
    if (iVar4 != 0) {
      iVar3 = 0;
      do {
        iVar3 = iVar3 + 1;
        if ((*(char **)(iVar2 + 8) != (char *)0x0) &&
           (iVar1 = strcmp(param_1,*(char **)(iVar2 + 8)), iVar1 == 0)) {
          return iVar2;
        }
        iVar2 = iVar2 + 0x40;
      } while (iVar3 != iVar4);
    }
    iVar5 = iVar5 + 1;
    if (iVar5 == 3) {
      return 0;
    }
  } while( true );
}

