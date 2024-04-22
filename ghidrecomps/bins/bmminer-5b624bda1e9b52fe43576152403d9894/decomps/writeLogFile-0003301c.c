
/* WARNING: Unknown calling convention */

void writeLogFile(char *logstr)

{
  FILE *__s;
  FILE *fd;
  size_t __n;
  
  __s = fopen(DAT_00033050,DAT_0003304c);
  if (__s == (FILE *)0x0) {
    return;
  }
  __n = strlen(logstr);
  fwrite(logstr,1,__n,__s);
                    /* WARNING: Could not recover jumptable at 0x0000a0e8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_LAB_0005f190)(__s);
  return;
}

