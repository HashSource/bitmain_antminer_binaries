
undefined check_pic_crc(byte *param_1)

{
  FILE *__stream;
  undefined uVar1;
  ushort uVar2;
  bool bVar3;
  byte *local_24;
  uint local_10;
  ushort local_a;
  
  local_a = 0;
  if ((param_1 == (byte *)0x0) || (*param_1 < 4)) {
    uVar1 = 0;
  }
  else {
    local_24 = param_1;
    for (local_10 = 0; local_10 < *param_1 - 2; local_10 = local_10 + 1) {
      local_a = local_a + *local_24;
      local_24 = local_24 + 1;
    }
    uVar2 = CONCAT11(*local_24,local_24[1]);
    if (5 < log_level) {
      __stream = fopen(log_file,"a+");
      if (__stream != (FILE *)0x0) {
        fprintf(__stream,"%s:%d: sum1,sum2 = %d,%d\n","power.c",0x138,(uint)local_a,(uint)uVar2);
      }
      fclose(__stream);
    }
    bVar3 = local_a == uVar2;
    if (bVar3) {
      uVar2 = 1;
    }
    uVar1 = (undefined)uVar2;
    if (!bVar3) {
      uVar1 = 0;
    }
  }
  return uVar1;
}

