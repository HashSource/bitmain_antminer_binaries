
/* WARNING: Unknown calling convention */

void get_intrange(char *arg,int *val1,int *val2)

{
  int iVar1;
  
  iVar1 = sscanf(arg,DAT_0001eb50,val1);
  if (iVar1 == 1) {
    *val2 = *val1;
  }
  return;
}

