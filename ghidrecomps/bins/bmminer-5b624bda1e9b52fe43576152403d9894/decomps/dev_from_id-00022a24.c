
/* WARNING: Unknown calling convention */

int dev_from_id(int thr_id)

{
  thr_info *ptVar1;
  thr_info *thr;
  
  ptVar1 = get_thread(thr_id);
  return ptVar1->cgpu->device_id;
}

