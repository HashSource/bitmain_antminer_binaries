
/* WARNING: Unknown calling convention */

void null_device_drv(device_drv *drv)

{
  drv->drv_detect = (_func_void__Bool *)0x1d919;
  drv->hw_error = (_func_void_thr_info_ptr *)0x1d90d;
  drv->thread_shutdown = (_func_void_thr_info_ptr *)0x1d911;
  drv->zero_stats = (_func_void_cgpu_info_ptr *)0x1d925;
  drv->hash_work = (_func_void_thr_info_ptr *)0x1d921;
  drv->thread_enable = (_func_void_thr_info_ptr *)0x1d915;
  drv->get_statline_before = (_func_void_char_ptr_size_t_cgpu_info_ptr *)0x1d8ed;
  drv->get_statline = (_func_void_char_ptr_size_t_cgpu_info_ptr *)0x1d8f1;
  drv->get_api_stats = (_func_api_data_ptr_cgpu_info_ptr *)0x1d91d;
  drv->thread_prepare = (_func__Bool_thr_info_ptr *)0x1d8f9;
  drv->can_limit_work = (_func_uint_thr_info_ptr *)0x1d8fd;
  drv->thread_init = (_func__Bool_thr_info_ptr *)0x1d905;
  drv->prepare_work = (_func__Bool_thr_info_ptr_work_ptr *)0x1d909;
  drv->set_device = (_func_char_ptr_cgpu_info_ptr_char_ptr_char_ptr_char_ptr *)0x0;
  drv->reinit_device = (_func_void_cgpu_info_ptr *)0x1d8e9;
  drv->identify_device = (_func_void_cgpu_info_ptr *)0x1d8e9;
  drv->flush_work = (_func_void_cgpu_info_ptr *)0x1d8e9;
  drv->update_work = (_func_void_cgpu_info_ptr *)0x1d8e9;
  drv->get_stats = (_func__Bool_cgpu_info_ptr *)0x1d8f5;
  drv->queue_full = (_func__Bool_cgpu_info_ptr *)0x1d8f5;
  *(undefined4 *)&drv->max_diff = 0;
  *(undefined4 *)((int)&drv->max_diff + 4) = 0x3ff00000;
  *(undefined4 *)&drv->min_diff = 0;
  *(undefined4 *)((int)&drv->min_diff + 4) = 0x3ff00000;
  return;
}

