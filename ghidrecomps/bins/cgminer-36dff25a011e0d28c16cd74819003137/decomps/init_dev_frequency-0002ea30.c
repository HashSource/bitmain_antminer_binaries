
/* WARNING: Unknown calling convention */

void init_dev_frequency(void)

{
  all_parameters *paVar1;
  _Bool _Var2;
  FILE *__stream;
  FILE *pFile;
  
  _Var2 = is_fixed_freq_mode();
  paVar1 = dev;
  if ((_Var2) && ((config_parameter._4_1_ & 8) != 0)) {
    dev->frequency = config_parameter.frequency;
    sprintf(dev->frequency_t,"%u",(uint)dev->frequency);
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      __stream = fopen(log_file,"a+");
      if (__stream != (FILE *)0x0) {
        fprintf(__stream,"%s:%d:%s: fixd frequency is %d\n","driver-btm-soc.c",0x1b51,
                "init_dev_frequency",(uint)dev->frequency);
      }
      fclose(__stream);
    }
  }
  else {
    *(undefined *)&dev->frequency = 0x13;
    *(undefined *)((int)&paVar1->frequency + 1) = 1;
  }
  return;
}

