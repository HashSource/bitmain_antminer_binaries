
_Bool read_encode_log_file(log_info_t *p_info)

{
  _Bool _Var1;
  FILE *f_in;
  FILE *f_out;
  int iVar2;
  size_t sVar3;
  size_t sVar4;
  log_info_t *p_info_local;
  char tmp42 [2048];
  _Bool res;
  int ret;
  FILE *encoded_file;
  FILE *origin_file;
  
  snprintf(p_info->encoded_path,0x80,"%s.64",p_info);
  snprintf(tmp42,0x800,"source_file:%s\n",p_info);
  _applog(5,tmp42,false);
  snprintf(tmp42,0x800,"encoded_file:%s\n",p_info->encoded_path);
  _applog(5,tmp42,false);
  f_in = fopen(p_info->path,"rb");
  f_out = fopen(p_info->encoded_path,"wb");
  snprintf(tmp42,0x800,"base64 encode: %s -> %s \n",p_info,p_info->encoded_path);
  _applog(5,tmp42,false);
  iVar2 = base64_encode_file((FILE *)f_in,(FILE *)f_out);
  fclose(f_in);
  fclose(f_out);
  if (iVar2 == 0) {
    sVar3 = get_file_size(p_info->path);
    sVar4 = get_file_size(p_info->encoded_path);
    get_file_size(p_info->encoded_path);
    get_file_size(p_info->path);
    snprintf(tmp42,0x800,"origin sz:%d,encode sz:%d,rate:%.1f%%\n",sVar3,sVar4);
    _applog(5,tmp42,false);
    p_info->encode = true;
    _Var1 = read_log_file(p_info);
    remove(p_info->encoded_path);
  }
  else {
    builtin_strncpy(tmp42,"base64 encode error.",0x14);
    tmp42[0x14] = '\n';
    tmp42[0x15] = '\0';
    _applog(5,tmp42,false);
    _Var1 = false;
  }
  return _Var1;
}

