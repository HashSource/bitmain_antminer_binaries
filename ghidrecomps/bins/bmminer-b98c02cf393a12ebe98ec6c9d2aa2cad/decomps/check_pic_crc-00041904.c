
bool check_pic_crc(byte *param_1)

{
  byte bVar1;
  byte bVar2;
  FILE *__stream;
  byte *pbVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  if (param_1 == (byte *)0x0) {
    return false;
  }
  uVar4 = (uint)*param_1;
  if (3 < uVar4) {
    uVar6 = 0;
    pbVar3 = param_1;
    uVar5 = uVar4;
    while (uVar6 = uVar5 + uVar6 & 0xffff, pbVar3 != param_1 + (uVar4 - 3)) {
      pbVar3 = pbVar3 + 1;
      uVar5 = (uint)*pbVar3;
    }
    bVar1 = param_1[uVar4 - 1];
    bVar2 = pbVar3[1];
    if (5 < log_level) {
      __stream = fopen(log_file,(char *)&DAT_0005e760);
      if (__stream != (FILE *)0x0) {
        fprintf(__stream,"%s:%d:%s: sum1,sum2 = %d,%d\n","power.c",0x137,DAT_00041994,uVar6,
                (uint)CONCAT11(bVar2,bVar1));
      }
      fclose(__stream);
    }
    return uVar6 == CONCAT11(bVar2,bVar1);
  }
  return false;
}

