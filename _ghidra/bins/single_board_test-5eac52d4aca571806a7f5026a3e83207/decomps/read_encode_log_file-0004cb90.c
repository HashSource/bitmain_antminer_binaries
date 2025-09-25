
_Bool read_encode_log_file(log_info_t *p_info)

{
  _Bool _Var1;
  FILE *f_in;
  FILE *f_out;
  int iVar2;
  log_info_t *p_info_local;
  _Bool res;
  int ret;
  FILE *encoded_file;
  FILE *origin_file;
  
  snprintf(p_info->encoded_path,0x80,"%s.64",p_info);
  f_in = fopen(p_info->path,"rb");
  f_out = fopen(p_info->encoded_path,"wb");
  iVar2 = base64_encode_file((FILE *)f_in,(FILE *)f_out);
  fclose(f_in);
  fclose(f_out);
  if (iVar2 == 0) {
    p_info->encode = true;
    _Var1 = read_log_file(p_info);
    remove(p_info->encoded_path);
  }
  else {
    _Var1 = false;
  }
  return _Var1;
}

