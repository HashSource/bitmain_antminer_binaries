
undefined4 EC_KEY_oct2key(int param_1,byte *param_2,size_t param_3,BN_CTX *param_4)

{
  int iVar1;
  EC_POINT *p;
  uint uVar2;
  EC_GROUP *group;
  bool bVar3;
  
  if (param_1 == 0) {
    return 0;
  }
  group = *(EC_GROUP **)(param_1 + 0xc);
  if (group != (EC_GROUP *)0x0) {
    p = *(EC_POINT **)(param_1 + 0x10);
    if (p == (EC_POINT *)0x0) {
      p = EC_POINT_new(group);
      *(EC_POINT **)(param_1 + 0x10) = p;
      if (p == (EC_POINT *)0x0) {
        return 0;
      }
      group = *(EC_GROUP **)(param_1 + 0xc);
    }
    iVar1 = EC_POINT_oct2point(group,p,param_2,param_3,param_4);
    if (iVar1 != 0) {
      uVar2 = *(int *)**(undefined4 **)(param_1 + 0xc) << 0x1e;
      bVar3 = -1 < (int)uVar2;
      if (bVar3) {
        uVar2 = *param_2 & 0xfffffffe;
      }
      if (bVar3) {
        *(uint *)(param_1 + 0x1c) = uVar2;
      }
      return 1;
    }
  }
  return 0;
}

