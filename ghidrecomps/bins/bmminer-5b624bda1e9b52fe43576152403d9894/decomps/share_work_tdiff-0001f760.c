
/* WARNING: Unknown calling convention */

int share_work_tdiff(cgpu_info *cgpu)

{
  return last_getwork - cgpu->last_device_valid_work;
}

