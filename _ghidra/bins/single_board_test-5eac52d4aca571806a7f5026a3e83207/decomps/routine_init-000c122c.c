
/* WARNING: Unknown calling convention */

int32_t routine_init(void)

{
  int iVar1;
  pthread_attr_t tattr_ctrl;
  
  pthread_mutex_init((pthread_mutex_t *)&ui_api_mutex,(pthread_mutexattr_t *)0x0);
  ui_callback[0] = (_func_void_ui_type_e_bitmain_key_status_e *)0x0;
  ui_callback[1] = (_func_void_ui_type_e_bitmain_key_status_e *)0x0;
  ui_callback[2] = (_func_void_ui_type_e_bitmain_key_status_e *)0x0;
  ui_callback[3] = (_func_void_ui_type_e_bitmain_key_status_e *)0x0;
  ui_callback[4] = (_func_void_ui_type_e_bitmain_key_status_e *)0x0;
  ui_flicker_map = new_c_map((clib_compare)0xc1075,(clib_destroy)0x0,(clib_destroy)0x0);
  pthread_attr_init((pthread_attr_t *)&tattr_ctrl);
  pthread_attr_setstacksize((pthread_attr_t *)&tattr_ctrl,0x200000);
  iVar1 = pthread_create(&ui_thread,(pthread_attr_t *)&tattr_ctrl,(__start_routine *)0xc10a5,
                         (void *)0x0);
  ui_pull_thread = 1;
  return iVar1;
}

