
int __stat(char *__file,stat *__buf)

{
  int iVar1;
  
  iVar1 = __xstat(3,__file,__buf);
  return iVar1;
}

