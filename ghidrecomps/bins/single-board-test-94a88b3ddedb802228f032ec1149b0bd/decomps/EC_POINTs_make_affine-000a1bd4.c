
int EC_POINTs_make_affine(EC_GROUP *group,size_t num,EC_POINT **points,BN_CTX *ctx)

{
  size_t sVar1;
  int iVar2;
  
  iVar2 = *(int *)group;
  if (*(code **)(iVar2 + 0x74) == (code *)0x0) {
    ERR_put_error(0x10,0x88,0x42,DAT_000a1c3c,0x403);
    iVar2 = 0;
  }
  else if (num == 0) {
LAB_000a1c08:
    iVar2 = (**(code **)(iVar2 + 0x74))();
  }
  else {
    if (iVar2 == *(int *)*points) {
      sVar1 = 0;
      do {
        sVar1 = sVar1 + 1;
        if (sVar1 == num) goto LAB_000a1c08;
        points = (EC_POINT **)((int **)points + 1);
      } while (iVar2 == *(int *)*points);
    }
    ERR_put_error(0x10,0x88,0x65,DAT_000a1c3c,0x408);
    iVar2 = 0;
  }
  return iVar2;
}

