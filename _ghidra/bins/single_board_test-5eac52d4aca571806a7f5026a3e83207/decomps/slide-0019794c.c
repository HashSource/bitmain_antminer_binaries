
void slide(char *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  byte *pbVar6;
  char *pcVar7;
  uint uVar8;
  char *pcVar9;
  int iVar10;
  
  uVar1 = 0;
  pbVar6 = (byte *)(param_1 + -1);
  do {
    iVar2 = (int)uVar1 >> 3;
    uVar8 = uVar1 & 7;
    uVar1 = uVar1 + 1;
    pbVar6 = pbVar6 + 1;
    *pbVar6 = (byte)((int)(uint)*(byte *)(param_2 + iVar2) >> uVar8) & 1;
  } while (uVar1 != 0x100);
  iVar2 = 0;
  pcVar9 = param_1 + 0x100;
  do {
    if (*param_1 != '\0') {
      uVar1 = 1;
      pcVar7 = param_1;
      do {
        if (0xff < uVar1 + iVar2) break;
        pcVar7 = pcVar7 + 1;
        if (*pcVar7 != 0) {
          iVar3 = (int)*pcVar7 << (uVar1 & 0xff);
          iVar10 = *param_1 + iVar3;
          if (iVar10 < 0x10) {
            *param_1 = (char)iVar10;
            *pcVar7 = '\0';
          }
          else {
            iVar3 = *param_1 - iVar3;
            if (iVar3 + 0xf < 0 != SCARRY4(iVar3,0xf)) break;
            *param_1 = (char)iVar3;
            pcVar4 = pcVar7;
            do {
              if (*pcVar4 == '\0') {
                *pcVar4 = '\x01';
                break;
              }
              pcVar5 = pcVar4 + 1;
              *pcVar4 = '\0';
              pcVar4 = pcVar5;
            } while (pcVar9 != pcVar5);
          }
        }
        uVar1 = uVar1 + 1;
      } while (uVar1 != 7);
    }
    iVar2 = iVar2 + 1;
    param_1 = param_1 + 1;
    if (iVar2 == 0x100) {
      return;
    }
  } while( true );
}

