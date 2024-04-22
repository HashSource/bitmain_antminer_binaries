
void process_true_data(float param_1,int param_2,int param_3)

{
  FILE *__stream;
  char acStack_e8 [204];
  
  if (7 < log_level) {
    __stream = fopen(log_file,(char *)&DAT_0005e760);
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: true_data = %f, i = %d\n","xadc.c",0xb7,DAT_0004bca0);
    }
    fclose(__stream);
  }
  switch(param_3) {
  case 5:
    if (param_1 != DAT_0004bc90 && param_1 < DAT_0004bc90 == (NAN(param_1) || NAN(DAT_0004bc90))) {
      sprintf(acStack_e8,"WARNING : %s is %f cent\n",*(int *)(param_2 + 0x14) + 0xb,param_3 + -5,
              (double)param_1);
      write_log_file(*(int *)(param_2 + 0x14) + 0xb,acStack_e8);
    }
    if (first_time_6468 == '\0') {
      return;
    }
    first_time_6468 = 0;
    sprintf(acStack_e8,"XADC checking when system bring up : %s is %f cent\n",
            *(int *)(param_2 + 0x14) + 0xb,&first_time_6468,(double)param_1);
    write_log_file("xadc_test",acStack_e8);
    return;
  case 0xf:
    break;
  case 0x11:
    break;
  case 0x13:
  }
  check_voltage(param_2,param_3);
  return;
}

