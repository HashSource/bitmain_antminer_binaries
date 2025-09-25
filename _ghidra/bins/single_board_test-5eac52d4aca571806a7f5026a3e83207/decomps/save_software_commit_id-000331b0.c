
/* WARNING: Unknown calling convention */

_Bool save_software_commit_id(void)

{
  size_t sVar1;
  char time_stamp [48];
  char tmp1 [256];
  
  memset(zhiju_software_commit_id,0,0x40);
  substr("version: 6eec27e318c6eb489e1c617136e1a6aadec82c7f commit: 2024-07-05 13:57:53 build: 2024-07-05 14:15:22"
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

