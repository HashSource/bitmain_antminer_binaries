
bool Curl_raw_equal(byte *param_1,byte *param_2)

{
  byte bVar1;
  byte *pbVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar4 = (uint)*param_1;
  if (uVar4 == 0) {
LAB_0004f43c:
    uVar5 = (uint)*param_2;
    uVar4 = 0;
  }
  else {
    bVar1 = *param_2;
    pbVar2 = param_2;
    while (uVar5 = (uint)bVar1, uVar5 != 0) {
      uVar6 = uVar4 - 0x61 & 0xff;
      uVar3 = uVar4;
      if (uVar6 < 0x1a) {
        uVar3 = uVar4 - 0x20 & 0xff;
      }
      if (uVar5 - 0x61 < 0x1a) {
        uVar5 = uVar5 - 0x20 & 0xff;
      }
      if (uVar3 != uVar5) {
        uVar5 = (uint)*pbVar2;
        goto LAB_0004f41e;
      }
      param_1 = param_1 + 1;
      uVar4 = (uint)*param_1;
      param_2 = pbVar2 + 1;
      if (uVar4 == 0) goto LAB_0004f43c;
      bVar1 = pbVar2[1];
      pbVar2 = param_2;
    }
    uVar6 = uVar4 - 0x61 & 0xff;
    uVar5 = 0;
LAB_0004f41e:
    if (uVar6 < 0x1a) {
      uVar4 = uVar4 - 0x20 & 0xff;
    }
  }
  if (uVar5 - 0x61 < 0x1a) {
    uVar5 = uVar5 - 0x20 & 0xff;
  }
  return uVar4 == uVar5;
}

