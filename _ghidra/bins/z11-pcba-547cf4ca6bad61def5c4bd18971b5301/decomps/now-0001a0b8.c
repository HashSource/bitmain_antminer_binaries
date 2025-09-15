
undefined8 now(void)

{
  int iVar1;
  int iVar2;
  timeval local_30;
  
  gettimeofday(&local_30,(__timezone_ptr_t)0x0);
  iVar1 = local_30.tv_sec >> 0x1f;
  iVar2 = ((((iVar1 << 5 | (uint)local_30.tv_sec >> 0x1b) - iVar1) -
           (uint)((uint)(local_30.tv_sec * 0x20) < (uint)local_30.tv_sec)) * 0x200 |
          (uint)(local_30.tv_sec * 0x1f) >> 0x17) +
          iVar1 + (uint)CARRY4(local_30.tv_sec * 0x3e00,local_30.tv_sec);
  return CONCAT44((local_30.tv_usec >> 0x1f) +
                  iVar1 + (((iVar2 * 0x40 | (uint)(local_30.tv_sec * 0x3e01) >> 0x1a) - iVar2) -
                          (uint)((uint)(local_30.tv_sec * 0xf8040) <
                                (uint)(local_30.tv_sec * 0x3e01))) +
                          (uint)CARRY4(local_30.tv_sec,local_30.tv_sec * 999999) +
                  (uint)CARRY4(local_30.tv_usec,local_30.tv_sec * 1000000),
                  local_30.tv_usec + local_30.tv_sec * 1000000);
}

