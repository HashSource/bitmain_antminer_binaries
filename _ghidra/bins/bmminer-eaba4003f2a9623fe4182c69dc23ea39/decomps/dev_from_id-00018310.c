
int dev_from_id(int thr_id)

{
  cgpu_info *pcVar1;
  int thr_id_local;
  cgpu_info *cgpu;
  
  pcVar1 = get_thr_cgpu(thr_id);
  return pcVar1->device_id;
}

