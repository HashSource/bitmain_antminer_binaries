
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
      builtin_strncpy(search_failed_info,"R:1",4);
      break;
    case 6:
      builtin_strncpy(search_failed_info,"R:2",4);
      break;
    case 7:
      snprintf(search_failed_info,0x40,"T:%d",chain);
      break;
    case 8:
      builtin_strncpy(search_failed_info,"P:1",4);
      break;
    case 9:
      builtin_strncpy(search_failed_info,"P:2",4);
      break;
    case 10:
      builtin_strncpy(search_failed_info,"F:1",4);
      break;
    case 0xb:
      snprintf(search_failed_info,0x40,"J%d:6",chain);
      break;
    case 0xc:
      builtin_strncpy(search_failed_info,"V:1",4);
      break;
    case 0xd:
      builtin_strncpy(search_failed_info,"M:1",4);
      break;
    case 0xe:
      builtin_strncpy(search_failed_info,"N:1",4);
      break;
    case 0xf:
      builtin_strncpy(search_failed_info,"P:4",4);
      break;
    default:
      builtin_strncpy(search_failed_info,"unknown",8);
      break;
    case 0x11:
      builtin_strncpy(search_failed_info,"R:3",4);
      break;
    case 0x12:
      builtin_strncpy(search_failed_info,"C:1",4);
      break;
    case 0x13:
      builtin_strncpy(search_failed_info,"N:2",4);
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

