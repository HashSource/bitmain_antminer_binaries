
/* WARNING: Unknown calling convention */

char * clib_strdup(char *ptr)

{
  char *pcVar1;
  
  pcVar1 = (char *)__strdup(ptr);
  return pcVar1;
}

