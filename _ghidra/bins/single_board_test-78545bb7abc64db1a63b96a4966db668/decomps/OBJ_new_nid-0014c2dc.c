
int OBJ_new_nid(int num)

{
  int iVar1;
  
  iVar1 = new_nid;
  new_nid = new_nid + num;
  return iVar1;
}

