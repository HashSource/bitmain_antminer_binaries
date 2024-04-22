
/* WARNING: Unknown calling convention */

void singleAsicTest_BM1385(void)

{
  pthread_t *ppVar1;
  int iVar2;
  uint uVar3;
  char lcd_display_buf [16];
  
  lcd_display_buf._8_4_ = DAT_00012320[2];
  lcd_display_buf._12_4_ = DAT_00012320[3];
  lcd_display_buf._0_4_ = *DAT_00012320;
  lcd_display_buf._4_4_ = DAT_00012320[1];
  printf("\nBegin %s test\n",DAT_00012320 + 4);
  system("date");
  putchar(10);
  memset(lcd_output,0x20,0x40);
  if (0 < lcd_fd) {
    lseek(lcd_fd,0,0);
    write(lcd_fd,lcd_output,0x40);
  }
  init_fpga();
  uVar3 = read_axi_fpga(0);
  write_axi_fpga(0,uVar3 | 0x20000000);
  reset_single_BM1385_global_arg();
  check_chain();
  iVar2 = DAT_0001232c;
  ppVar1 = DAT_00012324;
  if (gChain != 0xff) {
    pthread_create(DAT_00012324,(pthread_attr_t *)0x0,single_BM1385_show_status_func + 1,
                   chain_info + gChain);
    reset_hash_board();
    start_receive = true;
    pthread_create(ppVar1 + -1,(pthread_attr_t *)0x0,single_BM1385_receive_func + 1,
                   chain_info + gChain);
    puts("\n--- check asic number");
    check_BM1385_asic_reg(gChain,'\0','\0',true);
    printf("\n--- check chain: asicNum = %d\n",
           (uint)*(byte *)((int)ppVar1 + (int)gAsic_Core_Nonce_Num[0][0x4f] + gChain + 0x4c0));
    if (*(byte *)((int)ppVar1 + (int)gAsic_Core_Nonce_Num[0][0x4f] + gChain + 0x4c0) != Conf.AsicNum
       ) {
      pthread_cancel(ppVar1[-1]);
      pthread_cancel(*ppVar1);
      sprintf(lcd_display_buf + 7,"%d",
              (uint)*(byte *)((int)ppVar1 + (int)gAsic_Core_Nonce_Num[0][0x4f] + gChain + 0x4c0));
      write_lcd(0,"   Only have    ",0x10);
      write_lcd_no_memset(1,lcd_display_buf,0x10);
      write_lcd_no_memset(2,"      ASIC      ",0x10);
      printf("\n\n---%s: Only have %d ASIC\n",DAT_00012328,
             (uint)*(byte *)((int)ppVar1 + (int)gAsic_Core_Nonce_Num[0][0x4f] + gChain + 0x4c0));
      puts("----------------------------\n\n");
      return;
    }
    single_BM1385_calculate_timeout_and_baud();
    set_BM1385_freq(gChain,'\0',Conf.Freq,true);
    single_BM1385_set_address(gChain);
    check_BM1385_asic_reg(gChain,'\0','\0',true);
    single_BM1385_set_baud(gChain,(uchar)Conf.baud);
    single_BM1385_open_core(gChain);
    puts("\nBegin send test pattern");
    system("date");
    putchar(10);
    gStartTest = true;
    pthread_create(ppVar1 + -2,(pthread_attr_t *)0x0,single_BM1385_send_func + 1,chain_info + gChain
                  );
    pthread_join(ppVar1[-2],(void **)0x0);
    pthread_join(ppVar1[-1],(void **)0x0);
    pthread_cancel(*ppVar1);
    uVar3 = single_BM1385_get_result(gChain);
    single_BM1385_print_lcd(gChain,uVar3);
    set_fan_speed(0);
    usleep(500000);
    return;
  }
  write_lcd(1,"  no hash board ",0x10);
  pthread_cancel(*(pthread_t *)(iVar2 + 4));
  pthread_cancel(*(pthread_t *)(iVar2 + 8));
  puts("\nNo hash board, please plug in it");
  return;
}

