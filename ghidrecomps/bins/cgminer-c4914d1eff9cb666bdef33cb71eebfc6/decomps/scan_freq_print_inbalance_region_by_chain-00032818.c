
/* WARNING: Variable defined which should be unmapped: freq_scan_times-local */

void scan_freq_print_inbalance_region_by_chain(int chain,int freq_scan_times)

{
  char cVar1;
  FILE *pFVar2;
  int iVar3;
  int freq_scan_times_local;
  int chain_local;
  int bad_core [6];
  FILE *pFile_2;
  FILE *pFile_1;
  FILE *pFile;
  FILE *pFile_3;
  FILE *pFile_4;
  int chip;
  char inbalance_vol_num;
  _Bool handle_flag;
  int core;
  int vol_region;
  
  bad_core[0] = 0;
  bad_core[1] = 0;
  bad_core[2] = 0;
  bad_core[3] = 0;
  bad_core[4] = 0;
  bad_core[5] = 0;
  handle_flag = false;
  inbalance_vol_num = '\0';
  iVar3 = freq_scan_times + -1;
  for (vol_region = 0; vol_region < 6; vol_region = vol_region + 1) {
    bad_core[vol_region] = 0;
    chip = get_physical_chip_no(vol_region,0);
    if (4 < log_level) {
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"chip[%3d]\n",chip,pFVar2,iVar3);
      }
      fclose(pFVar2);
    }
    for (core = 0; core < 0xd0; core = core + 1) {
      if (scanfreq_info.asic_core_nonce_num[chain][chip][core] < scanfreq_info.AsicWorkCount / 0xd0)
      {
        bad_core[vol_region] = bad_core[vol_region] + 1;
      }
    }
    if (3 < log_level) {
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"domain[%2d] bad cores:[%3d]\n",vol_region + 1,bad_core[vol_region]);
      }
      fclose(pFVar2);
    }
    if (0x33 < bad_core[vol_region]) {
      handle_flag = true;
      cVar1 = (char)vol_region;
      if (inbalance_vol_num == '\0') {
        inbalance_info_record[chain].vol0 = cVar1 + '\x01';
      }
      else if (inbalance_vol_num == '\x01') {
        inbalance_info_record[chain].vol1 = cVar1 + '\x01';
      }
      else if (inbalance_vol_num == '\x02') {
        inbalance_info_record[chain].vol2 = cVar1 + '\x01';
      }
      else if (inbalance_vol_num == '\x03') {
        inbalance_info_record[chain].vol3 = cVar1 + '\x01';
      }
      else if (3 < log_level) {
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"too much inbalance vol region[%d]\n",(byte)inbalance_vol_num + 1);
        }
        fclose(pFVar2);
      }
      inbalance_vol_num = inbalance_vol_num + '\x01';
    }
  }
  inbalance_info_record[chain].len = inbalance_vol_num;
  if (handle_flag == true) {
    if (3 < log_level) {
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"Chain[%d]  FAIL !!!\n",chain,pFVar2,iVar3);
      }
      fclose(pFVar2);
    }
  }
  else {
    if (3 < log_level) {
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"Chain[%d]  PASS!!!\n",chain,pFVar2,iVar3);
      }
      fclose(pFVar2);
    }
    scanfreq_info.test_done[chain] = true;
  }
  return;
}

