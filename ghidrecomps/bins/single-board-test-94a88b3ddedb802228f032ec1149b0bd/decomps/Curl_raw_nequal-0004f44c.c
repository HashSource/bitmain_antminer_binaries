
bool Curl_raw_nequal(byte *param_1,byte *param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  byte *pbVar3;
  uint uVar4;
  uint uVar5;
  
  uVar2 = (uint)*param_1;
  if ((uVar2 == 0) || (uVar1 = (uint)*param_2, uVar1 == 0)) {
LAB_0004f4ca:
    if (param_3 != 0) {
      uVar5 = uVar2 - 0x61 & 0xff;
      pbVar3 = param_2;
LAB_0004f4a6:
      uVar1 = (uint)*pbVar3;
      if (uVar5 < 0x1a) {
        uVar2 = uVar2 - 0x20 & 0xff;
      }
      if (uVar1 - 0x61 < 0x1a) {
        uVar1 = uVar1 - 0x20 & 0xff;
      }
      return uVar2 == uVar1;
    }
  }
  else {
    pbVar3 = param_2;
    if (param_3 != 0) {
      do {
        uVar5 = uVar2 - 0x61 & 0xff;
        uVar4 = uVar2;
        if (uVar5 < 0x1a) {
          uVar4 = uVar2 - 0x20 & 0xff;
        }
        if (uVar1 - 0x61 < 0x1a) {
          uVar1 = uVar1 - 0x20 & 0xff;
        }
        param_2 = pbVar3 + 1;
        param_3 = param_3 + -1;
        if (uVar4 != uVar1) goto LAB_0004f4a6;
        param_1 = param_1 + 1;
        uVar2 = (uint)*param_1;
        if ((uVar2 == 0) || (uVar1 = (uint)pbVar3[1], uVar1 == 0)) goto LAB_0004f4ca;
        pbVar3 = param_2;
      } while (param_3 != 0);
    }
  }
  return true;
}

