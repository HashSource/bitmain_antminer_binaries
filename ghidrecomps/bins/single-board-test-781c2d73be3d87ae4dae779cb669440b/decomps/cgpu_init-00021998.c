
/* WARNING: Unknown calling convention */

int cgpu_init(void)

{
  int iVar1;
  
  printf("\n--- %s\n","cgpu_init");
  memset(&cgpu,0,0x100330);
  memset(&Conf,0,0x17c);
  iVar1 = open_lcd();
  if (iVar1 < 1) {
    printf("!!! %s: open lcd driver error\n","cgpu_init");
  }
  else {
    memset(lcd_output,0x20,0x40);
    write(lcd_fd,lcd_output,0x40);
    iVar1 = open_key();
    if (iVar1 < 1) {
      printf("!!! %s: open start key error\n","cgpu_init");
    }
    else {
      iVar1 = open_red_led();
      if (iVar1 < 1) {
        printf("!!! %s: open red led error\n","cgpu_init");
      }
      else {
        iVar1 = open_green_led();
        if (iVar1 < 1) {
          printf("!!! %s: open green led error\n","cgpu_init");
        }
        else {
          iVar1 = bitmain_axi_init();
          if (iVar1 < 0) {
            bitmain_axi_close();
          }
          else {
            iVar1 = open_power_control();
            if (0 < iVar1) {
              return 0;
            }
            printf("!!! %s: open power control gpio error\n","cgpu_init");
          }
          close_power_control();
        }
        close_green_led();
      }
      close_red_led();
    }
    close_key();
  }
  close_lcd();
  return -1;
}

