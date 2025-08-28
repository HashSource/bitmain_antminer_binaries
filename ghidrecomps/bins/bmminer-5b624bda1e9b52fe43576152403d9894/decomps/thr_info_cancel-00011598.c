
/* WARNING: Unknown calling convention */

void thr_info_cancel(thr_info *thr)

{
  if (thr == (thr_info *)0x0) {
    return;
  }
  if (thr->pth != 0) {
    pthread_cancel(thr->pth);
    thr->pth = 0;
  }
  (*(code *)(undefined *)0x0)(&thr->sem);
  return;
}

