
void rt_ringbuffer_init(undefined4 *param_1,undefined4 param_2,ushort param_3,undefined4 param_4)

{
  *(ushort *)(param_1 + 1) = *(ushort *)(param_1 + 1) & 1;
  *(byte *)(param_1 + 1) =
       *(byte *)(param_1 + 1) & 0xfe | (byte)(((uint)*(ushort *)(param_1 + 1) << 0x10) >> 0x11) & 1;
  *(ushort *)((int)param_1 + 6) = *(ushort *)((int)param_1 + 6) & 1;
  *(byte *)((int)param_1 + 6) =
       *(byte *)((int)param_1 + 6) & 0xfe |
       (byte)(((uint)*(ushort *)((int)param_1 + 6) << 0x10) >> 0x11) & 1;
  *param_1 = param_2;
  *(ushort *)(param_1 + 3) = param_3 & 0xfffc;
  param_1[0x22] = param_4;
  pthread_mutex_init((pthread_mutex_t *)(param_1 + 4),(pthread_mutexattr_t *)0x0);
  if (param_1[0x22] == 0) {
    pthread_cond_init((pthread_cond_t *)(param_1 + 10),(pthread_condattr_t *)0x0);
    pthread_cond_init((pthread_cond_t *)(param_1 + 0x16),(pthread_condattr_t *)0x0);
  }
  return;
}

