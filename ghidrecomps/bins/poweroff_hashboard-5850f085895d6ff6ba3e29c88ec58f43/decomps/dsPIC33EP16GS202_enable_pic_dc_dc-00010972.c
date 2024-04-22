
undefined4 dsPIC33EP16GS202_enable_pic_dc_dc(byte param_1,byte param_2)

{
  undefined local_14;
  byte local_13;
  byte local_10;
  byte local_f;
  int local_c;
  
  local_c = 0;
  local_14 = 0x15;
  local_13 = param_2;
  while( true ) {
    local_c = local_c + 1;
    send_pic_cmd(param_1,&local_14,2,&local_10,2);
    if ((local_10 == 0x15) && (local_f == 1)) break;
    if (2 < local_c) {
      printf("ERROR! failed on chain[%d] after %d times try!\n",(uint)param_1,local_c);
      printf("DEBUG! 0x%08x, 0x%08x\n",(uint)local_10,(uint)local_f);
      return 0xffffffff;
    }
    sleep(1);
  }
  printf("set chain[%d] dc power to [%d] ok!\n",(uint)param_1,(uint)param_2);
  return 0;
}

