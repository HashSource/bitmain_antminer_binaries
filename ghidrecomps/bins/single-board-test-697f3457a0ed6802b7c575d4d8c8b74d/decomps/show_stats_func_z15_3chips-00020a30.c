
/* WARNING: Unknown calling convention */

void * show_stats_func_z15_3chips(void)

{
  size_t sVar1;
  char str [16];
  int len;
  int time_counter;
  
  time_counter = 0;
  do {
    memset(lcd_output,0x20,0x40);
    sprintf(lcd_output[0],"time %ds",time_counter);
    str[0] = '\0';
    str[1] = '\0';
    str[2] = '\0';
    str[3] = '\0';
    str[4] = '\0';
    str[5] = '\0';
    str[6] = '\0';
    str[7] = '\0';
    str[8] = '\0';
    str[9] = '\0';
    str[10] = '\0';
    str[0xb] = '\0';
    str[0xc] = '\0';
    str[0xd] = '\0';
    str[0xe] = '\0';
    str[0xf] = '\0';
    sprintf(str,"nonce=%d %d %d",*g_patten.asic_recv_nonces,g_patten.asic_recv_nonces[1],
            g_patten.asic_recv_nonces[2]);
    sVar1 = strlen(str);
    memset(str + sVar1,0x20,0x10 - sVar1);
    lcd_output[1][0] = str[0];
    lcd_output[1][1] = str[1];
    lcd_output[1][2] = str[2];
    lcd_output[1][3] = str[3];
    lcd_output[1][4] = str[4];
    lcd_output[1][5] = str[5];
    lcd_output[1][6] = str[6];
    lcd_output[1][7] = str[7];
    lcd_output[1][8] = str[8];
    lcd_output[1][9] = str[9];
    lcd_output[1][10] = str[10];
    lcd_output[1][0xb] = str[0xb];
    lcd_output[1][0xc] = str[0xc];
    lcd_output[1][0xd] = str[0xd];
    lcd_output[1][0xe] = str[0xe];
    lcd_output[1][0xf] = str[0xf];
    sprintf(lcd_output[2],"chip: %d\'C      ",(uint)chip_high);
    sprintf(lcd_output[3],"pcb : %d\'C      ",(uint)pcb_high);
    time_counter = time_counter + 1;
    write(cgpu.lcd_fd,lcd_output,0x40);
    usleep(1000000);
  } while( true );
}

