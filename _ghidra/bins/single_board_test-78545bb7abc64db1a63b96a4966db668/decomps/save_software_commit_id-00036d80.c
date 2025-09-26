
/* WARNING: Unknown calling convention */

_Bool save_software_commit_id(void)

{
  size_t sVar1;
  char time_stamp [48];
  char tmp1 [256];
  
  memset(zhiju_software_commit_id,0,0x40);
  substr("version: b2cb0052105c62c2efac09b2b5bd71d43bfe9a6d commit: 2025-07-16 10:46:54 build: 2025-07-16 10:47:05"
         ,9,0x28,zhiju_software_commit_id);
  sVar1 = strlen(zhiju_software_commit_id);
  (zhiju_software_commit_id + sVar1)[0] = '_';
  (zhiju_software_commit_id + sVar1)[1] = '\0';
  strncat(zhiju_software_commit_id,Local_Config_Information->Test_Process,0x40);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : software_commit_id: %s\n","save_software_commit_id",zhiju_software_commit_id);
  snprintf(tmp1,0x100,"software_commit_id: %s",zhiju_software_commit_id);
  log_to_file(tmp1,time_stamp);
  return true;
}

