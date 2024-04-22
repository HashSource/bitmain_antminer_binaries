
void fill_device_drv(device_drv *drv)

{
  device_drv *drv_local;
  
  if (drv->drv_detect == (_func_void__Bool *)0x0) {
    drv->drv_detect = noop_detect + 1;
  }
  if (drv->reinit_device == (_func_void_cgpu_info_ptr *)0x0) {
    drv->reinit_device = noop_reinit_device + 1;
  }
  if (drv->get_statline_before == (_func_void_char_ptr_size_t_cgpu_info_ptr *)0x0) {
    drv->get_statline_before = blank_get_statline_before + 1;
  }
  if (drv->get_statline == (_func_void_char_ptr_size_t_cgpu_info_ptr *)0x0) {
    drv->get_statline = noop_get_statline + 1;
  }
  if (drv->get_stats == (_func__Bool_cgpu_info_ptr *)0x0) {
    drv->get_stats = noop_get_stats + 1;
  }
  if (drv->thread_prepare == (_func__Bool_thr_info_ptr *)0x0) {
    drv->thread_prepare = noop_thread_prepare + 1;
  }
  if (drv->thread_init == (_func__Bool_thr_info_ptr *)0x0) {
    drv->thread_init = noop_thread_init + 1;
  }
  if (drv->prepare_work == (_func__Bool_thr_info_ptr_work_ptr *)0x0) {
    drv->prepare_work = noop_prepare_work + 1;
  }
  if (drv->hw_error == (_func_void_thr_info_ptr *)0x0) {
    drv->hw_error = noop_hw_error + 1;
  }
  if (drv->thread_shutdown == (_func_void_thr_info_ptr *)0x0) {
    drv->thread_shutdown = noop_thread_shutdown + 1;
  }
  if (drv->thread_enable == (_func_void_thr_info_ptr *)0x0) {
    drv->thread_enable = noop_thread_enable + 1;
  }
  if (drv->hash_work == (_func_void_thr_info_ptr *)0x0) {
    drv->hash_work = hash_sole_work + 1;
  }
  if (drv->flush_work == (_func_void_cgpu_info_ptr *)0x0) {
    drv->flush_work = noop_reinit_device + 1;
  }
  if (drv->update_work == (_func_void_cgpu_info_ptr *)0x0) {
    drv->update_work = noop_reinit_device + 1;
  }
  if (drv->queue_full == (_func__Bool_cgpu_info_ptr *)0x0) {
    drv->queue_full = noop_get_stats + 1;
  }
  if (drv->zero_stats == (_func_void_cgpu_info_ptr *)0x0) {
    drv->zero_stats = generic_zero_stats + 1;
  }
  if (drv->max_diff == 0.0) {
    *(undefined4 *)&drv->max_diff = 0;
    *(undefined4 *)((int)&drv->max_diff + 4) = 0x3ff00000;
  }
  return;
}

