
/* WARNING: Unknown calling convention */

uint64_t miner_now(void)

{
  int iVar1;
  int iVar2;
  timeval tv;
  
  gettimeofday((timeval *)&tv,(__timezone_ptr_t)0x0);
  iVar1 = tv.tv_sec >> 0x1f;
  iVar2 = ((((iVar1 << 5 | (uint)tv.tv_sec >> 0x1b) - iVar1) -
           (uint)((uint)(tv.tv_sec * 0x20) < (uint)tv.tv_sec)) * 0x200 |
          (uint)(tv.tv_sec * 0x1f) >> 0x17) + iVar1 + (uint)CARRY4(tv.tv_sec * 0x3e00,tv.tv_sec);
  return CONCAT44((tv.tv_usec >> 0x1f) +
                  iVar1 + (((iVar2 * 0x40 | (uint)(tv.tv_sec * 0x3e01) >> 0x1a) - iVar2) -
                          (uint)((uint)(tv.tv_sec * 0xf8040) < (uint)(tv.tv_sec * 0x3e01))) +
                          (uint)CARRY4(tv.tv_sec,tv.tv_sec * 999999) +
                  (uint)CARRY4(tv.tv_usec,tv.tv_sec * 1000000),tv.tv_usec + tv.tv_sec * 1000000);
}

