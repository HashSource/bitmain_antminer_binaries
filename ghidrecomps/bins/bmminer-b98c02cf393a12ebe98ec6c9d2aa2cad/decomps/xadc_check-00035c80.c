
void xadc_check(void)

{
  void **ppvVar1;
  dirent **ppdVar2;
  int iVar3;
  int iVar4;
  dirent **local_14 [2];
  
  iVar3 = scandir("/sys/bus/iio/devices/iio:device0",local_14,(__selector *)0x0,alphasort);
  ppdVar2 = local_14[0];
  if (iVar3 < 0) {
    return;
  }
  if (iVar3 < 6) {
LAB_00035ca4:
    if (iVar3 == 0) goto LAB_00035cb8;
  }
  else {
    get_iio_node(local_14[0],5);
    process_true_data(ppdVar2,5);
    ppdVar2 = local_14[0];
    if (iVar3 < 0x10) goto LAB_00035ca4;
    get_iio_node(local_14[0],0xf);
    process_true_data(ppdVar2,0xf);
    ppdVar2 = local_14[0];
    if (iVar3 < 0x12) goto LAB_00035ca4;
    get_iio_node(local_14[0],0x11);
    process_true_data(ppdVar2,0x11);
    ppdVar2 = local_14[0];
    if (iVar3 < 0x14) goto LAB_00035ca4;
    get_iio_node(local_14[0],0x13);
    process_true_data(ppdVar2,0x13);
  }
  iVar4 = (iVar3 + -1) * 4;
  do {
    ppvVar1 = (void **)((int)local_14[0] + iVar4);
    iVar4 = iVar4 + -4;
    free(*ppvVar1);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
LAB_00035cb8:
  free(local_14[0]);
  return;
}

