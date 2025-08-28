
int init_global_config_parameter(init_config config)

{
  undefined4 uVar1;
  undefined2 uVar2;
  FILE *pFile;
  FILE *pFile_1;
  uint16_t crc;
  
  config_parameter._0_4_ = config._0_4_;
  uVar1 = config_parameter._0_4_;
  config_parameter._4_4_ = config._4_4_;
  config_parameter._8_4_ = config._8_4_;
  config_parameter._12_4_ = config._12_4_;
  config._16_4_ = config._16_4_;
  config.reg_data = config.reg_data;
  config._24_4_ = config._24_4_;
  config._28_4_ = config._28_4_;
  config_parameter.chain_check_time_integer = config.chain_check_time_integer;
  config_parameter.chain_check_time_fractions = config.chain_check_time_fractions;
  config_parameter.timeout_data_integer = config.timeout_data_integer;
  config_parameter.timeout_data_fractions = config.timeout_data_fractions;
  config_parameter.reg_data = config.reg_data;
  config_parameter.chip_address = config.chip_address;
  config_parameter.reg_address = config.reg_address;
  config_parameter.chain_min_freq = config.chain_min_freq;
  config_parameter.chain_max_freq = config.chain_max_freq;
  config_parameter.crc = config.crc;
  config_parameter.token_type = config.token_type;
  config_parameter._0_4_ = uVar1;
  if (config_parameter.token_type == 'Q') {
    config._0_2_ = CRC16(&config_parameter.token_type,0x1e);
    uVar2 = config._0_2_;
    if (config._0_2_ == config_parameter.crc) {
      config.frequency = 0;
      config.voltage = 0;
    }
    else {
      if (4 < log_level) {
        print_crt_time_to_file(log_file,4);
        config._0_4_ = fopen(log_file,"a+");
        uVar1 = config._0_4_;
        if (config._0_4_ != 0) {
          config.voltage = 0;
          config.token_type = (uint8_t)uVar2;
          config.version = SUB21(uVar2,1);
          config.frequency._0_1_ = config.token_type;
          config.frequency._1_1_ = config.version;
          fprintf((FILE *)uVar1,
                  "%s:%d:%s: config_parameter.crc = 0x%x, but we calculate it as 0x%x\n",
                  "driver-btm-soc.c",0x1b22,"init_global_config_parameter",
                  (uint)config_parameter._28_4_ >> 0x10,config._12_4_);
        }
        fclose((FILE *)uVar1);
      }
      config.frequency = 0xfffe;
      config.voltage = 0xffff;
    }
  }
  else {
    if (4 < log_level) {
      print_crt_time_to_file(log_file,4);
      config._0_4_ = fopen(log_file,"a+");
      if (config._0_4_ != 0) {
        config._12_4_ = config_parameter._0_4_ & 0xff;
        fprintf((FILE *)config._0_4_,"%s:%d:%s: config_parameter.token_type != 0x%x, it is 0x%x\n",
                "driver-btm-soc.c",0x1b1b,"init_global_config_parameter",0x51,config._12_4_);
      }
      fclose((FILE *)config._0_4_);
    }
    config.frequency = 0xffff;
    config.voltage = 0xffff;
  }
  config._0_4_ = config._12_4_;
  return config._0_4_;
}

