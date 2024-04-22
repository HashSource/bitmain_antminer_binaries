
/* WARNING: Unknown calling convention */

void * check_system_work(void)

{
  bool bVar1;
  _Bool _Var2;
  FILE *pFVar3;
  int iVar4;
  int extraout_r1;
  undefined4 uVar5;
  uint64_t *puVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  timeval diff;
  timeval tv_reboot_start;
  timeval tv_reboot;
  timeval tv_end;
  timeval tv_start;
  FILE *pFile_2;
  FILE *pFile_3;
  FILE *pFile_1;
  FILE *pFile;
  double latest_avg_rate;
  int six_hour;
  double total_secs;
  double total_mhashes;
  char *hash_log;
  int offset;
  _Bool get_stable_hashs_flag;
  double last_total_secs;
  double last_total_mhashes;
  uint32_t counter;
  int run_counter;
  int avg_num;
  int asic_num;
  int j;
  int i;
  
  cgtime(&tv_end);
  cgtime(&tv_reboot);
  copy_time(&tv_start,&tv_end);
  copy_time(&tv_reboot_start,&tv_reboot);
  run_counter = 0;
  counter = 0;
  last_total_mhashes = get_total_hashs();
  last_total_secs = get_total_secs();
  get_total_hashs();
  get_total_secs();
  bVar1 = true;
  do {
    while (doTestPatten != false) {
      cgsleep_ms(100);
    }
    set_led();
    counter = counter + 1;
    cgtime(&tv_end);
    cgtime(&tv_reboot);
    diff.tv_sec = tv_end.tv_sec - tv_start.tv_sec;
    if (tv_end.tv_usec - tv_start.tv_usec < 0) {
      diff.tv_sec = diff.tv_sec + -1;
    }
    if (counter == 0x1e) {
      disable_pic_circuit();
    }
    if (counter % 0x3c == 0) {
      if (counter % 600 == 0) {
        copy_log_to_latest("/var/log/hash_rate");
        clear_log("/var/log/hash_rate");
      }
      print_crt_time_to_file("/var/log/hash_rate",3);
      dump_nonce_info_all_domain();
      dump_nonce_info_all_asic();
    }
    if ((bVar1) && (counter % 0x78 == 0)) {
      bVar1 = false;
      last_total_mhashes = get_total_hashs();
      last_total_secs = get_total_secs();
    }
    if (counter % 0x708 == 0) {
      dVar7 = get_total_hashs();
      dVar8 = get_total_secs();
      dVar9 = (dVar7 - last_total_mhashes) / DAT_00029658;
      dVar10 = dVar8 - last_total_secs;
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar3 = fopen(log_file,"a+");
        if (pFVar3 != (FILE *)0x0) {
          fprintf(pFVar3,
                  "%s:%d:%s: The avg rate is  %0.0f in 30 mins, PCB temperature between %d ~ %d \n",
                  "driver-btm-soc.c",0xf40,"check_system_work");
        }
        fclose(pFVar3);
      }
      last_total_secs = dVar8;
      last_total_mhashes = dVar7;
      if ((((status_error != true) && (__aeabi_uidivmod(counter,0x5460), extraout_r1 == 0)) &&
          (iVar4 = get_ideal_hash_rate_fixed(),
          dVar9 / dVar10 < (double)(longlong)iVar4 * DAT_00029660)) &&
         ((_Var2 = is_domain_unbalance(), _Var2 && (3 < log_level)))) {
        print_crt_time_to_file(log_file,3);
        pFVar3 = fopen(log_file,"a+");
        if (pFVar3 != (FILE *)0x0) {
          fprintf(pFVar3,"%s:%d:%s: Six hour hash rate check: unbalance domain happened.\n",
                  "driver-btm-soc.c",0xf4d,"check_system_work");
        }
        fclose(pFVar3);
      }
    }
    if (counter % 10 == 0) {
      process_TEST();
    }
    if ((0x3c < diff.tv_sec) || ((_Var2 = is_in_error(), _Var2 && (0x1e < diff.tv_sec)))) {
      run_counter = run_counter + 1;
      asic_num = 0;
      avg_num = 0;
      for (i = 0; i < 0x10; i = i + 1) {
        if (dev->chain_exist[i] != 0) {
          asic_num = asic_num + (uint)dev->chain_asic_num[i];
          for (j = 0; j < (int)(uint)dev->chain_asic_num[i]; j = j + 1) {
            iVar4 = nonce_times % 0x3c;
            puVar6 = dev->chain_asic_nonce[i] + j;
            uVar5 = *(undefined4 *)((int)puVar6 + 4);
            *(undefined4 *)(nonce_num[i][j] + iVar4) = *(undefined4 *)puVar6;
            *(undefined4 *)((int)nonce_num[i][j] + iVar4 * 8 + 4) = uVar5;
            avg_num = *(int *)(dev->chain_asic_nonce[i] + j) + avg_num;
            if (4 < log_level) {
              print_crt_time_to_file(log_file,4);
              pFVar3 = fopen(log_file,"a+");
              if (pFVar3 != (FILE *)0x0) {
                fprintf(pFVar3,"%s:%d:%s: chain %d asic %d asic_nonce_num %lld\n","driver-btm-soc.c"
                        ,0xfb8,"check_system_work",i,j);
              }
              fclose(pFVar3);
            }
          }
        }
      }
      nonce_times = nonce_times + 1;
      memset(nonce_num10_string,0,0x1000);
      memset(nonce_num30_string,0,0x1000);
      memset(nonce_num60_string,0,0x1000);
      get_lastn_nonce_num(nonce_num10_string,10);
      get_lastn_nonce_num(nonce_num30_string,0x1e);
      get_lastn_nonce_num(nonce_num60_string,0x3c);
      if (asic_num != 0) {
        if (4 < log_level) {
          print_crt_time_to_file(log_file,4);
          pFVar3 = fopen(log_file,"a+");
          if (pFVar3 != (FILE *)0x0) {
            fprintf(pFVar3,"%s:%d:%s: avg_num %d asic_num %d\n","driver-btm-soc.c",0xfc6,
                    "check_system_work",avg_num,asic_num);
          }
          fclose(pFVar3);
        }
        __aeabi_idiv(avg_num,asic_num);
      }
      for (i = 0; i < 0x10; i = i + 1) {
        if (dev->chain_exist[i] != 0) {
          offset = 0;
          for (j = 0; j < (int)(uint)dev->chain_asic_num[i]; j = j + 1) {
            if ((j & 7U) == 0) {
              dev->chain_asic_status_string[i][j + offset] = ' ';
              offset = offset + 1;
            }
            iVar4 = get_asic_nonce_num(i,j,1);
            if (iVar4 < 2) {
              dev->chain_asic_status_string[i][j + offset] = 'o';
              if (status_error != true) {
                x_time[i][j] = x_time[i][j] + 1;
              }
            }
            else {
              dev->chain_asic_status_string[i][j + offset] = 'o';
            }
            puVar6 = dev->chain_asic_nonce[i] + j;
            *(undefined4 *)puVar6 = 0;
            *(undefined4 *)((int)puVar6 + 4) = 0;
          }
          dev->chain_asic_status_string[i][j + offset] = '\0';
        }
      }
      if (0x3c < run_counter) {
        run_counter = 0;
      }
      copy_time(&tv_start,&tv_end);
    }
    cgsleep_ms(1000);
  } while( true );
}

