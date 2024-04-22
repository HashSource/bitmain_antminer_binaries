
/* WARNING: Unknown calling convention */

void scanfreq_init_pic(void)

{
  uchar which_iic;
  int i;
  
  for (i = 0; i < 0x10; i = i + 1) {
    if (dev->chain_exist[i] == 1) {
      pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
      which_iic = (uchar)i;
      dsPIC33EP16GS202_reset_pic(which_iic);
      pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
      cgsleep_ms(100);
      pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
      dsPIC33EP16GS202_jump_to_app_from_loader(which_iic);
      pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
      cgsleep_ms(100);
      pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
      dsPIC33EP16GS202_enable_pic_dc_dc(which_iic,'\0');
      pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
    }
  }
  return;
}

