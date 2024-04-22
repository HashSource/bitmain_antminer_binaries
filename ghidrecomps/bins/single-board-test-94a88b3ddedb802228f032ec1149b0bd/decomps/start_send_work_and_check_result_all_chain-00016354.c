
void start_send_work_and_check_result_all_chain(int param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int aiStack_d8 [16];
  int aiStack_98 [16];
  int local_58;
  FILE *local_54;
  int local_50;
  FILE *local_4c;
  int local_48;
  int local_44;
  FILE *local_40;
  FILE *local_3c;
  FILE *local_38;
  FILE *local_34;
  FILE *local_30;
  FILE *local_2c;
  FILE *local_28;
  FILE *local_24;
  FILE *local_20;
  FILE *local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  if (3 < log_level) {
    local_1c = fopen(log_file,"a+");
    if (local_1c != (FILE *)0x0) {
      fprintf(local_1c,"%s:%d: start_send_work_and_get_result_all_chain enter\n",
              "board_frq_tuning.c",0x52a);
    }
    fclose(local_1c);
  }
  local_c = 0;
  for (local_14 = 0; local_14 < 0x10; local_14 = local_14 + 1) {
    iVar3 = is_S9_Hydro();
    if (iVar3 == 0) {
      if (*(int *)(cgpu + (local_14 + 0x9c638) * 4) != 0) {
        cVar1 = *(char *)(local_14 + param_1 + 0x58588);
        goto joined_r0x0001643c;
      }
    }
    else if (*(int *)(cgpu + (local_14 + 0x9c638) * 4) != 0) {
      iVar3 = get_board_index_S9_Hydro(local_14,0);
      cVar1 = *(char *)(param_1 + iVar3 + 0x58588);
joined_r0x0001643c:
      if (cVar1 == '\0') {
        *(undefined4 *)(chain_DataCount + local_14 * 4) = 0x390;
        *(undefined4 *)(chain_ValidNonce + local_14 * 4) = 0x12b40;
        *(undefined4 *)(chain_PassCount + local_14 * 4) = 0x390;
        StartSendFlag[local_14] = 1;
      }
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
    local_20 = fopen(log_file,"a+");
    if (local_20 != (FILE *)0x0) {
      fprintf(local_20,"%s:%d: start send works...\n","board_frq_tuning.c",0x54c);
    }
    fclose(local_20);
  }
  send_func_all();
  for (local_14 = 0; local_14 < 0x10; local_14 = local_14 + 1) {
    iVar3 = is_S9_Hydro();
    if (iVar3 == 0) {
      if (*(int *)(cgpu + (local_14 + 0x9c638) * 4) != 0) {
        cVar1 = *(char *)(local_14 + param_1 + 0x58588);
        goto joined_r0x000165c6;
      }
    }
    else if (*(int *)(cgpu + (local_14 + 0x9c638) * 4) != 0) {
      iVar3 = get_board_index_S9_Hydro(local_14,0);
      cVar1 = *(char *)(param_1 + iVar3 + 0x58588);
joined_r0x000165c6:
      if (cVar1 == '\0') {
        if (3 < log_level) {
          local_24 = fopen(log_file,"a+");
          if (local_24 != (FILE *)0x0) {
            fprintf(local_24,"%s:%d: wait recv nonce on chain[%d]\n","board_frq_tuning.c",0x55c,
                    local_14);
          }
          fclose(local_24);
        }
        local_10 = 0;
        local_c = 0;
        while ((local_c < 0x14 &&
               (*(int *)(valid_nonce_num + local_14 * 4) < *(int *)(chain_ValidNonce + local_14 * 4)
               ))) {
          if (*(int *)(valid_nonce_num + local_14 * 4) == local_10) {
            local_c = local_c + 1;
          }
          else {
            local_c = 0;
            local_10 = *(int *)(valid_nonce_num + local_14 * 4);
          }
          usleep(100000);
        }
      }
    }
  }
  gBegin_get_nonce = 0;
  start_receive = 0;
  for (local_14 = 0; local_14 < 0x10; local_14 = local_14 + 1) {
    iVar3 = is_T9_plus();
    if (iVar3 == 0) {
      if (*(int *)(cgpu + (local_14 + 0x9c638) * 4) != 0) {
        cVar1 = *(char *)(local_14 + param_1 + 0x58588);
        goto joined_r0x0001675e;
      }
    }
    else if (*(int *)(cgpu + (local_14 + 0x9c638) * 4) != 0) {
      iVar3 = get_board_index_S9_Hydro(local_14,0);
      cVar1 = *(char *)(param_1 + iVar3 + 0x58588);
joined_r0x0001675e:
      if (cVar1 == '\0') {
        if (3 < log_level) {
          local_28 = fopen(log_file,"a+");
          if (local_28 != (FILE *)0x0) {
            fprintf(local_28,"chain[%d] nonce status:\n",local_14);
          }
          fclose(local_28);
        }
        for (local_18 = 0; local_18 < 0x54; local_18 = local_18 + 1) {
          if (3 < log_level) {
            local_2c = fopen(log_file,"a+");
            if (local_2c != (FILE *)0x0) {
              fprintf(local_2c,"  Asic%02d",local_18 + 1);
            }
            fclose(local_2c);
          }
        }
        if (3 < log_level) {
          local_30 = fopen(log_file,"a+");
          if (local_30 != (FILE *)0x0) {
            fputc(10,local_30);
          }
          fclose(local_30);
        }
        for (local_18 = 0; local_18 < 0x54; local_18 = local_18 + 1) {
          if (3 < log_level) {
            local_34 = fopen(log_file,"a+");
            if (local_34 != (FILE *)0x0) {
              fprintf(local_34,"  %6d",
                      *(undefined4 *)(asic_nonce_num + (local_18 + local_14 * 0x100) * 4));
            }
            fclose(local_34);
          }
        }
        if (3 < log_level) {
          local_38 = fopen(log_file,"a+");
          if (local_38 != (FILE *)0x0) {
            fputc(10,local_38);
          }
          fclose(local_38);
        }
      }
    }
  }
  save_pattern_result(asic_nonce_num,param_1);
  local_14 = 0;
  do {
    if (0xf < local_14) {
      return;
    }
    iVar3 = is_S9_Hydro();
    if (iVar3 == 0) {
      if (*(int *)(cgpu + (local_14 + 0x9c638) * 4) != 0) {
        cVar1 = *(char *)(local_14 + param_1 + 0x58588);
        goto joined_r0x000169ce;
      }
    }
    else if (*(int *)(cgpu + (local_14 + 0x9c638) * 4) != 0) {
      iVar3 = get_board_index_S9_Hydro(local_14,0);
      cVar1 = *(char *)(param_1 + iVar3 + 0x58588);
joined_r0x000169ce:
      if (cVar1 == '\0') {
        init_chip_rate_table(param_1,asic_nonce_num + local_14 * 0x400,local_14);
        if (3 < log_level) {
          local_3c = fopen(log_file,"a+");
          if (local_3c != (FILE *)0x0) {
            fprintf(local_3c,"%s:%d: chain[%d] total valid nonce number:%d\n","board_frq_tuning.c",
                    0x59d,local_14,*(undefined4 *)(valid_nonce_num + local_14 * 4));
          }
          fclose(local_3c);
        }
        if (3 < log_level) {
          local_40 = fopen(log_file,"a+");
          if (local_40 != (FILE *)0x0) {
            fprintf(local_40,"%s:%d: chain[%d] total send work number:%d\n","board_frq_tuning.c",
                    0x59e,local_14,*(undefined4 *)(send_work_num + local_14 * 4));
          }
          fclose(local_40);
        }
        iVar3 = is_S9_Hydro();
        if (iVar3 == 0) {
          local_50 = (int)(longlong)
                          ((double)(longlong)*(int *)(chain_ValidNonce + local_14 * 4) *
                          DAT_00016d20);
          if (3 < log_level) {
            local_54 = fopen(log_file,"a+");
            if (local_54 != (FILE *)0x0) {
              fprintf(local_54,"%s:%d: chain[%d] require valid nonce number:%d\n",
                      "board_frq_tuning.c",0x5b7,local_14,local_50);
            }
            fclose(local_54);
          }
          if (local_50 < *(int *)(valid_nonce_num + local_14 * 4)) {
            *(undefined *)(local_14 + param_1 + 0x58588) = 1;
          }
        }
        else {
          memset(aiStack_d8,0,0x40);
          memset(aiStack_98,0,0x40);
          local_44 = get_board_index_S9_Hydro(local_14,&local_58);
          aiStack_d8[local_44] = aiStack_d8[local_44] + *(int *)(chain_ValidNonce + local_14 * 4);
          aiStack_98[local_44] = aiStack_98[local_44] + *(int *)(valid_nonce_num + local_14 * 4);
          if (local_58 == 2) {
            local_48 = (int)(longlong)((double)(longlong)aiStack_d8[local_44] * DAT_00016d20);
            if (3 < log_level) {
              local_4c = fopen(log_file,"a+");
              if (local_4c != (FILE *)0x0) {
                fprintf(local_4c,"%s:%d: board[%d] require valid nonce number:%d\n",
                        "board_frq_tuning.c",0x5ac,local_44,local_48);
              }
              fclose(local_4c);
            }
            if (local_48 < aiStack_98[local_44]) {
              *(undefined *)(local_44 + param_1 + 0x58588) = 1;
            }
          }
        }
        StartSendFlag[local_14] = 0;
      }
    }
    local_14 = local_14 + 1;
  } while( true );
}

