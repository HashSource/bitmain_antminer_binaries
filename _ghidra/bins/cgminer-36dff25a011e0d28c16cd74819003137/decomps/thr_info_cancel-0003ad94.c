
void thr_info_cancel(thr_info *thr)

{
  thr_info *thr_local;
  
  if (thr != (thr_info *)0x0) {
    if (thr->pth != 0) {
      pthread_cancel(thr->pth);
      thr->pth = 0;
    }
    cgsem_destroy(&thr->sem);
  }
  return;
}

