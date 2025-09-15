
void enable_device(cgpu_info *cgpu)

{
  cgpu_info **ppcVar1;
  cgpu_info *cgpu_local;
  
  cgpu->deven = DEV_ENABLED;
  _wr_lock(&devices_lock,"cgminer.c","enable_device",0x2b58);
  ppcVar1 = devices;
  cgpu->cgminer_id = cgminer_id_count;
  ppcVar1[cgpu->cgminer_id] = cgpu;
  cgminer_id_count = cgminer_id_count + 1;
  _wr_unlock(&devices_lock,"cgminer.c","enable_device",0x2b5a);
  if (hotplug_mode == false) {
    mining_threads = cgpu->threads + mining_threads;
  }
  else {
    new_threads = cgpu->threads + new_threads;
  }
  _rwlock_init(&cgpu->qlock,"cgminer.c","enable_device",0x2b65);
  cgpu->queued_work = (work *)0x0;
  return;
}

