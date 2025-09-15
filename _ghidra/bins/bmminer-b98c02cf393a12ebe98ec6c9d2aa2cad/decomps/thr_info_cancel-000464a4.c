
void thr_info_cancel(int param_1)

{
  if (param_1 == 0) {
    return;
  }
  if (*(pthread_t *)(param_1 + 0xc) == 0) {
    sem_destroy((sem_t *)(param_1 + 0x10));
    return;
  }
  pthread_cancel(*(pthread_t *)(param_1 + 0xc));
  *(undefined4 *)(param_1 + 0xc) = 0;
  sem_destroy((sem_t *)(param_1 + 0x10));
  return;
}

