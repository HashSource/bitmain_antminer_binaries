
/* WARNING: Unknown calling convention */

void calculate_timeout(void)

{
  int iVar1;
  FILE *__stream;
  FILE *pFile;
  
  if ((config_parameter._4_1_ & 4) != 0) {
    if ((config_parameter.timeout_data_integer == '\0') &&
       (config_parameter.timeout_data_fractions == '\0')) {
      iVar1 = calculate_core_number(dev->corenum);
      iVar1 = __aeabi_idiv(0x1000000,iVar1);
      iVar1 = __aeabi_idiv((uint)dev->addrInterval * iVar1,dev->frequency);
      dev->timeout = (iVar1 * 0x5a) / 100;
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        __stream = fopen(log_file,"a+");
        if (__stream != (FILE *)0x0) {
          fprintf(__stream,"%s:%d:%s: dev->timeout = %d\n","driver-btm-soc.c",0x1b96,
                  "calculate_timeout",dev->timeout);
        }
        fclose(__stream);
      }
    }
    else {
      dev->timeout = (uint)config_parameter.timeout_data_integer * 1000 +
                     (uint)config_parameter.timeout_data_fractions;
    }
    if (0x1ffff < dev->timeout) {
      dev->timeout = 0x1ffff;
    }
  }
  return;
}

