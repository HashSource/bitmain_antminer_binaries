
void singleBoardTest_V9_BM1385_45(void)

{
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined2 local_40;
  undefined local_3e;
  undefined4 local_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 local_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  local_14 = 0;
  local_18 = 0;
  local_1c = 0x1e240;
  local_2c = DAT_0002fdb4;
  uStack_28 = DAT_0002fdb8;
  uStack_24 = DAT_0002fdbc;
  uStack_20 = DAT_0002fdc0;
  local_3c = DAT_0002fdc4;
  uStack_38 = DAT_0002fdc8;
  uStack_34 = DAT_0002fdcc;
  uStack_30 = DAT_0002fdd0;
  local_40 = DAT_0002fdd4;
  local_3e = DAT_0002fdd6;
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  printf("\nBegin %s test\n","singleBoardTest_V9_BM1385_45",0,&local_40);
  system("date");
  putchar(10);
  memset(lcd_buffer + 0x20,0x20,0x40);
  if (0 < lcd_fd) {
    lseek(lcd_fd,0,0);
    write(lcd_fd,lcd_buffer + 0x20,0x40);
  }
  init_fpga();
  set_fpga_baud(0x1a);
  reset_V9_global_arg();
  check_chain();
  if (gChain == -1) {
    pthread_cancel(cgpu._65540_4_);
    pthread_cancel(cgpu._65544_4_);
    usleep(500000);
    write_lcd(1," no hash board  ",0x10);
    puts("\nNo hash board, please plug in it");
  }
  else {
    write_axi_fpga(0xd,0xffff);
    usleep(300000);
    reset_PIC16F1704_pic(gChain,gI2c);
    jump_from_loader_to_app_PIC16F1704(gChain,gI2c);
    read_PIC16F1705_iic_slave(gChain,gI2c,&local_40,3,&local_50);
  }
  return;
}

