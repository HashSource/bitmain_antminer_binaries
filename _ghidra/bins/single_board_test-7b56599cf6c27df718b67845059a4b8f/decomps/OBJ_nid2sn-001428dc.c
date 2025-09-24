
char * OBJ_nid2sn(int n)

{
  int iVar1;
  undefined4 local_28;
  undefined1 *local_24;
  undefined1 auStack_20 [8];
  int local_18;
  
  if ((uint)n < 0x4ab) {
    iVar1 = n;
    if ((n == 0) || (iVar1 = n * 2, *(int *)(&DAT_00261738 + n * 0x18) != 0)) {
      return *(char **)(&nid_objs + (n + iVar1) * 8);
    }
    iVar1 = 0xff;
  }
  else {
    if (added == 0) {
      return (char *)0x0;
    }
    local_24 = auStack_20;
    local_28 = 3;
    local_18 = n;
    iVar1 = OPENSSL_LH_retrieve(added,&local_28);
    if (iVar1 != 0) {
      return (char *)**(undefined4 **)(iVar1 + 4);
    }
    iVar1 = 0x10d;
  }
  ERR_put_error(8,0x68,0x65,"crypto/objects/obj_dat.c",iVar1);
  return (char *)0x0;
}

