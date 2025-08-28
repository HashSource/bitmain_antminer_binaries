
void check_system_work(void)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  char cVar5;
  int iVar6;
  FILE *pFVar7;
  byte bVar8;
  byte bVar9;
  int iVar10;
  int *piVar11;
  uint uVar12;
  undefined1 *__nptr;
  int iVar13;
  int *piVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  undefined4 uVar19;
  bool bVar20;
  double dVar21;
  undefined4 extraout_s1;
  double dVar22;
  int local_8dc;
  int *local_8c8;
  int *local_8c4;
  byte *local_8c0;
  uint local_8bc;
  int local_8a8;
  uint local_894;
  uint local_88c;
  int local_888;
  undefined4 local_870;
  int local_868;
  int local_864;
  int local_860;
  int local_85c;
  undefined1 auStack_858 [8];
  undefined1 auStack_850 [8];
  char acStack_848 [2052];
  
  cgtime(&local_860);
  cgtime(auStack_858);
  copy_time(&local_868,&local_860);
  copy_time(auStack_850,auStack_858);
  iVar6 = readRestartNum();
  if ((0 < iVar6) && (3 < log_level)) {
    pFVar7 = fopen(log_file,"a+");
    if (pFVar7 != (FILE *)0x0) {
      fprintf(pFVar7,"%s:%d:%s: restartNum = %d , auto-reinit enabled...\n","driver-btm-c5.c",0x2862
              ,"check_system_work",iVar6);
    }
    fclose(pFVar7);
  }
  local_88c = 0;
  bVar9 = 0;
  local_870 = 0;
  local_894 = 0;
  local_888 = 0;
  bVar1 = false;
  bVar2 = false;
  bVar3 = false;
  bVar4 = false;
  local_8bc = 1;
  do {
    while (set_led(global_stop), doTestPatten != '\0') {
      cgsleep_ms(100);
    }
    if (((local_8bc == (local_8bc / 0x1e) * 0x1e) && (!bVar1)) && (global_stop == 0)) {
      if (bVar9 < 10) {
        bVar9 = bVar9 + 1;
      }
      else {
        dVar22 = 0.0;
        __nptr = displayed_rate;
        iVar6 = 0;
        do {
          while ((iVar10 = iVar6 + 2, iVar6 = iVar6 + 1, *(int *)(dev + iVar10 * 4) == 1 &&
                 (*__nptr != '\0'))) {
            dVar21 = strtod(__nptr,(char **)0x0);
            dVar22 = dVar22 + dVar21;
            __nptr = __nptr + 0x20;
            if (iVar6 == 0x10) goto LAB_0003beac;
          }
          __nptr = __nptr + 0x20;
        } while (iVar6 != 0x10);
LAB_0003beac:
        iVar6 = (uint)(dVar22 < (double)(longlong)ideal_total_hash_rate * 0.92) << 0x1f;
        if (-1 < iVar6) {
          local_894 = 0;
        }
        if (iVar6 < 0) {
          local_894 = local_894 + 1;
          if (local_894 == (local_894 / 3) * 3) {
            local_888 = local_888 + 1;
            if (3 < log_level) {
              pFVar7 = fopen(log_file,"a+");
              if (pFVar7 != (FILE *)0x0) {
                fprintf(pFVar7,
                        "%s:%d:%s: re_open_core_times: %d, total_rate:%f, ideal_total_hash_rate:%d\n"
                        ,"driver-btm-c5.c",0x288c,"check_system_work",local_888,dVar22,
                        ideal_total_hash_rate);
              }
              fclose(pFVar7);
            }
            bVar9 = 0;
            re_open_core(local_870);
          }
          bVar1 = 0x3c < local_894;
        }
      }
    }
    if (local_8bc == 0x78) {
      if (opt_fixed_freq == '\0') {
        iVar6 = if_avg_hash_ok();
        if (iVar6 == 0) {
          if (1 < log_level) {
            pFVar7 = fopen(log_file,"a+");
            if (pFVar7 != (FILE *)0x0) {
              fprintf(pFVar7,"%s:%d:%s: hash rate is low...\n","driver-btm-c5.c",0x28a4,
                      "check_system_work");
            }
            fclose(pFVar7);
          }
          if (bring_up_pcb_temp < 0x23) {
            local_88c = local_88c + 1;
            re_open_core();
            if (3 < log_level) {
              pFVar7 = fopen(log_file,"a+");
              if (pFVar7 != (FILE *)0x0) {
                fprintf(pFVar7,"%s:%d:%s: re-open core %d times\n","driver-btm-c5.c",0x28b1,
                        "check_system_work",local_88c);
              }
              fclose(pFVar7);
            }
            bVar3 = false;
            local_870 = 1;
            is_working_in_low_temperature = 1;
            goto LAB_0003bf7a;
          }
        }
        else if (3 < log_level) {
          pFVar7 = fopen(log_file,"a+");
          if (pFVar7 != (FILE *)0x0) {
            fprintf(pFVar7,"%s:%d:%s: hash rate is ok now\n","driver-btm-c5.c",0x289f,
                    "check_system_work");
          }
          goto LAB_0003c3a0;
        }
        bVar4 = true;
      }
LAB_0003bf7a:
      uVar15 = local_8bc % 10;
    }
    else {
      if ((local_8bc - 0xb4 < 0x654) && (local_8bc + ((local_8bc >> 2) / 0x2d) * -0xb4 == 0)) {
        uVar15 = get_runtime_hash_rate(local_8bc,0xb4,(local_8bc >> 2) * 0x16c16c17);
        uVar19 = getAVGhashrate();
        dVar22 = (double)CONCAT44(extraout_s1,uVar19);
        if (4 < log_level) {
          pFVar7 = fopen(log_file,"a+");
          if (pFVar7 != (FILE *)0x0) {
            fprintf(pFVar7,"%s:%d:%s: run time hash = %f, avg hash = %f\n","driver-btm-c5.c",0x28c3,
                    "check_system_work",uVar15,dVar22);
          }
          fclose(pFVar7);
        }
        if (((uVar15 != 0) &&
            ((int)((uint)(dVar22 < (double)(longlong)ideal_total_hash_rate * 0.9) << 0x1f) < 0)) &&
           ((int)((uint)(dVar22 / (double)uVar15 < 0.95) << 0x1f) < 0)) {
          reCalculateAVG();
        }
      }
      if ((local_8bc == 0x168) <= bVar4) goto LAB_0003bf7a;
      if (3 < log_level) {
        pFVar7 = fopen(log_file,"a+");
        if (pFVar7 != (FILE *)0x0) {
          fprintf(pFVar7,"%s:%d:%s: checking hash again\n","driver-btm-c5.c",0x28cd,
                  "check_system_work");
        }
        fclose(pFVar7);
      }
      iVar6 = if_avg_hash_ok();
      if (iVar6 != 0) {
        if (log_level < 4) {
          bVar4 = true;
        }
        else {
          pFVar7 = fopen(log_file,"a+");
          if (pFVar7 != (FILE *)0x0) {
            fprintf(pFVar7,"%s:%d:%s: hash rate is ok now\n","driver-btm-c5.c",0x28d0,
                    "check_system_work");
          }
LAB_0003c3a0:
          bVar4 = true;
          fclose(pFVar7);
        }
        goto LAB_0003bf7a;
      }
      bVar4 = false;
      if (1 < local_88c) goto LAB_0003bf7a;
      local_8bc = 100;
      uVar15 = 0;
    }
    if ((bVar2) || (opt_fixed_freq != '\0')) {
LAB_0003bfde:
      if ((!bVar3) && (opt_fixed_freq == '\0')) {
LAB_0003c2e6:
        if (local_8bc == (local_8bc / 0x3c) * 0x3c) {
          if (4 < log_level) {
            pFVar7 = fopen(log_file,"a+");
            if (pFVar7 != (FILE *)0x0) {
              fprintf(pFVar7,
                      "%s:%d:%s: voltage check, last_testpatten_highest_pcb_temp = %d, critical_value = %d\n"
                      ,"driver-btm-c5.c",0x2903,"check_system_work",last_testpatten_highest_pcb_temp
                      ,0x2f);
            }
            fclose(pFVar7);
          }
          if (0x2f < last_testpatten_highest_pcb_temp) {
            set_working_voltage();
            if (3 < log_level) {
              pFVar7 = fopen(log_file,"a+");
              if (pFVar7 != (FILE *)0x0) {
                fprintf(pFVar7,"%s:%d:%s: voltage_check_done\n","driver-btm-c5.c",0x2909,
                        "check_system_work");
              }
              fclose(pFVar7);
            }
            bVar3 = true;
            is_working_in_low_temperature = 0;
            goto joined_r0x0003c316;
          }
        }
        bVar3 = false;
      }
    }
    else {
      if (local_8bc % 900 == 0) {
        if (4 < log_level) {
          pFVar7 = fopen(log_file,"a+");
          if (pFVar7 != (FILE *)0x0) {
            fprintf(pFVar7,"%s:%d:%s: check if the hash rate is too high...\n","driver-btm-c5.c",
                    0x28df,"check_system_work");
          }
          fclose(pFVar7);
        }
        iVar6 = check_avg_rate();
        if (iVar6 == 0) {
          ok_num_14263 = 0;
        }
        else {
          bVar2 = 5 < ok_num_14263;
          ok_num_14263 = ok_num_14263 + 1;
        }
        goto LAB_0003bfde;
      }
      if (!bVar3) goto LAB_0003c2e6;
    }
joined_r0x0003c316:
    if (uVar15 == 0) {
      xadc_check();
    }
    cgtime(&local_860);
    cgtime(auStack_858);
    iVar6 = local_860 - local_868;
    if (local_85c - local_864 < 0) {
      iVar6 = iVar6 + -1;
    }
    if (iVar6 < 0x12d) {
      if (0x3c < iVar6) goto LAB_0003c026;
      if (iVar6 < 0x1f) {
        bVar8 = 0;
      }
      else {
        bVar8 = global_stop & 1;
      }
      if (bVar8 != 0) goto LAB_0003c026;
    }
    else {
      check_temp_offside = 1;
LAB_0003c026:
      iVar18 = 0;
      iVar10 = 0;
      local_8c8 = (int *)0x0;
      iVar6 = nonce_times;
      do {
        if ((*(int *)(dev + (iVar10 + 2) * 4) != 0) &&
           (uVar15 = (uint)*(byte *)(dev + iVar10 + 0x53ec),
           local_8c8 = (int *)((int)local_8c8 + uVar15), uVar15 != 0)) {
          iVar17 = 0;
          do {
            iVar16 = dev + (iVar10 * 0x80 + iVar17) * 8;
            uVar19 = *(undefined4 *)(iVar16 + 0xb00);
            iVar13 = iVar6 % 0x3c + iVar10 * 0x1e00 + iVar17 * 0x3c;
            *(undefined4 *)(nonce_num + iVar13 * 8) = *(undefined4 *)(iVar16 + 0xafc);
            *(undefined4 *)(nonce_num + iVar13 * 8 + 4) = uVar19;
            iVar18 = iVar18 + *(int *)(iVar16 + 0xafc);
            if ((opt_debug != '\0') &&
               (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
              snprintf(acStack_848,0x800,"%s: chain %d asic %d asic_nonce_num %d",
                       "check_system_work",iVar10,iVar17,*(int *)(iVar16 + 0xafc));
              _applog(7,acStack_848,0);
              iVar6 = nonce_times;
            }
            iVar17 = iVar17 + 1;
          } while (iVar17 < (int)(uint)*(byte *)(dev + iVar10 + 0x53ec));
        }
        iVar10 = iVar10 + 1;
      } while (iVar10 != 0x10);
      nonce_times = iVar6 + 1;
      memset(nonce_num10_string,0,0x1000);
      memset(nonce_num30_string,0,0x1000);
      memset(nonce_num60_string,0,0x1000);
      get_lastn_nonce_num(nonce_num10_string,10);
      get_lastn_nonce_num(nonce_num30_string,0x1e);
      get_lastn_nonce_num(nonce_num60_string,0x3c);
      if (((local_8c8 != (int *)0x0) && (opt_debug != '\0')) &&
         ((use_syslog != '\0' || ((opt_log_output != '\0' || (6 < opt_log_level)))))) {
        snprintf(acStack_848,0x800,"%s: avg_num %d asic_num %d","check_system_work",iVar18,local_8c8
                );
        _applog(7,acStack_848,0);
      }
      iVar6 = dev;
      cVar5 = status_error;
      local_8dc = 0;
      local_8c4 = (int *)x_time;
      local_8c0 = (byte *)(dev + 0x53ec);
      local_8c8 = (int *)(dev + 4);
      piVar11 = (int *)(dev + 0x44);
      iVar18 = nonce_times % 0x3c + -1;
      iVar10 = nonce_times % 0x3c + 0x3b;
      if (-1 < iVar18) {
        iVar10 = iVar18;
      }
      do {
        local_8c8 = local_8c8 + 1;
        if (*local_8c8 != 0) {
          uVar15 = (uint)*local_8c0;
          if (uVar15 == 0) {
            local_8a8 = local_8dc << 4;
            iVar18 = 0;
          }
          else {
            iVar18 = 0;
            local_8a8 = local_8dc * 0x10;
            uVar12 = 0;
            iVar13 = iVar6 + local_8dc * 0x88;
            piVar14 = local_8c4;
            iVar17 = local_8dc * 0x1e00;
            do {
              bVar20 = (uVar12 & 7) == 0;
              iVar16 = iVar13 + iVar18;
              if (bVar20) {
                iVar17 = 0x20;
              }
              if (bVar20) {
                iVar18 = iVar18 + 1;
              }
              if (bVar20) {
                *(char *)(iVar16 + uVar12 + 0x4afc) = (char)iVar17;
              }
              if (*(int *)(nonce_num + (local_8dc * 0x1e00 + uVar12 * 0x3c + iVar10) * 8) < 2) {
                *(undefined1 *)(iVar13 + iVar18 + uVar12 + 0x4afc) = 0x6f;
                iVar17 = 0x6f;
                if (cVar5 == '\0') {
                  *piVar14 = *piVar14 + 1;
                  iVar17 = 0x6f;
                }
              }
              else {
                *(undefined1 *)(iVar13 + iVar18 + uVar12 + 0x4afc) = 0x6f;
              }
              iVar16 = local_8dc * 0x80 + uVar12;
              uVar12 = uVar12 + 1;
              piVar14 = piVar14 + 1;
              iVar16 = iVar6 + (iVar16 + 0x15f) * 8;
              *(undefined4 *)(iVar16 + 4) = 0;
              *(undefined4 *)(iVar16 + 8) = 0;
            } while (uVar12 != uVar15);
            iVar18 = uVar15 + iVar18;
          }
          *(undefined1 *)(iVar18 + iVar6 + (local_8a8 + local_8dc) * 8 + 0x4afc) = 0;
        }
        local_8dc = local_8dc + 1;
        local_8c0 = local_8c0 + 1;
        local_8c4 = local_8c4 + 0x100;
      } while (piVar11 != local_8c8);
      copy_time(&local_868,&local_860);
    }
    local_8bc = local_8bc + 1;
    cgsleep_ms(1000);
  } while( true );
}

