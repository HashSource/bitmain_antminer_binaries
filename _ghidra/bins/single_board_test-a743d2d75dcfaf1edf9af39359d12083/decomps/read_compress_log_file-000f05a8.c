
_Bool read_compress_log_file(log_info_t *p_info)

{
  _Bool _Var1;
  FILE *pFVar2;
  FILE *pFVar3;
  LZ4F_errorCode_t code;
  char *pcVar4;
  int iVar5;
  size_t sVar6;
  size_t sVar7;
  size_t sVar8;
  size_t sVar9;
  size_t sVar10;
  log_info_t *p_info_local;
  char tmp42 [2048];
  _Bool res;
  int ret_1;
  FILE *encoded_file;
  FILE *compressed_file_1;
  LZ4F_errorCode_t ret;
  FILE *compressed_file;
  FILE *source_file;
  
  snprintf(p_info->compressed_path,0x80,"%s.lz4",p_info);
  snprintf(p_info->encoded_path,0x80,"%s.64",p_info);
  snprintf(tmp42,0x800,"source_file:%s\n",p_info);
  _applog(5,tmp42,false);
  snprintf(tmp42,0x800,"compressed_file:%s\n",p_info->compressed_path);
  _applog(5,tmp42,false);
  snprintf(tmp42,0x800,"encoded_file:%s\n",p_info->encoded_path);
  _applog(5,tmp42,false);
  pFVar2 = fopen(p_info->path,"rb");
  pFVar3 = fopen(p_info->compressed_path,"wb");
  if (pFVar2 == (FILE *)0x0) {
    snprintf(tmp42,0x800,"file not exist: %s\n",p_info);
    _applog(5,tmp42,false);
    _Var1 = false;
  }
  else {
    code = compress_file((FILE *)pFVar2,(FILE *)pFVar3);
    fclose(pFVar2);
    fclose(pFVar3);
    if (code == 0) {
      pFVar2 = fopen(p_info->compressed_path,"rb");
      pFVar3 = fopen(p_info->encoded_path,"wb");
      snprintf(tmp42,0x800,"base64 encode: %s -> %s \n",p_info->compressed_path,p_info->encoded_path
              );
      _applog(5,tmp42,false);
      iVar5 = base64_encode_file((FILE *)pFVar2,(FILE *)pFVar3);
      fclose(pFVar2);
      fclose(pFVar3);
      if (iVar5 == 0) {
        sVar6 = get_file_size(p_info->path);
        sVar7 = get_file_size(p_info->compressed_path);
        sVar8 = get_file_size(p_info->encoded_path);
        sVar9 = get_file_size(p_info->encoded_path);
        sVar10 = get_file_size(p_info->path);
        snprintf(tmp42,0x800,"origin sz:%d,compress sz:%d,encode sz:%d,rate:%.1f%%\n",sVar6,sVar7,
                 sVar8,((double)sVar9 / (double)sVar10) * 100.0);
        _applog(5,tmp42,false);
        p_info->compressed = true;
        p_info->encode = true;
        _Var1 = read_log_file(p_info);
        remove(p_info->compressed_path);
        remove(p_info->encoded_path);
      }
      else {
        builtin_strncpy(tmp42,"base64 encode error.",0x14);
        tmp42[0x14] = '\n';
        tmp42[0x15] = '\0';
        _applog(5,tmp42,false);
        _Var1 = false;
      }
    }
    else {
      pcVar4 = LZ4F_getErrorName(code);
      snprintf(tmp42,0x800,"compression error: %s\n",pcVar4);
      _applog(5,tmp42,false);
      _Var1 = false;
    }
  }
  return _Var1;
}

