
_Bool read_compress_log_file(log_info_t *p_info)

{
  _Bool _Var1;
  FILE *pFVar2;
  FILE *pFVar3;
  int iVar4;
  log_info_t *p_info_local;
  _Bool res;
  int ret_1;
  FILE *encoded_file;
  FILE *compressed_file_1;
  LZ4F_errorCode_t ret;
  FILE *compressed_file;
  FILE *source_file;
  
  snprintf(p_info->compressed_path,0x80,"%s.lz4",p_info);
  snprintf(p_info->encoded_path,0x80,"%s.64",p_info);
  pFVar2 = fopen(p_info->path,"rb");
  pFVar3 = fopen(p_info->compressed_path,"wb");
  if ((pFVar2 == (FILE *)0x0) || (pFVar3 == (FILE *)0x0)) {
    _Var1 = false;
  }
  else {
    iVar4 = compress_file((FILE *)pFVar2,(FILE *)pFVar3);
    fclose(pFVar2);
    fclose(pFVar3);
    if (iVar4 == 0) {
      pFVar2 = fopen(p_info->compressed_path,"rb");
      pFVar3 = fopen(p_info->encoded_path,"wb");
      iVar4 = base64_encode_file((FILE *)pFVar2,(FILE *)pFVar3);
      fclose(pFVar2);
      fclose(pFVar3);
      if (iVar4 == 0) {
        p_info->compressed = true;
        p_info->encode = true;
        _Var1 = read_log_file(p_info);
        remove(p_info->compressed_path);
        remove(p_info->encoded_path);
      }
      else {
        _Var1 = false;
      }
    }
    else {
      _Var1 = false;
    }
  }
  return _Var1;
}

