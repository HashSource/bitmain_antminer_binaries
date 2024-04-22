
_Bool abandon_work(work *work,timeval *wdiff,uint64_t hashes)

{
  _Bool _Var1;
  uint in_r2;
  int in_r3;
  bool bVar2;
  uint64_t hashes_local;
  timeval *wdiff_local;
  work *work_local;
  
  if (wdiff->tv_sec <= opt_scantime) {
    bVar2 = in_r3 == 0;
    if (in_r3 == 0) {
      bVar2 = in_r2 < 0xfffffffe;
    }
    if ((bVar2) && (_Var1 = stale_work(work,false), !_Var1)) {
      return false;
    }
  }
  return true;
}

