
void freq_scan_error_code_set(int err_code,int chain)

{
  FILE *__stream;
  int chain_local;
  int err_code_local;
  FILE *pFile;
  
  if (freq_mode != 1) {
    freq_scan_status = 2;
    switch(err_code) {
    case 0:
      snprintf(search_failed_info,0x40,"J%d:1",chain);
      break;
    case 1:
      snprintf(search_failed_info,0x40,"J%d:2",chain);
      break;
    case 2:
      snprintf(search_failed_info,0x40,"J%d:3",chain);
      break;
    case 3:
      snprintf(search_failed_info,0x40,"J%d:4",chain);
      break;
    case 4:
      snprintf(search_failed_info,0x40,"J%d:5",chain);
      break;
    case 5:
      search_failed_info._0_4_ = DAT_00084ecc;
      break;
    case 6:
      search_failed_info._0_4_ = DAT_00084ed0;
      break;
    case 7:
      snprintf(search_failed_info,0x40,"T:%d",chain);
      break;
    case 8:
      search_failed_info._0_4_ = DAT_00084ee0;
      break;
    case 9:
      search_failed_info._0_4_ = DAT_00084ee4;
      break;
    case 10:
      search_failed_info._0_4_ = DAT_00084ee8;
      break;
    case 0xb:
      snprintf(search_failed_info,0x40,"J%d:6",chain);
      break;
    case 0xc:
      search_failed_info._0_4_ = DAT_00084ef4;
      break;
    case 0xd:
      search_failed_info._0_4_ = DAT_00084ef8;
      break;
    case 0xe:
      search_failed_info._0_4_ = DAT_00084efc;
      break;
    case 0xf:
      search_failed_info._0_4_ = DAT_00084f04;
      break;
    default:
      search_failed_info._0_4_ = s_unknown_00084f0c._0_4_;
      search_failed_info._4_4_ = s_unknown_00084f0c._4_4_;
      break;
    case 0x11:
      search_failed_info._0_4_ = DAT_00084ed4;
      break;
    case 0x12:
      search_failed_info._0_4_ = DAT_00084f08;
      break;
    case 0x13:
      search_failed_info._0_4_ = DAT_00084f00;
    }
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      __stream = fopen(log_file,"a+");
      if (__stream != (FILE *)0x0) {
        fprintf(__stream,"%s:%d:%s: Frequency scan error_code = %s.\n","freq_scan.c",0xbe,
                "freq_scan_error_code_set",search_failed_info);
      }
      fclose(__stream);
    }
  }
  return;
}

