
void thread_reportout(thr_info *thr)

{
  time_t tVar1;
  cgpu_info *pcVar2;
  thr_info *thr_local;
  
  thr->getwork = true;
  cgtime(&thr->last);
  thr->cgpu->status = LIFE_WELL;
  pcVar2 = thr->cgpu;
  tVar1 = time((time_t *)0x0);
  pcVar2->device_last_well = tVar1;
  return;
}

