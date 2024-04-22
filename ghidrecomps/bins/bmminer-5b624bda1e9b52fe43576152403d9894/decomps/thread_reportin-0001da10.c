
/* WARNING: Unknown calling convention */

void thread_reportin(thr_info *thr)

{
  time_t tVar1;
  cgpu_info *pcVar2;
  
  thr->getwork = false;
  cgtime(&thr->last);
  pcVar2 = thr->cgpu;
  pcVar2->status = LIFE_WELL;
  tVar1 = time((time_t *)0x0);
  pcVar2->device_last_well = tVar1;
  return;
}

