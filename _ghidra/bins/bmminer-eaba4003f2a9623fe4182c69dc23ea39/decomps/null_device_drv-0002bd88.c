
void null_device_drv(device_drv *drv)

{
  device_drv *drv_local;
  
  drv->drv_detect = (_func_void__Bool *)0x2bba1;
  drv->reinit_device = (_func_void_cgpu_info_ptr *)0x2baa1;
  drv->get_statline_before = (_func_void_char_ptr_size_t_cgpu_info_ptr *)0x2bab5;
  drv->get_statline = (_func_void_char_ptr_size_t_cgpu_info_ptr *)0x2bacd;
  drv->get_api_stats = (_func_api_data_ptr_cgpu_info_ptr *)0x2bbb5;
  drv->get_stats = (_func__Bool_cgpu_info_ptr *)0x2bae5;
  drv->identify_device = (_func_void_cgpu_info_ptr *)0x2baa1;
  drv->set_device = (_func_char_ptr_cgpu_info_ptr_char_ptr_char_ptr_char_ptr *)0x0;
  drv->thread_prepare = (_func__Bool_thr_info_ptr *)0x2bafd;
  drv->can_limit_work = (_func_uint_thr_info_ptr *)0x2bb15;
  drv->thread_init = (_func__Bool_thr_info_ptr *)0x2bb35;
  drv->prepare_work = (_func__Bool_thr_info_ptr_work_ptr *)0x2bb4d;
  drv->hash_work = (_func_void_thr_info_ptr *)0x2bbcd;
  drv->hw_error = (_func_void_thr_info_ptr *)0x2bb65;
  drv->thread_shutdown = (_func_void_thr_info_ptr *)0x2bb79;
  drv->thread_enable = (_func_void_thr_info_ptr *)0x2bb8d;
  drv->zero_stats = (_func_void_cgpu_info_ptr *)0x2bbe1;
  drv->hash_work = (_func_void_thr_info_ptr *)0x2bbcd;
  drv->queue_full = (_func__Bool_cgpu_info_ptr *)0x2bae5;
  drv->flush_work = (_func_void_cgpu_info_ptr *)0x2baa1;
  drv->update_work = (_func_void_cgpu_info_ptr *)0x2baa1;
  *(undefined4 *)&drv->max_diff = 0;
  *(undefined4 *)((int)&drv->max_diff + 4) = 0x3ff00000;
  *(undefined4 *)&drv->min_diff = 0;
  *(undefined4 *)((int)&drv->min_diff + 4) = 0x3ff00000;
  return;
}

