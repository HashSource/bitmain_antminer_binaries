
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void lcd_clear_result(void)

{
  int iVar1;
  char tmp42 [2048];
  
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)&ui_api_mutex);
  if (iVar1 == 0) {
    if (0 < lcd_ctx) {
      lcd_clear(lcd_ctx);
    }
    pthread_mutex_unlock((pthread_mutex_t *)&ui_api_mutex);
    return;
  }
  builtin_strncpy(tmp42,"failed to api lock\n",0x14);
  _applog(0,tmp42,false);
  return;
}

