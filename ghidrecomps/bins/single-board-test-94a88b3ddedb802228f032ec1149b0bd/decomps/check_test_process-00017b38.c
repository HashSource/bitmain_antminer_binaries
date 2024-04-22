
undefined check_test_process(int param_1)

{
  int iVar1;
  undefined uVar2;
  bool bVar3;
  int local_1c;
  FILE *local_18;
  int local_14;
  int local_10;
  int local_c;
  
  local_10 = 0;
  local_14 = 0;
  for (local_c = 0; local_c < 0x10; local_c = local_c + 1) {
    if (*(int *)(cgpu + (local_c + 0x9c638) * 4) != 0) {
      iVar1 = is_S9_Hydro();
      if (iVar1 == 0) {
        local_14 = local_14 + 1;
      }
      else {
        get_board_index_S9_Hydro(local_c,&local_1c);
        if (local_1c == 0) {
          local_14 = local_14 + 1;
        }
      }
      if (*(char *)(local_c + param_1 + 0x58588) != '\0') {
        local_10 = local_10 + 1;
      }
    }
  }
  if (3 < log_level) {
    local_18 = fopen(log_file,"a+");
    if (local_18 != (FILE *)0x0) {
      fprintf(local_18," finished %d of %d\n\n",local_10,local_14);
    }
    fclose(local_18);
  }
  bVar3 = local_10 == local_14;
  if (bVar3) {
    local_14 = 1;
  }
  uVar2 = (undefined)local_14;
  if (!bVar3) {
    uVar2 = 0;
  }
  return uVar2;
}

