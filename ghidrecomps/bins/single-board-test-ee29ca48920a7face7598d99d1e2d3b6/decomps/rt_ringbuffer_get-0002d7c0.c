
ushort rt_ringbuffer_get(void **param_1,void *param_2,ushort param_3)

{
  ushort local_22;
  uint local_14;
  
  pthread_mutex_lock((pthread_mutex_t *)(param_1 + 4));
  local_14 = rt_ringbuffer_data_len(param_1);
  local_22 = param_3;
  if (param_1[0x22] == (void *)0x1) {
    if (local_14 == 0) {
      pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 4));
      return 0;
    }
    if (local_14 < param_3) {
      local_22 = (ushort)local_14;
    }
  }
  else if (param_1[0x22] == (void *)0x0) {
    while (local_14 < param_3) {
      pthread_cond_wait((pthread_cond_t *)(param_1 + 0x16),(pthread_mutex_t *)(param_1 + 4));
      local_14 = rt_ringbuffer_data_len(param_1);
    }
  }
  if ((int)(uint)local_22 <
      (int)((uint)*(ushort *)(param_1 + 3) - (((uint)*(ushort *)(param_1 + 1) << 0x10) >> 0x11))) {
    memcpy(param_2,(void *)((int)*param_1 + (((uint)*(ushort *)(param_1 + 1) << 0x10) >> 0x11)),
           (uint)local_22);
    *(ushort *)(param_1 + 1) =
         *(ushort *)(param_1 + 1) & 1 |
         (ushort)(((uint)local_22 + (((uint)*(ushort *)(param_1 + 1) << 0x10) >> 0x11) & 0x7fff) <<
                 1);
    pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 4));
    pthread_cond_signal((pthread_cond_t *)(param_1 + 10));
  }
  else {
    memcpy(param_2,(void *)((int)*param_1 + (((uint)*(ushort *)(param_1 + 1) << 0x10) >> 0x11)),
           (uint)*(ushort *)(param_1 + 3) - (((uint)*(ushort *)(param_1 + 1) << 0x10) >> 0x11));
    memcpy((void *)((int)param_2 +
                   ((uint)*(ushort *)(param_1 + 3) -
                   (((uint)*(ushort *)(param_1 + 1) << 0x10) >> 0x11))),*param_1,
           (uint)local_22 -
           ((uint)*(ushort *)(param_1 + 3) - (((uint)*(ushort *)(param_1 + 1) << 0x10) >> 0x11)));
    *(byte *)(param_1 + 1) =
         *(byte *)(param_1 + 1) & 0xfe | ~(byte)(((uint)*(byte *)(param_1 + 1) << 0x1f) >> 0x1f) & 1
    ;
    *(ushort *)(param_1 + 1) =
         *(ushort *)(param_1 + 1) & 1 |
         (ushort)(((uint)local_22 +
                   ((((uint)*(ushort *)(param_1 + 1) << 0x10) >> 0x11) -
                    (uint)*(ushort *)(param_1 + 3) & 0xffff) & 0x7fff) << 1);
    pthread_cond_signal((pthread_cond_t *)(param_1 + 10));
    pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 4));
  }
  return local_22;
}

