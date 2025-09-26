
int range_should_be_prefix(char *param_1,char *param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  
  if ((param_3 < 1) || (*param_1 != *param_2)) {
    iVar3 = 0;
  }
  else {
    iVar2 = 0;
    pcVar5 = param_2;
    pcVar4 = param_1;
    do {
      iVar2 = iVar2 + 1;
      iVar3 = param_3;
      if (param_3 == iVar2) break;
      pcVar4 = pcVar4 + 1;
      pcVar5 = pcVar5 + 1;
      iVar3 = iVar2;
    } while (*pcVar4 == *pcVar5);
  }
  param_3 = param_3 + -1;
  if (((-1 < param_3) && (param_1[param_3] == '\0')) && (param_2[param_3] == -1)) {
    pcVar5 = param_2 + param_3;
    pcVar4 = param_1 + param_3;
    do {
      bVar6 = param_3 == 0;
      param_3 = param_3 + -1;
      if ((bVar6) || (pcVar4 = pcVar4 + -1, *pcVar4 != '\0')) break;
      pcVar5 = pcVar5 + -1;
    } while (*pcVar5 == -1);
  }
  if (param_3 <= iVar3) {
    if (param_3 < iVar3) {
      return iVar3 << 3;
    }
    bVar1 = param_1[iVar3] ^ param_2[iVar3];
    if (bVar1 == 0xf) {
      iVar2 = 4;
    }
    else if (bVar1 < 0x10) {
      if (bVar1 == 3) {
        iVar2 = 6;
      }
      else if (bVar1 == 7) {
        iVar2 = 5;
      }
      else {
        if (bVar1 != 1) {
          return -1;
        }
        iVar2 = 7;
      }
    }
    else if (bVar1 == 0x3f) {
      iVar2 = 2;
    }
    else if (bVar1 == 0x7f) {
      iVar2 = 1;
    }
    else {
      if (bVar1 != 0x1f) {
        return -1;
      }
      iVar2 = 3;
    }
    if (((param_1[iVar3] & bVar1) == 0) && ((bVar1 & ~param_2[iVar3]) == 0)) {
      return iVar2 + iVar3 * 8;
    }
  }
  return -1;
}

