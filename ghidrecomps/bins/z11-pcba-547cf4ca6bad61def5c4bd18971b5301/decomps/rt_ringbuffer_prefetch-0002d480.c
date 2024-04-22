
ushort rt_ringbuffer_prefetch(void **param_1,void *param_2,ushort param_3)

{
  uint uVar1;
  ushort local_22;
  
  uVar1 = rt_ringbuffer_data_len(param_1);
  if (uVar1 == 0) {
    local_22 = 0;
  }
  else {
    local_22 = param_3;
    if (uVar1 < param_3) {
      local_22 = (ushort)uVar1;
    }
    if ((int)(uint)local_22 <
        (int)((uint)*(ushort *)(param_1 + 3) - (((uint)*(ushort *)(param_1 + 1) << 0x10) >> 0x11)))
    {
      memcpy(param_2,(void *)((int)*param_1 + (((uint)*(ushort *)(param_1 + 1) << 0x10) >> 0x11)),
             (uint)local_22);
    }
    else {
      memcpy(param_2,(void *)((int)*param_1 + (((uint)*(ushort *)(param_1 + 1) << 0x10) >> 0x11)),
             (uint)*(ushort *)(param_1 + 3) - (((uint)*(ushort *)(param_1 + 1) << 0x10) >> 0x11));
      memcpy((void *)((int)param_2 +
                     ((uint)*(ushort *)(param_1 + 3) -
                     (((uint)*(ushort *)(param_1 + 1) << 0x10) >> 0x11))),*param_1,
             (uint)local_22 -
             ((uint)*(ushort *)(param_1 + 3) - (((uint)*(ushort *)(param_1 + 1) << 0x10) >> 0x11)));
    }
  }
  return local_22;
}

