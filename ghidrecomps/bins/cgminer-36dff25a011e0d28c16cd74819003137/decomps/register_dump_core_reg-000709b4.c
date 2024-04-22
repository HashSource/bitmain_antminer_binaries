
void register_dump_core_reg(uint8_t core_reg,reg_status_t *reg_status)

{
  FILE *__stream;
  reg_status_t *reg_status_local;
  uint8_t core_reg_local;
  FILE *pFile;
  
  if (core_reg == '\0') {
    register_parse_clock_delay_ctrl(reg_status);
  }
  else if (core_reg == '\x01') {
    register_parse_process_monitor_ctrl(reg_status);
  }
  else if (core_reg == '\x02') {
    register_parse_process_monitor_data(reg_status);
  }
  else if (core_reg == '\x03') {
    register_parse_core_error(reg_status);
  }
  else if (core_reg == '\x04') {
    register_parse_core_enable(reg_status);
  }
  else if (core_reg == '\x05') {
    register_parse_hash_clock_ctrl(reg_status);
  }
  else if (core_reg == '\x06') {
    register_parse_hash_clock_counter(reg_status);
  }
  else if (core_reg == '\a') {
    register_parse_sweep_freq_ctrl(reg_status);
  }
  else if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: Unknown reg: %d\n","register.c",0x42b,"register_dump_core_reg",
              (uint)core_reg);
    }
    fclose(__stream);
  }
  return;
}

