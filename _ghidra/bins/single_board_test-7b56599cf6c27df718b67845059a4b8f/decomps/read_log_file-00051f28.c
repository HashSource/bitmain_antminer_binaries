
_Bool read_log_file(log_info_t *p_info)

{
  size_t __size;
  char *pcVar1;
  size_t sVar2;
  log_info_t *p_info_local;
  int read_len;
  int file_size;
  char *path_str;
  _Bool res;
  FILE *file;
  
  file = (FILE *)0x0;
  res = false;
  if (p_info->encode == false) {
    path_str = p_info->path;
    if (p_info->compressed != false) {
      path_str = p_info->encoded_path;
    }
  }
  else {
    path_str = p_info->encoded_path;
  }
  if (path_str != (char *)0x0) {
    file = (FILE *)fopen(path_str,"r");
  }
  if (file != (FILE *)0x0) {
    fseek((FILE *)file,0,2);
    __size = ftell((FILE *)file);
    fseek((FILE *)file,0,0);
    if (__size != 0) {
      pcVar1 = (char *)malloc(__size);
      p_info->data = pcVar1;
      if (p_info->data != (char *)0x0) {
        memset(p_info->data,0,__size);
        sVar2 = fread(p_info->data,1,__size,(FILE *)file);
        if (sVar2 == __size) {
          p_info->origin_size = sVar2;
          p_info->filter_size = p_info->origin_size;
          res = true;
        }
        else {
          free(p_info->data);
        }
      }
    }
    fclose((FILE *)file);
  }
  return res;
}

