
/* WARNING: Unknown calling convention */

void check_asic_status(void)

{
  all_parameters *paVar1;
  _Bool _Var2;
  FILE *pFVar3;
  int iVar4;
  undefined4 uVar5;
  FILE *pFile;
  FILE *pFile_1;
  int offset;
  int avg_num;
  int asic_num;
  int j;
  int i;
  
  _Var2 = is_in_error();
  if (!_Var2) {
    asic_num = 0;
    avg_num = 0;
    for (i = 0; i < 0x10; i = i + 1) {
      if (dev->chain_exist[i] != 0) {
        asic_num = asic_num + (uint)dev->chain_asic_num[i];
        for (j = 0; j < (int)(uint)dev->chain_asic_num[i]; j = j + 1) {
          iVar4 = nonce_times % 0x3c;
          uVar5 = *(undefined4 *)((int)dev->chain_asic_nonce[i] + j * 8 + 4);
          *(undefined4 *)(nonce_num[i][j] + iVar4) = *(undefined4 *)(dev->chain_asic_nonce[i] + j);
          *(undefined4 *)((int)nonce_num[i][j] + iVar4 * 8 + 4) = uVar5;
          avg_num = avg_num + *(int *)(dev->chain_asic_nonce[i] + j);
          if (4 < log_level) {
            print_crt_time_to_file(log_file,4);
            pFVar3 = fopen(log_file,"a+");
            if (pFVar3 != (FILE *)0x0) {
              fprintf(pFVar3,"%s:%d:%s: chain %d asic %d asic_nonce_num %llu\n","driver-btm-soc.c",
                      0xcdb,"check_asic_status",i,j);
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
          fprintf(pFVar3,"%s:%d:%s: avg_num %d asic_num %d\n","driver-btm-soc.c",0xce9,
                  "check_asic_status",avg_num,asic_num);
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
          paVar1 = dev;
          *(undefined4 *)(dev->chain_asic_nonce[i] + j) = 0;
          *(undefined4 *)((int)paVar1->chain_asic_nonce[i] + j * 8 + 4) = 0;
        }
        dev->chain_asic_status_string[i][j + offset] = '\0';
      }
    }
  }
  return;
}

