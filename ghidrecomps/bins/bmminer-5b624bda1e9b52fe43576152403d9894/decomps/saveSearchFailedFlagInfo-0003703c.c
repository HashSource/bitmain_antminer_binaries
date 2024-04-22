
/* WARNING: Unknown calling convention */

void saveSearchFailedFlagInfo(char *search_failed_info)

{
  FILE *__s;
  FILE *fd;
  size_t sVar1;
  
  __s = fopen(DAT_00037080,DAT_0003707c);
  if (__s != (FILE *)0x0) {
    sVar1 = strlen(search_failed_info);
    fwrite(search_failed_info,1,sVar1 + 1,__s);
    fclose(__s);
  }
  system(DAT_00037084);
  system(DAT_00037088);
                    /* WARNING: Could not recover jumptable at 0x0000a128. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_LAB_0005f1a4)(DAT_0003708c);
  return;
}

