
/* WARNING: Unknown calling convention */

_Bool freq_tuning_alloc_works_buffer(void)

{
  freq_tuning_work *pfVar1;
  FILE *__stream;
  FILE *pFile;
  _Bool ret;
  int asic;
  
  ret = true;
  memset(g_works,0,0xc0);
  asic = 0;
  do {
    if (0x2f < asic) {
LAB_0001c8bc:
      if (ret != true) {
        freq_tuning_free_works_buffer();
      }
      return ret;
    }
    pfVar1 = (freq_tuning_work *)
             _cgmalloc(0x8880,"freq_tuning.c","freq_tuning_alloc_works_buffer",0xb3f);
    g_works[asic] = pfVar1;
    if (g_works[asic] == (freq_tuning_work *)0x0) {
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        __stream = fopen(log_file,"a+");
        if (__stream != (FILE *)0x0) {
          fprintf(__stream,"%s:%d:%s: Fail to allocate buffer for works!\n","freq_tuning.c",0xb42,
                  "freq_tuning_alloc_works_buffer");
        }
        fclose(__stream);
      }
      ret = false;
      goto LAB_0001c8bc;
    }
    asic = asic + 1;
  } while( true );
}

