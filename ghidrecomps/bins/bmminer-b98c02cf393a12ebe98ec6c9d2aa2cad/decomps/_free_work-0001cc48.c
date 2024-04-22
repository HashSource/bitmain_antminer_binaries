
void _free_work(void **param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  void *__ptr;
  
  __ptr = *param_1;
  if (__ptr == (void *)0x0) {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
      _free_work_part_36(param_2,param_3,param_4,param_4);
      return;
    }
  }
  else {
    clean_work(__ptr);
    free(__ptr);
    *param_1 = (void *)0x0;
  }
  return;
}

