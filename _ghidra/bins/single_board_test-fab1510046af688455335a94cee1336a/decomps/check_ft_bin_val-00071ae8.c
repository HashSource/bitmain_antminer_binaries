
_Bool check_ft_bin_val(char fe_flag,int fe_ver,int ft_ver,int vol_bin,int ele_bin,int speed_bin,
                      int col)

{
  _Bool _Var1;
  int vol_bin_local;
  int ft_ver_local;
  int fe_ver_local;
  char fe_flag_local;
  char time_stamp [48];
  char tmp1 [2048];
  
  if ((fe_flag == 'F') || (fe_flag == 'E')) {
    if (fe_ver < 8) {
      if (ft_ver < 0x40) {
        if (vol_bin < 8) {
          if (ele_bin < 4) {
            if (speed_bin < 8) {
              if (col < 0x10) {
                _Var1 = true;
              }
              else {
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s: col is err:%d\n","check_ft_bin_val",col);
                snprintf(tmp1,0x800,"col is err:%d",col);
                log_to_file(tmp1,time_stamp);
                _Var1 = false;
              }
            }
            else {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s: speed_bin is err:%d\n","check_ft_bin_val",speed_bin);
              snprintf(tmp1,0x800,"speed_bin is err:%d",speed_bin);
              log_to_file(tmp1,time_stamp);
              _Var1 = false;
            }
          }
          else {
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            printf("%s: ele_bin is err:%d\n","check_ft_bin_val",ele_bin);
            snprintf(tmp1,0x800,"ele_bin is err:%d",ele_bin);
            log_to_file(tmp1,time_stamp);
            _Var1 = false;
          }
        }
        else {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s: vol_bin is err:%d\n","check_ft_bin_val",vol_bin);
          snprintf(tmp1,0x800,"vol_bin is err:%d",vol_bin);
          log_to_file(tmp1,time_stamp);
          _Var1 = false;
        }
      }
      else {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: ft_ver is err:%d\n","check_ft_bin_val",ft_ver);
        snprintf(tmp1,0x800,"ft_ver is err:%d",ft_ver);
        log_to_file(tmp1,time_stamp);
        _Var1 = false;
      }
    }
    else {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: fe_ver is err:%d\n","check_ft_bin_val",fe_ver);
      snprintf(tmp1,0x800,"fe_ver is err:%d",fe_ver);
      log_to_file(tmp1,time_stamp);
      _Var1 = false;
    }
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: fe_flag is err:%d\n","check_ft_bin_val",(uint)(byte)fe_flag);
    snprintf(tmp1,0x800,"fe_flag is err:%d",(uint)(byte)fe_flag);
    log_to_file(tmp1,time_stamp);
    _Var1 = false;
  }
  return _Var1;
}

