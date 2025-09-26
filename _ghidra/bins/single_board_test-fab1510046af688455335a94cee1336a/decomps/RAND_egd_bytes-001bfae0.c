
int RAND_egd_bytes(char *path,int bytes)

{
  int iVar1;
  int iVar2;
  
  iVar1 = RAND_query_egd_bytes(path,(uchar *)0x0,bytes);
  if ((0 < iVar1) && (iVar2 = RAND_status(), iVar2 == 1)) {
    return iVar1;
  }
  return 0;
}

