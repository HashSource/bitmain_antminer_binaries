
bool if_avg_hash_ok(void)

{
  FILE *__stream;
  undefined4 uVar1;
  undefined4 extraout_s1;
  
  uVar1 = getAVGhashrate();
  if (3 < log_level) {
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: avg hash rate = %f, ideal hash rate = %d\n","driver-btm-c5.c",
              0x26b1,"if_avg_hash_ok");
    }
    fclose(__stream);
  }
  return (double)(longlong)ideal_total_hash_rate * 0.99 < (double)CONCAT44(extraout_s1,uVar1);
}

