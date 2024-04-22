
void null_device_drv(device_drv *drv)

{
  device_drv *drv_local;
  
  drv->drv_detect = noop_detect + 1;
  drv->reinit_device = noop_reinit_device + 1;
  drv->get_statline_before = blank_get_statline_before + 1;
  drv->get_statline = noop_get_statline + 1;
  drv->get_api_stats = noop_get_api_stats + 1;
  drv->get_stats = noop_get_stats + 1;
  drv->identify_device = noop_reinit_device + 1;
  drv->set_device = (_func_char_ptr_cgpu_info_ptr_char_ptr_char_ptr_char_ptr *)0x0;
  drv->thread_prepare = noop_thread_prepare + 1;
  drv->can_limit_work = noop_can_limit_work + 1;
  drv->thread_init = noop_thread_init + 1;
  drv->prepare_work = noop_prepare_work + 1;
  drv->hash_work = noop_hash_work + 1;
  drv->hw_error = noop_hw_error + 1;
  drv->thread_shutdown = noop_thread_shutdown + 1;
  drv->thread_enable = noop_thread_enable + 1;
  drv->zero_stats = generic_zero_stats + 1;
  drv->hash_work = noop_hash_work + 1;
  drv->queue_full = noop_get_stats + 1;
  drv->flush_work = noop_reinit_device + 1;
  drv->update_work = noop_reinit_device + 1;
  *(undefined4 *)&drv->max_diff = 0;
  *(undefined4 *)((int)&drv->max_diff + 4) = 0x3ff00000;
  *(undefined4 *)&drv->min_diff = 0;
  *(undefined4 *)((int)&drv->min_diff + 4) = 0x3ff00000;
  return;
}

