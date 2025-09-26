
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void pt_exit(void)

{
  char tmp42 [256];
  
  builtin_strncpy(tmp42,"pt exit\n",8);
  tmp42[8] = '\0';
  puts(tmp42);
  return;
}

