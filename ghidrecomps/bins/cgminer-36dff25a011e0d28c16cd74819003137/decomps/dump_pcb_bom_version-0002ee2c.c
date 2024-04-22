
/* WARNING: Unknown calling convention */

void dump_pcb_bom_version(void)

{
  uint16_t uVar1;
  FILE *pFVar2;
  FILE *pFile_1;
  FILE *pFile;
  int chain;
  
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          uVar1 = eeprom_get_pcb_version(chain);
          fprintf(pFVar2,"%s:%d:%s: Chain [%d] PCB Version: 0x%04x\n","driver-btm-soc.c",0x1b83,
                  "dump_pcb_bom_version",chain,(uint)uVar1);
        }
        fclose(pFVar2);
      }
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          uVar1 = eeprom_get_bom_version(chain);
          fprintf(pFVar2,"%s:%d:%s: Chain [%d] BOM Version: 0x%04x\n","driver-btm-soc.c",0x1b84,
                  "dump_pcb_bom_version",chain,(uint)uVar1);
        }
        fclose(pFVar2);
      }
    }
  }
  return;
}

