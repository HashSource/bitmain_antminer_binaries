
bool ssleay_rand_status(void)

{
  bool bVar1;
  bool bVar2;
  int *piVar3;
  int *piVar4;
  char *file;
  int iVar5;
  bool bVar6;
  double dVar7;
  CRYPTO_THREADID CStack_18;
  
  piVar3 = DAT_001030c8;
  CRYPTO_THREADID_current(&CStack_18);
  if (*piVar3 != 0) {
    CRYPTO_lock(5,0x13,DAT_001030cc,0x22f);
    iVar5 = CRYPTO_THREADID_cmp((CRYPTO_THREADID *)(piVar3 + 1),&CStack_18);
    CRYPTO_lock(6,0x13,DAT_001030cc,0x231);
    if (iVar5 == 0) {
      bVar6 = true;
      goto LAB_00103052;
    }
  }
  CRYPTO_lock(9,0x12,DAT_001030cc,0x236);
  CRYPTO_lock(9,0x13,DAT_001030cc,0x23b);
  CRYPTO_THREADID_cpy(DAT_001030d0,&CStack_18);
  bVar6 = false;
  CRYPTO_lock(10,0x13,DAT_001030cc,0x23d);
  *piVar3 = 1;
LAB_00103052:
  piVar4 = DAT_001030c8;
  if (piVar3[3] == 0) {
    RAND_poll();
    piVar4[3] = 1;
  }
  file = DAT_001030cc;
  dVar7 = *(double *)(piVar3 + 4);
  bVar1 = dVar7 < DAT_001030c0;
  bVar2 = NAN(DAT_001030c0);
  if (!bVar6) {
    *DAT_001030c8 = 0;
    CRYPTO_lock(10,0x12,file,0x24c);
  }
  return bVar1 == (NAN(dVar7) || bVar2);
}

