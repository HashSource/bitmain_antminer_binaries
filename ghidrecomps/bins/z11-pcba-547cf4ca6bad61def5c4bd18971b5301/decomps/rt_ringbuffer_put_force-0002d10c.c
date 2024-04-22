
ushort rt_ringbuffer_put_force(void **param_1,void *param_2,ushort param_3)

{
  short sVar1;
  ushort uVar2;
  short sVar3;
  ushort local_22;
  
  pthread_mutex_lock((pthread_mutex_t *)(param_1 + 4));
  sVar1 = *(short *)(param_1 + 3);
  sVar3 = rt_ringbuffer_data_len(param_1);
  uVar2 = sVar1 - sVar3;
  local_22 = param_3;
  if (uVar2 < param_3) {
    local_22 = *(ushort *)(param_1 + 3);
  }
  if ((int)(uint)local_22 <
      (int)((uint)*(ushort *)(param_1 + 3) - (((uint)*(ushort *)((int)param_1 + 6) << 0x10) >> 0x11)
           )) {
    memcpy((void *)((int)*param_1 + (((uint)*(ushort *)((int)param_1 + 6) << 0x10) >> 0x11)),param_2
           ,(uint)local_22);
    *(ushort *)((int)param_1 + 6) =
         *(ushort *)((int)param_1 + 6) & 1 |
         (ushort)(((uint)local_22 + (((uint)*(ushort *)((int)param_1 + 6) << 0x10) >> 0x11) & 0x7fff
                  ) << 1);
    if (uVar2 < local_22) {
      *(ushort *)(param_1 + 1) =
           *(ushort *)(param_1 + 1) & 1 |
           (ushort)((((uint)*(ushort *)((int)param_1 + 6) << 0x10) >> 0x11) << 1);
    }
    pthread_cond_signal((pthread_cond_t *)(param_1 + 0x16));
    pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 4));
  }
  else {
    memcpy((void *)((int)*param_1 + (((uint)*(ushort *)((int)param_1 + 6) << 0x10) >> 0x11)),param_2
           ,(uint)*(ushort *)(param_1 + 3) - (((uint)*(ushort *)((int)param_1 + 6) << 0x10) >> 0x11)
          );
    memcpy(*param_1,(void *)((int)param_2 +
                            ((uint)*(ushort *)(param_1 + 3) -
                            (((uint)*(ushort *)((int)param_1 + 6) << 0x10) >> 0x11))),
           (uint)local_22 -
           ((uint)*(ushort *)(param_1 + 3) - (((uint)*(ushort *)((int)param_1 + 6) << 0x10) >> 0x11)
           ));
    *(byte *)((int)param_1 + 6) =
         *(byte *)((int)param_1 + 6) & 0xfe |
         ~(byte)(((uint)*(byte *)((int)param_1 + 6) << 0x1f) >> 0x1f) & 1;
    *(ushort *)((int)param_1 + 6) =
         *(ushort *)((int)param_1 + 6) & 1 |
         (ushort)(((uint)local_22 +
                   ((((uint)*(ushort *)((int)param_1 + 6) << 0x10) >> 0x11) -
                    (uint)*(ushort *)(param_1 + 3) & 0xffff) & 0x7fff) << 1);
    if (uVar2 < local_22) {
      *(byte *)(param_1 + 1) =
           *(byte *)(param_1 + 1) & 0xfe |
           ~(byte)(((uint)*(byte *)(param_1 + 1) << 0x1f) >> 0x1f) & 1;
      *(ushort *)(param_1 + 1) =
           *(ushort *)(param_1 + 1) & 1 |
           (ushort)((((uint)*(ushort *)((int)param_1 + 6) << 0x10) >> 0x11) << 1);
    }
    pthread_cond_signal((pthread_cond_t *)(param_1 + 0x16));
    pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 4));
  }
  return local_22;
}

