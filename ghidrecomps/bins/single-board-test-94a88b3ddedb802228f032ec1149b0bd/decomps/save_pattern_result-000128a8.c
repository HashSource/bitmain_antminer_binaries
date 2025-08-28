
void save_pattern_result(int param_1,int param_2)

{
  char cVar1;
  size_t sVar2;
  int iVar3;
  char local_458 [16];
  undefined4 local_448;
  char acStack_418 [1024];
  int local_18;
  int local_14;
  
  if (pattern_file_fd == (FILE *)0x0) {
    pattern_file_fd = fopen("/tmp/pattern_test_result_file","w");
    if (pattern_file_fd == (FILE *)0x0) {
      fclose((FILE *)0x0);
      return;
    }
    memset(acStack_418,0,0x400);
    for (local_18 = 0; local_18 < 0x54; local_18 = local_18 + 1) {
      memset(local_458,0,0x40);
      sprintf(local_458,"  Asic%02d",local_18 + 1);
      strcat(acStack_418,local_458);
    }
    sVar2 = strlen(acStack_418);
    (acStack_418 + sVar2)[0] = '\n';
    (acStack_418 + sVar2)[1] = '\0';
    fprintf(pattern_file_fd,acStack_418,0);
    fclose(pattern_file_fd);
  }
  pattern_file_fd = fopen("/tmp/pattern_test_result_file","a+");
  if (pattern_file_fd == (FILE *)0x0) {
    fclose((FILE *)0x0);
  }
  else {
    memset(local_458,0,0x40);
    builtin_strncpy(local_458,"pattern test sta",0x10);
    local_448._0_1_ = 'r';
    local_448._1_1_ = 't';
    local_448._2_1_ = '\n';
    local_448._3_1_ = '\0';
    fprintf(pattern_file_fd,local_458,0);
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
          memset(local_458,0,0x40);
          sprintf(local_458,"chain[%d] nonce status:\n",local_14);
          fprintf(pattern_file_fd,local_458,0);
          memset(acStack_418,0,0x400);
          for (local_18 = 0; local_18 < 0x54; local_18 = local_18 + 1) {
            memset(local_458,0,0x40);
            sprintf(local_458,"  %6d",*(undefined4 *)(local_14 * 0x400 + param_1 + local_18 * 4));
            strcat(acStack_418,local_458);
          }
          sVar2 = strlen(acStack_418);
          (acStack_418 + sVar2)[0] = '\n';
          (acStack_418 + sVar2)[1] = '\0';
          fprintf(pattern_file_fd,acStack_418,0);
        }
      }
    }
    memset(local_458,0,0x40);
    builtin_strncpy(local_458,"pattern test ove",0x10);
    local_448 = CONCAT13(local_448._3_1_,0xa72);
    fprintf(pattern_file_fd,local_458,0);
    fclose(pattern_file_fd);
  }
  return;
}

