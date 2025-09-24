
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void fix_pattern_file(void)

{
  FILE *__stream;
  FILE *__s;
  size_t sVar1;
  char time_stamp [48];
  char tmp1 [256];
  pattern_struct_in_file work_in_file;
  int fsize;
  FILE *fp_w;
  FILE *fp_r;
  int pattern;
  int core;
  int asic;
  
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s :  \n","fix_pattern_file");
  tmp1[0] = ' ';
  tmp1[1] = '\0';
  log_to_file(tmp1,time_stamp);
  __stream = fopen("/mnt/card/BM1368-pattern/pattern_16midstate.bin","r");
  __s = fopen("/mnt/card/BM1368-pattern/pattern_16midstate_1376.bin","rw");
  for (asic = 0; asic < 0xd8; asic = asic + 1) {
    for (core = 0; core < 0x500; core = core + 1) {
      for (pattern = 0; pattern < 8; pattern = pattern + 1) {
        sVar1 = fread(&work_in_file,1,0xc,__stream);
        if (sVar1 != 0xc) {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : read pattern err.\n","fix_pattern_file");
          builtin_strncpy(tmp1,"read pattern err",0x10);
          tmp1[0x10] = '.';
          tmp1[0x11] = '\0';
          log_to_file(tmp1,time_stamp);
        }
        if (core < 0x4fc) {
          sVar1 = fwrite(&work_in_file,1,0xc,__s);
          if (sVar1 != 0xc) {
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            printf("%s : write pattern err.\n","fix_pattern_file");
            builtin_strncpy(tmp1,"write pattern er",0x10);
            tmp1[0x10] = 'r';
            tmp1[0x11] = '.';
            tmp1[0x12] = '\0';
            log_to_file(tmp1,time_stamp);
          }
        }
      }
    }
  }
  fclose(__stream);
  fclose(__s);
  return;
}

