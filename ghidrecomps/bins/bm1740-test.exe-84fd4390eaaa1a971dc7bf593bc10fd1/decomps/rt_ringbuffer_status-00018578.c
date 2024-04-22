
undefined4 rt_ringbuffer_status(int param_1)

{
  undefined4 uVar1;
  
  if (((uint)*(ushort *)(param_1 + 4) << 0x10) >> 0x11 ==
      ((uint)*(ushort *)(param_1 + 6) << 0x10) >> 0x11) {
    if ((*(byte *)(param_1 + 4) & 1) == (*(byte *)(param_1 + 6) & 1)) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 2;
  }
  return uVar1;
}

