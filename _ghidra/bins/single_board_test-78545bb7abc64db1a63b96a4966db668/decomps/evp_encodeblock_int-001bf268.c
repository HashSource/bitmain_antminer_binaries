
int evp_encodeblock_int(int param_1,undefined1 *param_2,int param_3,int param_4)

{
  byte bVar1;
  undefined1 *puVar2;
  int iVar3;
  uint uVar4;
  char cVar5;
  uint uVar6;
  char *pcVar7;
  
  if (param_1 == 0) {
    pcVar7 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
  }
  else if (*(int *)(param_1 + 0x5c) << 0x1e < 0) {
    pcVar7 = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz./";
  }
  else {
    pcVar7 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
  }
  if (param_4 < 1) {
    iVar3 = 0;
  }
  else {
    param_3 = param_3 + 3;
    iVar3 = 0;
    puVar2 = param_2 + 4;
    do {
      param_2 = puVar2;
      if (param_4 < 3) {
        cVar5 = '=';
        uVar4 = (uint)*(byte *)(param_3 + -3) << 0x10;
        if (param_4 == 2) {
          uVar6 = (uint)*(byte *)(param_3 + -2) << 8;
          param_2[-4] = pcVar7[uVar4 >> 0x12];
          param_2[-3] = pcVar7[((uVar4 | uVar6) << 0xe) >> 0x1a];
          cVar5 = pcVar7[(uVar6 & 0xfc0) >> 6];
        }
        else {
          param_2[-4] = pcVar7[uVar4 >> 0x12];
          param_2[-3] = pcVar7[uVar4 >> 0xc & 0x3f];
        }
        param_2[-1] = 0x3d;
        param_2[-2] = cVar5;
      }
      else {
        bVar1 = *(byte *)(param_3 + -1);
        uVar4 = (uint)*(byte *)(param_3 + -3) << 0x10;
        uVar6 = (uint)bVar1 | (uint)*(byte *)(param_3 + -2) << 8 | uVar4;
        param_2[-4] = pcVar7[uVar4 >> 0x12];
        param_2[-3] = pcVar7[(uVar6 << 0xe) >> 0x1a];
        param_2[-2] = pcVar7[(uVar6 << 0x14) >> 0x1a];
        param_2[-1] = pcVar7[bVar1 & 0x3f];
      }
      param_4 = param_4 + -3;
      iVar3 = iVar3 + 4;
      param_3 = param_3 + 3;
      puVar2 = param_2 + 4;
    } while (0 < param_4);
  }
  *param_2 = 0;
  return iVar3;
}

