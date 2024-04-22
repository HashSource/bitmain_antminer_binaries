
void CRYPTO_mem_leaks(bio_st *bio)

{
  int iVar1;
  char *pcVar2;
  ulong uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  bio_st *local_24;
  int local_20;
  undefined4 local_1c;
  
  iVar4 = DAT_0008ad18;
  if ((*(int *)(DAT_0008ad18 + 0x18) != 0) || (*(int *)(DAT_0008ad18 + 0x14) != 0)) {
    CRYPTO_mem_ctrl_constprop_2();
    local_1c = 0;
    local_20 = 0;
    local_24 = bio;
    if ((*(_LHASH **)(iVar4 + 0x18) == (_LHASH *)0x0) ||
       (lh_doall_arg(*(_LHASH **)(iVar4 + 0x18),DAT_0008ad1c,&local_24), local_20 == 0)) {
      CRYPTO_lock(9,0x14,DAT_0008ad24,0x2eb);
      iVar1 = DAT_0008ad18;
      uVar6 = *(undefined4 *)(iVar4 + 4);
      *(undefined4 *)(iVar4 + 4) = 0;
      if (*(_LHASH **)(iVar4 + 0x18) != (_LHASH *)0x0) {
        lh_free(*(_LHASH **)(iVar4 + 0x18));
        *(undefined4 *)(iVar1 + 0x18) = 0;
      }
      iVar1 = DAT_0008ad18;
      if ((*(_LHASH **)(iVar4 + 0x14) != (_LHASH *)0x0) &&
         (uVar3 = lh_num_items(*(_LHASH **)(iVar4 + 0x14)), uVar3 == 0)) {
        lh_free(*(_LHASH **)(iVar1 + 0x14));
        *(undefined4 *)(iVar1 + 0x14) = 0;
      }
      pcVar2 = DAT_0008ad24;
      *(undefined4 *)(iVar4 + 4) = uVar6;
      CRYPTO_lock(10,0x14,pcVar2,0x300);
    }
    else {
      BIO_printf(bio,DAT_0008ad20,local_1c);
    }
    CRYPTO_lock(9,0x14,DAT_0008ad24,0xd4);
    iVar1 = DAT_0008ad18;
    uVar5 = *(uint *)(iVar4 + 4);
    if ((((int)(uVar5 << 0x1f) < 0) && (*(int *)(DAT_0008ad18 + 8) != 0)) &&
       (iVar4 = *(int *)(DAT_0008ad18 + 8) + -1, *(int *)(DAT_0008ad18 + 8) = iVar4,
       pcVar2 = DAT_0008ad24, iVar4 == 0)) {
      *(uint *)(iVar1 + 4) = uVar5 | 2;
      CRYPTO_lock(10,0x1b,pcVar2,0x109);
    }
    CRYPTO_lock(10,0x14,DAT_0008ad24,0x112);
  }
  return;
}

