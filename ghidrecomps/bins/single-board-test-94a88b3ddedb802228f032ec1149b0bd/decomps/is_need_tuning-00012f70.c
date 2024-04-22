
undefined4 is_need_tuning(int param_1,int param_2,int *param_3,int *param_4)

{
  char cVar1;
  FILE *pFVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int local_14;
  int local_10;
  int local_c;
  
  if ((param_3 == (int *)0x0) || (param_4 == (int *)0x0)) {
    if (1 < log_level) {
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d: invalid parameter!\n","board_frq_tuning.c",0xf8);
      }
      fclose(pFVar2);
    }
    uVar5 = 0;
  }
  else if (conf._144_4_ == 0) {
    if (3 < log_level) {
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d: force_freq not set, don\'t need tuning\n","board_frq_tuning.c",0xfe);
      }
      fclose(pFVar2);
    }
    uVar5 = 0;
  }
  else if (param_1 < param_2) {
    cVar1 = is_S9();
    if (cVar1 == '\x01') {
      cVar1 = is_search_mode6();
      if (cVar1 == '\x01') {
        iVar3 = GetTotalRate();
        if (3 < log_level) {
          pFVar2 = fopen(log_file,"a+");
          if (pFVar2 != (FILE *)0x0) {
            fprintf(pFVar2,"%s:%d: total_rate = %d\n","board_frq_tuning.c",0x118,iVar3);
          }
          fclose(pFVar2);
        }
        if ((iVar3 < param_1) || (param_2 < iVar3)) {
          if (3 < log_level) {
            pFVar2 = fopen(log_file,"a+");
            if (pFVar2 != (FILE *)0x0) {
              fprintf(pFVar2,"%s:%d: Don\'t need freqency tuning.\n","board_frq_tuning.c",0x11c);
            }
            fclose(pFVar2);
          }
          uVar5 = 0;
        }
        else {
          local_10 = 0;
          local_14 = 0;
          for (local_c = 0; local_c < 0x10; local_c = local_c + 1) {
            if (*(int *)(chain_vol_value + local_c * 4) == 0x366) {
              local_10 = local_10 + 1;
              iVar4 = GetBoardRate(local_c);
              if (local_14 < iVar4) {
                *param_3 = local_c;
                local_14 = iVar4;
              }
              if (3 < log_level) {
                pFVar2 = fopen(log_file,"a+");
                if (pFVar2 != (FILE *)0x0) {
                  fprintf(pFVar2,"%s:%d: i, rate = %d, %d\n","board_frq_tuning.c",0x131,local_c,
                          iVar4);
                }
                fclose(pFVar2);
              }
            }
          }
          if (3 < log_level) {
            pFVar2 = fopen(log_file,"a+");
            if (pFVar2 != (FILE *)0x0) {
              fprintf(pFVar2,"%s:%d: v870_num = %d\n","board_frq_tuning.c",0x135,local_10);
            }
            fclose(pFVar2);
          }
          if (local_10 < 2) {
            uVar5 = 0;
          }
          else {
            *param_4 = (local_14 + param_2) - iVar3;
            if (3 < log_level) {
              pFVar2 = fopen(log_file,"a+");
              if (pFVar2 != (FILE *)0x0) {
                fprintf(pFVar2,"%s:%d: chain_index, excepted_board_rate = %d, %d\n",
                        "board_frq_tuning.c",0x13c,*param_3,*param_4);
              }
              fclose(pFVar2);
            }
            uVar5 = 1;
          }
        }
      }
      else {
        if (3 < log_level) {
          pFVar2 = fopen(log_file,"a+");
          if (pFVar2 != (FILE *)0x0) {
            fprintf(pFVar2,"%s:%d: It\'s not search mode 6, will leave.\n","board_frq_tuning.c",
                    0x112);
          }
          fclose(pFVar2);
        }
        uVar5 = 0;
      }
    }
    else {
      if (3 < log_level) {
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d: This tuning is only for S9\n","board_frq_tuning.c",0x10b);
        }
        fclose(pFVar2);
      }
      uVar5 = 0;
    }
  }
  else {
    if (1 < log_level) {
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,
                "%s:%d: invalid parameter, min_total_rate must less than excepted_total_rate!\n",
                "board_frq_tuning.c",0x104);
      }
      fclose(pFVar2);
    }
    uVar5 = 0;
  }
  return uVar5;
}

