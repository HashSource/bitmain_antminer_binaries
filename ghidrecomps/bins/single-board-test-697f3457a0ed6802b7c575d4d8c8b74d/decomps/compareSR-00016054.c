
int compareSR(void *p1,void *p2)

{
  int iVar1;
  void *p2_local;
  void *p1_local;
  
  iVar1 = memcmp(p1,p2,compare_size);
  return iVar1;
}

