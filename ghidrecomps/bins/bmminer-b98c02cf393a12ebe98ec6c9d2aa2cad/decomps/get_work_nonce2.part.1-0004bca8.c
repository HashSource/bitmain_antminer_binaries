
void get_work_nonce2_part_1(undefined4 *param_1)

{
  FILE *__stream;
  
  __stream = fopen(log_file,(char *)&DAT_0005e760);
  if (__stream != (FILE *)0x0) {
    fprintf(__stream,"%s:%d:%s: WORK_NONCE_2 buf[0]: 0x%x, buf[1]: 0x%x\n","znyq7010.c",0x2c6,
            "get_work_nonce2",*param_1,param_1[1]);
  }
  (*(code *)PTR_fclose_0007cfe8)(__stream);
  return;
}

