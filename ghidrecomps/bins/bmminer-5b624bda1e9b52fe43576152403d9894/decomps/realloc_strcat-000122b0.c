
/* WARNING: Unknown calling convention */

void * realloc_strcat(char *ptr,char *s)

{
  size_t sVar1;
  size_t len;
  char *pcVar2;
  char *ret;
  
  sVar1 = strlen(s);
  pcVar2 = ptr;
  if (sVar1 != 0) {
    if (ptr != (char *)0x0) {
      pcVar2 = (char *)strlen(ptr);
    }
    pcVar2 = pcVar2 + sVar1 + 1;
    if (((uint)pcVar2 & 3) != 0) {
      pcVar2 = (char *)(((uint)pcVar2 & 0xfffffffc) + 4);
    }
    pcVar2 = (char *)_cgmalloc((uint)pcVar2,DAT_00012308,DAT_0001230c,0xc8a);
    if (ptr == (char *)0x0) {
      strcpy(pcVar2,s);
    }
    else {
      sprintf(pcVar2,DAT_00012310,ptr,s);
      free(ptr);
    }
  }
  return pcVar2;
}

