
int32_t skip_rows(FILE *asic_pattern_file_handle,int skip_count)

{
  size_t sVar1;
  int skip_count_local;
  FILE *asic_pattern_file_handle_local;
  char time_stamp [48];
  char tmp1 [256];
  test_pattern_new skip_pattern;
  int32_t ret;
  
  skip_count_local = skip_count;
  do {
    if (skip_count_local == 0) {
      return 0;
    }
    sVar1 = fread(&skip_pattern,1,0xc,(FILE *)asic_pattern_file_handle);
    skip_count_local = skip_count_local + -1;
  } while (sVar1 == 0xc);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : skip pattern from file error!\n","skip_rows");
  builtin_strncpy(tmp1,"skip pattern from file error",0x1c);
  tmp1[0x1c] = '!';
  tmp1[0x1d] = '\0';
  log_to_file(tmp1,time_stamp);
  return 0;
}

