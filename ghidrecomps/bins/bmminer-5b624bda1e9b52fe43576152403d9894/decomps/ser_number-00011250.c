
/* WARNING: Unknown calling convention */
/* Local variable len:int[r0:4] conflicts with parameter, skipped. */

int ser_number(uchar *s,int32_t val)

{
  int iVar1;
  uchar uVar2;
  
  if (val < 0x80) {
    uVar2 = '\x01';
    iVar1 = 2;
  }
  else if (val < 0x4080) {
    iVar1 = 3;
    uVar2 = '\x02';
  }
  else if (val < 0x204080) {
    iVar1 = 4;
    uVar2 = '\x03';
  }
  else {
    iVar1 = 5;
    uVar2 = '\x04';
  }
  *(int32_t *)(s + 1) = val;
  *s = uVar2;
  return iVar1;
}

