
_Bool data_enc(uint32_t *buf,uint32_t len,uint8_t algorithm_type,uint8_t key_version)

{
  _Bool _Var1;
  uint8_t key_version_local;
  uint8_t algorithm_type_local;
  uint32_t len_local;
  uint32_t *buf_local;
  char time_stamp [48];
  char tmp1 [2048];
  
  if (key_version < 4) {
    if (algorithm_type == '\x01') {
      if ((len & 7) == 0) {
        xxtea_encode(buf,len >> 2,xxtea_key[key_version]);
        _Var1 = true;
      }
      else {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s:  xxtea input data length %% 8 must be 0, but now is %d\n","data_enc",len & 7);
        snprintf(tmp1,0x800," xxtea input data length %% 8 must be 0, but now is %d",len & 7);
        log_to_file(tmp1,time_stamp);
        _Var1 = false;
      }
    }
    else {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: algorithm_type is %d, but not support it\n","data_enc",(uint)algorithm_type);
      snprintf(tmp1,0x800,"algorithm_type is %d, but not support it",(uint)algorithm_type);
      log_to_file(tmp1,time_stamp);
      _Var1 = false;
    }
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: key_version %u not support\n","data_enc",(uint)key_version);
    snprintf(tmp1,0x800,"key_version %u not support",(uint)key_version);
    log_to_file(tmp1,time_stamp);
    _Var1 = false;
  }
  return _Var1;
}

