
void setStartTimePoint(void)

{
  int iVar1;
  int *piVar2;
  char *pcVar3;
  sysinfo local_58;
  FILE *local_18;
  FILE *local_14;
  
  iVar1 = sysinfo(&local_58);
  if (iVar1 == 0) {
    search_start_time = local_58.uptime;
    if (3 < log_level) {
      local_18 = fopen(log_file,"a+");
      if (local_18 != (FILE *)0x0) {
        fprintf(local_18,"%s:%d: get search_start_time=%d \n","main.c",0x113,search_start_time);
      }
      fclose(local_18);
    }
  }
  else {
    if (3 < log_level) {
      local_14 = fopen(log_file,"a+");
      if (local_14 != (FILE *)0x0) {
        piVar2 = __errno_location();
        iVar1 = *piVar2;
        piVar2 = __errno_location();
        pcVar3 = strerror(*piVar2);
        fprintf(local_14,"%s:%d: Failed to get sysinfo, errno:%u, reason:%s\n","main.c",0x10a,iVar1,
                pcVar3);
      }
      fclose(local_14);
    }
    search_start_time = time((time_t *)0x0);
  }
  return;
}

