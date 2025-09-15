
byte pool_unusable_part_4(int param_1)

{
  byte bVar1;
  
  bVar1 = *(byte *)(param_1 + 0x280);
  if ((bVar1 != 0) && (*(char *)(param_1 + 0x281) != '\0')) {
    bVar1 = *(byte *)(param_1 + 0x283) ^ 1;
  }
  return bVar1;
}

