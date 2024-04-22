
ushort rt_ringbuffer_put(void **param_1,void *param_2,ushort param_3)

{
  short sVar1;
  short sVar2;
  ushort local_22;
  ushort local_12;
  
  pthread_mutex_lock((pthread_mutex_t *)(param_1 + 4));
  sVar1 = *(short *)(param_1 + 3);
  sVar2 = rt_ringbuffer_data_len(param_1);
  local_12 = sVar1 - sVar2;
  if (param_1[0x22] == (void *)0x1) {
    if (local_12 == 0) {
      pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 4));
      return 0;
    }
    local_22 = param_3;
    if (local_12 < param_3) {
      local_22 = local_12;
    }
  }
  else {
    local_22 = param_3;
    if (param_1[0x22] == (void *)0x0) {
      while (local_12 < param_3) {
        pthread_cond_wait((pthread_cond_t *)(param_1 + 10),(pthread_mutex_t *)(param_1 + 4));
        sVar1 = *(short *)(param_1 + 3);
        sVar2 = rt_ringbuffer_data_len(param_1);
        local_12 = sVar1 - sVar2;
      }
    }
  }
  if ((int)(uint)local_22 <
      (int)((uint)*(ushort *)(param_1 + 3) - (((uint)*(ushort *)((int)param_1 + 6) << 0x10) >> 0x11)
           )) {
    memcpy((void *)((int)*param_1 + (((uint)*(ushort *)((int)param_1 + 6) << 0x10) >> 0x11)),param_2
           ,(uint)local_22);
    *(ushort *)((int)param_1 + 6) =
         *(ushort *)((int)param_1 + 6) & 1 |
         (ushort)(((((uint)*(ushort *)((int)param_1 + 6) << 0x10) >> 0x11) + (uint)local_22 & 0x7fff
                  ) << 1);
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
           (uint)local_22 +
           ((((uint)*(ushort *)((int)param_1 + 6) << 0x10) >> 0x11) - (uint)*(ushort *)(param_1 + 3)
           ));
    *(byte *)((int)param_1 + 6) =
         *(byte *)((int)param_1 + 6) & 0xfe |
         ~(byte)(((uint)*(byte *)((int)param_1 + 6) << 0x1f) >> 0x1f) & 1;
    *(ushort *)((int)param_1 + 6) =
         *(ushort *)((int)param_1 + 6) & 1 |
         (ushort)((((((uint)*(ushort *)((int)param_1 + 6) << 0x10) >> 0x11) -
                    (uint)*(ushort *)(param_1 + 3) & 0xffff) + (uint)local_22 & 0x7fff) << 1);
    pthread_cond_signal((pthread_cond_t *)(param_1 + 0x16));
    pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 4));
  }
  return local_22;
}

