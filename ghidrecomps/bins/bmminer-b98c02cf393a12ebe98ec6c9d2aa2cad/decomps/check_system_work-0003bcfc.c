
void check_system_work(void)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  undefined4 uVar8;
  char cVar9;
  int iVar10;
  FILE *pFVar11;
  byte bVar12;
  byte bVar13;
  int iVar14;
  int *piVar15;
  uint uVar16;
  undefined1 *__nptr;
  int iVar17;
  int *piVar18;
  uint uVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  undefined4 uVar23;
  bool bVar24;
  double dVar25;
  double dVar26;
  int local_8dc;
  int *local_8c8;
  int *local_8c4;
  byte *local_8c0;
  uint local_8bc;
  undefined4 local_8b8;
  int local_8a8;
  uint local_894;
  uint local_88c;
  int local_888;
  undefined4 local_870;
  int local_868;
  int local_864;
  int local_860;
  int local_85c;
  undefined auStack_858 [8];
  undefined auStack_850 [8];
  char acStack_848 [2052];
  
  cgtime(&local_860);
  cgtime(auStack_858);
  copy_time(&local_868,&local_860);
  copy_time(auStack_850,auStack_858);
  iVar10 = readRestartNum();
  if (iVar10 < 1) {
    local_8b8 = DAT_0003c750;
  }
  else if (log_level < 4) {
    local_8b8 = DAT_0003be78;
  }
  else {
    pFVar11 = fopen(log_file,(char *)&DAT_0005e760);
    local_8b8 = DAT_0003c750;
    if (pFVar11 != (FILE *)0x0) {
      fprintf(pFVar11,"%s:%d:%s: restartNum = %d , auto-reinit enabled...\n","driver-btm-c5.c",
              0x2862,DAT_0003c750,iVar10);
    }
    fclose(pFVar11);
  }
  dVar7 = DAT_0003be68;
  dVar6 = DAT_0003be60;
  dVar5 = DAT_0003be58;
  local_88c = 0;
  bVar13 = 0;
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
    if (((local_8bc ==
          (((uint)((ulonglong)local_8bc * 0x88888889 >> 0x20) & 0xfffffff0) - local_8bc / 0x1e) * 2)
        && (!bVar1)) && (global_stop == 0)) {
      if (bVar13 < 10) {
        bVar13 = bVar13 + 1;
      }
      else {
        __nptr = displayed_rate;
        iVar10 = 0;
        dVar26 = DAT_0003be70;
        do {
          while ((iVar14 = iVar10 + 2, iVar10 = iVar10 + 1, *(int *)(dev + iVar14 * 4) == 1 &&
                 (*__nptr != '\0'))) {
            dVar25 = strtod(__nptr,(char **)0x0);
            dVar26 = dVar26 + dVar25;
            __nptr = __nptr + 0x20;
            if (iVar10 == 0x10) goto LAB_0003beac;
          }
          __nptr = __nptr + 0x20;
        } while (iVar10 != 0x10);
LAB_0003beac:
        iVar10 = (uint)(dVar26 < (double)(longlong)ideal_total_hash_rate * dVar7) << 0x1f;
        if (-1 < iVar10) {
          local_894 = 0;
        }
        if (iVar10 < 0) {
          local_894 = local_894 + 1;
          if (local_894 ==
              local_894 / 3 + ((uint)((ulonglong)local_894 * 0xaaaaaaab >> 0x20) & 0xfffffffe)) {
            local_888 = local_888 + 1;
            if (3 < log_level) {
              pFVar11 = fopen(log_file,(char *)&DAT_0005e760);
              if (pFVar11 != (FILE *)0x0) {
                fprintf(pFVar11,
                        "%s:%d:%s: re_open_core_times: %d, total_rate:%f, ideal_total_hash_rate:%d\n"
                        ,"driver-btm-c5.c",0x288c,local_8b8,local_888,dVar26,ideal_total_hash_rate);
              }
              fclose(pFVar11);
            }
            bVar13 = 0;
            re_open_core(local_870);
          }
          bVar1 = 0x3c < local_894;
        }
      }
    }
    if (local_8bc == 0x78) {
      if (opt_fixed_freq == '\0') {
        iVar10 = if_avg_hash_ok();
        if (iVar10 == 0) {
          if (1 < log_level) {
            pFVar11 = fopen(log_file,(char *)&DAT_0005e760);
            if (pFVar11 != (FILE *)0x0) {
              fprintf(pFVar11,"%s:%d:%s: hash rate is low...\n","driver-btm-c5.c",0x28a4,local_8b8);
            }
            fclose(pFVar11);
          }
          if (bring_up_pcb_temp < 0x23) {
            local_88c = local_88c + 1;
            re_open_core();
            if (3 < log_level) {
              pFVar11 = fopen(log_file,(char *)&DAT_0005e760);
              if (pFVar11 != (FILE *)0x0) {
                fprintf(pFVar11,"%s:%d:%s: re-open core %d times\n","driver-btm-c5.c",0x28b1,
                        local_8b8,local_88c);
              }
              fclose(pFVar11);
            }
            bVar3 = false;
            local_870 = 1;
            is_working_in_low_temperature = 1;
            goto LAB_0003bf7a;
          }
        }
        else if (3 < log_level) {
          pFVar11 = fopen(log_file,(char *)&DAT_0005e760);
          if (pFVar11 != (FILE *)0x0) {
            fprintf(pFVar11,"%s:%d:%s: hash rate is ok now\n","driver-btm-c5.c",0x289f,local_8b8);
          }
          goto LAB_0003c3a0;
        }
        bVar4 = true;
      }
LAB_0003bf7a:
      uVar19 = local_8bc % 10;
    }
    else {
      if ((local_8bc - 0xb4 < 0x654) && (local_8bc + ((local_8bc >> 2) / 0x2d) * -0xb4 == 0)) {
        uVar19 = get_runtime_hash_rate(local_8bc,0xb4,(local_8bc >> 2) * 0x16c16c17);
        dVar26 = (double)getAVGhashrate();
        if (4 < log_level) {
          pFVar11 = fopen(log_file,(char *)&DAT_0005e760);
          if (pFVar11 != (FILE *)0x0) {
            fprintf(pFVar11,"%s:%d:%s: run time hash = %f, avg hash = %f\n","driver-btm-c5.c",0x28c3
                    ,local_8b8,uVar19,dVar26);
          }
          fclose(pFVar11);
        }
        if (((uVar19 != 0) &&
            ((int)((uint)(dVar26 < (double)(longlong)ideal_total_hash_rate * dVar5) << 0x1f) < 0))
           && ((int)((uint)(dVar26 / (double)(ulonglong)uVar19 < dVar6) << 0x1f) < 0)) {
          reCalculateAVG();
        }
      }
      if ((local_8bc == 0x168) <= bVar4) goto LAB_0003bf7a;
      if (3 < log_level) {
        pFVar11 = fopen(log_file,(char *)&DAT_0005e760);
        if (pFVar11 != (FILE *)0x0) {
          fprintf(pFVar11,"%s:%d:%s: checking hash again\n","driver-btm-c5.c",0x28cd,local_8b8);
        }
        fclose(pFVar11);
      }
      iVar10 = if_avg_hash_ok();
      if (iVar10 != 0) {
        if (log_level < 4) {
          bVar4 = true;
        }
        else {
          pFVar11 = fopen(log_file,(char *)&DAT_0005e760);
          if (pFVar11 != (FILE *)0x0) {
            fprintf(pFVar11,"%s:%d:%s: hash rate is ok now\n","driver-btm-c5.c",0x28d0,local_8b8);
          }
LAB_0003c3a0:
          bVar4 = true;
          fclose(pFVar11);
        }
        goto LAB_0003bf7a;
      }
      bVar4 = false;
      if (1 < local_88c) goto LAB_0003bf7a;
      local_8bc = 100;
      uVar19 = 0;
    }
    if ((bVar2) || (opt_fixed_freq != '\0')) {
LAB_0003bfde:
      if ((!bVar3) && (opt_fixed_freq == '\0')) {
LAB_0003c2e6:
        if (local_8bc == (local_8bc / 0x3c) * 0x3c) {
          if (4 < log_level) {
            pFVar11 = fopen(log_file,(char *)&DAT_0005e760);
            if (pFVar11 != (FILE *)0x0) {
              fprintf(pFVar11,
                      "%s:%d:%s: voltage check, last_testpatten_highest_pcb_temp = %d, critical_value = %d\n"
                      ,"driver-btm-c5.c",0x2903,local_8b8,last_testpatten_highest_pcb_temp,0x2f);
            }
            fclose(pFVar11);
          }
          if (0x2f < last_testpatten_highest_pcb_temp) {
            set_working_voltage();
            if (3 < log_level) {
              pFVar11 = fopen(log_file,(char *)&DAT_0005e760);
              if (pFVar11 != (FILE *)0x0) {
                fprintf(pFVar11,"%s:%d:%s: voltage_check_done\n","driver-btm-c5.c",0x2909,local_8b8)
                ;
              }
              fclose(pFVar11);
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
          pFVar11 = fopen(log_file,(char *)&DAT_0005e760);
          if (pFVar11 != (FILE *)0x0) {
            fprintf(pFVar11,"%s:%d:%s: check if the hash rate is too high...\n","driver-btm-c5.c",
                    0x28df,local_8b8);
          }
          fclose(pFVar11);
        }
        iVar10 = check_avg_rate();
        if (iVar10 == 0) {
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
    if (uVar19 == 0) {
      xadc_check();
    }
    cgtime(&local_860);
    cgtime(auStack_858);
    iVar10 = local_860 - local_868;
    if (local_85c - local_864 < 0) {
      iVar10 = iVar10 + -1;
    }
    if (iVar10 < 0x12d) {
      if (0x3c < iVar10) goto LAB_0003c026;
      if (iVar10 < 0x1f) {
        bVar12 = 0;
      }
      else {
        bVar12 = global_stop & 1;
      }
      if (bVar12 != 0) goto LAB_0003c026;
    }
    else {
      check_temp_offside = 1;
LAB_0003c026:
      iVar22 = 0;
      iVar14 = 0;
      local_8c8 = (int *)0x0;
      iVar10 = nonce_times;
      do {
        if ((*(int *)(dev + (iVar14 + 2) * 4) != 0) &&
           (uVar19 = (uint)*(byte *)(dev + iVar14 + 0x53ec),
           local_8c8 = (int *)((int)local_8c8 + uVar19), uVar19 != 0)) {
          iVar21 = 0;
          do {
            uVar8 = DAT_0003c368;
            iVar20 = dev + (iVar14 * 0x80 + iVar21) * 8;
            uVar23 = *(undefined4 *)(iVar20 + 0xb00);
            iVar17 = iVar10 % 0x3c + iVar14 * 0x1e00 + iVar21 * 0x3c;
            *(undefined4 *)(nonce_num + iVar17 * 8) = *(undefined4 *)(iVar20 + 0xafc);
            *(undefined4 *)(nonce_num + iVar17 * 8 + 4) = uVar23;
            iVar22 = iVar22 + *(int *)(iVar20 + 0xafc);
            if ((opt_debug != '\0') &&
               (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
              snprintf(acStack_848,0x800,"%s: chain %d asic %d asic_nonce_num %d",uVar8,iVar14,
                       iVar21,*(int *)(iVar20 + 0xafc));
              _applog(7,acStack_848,0);
              iVar10 = nonce_times;
            }
            iVar21 = iVar21 + 1;
          } while (iVar21 < (int)(uint)*(byte *)(dev + iVar14 + 0x53ec));
        }
        iVar14 = iVar14 + 1;
      } while (iVar14 != 0x10);
      nonce_times = iVar10 + 1;
      memset(nonce_num10_string,0,0x1000);
      memset(nonce_num30_string,0,0x1000);
      memset(nonce_num60_string,0,0x1000);
      get_lastn_nonce_num(nonce_num10_string,10);
      get_lastn_nonce_num(nonce_num30_string,0x1e);
      get_lastn_nonce_num(nonce_num60_string,0x3c);
      if (((local_8c8 != (int *)0x0) && (opt_debug != '\0')) &&
         ((use_syslog != '\0' || ((opt_log_output != '\0' || (6 < opt_log_level)))))) {
        snprintf(acStack_848,0x800,"%s: avg_num %d asic_num %d",DAT_0003c368,iVar22,local_8c8);
        _applog(7,acStack_848,0);
      }
      iVar10 = dev;
      cVar9 = status_error;
      local_8dc = 0;
      local_8c4 = DAT_0003c36c;
      local_8c0 = (byte *)(dev + 0x53ec);
      local_8c8 = (int *)(dev + 4);
      piVar15 = (int *)(dev + 0x44);
      iVar22 = nonce_times % 0x3c + -1;
      iVar14 = nonce_times % 0x3c + 0x3b;
      if (-1 < iVar22) {
        iVar14 = iVar22;
      }
      do {
        local_8c8 = local_8c8 + 1;
        if (*local_8c8 != 0) {
          uVar19 = (uint)*local_8c0;
          if (uVar19 == 0) {
            local_8a8 = local_8dc << 4;
            iVar22 = 0;
          }
          else {
            iVar22 = 0;
            local_8a8 = local_8dc * 0x10;
            uVar16 = 0;
            iVar17 = iVar10 + local_8dc * 0x88;
            piVar18 = local_8c4;
            iVar21 = local_8dc * 0x1e00;
            do {
              bVar24 = (uVar16 & 7) == 0;
              iVar20 = iVar17 + iVar22;
              if (bVar24) {
                iVar21 = 0x20;
              }
              if (bVar24) {
                iVar22 = iVar22 + 1;
              }
              if (bVar24) {
                *(char *)(iVar20 + uVar16 + 0x4afc) = (char)iVar21;
              }
              if (*(int *)(nonce_num + (local_8dc * 0x1e00 + uVar16 * 0x3c + iVar14) * 8) < 2) {
                *(undefined *)(iVar17 + iVar22 + uVar16 + 0x4afc) = 0x6f;
                iVar21 = 0x6f;
                if (cVar9 == '\0') {
                  *piVar18 = *piVar18 + 1;
                  iVar21 = 0x6f;
                }
              }
              else {
                *(undefined *)(iVar17 + iVar22 + uVar16 + 0x4afc) = 0x6f;
              }
              iVar20 = local_8dc * 0x80 + uVar16;
              uVar16 = uVar16 + 1;
              piVar18 = piVar18 + 1;
              iVar20 = iVar10 + (iVar20 + 0x15f) * 8;
              *(undefined4 *)(iVar20 + 4) = 0;
              *(undefined4 *)(iVar20 + 8) = 0;
            } while (uVar16 != uVar19);
            iVar22 = uVar19 + iVar22;
          }
          *(undefined *)(iVar22 + iVar10 + (local_8a8 + local_8dc) * 8 + 0x4afc) = 0;
        }
        local_8dc = local_8dc + 1;
        local_8c0 = local_8c0 + 1;
        local_8c4 = local_8c4 + 0x100;
      } while (piVar15 != local_8c8);
      copy_time(&local_868,&local_860);
    }
    local_8bc = local_8bc + 1;
    cgsleep_ms(1000);
  } while( true );
}

