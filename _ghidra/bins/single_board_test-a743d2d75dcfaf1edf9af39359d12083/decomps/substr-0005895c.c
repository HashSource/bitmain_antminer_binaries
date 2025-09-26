
_Bool substr(char *src,uint32_t start,uint32_t length,char *dest)

{
  size_t sVar1;
  _Bool _Var2;
  char *dest_local;
  uint32_t length_local;
  uint32_t start_local;
  char *src_local;
  char time_stamp [48];
  char tmp1 [2048];
  uint32_t source_string_length;
  uint32_t i;
  
  sVar1 = strlen(src);
  if (sVar1 < start + length) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: You want copy to many chars\n","substr");
    builtin_strncpy(tmp1,"You want copy to many chars",0x1c);
    log_to_file(tmp1,time_stamp);
    _Var2 = false;
  }
  else {
    for (i = 0; i < length; i = i + 1) {
      dest[i] = src[i + start];
    }
    dest[i] = '\0';
    _Var2 = true;
  }
  return _Var2;
}

