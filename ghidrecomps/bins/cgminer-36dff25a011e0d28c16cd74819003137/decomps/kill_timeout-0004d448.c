
void kill_timeout(thr_info *thr)

{
  thr_info *thr_local;
  
  cg_completion_timeout(thr_info_cancel,thr,1000);
  return;
}

