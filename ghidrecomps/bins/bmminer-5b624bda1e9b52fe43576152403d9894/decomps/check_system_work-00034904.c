
/* WARNING: Unknown calling convention */

void * check_system_work(void)

{
  char *__format;
  undefined4 uVar1;
  _Bool _Var2;
  int *nonce;
  uint64_t *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  all_parameters *paVar11;
  undefined4 uVar12;
  int local_960;
  int local_958;
  all_parameters *local_954;
  int local_950;
  timeval tv_start;
  timeval tv_end;
  timeval tv_reboot;
  timeval tv_reboot_start;
  char logstr [256];
  char tmp42 [2048];
  
  cgtime(&tv_end);
  cgtime(&tv_reboot);
  copy_time(&tv_start,&tv_end);
  copy_time(&tv_reboot_start,&tv_reboot);
  sprintf(logstr,DAT_00034c3c,2);
  writeInitLogFile(logstr);
  do {
    while (set_led(global_stop), doTestPatten != false) {
      cgsleep_ms(100);
    }
    cgtime(&tv_end);
    cgtime(&tv_reboot);
    iVar4 = tv_end.tv_sec - tv_start.tv_sec;
    if (tv_end.tv_usec - tv_start.tv_usec < 0) {
      iVar4 = iVar4 + -1;
    }
    if (iVar4 < 0x12d) {
      if ((0x3c < iVar4) || ((global_stop != false && (0x1e < iVar4)))) goto LAB_0003499e;
    }
    else {
      check_temp_offside = true;
LAB_0003499e:
      iVar10 = 0;
      local_950 = 0;
      local_954 = (all_parameters *)0x0;
      iVar4 = nonce_times;
      do {
        if (dev->chain_exist[(int)local_954] != 0) {
          iVar8 = (int)dev->chain_exist + (int)local_954 + -8;
          local_950 = local_950 + (uint)*(byte *)(iVar8 + 0x2faa);
          if (*(byte *)(iVar8 + 0x2faa) != 0) {
            iVar7 = 0;
            paVar11 = dev;
            do {
              uVar1 = DAT_00034c44;
              __format = DAT_00034c40;
              uVar12 = *(undefined4 *)
                        ((int)paVar11->chain_asic_nonce[(int)local_954] + iVar7 * 8 + 4);
              *(undefined4 *)(nonce_num[(int)local_954][iVar7] + iVar4 % 0x3c) =
                   *(undefined4 *)(paVar11->chain_asic_nonce[(int)local_954] + iVar7);
              *(undefined4 *)((int)nonce_num[(int)local_954][iVar7] + (iVar4 % 0x3c) * 8 + 4) =
                   uVar12;
              iVar9 = *(int *)(paVar11->chain_asic_nonce[(int)local_954] + iVar7);
              iVar10 = iVar10 + iVar9;
              if ((opt_debug != false) &&
                 (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
                snprintf(tmp42,0x800,__format,uVar1,local_954,iVar7,iVar9,
                         *(undefined4 *)
                          ((int)paVar11->chain_asic_nonce[(int)local_954] + iVar7 * 8 + 4));
                _applog(7,tmp42,false);
                iVar8 = (int)dev->chain_exist + (int)local_954 + -8;
                iVar4 = nonce_times;
                paVar11 = dev;
              }
              iVar7 = iVar7 + 1;
            } while (iVar7 < (int)(uint)*(byte *)(iVar8 + 0x2faa));
          }
        }
        local_954 = (all_parameters *)((int)local_954 + 1);
      } while (local_954 != (all_parameters *)0x10);
      nonce_times = iVar4 + 1;
      memset(DAT_00034c48,0,0x1000);
      memset(DAT_00034c4c,0,0x1000);
      memset(DAT_00034c50,0,0x1000);
      get_lastn_nonce_num(DAT_00034c48,10);
      get_lastn_nonce_num(DAT_00034c4c,0x1e);
      get_lastn_nonce_num(DAT_00034c50,0x3c);
      if (((local_950 != 0) && (opt_debug != false)) &&
         ((use_syslog != false || ((opt_log_output != false || (6 < opt_log_level)))))) {
        snprintf(tmp42,0x800,DAT_00034c54,DAT_00034c44,iVar10,local_950);
        _applog(7,tmp42,false);
      }
      paVar11 = dev;
      _Var2 = status_error;
      local_954 = dev;
      local_960 = DAT_00034c58;
      local_958 = 0;
      iVar4 = nonce_times % 0x3c + -1;
      if (iVar4 < 0) {
        iVar4 = nonce_times % 0x3c + 0x3b;
      }
      do {
        if (local_954->chain_exist[0] != 0) {
          if (paVar11->chain_asic_num[local_958] == '\0') {
            local_950 = local_958 << 3;
            iVar10 = 0;
          }
          else {
            local_950 = local_958 * 8;
            iVar8 = 0;
            iVar10 = 0;
            puVar3 = nonce_num[local_958][0] + iVar4;
            uVar6 = 0;
            do {
              if ((uVar6 & 7) == 0) {
                paVar11->chain_asic_status_string[local_958][uVar6 + iVar10] = ' ';
                iVar10 = iVar10 + 1;
              }
              if (*(int *)puVar3 < 2) {
                paVar11->chain_asic_status_string[local_958][uVar6 + iVar10] = 'o';
                if (_Var2 == false) {
                  *(int *)(local_960 + iVar8) = *(int *)(local_960 + iVar8) + 1;
                }
              }
              else {
                paVar11->chain_asic_status_string[local_958][uVar6 + iVar10] = 'o';
              }
              uVar5 = uVar6 + 1;
              iVar8 = iVar8 + 4;
              puVar3 = puVar3 + 0x3c;
              *(undefined2 *)(paVar11->chain_asic_nonce[local_958] + uVar6) = 0;
              *(undefined2 *)((int)paVar11->chain_asic_nonce[local_958] + uVar6 * 8 + 2) = 0;
              *(undefined2 *)((int)paVar11->chain_asic_nonce[local_958] + uVar6 * 8 + 4) = 0;
              *(undefined2 *)((int)paVar11->chain_asic_nonce[local_958] + uVar6 * 8 + 6) = 0;
              uVar6 = uVar5;
            } while ((int)uVar5 < (int)(uint)paVar11->chain_asic_num[local_958]);
            iVar10 = iVar10 + uVar5;
          }
          paVar11->chain_asic_status_string[0][iVar10 + (local_950 + local_958) * 8] = '\0';
        }
        local_958 = local_958 + 1;
        local_954 = (all_parameters *)&local_954->pwm_value;
        local_960 = local_960 + 0x400;
      } while (local_958 != 0x10);
      copy_time(&tv_start,&tv_end);
    }
    cgsleep_ms(1000);
  } while( true );
}

