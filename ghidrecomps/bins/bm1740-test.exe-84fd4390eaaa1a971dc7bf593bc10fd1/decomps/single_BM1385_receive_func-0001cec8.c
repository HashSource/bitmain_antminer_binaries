
undefined4 single_BM1385_receive_func(byte *param_1)

{
  int iVar1;
  undefined4 local_61c;
  undefined local_618;
  undefined auStack_614 [500];
  undefined auStack_420 [1000];
  int local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  byte local_26;
  byte local_25;
  byte *local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  int local_14;
  uint local_10;
  uint local_c;
  
  local_25 = *param_1;
  local_26 = param_1[1];
  local_24 = param_1;
  memset(auStack_420,0,1000);
  memset(auStack_614,0,500);
  local_61c = 0;
  local_618 = 0;
  local_2c = 0;
  local_c = 0;
  local_10 = 0;
  local_14 = 0;
  local_30 = 0;
  local_34 = 0;
  local_18 = 0;
  local_1c = 0;
  local_20 = 0;
  local_38 = 0;
  printf("%s: which_chain = %d, which_i2c = %d\n","single_BM1385_receive_func",(uint)local_25,
         (uint)local_26);
  clear_uart_rx_fifo(local_25);
LAB_0001d1a0:
  do {
    if (start_receive == '\0') {
      return 0;
    }
    usleep(5000);
    local_18 = 0;
    while( true ) {
      if (4999999 < local_18) goto LAB_0001d1a0;
      memset(auStack_420,0,1000);
      local_2c = uart_receive(local_25,auStack_420,1000);
      if ((local_2c != 0) && (local_c < 3)) break;
      local_18 = local_18 + 1;
    }
    for (local_1c = 0; local_1c < local_2c; local_1c = local_1c + 1) {
      auStack_614[local_10] = auStack_420[local_1c];
      local_10 = local_10 + 1;
    }
    if (4 < local_10) {
      local_30 = local_10 / 5;
      for (local_1c = 0; local_1c < local_30; local_1c = local_1c + 1) {
        memset(&local_61c,0,5);
        for (local_20 = 0; local_20 < 5; local_20 = local_20 + 1) {
          *(undefined *)((int)&local_61c + local_20) = auStack_614[local_14];
          local_14 = local_14 + 1;
        }
        iVar1 = BM1385_is_nonce_or_reg_value(local_618);
        if (iVar1 == 0) {
          local_38 = single_BM1385_check_register_value(local_25,&local_61c);
          if (local_38 == -1) {
            local_c = local_c + 1;
          }
        }
        else if ((gStartTest != '\0') && (gIsOpenCoreEnd != '\0')) {
          local_38 = single_BM1385_check_nonce(local_25,&local_61c);
          if (local_38 == -1) {
            local_c = local_c + 1;
          }
        }
      }
      local_34 = local_10 - local_14;
      for (local_20 = 0; local_20 < local_34; local_20 = local_20 + 1) {
        auStack_614[local_20] = auStack_614[local_14];
        local_14 = local_14 + 1;
      }
      local_10 = local_34;
      local_14 = 0;
      local_30 = 0;
    }
  } while( true );
}

