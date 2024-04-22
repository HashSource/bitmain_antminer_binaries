
_Bool register_process_asic_response(int chain,uint8_t asic,uint8_t reg,uint32_t *response)

{
  uchar uVar1;
  byte bVar2;
  uint uVar3;
  byte bVar4;
  FILE *pFVar5;
  uint uVar6;
  uint32_t *response_local;
  uint8_t reg_local;
  uint8_t asic_local;
  int chain_local;
  FILE *pFile;
  FILE *pFile_1;
  uint8_t asic_from_reg;
  uint8_t chain_number;
  uint32_t reg_value;
  uint8_t reg_address;
  uint32_t reg_value_num;
  uint32_t i;
  _Bool found;
  
  uVar3 = reg_value_buf.reg_value_num;
  found = false;
  i = 0;
  while ((i < uVar3 && (found != true))) {
    uVar1 = reg_value_buf.reg_buffer[reg_value_buf.p_rd].reg_address;
    uVar6 = reg_value_buf.reg_buffer[reg_value_buf.p_rd].reg_value;
    bVar2 = reg_value_buf.reg_buffer[reg_value_buf.p_rd].chain_number;
    bVar4 = __udivsi3(reg_value_buf.reg_buffer[reg_value_buf.p_rd].chip_address,dev->addrInterval);
    if (uVar1 == reg) {
      if ((chain == (uint)bVar2) && (bVar4 == asic)) {
        *response = uVar6;
      }
      else if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar5 = fopen(log_file,"a+");
        if (pFVar5 != (FILE *)0x0) {
          fprintf(pFVar5,"%s:%d:%s: Get another asic response: chain = %d, asic = %d\n","register.c"
                  ,0x39b,"register_process_asic_response",(uint)bVar2,(uint)bVar4);
        }
        fclose(pFVar5);
      }
      found = true;
    }
    else if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar5 = fopen(log_file,"a+");
      if (pFVar5 != (FILE *)0x0) {
        fprintf(pFVar5,"%s:%d:%s: Get another register: 0x%X\n","register.c",0x3a2,
                "register_process_asic_response",(uint)reg);
      }
      fclose(pFVar5);
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

