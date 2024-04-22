
/* WARNING: Unknown calling convention */

void clear_probability_file(void)

{
  FILE *pFVar1;
  FILE *fd;
  
  pFVar1 = fopen("/config/reopen_algorithm_static_parameters.config","wb");
  if (pFVar1 != (FILE *)0x0) {
    fclose(pFVar1);
    remove("/config/reopen_algorithm_static_parameters.config");
  }
  pFVar1 = fopen("/config/reopen_algorithm_efficient_normal_temp_parameters.config","wb");
  if (pFVar1 != (FILE *)0x0) {
    fclose(pFVar1);
    remove("/config/reopen_algorithm_efficient_normal_temp_parameters.config");
  }
  pFVar1 = fopen("/config/reopen_algorithm_efficient_low_temp_parameters.config","wb");
  if (pFVar1 != (FILE *)0x0) {
    fclose(pFVar1);
    remove("/config/reopen_algorithm_efficient_low_temp_parameters.config");
  }
  pFVar1 = fopen("/config/reopen_algorithm_high_power_normal_temp_parameters.config","wb");
  if (pFVar1 != (FILE *)0x0) {
    fclose(pFVar1);
    remove("/config/reopen_algorithm_high_power_normal_temp_parameters.config");
  }
  pFVar1 = fopen("/config/reopen_algorithm_high_power_low_temp_parameters.config","wb");
  if (pFVar1 != (FILE *)0x0) {
    fclose(pFVar1);
    remove("/config/reopen_algorithm_high_power_low_temp_parameters.config");
  }
  return;
}

