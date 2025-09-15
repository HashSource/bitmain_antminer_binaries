
void fill_device_drv(device_drv *drv)

{
  device_drv *drv_local;
  
  if (drv->drv_detect == (_func_void__Bool *)0x0) {
    drv->drv_detect = (_func_void__Bool *)0x5bdd3;
  }
  if (drv->reinit_device == (_func_void_cgpu_info_ptr *)0x0) {
    drv->reinit_device = (_func_void_cgpu_info_ptr *)0x5bcf9;
  }
  if (drv->get_statline_before == (_func_void_char_ptr_size_t_cgpu_info_ptr *)0x0) {
    drv->get_statline_before = (_func_void_char_ptr_size_t_cgpu_info_ptr *)0x5bd0d;
  }
  if (drv->get_statline == (_func_void_char_ptr_size_t_cgpu_info_ptr *)0x0) {
    drv->get_statline = (_func_void_char_ptr_size_t_cgpu_info_ptr *)0x5bd25;
  }
  if (drv->get_stats == (_func__Bool_cgpu_info_ptr *)0x0) {
    drv->get_stats = (_func__Bool_cgpu_info_ptr *)0x5bd3d;
  }
  if (drv->thread_prepare == (_func__Bool_thr_info_ptr *)0x0) {
    drv->thread_prepare = (_func__Bool_thr_info_ptr *)0x5bd53;
  }
  if (drv->thread_init == (_func__Bool_thr_info_ptr *)0x0) {
    drv->thread_init = (_func__Bool_thr_info_ptr *)0x5bd69;
  }
  if (drv->prepare_work == (_func__Bool_thr_info_ptr_work_ptr *)0x0) {
    drv->prepare_work = (_func__Bool_thr_info_ptr_work_ptr *)0x5bd7f;
  }
  if (drv->hw_error == (_func_void_thr_info_ptr *)0x0) {
    drv->hw_error = (_func_void_thr_info_ptr *)0x5bd97;
  }
  if (drv->thread_shutdown == (_func_void_thr_info_ptr *)0x0) {
    drv->thread_shutdown = (_func_void_thr_info_ptr *)0x5bdab;
  }
  if (drv->thread_enable == (_func_void_thr_info_ptr *)0x0) {
    drv->thread_enable = (_func_void_thr_info_ptr *)0x5bdbf;
  }
  if (drv->hash_work == (_func_void_thr_info_ptr *)0x0) {
    drv->hash_work = (_func_void_thr_info_ptr *)0x5893b;
  }
  if (drv->flush_work == (_func_void_cgpu_info_ptr *)0x0) {
    drv->flush_work = (_func_void_cgpu_info_ptr *)0x5bcf9;
  }
  if (drv->update_work == (_func_void_cgpu_info_ptr *)0x0) {
    drv->update_work = (_func_void_cgpu_info_ptr *)0x5bcf9;
  }
  if (drv->queue_full == (_func__Bool_cgpu_info_ptr *)0x0) {
    drv->queue_full = (_func__Bool_cgpu_info_ptr *)0x5bd3d;
  }
  if (drv->zero_stats == (_func_void_cgpu_info_ptr *)0x0) {
    drv->zero_stats = (_func_void_cgpu_info_ptr *)0x5bde9;
  }
  if (drv->max_diff == 0.0) {
    *(undefined4 *)&drv->max_diff = 0;
    *(undefined4 *)((int)&drv->max_diff + 4) = 0x3ff00000;
  }
  return;
}

