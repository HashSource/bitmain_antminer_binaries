
void V9_show_status_func(byte *param_1)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  
  bVar1 = *param_1;
  bVar2 = param_1[1];
  time_counter = 0;
  do {
    memset(lcd_buffer + 0x20,0x20,0x40);
    uVar3 = read_temperature_through_fpga_iic_register(bVar1,bVar2);
    sprintf(lcd_buffer + 0x20,"   time %ds",time_counter);
    sprintf(DAT_00017e50,"   nonce=%d",*(undefined4 *)(gValid_Nonce_Num + (uint)bVar1 * 4));
    sprintf(DAT_00017e54,"   temp %d `C",uVar3);
    if (gHighest_Temp < uVar3) {
      gHighest_Temp = uVar3;
    }
    time_counter = time_counter + 1;
    write(lcd_fd,lcd_buffer + 0x20,0x40);
    if ((int)uVar3 < (int)Conf[224]) {
      if (gStartTest != '\x01') {
        printf("\nHash Board temperature is %d, waiting it raise to start temperature %d\n",uVar3,
               (int)Conf[224]);
      }
    }
    else {
      if (gStartTest != '\x01') {
        printf("\nBegin test!!! Hash Board temperature is %d\n",uVar3);
      }
      gStartTest = '\x01';
    }
    set_fan_speed(10);
    printf("\nChain%d get valid nonce number : %d. temperature is %d\n",(uint)bVar1,
           *(undefined4 *)(gValid_Nonce_Num + (uint)bVar1 * 4),uVar3);
    usleep(1000000);
  } while( true );
}

