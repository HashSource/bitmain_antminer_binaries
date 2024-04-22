
void register_dump_asic_reg(uint8_t asic_reg,reg_status_t *reg_status)

{
  FILE *__stream;
  reg_status_t *reg_status_local;
  uint8_t asic_reg_local;
  FILE *pFile;
  
  if (asic_reg == '\0') {
    register_parse_chip_address(reg_status);
  }
  else if (asic_reg == '\x04') {
    register_parse_hash_rate(reg_status);
  }
  else if (asic_reg == '\b') {
    register_parse_pll0_parameter(reg_status);
  }
  else if (asic_reg == '\f') {
    register_parse_chip_nonce_offset(reg_status);
  }
  else if (asic_reg == '\x10') {
    register_parse_hash_counting_number(reg_status);
  }
  else if (asic_reg == '\x14') {
    register_parse_ticket_mask(reg_status);
  }
  else if (asic_reg == '\x18') {
    register_parse_misc_control(reg_status);
  }
  else if (asic_reg == ' ') {
    register_parse_ordered_clock_enable(reg_status);
  }
  else if (asic_reg == '8') {
    register_parse_ticket_mask2(reg_status);
  }
  else if (asic_reg == 'D') {
    register_parse_external_temperature_sensor_read(reg_status);
  }
  else if (asic_reg == 'H') {
    register_parse_error_flag(reg_status);
  }
  else if (asic_reg == 'L') {
    register_parse_nonce_error_counter(reg_status);
  }
  else if (asic_reg == 'P') {
    register_parse_nonce_overflow_counter(reg_status);
  }
  else if (asic_reg == 'T') {
    register_parse_analog_mux_control(reg_status);
  }
  else if (asic_reg == 'X') {
    register_parse_io_drive_strength_configuration(reg_status);
  }
  else if (asic_reg == '\\') {
    register_parse_time_out(reg_status);
  }
  else if (asic_reg == '`') {
    register_parse_pll1_parameter(reg_status);
  }
  else if (asic_reg == 'd') {
    register_parse_pll2_parameter(reg_status);
  }
  else if (asic_reg == 'h') {
    register_parse_pll3_parameter(reg_status);
  }
  else if (asic_reg == 'l') {
    register_parse_ordered_clock_monitor(reg_status);
  }
  else if (asic_reg == 'p') {
    register_parse_pll0_divider(reg_status);
  }
  else if (asic_reg == 't') {
    register_parse_pll1_divider(reg_status);
  }
  else if (asic_reg == 'x') {
    register_parse_pll2_divider(reg_status);
  }
  else if (asic_reg == '|') {
    register_parse_pll3_divider(reg_status);
  }
  else if (asic_reg == 0x80) {
    register_parse_clock_order_0(reg_status);
  }
  else if (asic_reg == 0x84) {
    register_parse_clock_order_1(reg_status);
  }
  else if (asic_reg == 0x90) {
    register_parse_frequency_sweep_control(reg_status);
  }
  else if (asic_reg == 0x94) {
    register_parse_golden_nonce_for_sweep_return(reg_status);
  }
  else if (asic_reg == 0x98) {
    register_parse_returned_group_pattern_status(reg_status);
  }
  else if (asic_reg == 0x9c) {
    register_parse_nonce_returned_timeout(reg_status);
  }
  else if (asic_reg == 0xa0) {
    register_parse_returned_single_pattern_status(reg_status);
  }
  else if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: Unknown reg: %d\n","register.c",0x4af,"register_dump_asic_reg",
              (uint)asic_reg);
    }
    fclose(__stream);
  }
  return;
}

