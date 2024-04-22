
void print_freq_table(void)

{
  FILE *pFVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  int local_34;
  int *local_30;
  
  local_30 = DAT_000359a4;
  local_34 = 0;
  do {
    if (*(int *)(dev + (local_34 + 2) * 4) == 1) {
      if (3 < log_level) {
        pFVar1 = fopen(log_file,(char *)&DAT_0005e760);
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d:%s: chain[%d] freq table:\n","driver-btm-c5.c",0x27d8,DAT_000359a8,
                  local_34);
        }
        fclose(pFVar1);
      }
      uVar3 = 1;
      uVar2 = log_level;
      piVar4 = local_30;
LAB_000358ce:
      do {
        if (3 < uVar2) {
          pFVar1 = fopen(log_file,(char *)&DAT_0005e760);
          if (pFVar1 != (FILE *)0x0) {
            fprintf(pFVar1,"Asic[%2d]:%s ",uVar3 - 1,*(undefined4 *)(freq_pll_1385 + *piVar4 * 0x10)
                   );
          }
          fclose(pFVar1);
          uVar2 = log_level;
          if (((uVar3 & 7) == 0) && (3 < log_level)) {
            pFVar1 = fopen(log_file,(char *)&DAT_0005e760);
            if (pFVar1 != (FILE *)0x0) {
              fputc(10,pFVar1);
            }
            uVar3 = uVar3 + 1;
            fclose(pFVar1);
            piVar4 = piVar4 + 1;
            uVar2 = log_level;
            if (uVar3 == 0x55) break;
            goto LAB_000358ce;
          }
        }
        uVar3 = uVar3 + 1;
        piVar4 = piVar4 + 1;
      } while (uVar3 != 0x55);
      if (3 < uVar2) {
        pFVar1 = fopen(log_file,(char *)&DAT_0005e760);
        if (pFVar1 != (FILE *)0x0) {
          fwrite(&DAT_00060a5c,1,2,pFVar1);
        }
        fclose(pFVar1);
      }
    }
    local_34 = local_34 + 1;
    local_30 = local_30 + 0x100;
    if (local_34 == 0x10) {
      return;
    }
  } while( true );
}

