
undefined4 file_connect(int *param_1,undefined *param_2)

{
  char cVar1;
  char *__file;
  void *pvVar2;
  undefined4 uVar3;
  char *pcVar4;
  int iVar5;
  char **ppcVar6;
  size_t local_24;
  
  iVar5 = *param_1;
  ppcVar6 = *(char ***)(iVar5 + 0x14c);
  __file = (char *)curl_easy_unescape(iVar5,*(undefined4 *)(iVar5 + 0x868c),0,&local_24);
  if (__file == (char *)0x0) {
    uVar3 = 0x1b;
  }
  else {
    pvVar2 = memchr(__file,0,local_24);
    if (pvVar2 == (void *)0x0) {
      pcVar4 = (char *)open64(__file,0);
      cVar1 = *(char *)(iVar5 + 0x309);
      ppcVar6[2] = pcVar4;
      *ppcVar6 = __file;
      ppcVar6[1] = __file;
      if ((cVar1 == '\0') && (pcVar4 == (char *)0xffffffff)) {
        Curl_failf(iVar5,DAT_00059e08,*(undefined4 *)(iVar5 + 0x868c));
        file_done(param_1,0x25,0);
        uVar3 = 0x25;
      }
      else {
        uVar3 = 0;
        *param_2 = 1;
      }
    }
    else {
      uVar3 = 3;
    }
  }
  return uVar3;
}

