
int match_level(eeprom_v1 *ctx,pattern_runtime_ctx *runtime,float *matrix)

{
  _Bool _Var1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  float *pfVar7;
  float fVar8;
  double dVar9;
  int local_1d0;
  float *matrix_local;
  pattern_runtime_ctx *runtime_local;
  eeprom_v1 *ctx_local;
  char time_stamp [48];
  char tmp1 [256];
  float dec_base [3] [3];
  int col;
  int row;
  int low_freq;
  int high_freq;
  uint8_t_0_ *margin_dec_matrix;
  int bad_count;
  int avg;
  int i_1;
  int i;
  float sum_dec;
  int margin;
  int k;
  int x;
  uint32_t matched_vol;
  uint32_t matched_freq;
  
  matched_freq = 0;
  matched_vol._0_2_ = 0;
  matrix_local = matrix;
  runtime_local = runtime;
  ctx_local = ctx;
  fVar8 = get_avg_matrix(matrix,runtime->config->asics);
  dVar9 = floor((double)fVar8);
  iVar4 = (int)(longlong)dVar9;
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : sweep get matrix avg:%d\n","match_level",iVar4);
  snprintf(tmp1,0x100,"sweep get matrix avg:%d",iVar4);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : test level:%d\n","match_level",runtime_local->config->test_levels);
  snprintf(tmp1,0x100,"test level:%d",runtime_local->config->test_levels);
  log_to_file(tmp1,time_stamp);
  for (x = 0; x < runtime_local->config->test_levels; x = x + 1) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : cfg index[%d],level:[%d],freq:[%d]\n","match_level",x,
           runtime_local->config->tests[x].level,runtime_local->config->tests[x].freq);
    snprintf(tmp1,0x100,"cfg index[%d],level:[%d],freq:[%d]",x,runtime_local->config->tests[x].level
             ,runtime_local->config->tests[x].freq);
    log_to_file(tmp1,time_stamp);
  }
  k = 0;
  do {
    if (runtime_local->config->test_levels <= k) {
LAB_0005d492:
      if (matched_freq == 0) {
        set_sweep_err_state(0xe,false);
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : fail match freq\n","match_level");
        builtin_strncpy(tmp1,"fail match freq",0x10);
        log_to_file(tmp1,time_stamp);
        iVar4 = -1;
      }
      else {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        iVar2 = get_margin();
        printf("%s : ##margin is %d\n","match_level",iVar2);
        iVar2 = get_margin();
        snprintf(tmp1,0x100,"##margin is %d",iVar2);
        log_to_file(tmp1,time_stamp);
        pcVar3 = strstr(((g_rt.config)->board).board_name,"A3HB70503");
        if ((pcVar3 == (char *)0x0) ||
           ((_Var1 = is_ft_x("E1V07"), !_Var1 && (_Var1 = is_ft_x("F1V03"), !_Var1)))) {
          margin = iVar4 - matched_freq;
        }
        else {
          margin = (iVar4 - matched_freq) + -6;
        }
        if (margin < 0) {
          margin = 0;
        }
        if ((margin < 0) || (0x78 < margin)) {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : match failed margin < 0 or too big\n","match_level");
          builtin_strncpy(tmp1,"match failed margin < 0 or too b",0x20);
          tmp1[0x20] = 'i';
          tmp1[0x21] = 'g';
          tmp1[0x22] = '\0';
          log_to_file(tmp1,time_stamp);
          iVar4 = -1;
        }
        else {
          clear_bad_asic_ids();
          uVar5 = runtime_local->config->asics + 7U & 0xfffffff8;
          if (runtime_local->config->tests[0].freq == matched_freq) {
            iVar4 = 0x208;
          }
          else {
            iVar4 = 0x1ea;
          }
          if (runtime_local->config->tests[0].freq == matched_freq) {
            iVar2 = 0x1cc;
          }
          else {
            iVar2 = 0x1b1;
          }
          dec_base[0][0] = 3.0;
          dec_base[0][1] = 2.0;
          dec_base[0][2] = 3.0;
          dec_base[1][0] = 2.0;
          dec_base[1][1] = 1.0;
          dec_base[1][2] = 2.0;
          dec_base[2][0] = 1.0;
          dec_base[2][1] = 0.0;
          dec_base[2][2] = 1.0;
          sum_dec = 0.0;
          for (i = 0; i < runtime_local->config->asics; i = i + 1) {
            if (matrix_local[i] <= (float)(longlong)iVar4) {
              if ((int)((uint)(matrix_local[i] < (float)(longlong)iVar2) << 0x1f) < 0) {
                iVar6 = 2;
              }
              else {
                iVar6 = 1;
              }
            }
            else {
              iVar6 = 0;
            }
            local_1d0 = (uint)(0.0 < dec_base[iVar6][state_matrix[i]]) *
                        (int)dec_base[iVar6][state_matrix[i]];
            iVar6 = local_1d0;
            *(undefined1 *)((int)&local_1d0 + (i - uVar5)) = (undefined1)local_1d0;
            sum_dec = sum_dec + (float)*(byte *)((int)&local_1d0 + (i - uVar5));
            local_1d0 = iVar6;
          }
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : margin:%d\n","match_level",margin);
          snprintf(tmp1,0x100,"margin:%d",margin);
          log_to_file(tmp1,time_stamp);
          for (i_1 = 0; i_1 < runtime_local->config->asics; i_1 = i_1 + 1) {
            _Var1 = is_ft("F1V02B4C1-2-3_F1V02B5C1-3-4");
            if ((((_Var1) || (_Var1 = is_ft("F1V02B2C1-2"), _Var1)) ||
                (_Var1 = is_ft("F1V02B3C2-1"), _Var1)) || (_Var1 = is_ft("F1V02B1C1-2"), _Var1)) {
              iVar4 = get_margin();
              matrix_local[i_1] =
                   (float)((double)matrix_local[i_1] -
                          ((double)(longlong)(margin - iVar4) *
                           (double)(longlong)runtime_local->config->asics *
                          (double)*(byte *)((int)&local_1d0 + (i_1 - uVar5))) / (double)sum_dec);
            }
            else {
              iVar4 = get_margin();
              if (0 < margin - iVar4) {
                pfVar7 = matrix_local + i_1;
                fVar8 = matrix_local[i_1];
                iVar4 = get_margin();
                *pfVar7 = fVar8 - (float)(longlong)(margin - iVar4);
              }
            }
          }
          display_PCBA_result(matrix_local,(uint8_t)runtime_local->config->domains,
                              (uint8_t)runtime_local->config->asics_in_domain,true);
          (ctx_local->data).field_2.format_v1.pt2.voltage = (uint16_t)matched_vol;
          (ctx_local->data).field_2.format_v1.pt2.frequency = (uint16_t)matched_freq;
          iVar4 = 0;
        }
      }
      return iVar4;
    }
    iVar6 = runtime_local->config->tests[k].freq;
    iVar2 = get_margin();
    if (iVar2 + iVar6 + 3 <= iVar4) {
      matched_freq = runtime_local->config->tests[k].freq;
      matched_vol._0_2_ = (uint16_t)runtime_local->config->tests[k].voltage;
      runtime_local->config->sweeped_res_index = k;
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : matched index:[%d] level:%d,freq:%d\n","match_level",
             runtime_local->config->sweeped_res_index,
             runtime_local->config->tests[runtime_local->config->sweeped_res_index].level,
             runtime_local->config->tests[runtime_local->config->sweeped_res_index].freq);
      snprintf(tmp1,0x100,"matched index:[%d] level:%d,freq:%d",
               runtime_local->config->sweeped_res_index,
               runtime_local->config->tests[runtime_local->config->sweeped_res_index].level,
               runtime_local->config->tests[runtime_local->config->sweeped_res_index].freq);
      log_to_file(tmp1,time_stamp);
      goto LAB_0005d492;
    }
    k = k + 1;
  } while( true );
}

