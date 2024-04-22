
void get_work_by_nonce2(undefined4 *param_1,int *param_2,int param_3,undefined4 param_4,
                       undefined4 param_5,undefined4 param_6,uint param_7)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 unaff_r8;
  undefined4 uVar3;
  
  iVar2 = make_work();
  *param_2 = iVar2;
  uVar3 = *param_1;
  iVar2 = pthread_mutex_lock((pthread_mutex_t *)(param_3 + 0xd4));
  if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
    _mutex_lock_part_47_constprop_75(DAT_00023738,0x202b);
  }
  iVar2 = pthread_rwlock_wrlock((pthread_rwlock_t *)(param_3 + 0xec));
  uVar1 = DAT_00023738;
  if (iVar2 == 0) {
    param_7 = param_7 << 0x18 | (param_7 >> 8 & 0xff) << 0x10 | (param_7 >> 0x10 & 0xff) << 8 |
              param_7 >> 0x18;
    *(undefined4 *)(param_3 + 0x270) = param_5;
    *(undefined4 *)(param_3 + 0x274) = param_6;
    _cg_memcpy(param_3 + 0x62c,&param_7,4,"cgminer.c",uVar1,0x202f);
    iVar2 = pthread_rwlock_unlock((pthread_rwlock_t *)(param_3 + 0xec));
    unaff_r8 = uVar1;
    if (iVar2 == 0) {
      iVar2 = pthread_mutex_unlock((pthread_mutex_t *)(param_3 + 0xd4));
      if (iVar2 == 0) {
        (*selective_yield)();
        gen_stratum_work(param_3,*param_2);
        uVar1 = work_block;
        *(undefined4 *)(*param_2 + 0x104) = param_4;
        iVar2 = *param_2;
        *(undefined4 *)(iVar2 + 0x150) = uVar1;
        *(undefined4 *)(iVar2 + 0x100) = uVar3;
        *(int *)(*(int *)(iVar2 + 0x104) + 0x44) = *(int *)(*(int *)(iVar2 + 0x104) + 0x44) + 1;
        *(undefined *)(iVar2 + 0x110) = 1;
        *(uint *)(iVar2 + 0x1bc) = param_7;
        return;
      }
                    /* WARNING: Subroutine does not return */
      _mutex_unlock_noyield_part_48_constprop_77(uVar1,0x2030);
    }
  }
  else {
    _wr_lock_part_54_constprop_73(DAT_00023738,0x202b);
  }
                    /* WARNING: Subroutine does not return */
  _rw_unlock_part_40_constprop_79(unaff_r8,0x2030);
}

