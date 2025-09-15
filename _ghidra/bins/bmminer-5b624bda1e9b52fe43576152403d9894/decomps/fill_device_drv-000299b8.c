
/* WARNING: Unknown calling convention */

void fill_device_drv(device_drv *drv)

{
  _func_void_cgpu_info_ptr *p_Var1;
  _func_void_char_ptr_size_t_cgpu_info_ptr *p_Var2;
  _func__Bool_cgpu_info_ptr *p_Var3;
  _func__Bool_thr_info_ptr *p_Var4;
  _func__Bool_thr_info_ptr_work_ptr *p_Var5;
  _func_void_thr_info_ptr *p_Var6;
  
  if (drv->drv_detect == (_func_void__Bool *)0x0) {
    drv->drv_detect = (_func_void__Bool *)0x1d919;
    p_Var1 = drv->reinit_device;
  }
  else {
    p_Var1 = drv->reinit_device;
  }
  if (p_Var1 == (_func_void_cgpu_info_ptr *)0x0) {
    drv->reinit_device = (_func_void_cgpu_info_ptr *)0x1d8e9;
    p_Var2 = drv->get_statline_before;
  }
  else {
    p_Var2 = drv->get_statline_before;
  }
  if (p_Var2 == (_func_void_char_ptr_size_t_cgpu_info_ptr *)0x0) {
    drv->get_statline_before = (_func_void_char_ptr_size_t_cgpu_info_ptr *)0x1d8ed;
    p_Var2 = drv->get_statline;
  }
  else {
    p_Var2 = drv->get_statline;
  }
  if (p_Var2 == (_func_void_char_ptr_size_t_cgpu_info_ptr *)0x0) {
    drv->get_statline = (_func_void_char_ptr_size_t_cgpu_info_ptr *)0x1d8f1;
    p_Var3 = drv->get_stats;
  }
  else {
    p_Var3 = drv->get_stats;
  }
  if (p_Var3 == (_func__Bool_cgpu_info_ptr *)0x0) {
    drv->get_stats = (_func__Bool_cgpu_info_ptr *)0x1d8f5;
    p_Var4 = drv->thread_prepare;
  }
  else {
    p_Var4 = drv->thread_prepare;
  }
  if (p_Var4 == (_func__Bool_thr_info_ptr *)0x0) {
    drv->thread_prepare = (_func__Bool_thr_info_ptr *)0x1d8f9;
    p_Var4 = drv->thread_init;
  }
  else {
    p_Var4 = drv->thread_init;
  }
  if (p_Var4 == (_func__Bool_thr_info_ptr *)0x0) {
    drv->thread_init = (_func__Bool_thr_info_ptr *)0x1d905;
    p_Var5 = drv->prepare_work;
  }
  else {
    p_Var5 = drv->prepare_work;
  }
  if (p_Var5 == (_func__Bool_thr_info_ptr_work_ptr *)0x0) {
    drv->prepare_work = (_func__Bool_thr_info_ptr_work_ptr *)0x1d909;
    p_Var6 = drv->hw_error;
  }
  else {
    p_Var6 = drv->hw_error;
  }
  if (p_Var6 == (_func_void_thr_info_ptr *)0x0) {
    drv->hw_error = (_func_void_thr_info_ptr *)0x1d90d;
    p_Var6 = drv->thread_shutdown;
  }
  else {
    p_Var6 = drv->thread_shutdown;
  }
  if (p_Var6 == (_func_void_thr_info_ptr *)0x0) {
    drv->thread_shutdown = (_func_void_thr_info_ptr *)0x1d911;
    p_Var6 = drv->thread_enable;
  }
  else {
    p_Var6 = drv->thread_enable;
  }
  if (p_Var6 == (_func_void_thr_info_ptr *)0x0) {
    drv->thread_enable = (_func_void_thr_info_ptr *)0x1d915;
    p_Var6 = drv->hash_work;
  }
  else {
    p_Var6 = drv->hash_work;
  }
  if (p_Var6 == (_func_void_thr_info_ptr *)0x0) {
    drv->hash_work = (_func_void_thr_info_ptr *)0x28e41;
    p_Var1 = drv->flush_work;
  }
  else {
    p_Var1 = drv->flush_work;
  }
  if (p_Var1 == (_func_void_cgpu_info_ptr *)0x0) {
    drv->flush_work = (_func_void_cgpu_info_ptr *)0x1d8e9;
    p_Var1 = drv->update_work;
  }
  else {
    p_Var1 = drv->update_work;
  }
  if (p_Var1 == (_func_void_cgpu_info_ptr *)0x0) {
    drv->update_work = (_func_void_cgpu_info_ptr *)0x1d8e9;
    p_Var3 = drv->queue_full;
  }
  else {
    p_Var3 = drv->queue_full;
  }
  if (p_Var3 == (_func__Bool_cgpu_info_ptr *)0x0) {
    drv->queue_full = (_func__Bool_cgpu_info_ptr *)0x1d8f5;
    p_Var1 = drv->zero_stats;
  }
  else {
    p_Var1 = drv->zero_stats;
  }
  if (p_Var1 == (_func_void_cgpu_info_ptr *)0x0) {
    drv->zero_stats = (_func_void_cgpu_info_ptr *)0x1d925;
  }
  if (drv->max_diff == 0.0) {
    drv->max_diff = 1.0;
  }
  return;
}

