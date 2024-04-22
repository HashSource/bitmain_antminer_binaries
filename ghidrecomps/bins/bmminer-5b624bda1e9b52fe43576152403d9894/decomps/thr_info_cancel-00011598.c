
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
                    /* WARNING: Could not recover jumptable at 0x0000a1d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_LAB_0005f1dc)(&thr->sem);
  return;
}

