
int CRYPTO_push_info_(char *info,char *file,int line)

{
  char *file_00;
  CRYPTO_THREADID *id;
  void *pvVar1;
  int iVar2;
  _LHASH *p_Var3;
  int iVar4;
  uint uVar5;
  CRYPTO_THREADID CStack_28;
  
  iVar4 = DAT_0008a6b8;
  if (-1 < *(int *)(DAT_0008a6b8 + 4) << 0x1f) {
    return 0;
  }
  CRYPTO_THREADID_current(&CStack_28);
  CRYPTO_lock(5,0x14,DAT_0008a6bc,0x11d);
  if (*(int *)(iVar4 + 4) << 0x1e < 0) {
    CRYPTO_lock(6,0x14,DAT_0008a6bc,0x122);
  }
  else {
    iVar2 = CRYPTO_THREADID_cmp((CRYPTO_THREADID *)(iVar4 + 0xc),&CStack_28);
    CRYPTO_lock(6,0x14,DAT_0008a6bc,0x122);
    if (iVar2 == 0) {
      return 0;
    }
  }
  CRYPTO_mem_ctrl_constprop_2();
  id = (CRYPTO_THREADID *)CRYPTO_malloc(0x1c,DAT_0008a6bc,0x18d);
  iVar2 = DAT_0008a6b8;
  if (id != (CRYPTO_THREADID *)0x0) {
    if (*(int *)(iVar4 + 0x14) == 0) {
      p_Var3 = lh_new(DAT_0008a6c0,DAT_0008a6c4);
      *(_LHASH **)(iVar2 + 0x14) = p_Var3;
      if (p_Var3 == (_LHASH *)0x0) {
        CRYPTO_free(id);
        goto LAB_0008a63c;
      }
    }
    CRYPTO_THREADID_current(id);
    id[1].ptr = file;
    id[1].val = line;
    id[2].ptr = info;
    id[3].ptr = (void *)0x1;
    id[2].val = 0;
    pvVar1 = lh_insert(*(_LHASH **)(iVar4 + 0x14),id);
    if (pvVar1 != (void *)0x0) {
      id[2].val = (ulong)pvVar1;
    }
  }
LAB_0008a63c:
  CRYPTO_lock(9,0x14,DAT_0008a6bc,0xd4);
  iVar2 = DAT_0008a6b8;
  uVar5 = *(uint *)(iVar4 + 4);
  if ((((int)(uVar5 << 0x1f) < 0) && (*(int *)(DAT_0008a6b8 + 8) != 0)) &&
     (iVar4 = *(int *)(DAT_0008a6b8 + 8) + -1, *(int *)(DAT_0008a6b8 + 8) = iVar4,
     file_00 = DAT_0008a6bc, iVar4 == 0)) {
    *(uint *)(iVar2 + 4) = uVar5 | 2;
    CRYPTO_lock(10,0x1b,file_00,0x109);
  }
  CRYPTO_lock(10,0x14,DAT_0008a6bc,0x112);
  return 0;
}

