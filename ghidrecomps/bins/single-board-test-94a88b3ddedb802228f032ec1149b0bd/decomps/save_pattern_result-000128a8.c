
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void save_pattern_result(int param_1,int param_2)

{
  char cVar1;
  size_t sVar2;
  int iVar3;
  undefined4 local_458;
  undefined4 uStack_454;
  undefined4 uStack_450;
  undefined4 uStack_44c;
  undefined4 local_448;
  undefined2 auStack_418 [512];
  int local_18;
  int local_14;
  
  if (pattern_file_fd == (FILE *)0x0) {
    pattern_file_fd = fopen("/tmp/pattern_test_result_file","w");
    if (pattern_file_fd == (FILE *)0x0) {
      fclose((FILE *)0x0);
      return;
    }
    memset(auStack_418,0,0x400);
    for (local_18 = 0; local_18 < 0x54; local_18 = local_18 + 1) {
      memset(&local_458,0,0x40);
      sprintf((char *)&local_458,"  Asic%02d",local_18 + 1);
      strcat((char *)auStack_418,(char *)&local_458);
    }
    sVar2 = strlen((char *)auStack_418);
    *(undefined2 *)((int)auStack_418 + sVar2) = DAT_0012cfbc;
    fprintf(pattern_file_fd,(char *)auStack_418,0);
    fclose(pattern_file_fd);
  }
  pattern_file_fd = fopen("/tmp/pattern_test_result_file","a+");
  if (pattern_file_fd == (FILE *)0x0) {
    fclose((FILE *)0x0);
  }
  else {
    memset(&local_458,0,0x40);
    local_458._0_1_ = s_pattern_test_start_0012cfc4[0];
    local_458._1_1_ = s_pattern_test_start_0012cfc4[1];
    local_458._2_1_ = s_pattern_test_start_0012cfc4[2];
    local_458._3_1_ = s_pattern_test_start_0012cfc4[3];
    uStack_454._0_1_ = s_pattern_test_start_0012cfc4[4];
    uStack_454._1_1_ = s_pattern_test_start_0012cfc4[5];
    uStack_454._2_1_ = s_pattern_test_start_0012cfc4[6];
    uStack_454._3_1_ = s_pattern_test_start_0012cfc4[7];
    uStack_450._0_1_ = s_pattern_test_start_0012cfc4[8];
    uStack_450._1_1_ = s_pattern_test_start_0012cfc4[9];
    uStack_450._2_1_ = s_pattern_test_start_0012cfc4[10];
    uStack_450._3_1_ = s_pattern_test_start_0012cfc4[11];
    uStack_44c._0_1_ = s_pattern_test_start_0012cfc4[12];
    uStack_44c._1_1_ = s_pattern_test_start_0012cfc4[13];
    uStack_44c._2_1_ = s_pattern_test_start_0012cfc4[14];
    uStack_44c._3_1_ = s_pattern_test_start_0012cfc4[15];
    local_448._0_1_ = s_pattern_test_start_0012cfc4[16];
    local_448._1_1_ = s_pattern_test_start_0012cfc4[17];
    local_448._2_1_ = s_pattern_test_start_0012cfc4[18];
    local_448._3_1_ = s_pattern_test_start_0012cfc4[19];
    fprintf(pattern_file_fd,(char *)&local_458,0);
    for (local_14 = 0; local_14 < 0x10; local_14 = local_14 + 1) {
      iVar3 = is_T9_plus();
      if (iVar3 == 0) {
        if (*(int *)(cgpu + (local_14 + 0x9c638) * 4) != 0) {
          cVar1 = *(char *)(local_14 + param_2 + 0x58588);
          goto joined_r0x00012aac;
        }
      }
      else if (*(int *)(cgpu + (local_14 + 0x9c638) * 4) != 0) {
        iVar3 = get_board_index_S9_Hydro(local_14,0);
        cVar1 = *(char *)(param_2 + iVar3 + 0x58588);
joined_r0x00012aac:
        if (cVar1 == '\0') {
          memset(&local_458,0,0x40);
          sprintf((char *)&local_458,"chain[%d] nonce status:\n",local_14);
          fprintf(pattern_file_fd,(char *)&local_458,0);
          memset(auStack_418,0,0x400);
          for (local_18 = 0; local_18 < 0x54; local_18 = local_18 + 1) {
            memset(&local_458,0,0x40);
            sprintf((char *)&local_458,"  %6d",
                    *(undefined4 *)(local_14 * 0x400 + param_1 + local_18 * 4));
            strcat((char *)auStack_418,(char *)&local_458);
          }
          sVar2 = strlen((char *)auStack_418);
          *(undefined2 *)((int)auStack_418 + sVar2) = DAT_0012cfbc;
          fprintf(pattern_file_fd,(char *)auStack_418,0);
        }
      }
    }
    memset(&local_458,0,0x40);
    local_458._0_1_ = s_pattern_test_over_0012cffc[0];
    local_458._1_1_ = s_pattern_test_over_0012cffc[1];
    local_458._2_1_ = s_pattern_test_over_0012cffc[2];
    local_458._3_1_ = s_pattern_test_over_0012cffc[3];
    uStack_454._0_1_ = s_pattern_test_over_0012cffc[4];
    uStack_454._1_1_ = s_pattern_test_over_0012cffc[5];
    uStack_454._2_1_ = s_pattern_test_over_0012cffc[6];
    uStack_454._3_1_ = s_pattern_test_over_0012cffc[7];
    uStack_450._0_1_ = s_pattern_test_over_0012cffc[8];
    uStack_450._1_1_ = s_pattern_test_over_0012cffc[9];
    uStack_450._2_1_ = s_pattern_test_over_0012cffc[10];
    uStack_450._3_1_ = s_pattern_test_over_0012cffc[11];
    uStack_44c._0_1_ = s_pattern_test_over_0012cffc[12];
    uStack_44c._1_1_ = s_pattern_test_over_0012cffc[13];
    uStack_44c._2_1_ = s_pattern_test_over_0012cffc[14];
    uStack_44c._3_1_ = s_pattern_test_over_0012cffc[15];
    fprintf(pattern_file_fd,(char *)&local_458,0);
    fclose(pattern_file_fd);
  }
  return;
}

