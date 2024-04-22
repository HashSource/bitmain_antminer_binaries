
/* WARNING: Unknown calling convention */

int get_works(void)

{
  int ret;
  int iVar1;
  double dVar2;
  timeval t0;
  timeval t1;
  
  gettimeofday((timeval *)&t0,(__timezone_ptr_t)0x0);
  if (Conf.AsicType == 0x1397) {
    ret = get_works_v2();
  }
  else {
    ret = get_works_v1();
  }
  if (ret < 0) {
    iVar1 = -0xe;
  }
  else {
    gettimeofday((timeval *)&t1,(__timezone_ptr_t)0x0);
    dVar2 = (double)((float)(longlong)(t1.tv_usec - t0.tv_usec) / DAT_00021b74 +
                    (float)(longlong)(t1.tv_sec - t0.tv_sec));
    printf("get_works took %.3fs\n",t0.tv_sec,SUB84(dVar2,0),(int)((ulonglong)dVar2 >> 0x20));
    iVar1 = 0;
  }
  return iVar1;
}

