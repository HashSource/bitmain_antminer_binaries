
thr_info * get_thread(int thr_id)

{
  thr_info *ptVar1;
  int thr_id_local;
  thr_info *thr;
  
  _rd_lock(&mining_thr_lock,"cgminer.c","get_thread",0x24b);
  ptVar1 = __get_thread(thr_id);
  _rd_unlock(&mining_thr_lock,"cgminer.c","get_thread",0x24d);
  return ptVar1;
}

