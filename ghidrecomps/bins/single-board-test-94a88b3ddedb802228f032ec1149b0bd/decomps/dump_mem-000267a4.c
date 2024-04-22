
void dump_mem(int param_1,int param_2,int param_3)

{
  uint uVar1;
  undefined auStack_3c [20];
  FILE *local_28;
  FILE *local_24;
  FILE *local_20;
  FILE *local_1c;
  FILE *local_18;
  FILE *local_14;
  int local_10;
  uint local_c;
  
  local_10 = param_2;
  if ((param_1 != 0) && (3 < log_level)) {
    local_14 = fopen(log_file,"a+");
    if (local_14 != (FILE *)0x0) {
      fprintf(local_14,"%s:\n",param_1);
    }
    fclose(local_14);
  }
  for (local_c = 0; (int)local_c < param_3; local_c = local_c + 1) {
    if ((local_c & 0xf) == 0) {
      if ((local_c != 0) && (3 < log_level)) {
        local_18 = fopen(log_file,"a+");
        if (local_18 != (FILE *)0x0) {
          fprintf(local_18,"  %s\n",auStack_3c);
        }
        fclose(local_18);
      }
      if (3 < log_level) {
        local_1c = fopen(log_file,"a+");
        if (local_1c != (FILE *)0x0) {
          fprintf(local_1c,"  %04x ",local_c);
        }
        fclose(local_1c);
      }
    }
    if (3 < log_level) {
      local_20 = fopen(log_file,"a+");
      if (local_20 != (FILE *)0x0) {
        fprintf(local_20," %02x",(uint)*(byte *)(local_c + local_10));
      }
      fclose(local_20);
    }
    if ((*(byte *)(local_c + local_10) < 0x20) || (0x7e < *(byte *)(local_c + local_10))) {
      uVar1 = local_c & 0xf;
      if ((int)local_c < 1) {
        uVar1 = -(-local_c & 0xf);
      }
      auStack_3c[uVar1] = 0x2e;
    }
    else {
      uVar1 = local_c & 0xf;
      if ((int)local_c < 1) {
        uVar1 = -(-local_c & 0xf);
      }
      auStack_3c[uVar1] = *(undefined *)(local_c + local_10);
    }
    uVar1 = local_c & 0xf;
    if ((int)local_c < 1) {
      uVar1 = -(-local_c & 0xf);
    }
    auStack_3c[uVar1 + 1] = 0;
  }
  for (; (local_c & 0xf) != 0; local_c = local_c + 1) {
    if (3 < log_level) {
      local_24 = fopen(log_file,"a+");
      if (local_24 != (FILE *)0x0) {
        fwrite(&DAT_00130544,1,3,local_24);
      }
      fclose(local_24);
    }
  }
  if (3 < log_level) {
    local_28 = fopen(log_file,"a+");
    if (local_28 != (FILE *)0x0) {
      fprintf(local_28,"  %s\n",auStack_3c);
    }
    fclose(local_28);
  }
  return;
}

