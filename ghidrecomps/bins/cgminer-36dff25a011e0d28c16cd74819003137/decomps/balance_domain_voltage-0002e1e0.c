
/* WARNING: Unknown calling convention */

void balance_domain_voltage(void)

{
  FILE *pFVar1;
  FILE *pFile_1;
  FILE *pFile;
  int chain;
  int open_core_count;
  
  open_core_count = 0x15;
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,
              "%s:%d:%s: To balance voltage domain, open all core and reset hash board after find asic num.\n"
              ,"driver-btm-soc.c",0x1acd,"balance_domain_voltage");
    }
    fclose(pFVar1);
  }
  for (; open_core_count < 0x55; open_core_count = open_core_count << 1) {
    for (chain = 0; chain < 0x10; chain = chain + 1) {
      if (dev->chain_exist[chain] != 0) {
        if (3 < log_level) {
          print_crt_time_to_file(log_file,3);
          pFVar1 = fopen(log_file,"a+");
          if (pFVar1 != (FILE *)0x0) {
            fprintf(pFVar1,"%s:%d:%s: Open core %d for chain %d\n","driver-btm-soc.c",0x1ad8,
                    "balance_domain_voltage",open_core_count,chain);
          }
          fclose(pFVar1);
        }
        open_core_BM1391_pre_open(chain,open_core_count,'\x01');
        set_reset_hashboard(chain,1);
        sleep(3);
        set_reset_hashboard(chain,0);
        sleep(3);
      }
    }
  }
  return;
}

