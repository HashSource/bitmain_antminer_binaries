
/* WARNING: Unknown calling convention */

int check_nonce_rate(void)

{
  int iVar1;
  float fVar2;
  char time_stamp [48];
  char tmp1 [256];
  float nonce_rate;
  
  fVar2 = (float)g_rt.asic_stats.valid_nonce_num /
          (float)(longlong)
                 ((g_rt.config)->patter_num * (g_rt.config)->asic_small_cores * (g_rt.config)->asics
                 );
  if ((int)(fVar2 * 10000.0) < ((g_rt.config)->standard).nonce_rate) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : warning current nonce_rate:%f  standard nonce_rate:%d \n","check_nonce_rate",
           SUB84((double)fVar2,0),(int)((ulonglong)(double)fVar2 >> 0x20),
           ((g_rt.config)->standard).nonce_rate);
    iVar1 = ((g_rt.config)->standard).nonce_rate;
    snprintf(tmp1,0x100,"warning current nonce_rate:%f  standard nonce_rate:%d ",iVar1,(double)fVar2
             ,iVar1);
    log_to_file(tmp1,time_stamp);
    iVar1 = -1;
  }
  else {
    g_rt.nonce_rate = fVar2;
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : nonce_rate:%f\n","check_nonce_rate",SUB84((double)fVar2,0),
           (int)((ulonglong)(double)fVar2 >> 0x20));
    snprintf(tmp1,0x100,"nonce_rate:%f",tmp1,(double)fVar2);
    log_to_file(tmp1,time_stamp);
    iVar1 = 0;
  }
  return iVar1;
}

