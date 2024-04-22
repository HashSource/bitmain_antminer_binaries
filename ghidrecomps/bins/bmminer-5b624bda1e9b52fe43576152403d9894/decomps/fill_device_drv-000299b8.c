
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
    drv->drv_detect = DAT_00029ad4;
    p_Var1 = drv->reinit_device;
  }
  else {
    p_Var1 = drv->reinit_device;
  }
  if (p_Var1 == (_func_void_cgpu_info_ptr *)0x0) {
    drv->reinit_device = DAT_00029ad8;
    p_Var2 = drv->get_statline_before;
  }
  else {
    p_Var2 = drv->get_statline_before;
  }
  if (p_Var2 == (_func_void_char_ptr_size_t_cgpu_info_ptr *)0x0) {
    drv->get_statline_before = DAT_00029adc;
    p_Var2 = drv->get_statline;
  }
  else {
    p_Var2 = drv->get_statline;
  }
  if (p_Var2 == (_func_void_char_ptr_size_t_cgpu_info_ptr *)0x0) {
    drv->get_statline = DAT_00029ae0;
    p_Var3 = drv->get_stats;
  }
  else {
    p_Var3 = drv->get_stats;
  }
  if (p_Var3 == (_func__Bool_cgpu_info_ptr *)0x0) {
    drv->get_stats = DAT_00029ae4;
    p_Var4 = drv->thread_prepare;
  }
  else {
    p_Var4 = drv->thread_prepare;
  }
  if (p_Var4 == (_func__Bool_thr_info_ptr *)0x0) {
    drv->thread_prepare = DAT_00029ae8;
    p_Var4 = drv->thread_init;
  }
  else {
    p_Var4 = drv->thread_init;
  }
  if (p_Var4 == (_func__Bool_thr_info_ptr *)0x0) {
    drv->thread_init = DAT_00029aec;
    p_Var5 = drv->prepare_work;
  }
  else {
    p_Var5 = drv->prepare_work;
  }
  if (p_Var5 == (_func__Bool_thr_info_ptr_work_ptr *)0x0) {
    drv->prepare_work = DAT_00029af0;
    p_Var6 = drv->hw_error;
  }
  else {
    p_Var6 = drv->hw_error;
  }
  if (p_Var6 == (_func_void_thr_info_ptr *)0x0) {
    drv->hw_error = DAT_00029af4;
    p_Var6 = drv->thread_shutdown;
  }
  else {
    p_Var6 = drv->thread_shutdown;
  }
  if (p_Var6 == (_func_void_thr_info_ptr *)0x0) {
    drv->thread_shutdown = DAT_00029af8;
    p_Var6 = drv->thread_enable;
  }
  else {
    p_Var6 = drv->thread_enable;
  }
  if (p_Var6 == (_func_void_thr_info_ptr *)0x0) {
    drv->thread_enable = DAT_00029afc;
    p_Var6 = drv->hash_work;
  }
  else {
    p_Var6 = drv->hash_work;
  }
  if (p_Var6 == (_func_void_thr_info_ptr *)0x0) {
    drv->hash_work = DAT_00029b00;
    p_Var1 = drv->flush_work;
  }
  else {
    p_Var1 = drv->flush_work;
  }
  if (p_Var1 == (_func_void_cgpu_info_ptr *)0x0) {
    drv->flush_work = DAT_00029ad8;
    p_Var1 = drv->update_work;
  }
  else {
    p_Var1 = drv->update_work;
  }
  if (p_Var1 == (_func_void_cgpu_info_ptr *)0x0) {
    drv->update_work = DAT_00029ad8;
    p_Var3 = drv->queue_full;
  }
  else {
    p_Var3 = drv->queue_full;
  }
  if (p_Var3 == (_func__Bool_cgpu_info_ptr *)0x0) {
    drv->queue_full = DAT_00029ae4;
    p_Var1 = drv->zero_stats;
  }
  else {
    p_Var1 = drv->zero_stats;
  }
  if (p_Var1 == (_func_void_cgpu_info_ptr *)0x0) {
    drv->zero_stats = DAT_00029b04;
  }
  if (drv->max_diff == 0.0) {
    drv->max_diff = 1.0;
  }
  return;
}

