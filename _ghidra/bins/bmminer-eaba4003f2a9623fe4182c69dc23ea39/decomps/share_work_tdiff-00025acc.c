
int share_work_tdiff(cgpu_info *cgpu)

{
  cgpu_info *cgpu_local;
  
  return last_getwork - cgpu->last_device_valid_work;
}

