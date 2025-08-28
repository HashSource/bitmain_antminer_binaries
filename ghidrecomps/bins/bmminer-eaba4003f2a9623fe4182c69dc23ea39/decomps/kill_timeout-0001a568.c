
void kill_timeout(thr_info *thr)

{
  thr_info *thr_local;
  
  cg_completion_timeout((void *)0x5afb5,thr,1000);
  return;
}

