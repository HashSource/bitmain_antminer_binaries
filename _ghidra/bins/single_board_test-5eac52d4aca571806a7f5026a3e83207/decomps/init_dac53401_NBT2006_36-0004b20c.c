
_Bool init_dac53401_NBT2006_36(uint8_t which_chain)

{
  _Bool _Var1;
  uint8_t which_chain_local;
  char time_stamp [48];
  char tmp1 [256];
  uint8_t data [2];
  uint8_t gain;
  uint8_t ref_en;
  
  data[0] = '\0';
  data[1] = '\0';
  _Var1 = read_dac(which_chain,'\x01',0xd1,data,2);
  if (_Var1) {
    data[1] = data[1] & 0xe0 | 5;
    usleep(200000);
    _Var1 = write_dac(which_chain,'\x01',0xd1,data,2);
    if (_Var1) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : success\n","init_dac53401_NBT2006_36");
      builtin_strncpy(tmp1,"success",8);
      log_to_file(tmp1,time_stamp);
      _Var1 = true;
    }
    else {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : fail\n","init_dac53401_NBT2006_36");
      builtin_strncpy(tmp1,"fail",4);
      tmp1._4_4_ = tmp1._4_4_ & 0xffffff00;
      log_to_file(tmp1,time_stamp);
      _Var1 = false;
    }
  }
  else {
    _Var1 = false;
  }
  return _Var1;
}

