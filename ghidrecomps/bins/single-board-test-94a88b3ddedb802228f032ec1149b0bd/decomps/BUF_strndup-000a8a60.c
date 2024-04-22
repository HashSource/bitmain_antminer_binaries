
char * BUF_strndup(char *str,size_t siz)

{
  char cVar1;
  char *pcVar2;
  int num;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  bool bVar7;
  
  if (str == (char *)0x0) {
    pcVar3 = (char *)0x0;
  }
  else {
    if (siz == 0) {
      num = 1;
      iVar4 = 0;
    }
    else if (*str == '\0') {
      num = 1;
      iVar4 = 0;
    }
    else {
      iVar4 = 0;
      pcVar3 = str + 1;
      do {
        pcVar6 = pcVar3;
        bVar7 = iVar4 == siz - 1;
        iVar4 = iVar4 + 1;
        if (bVar7) {
          iVar4 = (int)pcVar6 - (int)str;
          num = iVar4 + 1;
          goto LAB_000a8a90;
        }
        pcVar3 = pcVar6 + 1;
      } while (*pcVar6 != '\0');
      iVar4 = (int)pcVar6 - (int)str;
      num = iVar4 + 1;
    }
LAB_000a8a90:
    pcVar3 = (char *)CRYPTO_malloc(num,DAT_000a8af4,0x58);
    if (pcVar3 == (char *)0x0) {
      ERR_put_error(7,0x68,0x41,DAT_000a8af4,0x5a);
    }
    else {
      uVar5 = iVar4 + 1;
      if (uVar5 < 2) {
        pcVar6 = pcVar3;
        if (uVar5 == 0) {
          return pcVar3;
        }
      }
      else {
        cVar1 = *str;
        pcVar2 = pcVar3;
        while (pcVar6 = pcVar2, cVar1 != '\0') {
          uVar5 = uVar5 - 1;
          *pcVar2 = cVar1;
          pcVar6 = pcVar2 + 1;
          if (uVar5 == 1) break;
          str = str + 1;
          pcVar2 = pcVar2 + 1;
          cVar1 = *str;
        }
      }
      *pcVar6 = '\0';
    }
  }
  return pcVar3;
}

