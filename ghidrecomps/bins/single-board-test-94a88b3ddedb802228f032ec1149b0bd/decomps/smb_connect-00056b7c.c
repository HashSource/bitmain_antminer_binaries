
undefined4 smb_connect(int param_1)

{
  int iVar1;
  char *pcVar2;
  char *__s;
  
  if (*(char *)(param_1 + 0x1f1) == '\0') {
    return 0x43;
  }
  memset((void *)(param_1 + 0x3c0),0,0x30);
  *(undefined4 *)(param_1 + 0x3c0) = 1;
  iVar1 = (*Curl_cmalloc)(0x9000);
  *(int *)(param_1 + 0x3dc) = iVar1;
  if (iVar1 != 0) {
    __s = *(char **)(param_1 + 0x120);
    *(undefined1 *)(param_1 + 0x1ed) = 0;
    pcVar2 = strchr(__s,0x2f);
    if ((pcVar2 == (char *)0x0) && (pcVar2 = strchr(__s,0x5c), pcVar2 == (char *)0x0)) {
      *(char **)(param_1 + 0x3c4) = __s;
      iVar1 = (*Curl_cstrdup)(*(undefined4 *)(param_1 + 0x98));
      *(int *)(param_1 + 0x3c8) = iVar1;
      if (iVar1 != 0) {
        return 0;
      }
    }
    else {
      *(char **)(param_1 + 0x3c4) = pcVar2 + 1;
      iVar1 = (*Curl_cstrdup)(__s);
      *(int *)(param_1 + 0x3c8) = iVar1;
      if (iVar1 != 0) {
        pcVar2[iVar1 - *(int *)(param_1 + 0x120)] = '\0';
        return 0;
      }
    }
  }
  return 0x1b;
}

