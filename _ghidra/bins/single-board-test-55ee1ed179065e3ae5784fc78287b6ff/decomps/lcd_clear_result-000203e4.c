
void lcd_clear_result(void)

{
  int iVar1;
  
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)&ui_api_mutex);
  if (iVar1 == 0) {
    if (0 < lcd_ctx) {
      lcd_clear(lcd_ctx);
    }
    pthread_mutex_unlock((pthread_mutex_t *)&ui_api_mutex);
  }
  else {
    printf("%s:%d","lcd_clear_result",0x18c);
    puts("failed to api lock");
  }
  return;
}

