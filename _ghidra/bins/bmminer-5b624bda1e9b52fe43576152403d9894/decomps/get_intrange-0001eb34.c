
/* WARNING: Unknown calling convention */

void get_intrange(char *arg,int *val1,int *val2)

{
  int iVar1;
  
  iVar1 = sscanf(arg,"%d-%d",val1,val2);
  if (iVar1 == 1) {
    *val2 = *val1;
  }
  return;
}

