
U64 XXH64_mergeRound(U64 acc,U64 val)

{
  longlong lVar1;
  uint uVar2;
  U64 UVar3;
  U64 val_local;
  U64 acc_local;
  
  UVar3 = XXH64_round(0,val);
  acc_local._0_4_ = (uint)acc;
  acc_local._4_4_ = (uint)(acc >> 0x20);
  val_local._0_4_ = (uint)UVar3;
  val_local._4_4_ = (uint)(UVar3 >> 0x20);
  lVar1 = (ulonglong)((uint)acc_local ^ (uint)val_local) * 0x85ebca87;
  uVar2 = (uint)lVar1;
  acc_local = CONCAT44((acc_local._4_4_ ^ val_local._4_4_) * -0x7a143579 +
                       ((uint)acc_local ^ (uint)val_local) * -0x61c8864f +
                       (int)((ulonglong)lVar1 >> 0x20) + (0x3d4d519c < uVar2) + 0x85ebca77,
                       uVar2 + 0xc2b2ae63);
  return acc_local;
}

