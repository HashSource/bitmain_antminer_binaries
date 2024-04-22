
/* WARNING: Unknown calling convention */

uchar c2hex(uchar value)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = (uint)value;
  if (uVar1 - 0x30 < 10) {
    return value & 0xf;
  }
  uVar2 = uVar1 & 0xdf;
  if (uVar2 == 0x41) {
    return '\n';
  }
  if (uVar2 == 0x42) {
    return '\v';
  }
  if (uVar2 == 0x43) {
    return '\f';
  }
  if (uVar2 == 0x44) {
    return '\r';
  }
  if (uVar2 == 0x45) {
    return '\x0e';
  }
  if (uVar2 == 0x46) {
    return '\x0f';
  }
  printf("input value error: %c\n",uVar1);
  return 0xff;
}

