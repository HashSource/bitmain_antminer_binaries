
void CRYPTO_dbg_realloc(void *addr1,void *addr2,int num,char *file,int line,int before_p)

{
  char *file_00;
  void **data;
  int iVar1;
  int iVar2;
  uint uVar3;
  CRYPTO_THREADID CStack_44;
  void *local_3c [9];
  
  iVar2 = DAT_0008ac40;
  if ((before_p == 1) && (addr2 != (void *)0x0)) {
    if (addr1 == (void *)0x0) {
      CRYPTO_dbg_malloc(addr2,num,file,line,0x81);
    }
    else if (*(int *)(DAT_0008ac40 + 4) << 0x1f < 0) {
      CRYPTO_THREADID_current(&CStack_44);
      CRYPTO_lock(5,0x14,DAT_0008ac44,0x11d);
      if (*(int *)(iVar2 + 4) << 0x1e < 0) {
        CRYPTO_lock(6,0x14,DAT_0008ac44,0x122);
      }
      else {
        iVar1 = CRYPTO_THREADID_cmp((CRYPTO_THREADID *)(iVar2 + 0xc),&CStack_44);
        CRYPTO_lock(6,0x14,DAT_0008ac44,0x122);
        if (iVar1 == 0) {
          return;
        }
      }
      CRYPTO_mem_ctrl_constprop_2();
      local_3c[0] = addr1;
      data = (void **)lh_delete(*(_LHASH **)(iVar2 + 0x18),local_3c);
      iVar1 = DAT_0008ac40;
      if (data != (void **)0x0) {
        *data = addr2;
        data[1] = (void *)num;
        lh_insert(*(_LHASH **)(iVar1 + 0x18),data);
      }
      CRYPTO_lock(9,0x14,DAT_0008ac44,0xd4);
      iVar1 = DAT_0008ac40;
      uVar3 = *(uint *)(iVar2 + 4);
      if ((((int)(uVar3 << 0x1f) < 0) && (*(int *)(DAT_0008ac40 + 8) != 0)) &&
         (iVar2 = *(int *)(DAT_0008ac40 + 8) + -1, *(int *)(DAT_0008ac40 + 8) = iVar2,
         file_00 = DAT_0008ac44, iVar2 == 0)) {
        *(uint *)(iVar1 + 4) = uVar3 | 2;
        CRYPTO_lock(10,0x1b,file_00,0x109);
      }
      CRYPTO_lock(10,0x14,DAT_0008ac44,0x112);
    }
  }
  return;
}

