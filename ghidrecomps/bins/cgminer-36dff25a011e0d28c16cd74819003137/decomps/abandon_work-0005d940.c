
_Bool abandon_work(work *work,timeval *wdiff,uint64_t hashes)

{
  _Bool _Var1;
  uint64_t hashes_local;
  timeval *wdiff_local;
  work *work_local;
  
  if (wdiff->tv_sec <= opt_scantime) {
    hashes_local._0_4_ = (uint)hashes;
    hashes_local._4_4_ = (int)(hashes >> 0x20);
    if ((hashes_local._4_4_ == 0 && (uint)hashes_local < 0xfffffffe) &&
       (_Var1 = stale_work(work,false), !_Var1)) {
      return false;
    }
  }
  return true;
}

