
_Bool register_process_core_response(int chain,uint8_t asic,core_reg_status_t *core_reg_status)

{
  byte bVar1;
  uint uVar2;
  byte bVar3;
  FILE *pFVar4;
  uint uVar5;
  core_reg_status_t *core_reg_status_local;
  uint8_t asic_local;
  int chain_local;
  FILE *pFile;
  FILE *pFile_1;
  uint8_t asic_from_reg;
  uint32_t reg_buf;
  uint8_t reg;
  uint32_t reg_value_num;
  int i;
  _Bool found;
  
  uVar2 = reg_value_buf.reg_value_num;
  found = false;
  i = 0;
  while (((uint)i < uVar2 && (found != true))) {
    bVar1 = reg_value_buf.reg_buffer[reg_value_buf.p_rd].reg_address;
    uVar5 = reg_value_buf.reg_buffer[reg_value_buf.p_rd].reg_value;
    bVar3 = __udivsi3(reg_value_buf.reg_buffer[reg_value_buf.p_rd].chip_address,dev->addrInterval);
    if (bVar1 == 0x40) {
      if ((chain == (uint)reg_value_buf.reg_buffer[reg_value_buf.p_rd].chain_number) &&
         (bVar3 == asic)) {
        core_reg_status->reg_response = uVar5;
      }
      else if (3 < log_level) {
        print_crt_time_to_file(register_file_str,3);
        pFVar4 = fopen(register_file_str,"a+");
        if (pFVar4 != (FILE *)0x0) {
          fprintf(pFVar4,"%s:%d:%s: Get another core response: chain = %d, asic = %d\n","register.c"
                  ,0x100,"register_process_core_response",
                  (uint)reg_value_buf.reg_buffer[reg_value_buf.p_rd].chain_number,(uint)bVar3);
        }
        fclose(pFVar4);
      }
      found = true;
    }
    else if (3 < log_level) {
      print_crt_time_to_file(register_file_str,3);
      pFVar4 = fopen(register_file_str,"a+");
      if (pFVar4 != (FILE *)0x0) {
        fprintf(pFVar4,"%s:%d:%s: Get another register: 0x%X\n","register.c",0x107,
                "register_process_core_response",(uint)bVar1);
      }
      fclose(pFVar4);
    }
    reg_value_buf.p_rd = reg_value_buf.p_rd + 1;
    reg_value_buf.reg_value_num = reg_value_buf.reg_value_num - 1;
    if (0x1fe < reg_value_buf.p_rd) {
      reg_value_buf.p_rd = 0;
    }
    i = i + 1;
  }
  return found;
}

