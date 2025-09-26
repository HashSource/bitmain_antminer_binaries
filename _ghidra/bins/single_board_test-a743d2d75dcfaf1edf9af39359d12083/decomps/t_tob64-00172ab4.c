
void t_tob64(char *param_1,byte *param_2,int param_3)

{
  byte *pbVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  iVar5 = param_3 % 3;
  if (iVar5 == 1) {
    uVar4 = (uint)*param_2;
    uVar6 = 0;
  }
  else if (iVar5 == 2) {
    uVar6 = (uint)*param_2;
    uVar4 = (uint)param_2[1];
  }
  else {
    uVar4 = 0;
    uVar6 = uVar4;
  }
  uVar7 = 0;
  uVar3 = 0;
  pbVar1 = param_2 + iVar5;
  do {
    uVar7 = uVar7 & 1;
    if (uVar3 >> 2 != 0) {
      uVar7 = 1;
    }
    if (uVar7 == 0) {
      uVar7 = uVar6 >> 4 | (uVar3 & 3) << 4;
      pcVar2 = param_1;
      if (uVar7 != 0) goto LAB_00172b06;
      uVar6 = uVar4 >> 6 | (uVar6 & 0xf) << 2;
      if (uVar6 != 0) goto LAB_00172b18;
      uVar7 = uVar4 & 0x3f;
      if (uVar7 != 0) goto LAB_00172b22;
    }
    else {
      uVar7 = uVar6 >> 4 | (uVar3 & 3) << 4;
      *param_1 = b64table[uVar3 >> 2];
      pcVar2 = param_1 + 1;
LAB_00172b06:
      uVar6 = uVar4 >> 6 | (uVar6 & 0xf) << 2;
      param_1 = pcVar2 + 1;
      *pcVar2 = b64table[uVar7];
LAB_00172b18:
      *param_1 = b64table[uVar6];
      pcVar2 = param_1 + 1;
LAB_00172b22:
      uVar7 = 1;
      param_1 = pcVar2 + 1;
      *pcVar2 = b64table[uVar4 & 0x3f];
    }
    if (param_3 <= iVar5) {
      *param_1 = '\0';
      return;
    }
    uVar3 = (uint)*pbVar1;
    iVar5 = iVar5 + 3;
    uVar6 = (uint)pbVar1[1];
    uVar4 = (uint)pbVar1[2];
    pbVar1 = pbVar1 + 3;
  } while( true );
}

