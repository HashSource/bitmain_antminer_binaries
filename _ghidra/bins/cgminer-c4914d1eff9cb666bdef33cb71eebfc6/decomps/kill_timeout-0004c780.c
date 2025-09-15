
void kill_timeout(thr_info *thr)

{
  thr_info *thr_local;
  
  cg_completion_timeout((void *)0x3ea8b,thr,1000);
  return;
}

