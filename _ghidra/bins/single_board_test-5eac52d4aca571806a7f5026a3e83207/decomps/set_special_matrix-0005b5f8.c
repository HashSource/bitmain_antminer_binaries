
void set_special_matrix(pattern_runtime_ctx *runtime,float *matrix)

{
  char *pcVar1;
  float *matrix_local;
  pattern_runtime_ctx *runtime_local;
  char time_stamp [48];
  char tmp1 [256];
  int i;
  
  pcVar1 = strstr(ft,"F1V01B5C1-4");
  if (pcVar1 != (char *)0x0) {
    for (i = 0; i < runtime->config->asics; i = i + 1) {
      matrix[i] = matrix[i] / runtime->nonce_rate;
    }
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : sweep matrix add, becauce of nonce rate %f\n","set_special_matrix",
           SUB84((double)runtime->nonce_rate,0),
           (int)((ulonglong)(double)runtime->nonce_rate >> 0x20));
    snprintf(tmp1,0x100,"sweep matrix add, becauce of nonce rate %f",tmp1,
             (double)runtime->nonce_rate);
    log_to_file(tmp1,time_stamp);
  }
  return;
}

