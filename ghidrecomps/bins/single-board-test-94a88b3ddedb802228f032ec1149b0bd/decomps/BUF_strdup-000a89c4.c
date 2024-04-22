
char * BUF_strdup(char *str)

{
  char cVar1;
  char *pcVar2;
  size_t sVar3;
  int num;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  char *pcVar7;
  bool bVar8;
  
  if (str == (char *)0x0) {
    pcVar4 = (char *)0x0;
  }
  else {
    sVar3 = strlen(str);
    if (sVar3 == 0) {
      num = 1;
      iVar5 = 0;
    }
    else if (*str == '\0') {
      num = 1;
      iVar5 = 0;
    }
    else {
      iVar5 = 0;
      pcVar4 = str + 1;
      do {
        pcVar7 = pcVar4;
        bVar8 = iVar5 == sVar3 - 1;
        iVar5 = iVar5 + 1;
        if (bVar8) {
          iVar5 = (int)pcVar7 - (int)str;
          num = iVar5 + 1;
          goto LAB_000a89f8;
        }
        pcVar4 = pcVar7 + 1;
      } while (*pcVar7 != '\0');
      iVar5 = (int)pcVar7 - (int)str;
      num = iVar5 + 1;
    }
LAB_000a89f8:
    pcVar4 = (char *)CRYPTO_malloc(num,DAT_000a8a5c,0x58);
    if (pcVar4 == (char *)0x0) {
      ERR_put_error(7,0x68,0x41,DAT_000a8a5c,0x5a);
    }
    else {
      uVar6 = iVar5 + 1;
      if (uVar6 < 2) {
        pcVar7 = pcVar4;
        if (uVar6 == 0) {
          return pcVar4;
        }
      }
      else {
        cVar1 = *str;
        pcVar2 = pcVar4;
        while (pcVar7 = pcVar2, cVar1 != '\0') {
          uVar6 = uVar6 - 1;
          *pcVar2 = cVar1;
          pcVar7 = pcVar2 + 1;
          if (uVar6 == 1) break;
          str = str + 1;
          pcVar2 = pcVar2 + 1;
          cVar1 = *str;
        }
      }
      *pcVar7 = '\0';
    }
  }
  return pcVar4;
}

