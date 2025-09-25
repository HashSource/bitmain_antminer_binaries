
int set_special_avg_matrix(pattern_runtime_ctx *runtime,int avg)

{
  char *pcVar1;
  int avg_local;
  pattern_runtime_ctx *runtime_local;
  char time_stamp [48];
  char tmp1 [256];
  
  pcVar1 = strstr(ft,"F1V01B5C1-4");
  if (pcVar1 != (char *)0x0) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : sweep avg reduce, becauce of nonce rate %f\n","set_special_avg_matrix",
           SUB84((double)runtime->nonce_rate,0),
           (int)((ulonglong)(double)runtime->nonce_rate >> 0x20));
    snprintf(tmp1,0x100,"sweep avg reduce, becauce of nonce rate %f",tmp1,
             (double)runtime->nonce_rate);
    log_to_file(tmp1,time_stamp);
    avg = (int)((float)(longlong)avg * runtime->nonce_rate);
  }
  return avg;
}

