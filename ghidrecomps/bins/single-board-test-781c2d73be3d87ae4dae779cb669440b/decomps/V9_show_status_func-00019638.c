
/* WARNING: Unknown calling convention */

void * V9_show_status_func(void *arg)

{
  byte bVar1;
  byte which_chain_00;
  byte bVar2;
  chain_info *chain_info;
  int temp;
  uchar which_chain;
  uint uVar4;
  uchar which_i2c;
  uint uVar3;
  
  bVar1 = *(byte *)((int)arg + 1);
                    /* WARNING: Load size is inaccurate */
  which_chain_00 = *arg;
  uVar4 = (uint)which_chain_00;
  time_counter = 0;
  do {
    memset(lcd_output,0x20,0x40);
    bVar2 = read_temperature_through_fpga_iic_register(which_chain_00,(uint)bVar1);
    uVar3 = (uint)bVar2;
    sprintf(lcd_output[0],"   time %ds",time_counter);
    sprintf(DAT_00019750,"   nonce=%d",gValid_Nonce_Num[uVar4]);
    sprintf(DAT_00019754,"   temp %d `C",uVar3);
    if (gHighest_Temp < uVar3) {
      gHighest_Temp = uVar3;
    }
    time_counter = time_counter + 1;
    write(lcd_fd,lcd_output,0x40);
    if ((int)uVar3 < Conf.StartTemp) {
      if (gStartTest == false) {
        printf("\nHash Board temperature is %d, waiting it raise to start temperature %d\n",uVar3);
      }
    }
    else {
      if (gStartTest == false) {
        printf("\nBegin test!!! Hash Board temperature is %d\n",uVar3);
      }
      gStartTest = true;
    }
    set_fan_speed(0);
    printf("\nChain%d get valid nonce number : %d. temperature is %d\n",uVar4,
           gValid_Nonce_Num[uVar4],uVar3);
    usleep(1000000);
  } while( true );
}

