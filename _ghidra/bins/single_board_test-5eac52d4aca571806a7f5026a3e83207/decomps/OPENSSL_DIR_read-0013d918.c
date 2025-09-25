
int OPENSSL_DIR_read(int *param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  dirent *pdVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *__ptr;
  DIR *pDVar5;
  
  if (param_2 == (char *)0x0 || param_1 == (int *)0x0) {
    piVar1 = __errno_location();
    *piVar1 = 0x16;
    return 0;
  }
  piVar1 = __errno_location();
  puVar4 = (undefined4 *)*param_1;
  *piVar1 = 0;
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)calloc(0x1008,1);
    *param_1 = (int)puVar4;
    if (puVar4 == (undefined4 *)0x0) {
      *piVar1 = 0xc;
      return 0;
    }
    pDVar5 = opendir(param_2);
    __ptr = (undefined4 *)*param_1;
    *puVar4 = pDVar5;
    pDVar5 = (DIR *)*__ptr;
    if (pDVar5 == (DIR *)0x0) {
      iVar3 = *piVar1;
      free(__ptr);
      *param_1 = 0;
      *piVar1 = iVar3;
      return 0;
    }
  }
  else {
    pDVar5 = (DIR *)*puVar4;
  }
  pdVar2 = readdir(pDVar5);
  if (pdVar2 == (dirent *)0x0) {
    iVar3 = 0;
  }
  else {
    OPENSSL_strlcpy(*param_1 + 4,pdVar2->d_name,0x1001,*param_1,param_4);
    iVar3 = *param_1 + 4;
  }
  return iVar3;
}

