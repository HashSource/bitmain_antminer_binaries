
/* WARNING: Unknown calling convention */
/* Local variable chain_info:chain_info *[r0:4] conflicts with parameter, skipped. */

void * single_BM1385_show_status_func(void *arg)

{
  byte bVar1;
  uint uVar2;
  uchar which_chain;
  
                    /* WARNING: Load size is inaccurate */
  bVar1 = *arg;
  time_counter = 0;
  do {
    uVar2 = time_counter;
    memset(lcd_output,0x20,0x40);
    sprintf(DAT_00010dfc,"   time %ds",uVar2);
    sprintf(DAT_00010e00,"   nonce=%d",gValid_Nonce_Num[bVar1]);
    time_counter = time_counter + 1;
    write(lcd_fd,lcd_output,0x40);
    set_fan_speed(10);
    usleep(1000000);
  } while( true );
}

