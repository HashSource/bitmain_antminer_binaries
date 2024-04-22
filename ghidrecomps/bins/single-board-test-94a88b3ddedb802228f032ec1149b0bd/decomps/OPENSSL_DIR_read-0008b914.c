
int OPENSSL_DIR_read(void **param_1,char *param_2)

{
  int *piVar1;
  dirent *pdVar2;
  void *__s;
  int iVar3;
  DIR *pDVar4;
  DIR **ppDVar5;
  
  if (param_1 == (void **)0x0 || param_2 == (char *)0x0) {
    piVar1 = __errno_location();
    *piVar1 = 0x16;
    return 0;
  }
  piVar1 = __errno_location();
  ppDVar5 = (DIR **)*param_1;
  *piVar1 = 0;
  if (ppDVar5 == (DIR **)0x0) {
    __s = malloc(0x1008);
    *param_1 = __s;
    if (__s == (void *)0x0) {
      *piVar1 = 0xc;
      return 0;
    }
    memset(__s,0,0x1008);
    ppDVar5 = (DIR **)*param_1;
    pDVar4 = opendir(param_2);
    *ppDVar5 = pDVar4;
                    /* WARNING: Load size is inaccurate */
    pDVar4 = **param_1;
    if (pDVar4 == (DIR *)0x0) {
      iVar3 = *piVar1;
      free(*param_1);
      *param_1 = (void *)0x0;
      *piVar1 = iVar3;
      return 0;
    }
  }
  else {
    pDVar4 = *ppDVar5;
  }
  pdVar2 = readdir(pDVar4);
  if (pdVar2 == (dirent *)0x0) {
    iVar3 = 0;
  }
  else {
    strncpy((char *)((int)*param_1 + 4),pdVar2->d_name,0x1000);
    *(undefined *)((int)*param_1 + 0x1004) = 0;
    iVar3 = (int)*param_1 + 4;
  }
  return iVar3;
}

