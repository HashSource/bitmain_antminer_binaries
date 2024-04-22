
/* WARNING: Unknown calling convention */

void clear_queue(void)

{
  FILE *pFVar1;
  FILE *pFile_1;
  FILE *pFile;
  
  thash_index = 0;
  length = 0;
  memset(thashrate_array,0,0x208);
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d:%s: reset calc...\n","hash_rate.c",0x3a,"clear_queue");
    }
    fclose(pFVar1);
  }
  if (4 < log_level) {
    print_crt_time_to_file(log_file,4);
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d:%s: thash_index = %d,length = %d\n","hash_rate.c",0x3b,"clear_queue",
              thash_index,length);
    }
    fclose(pFVar1);
  }
  return;
}

