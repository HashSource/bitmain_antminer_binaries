
/* WARNING: Unknown calling convention */

int32_t lcd_show_result(int32_t line,int8_t *data,uint32_t size)

{
  int iVar1;
  int32_t iVar2;
  char tmp42 [2048];
  
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)&ui_api_mutex);
  if (iVar1 == 0) {
    if (lcd_ctx < 0) {
      lcd_ctx = lcd_init(lcd_path);
      lcd_clear(lcd_ctx);
    }
    if (lcd_ctx < 1) {
      iVar2 = -1;
      snprintf(tmp42,0x800,"failed to init %s\n",lcd_path);
      _applog(0,tmp42,false);
    }
    else {
      iVar2 = lcd_write(lcd_ctx,(int8_t)line,data,size);
    }
    pthread_mutex_unlock((pthread_mutex_t *)&ui_api_mutex);
  }
  else {
    builtin_strncpy(tmp42,"failed to api lock\n",0x14);
    _applog(0,tmp42,false);
    iVar2 = -4;
  }
  return iVar2;
}

