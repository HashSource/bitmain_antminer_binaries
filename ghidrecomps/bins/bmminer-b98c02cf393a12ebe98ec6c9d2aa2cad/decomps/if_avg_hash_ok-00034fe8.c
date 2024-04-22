
bool if_avg_hash_ok(void)

{
  FILE *__stream;
  double dVar1;
  double dVar2;
  
  dVar1 = (double)getAVGhashrate();
  if (3 < log_level) {
    __stream = fopen(log_file,(char *)&DAT_0005e760);
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: avg hash rate = %f, ideal hash rate = %d\n","driver-btm-c5.c",
              0x26b1,DAT_00035098);
    }
    fclose(__stream);
  }
  dVar2 = (double)(longlong)ideal_total_hash_rate * DAT_00035090;
  return dVar1 != dVar2 && dVar1 < dVar2 == (NAN(dVar1) || NAN(dVar2));
}

