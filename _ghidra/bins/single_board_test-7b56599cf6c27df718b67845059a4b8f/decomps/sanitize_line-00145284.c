
int sanitize_line(char *param_1,int param_2,uint param_3)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  char *pcVar6;
  bool bVar7;
  
  if ((param_3 & 2) == 0) {
    if ((int)(param_3 << 0x1d) < 0) {
      if (0 < param_2) {
        iVar3 = 0;
        pcVar6 = param_1;
        do {
          iVar4 = ossl_ctype_check(*pcVar6,0x400);
          if ((iVar4 == 0) || (*pcVar6 == '\n' || *pcVar6 == '\r')) {
            *pcVar6 = '\n';
            param_1[iVar3 + 1] = '\0';
            return iVar3 + 1;
          }
          iVar3 = iVar3 + 1;
          pcVar6 = pcVar6 + 1;
        } while (param_2 != iVar3);
        goto LAB_00145302;
      }
    }
    else if ((0 < param_2) && (cVar2 = *param_1, cVar2 != '\r' && cVar2 != '\n')) {
      iVar3 = 0;
      pcVar6 = param_1;
      while( true ) {
        iVar4 = iVar3;
        iVar3 = ossl_ctype_check(cVar2,0x40);
        if (iVar3 != 0) {
          *pcVar6 = ' ';
        }
        iVar3 = iVar4 + 1;
        if (param_2 == iVar3) break;
        pcVar6 = pcVar6 + 1;
        cVar2 = *pcVar6;
        if (cVar2 == '\r' || cVar2 == '\n') {
          iVar4 = iVar4 + 2;
          *pcVar6 = '\n';
          param_1[iVar4] = '\0';
          return iVar4;
        }
      }
LAB_00145302:
      param_1[param_2] = '\n';
      param_1[param_2 + 1] = '\0';
      return param_2 + 1;
    }
    iVar3 = 1;
    pcVar6 = param_1;
  }
  else {
    if (-1 < param_2) {
      bVar1 = param_1[param_2];
      pbVar5 = (byte *)(param_1 + param_2);
      while ((bVar1 < 0x21 && (bVar7 = param_2 != 0, param_2 = param_2 + -1, bVar7))) {
        pbVar5 = pbVar5 + -1;
        bVar1 = *pbVar5;
      }
    }
    iVar3 = param_2 + 2;
    pcVar6 = param_1 + param_2 + 1;
  }
  *pcVar6 = '\n';
  param_1[iVar3] = '\0';
  return iVar3;
}

