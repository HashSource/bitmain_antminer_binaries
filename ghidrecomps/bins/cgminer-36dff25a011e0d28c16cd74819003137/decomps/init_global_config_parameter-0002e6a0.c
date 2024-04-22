
int init_global_config_parameter(init_config config)

{
  uint16_t uVar1;
  undefined4 in_r0;
  FILE *pFVar2;
  undefined4 in_r1;
  undefined4 in_r2;
  undefined4 in_r3;
  int iVar3;
  FILE *pFile;
  FILE *pFile_1;
  uint16_t crc;
  
  config_parameter._16_4_ = config._0_4_;
  config_parameter.reg_data = config._4_4_;
  config_parameter._24_4_ = config._8_4_;
  config_parameter.chain_max_freq = config.frequency;
  config_parameter.crc = config.voltage;
  config_parameter.token_type = (uint8_t)in_r0;
  config_parameter._0_4_ = in_r0;
  config_parameter._4_4_ = in_r1;
  config_parameter._8_4_ = in_r2;
  config_parameter._12_4_ = in_r3;
  if (config_parameter.token_type == 'Q') {
    uVar1 = CRC16(&config_parameter.token_type,0x1e);
    if (uVar1 == config_parameter.crc) {
      iVar3 = 0;
    }
    else {
      if (4 < log_level) {
        print_crt_time_to_file(log_file,4);
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: config_parameter.crc = 0x%x, but we calculate it as 0x%x\n",
                  "driver-btm-soc.c",0x1b22,"init_global_config_parameter",
                  (uint)config_parameter._28_4_ >> 0x10,(uint)uVar1);
        }
        fclose(pFVar2);
      }
      iVar3 = -2;
    }
  }
  else {
    if (4 < log_level) {
      print_crt_time_to_file(log_file,4);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: config_parameter.token_type != 0x%x, it is 0x%x\n",
                "driver-btm-soc.c",0x1b1b,"init_global_config_parameter",0x51,
                config_parameter._0_4_ & 0xff);
      }
      fclose(pFVar2);
    }
    iVar3 = -1;
  }
  return iVar3;
}

