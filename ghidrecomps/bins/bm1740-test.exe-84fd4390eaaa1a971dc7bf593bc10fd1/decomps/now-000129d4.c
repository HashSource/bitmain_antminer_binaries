
undefined8 now(void)

{
  longlong lVar1;
  timeval local_18;
  
  gettimeofday(&local_18,(__timezone_ptr_t)0x0);
  lVar1 = (ulonglong)(uint)local_18.tv_sec * 1000000 +
          CONCAT44((local_18.tv_sec >> 0x1f) * 1000000,local_18.tv_usec);
  return CONCAT44((local_18.tv_usec >> 0x1f) + (int)((ulonglong)lVar1 >> 0x20),(int)lVar1);
}

