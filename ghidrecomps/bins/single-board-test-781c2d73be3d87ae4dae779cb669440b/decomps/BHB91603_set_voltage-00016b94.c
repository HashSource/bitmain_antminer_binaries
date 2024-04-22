
/* WARNING: Unknown calling convention */

int BHB91603_set_voltage(uchar which_chain,uchar which_i2c)

{
  pthread_t *ppVar1;
  int iVar2;
  
  iVar2 = Calibration_voltage(which_chain,which_i2c);
  ppVar1 = DAT_00016c8c;
  if (iVar2 != 0) {
    pthread_cancel(*DAT_00016c8c);
    pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
    pthread_cancel(ppVar1[1]);
    pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
    if (iVar2 == -1) {
      write_lcd(1,"  Can not find  ",0x10);
      write_lcd_no_memset(2,"  match voltage ",0x10);
      printf("\n!!! %s: Can\'t find match voltage!\n",DAT_00016c90);
      return -1;
    }
    if (iVar2 == -2) {
      write_lcd(0," Maximum N value",0x10);
      write_lcd_no_memset(1," can not match  ",0x10);
      write_lcd_no_memset(2,"    voltage     ",0x10);
      printf("\n!!! %s: Maximum N value can\'t match voltage!\n",DAT_00016c90);
      return -2;
    }
    if (iVar2 == -3) {
      write_lcd(0," Minimum N value",0x10);
      write_lcd_no_memset(1," can not match  ",0x10);
      write_lcd_no_memset(2,"    voltage     ",0x10);
      printf("\n!!! %s: Minimum N value can\'t match voltage!\n",DAT_00016c90);
      return -3;
    }
  }
  return iVar2;
}

