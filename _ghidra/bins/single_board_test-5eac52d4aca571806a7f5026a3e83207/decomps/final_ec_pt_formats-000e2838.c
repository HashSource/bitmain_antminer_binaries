
undefined4 final_ec_pt_formats(int param_1)

{
  char *pcVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  
  if ((((*(int *)(param_1 + 0x1c) == 0) && (*(int *)(param_1 + 0x564) != 0)) &&
      (*(int *)(param_1 + 0x560) != 0)) &&
     ((((pcVar1 = *(char **)(param_1 + 0x56c), pcVar1 != (char *)0x0 &&
        (iVar4 = *(int *)(param_1 + 0x568), iVar4 != 0)) &&
       ((iVar2 = *(int *)(*(int *)(param_1 + 0x7c) + 0x210), *(int *)(iVar2 + 0x10) << 0x1d < 0 ||
        (*(int *)(iVar2 + 0x14) << 0x1c < 0)))) && (*pcVar1 != '\0')))) {
    pcVar3 = pcVar1;
    do {
      pcVar3 = pcVar3 + 1;
      if (pcVar1 + iVar4 == pcVar3) break;
    } while (*pcVar3 != '\0');
    if ((int)pcVar3 - (int)pcVar1 == iVar4) {
      ossl_statem_fatal(param_1,0x2f,0x1e5,0x9d,"ssl/statem/extensions.c",0x42e);
      return 0;
    }
  }
  return 1;
}

