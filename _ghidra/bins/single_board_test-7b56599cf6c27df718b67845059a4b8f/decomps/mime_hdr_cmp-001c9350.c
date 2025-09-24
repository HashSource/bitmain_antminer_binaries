
int mime_hdr_cmp(undefined4 *param_1,undefined4 *param_2)

{
  char *__s1;
  int iVar1;
  char *__s2;
  
  __s1 = *(char **)*param_1;
  __s2 = *(char **)*param_2;
  if ((__s1 != (char *)0x0) && (__s2 != (char *)0x0)) {
    iVar1 = strcmp(__s1,__s2);
    return iVar1;
  }
  if (__s2 != (char *)0x0) {
    __s2 = (char *)0x1;
  }
  if (__s1 == (char *)0x0) {
    iVar1 = -(int)__s2;
  }
  else {
    iVar1 = 1 - (int)__s2;
  }
  return iVar1;
}

