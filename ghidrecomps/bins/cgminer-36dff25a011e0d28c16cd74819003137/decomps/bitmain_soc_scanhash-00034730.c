
int64_t bitmain_soc_scanhash(thr_info *thr)

{
  thr_info *thr_local;
  
  h._0_4_ = 0;
  h._4_4_ = 0;
  bitmain_scanhash(thr);
  return CONCAT44(h._4_4_,(undefined4)h);
}

