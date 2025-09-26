
undefined4 ia5ncasecmp(byte *param_1,int param_2,int param_3)

{
  byte *pbVar1;
  undefined4 uVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  byte *pbVar2;
  
  if (param_3 == 0) {
    return 0;
  }
  pbVar4 = (byte *)(param_2 + -1);
  pbVar2 = param_1;
  do {
    pbVar1 = pbVar2 + 1;
    uVar5 = (uint)*pbVar2;
    pbVar4 = pbVar4 + 1;
    uVar6 = (uint)*pbVar4;
    if (uVar5 != uVar6) {
      if (uVar5 - 0x41 < 0x1a) {
        uVar5 = uVar5 + 0x20 & 0xff;
        if (0x19 < uVar6 - 0x41) {
          if (uVar6 != uVar5) goto LAB_0017fc64;
          goto LAB_0017fc7a;
        }
      }
      else if (0x19 < uVar6 - 0x41) goto LAB_0017fc64;
      uVar6 = uVar6 + 0x20 & 0xff;
      if (uVar6 != uVar5) {
LAB_0017fc64:
        if (uVar5 < uVar6) {
          uVar3 = 0xffffffff;
        }
        else {
          uVar3 = 1;
        }
        return uVar3;
      }
    }
LAB_0017fc7a:
    pbVar2 = pbVar1;
    if (pbVar1 == param_1 + param_3) {
      return 0;
    }
  } while( true );
}

