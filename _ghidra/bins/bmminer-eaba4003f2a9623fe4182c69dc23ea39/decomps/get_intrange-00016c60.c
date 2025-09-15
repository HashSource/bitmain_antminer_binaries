
void get_intrange(char *arg,int *val1,int *val2)

{
  int iVar1;
  int *val2_local;
  int *val1_local;
  char *arg_local;
  
  iVar1 = sscanf(arg,"%d-%d",val1,val2);
  if (iVar1 == 1) {
    *val2 = *val1;
  }
  return;
}

