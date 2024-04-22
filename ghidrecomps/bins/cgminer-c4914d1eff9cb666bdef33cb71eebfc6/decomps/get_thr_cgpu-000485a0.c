
cgpu_info * get_thr_cgpu(int thr_id)

{
  thr_info *ptVar1;
  int thr_id_local;
  thr_info *thr;
  
  ptVar1 = get_thread(thr_id);
  return ptVar1->cgpu;
}

