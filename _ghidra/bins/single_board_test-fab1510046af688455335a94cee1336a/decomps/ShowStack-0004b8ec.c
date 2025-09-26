
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ShowStack(void)

{
  int iVar1;
  int iVar2;
  void *buffer [1024];
  char **symbols;
  int n;
  int i;
  
  iVar1 = backtrace(buffer,0x400);
  printf("backtrace len = %d\n",iVar1);
  iVar2 = backtrace_symbols(buffer,iVar1);
  for (i = 0; i < iVar1; i = i + 1) {
    puts(*(char **)(i * 4 + iVar2));
  }
  return;
}

