
void get_ideal_hash_rate(int *param_1)

{
  int iVar1;
  uint uVar2;
  int local_7c;
  int local_78;
  FILE *local_74;
  FILE *local_70;
  FILE *local_6c;
  FILE *local_68;
  int local_64;
  FILE *local_60;
  FILE *local_5c;
  FILE *local_58;
  int local_54;
  FILE *local_50;
  FILE *local_4c;
  FILE *local_48;
  FILE *local_44;
  FILE *local_40;
  FILE *local_3c;
  int local_38;
  FILE *local_34;
  double local_30;
  int local_24;
  int local_20;
  int local_1c;
  uint local_18;
  uint local_14;
  
  for (local_14 = 0; (int)local_14 < 0x10; local_14 = local_14 + 1) {
    if ((*(int *)(cgpu + (local_14 + 0x9c638) * 4) != 0) &&
       ((iVar1 = is_S9_Hydro(), iVar1 == 0 ||
        (iVar1 = get_board_index_S9_Hydro(local_14,0), iVar1 == local_14)))) {
      *(undefined *)((int)param_1 + local_14 + 0x58588) = 0;
    }
  }
  board_init_all_chain(param_1);
  local_1c = 9999;
  for (local_14 = 0; (int)local_14 < 0x10; local_14 = local_14 + 1) {
    if (*(int *)(cgpu + (local_14 + 0x9c638) * 4) != 0) {
      if (5 < log_level) {
        local_34 = fopen(log_file,"a+");
        if (local_34 != (FILE *)0x0) {
          fprintf(local_34,"%s:%d: chain[%d] set freq:\n","board_frq_tuning.c",0x75c,local_14);
        }
        fclose(local_34);
      }
      iVar1 = is_S9_Hydro();
      if (iVar1 == 0) {
        for (local_18 = 0; (int)local_18 < *param_1; local_18 = local_18 + 1) {
          set_frequency_with_addr_plldatai
                    (param_1[local_18 + local_14 * 0x100 + 2],0,(local_18 & 0x7f) << 1,
                     local_14 & 0xff);
          if (param_1[local_18 + local_14 * 0x100 + 2] < local_1c) {
            local_1c = param_1[local_18 + local_14 * 0x100 + 2];
          }
          if (5 < log_level) {
            local_40 = fopen(log_file,"a+");
            if (local_40 != (FILE *)0x0) {
              iVar1 = atoi(*(char **)(freq_pll_1385 +
                                     param_1[local_18 + local_14 * 0x100 + 2] * 0x10));
              fprintf(local_40,"%3d ",iVar1);
            }
            fclose(local_40);
          }
        }
      }
      else {
        local_38 = get_board_index_S9_Hydro(local_14,&local_78);
        for (local_18 = 0; (int)local_18 < 0x54; local_18 = local_18 + 1) {
          set_frequency_with_addr_plldatai
                    (param_1[local_78 * 0x54 + local_18 + local_38 * 0x100 + 2],0,
                     (local_18 & 0x7f) << 1,local_14 & 0xff);
          if (param_1[local_78 * 0x54 + local_18 + local_38 * 0x100 + 2] < local_1c) {
            local_1c = param_1[local_78 * 0x54 + local_18 + local_38 * 0x100 + 2];
          }
          if (5 < log_level) {
            local_3c = fopen(log_file,"a+");
            if (local_3c != (FILE *)0x0) {
              iVar1 = atoi(*(char **)(freq_pll_1385 +
                                     param_1[local_78 * 0x54 + local_18 + local_38 * 0x100 + 2] *
                                     0x10));
              fprintf(local_3c,"%3d ",iVar1);
            }
            fclose(local_3c);
          }
        }
      }
      if (5 < log_level) {
        local_44 = fopen(log_file,"a+");
        if (local_44 != (FILE *)0x0) {
          fputc(10,local_44);
        }
        fclose(local_44);
      }
    }
  }
  iVar1 = atoi(*(char **)(freq_pll_1385 + local_1c * 0x10));
  set_time_control_by_frq(iVar1);
  highest_voltage_open_core_all_chain(param_1);
  if (3 < log_level) {
    local_48 = fopen(log_file,"a+");
    if (local_48 != (FILE *)0x0) {
      fprintf(local_48,"%s:%d: start_send_work_and_get_result_all_chain enter\n",
              "board_frq_tuning.c",0x782);
    }
    fclose(local_48);
  }
  local_20 = 0;
  for (local_14 = 0; (int)local_14 < 0x10; local_14 = local_14 + 1) {
    if (*(int *)(cgpu + (local_14 + 0x9c638) * 4) != 0) {
      *(undefined4 *)(chain_DataCount + local_14 * 4) = 0x390;
      *(undefined4 *)(chain_ValidNonce + local_14 * 4) = 0x12b40;
      *(undefined4 *)(chain_PassCount + local_14 * 4) = 0x390;
      StartSendFlag[local_14] = 1;
    }
  }
  reset_work_data();
  if (gBegin_get_nonce != '\x01') {
    puts("clement2 set_nonce_fifo_interrupt");
    uVar2 = get_nonce_fifo_interrupt();
    set_nonce_fifo_interrupt(uVar2 | 0x10000);
    gBegin_get_nonce = '\x01';
  }
  if (3 < log_level) {
    local_4c = fopen(log_file,"a+");
    if (local_4c != (FILE *)0x0) {
      fprintf(local_4c,"%s:%d: start send works...\n","board_frq_tuning.c",0x79c);
    }
    fclose(local_4c);
  }
  send_func_all();
  for (local_14 = 0; (int)local_14 < 0x10; local_14 = local_14 + 1) {
    if (*(int *)(cgpu + (local_14 + 0x9c638) * 4) != 0) {
      if (3 < log_level) {
        local_50 = fopen(log_file,"a+");
        if (local_50 != (FILE *)0x0) {
          fprintf(local_50,"%s:%d: wait recv nonce on chain[%d]\n","board_frq_tuning.c",0x7a4,
                  local_14);
        }
        fclose(local_50);
      }
      local_24 = 0;
      local_20 = 0;
      while ((local_20 < 0x14 &&
             (*(int *)(valid_nonce_num + local_14 * 4) < *(int *)(chain_ValidNonce + local_14 * 4)))
            ) {
        if (*(int *)(valid_nonce_num + local_14 * 4) == local_24) {
          local_20 = local_20 + 1;
        }
        else {
          local_20 = 0;
          local_24 = *(int *)(valid_nonce_num + local_14 * 4);
        }
        usleep(100000);
      }
    }
  }
  gBegin_get_nonce = 0;
  start_receive = 0;
  local_30 = 0.0;
  local_54 = 0;
  for (local_14 = 0; (int)local_14 < 0x10; local_14 = local_14 + 1) {
    if ((*(int *)(cgpu + (local_14 + 0x9c638) * 4) != 0) && (param_1[local_14 + 0x15002] != 0)) {
      local_30 = 0.0;
      if (3 < log_level) {
        local_58 = fopen(log_file,"a+");
        if (local_58 != (FILE *)0x0) {
          fprintf(local_58,"chain[%d] nonce status:\n",local_14);
        }
        fclose(local_58);
      }
      for (local_18 = 0; (int)local_18 < 0x54; local_18 = local_18 + 1) {
        if (3 < log_level) {
          local_5c = fopen(log_file,"a+");
          if (local_5c != (FILE *)0x0) {
            fprintf(local_5c,"  Asic%02d",local_18 + 1);
          }
          fclose(local_5c);
        }
      }
      if (3 < log_level) {
        local_60 = fopen(log_file,"a+");
        if (local_60 != (FILE *)0x0) {
          fputc(10,local_60);
        }
        fclose(local_60);
      }
      iVar1 = is_S9_Hydro();
      if (iVar1 == 0) {
        for (local_18 = 0; (int)local_18 < *param_1; local_18 = local_18 + 1) {
          iVar1 = atoi(*(char **)(freq_pll_1385 + param_1[local_18 + local_14 * 0x100 + 2] * 0x10));
          local_30 = local_30 +
                     ((double)(longlong)
                              (*(int *)(asic_nonce_num + (local_18 + local_14 * 0x100) * 4) * iVar1)
                     / 8.0) / DAT_00018570;
          if (3 < log_level) {
            local_6c = fopen(log_file,"a+");
            if (local_6c != (FILE *)0x0) {
              fprintf(local_6c,"  %6d",
                      *(undefined4 *)(asic_nonce_num + (local_18 + local_14 * 0x100) * 4));
            }
            fclose(local_6c);
          }
        }
      }
      else {
        local_64 = get_board_index_S9_Hydro(local_14,&local_7c);
        for (local_18 = 0; (int)local_18 < 0x54; local_18 = local_18 + 1) {
          iVar1 = atoi(*(char **)(freq_pll_1385 +
                                 param_1[local_7c * 0x54 + local_18 + local_64 * 0x100 + 2] * 0x10))
          ;
          local_30 = local_30 +
                     ((double)(longlong)
                              (*(int *)(asic_nonce_num + (local_18 + local_14 * 0x100) * 4) * iVar1)
                     / 8.0) / DAT_00018570;
          if (3 < log_level) {
            local_68 = fopen(log_file,"a+");
            if (local_68 != (FILE *)0x0) {
              fprintf(local_68,"  %6d",
                      *(undefined4 *)(asic_nonce_num + (local_18 + local_14 * 0x100) * 4));
            }
            fclose(local_68);
          }
        }
      }
      if (3 < log_level) {
        local_70 = fopen(log_file,"a+");
        if (local_70 != (FILE *)0x0) {
          fputc(10,local_70);
        }
        fclose(local_70);
      }
      local_54 = (int)(longlong)local_30;
      param_1[local_14 + 0x16166] = local_54;
      if (3 < log_level) {
        local_74 = fopen(log_file,"a+");
        if (local_74 != (FILE *)0x0) {
          fprintf(local_74,"%s:%d: chain[%d] ideal hash rate = %d\n","board_frq_tuning.c",0x7e5,
                  local_14,local_54);
        }
        fclose(local_74);
      }
    }
  }
  save_pattern_result(asic_nonce_num,param_1);
  return;
}

