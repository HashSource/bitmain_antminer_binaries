
/* WARNING: Unknown calling convention */

int64_t bitmain_c5_scanhash(thr_info *thr)

{
  pthread_t send_id;
  
  h._0_4_ = 0;
  h._4_4_ = 0;
  pthread_create(&send_id,(pthread_attr_t *)0x0,bitmain_scanhash + 1,thr);
  pthread_join(send_id,(void **)0x0);
  return CONCAT44(h._4_4_,(undefined4)h);
}

