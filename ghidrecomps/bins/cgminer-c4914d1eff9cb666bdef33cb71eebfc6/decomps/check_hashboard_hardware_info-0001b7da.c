
/* WARNING: Unknown calling convention */

int check_hashboard_hardware_info(void)

{
  uint8_t chain_00;
  _Bool _Var1;
  _Bool _Var2;
  _Bool _Var3;
  _Bool _Var4;
  FILE *pFVar5;
  bool bVar6;
  FILE *pFile;
  FILE *pFile_9;
  FILE *pFile_8;
  FILE *pFile_7;
  FILE *pFile_6;
  FILE *pFile_5;
  FILE *pFile_4;
  FILE *pFile_3;
  FILE *pFile_2;
  FILE *pFile_1;
  CHIP_LEVEL bin;
  CHIP_MINOR_TYPE minor;
  CHIP_MAJOR_TYPE major;
  _Bool success;
  int chain;
  
  success = true;
  major = 0xffff;
  minor = 0xffff;
  bin = 0xffff;
  chain = 0;
  do {
    if (0xf < chain) {
      return 0;
    }
    if (dev->chain_exist[chain] != 0) {
      chain_00 = (uint8_t)chain;
      _Var1 = eeprom_get_chip_major_type(chain_00,g_major_type + chain);
      bVar6 = (success & _Var1) != 0;
      _Var1 = eeprom_get_chip_minor_type(chain_00,g_minor_type + chain);
      _Var2 = eeprom_get_chip_level(chain_00,g_bin_level + chain);
      _Var3 = eeprom_get_bom_version(chain_00,bom_version + chain);
      _Var4 = eeprom_get_pcb_version(chain_00,chain_pcb_version + chain);
      success = (((bVar6 && _Var1) && _Var2) && _Var3) && _Var4;
      g_device_minor_type = g_minor_type[chain];
      g_device_bin_level = g_bin_level[chain];
      if ((((!bVar6 || !_Var1) || !_Var2) || !_Var3) || !_Var4) {
        if (3 < log_level) {
          print_crt_time_to_file(log_file,3);
          pFVar5 = fopen(log_file,"a+");
          if (pFVar5 != (FILE *)0x0) {
            fprintf(pFVar5,"%s:%d:%s: error! chain[%d] hashboard hardware info is wrong!\n",
                    "driver-btm-soc.c",0x3c9,"check_hashboard_hardware_info",chain);
          }
          fclose(pFVar5);
        }
        freq_scan_error_code_set(3,chain);
        return -1;
      }
      if (3 < log_level) {
        pFVar5 = fopen(log_file,"a+");
        if (pFVar5 != (FILE *)0x0) {
          fprintf(pFVar5,"\nread chain[%d] hardware info:\n",chain);
        }
        fclose(pFVar5);
      }
      if (3 < log_level) {
        pFVar5 = fopen(log_file,"a+");
        if (pFVar5 != (FILE *)0x0) {
          fprintf(pFVar5,"major type: %d\n",g_major_type[chain]);
        }
        fclose(pFVar5);
      }
      if (3 < log_level) {
        pFVar5 = fopen(log_file,"a+");
        if (pFVar5 != (FILE *)0x0) {
          fprintf(pFVar5,"minor type: %d\n",g_minor_type[chain]);
        }
        fclose(pFVar5);
      }
      if (3 < log_level) {
        pFVar5 = fopen(log_file,"a+");
        if (pFVar5 != (FILE *)0x0) {
          fprintf(pFVar5,"chip level: %d\n",g_bin_level[chain]);
        }
        fclose(pFVar5);
      }
      if (3 < log_level) {
        pFVar5 = fopen(log_file,"a+");
        if (pFVar5 != (FILE *)0x0) {
          fprintf(pFVar5,"bom version: 0x%02x\n",(uint)bom_version[chain]);
        }
        fclose(pFVar5);
      }
      if (3 < log_level) {
        pFVar5 = fopen(log_file,"a+");
        if (pFVar5 != (FILE *)0x0) {
          fprintf(pFVar5,"pcb version: 0x%02x\n",(uint)chain_pcb_version[chain]);
        }
        fclose(pFVar5);
      }
      if (major == 0xffff) {
        major = g_major_type[chain];
      }
      else if (major != g_major_type[chain]) {
        if (3 < log_level) {
          print_crt_time_to_file(log_file,3);
          pFVar5 = fopen(log_file,"a+");
          if (pFVar5 != (FILE *)0x0) {
            fprintf(pFVar5,
                    "%s:%d:%s: error! chain[%d] hashboard hardware info is wrong! %d != %d \n",
                    "driver-btm-soc.c",0x3d5,"check_hashboard_hardware_info",chain,major,
                    g_major_type[chain]);
          }
          fclose(pFVar5);
        }
        freq_scan_error_code_set(3,chain);
        return -1;
      }
      if (minor == 0xffff) {
        minor = g_minor_type[chain];
      }
      else if (minor != g_minor_type[chain]) {
        if (3 < log_level) {
          print_crt_time_to_file(log_file,3);
          pFVar5 = fopen(log_file,"a+");
          if (pFVar5 != (FILE *)0x0) {
            fprintf(pFVar5,
                    "%s:%d:%s: error! chain[%d] hashboard hardware info is wrong! %d != %d \n",
                    "driver-btm-soc.c",0x3d6,"check_hashboard_hardware_info",chain,minor,
                    g_minor_type[chain]);
          }
          fclose(pFVar5);
        }
        freq_scan_error_code_set(3,chain);
        return -1;
      }
      if (bin == 0xffff) {
        bin = g_bin_level[chain];
      }
      else if (bin != g_bin_level[chain]) {
        if (3 < log_level) {
          print_crt_time_to_file(log_file,3);
          pFVar5 = fopen(log_file,"a+");
          if (pFVar5 != (FILE *)0x0) {
            fprintf(pFVar5,
                    "%s:%d:%s: error! chain[%d] hashboard hardware info is wrong! %d != %d \n",
                    "driver-btm-soc.c",0x3d7,"check_hashboard_hardware_info",chain,bin,
                    g_bin_level[chain]);
          }
          fclose(pFVar5);
        }
        freq_scan_error_code_set(3,chain);
        return -1;
      }
    }
    chain = chain + 1;
  } while( true );
}

