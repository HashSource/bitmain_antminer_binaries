
void CRYPTO_dbg_malloc(void *addr,int num,char *file,int line,int before_p)

{
  uint *puVar1;
  uint *puVar2;
  char *file_00;
  void **ptr;
  _LHASH *p_Var3;
  void *pvVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  bool bVar8;
  CRYPTO_THREADID CStack_44;
  CRYPTO_THREADID aCStack_3c [4];
  
  puVar1 = DAT_0008aa48;
  if ((before_p & 0x7fU) != 1) {
    return;
  }
  if (addr == (void *)0x0) {
    return;
  }
  if (-1 < (int)(DAT_0008aa48[1] << 0x1f)) {
    return;
  }
  CRYPTO_THREADID_current(&CStack_44);
  CRYPTO_lock(5,0x14,DAT_0008aa4c,0x11d);
  if ((int)(puVar1[1] << 0x1e) < 0) {
    CRYPTO_lock(6,0x14,DAT_0008aa4c,0x122);
  }
  else {
    iVar7 = CRYPTO_THREADID_cmp((CRYPTO_THREADID *)(puVar1 + 3),&CStack_44);
    CRYPTO_lock(6,0x14,DAT_0008aa4c,0x122);
    if (iVar7 == 0) {
      return;
    }
  }
  CRYPTO_mem_ctrl_constprop_2();
  ptr = (void **)CRYPTO_malloc(0x24,DAT_0008aa4c,0x1e1);
  puVar2 = DAT_0008aa48;
  if (ptr != (void **)0x0) {
    if (puVar1[6] == 0) {
      p_Var3 = lh_new(DAT_0008aa50,DAT_0008aa54);
      puVar2[6] = (uint)p_Var3;
      if (p_Var3 == (_LHASH *)0x0) {
        CRYPTO_free(addr);
        CRYPTO_free(ptr);
        goto LAB_0008a9a8;
      }
    }
    uVar6 = *puVar1;
    *ptr = addr;
    ptr[1] = (void *)num;
    ptr[2] = file;
    ptr[3] = (void *)line;
    puVar2 = DAT_0008aa48;
    if ((uVar6 & 2) == 0) {
      *(undefined *)(ptr + 4) = 0;
      *(undefined *)((int)ptr + 0x11) = 0;
      *(undefined *)((int)ptr + 0x12) = 0;
      *(undefined *)((int)ptr + 0x13) = 0;
      *(undefined *)(ptr + 5) = 0;
      *(undefined *)((int)ptr + 0x15) = 0;
      *(undefined *)((int)ptr + 0x16) = 0;
      *(undefined *)((int)ptr + 0x17) = 0;
    }
    else {
      CRYPTO_THREADID_current((CRYPTO_THREADID *)(ptr + 4));
      uVar6 = *puVar2;
    }
    pvVar4 = (void *)puVar1[7];
    bVar8 = (uVar6 & 1) != 0;
    if (!bVar8) {
      ptr[7] = (void *)0x0;
    }
    ptr[6] = pvVar4;
    puVar1[7] = (int)pvVar4 + 1;
    if (bVar8) {
      pvVar4 = (void *)time((time_t *)0x0);
      ptr[7] = pvVar4;
    }
    CRYPTO_THREADID_current(aCStack_3c);
    p_Var3 = (_LHASH *)puVar1[5];
    ptr[8] = (void *)0x0;
    if ((p_Var3 != (_LHASH *)0x0) &&
       (pvVar4 = lh_retrieve(p_Var3,aCStack_3c), pvVar4 != (void *)0x0)) {
      iVar7 = *(int *)((int)pvVar4 + 0x18);
      ptr[8] = pvVar4;
      *(int *)((int)pvVar4 + 0x18) = iVar7 + 1;
    }
    addr = lh_insert((_LHASH *)puVar1[6],ptr);
    if (addr == (void *)0x0) goto LAB_0008a9a8;
    iVar7 = *(int *)((int)addr + 0x20);
    if (iVar7 != 0) {
      *(int *)(iVar7 + 0x18) = *(int *)(iVar7 + 0x18) + -1;
    }
  }
  CRYPTO_free(addr);
LAB_0008a9a8:
  CRYPTO_lock(9,0x14,DAT_0008aa4c,0xd4);
  puVar2 = DAT_0008aa48;
  uVar6 = puVar1[1];
  if ((((int)(uVar6 << 0x1f) < 0) && (DAT_0008aa48[2] != 0)) &&
     (uVar5 = DAT_0008aa48[2] - 1, DAT_0008aa48[2] = uVar5, file_00 = DAT_0008aa4c, uVar5 == 0)) {
    puVar2[1] = uVar6 | 2;
    CRYPTO_lock(10,0x1b,file_00,0x109);
  }
  CRYPTO_lock(10,0x14,DAT_0008aa4c,0x112);
  return;
}

