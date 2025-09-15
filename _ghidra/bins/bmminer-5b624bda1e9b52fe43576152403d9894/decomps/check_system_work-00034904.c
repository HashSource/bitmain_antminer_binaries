
/* WARNING: Unknown calling convention */

void * check_system_work(void)

{
  _Bool _Var1;
  uint64_t *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  all_parameters *paVar10;
  undefined4 uVar11;
  int (*local_960) [256];
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
  sprintf(logstr,"restartNum = %d , auto-reinit enabled...\n",2);
  writeInitLogFile(logstr);
  do {
    while (set_led(global_stop), doTestPatten != false) {
      cgsleep_ms(100);
    }
    cgtime(&tv_end);
    cgtime(&tv_reboot);
    iVar3 = tv_end.tv_sec - tv_start.tv_sec;
    if (tv_end.tv_usec - tv_start.tv_usec < 0) {
      iVar3 = iVar3 + -1;
    }
    if (iVar3 < 0x12d) {
      if ((0x3c < iVar3) || ((global_stop != false && (0x1e < iVar3)))) goto LAB_0003499e;
    }
    else {
      check_temp_offside = true;
LAB_0003499e:
      iVar9 = 0;
      local_950 = 0;
      local_954 = (all_parameters *)0x0;
      iVar3 = nonce_times;
      do {
        if (dev->chain_exist[(int)local_954] != 0) {
          iVar7 = (int)dev->chain_exist + (int)local_954 + -8;
          local_950 = local_950 + (uint)*(byte *)(iVar7 + 0x2faa);
          if (*(byte *)(iVar7 + 0x2faa) != 0) {
            iVar6 = 0;
            paVar10 = dev;
            do {
              uVar11 = *(undefined4 *)
                        ((int)paVar10->chain_asic_nonce[(int)local_954] + iVar6 * 8 + 4);
              *(int *)(nonce_num[(int)local_954][iVar6] + iVar3 % 0x3c) =
                   (int)paVar10->chain_asic_nonce[(int)local_954][iVar6];
              *(undefined4 *)((int)nonce_num[(int)local_954][iVar6] + (iVar3 % 0x3c) * 8 + 4) =
                   uVar11;
              iVar8 = (int)paVar10->chain_asic_nonce[(int)local_954][iVar6];
              iVar9 = iVar9 + iVar8;
              if ((opt_debug != false) &&
                 (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
                snprintf(tmp42,0x800,"%s: chain %d asic %d asic_nonce_num %d","check_system_work",
                         local_954,iVar6,iVar8,
                         *(undefined4 *)
                          ((int)paVar10->chain_asic_nonce[(int)local_954] + iVar6 * 8 + 4));
                _applog(7,tmp42,false);
                iVar7 = (int)dev->chain_exist + (int)local_954 + -8;
                iVar3 = nonce_times;
                paVar10 = dev;
              }
              iVar6 = iVar6 + 1;
            } while (iVar6 < (int)(uint)*(byte *)(iVar7 + 0x2faa));
          }
        }
        local_954 = (all_parameters *)((int)local_954 + 1);
      } while (local_954 != (all_parameters *)0x10);
      nonce_times = iVar3 + 1;
      memset(nonce_num10_string,0,0x1000);
      memset(nonce_num30_string,0,0x1000);
      memset(nonce_num60_string,0,0x1000);
      get_lastn_nonce_num(nonce_num10_string,10);
      get_lastn_nonce_num(nonce_num30_string,0x1e);
      get_lastn_nonce_num(nonce_num60_string,0x3c);
      if (((local_950 != 0) && (opt_debug != false)) &&
         ((use_syslog != false || ((opt_log_output != false || (6 < opt_log_level)))))) {
        snprintf(tmp42,0x800,"%s: avg_num %d asic_num %d","check_system_work",iVar9,local_950);
        _applog(7,tmp42,false);
      }
      paVar10 = dev;
      _Var1 = status_error;
      local_954 = dev;
      local_960 = x_time;
      local_958 = 0;
      iVar3 = nonce_times % 0x3c + -1;
      if (iVar3 < 0) {
        iVar3 = nonce_times % 0x3c + 0x3b;
      }
      do {
        if (local_954->chain_exist[0] != 0) {
          if (paVar10->chain_asic_num[local_958] == '\0') {
            local_950 = local_958 << 3;
            iVar9 = 0;
          }
          else {
            local_950 = local_958 * 8;
            iVar7 = 0;
            iVar9 = 0;
            puVar2 = nonce_num[local_958][0] + iVar3;
            uVar5 = 0;
            do {
              if ((uVar5 & 7) == 0) {
                paVar10->chain_asic_status_string[local_958][uVar5 + iVar9] = ' ';
                iVar9 = iVar9 + 1;
              }
              if ((int)*puVar2 < 2) {
                paVar10->chain_asic_status_string[local_958][uVar5 + iVar9] = 'o';
                if (_Var1 == false) {
                  *(int *)((int)*local_960 + iVar7) = *(int *)((int)*local_960 + iVar7) + 1;
                }
              }
              else {
                paVar10->chain_asic_status_string[local_958][uVar5 + iVar9] = 'o';
              }
              uVar4 = uVar5 + 1;
              iVar7 = iVar7 + 4;
              puVar2 = puVar2 + 0x3c;
              *(undefined2 *)(paVar10->chain_asic_nonce[local_958] + uVar5) = 0;
              *(undefined2 *)((int)paVar10->chain_asic_nonce[local_958] + uVar5 * 8 + 2) = 0;
              *(undefined2 *)((int)paVar10->chain_asic_nonce[local_958] + uVar5 * 8 + 4) = 0;
              *(undefined2 *)((int)paVar10->chain_asic_nonce[local_958] + uVar5 * 8 + 6) = 0;
              uVar5 = uVar4;
            } while ((int)uVar4 < (int)(uint)paVar10->chain_asic_num[local_958]);
            iVar9 = iVar9 + uVar4;
          }
          paVar10->chain_asic_status_string[0][iVar9 + (local_950 + local_958) * 8] = '\0';
        }
        local_958 = local_958 + 1;
        local_954 = (all_parameters *)&local_954->pwm_value;
        local_960 = local_960 + 1;
      } while (local_958 != 0x10);
      copy_time(&tv_start,&tv_end);
    }
    cgsleep_ms(1000);
  } while( true );
}

