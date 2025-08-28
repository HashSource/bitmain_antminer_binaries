
void handle_asic_response(void)

{
  pthread_t __th;
  int iVar1;
  char acStack_15198 [1024];
  char acStack_14d98 [4];
  int iStack_14d94;
  undefined1 auStack_14d90 [4368];
  undefined1 auStack_13c80 [4072];
  char acStack_12c98 [1032];
  int iStack_12890;
  int iStack_1288c;
  char acStack_12888 [74400];
  char acStack_5e8 [1488];
  undefined4 local_18;
  byte local_11;
  int local_10;
  int local_c;
  
  memset(acStack_5e8,0,0x5d0);
  local_11 = 0;
  local_c = 0;
  __th = pthread_self();
  pthread_detach(__th);
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
    snprintf(acStack_15198,0x400,"Start A New Asic Response.Chain Id:[%d]\n",(uint)local_11);
    _applog(2,acStack_15198,0);
  }
  memset(acStack_12888,0,0x122a0);
  iStack_1288c = 0;
  iStack_12890 = 0;
  memset(acStack_12c98,0,0x406);
  local_18 = 0x122a0;
  do {
    do {
      while (start_recv != '\x01') {
        usleep(100000);
      }
      usleep(500);
      local_c = uart_receive(*(uint *)(g_chain + (uint)local_11 * 0x20) & 0xff,acStack_5e8,0x5d0);
      for (local_10 = 0; local_10 < local_c; local_10 = local_10 + 1) {
        acStack_12888[iStack_12890] = acStack_5e8[local_10];
        add_point(&iStack_12890,local_18);
      }
    } while (iStack_1288c == iStack_12890);
    if (iStack_1288c < iStack_12890) {
      iVar1 = -iStack_1288c;
    }
    else {
      iVar1 = 0x122a0 - iStack_1288c;
    }
    local_c = iStack_12890 + iVar1;
    while (2 < local_c) {
      iStack_14d94 = iStack_1288c;
      acStack_14d98[0] = '\0';
      acStack_14d98[1] = '\0';
      acStack_14d98[2] = 0;
      for (local_10 = 0; local_10 < 3; local_10 = local_10 + 1) {
        acStack_14d98[local_10] = acStack_12888[iStack_14d94];
        add_point(&iStack_14d94,local_18);
      }
      if ((acStack_14d98[0] == -0x56) && (acStack_14d98[1] == 'U')) {
        if ((acStack_14d98[2] & 0xf0U) == 0xe0) {
          if (local_c < 0x5d) break;
          for (local_10 = 0; local_10 < 0x5d; local_10 = local_10 + 1) {
            acStack_12c98[local_10] = acStack_12888[iStack_1288c];
            add_point(&iStack_1288c,local_18);
          }
          local_c = local_c + -0x5d;
          nonce_handle(auStack_13c80,auStack_14d90,acStack_12c98,0x5d,local_11);
        }
        else if (acStack_14d98[2] == 0xcc) {
          if (local_c < 9) break;
          for (local_10 = 0; local_10 < 9; local_10 = local_10 + 1) {
            acStack_12c98[local_10] = acStack_12888[iStack_1288c];
            add_point(&iStack_1288c,local_18);
          }
          local_c = local_c + -9;
          pm_handle(acStack_12c98,9,local_11);
        }
        else if (acStack_14d98[2] == 0xd0) {
          if (local_c < 0x406) break;
          for (local_10 = 0; local_10 < 0x406; local_10 = local_10 + 1) {
            acStack_12c98[local_10] = acStack_12888[iStack_1288c];
            add_point(&iStack_1288c,local_18);
          }
          local_c = local_c + -0x406;
          pt_handle(acStack_12c98,0x406,local_11);
        }
        else {
          if (local_c < 9) break;
          for (local_10 = 0; local_10 < 9; local_10 = local_10 + 1) {
            acStack_12c98[local_10] = acStack_12888[iStack_1288c];
            add_point(&iStack_1288c,local_18);
          }
          local_c = local_c + -9;
          reg_handle(acStack_12c98,9,local_11);
        }
      }
      else {
        add_point(&iStack_1288c,local_18);
        local_c = local_c + -1;
      }
    }
  } while( true );
}

