
uint rt_ringbuffer_data_len(int param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = rt_ringbuffer_status(param_1);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else if (iVar1 == 1) {
    uVar2 = (uint)*(ushort *)(param_1 + 0xc);
  }
  else if (((uint)*(ushort *)(param_1 + 4) << 0x10) >> 0x11 <
           ((uint)*(ushort *)(param_1 + 6) << 0x10) >> 0x11) {
    uVar2 = (((uint)*(ushort *)(param_1 + 6) << 0x10) >> 0x11) -
            (((uint)*(ushort *)(param_1 + 4) << 0x10) >> 0x11) & 0xffff;
  }
  else {
    uVar2 = (uint)(ushort)(((*(ushort *)(param_1 + 6) >> 1) - (*(ushort *)(param_1 + 4) >> 1)) +
                          *(short *)(param_1 + 0xc));
  }
  return uVar2;
}

