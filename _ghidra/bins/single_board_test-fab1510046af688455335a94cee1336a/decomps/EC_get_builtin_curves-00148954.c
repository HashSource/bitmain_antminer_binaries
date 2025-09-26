
size_t EC_get_builtin_curves(EC_builtin_curve *r,size_t nitems)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  if (r != (EC_builtin_curve *)0x0 && nitems != 0) {
    if (0x50 < nitems) {
      nitems = 0x51;
    }
    if (nitems != 0) {
      puVar3 = &curve_list;
      iVar2 = 0;
      do {
        uVar1 = *puVar3;
        uVar4 = puVar3[3];
        puVar3 = puVar3 + 4;
        *(undefined4 *)((int)&r->nid + iVar2) = uVar1;
        *(undefined4 *)((int)&r->comment + iVar2) = uVar4;
        iVar2 = iVar2 + 8;
      } while (puVar3 != &curve_list + nitems * 4);
    }
  }
  return 0x51;
}

