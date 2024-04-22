
_Bool abandon_work(work *work,timeval *wdiff,uint64_t hashes)

{
  _Bool _Var1;
  uint in_r2;
  int in_r3;
  uint64_t hashes_local;
  timeval *wdiff_local;
  work *work_local;
  
  if (((opt_scantime < wdiff->tv_sec) ||
      ((in_r3 != 0 || 0xfffffffc < in_r2) && (in_r3 != 0 || in_r2 != 0xfffffffd))) ||
     (_Var1 = stale_work(work,false), _Var1)) {
    _Var1 = true;
  }
  else {
    _Var1 = false;
  }
  return _Var1;
}

